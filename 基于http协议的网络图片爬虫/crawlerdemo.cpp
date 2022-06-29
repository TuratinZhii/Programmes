//*All rights served by GitHub@TualatinZhii 2022*//

#include <string> 
#include <iostream> 
#include <fstream> 
#include <vector> 
#include "winsock2.h" 
#include <time.h> 
#include <queue> 
#include <unordered_set>
#include <windows.h>
#include <cstdlib>

#pragma comment(lib,"ws2_32.lib")
using namespace std;

#define DEFAULT_PAGE_BUF_SIZE 1048576

queue<string> hreFurl;
unordered_set<string> visitedUrl;
unordered_set<string> visitedImg;
int depth=0;
int _ImgCnt=1;

//解析URL,主机名,资源名
bool PARSEURL(const string &url,string &host,string &resource)
{
    if(strlen(url.c_str()) > 2000)
    {
        return false;
    }

    const char* pos=strstr(url.c_str(),"https://");
    if(pos==NULL)
    {
        pos=url.c_str();
    }
    else
    {
        pos+=strlen("https://");
    }

    if(strstr(pos,"/")==0)
    {
        return false;
    }

    char pHost[100];
    char pResourse[2000];
    sscanf(pos,"%[^/] %s",pHost,pResourse);
    host=pHost;
    resource=pResourse;
    return true;
}

//请求访问
bool GetHttpResponse(const string &url,char* &response,int &read)
{
    string host,resourse;
    if(!PARSEURL(url,host,resourse))
    {
        cout<<"Error:URL error"<<endl;
        return false;
    }

    //建立套接字
    struct hostent* hp=gethostbyname(host.c_str());
    if(hp==NULL)
    {
        cout<<"Error:please check host address"<<endl;
        return false;
    }

    SOCKET soc=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(soc==-1 || soc==-2)
    {
        cout<<"Error:socket error"<<endl;
        return false;
    }

    //建立服务器地址
    SOCKADDR_IN soca;
    soca.sin_family=AF_INET;
    soca.sin_port=htons(80);
    memcpy(&soca.sin_addr,hp->h_addr,4);

    //建立连接
    if(connect(soc,(sockaddr*)&soca,sizeof(soca)) != 0)
    {
        cout<<"Error:can not connect-- "<<url<<endl;
        closesocket(soc);
        return false;
    }

    //发送数据
    string request="GET"+resourse+"HTTP/1.1\r\nHost:"+host+"\r\nConnection:Close\r\n\r\n";
    if(SOCKET_ERROR==send(soc,request.c_str(),request.size(),0))
    {
        cout<<"Error:sending error"<<endl;
        closesocket(soc);
        return false;
    }

    //接收数据
    int _contentLength=DEFAULT_PAGE_BUF_SIZE;
    char* pageBuf=(char*)malloc(_contentLength);
    memset(pageBuf,0,_contentLength);

    read=0;
    int ret=1;
    cout<<"reading......"<<endl;
    while(ret > 0)
    {
        ret=recv(soc,pageBuf+read,_contentLength-read,0);

        if(ret > 0)
        {
            read+=ret;
        }

        if(_contentLength-read < 100)
        {
            cout<<"\nReallocing memory......"<<endl;
            _contentLength*=2;
            pageBuf=(char*)realloc(pageBuf,_contentLength); //内存再分配
        }
        cout<<ret<<" ";
    }
    cout<<endl;

    pageBuf[read]='\0';
    response=pageBuf;
    closesocket(soc);
    return true;
}

//提取所有的URL
void HTMLPARSE(string &htmlResponse,vector<string> &imgurls,const string &host)
{
    //将所有链接加入队列中
    const char* p=htmlResponse.c_str();
    char temp_1[10]="href=\"";
    char* tag=temp_1;
    const char* pos=strstr(p,tag);
    ofstream fo("Url.txt",ios::app);
    while(pos)
    {
        pos+=strlen(tag);
        const char* next=strstr(pos,"\"");
        if(next)
        {
            char* url=new char[next-pos+1];
            sscanf(pos,"%[^\"]",url);
            string url_s=url;
            if(visitedUrl.find(url_s)==visitedUrl.end())
            {
                visitedUrl.insert(url_s);
                fo<<url_s<<endl;
                hreFurl.push(url_s);
            }
            pos=strstr(pos,tag);
            delete [] url;
        }
    }
    fo<<endl<<endl;
    fo.close();

    char temp_2[10]="<img";
    tag=temp_2;
    const char* at_1="src=\"";
    const char* at_2="lazy-src=\"";
    const char* pos_0=strstr(p,tag);
    while(pos_0)
    {
        pos_0+=strlen(tag);
        const char* pos_1=strstr(pos_0,at_2);
        if(!pos_1 || pos_1 > strstr(pos_0,">"))
        {
            pos=strstr(pos_0,at_1);
            if(!pos)
            {
                pos_0=strstr(at_1,tag);
                continue;
            }
            else
            {
                pos=pos+strlen(at_1);
            }
        }
        else
        {
            pos=pos_1+strlen(at_2);
        }

        const char* next=strstr(pos,"\"");
        if(next)
        {
            char* url=new char[next-pos+1];
            sscanf(pos,"%[^\"]",url);
            cout<<url<<endl;
            string imgUrl=url;
            
            if(visitedImg.find(imgUrl)==visitedImg.end())
            {
                visitedImg.insert(imgUrl);
                imgurls.push_back(imgUrl);
            }
            pos_0=strstr(pos_0,tag);
            delete [] url;
        }
    }
    cout<<"Saving URL......"<<endl;
}

//把URL转为文件名
string TURNFILENAME(const string &url)
{
    string filename;
    filename.resize(url.size());
    int k=0;
    for(int i=0; i<(int)url.size(); i++)
    {
        char ch=url[i];
        if(ch!='\\' && ch!='/' && ch!='*' && ch!='?' && ch!='"' && ch!=':' && ch!='<' && ch!='>' &&ch!='|')
        {
            filename[k++]=ch;
        }
    }
    return filename.substr(0,k)+".txt";
}

//下载图片到文件夹
void DOWNLOADIMG(vector<string> &imgurls,const string &url)
{
    //生成图片文件夹
    string foldname=TURNFILENAME(url);
    foldname="./img/"+foldname;
    if(!CreateDirectory(foldname.c_str(),NULL))
    {
        cout<<"Error:can not create folder"<<endl;
    }
    char* image;
    int byteRead;
    for(int i=0; i<imgurls.size(); i++)
    {
        //判断是否为图片文件
        string str=imgurls[i];
        int pos=str.find_last_of(".");
        if(pos==string::npos)
        {
            continue;
        }
        else
        {
            string ext=str.substr(pos+1,str.size()-pos-1);
            if(ext!="bmp" && ext!="jpg" && ext!="jpeg" && ext!="gif" && ext!="png")
            continue;
        }

        //下载图片内容
        if(GetHttpResponse(imgurls[i],image,byteRead))
        {
            if(strlen(image)==0)
            {
                continue;
            }
            const char* p=image;
            const char* pos=strstr(p,"\r\n\r\n")+strlen("\r\n\r\n");
            int index=imgurls[i].find_last_of("/");

            if(index!=string::npos)
            {
                string imgname=imgurls[i].substr(index,imgurls[i].size());
                ofstream fo(foldname+imgname,ios::binary);
                if(!fo.is_open())
                {
                    continue;
                }
                cout<<"Saved:"<<endl;
                cout<<_ImgCnt++<<foldname+imgname<<endl;
                fo.write(pos,byteRead-(pos-p));
                fo.close();
            }
            free(image);
        }
    }
}

//(来自Alex_zhang)广度遍历
void BFS( const string & url ){ 
    char * response; 
    int bytes; 
    // 获取网页的相应，放入response中。 
    if( !GetHttpResponse( url, response, bytes ) ){ 
        cout << "The url is wrong! ignore." << endl; 
        return; 
    } 
    string httpResponse=response; 
    free( response ); 
    string filename = TURNFILENAME( url ); 
    ofstream ofile( "./html/"+filename ); 
    if( ofile.is_open() ){ 
        // 保存该网页的文本内容 
        ofile << httpResponse << endl; 
        ofile.close(); 
    } 
    vector<string> imgurls; 
    //解析该网页的所有图片链接，放入imgurls里面 
    HTMLPARSE( httpResponse,  imgurls, url ); 
 
    //下载所有的图片资源 
    DOWNLOADIMG( imgurls, url ); 
}

//----------------//


int main()
{
    cout<<"//*All rights served by GitHub@TualatinZhii 2022*//\n"<<endl;
    
    //初始化套接字
    WSADATA wsadata;
    if(WSAStartup(MAKEWORD(2,2),&wsadata) != 0)
    {
        return true;
    }
    //创建文件夹保存图片和网页文本文件
    CreateDirectory("./img",0);
    CreateDirectory("./html",0);

    string urlStart;
    cout<<"Please give the start website:"<<endl;
    cin>>urlStart;

    BFS(urlStart);

    //保存访问过的网址
    visitedUrl.insert(urlStart);

    //(来自Alex_zhang)遍历网址
    while(hreFurl.size()!=0)
    {
        string url=hreFurl.front();
        cout<<url<<endl;
        BFS(url);
        hreFurl.pop();
    }

    WSACleanup();
    system("pause");
    return 0;
}

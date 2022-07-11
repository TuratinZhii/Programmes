; �ýű�ʹ�� HM VNISEdit �ű��༭���򵼲���

; ��װ�����ʼ���峣��
!define PRODUCT_NAME "ImgCrawler"
!define PRODUCT_VERSION "1.3a"
!define PRODUCT_PUBLISHER "TuratinZhii"
!define PRODUCT_WEB_SITE "https://github.com/TuratinZhii/Programmes"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\CrawlerAlpha.exe"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"

SetCompressor lzma

; ------ MUI �ִ����涨�� (1.67 �汾���ϼ���) ------
!include "MUI.nsh"

; MUI Ԥ���峣��
!define MUI_ABORTWARNING
!define MUI_ICON "D:\VisualStudioCode\����������԰�\�����ļ�\thumb_1000_0_20220528045208348.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall.ico"

; ����ѡ�񴰿ڳ�������
!define MUI_LANGDLL_REGISTRY_ROOT "${PRODUCT_UNINST_ROOT_KEY}"
!define MUI_LANGDLL_REGISTRY_KEY "${PRODUCT_UNINST_KEY}"
!define MUI_LANGDLL_REGISTRY_VALUENAME "NSIS:Language"

; ��ӭҳ��
!insertmacro MUI_PAGE_WELCOME
; ���ѡ��ҳ��
!insertmacro MUI_PAGE_COMPONENTS
; ��װĿ¼ѡ��ҳ��
!insertmacro MUI_PAGE_DIRECTORY
; ��װ����ҳ��
!insertmacro MUI_PAGE_INSTFILES
; ��װ���ҳ��
!define MUI_FINISHPAGE_RUN "$INSTDIR\CrawlerAlpha.exe"
!insertmacro MUI_PAGE_FINISH

; ��װж�ع���ҳ��
!insertmacro MUI_UNPAGE_INSTFILES

; ��װ�����������������
!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "SimpChinese"

; ��װԤ�ͷ��ļ�
!insertmacro MUI_RESERVEFILE_LANGDLL
!insertmacro MUI_RESERVEFILE_INSTALLOPTIONS
; ------ MUI �ִ����涨����� ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "Setup.exe"
InstallDir "$PROGRAMFILES\ImgCrawler"
InstallDirRegKey HKLM "${PRODUCT_UNINST_KEY}" "UninstallString"
ShowInstDetails show
ShowUnInstDetails show

Section "MainSection" SEC01
  SetOutPath "$INSTDIR"
  SetOverwrite ifnewer
  File "D:\VisualStudioCode\����������԰�\����������\CrawlerAlpha.exe"
  CreateDirectory "$SMPROGRAMS\ImgCrawler"
  CreateShortCut "$SMPROGRAMS\ImgCrawler\ImgCrawler.lnk" "$INSTDIR\CrawlerAlpha.exe"
  CreateShortCut "$DESKTOP\ImgCrawler.lnk" "$INSTDIR\CrawlerAlpha.exe"
  File "D:\VisualStudioCode\����������԰�\(��ǰ�ض�)ʹ��ָ��.txt"
  File "D:\VisualStudioCode\����������԰�\�����Լ�.txt"
  File "D:\VisualStudioCode\����������԰�\���԰淢��˵��.txt"
  SetOutPath "$INSTDIR\����������"
  File "D:\VisualStudioCode\����������԰�\����������\CrawlerAlpha.exe.lnk"
  SetOutPath "$INSTDIR\�����ļ�"
  File "D:\VisualStudioCode\����������԰�\�����ļ�\crawleralpha.cpp"
  File "D:\VisualStudioCode\����������԰�\�����ļ�\thumb_1000_0_20220528045208348.ico"
SectionEnd

Section -AdditionalIcons
  SetOutPath $INSTDIR
  WriteIniStr "$INSTDIR\${PRODUCT_NAME}.url" "InternetShortcut" "URL" "${PRODUCT_WEB_SITE}"
  CreateShortCut "$SMPROGRAMS\ImgCrawler\Website.lnk" "$INSTDIR\${PRODUCT_NAME}.url"
  CreateShortCut "$SMPROGRAMS\ImgCrawler\Uninstall.lnk" "$INSTDIR\uninst.exe"
SectionEnd

Section -Post
  WriteUninstaller "$INSTDIR\uninst.exe"
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "" "$INSTDIR\CrawlerAlpha.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayIcon" "$INSTDIR\CrawlerAlpha.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayVersion" "${PRODUCT_VERSION}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "URLInfoAbout" "${PRODUCT_WEB_SITE}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "Publisher" "${PRODUCT_PUBLISHER}"
SectionEnd

#-- ���� NSIS �ű��༭�������� Function ���α�������� Section ����֮���д���Ա��ⰲװ�������δ��Ԥ֪�����⡣--#

; �����������
!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC01} ""
!insertmacro MUI_FUNCTION_DESCRIPTION_END

Function .onInit
  !insertmacro MUI_LANGDLL_DISPLAY
FunctionEnd

/******************************
 *  �����ǰ�װ�����ж�ز���  *
 ******************************/

Section Uninstall
  Delete "$INSTDIR\${PRODUCT_NAME}.url"
  Delete "$INSTDIR\uninst.exe"
  Delete "$INSTDIR\�����ļ�\thumb_1000_0_20220528045208348.ico"
  Delete "$INSTDIR\�����ļ�\crawleralpha.cpp"
  Delete "$INSTDIR\����������\CrawlerAlpha.exe.lnk"
  Delete "$INSTDIR\���԰淢��˵��.txt"
  Delete "$INSTDIR\�����Լ�.txt"
  Delete "$INSTDIR\(��ǰ�ض�)ʹ��ָ��.txt"
  Delete "$INSTDIR\CrawlerAlpha.exe"

  Delete "$SMPROGRAMS\ImgCrawler\Uninstall.lnk"
  Delete "$SMPROGRAMS\ImgCrawler\Website.lnk"
  Delete "$DESKTOP\ImgCrawler.lnk"
  Delete "$SMPROGRAMS\ImgCrawler\ImgCrawler.lnk"

  RMDir "$SMPROGRAMS\ImgCrawler"
  RMDir "$INSTDIR\�����ļ�"
  RMDir "$INSTDIR\����������"

  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
  SetAutoClose true
SectionEnd

#-- ���� NSIS �ű��༭�������� Function ���α�������� Section ����֮���д���Ա��ⰲװ�������δ��Ԥ֪�����⡣--#

Function un.onInit
!insertmacro MUI_UNGETLANGUAGE
  MessageBox MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON2 "��ȷʵҪ��ȫ�Ƴ�ImgCrawler1.3a���������е������" IDYES +2
  Abort
FunctionEnd

Function un.onUninstSuccess
  HideWindow
  MessageBox MB_ICONINFORMATION|MB_OK "ImgCrawler1.3a�ѳɹ��ش����ļ�����Ƴ���"
FunctionEnd

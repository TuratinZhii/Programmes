; 该脚本使用 HM VNISEdit 脚本编辑器向导产生

; 安装程序初始定义常量
!define PRODUCT_NAME "ImgCrawler"
!define PRODUCT_VERSION "1.3a"
!define PRODUCT_PUBLISHER "TuratinZhii"
!define PRODUCT_WEB_SITE "https://github.com/TuratinZhii/Programmes"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\CrawlerAlpha.exe"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"

SetCompressor lzma

; ------ MUI 现代界面定义 (1.67 版本以上兼容) ------
!include "MUI.nsh"

; MUI 预定义常量
!define MUI_ABORTWARNING
!define MUI_ICON "D:\VisualStudioCode\网络爬虫测试版\配置文件\thumb_1000_0_20220528045208348.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall.ico"

; 语言选择窗口常量设置
!define MUI_LANGDLL_REGISTRY_ROOT "${PRODUCT_UNINST_ROOT_KEY}"
!define MUI_LANGDLL_REGISTRY_KEY "${PRODUCT_UNINST_KEY}"
!define MUI_LANGDLL_REGISTRY_VALUENAME "NSIS:Language"

; 欢迎页面
!insertmacro MUI_PAGE_WELCOME
; 组件选择页面
!insertmacro MUI_PAGE_COMPONENTS
; 安装目录选择页面
!insertmacro MUI_PAGE_DIRECTORY
; 安装过程页面
!insertmacro MUI_PAGE_INSTFILES
; 安装完成页面
!define MUI_FINISHPAGE_RUN "$INSTDIR\CrawlerAlpha.exe"
!insertmacro MUI_PAGE_FINISH

; 安装卸载过程页面
!insertmacro MUI_UNPAGE_INSTFILES

; 安装界面包含的语言设置
!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "SimpChinese"

; 安装预释放文件
!insertmacro MUI_RESERVEFILE_LANGDLL
!insertmacro MUI_RESERVEFILE_INSTALLOPTIONS
; ------ MUI 现代界面定义结束 ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "Setup.exe"
InstallDir "$PROGRAMFILES\ImgCrawler"
InstallDirRegKey HKLM "${PRODUCT_UNINST_KEY}" "UninstallString"
ShowInstDetails show
ShowUnInstDetails show

Section "MainSection" SEC01
  SetOutPath "$INSTDIR"
  SetOverwrite ifnewer
  File "D:\VisualStudioCode\网络爬虫测试版\爬虫主程序\CrawlerAlpha.exe"
  CreateDirectory "$SMPROGRAMS\ImgCrawler"
  CreateShortCut "$SMPROGRAMS\ImgCrawler\ImgCrawler.lnk" "$INSTDIR\CrawlerAlpha.exe"
  CreateShortCut "$DESKTOP\ImgCrawler.lnk" "$INSTDIR\CrawlerAlpha.exe"
  File "D:\VisualStudioCode\网络爬虫测试版\(用前必读)使用指南.txt"
  File "D:\VisualStudioCode\网络爬虫测试版\报错自检.txt"
  File "D:\VisualStudioCode\网络爬虫测试版\测试版发行说明.txt"
  SetOutPath "$INSTDIR\爬虫主程序"
  File "D:\VisualStudioCode\网络爬虫测试版\爬虫主程序\CrawlerAlpha.exe.lnk"
  SetOutPath "$INSTDIR\配置文件"
  File "D:\VisualStudioCode\网络爬虫测试版\配置文件\crawleralpha.cpp"
  File "D:\VisualStudioCode\网络爬虫测试版\配置文件\thumb_1000_0_20220528045208348.ico"
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

#-- 根据 NSIS 脚本编辑规则，所有 Function 区段必须放置在 Section 区段之后编写，以避免安装程序出现未可预知的问题。--#

; 区段组件描述
!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC01} ""
!insertmacro MUI_FUNCTION_DESCRIPTION_END

Function .onInit
  !insertmacro MUI_LANGDLL_DISPLAY
FunctionEnd

/******************************
 *  以下是安装程序的卸载部分  *
 ******************************/

Section Uninstall
  Delete "$INSTDIR\${PRODUCT_NAME}.url"
  Delete "$INSTDIR\uninst.exe"
  Delete "$INSTDIR\配置文件\thumb_1000_0_20220528045208348.ico"
  Delete "$INSTDIR\配置文件\crawleralpha.cpp"
  Delete "$INSTDIR\爬虫主程序\CrawlerAlpha.exe.lnk"
  Delete "$INSTDIR\测试版发行说明.txt"
  Delete "$INSTDIR\报错自检.txt"
  Delete "$INSTDIR\(用前必读)使用指南.txt"
  Delete "$INSTDIR\CrawlerAlpha.exe"

  Delete "$SMPROGRAMS\ImgCrawler\Uninstall.lnk"
  Delete "$SMPROGRAMS\ImgCrawler\Website.lnk"
  Delete "$DESKTOP\ImgCrawler.lnk"
  Delete "$SMPROGRAMS\ImgCrawler\ImgCrawler.lnk"

  RMDir "$SMPROGRAMS\ImgCrawler"
  RMDir "$INSTDIR\配置文件"
  RMDir "$INSTDIR\爬虫主程序"

  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
  SetAutoClose true
SectionEnd

#-- 根据 NSIS 脚本编辑规则，所有 Function 区段必须放置在 Section 区段之后编写，以避免安装程序出现未可预知的问题。--#

Function un.onInit
!insertmacro MUI_UNGETLANGUAGE
  MessageBox MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON2 "您确实要完全移除ImgCrawler1.3a，及其所有的组件？" IDYES +2
  Abort
FunctionEnd

Function un.onUninstSuccess
  HideWindow
  MessageBox MB_ICONINFORMATION|MB_OK "ImgCrawler1.3a已成功地从您的计算机移除。"
FunctionEnd

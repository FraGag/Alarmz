SetCompressor /SOLID lzma

; If the execution level isn't set explicitly, shortcuts written to the user's
; start menu will actually be written to the common start menu, and the
; uninstaller will try to delete the shortcuts from the user's start menu,
; but they're not actually there...
RequestExecutionLevel user

!define PRODUCT_NAME "Alarmz"
!define PRODUCT_VERSION "2.0.1"
!define PRODUCT_PUBLISHER "Francis Gagné"
!define PRODUCT_WEB_SITE "http://fragag.ifrance.com/"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\Alarmz.exe"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"
!define PRODUCT_STARTMENU_REGVAL "NSIS:StartMenuDir"

; MUI 1.67 compatible ------
!include "MUI.nsh"

; MUI Settings
!define MUI_ABORTWARNING
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\modern-install.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall.ico"

; Welcome page
!insertmacro MUI_PAGE_WELCOME
; Directory page
!insertmacro MUI_PAGE_DIRECTORY
; Start menu page
var ICONS_GROUP
!define MUI_STARTMENUPAGE_NODISABLE
!define MUI_STARTMENUPAGE_DEFAULTFOLDER "Alarmz"
!define MUI_STARTMENUPAGE_REGISTRY_ROOT "${PRODUCT_UNINST_ROOT_KEY}"
!define MUI_STARTMENUPAGE_REGISTRY_KEY "${PRODUCT_UNINST_KEY}"
!define MUI_STARTMENUPAGE_REGISTRY_VALUENAME "${PRODUCT_STARTMENU_REGVAL}"
!insertmacro MUI_PAGE_STARTMENU Application $ICONS_GROUP
; Instfiles page
!define MUI_LANGDLL_REGISTRY_ROOT "HKCU"
!define MUI_LANGDLL_REGISTRY_KEY "Software\FraGag\Alarmz"
!define MUI_LANGDLL_REGISTRY_VALUENAME "SetupLanguage"
!insertmacro MUI_PAGE_INSTFILES
; Finish page
!define MUI_FINISHPAGE_RUN "$INSTDIR\Alarmz.exe"
!insertmacro MUI_PAGE_FINISH

; Uninstaller pages
!insertmacro MUI_UNPAGE_INSTFILES
!define MUI_CUSTOMFUNCTION_UNGUIINIT "un.Prompt"

; Language files
!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "French"

; MUI end ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "Alarmz201Setup.exe"
InstallDir "$PROGRAMFILES\Alarmz"
InstallDirRegKey HKLM "${PRODUCT_DIR_REGKEY}" ""
ShowInstDetails show
ShowUnInstDetails show

LangString language ${LANG_ENGLISH} "en_US"
LangString language ${LANG_FRENCH} "fr"
LangString website ${LANG_ENGLISH} "Web Site"
LangString website ${LANG_FRENCH} "Site web"
LangString uninstall ${LANG_ENGLISH} "Uninstall"
LangString uninstall ${LANG_FRENCH} "Désinstaller"
LangString uninst_success ${LANG_ENGLISH} "$(^Name) has been successfully uninstalled from your computer."
LangString uninst_success ${LANG_FRENCH} "$(^Name) a été désinstallé avec succès de votre ordinateur."
LangString are_you_sure ${LANG_ENGLISH} "Are you sure you want to completely uninstall $(^Name)?"
LangString are_you_sure ${LANG_FRENCH} "Êtes-vous certain de vouloir désinstaller totalement $(^Name) ?"

Function .onInit
  !insertmacro MUI_LANGDLL_DISPLAY
FunctionEnd

Section "Main" SEC01
  UserInfo::GetAccountType
  Pop $1
  StrCmp $1 "Admin" 0 +3
    SetShellVarContext all
    Goto admin_check_done
  StrCmp $1 "Power" 0 +3
    SetShellVarContext all
    Goto admin_check_done

admin_check_done:
  SetOutPath "$INSTDIR"
  SetOverwrite ifnewer
  Delete "Alarmz.chm" # delete help file from Alarmz 1.x (even though the default installation path changed...)
  File "Alarmz.exe"
  File "libgcc_s_dw2-1.dll"
  File "mingwm10.dll"
  File "QtCore4.dll"
  File "QtGui4.dll"
  File "QtXml4.dll"
  File "Alarmz_fr.qm"
  File "qt_fr.qm"
  SetOutPath "$INSTDIR\imageformats"
  File "imageformats\qico4.dll"
  SetOutPath "$INSTDIR\doc"
  File /r "doc\*"
  
; Language in Registry
  WriteRegStr HKCU "Software\FraGag\Alarmz" "Language" "$(language)"

; Shortcuts
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
  CreateDirectory "$SMPROGRAMS\$ICONS_GROUP"
  CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Alarmz.lnk" "$INSTDIR\Alarmz.exe"
  CreateShortCut "$DESKTOP\Alarmz.lnk" "$INSTDIR\Alarmz.exe"
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section -AdditionalIcons
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
  WriteIniStr "$INSTDIR\${PRODUCT_NAME}.url" "InternetShortcut" "URL" "${PRODUCT_WEB_SITE}"
  CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\$(website).lnk" "$INSTDIR\${PRODUCT_NAME}.url"
  CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\$(uninstall).lnk" "$INSTDIR\uninst.exe"
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section -Post
  WriteUninstaller "$INSTDIR\uninst.exe"
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "" "$INSTDIR\Alarmz.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayIcon" "$INSTDIR\Alarmz.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayVersion" "${PRODUCT_VERSION}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "URLInfoAbout" "${PRODUCT_WEB_SITE}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "Publisher" "${PRODUCT_PUBLISHER}"
SectionEnd


Function un.onUninstSuccess
  HideWindow
  MessageBox MB_ICONINFORMATION|MB_OK "$(uninst_success)"
FunctionEnd

Function un.onInit
  !insertmacro MUI_LANGDLL_DISPLAY
FunctionEnd

Function un.Prompt
  MessageBox MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON2 "$(are_you_sure)" IDYES +2
  Abort
FunctionEnd

Section Uninstall
  UserInfo::GetAccountType
  Pop $1
  StrCmp $1 "Admin" 0 +3
    SetShellVarContext all
    Goto admin_check_done
  StrCmp $1 "Power" 0 +3
    SetShellVarContext all
    Goto admin_check_done

admin_check_done:
  !insertmacro MUI_STARTMENU_GETFOLDER Application $ICONS_GROUP
  Delete "$INSTDIR\${PRODUCT_NAME}.url"
  Delete "$INSTDIR\uninst.exe"
  RMDir /r "$INSTDIR\doc"
  Delete "$INSTDIR\qt_fr.qm"
  Delete "$INSTDIR\Alarmz_fr.qm"
  Delete "$INSTDIR\QtXml4.dll"
  Delete "$INSTDIR\QtGui4.dll"
  Delete "$INSTDIR\QtCore4.dll"
  Delete "$INSTDIR\mingwm10.dll"
  Delete "$INSTDIR\libgcc_s_dw2-1.dll"
  Delete "$INSTDIR\Alarmz.exe"
  RMDir "$INSTDIR"

  Delete "$SMPROGRAMS\$ICONS_GROUP\$(uninstall).lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\$(website).lnk"
  Delete "$DESKTOP\Alarmz.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Alarmz.lnk"

  RMDir "$SMPROGRAMS\$ICONS_GROUP"
  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
  DeleteRegValue ${MUI_LANGDLL_REGISTRY_ROOT} ${MUI_LANGDLL_REGISTRY_KEY} ${MUI_LANGDLL_REGISTRY_VALUENAME}
  SetAutoClose true
SectionEnd
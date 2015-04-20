; Define MinGW to include the MinGW runtime DLLs
; Define X64 to install in $ProgramFiles64 instead of $ProgramFiles

SetCompressor /SOLID lzma

; If the execution level isn't set explicitly, shortcuts written to the user's
; start menu will actually be written to the common start menu, and the
; uninstaller will try to delete the shortcuts from the user's start menu,
; but they're not actually there...
RequestExecutionLevel user

!define PRODUCT_NAME "Alarmz"
!define PRODUCT_VERSION "2.0.3"
!define PRODUCT_PUBLISHER "Francis Gagné"
!define PRODUCT_WEB_SITE "https://bitbucket.org/FraGag/alarmz"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\Alarmz.exe"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "SHCTX"
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
OutFile "Alarmz203Setup.exe"
InstallDir "$LOCALAPPDATA\Alarmz"
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

  UserInfo::GetAccountType
  Pop $1
  StrCmp $1 "Admin" Admin
  StrCmp $1 "Power" Admin
  Goto AdminCheckDone

Admin:
!ifdef X64
  StrCpy $INSTDIR "$PROGRAMFILES64\Alarmz"
!else
  StrCpy $INSTDIR "$PROGRAMFILES\Alarmz"
!endif
  SetShellVarContext all

AdminCheckDone:
FunctionEnd

Section "Main" SEC01
  SetOutPath "$INSTDIR"
  SetOverwrite ifnewer
  Delete "Alarmz.chm" # delete help file from Alarmz 1.x (even though the default installation path changed...)
  File "Alarmz.exe"
!ifdef MinGW
  File "libgcc_s_dw2-1.dll"
  File "libstdc++-6.dll"
  File "libwinpthread-1.dll"
!endif
  File "icudt53.dll"
  File "icuin53.dll"
  File "icuuc53.dll"
  File "Qt5Core.dll"
  File "Qt5Gui.dll"
  File "Qt5Multimedia.dll"
  File "Qt5Network.dll"
  File "Qt5Widgets.dll"
  File "Qt5Xml.dll"
  File "Alarmz_fr.qm"
  File "qt_fr.qm"
  SetOutPath "$INSTDIR\audio"
  File "qtaudio_windows.dll"
  SetOutPath "$INSTDIR\imageformats"
  File "qico.dll"
  SetOutPath "$INSTDIR\platforms"
  File "qwindows.dll"
  SetOutPath "$INSTDIR\doc"
  File /r "doc\*"
  SetOutPath "$INSTDIR"

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
  WriteRegStr SHCTX "${PRODUCT_DIR_REGKEY}" "" "$INSTDIR\Alarmz.exe"
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
  StrCmp $1 "Admin" Admin
  StrCmp $1 "Power" Admin
  Goto AdminCheckDone

Admin:
  SetShellVarContext all

AdminCheckDone:
  !insertmacro MUI_STARTMENU_GETFOLDER Application $ICONS_GROUP
  Delete "$INSTDIR\${PRODUCT_NAME}.url"
  Delete "$INSTDIR\uninst.exe"
  RMDir /r "$INSTDIR\doc"
  RMDir /r "$INSTDIR\platforms"
  RMDir /r "$INSTDIR\imageformats"
  RMDir /r "$INSTDIR\audio"
  Delete "$INSTDIR\qt_fr.qm"
  Delete "$INSTDIR\Alarmz_fr.qm"
  Delete "$INSTDIR\Qt5Xml.dll"
  Delete "$INSTDIR\Qt5Widgets.dll"
  Delete "$INSTDIR\Qt5Network.dll"
  Delete "$INSTDIR\Qt5Multimedia.dll"
  Delete "$INSTDIR\Qt5Gui.dll"
  Delete "$INSTDIR\Qt5Core.dll"
  Delete "$INSTDIR\icuuc53.dll"
  Delete "$INSTDIR\icuin53.dll"
  Delete "$INSTDIR\icudt53.dll"
!ifdef MinGW
  Delete "$INSTDIR\libwinpthread-1.dll"
  Delete "$INSTDIR\libstdc++-6.dll"
  Delete "$INSTDIR\libgcc_s_dw2-1.dll"
!endif
  Delete "$INSTDIR\Alarmz.exe"
  RMDir "$INSTDIR"

  Delete "$SMPROGRAMS\$ICONS_GROUP\$(uninstall).lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\$(website).lnk"
  Delete "$DESKTOP\Alarmz.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Alarmz.lnk"

  RMDir "$SMPROGRAMS\$ICONS_GROUP"
  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey SHCTX "${PRODUCT_DIR_REGKEY}"
  DeleteRegValue ${MUI_LANGDLL_REGISTRY_ROOT} ${MUI_LANGDLL_REGISTRY_KEY} ${MUI_LANGDLL_REGISTRY_VALUENAME}
  SetAutoClose true
SectionEnd
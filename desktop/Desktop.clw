; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainDlg
LastTemplate=CRichEditCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Desktop.h"

ClassCount=6
Class1=CBambooApp
Class2=CMainDlg
Class3=CAboutDlg

ResourceCount=9
Resource1=IDD_DESKTOP_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDR_ACCEL_MAIN
Resource4=IDD_DESKTOP_DIALOG (English (U.S.))
Class4=CCommandEdit
Resource5=IDR_MENU_MAIN
Resource6=IDD_ABOUTBOX (English (U.S.))
Class5=CEnvironmentList
Class6=CCodeEditor
Resource7=IDR_MENU_MAIN (English (U.K.))
Resource8=IDD_ABOUTBOX
Resource9=IDR_ACCEL_MAIN (English (U.K.))

[CLS:CBambooApp]
Type=0
HeaderFile=Desktop.h
ImplementationFile=Desktop.cpp
Filter=N

[CLS:CMainDlg]
Type=0
HeaderFile=src\maindlg.h
ImplementationFile=src\maindlg.cpp
BaseClass=CResizableDialog
LastObject=IDM_MENU_RUN
Filter=D
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MainDlg.h
ImplementationFile=MainDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DESKTOP_DIALOG]
Type=1
Class=CMainDlg
ControlCount=5
Control1=IDC_STATIC_ENV,button,1342177287
Control2=IDC_LIST_ENV,SysListView32,1350631429
Control3=IDC_STATIC_SCRATCHPAD,button,1342177287
Control4=IDC_EDIT_COMMAND,edit,1352732676
Control5=IDC_RICH_EDITOR,RICHEDIT,1353781444

[DLG:IDD_DESKTOP_DIALOG (English (U.S.))]
Type=1
Class=CMainDlg
ControlCount=5
Control1=IDC_STATIC_ENV,button,1342177287
Control2=IDC_LIST_ENV,SysListView32,1350631429
Control3=IDC_STATIC_SCRATCHPAD,button,1342177287
Control4=IDC_EDIT_COMMAND,edit,1352732676
Control5=IDC_RICH_EDITOR,RICHEDIT,1353781444

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CCommandEdit]
Type=0
HeaderFile=src\CommandEdit.h
ImplementationFile=src\CommandEdit.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC
LastObject=CCommandEdit

[MNU:IDR_MENU_MAIN]
Type=1
Class=CMainDlg
Command1=IDM_MENU_FILE_EXIT
Command2=IDM_MENU_RUN
Command3=IDM_MENU_HELP_ABOUT
CommandCount=3

[ACL:IDR_ACCEL_MAIN]
Type=1
Class=CMainDlg
Command1=IDA_ACCEL_QUIT
Command2=IDA_ACCEL_HELP
CommandCount=2

[CLS:CEnvironmentList]
Type=0
HeaderFile=src\EnvironmentList.h
ImplementationFile=src\EnvironmentList.cpp
BaseClass=CListCtrl
Filter=W
LastObject=CEnvironmentList

[CLS:CCodeEditor]
Type=0
HeaderFile=src\CodeEditor.h
ImplementationFile=src\CodeEditor.cpp
BaseClass=CRichEditCtrl
Filter=W

[MNU:IDR_MENU_MAIN (English (U.K.))]
Type=1
Class=?
Command1=IDM_MENU_FILE_EXIT
Command2=IDM_MENU_RUN
Command3=IDM_MENU_HELP_ABOUT
CommandCount=3

[ACL:IDR_ACCEL_MAIN (English (U.K.))]
Type=1
Class=?
Command1=IDA_ACCEL_QUIT
Command2=IDA_ACCEL_HELP
CommandCount=2


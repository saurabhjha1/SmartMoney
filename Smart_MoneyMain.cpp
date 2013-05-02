/***************************************************************
 * Name:      Smart_MoneyMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Saurabh Jha (saurabhjha2010@gmail.com)
 * Created:   2011-10-29
 * Copyright: Saurabh Jha (http://saurabhjha.in)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Smart_MoneyMain.h"
#include <wx/msgdlg.h>

#include "mydbsingleton.h"
#include "NewRegisterForm.h"
#include "TransactionForm.h"

//(*InternalHeaders(Smart_MoneyFrame)
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

//helper functions

//* Heade file for db connection
#include <mysql++.h>
#include <string>
#include "student.h"
// dbconnect function


using namespace mysqlpp;
//*
enum wxbuildinfoformat
{
    short_f, long_f
};
//std::string SqlQuery;
wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Smart_MoneyFrame)
const long Smart_MoneyFrame::ID_STATICTEXT1 = wxNewId();
const long Smart_MoneyFrame::ID_STATICTEXT2 = wxNewId();
const long Smart_MoneyFrame::ID_TEXTCTRL1 = wxNewId();
const long Smart_MoneyFrame::ID_STATICTEXT3 = wxNewId();
const long Smart_MoneyFrame::ID_TEXTCTRL2 = wxNewId();
const long Smart_MoneyFrame::ID_BUTTON1 = wxNewId();
const long Smart_MoneyFrame::ID_BUTTON2 = wxNewId();
const long Smart_MoneyFrame::ID_PANEL1 = wxNewId();
const long Smart_MoneyFrame::idMenuQuit = wxNewId();
const long Smart_MoneyFrame::idMenuAbout = wxNewId();
const long Smart_MoneyFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Smart_MoneyFrame,wxFrame)
    //(*EventTable(Smart_MoneyFrame)
    //*)
END_EVENT_TABLE()

Smart_MoneyFrame::Smart_MoneyFrame(wxWindow* parent,wxWindowID id)
{

    //(*Initialize(Smart_MoneyFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("Login Form"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxSYSTEM_MENU|wxFRAME_NO_TASKBAR, _T("wxID_ANY"));
    SetClientSize(wxSize(368,250));
    SetMinSize(wxSize(368,250));
    SetMaxSize(wxSize(368,250));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ADD_BOOKMARK")),wxART_FRAME_ICON));
    	SetIcon(FrameIcon);
    }
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,56), wxSize(528,264), wxSIMPLE_BORDER|wxRAISED_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Login Form"), wxPoint(120,24), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DDKSHADOW));
    wxFont StaticText1Font(14,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("User id"), wxPoint(48,64), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    TextLoginId = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(144,64), wxSize(199,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextLoginId->SetMaxLength(10);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Password"), wxPoint(48,120), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont StaticText3Font(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    TextPassword = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxPoint(144,120), wxSize(199,27), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Login"), wxPoint(144,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("New user"), wxPoint(272,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Center();

//    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Smart_MoneyFrame::OnTextLoginIdText);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Smart_MoneyFrame::OnButton1Click1);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Smart_MoneyFrame::OnButton2Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Smart_MoneyFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Smart_MoneyFrame::OnAbout);
    //*)
}

Smart_MoneyFrame::~Smart_MoneyFrame()
{
    //(*Destroy(Smart_MoneyFrame)
    //*)
}

void Smart_MoneyFrame::OnQuit(wxCommandEvent& event)
{
    this->InitDialog();
    Close();
}

void Smart_MoneyFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Smart_MoneyFrame::OnButton1Click(wxCommandEvent& event)
{Smart_MoneyFrame* Frame = new Smart_MoneyFrame(0);
    wxMessageBox(_T("hello"));
}


void Smart_MoneyFrame::OnMyUserSubmitButtonClick(wxCommandEvent& event)
{
    wxMessageBox(_T("Submit Successful"));
}

void Smart_MoneyFrame::OnButton1Click1(wxCommandEvent& event)
{
  //wxMessageBox(_T("HELLO"));
  bool login_status=0;
std::string SqlQuery;
  SqlQuery="Select User_id,Password from user";
   std::string tmp;

  std::vector<std::string> ex = mydbSingleton::getInstance().listTable(SqlQuery);
 std::vector<std::string>::const_iterator vec;
int i=0;
 for(vec=ex.begin();vec!=ex.end();vec=vec+2,i=i+2)
 {
   //wxMessageBox(wxString::FromUTF8(ex[i].c_str()));


    if((this->TextLoginId->GetValue() == wxString::FromUTF8(ex[i].c_str()))&&(this->TextPassword->GetValue()==wxString::FromUTF8(ex[i+1].c_str())))
        {
            wxMessageBox(wxString::FromUTF8(ex[i].c_str()));
            tmp = ex[i];
            login_status=1;
            break;
        }

 }
 if(login_status==1){
 wxMessageBox(_T("Login Successful"));
  this->Show(false);
 TransactionForm* LoguserFrame = new TransactionForm(0, new student(tmp));
 LoguserFrame->Show();
 this->Close();
  // hide the windows now
 // and load the next module.

 }
 else wxMessageBox(_T("OOPS!!! Wrong login details. Enter again...."));

}





void Smart_MoneyFrame::OnButton2Click(wxCommandEvent& event)
{
   // this->hidden(true);
    this->Show(false);
   NewRegisterForm* newuserFrame = new NewRegisterForm(0);
   newuserFrame->Show();
   this->Close();



}



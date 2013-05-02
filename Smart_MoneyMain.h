/***************************************************************
 * Name:      Smart_MoneyMain.h
 * Purpose:   Defines Application Frame
 * Author:    Saurabh Jha (saurabhjha2010@@gmail.com)
 * Created:   2011-10-29
 * Copyright: Saurabh Jha (http://saurabhjha.in)
 * License:
 **************************************************************/

#ifndef SMART_MONEYMAIN_H
#define SMART_MONEYMAIN_H

//(*Headers(Smart_MoneyFrame)
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Smart_MoneyFrame: public wxFrame
{
public:

    Smart_MoneyFrame(wxWindow* parent,wxWindowID id = -1);
    virtual ~Smart_MoneyFrame();
    wxTextCtrl* TextLoginId;



private:

    //(*Handlers(Smart_MoneyFrame)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnButton1Click(wxCommandEvent& event);
    void OnMyUserSubmitButtonClick(wxCommandEvent& event);
    void OnButton1Click1(wxCommandEvent& event);
    void OnButton2Click(wxCommandEvent& event);
    void OnTextLoginIdText(wxCommandEvent& event);
    //*)

    //(*Identifiers(Smart_MoneyFrame)
    static const long ID_STATICTEXT1;
    static const long ID_STATICTEXT2;
    static const long ID_TEXTCTRL1;
    static const long ID_STATICTEXT3;
    static const long ID_TEXTCTRL2;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_PANEL1;
    static const long idMenuQuit;
    static const long idMenuAbout;
    static const long ID_STATUSBAR1;
    //*)

    //(*Declarations(Smart_MoneyFrame)
    wxPanel* Panel1;
    wxStatusBar* StatusBar1;
    wxButton* Button1;
    wxButton* Button2;
    wxStaticText* StaticText1;
    wxStaticText* StaticText3;
    wxStaticText* StaticText2;
    wxTextCtrl* TextPassword;
    wxTextCtrl* TextLoginId;
    //*)

    DECLARE_EVENT_TABLE()
};

#endif // SMART_MONEYMAIN_H

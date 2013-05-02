#include "wx_pch.h"
#include "NewRegisterForm.h"
#include "user.h"
#include "student.h"
#include "faculty.h"
#include "guardian.h"
#include "myfunctionclass.h"
#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(NewRegisterForm)
	//*)
#endif
//(*InternalHeaders(NewRegisterForm)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(NewRegisterForm)
//*)

BEGIN_EVENT_TABLE(NewRegisterForm,wxFrame)
	//(*EventTable(NewRegisterForm)
	//*)
END_EVENT_TABLE()

NewRegisterForm::NewRegisterForm(wxWindow* parent)
{
    this->wxWindow::SetFocus();

	//(*Initialize(NewRegisterForm)
	wxXmlResource::Get()->LoadObject(this,parent,_T("NewRegisterForm"),_T("wxFrame"));
	StaticText1 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT1"));
	StaticText2 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT2"));
	TextCtrl_FirstName = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_FIRSTNAME"));
	StaticText3 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT3"));
	TextCtrl_LastName = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_LASTNAME"));
	StaticText4 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT4"));
	TextCtrl_Address = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_ADDRESS"));
	StaticText5 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT5"));
	TextCtrl_City = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_CITY"));
	StaticText6 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT6"));
	TextCtrl_State = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_STATE"));
	StaticText7 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT7"));
	TextCtrl_Pin = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_PIN"));
	StaticText8 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT8"));
	TextCtrl_Mobile = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_MOBILE"));
	StaticText9 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT9"));
	TextCtrl_Email = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_EMAIL"));
	StaticText10 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT10"));
	TextCtrl_Password = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_PASSWORD"));
	StaticText11 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT11"));
	TextCtrl_TransPin = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_TRANSACTIONPIN"));
	StaticText_BloodGroup = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT12"));
	TextCtrl_BloodGroup = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_BLOOOUP"));
	StaticText_Type = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT13"));
	Choice_Type = (wxChoice*)FindWindow(XRCID("ID_CHOICE_TYPE"));
	Button_Submit = (wxButton*)FindWindow(XRCID("ID_BUTTON_SUBMT"));
	Button_Reset = (wxButton*)FindWindow(XRCID("ID_BUTTON_RESET"));
	StaticText_DOB = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT_DOB"));
	TextCtrl_DOB = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_DOB"));
	StaticLine1 = (wxStaticLine*)FindWindow(XRCID("ID_STATICLINE1"));
	StaticTextFaculty = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT19"));
	StaticTextEmployeeID = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT20"));
	TextCtrl_EmployeeID = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL5"));
	StaticTextDepartment = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT_DEPARTMENT"));
	TextCtrl_Dept = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_Department"));
	Panel_Faculty = (wxPanel*)FindWindow(XRCID("ID_PANEL1"));
	StaticText_Student = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT14"));
	StaticText_Registration = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT15"));
	StaticText_Father = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT16"));
	StaticText_FatherContact = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT17"));
	TextCtrl_Registration = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL1"));
	TextCtrl_GuardianName = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL2"));
	TextCtrl_GuardianContact = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL3"));
	StaticText_GuardianId = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT18"));
	TextCtrl_GuardianID = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL4"));
	Panel_Student = (wxPanel*)FindWindow(XRCID("ID_PANEL2"));
	StaticTextAdetails = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT_ADDITIONALDETAILS"));
	Panel1 = (wxPanel*)FindWindow(XRCID("ID_PANEL_REGISTER"));

	Connect(XRCID("ID_CHOICE_TYPE"),wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&NewRegisterForm::OnChoice_TypeSelect);
	Connect(XRCID("ID_BUTTON_SUBMT"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&NewRegisterForm::OnButton_SubmitClick);
	Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&NewRegisterForm::OnPanel1Paint,0,this);
	//*)
}

NewRegisterForm::~NewRegisterForm()
{
	//(*Destroy(NewRegisterForm)
	//*)
}


void NewRegisterForm::OnButton_SubmitClick(wxCommandEvent& event)
{
    std::string user_type;
    MyFunctionClass str;
    std::string string1;
    std::string SqlQuery;
    string1=str.ConvertToString(this->TextCtrl_City);
    //wxMessageBox((wxString::FromUTF8(string1.c_str())));

    user *NewUser;
    student NewStudent;
    faculty NewFaculty;
    guardian NewGuardian;

    //Determines the type of user that is registering
    if(this->Choice_Type->GetCurrentSelection()==0)
    {

        NewUser=&NewStudent;
        user_type="Student";
        NewUser->writeDetails(str.ConvertToString(this->TextCtrl_FirstName),str.ConvertToString(this->TextCtrl_LastName),str.ConvertToString(this->TextCtrl_Address),str.ConvertToString( this->TextCtrl_City),str.ConvertToString(this->TextCtrl_State),str.ConvertToString(this->TextCtrl_Pin),str.ConvertToString(this->TextCtrl_TransPin),str.ConvertToString(TextCtrl_Mobile),str.ConvertToString(this->TextCtrl_Email),str.ConvertToString(this->TextCtrl_DOB),str.ConvertToString(this->TextCtrl_Password),str.ConvertToString(this->TextCtrl_BloodGroup),0,user_type,str.ConvertToString(this->TextCtrl_Registration),str.ConvertToString(this->TextCtrl_GuardianName),str.ConvertToString(this->TextCtrl_GuardianID),str.ConvertToString(this->TextCtrl_GuardianContact));

    }
    if(this->Choice_Type->GetCurrentSelection()==1)
    {

        NewUser=&NewFaculty;
        user_type="Faculty";
        NewUser->writeDetails(str.ConvertToString(this->TextCtrl_FirstName),str.ConvertToString(this->TextCtrl_LastName),str.ConvertToString(this->TextCtrl_Address),str.ConvertToString( this->TextCtrl_City),str.ConvertToString(this->TextCtrl_State),str.ConvertToString(this->TextCtrl_Pin),str.ConvertToString(this->TextCtrl_TransPin),str.ConvertToString(TextCtrl_Mobile),str.ConvertToString(this->TextCtrl_Email),str.ConvertToString(this->TextCtrl_DOB),str.ConvertToString(this->TextCtrl_Password),str.ConvertToString(this->TextCtrl_BloodGroup),0,user_type,str.ConvertToString(this->TextCtrl_EmployeeID),str.ConvertToString(this->TextCtrl_Dept),str.ConvertToString(this->TextCtrl_GuardianID),str.ConvertToString(this->TextCtrl_GuardianContact));


    }
    if(this->Choice_Type->GetCurrentSelection()==2)
    {

        user_type="Guardian";
        NewUser=&NewGuardian;
        NewUser->writeDetails(str.ConvertToString(this->TextCtrl_FirstName),str.ConvertToString(this->TextCtrl_LastName),str.ConvertToString(this->TextCtrl_Address),str.ConvertToString( this->TextCtrl_City),str.ConvertToString(this->TextCtrl_State),str.ConvertToString(this->TextCtrl_Pin),str.ConvertToString(this->TextCtrl_TransPin),str.ConvertToString(TextCtrl_Mobile),str.ConvertToString(this->TextCtrl_Email),str.ConvertToString(this->TextCtrl_DOB),str.ConvertToString(this->TextCtrl_Password),str.ConvertToString(this->TextCtrl_BloodGroup),0,user_type,str.ConvertToString(this->TextCtrl_EmployeeID),str.ConvertToString(this->TextCtrl_Dept),str.ConvertToString(this->TextCtrl_GuardianID),str.ConvertToString(this->TextCtrl_GuardianContact));


    }

     wxMessageBox(_T("WRITING TO DB"));

     NewUser->writeDb();
     NewUser->getDetails();
     wxMessageBox(_T("Thankyou for registering"));
     string createdid="Your User ID is :";
     createdid=createdid+NewUser->getUserId()+"\n This will be used for further reference.";
    wxMessageBox(wxString::FromUTF8((createdid.c_str())));


    this->TextCtrl_Address->SetValue(_T(""));
    this->TextCtrl_BloodGroup->SetValue(_T(""));
    this->TextCtrl_City->SetValue(_T(""));
    this->TextCtrl_City->SetValue(_T(""));
    this->TextCtrl_Dept->SetValue(_T(""));
    this->TextCtrl_DOB->SetValue(_T(""));
    this->TextCtrl_Email->SetValue(_T(""));
    this->TextCtrl_EmployeeID->SetValue(_T(""));
    this->TextCtrl_GuardianName->SetValue(_T(""));
    this->TextCtrl_FirstName->SetValue(_T(""));
    this->TextCtrl_LastName->SetValue(_T(""));
    this->TextCtrl_GuardianID->SetValue(_T(""));
    this->TextCtrl_Mobile->SetValue(_T(""));
    this->TextCtrl_Password->SetValue(_T(""));
    this->TextCtrl_Pin->SetValue(_T(""));
    this->TextCtrl_Registration->SetValue(_T(""));
    this->TextCtrl_State->SetValue(_T(""));
    this->TextCtrl_TransPin->SetValue(_T(""));
    this->TextCtrl_GuardianContact->SetValue(_T(""));

     //delete NewUser;
}


void NewRegisterForm::OnClose(wxCloseEvent& event)
{


}

void NewRegisterForm::OnPanel1Paint(wxPaintEvent& event)
{
}

void NewRegisterForm::OnPanel2Paint(wxPaintEvent& event)
{
}

void NewRegisterForm::OnChoice_TypeSelect(wxCommandEvent& event)
{
    // guardian is selected
     if(this->Choice_Type->GetCurrentSelection()==2)
     {
       this->Panel_Student->wxWindow::Show(false);
       this->Panel_Faculty->wxWindow::Show(false);
     }
     //if Student is selected
      if(this->Choice_Type->GetCurrentSelection()==0)
     {
       this->Panel_Student->wxWindow::Show(true);
       this->Panel_Faculty->wxWindow::Show(false);
     }
     //if faculty is selected
      if(this->Choice_Type->GetCurrentSelection()==1)
     {
       this->Panel_Student->wxWindow::Show(false);
       this->Panel_Faculty->wxWindow::Show(true);
     }
}
// Resets the registration form
void NewRegisterForm::OnButton_ResetClick(wxCommandEvent& event)
{
    this->TextCtrl_Address->SetValue(_T(""));
    this->TextCtrl_BloodGroup->SetValue(_T(""));
    this->TextCtrl_City->SetValue(_T(""));
    this->TextCtrl_City->SetValue(_T(""));
    this->TextCtrl_Dept->SetValue(_T(""));
    this->TextCtrl_DOB->SetValue(_T(""));
    this->TextCtrl_Email->SetValue(_T(""));
    this->TextCtrl_EmployeeID->SetValue(_T(""));
    this->TextCtrl_GuardianName->SetValue(_T(""));
    this->TextCtrl_FirstName->SetValue(_T(""));
    this->TextCtrl_LastName->SetValue(_T(""));
    this->TextCtrl_GuardianID->SetValue(_T(""));
    this->TextCtrl_Mobile->SetValue(_T(""));
    this->TextCtrl_Password->SetValue(_T(""));
    this->TextCtrl_Pin->SetValue(_T(""));
    this->TextCtrl_Registration->SetValue(_T(""));
    this->TextCtrl_State->SetValue(_T(""));
    this->TextCtrl_TransPin->SetValue(_T(""));
    this->TextCtrl_GuardianContact->SetValue(_T(""));
}

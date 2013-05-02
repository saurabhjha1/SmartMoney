#ifndef NEWREGISTERFORM_H
#define NEWREGISTERFORM_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(NewRegisterForm)
	#include <wx/button.h>
	#include <wx/panel.h>
	#include <wx/frame.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	#include <wx/choice.h>
	//*)
#endif
//(*Headers(NewRegisterForm)
#include <wx/statline.h>
//*)

class NewRegisterForm: public wxFrame
{
	public:

		NewRegisterForm(wxWindow* parent);
		virtual ~NewRegisterForm();

		//(*Declarations(NewRegisterForm)
		wxTextCtrl* TextCtrl_LastName;
		wxPanel* Panel1;
		wxStaticText* StaticText_Father;
		wxButton* Button_Reset;
		wxTextCtrl* TextCtrl_EmployeeID;
		wxTextCtrl* TextCtrl_Password;
		wxStaticText* StaticText_Type;
		wxButton* Button_Submit;
		wxTextCtrl* TextCtrl_Registration;
		wxTextCtrl* TextCtrl_GuardianContact;
		wxTextCtrl* TextCtrl_Address;
		wxStaticText* StaticTextAdetails;
		wxStaticText* StaticText_Registration;
		wxStaticText* StaticTextDepartment;
		wxStaticText* StaticText1;
		wxStaticText* StaticText_FatherContact;
		wxStaticText* StaticText10;
		wxTextCtrl* TextCtrl_Dept;
		wxStaticText* StaticText_DOB;
		wxStaticText* StaticText3;
		wxChoice* Choice_Type;
		wxTextCtrl* TextCtrl_GuardianName;
		wxStaticLine* StaticLine1;
		wxStaticText* StaticText_BloodGroup;
		wxStaticText* StaticText8;
		wxTextCtrl* TextCtrl_TransPin;
		wxTextCtrl* TextCtrl_BloodGroup;
		wxStaticText* StaticText7;
		wxTextCtrl* TextCtrl_GuardianID;
		wxTextCtrl* TextCtrl_Email;
		wxTextCtrl* TextCtrl_FirstName;
		wxStaticText* StaticText4;
		wxStaticText* StaticText_GuardianId;
		wxTextCtrl* TextCtrl_Pin;
		wxStaticText* StaticText5;
		wxPanel* Panel_Faculty;
		wxStaticText* StaticText2;
		wxStaticText* StaticTextEmployeeID;
		wxStaticText* StaticText6;
		wxStaticText* StaticText_Student;
		wxTextCtrl* TextCtrl_State;
		wxTextCtrl* TextCtrl_City;
		wxPanel* Panel_Student;
		wxTextCtrl* TextCtrl_DOB;
		wxTextCtrl* TextCtrl_Mobile;
		wxStaticText* StaticText9;
		wxStaticText* StaticTextFaculty;
		wxStaticText* StaticText11;
		//*)

	protected:

		//(*Identifiers(NewRegisterForm)
		//*)

	private:

		//(*Handlers(NewRegisterForm)
		void OnButton_SubmitClick(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		void OnPanel1Paint(wxPaintEvent& event);
		void OnPanel2Paint(wxPaintEvent& event);
		void OnChoice_TypeSelect(wxCommandEvent& event);
		void OnButton_ResetClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif

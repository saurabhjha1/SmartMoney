#ifndef TRANSACTIONFORM_H
#define TRANSACTIONFORM_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(TransactionForm)
	#include <wx/button.h>
	#include <wx/panel.h>
	#include <wx/frame.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	//*)
#endif
//(*Headers(TransactionForm)
#include <wx/statline.h>
//*)

#include "user.h"

class TransactionForm: public wxFrame
{
	public:

		TransactionForm(wxWindow* parent, user *obj);
		virtual ~TransactionForm();

		//(*Declarations(TransactionForm)
		wxTextCtrl* TextCtrl_To_amt_1;
		wxStaticText* StaticText13;
		wxStaticText* StaticText14;
		wxStaticText* StaticText15;
		wxTextCtrl* TextCtrl_To_3;
		wxStaticLine* StaticLine2;
		wxStaticText* StaticText_AccNo;
		wxTextCtrl* TextCtrl_To_Amount;
		wxStaticText* statfrmaccount;
		wxTextCtrl* TextCtrl_ToAccnt_Admin;
		wxStaticText* StaticText_BalanceValue;
		wxTextCtrl* TextCtrl_Amt_Admin;
		wxButton* Button_Withdraw;
		wxButton* Button1;
		wxTextCtrl* TextCtrl_To_Amt_3;
		wxStaticText* StaticText1;
		wxStaticText* StaticText10;
		wxStaticText* StaticText_AccountDetails;
		wxStaticText* StaticText16;
		wxTextCtrl* TextCtrl_Wamt;
		wxStaticText* StaticText3;
		wxStaticLine* StaticLine1;
		wxTextCtrl* TextCtrl_TransAccount;
		wxStaticText* StaticText8;
		wxStaticText* StaticText12;
		wxStaticText* StaticText_CurrenBalance;
		wxStaticText* StaticText_proName;
		wxStaticText* StaticText7;
		wxButton* Button_Create;
		wxTextCtrl* TextCtrl_To_1;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText2;
		wxPanel* TransactionPanel;
		wxButton* Button_LoadDetails;
		wxButton* SubmitTransfer;
		wxTextCtrl* TextCtrl_To_amt_2;
		wxPanel* Panel_admin;
		wxStaticText* StaticText6;
		wxTextCtrl* TextCtrl_To_2;
		wxButton* Button_LogOut;
		wxTextCtrl* TextCtrl_FrmAccnt_Admin;
		wxTextCtrl* TextCtrl_CreateAcc;
		wxStaticText* StaticText9;
		wxStaticText* StaticText11;
		//*)

	protected:

		//(*Identifiers(TransactionForm)
		//*)

		user *mUser;

	private:

		//(*Handlers(TransactionForm)
		void OnButton_LoadDetailsClick(wxCommandEvent& event);
		void OnSubmitTransferClick(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton_WithdrawClick(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton_CreateClick(wxCommandEvent& event);
		void OnButton_LogOutClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif

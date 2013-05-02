#include "wx_pch.h"
#include "TransactionForm.h"
#include "bankaccounts.h"
#include "user.h"
#include "student.h"
#include "faculty.h"
#include "guardian.h"
#include "mydbsingleton.h"
#include "myfunctionclass.h"
#include <string>
#include "Smart_MoneyMain.h"
#include "admin.h"
#include <wx/hyperlink.h>
using namespace std;

#ifndef WX_PRECOMP
//(*InternalHeadersPCH(TransactionForm)
//*)
#endif
//(*InternalHeaders(TransactionForm)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(TransactionForm)
//*)
bankAccounts Logbank; // keeps track of the user bank account currently logged on

string UId;          // User id of logged in user
string UType;        // Type of user currently logged in
string UAcc;         // Account id of currently logged in user
string SqlQuery;     // to store SQL Queries
user *LogUser;

student LogStudent;
faculty LogFaculty;
guardian LogGuardian;
Admin LogAdmin;

BEGIN_EVENT_TABLE(TransactionForm,wxFrame)
    //(*EventTable(TransactionForm)
    //*)
END_EVENT_TABLE()

TransactionForm::TransactionForm(wxWindow* parent, user *obj)
{


    //(*Initialize(TransactionForm)
    wxXmlResource::Get()->LoadObject(this,parent,_T("TransactionForm"),_T("wxFrame"));
    StaticLine1 = (wxStaticLine*)FindWindow(XRCID("ID_STATICLINE1"));
    StaticText_AccountDetails = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT1"));
    StaticText_CurrenBalance = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT2"));
    StaticText_BalanceValue = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT_BALANCEVALUE"));
    StaticText1 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT3"));
    StaticText2 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT4"));
    StaticText3 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT5"));
    StaticText4 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT6"));
    TextCtrl_To_1 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL1"));
    TextCtrl_To_amt_1 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL2"));
    TextCtrl_To_2 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL3"));
    TextCtrl_To_amt_2 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL4"));
    TextCtrl_To_3 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL5"));
    TextCtrl_To_Amt_3 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL6"));
    StaticLine2 = (wxStaticLine*)FindWindow(XRCID("ID_STATICLINE2"));
    StaticText5 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT7"));
    StaticText6 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT8"));
    TextCtrl_TransAccount = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL7"));
    StaticText7 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT9"));
    TextCtrl_To_Amount = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL8"));
    SubmitTransfer = (wxButton*)FindWindow(XRCID("ID_BUTTON1"));
    StaticText8 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT10"));
    StaticText9 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT11"));
    statfrmaccount = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT12"));
    TextCtrl_FrmAccnt_Admin = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL9"));
    StaticText10 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT13"));
    TextCtrl_ToAccnt_Admin = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL10"));
    StaticText11 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT14"));
    TextCtrl_Amt_Admin = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL11"));
    Button1 = (wxButton*)FindWindow(XRCID("ID_BUTTON2"));
    StaticText14 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT18"));
    StaticText15 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT19"));
    TextCtrl_CreateAcc = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL13"));
    Button_Create = (wxButton*)FindWindow(XRCID("ID_BUTTON_CREATE"));
    Panel_admin = (wxPanel*)FindWindow(XRCID("ID_PANEL1"));
    Button_LoadDetails = (wxButton*)FindWindow(XRCID("ID_BUTTON3"));
    StaticText12 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT15"));
    TextCtrl_Wamt = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL12"));
    StaticText13 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT16"));
    Button_Withdraw = (wxButton*)FindWindow(XRCID("ID_BUTTON4"));
    StaticText_proName = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT17"));
    StaticText16 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT20"));
    StaticText_AccNo = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT21"));
    Button_LogOut = (wxButton*)FindWindow(XRCID("ID_BUTTON5"));
    TransactionPanel = (wxPanel*)FindWindow(XRCID("ID_PANEL_TRANSACTION"));

    Connect(XRCID("ID_BUTTON1"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TransactionForm::OnSubmitTransferClick);
    Connect(XRCID("ID_BUTTON2"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TransactionForm::OnButton1Click);
    Connect(XRCID("ID_BUTTON_CREATE"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TransactionForm::OnButton_CreateClick);
    Connect(XRCID("ID_BUTTON3"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TransactionForm::OnButton_LoadDetailsClick);
    Connect(XRCID("ID_BUTTON4"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TransactionForm::OnButton_WithdrawClick);
    Connect(XRCID("ID_BUTTON5"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TransactionForm::OnButton_LogOutClick);
    //*)

    this->mUser = obj;
}

TransactionForm::~TransactionForm()
{
    //(*Destroy(TransactionForm)
    //*)
}



/** This function load the details and keeps track of user activities when LOAD DETAILS is clikced */
void TransactionForm::OnButton_LoadDetailsClick(wxCommandEvent& event)
{

    MyFunctionClass str; // calling my function class to create an object to execute special conversion functions of wxString and string
    UId= this->mUser->getLoginId();
    UAcc=Logbank.account_number(UId);
    Logbank.get_details(UAcc);

    wxMessageBox(wxString::FromUTF8(UId.c_str()));
    SqlQuery="SELECT type FROM `user` WHERE User_id='"+UId+"'";
    std::vector<std::string> ex = mydbSingleton::getInstance().listTable(SqlQuery);
    UType=ex[0];

    wxMessageBox(wxString::FromUTF8(UType.c_str()));


    // if the user is student then following action is taken
    if(UType=="Student")
    {
        LogUser=&LogStudent;
        LogUser->readDb(UId);

        string UName="Hi "+LogStudent.getName();
        this->StaticText_proName->SetLabel(wxString::FromUTF8(UName.c_str()));
        this->StaticText_AccNo->SetLabel(wxString::FromUTF8((UAcc.c_str())));
        wxMessageBox(wxString::FromUTF8(UAcc.c_str()));

        std::string strBalance;
        std::stringstream out;
        out << Logbank.getBalance();
        strBalance = out.str();
        wxMessageBox(wxString::FromUTF8(strBalance.c_str()));
        this->StaticText_BalanceValue->SetLabel(wxString::FromUTF8(strBalance.c_str()));

        SqlQuery="SELECT `FrmAccount`, `ToAccount` , `Amount`, `Description` FROM `tansactionHistory` WHERE FrmAccount='";
        SqlQuery=SqlQuery+Logbank.account_number(UId)+"' OR ToAccount='";
        SqlQuery=SqlQuery+Logbank.account_number(UId)+"' ORDER BY Id DESC";
        ex = mydbSingleton::getInstance().listTable(SqlQuery);


        int size=(int)ex.size();

        // load last 3 transactions of the student
        if(size>=12)
        {
            if(ex[3]=="Deposit")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Withdraw")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Transfer")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(ex[1].c_str()));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }


            if(ex[7]=="Deposit")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }
            else if(ex[7]=="Withdraw")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }
            else if(ex[7]=="Transfer")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8((ex[5].c_str())));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }
            if(ex[11]=="Deposit")
            {
                this->TextCtrl_To_3->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_Amt_3->SetValue(wxString::FromUTF8((ex[10].c_str())));

            }

            else if(ex[11]=="Withdraw")
            {
                this->TextCtrl_To_3->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_Amt_3->SetValue(wxString::FromUTF8((ex[10].c_str())));

            }

            else if(ex[11]=="Transfer")
            {
                this->TextCtrl_To_3->SetValue(wxString::FromUTF8((ex[9].c_str())));
                this->TextCtrl_To_Amt_3->SetValue(wxString::FromUTF8((ex[10].c_str())));

            }
        }
        if(size==8)
        {
            if(ex[3]=="Deposit")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Withdraw")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Transfer")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(ex[1].c_str()));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }


            if(ex[7]=="Deposit")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }
            else if(ex[7]=="Withdraw")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }
            else if(ex[7]=="Transfer")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8((ex[5].c_str())));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }

        }
        if(size==4)
        {
            if(ex[3]=="Deposit")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Withdraw")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Transfer")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(ex[1].c_str()));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }


        }


    }
    // if the user is faculty following actions are taken

    if(UType=="Faculty")
    {
        LogUser=&LogFaculty;
        LogUser->readDb(UId);
        string UName="Hi "+LogFaculty.getName();
        this->StaticText_proName->SetLabel(wxString::FromUTF8(UName.c_str()));
        UAcc=Logbank.account_number(UId);
        this->StaticText_AccNo->SetLabel(wxString::FromUTF8((UAcc.c_str())));
        wxMessageBox(wxString::FromUTF8(UAcc.c_str()));

        Logbank.get_details(UAcc);

        std::string strBalance;
        std::stringstream out;
        out << Logbank.getBalance();
        strBalance = out.str();
        wxMessageBox(wxString::FromUTF8(strBalance.c_str()));
        this->StaticText_BalanceValue->SetLabel(wxString::FromUTF8(strBalance.c_str()));

        SqlQuery="SELECT `FrmAccount`, `ToAccount` , `Amount`, `Description` FROM `tansactionHistory` WHERE FrmAccount='";
        SqlQuery=SqlQuery+Logbank.account_number(UId)+"' OR ToAccount='";
        SqlQuery=SqlQuery+Logbank.account_number(UId)+"' ORDER BY Id DESC";
        ex = mydbSingleton::getInstance().listTable(SqlQuery);

        int size=(int)ex.size();
        //load last 3 transaction history
        if(size>=12)
        {
            if(ex[3]=="Deposit")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Withdraw")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Transfer")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(ex[1].c_str()));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }


            if(ex[7]=="Deposit")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }
            else if(ex[7]=="Withdraw")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }
            else if(ex[7]=="Transfer")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8((ex[5].c_str())));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }
            if(ex[11]=="Deposit")
            {
                this->TextCtrl_To_3->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_Amt_3->SetValue(wxString::FromUTF8((ex[10].c_str())));

            }

            else if(ex[11]=="Withdraw")
            {
                this->TextCtrl_To_3->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_Amt_3->SetValue(wxString::FromUTF8((ex[10].c_str())));

            }

            else if(ex[11]=="Transfer")
            {
                this->TextCtrl_To_3->SetValue(wxString::FromUTF8((ex[9].c_str())));
                this->TextCtrl_To_Amt_3->SetValue(wxString::FromUTF8((ex[10].c_str())));

            }
        }
        if(size==8)
        {
            if(ex[3]=="Deposit")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Withdraw")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Transfer")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(ex[1].c_str()));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }


            if(ex[7]=="Deposit")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }
            else if(ex[7]=="Withdraw")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }
            else if(ex[7]=="Transfer")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8((ex[5].c_str())));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }

        }
        if(size==4)
        {
            if(ex[3]=="Deposit")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Withdraw")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Transfer")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(ex[1].c_str()));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }


        }





    }
    // if guardian tries to login the program exits
    if(UType=="Guardian")
    {
        LogUser=&LogGuardian;
        wxMessageBox(_T("Sorry but you are not supposed to use this software.\n Exiting....."));
        this->Close();

    }
    // if the admin logs in following actions are taken
    if(UType=="Admin")
    {
        LogUser=&LogAdmin;
        LogAdmin.readDb(UId);
        string UName="Hi "+LogAdmin.getName();
        this->StaticText_proName->SetLabel(wxString::FromUTF8(UName.c_str()));
        this->Panel_admin->wxWindow::Show(true);

        LogUser->readDb(UId);
        UAcc=Logbank.account_number(UId);
        this->StaticText_AccNo->SetLabel(wxString::FromUTF8((UAcc.c_str())));
        wxMessageBox(wxString::FromUTF8((UAcc.c_str())));

        Logbank.get_details(UAcc);

        std::string strBalance;
        std::stringstream out;
        out << Logbank.getBalance();
        strBalance = out.str();
        wxMessageBox(wxString::FromUTF8(strBalance.c_str()));
        this->StaticText_BalanceValue->SetLabel(wxString::FromUTF8(strBalance.c_str()));

        SqlQuery="SELECT `FrmAccount`, `ToAccount` , `Amount`, `Description` FROM `tansactionHistory` WHERE FrmAccount='";
        SqlQuery=SqlQuery+Logbank.account_number(UId)+"' OR ToAccount='";
        SqlQuery=SqlQuery+Logbank.account_number(UId)+"' ORDER BY Id DESC";
        ex = mydbSingleton::getInstance().listTable(SqlQuery);

        int size=(int)ex.size();

        // load last 3 transaction history of the admin of his account
        if(size>=12)
        {
            if(ex[3]=="Deposit")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Withdraw")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Transfer")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(ex[1].c_str()));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }


            if(ex[7]=="Deposit")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }
            else if(ex[7]=="Withdraw")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }
            else if(ex[7]=="Transfer")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8((ex[5].c_str())));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }
            if(ex[11]=="Deposit")
            {
                this->TextCtrl_To_3->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_Amt_3->SetValue(wxString::FromUTF8((ex[10].c_str())));

            }

            else if(ex[11]=="Withdraw")
            {
                this->TextCtrl_To_3->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_Amt_3->SetValue(wxString::FromUTF8((ex[10].c_str())));

            }

            else if(ex[11]=="Transfer")
            {
                this->TextCtrl_To_3->SetValue(wxString::FromUTF8((ex[9].c_str())));
                this->TextCtrl_To_Amt_3->SetValue(wxString::FromUTF8((ex[10].c_str())));

            }
        }
        if(size==8)
        {
            if(ex[3]=="Deposit")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Withdraw")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Transfer")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(ex[1].c_str()));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }


            if(ex[7]=="Deposit")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }
            else if(ex[7]=="Withdraw")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }
            else if(ex[7]=="Transfer")
            {
                this->TextCtrl_To_2->SetValue(wxString::FromUTF8((ex[5].c_str())));
                this->TextCtrl_To_amt_2->SetValue(wxString::FromUTF8((ex[6].c_str())));

            }

        }
        if(size==4)
        {
            if(ex[3]=="Deposit")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self Deposit")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Withdraw")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(("self withdrawl")));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }
            else if(ex[3]=="Transfer")
            {
                this->TextCtrl_To_1->SetValue(wxString::FromUTF8(ex[1].c_str()));
                this->TextCtrl_To_amt_1->SetValue(wxString::FromUTF8((ex[2].c_str())));

            }


        }
    }
}

/** This function grabs the amount and account number from the user and transacts the money appropriately*/
void TransactionForm::OnSubmitTransferClick(wxCommandEvent& event)
{
    MyFunctionClass str;
    if((str.ConvertToString(this->TextCtrl_TransAccount)!="")&&(str.ConvertToString(this->TextCtrl_To_Amount)!="")==1)
    {


        if(Logbank.transfer(str.ConvertToString(this->TextCtrl_TransAccount),str.ConvertToString(this->TextCtrl_To_Amount))==0)
        {
            this->TextCtrl_TransAccount->SetValue(_T(""));
            this->TextCtrl_To_Amount->SetValue(_T(""));
            wxMessageBox(_T("Money Transferred"));
        }
        else
            wxMessageBox(_T("Low Balance or Wrong information provided. Try Again"));
    }
    else
        wxMessageBox(_T("Please fill the details before submitting."));

}

/** Deposit the money from one account to another or to self depending on type of user */
void TransactionForm::OnButton1Click(wxCommandEvent& event)
{
    MyFunctionClass str;
    if((str.ConvertToString(this->TextCtrl_ToAccnt_Admin)!="")&&(str.ConvertToString(this->TextCtrl_Amt_Admin)!=""))
    {
        if(Logbank.deposit(str.ConvertToString(this->TextCtrl_FrmAccnt_Admin),str.ConvertToString(this->TextCtrl_ToAccnt_Admin),str.ConvertToString(this->TextCtrl_Amt_Admin))==0)
        {
            this->TextCtrl_FrmAccnt_Admin->SetValue(_T(""));
            this->TextCtrl_ToAccnt_Admin->SetValue(_T(""));
            this->TextCtrl_Amt_Admin->SetValue(_T(""));

            wxMessageBox(_T("Money Deposited"));
        }
        else
            wxMessageBox(_T("Wrong Details!!! Please try again with correct values."));
    }
    else wxMessageBox(_T("Please complete the details before submitting."));

}
/** This function allows user to withdraw moeny from the acccount*/
void TransactionForm::OnButton_WithdrawClick(wxCommandEvent& event)
{
    UId= this->mUser->getLoginId();
    UAcc=Logbank.account_number(UId);
    Logbank.get_details(UAcc);
    MyFunctionClass str;
    string amt;
    amt=(str.ConvertToString((this->TextCtrl_Wamt)).c_str());
    if(amt=="")
    {
        wxMessageBox(_T("Please enter the amount to continue."));
        return;
    }

    if(Logbank.withdraw(UAcc,amt)==0)
    {
        this->TextCtrl_Wamt->SetValue(_T(""));
        wxMessageBox(_T("Successfull withdrawl.\nPlease collect the cash"));
    }
    else
        wxMessageBox(_T("Either low balance or no balance"));
}

void TransactionForm::OnButton2Click(wxCommandEvent& event)
{
}
/** This function allows the admin to create an account of the user iff all the details of the user are verfied.*/
void TransactionForm::OnButton_CreateClick(wxCommandEvent& event)
{
    MyFunctionClass str;
    if( Logbank.create_account(((str.ConvertToString(this->TextCtrl_CreateAcc))).c_str())==0)
        wxMessageBox(_T("Bank account successfully created"));
}

void TransactionForm::OnButton_LogOutClick(wxCommandEvent& event)
{
this->Close();
}

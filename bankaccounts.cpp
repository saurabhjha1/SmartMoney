#include "bankaccounts.h"
#include "mydbsingleton.h"

#include <stdlib.h> // this alllows the conversion of string to double datatype
#include <string>
#include <sstream> // this allows the conversion of the double to string datatype
using namespace std;


bankAccounts::bankAccounts()
{
    //ctor
}

bankAccounts::~bankAccounts()
{
    //dtor
}

int bankAccounts::get_details(string Account_number)
{

    string SqlQuery;
    SqlQuery="select User_id, Balance from `accounts` where Account_number='";
    SqlQuery=SqlQuery+Account_number+"'";
    std::vector<std::string>ex=mydbSingleton::getInstance().listTable(SqlQuery);
    if(ex.size()==2){
    this->Account_no=Account_number;
    this->Balance=atof(ex[1].c_str());
    this->User_id=ex[0];
    return 0;
    }
    else
    return 1;

}

int bankAccounts::deposit(string frmAccount_number,string toAccount_number,string amount)
{
    std::string strBalance;
    std::stringstream out;
    std::stringstream out2;
    bankAccounts FromUser;
    string SqlQuery1;
    int status=-1;
    if(frmAccount_number!="")
    {


    if(FromUser.get_details(frmAccount_number)==1) return status;
    double newbal;
    newbal=atof(amount.c_str());
    string SqlQuery;
    if(FromUser.Balance>newbal)
    {
        FromUser.Balance=FromUser.Balance-newbal;
        out << FromUser.Balance;
        strBalance = out.str();
        SqlQuery="UPDATE `accounts` SET `Balance`=";
        SqlQuery=SqlQuery+"'"+strBalance+"' WHERE `Account_number`=";
        SqlQuery=SqlQuery+"'"+FromUser.Account_no+"'";


        bankAccounts ToUser;
        if(ToUser.get_details(toAccount_number)==1) return status;
        ToUser.Balance+=newbal;
        out2 << ToUser.Balance;
        strBalance="";
        strBalance = out2.str();
        SqlQuery1="UPDATE `accounts` SET `Balance`=";
        SqlQuery1=SqlQuery1+"'"+strBalance+"' WHERE `Account_number`=";
        SqlQuery1=SqlQuery1+"'"+ToUser.Account_no+"'";
        std::vector<std::string>ex=mydbSingleton::getInstance().listTable(SqlQuery);
        ex=mydbSingleton::getInstance().listTable(SqlQuery1);
        transactionHistory(this->Account_no,ToUser.Account_no,amount,"Transfer");
        status=0;
    }
    else status=1; // Not enough balance
    }
    if(frmAccount_number=="")
    {
    std::string strBalance;
    std::stringstream out;
    std::stringstream out2;
    string SqlQuery;
    double newbal;
    newbal=atof(amount.c_str());


    bankAccounts ToUser;
    if(ToUser.get_details(toAccount_number)==1) return -1;
    ToUser.Balance+=newbal;
    out2 << ToUser.Balance;
    strBalance="";
    strBalance = out2.str();
    SqlQuery="UPDATE `accounts` SET `Balance`=";
    SqlQuery=SqlQuery+"'"+strBalance+"' WHERE `Account_number`=";
    SqlQuery=SqlQuery+"'"+ToUser.Account_no+"'";
    std::vector<std::string> ex=mydbSingleton::getInstance().listTable(SqlQuery);
    transactionHistory("0",ToUser.Account_no,amount,"Deposit");
    status=0;

    }

    return status;
}
int bankAccounts::withdraw(string Account_number,string amount)
{
    std::string strBalance;
    std::stringstream out;
    std::stringstream out2;
    string SqlQuery;
    double newbal;
    newbal=atof(amount.c_str());


    bankAccounts ToUser;
    if(this->Balance>newbal){
    this->Balance-=newbal;
    out2 << this->Balance;
    strBalance="";
    strBalance = out2.str();
    SqlQuery="UPDATE `accounts` SET `Balance`=";
    SqlQuery=SqlQuery+"'"+strBalance+"' WHERE `Account_number`=";
    SqlQuery=SqlQuery+"'"+this->Account_no+"'";
    std::vector<std::string> ex=mydbSingleton::getInstance().listTable(SqlQuery);
    string s1,s2;
    s1="0";
    s2="Withdraw";
    if(transactionHistory(this->Account_no,s1,amount,s2)==0) ;
    return 0;
    }
    else return 1;

}
void bankAccounts::modify_details(string Account_number,string Balance)
{
    std::string strBalance;
    std::stringstream out;
    double newbal;
    newbal=atof(Balance.c_str());
    string SqlQuery;
    this->Balance=newbal;
    out << this->Balance;
    strBalance = out.str();
    SqlQuery="UPDATE `accounts` SET `Balance`=";
    SqlQuery=SqlQuery+"'"+strBalance+"' where `Account_number`=";
    SqlQuery=SqlQuery+"'"+this->User_id+"'";
    std::vector<std::string>ex=mydbSingleton::getInstance().listTable(SqlQuery);
}
int bankAccounts::transfer(string Account_number,string amount)
{
    std::string strBalance;
    std::stringstream out;
    std::stringstream out2;
    string SqlQuery1;
    double newbal;
    newbal=atof(amount.c_str());
    string SqlQuery;

    if(this->Balance>newbal){

    bankAccounts ToUser;
    if(ToUser.get_details(Account_number)==1) return 1;
    ToUser.Balance+=newbal;
    out2<<ToUser.Balance;
    strBalance="";
    strBalance = out2.str();
    SqlQuery1="UPDATE `accounts` SET `Balance`=";
    SqlQuery1=SqlQuery1+"'"+strBalance+"' WHERE `Account_number`=";
    SqlQuery1=SqlQuery1+"'"+ToUser.Account_no+"'";

    this->Balance=this->Balance-newbal;
    out << this->Balance;
    strBalance="";
    strBalance = out.str();
    SqlQuery="UPDATE `accounts` SET `Balance`=";
    SqlQuery=SqlQuery+"'"+strBalance+"' WHERE `Account_number`=";
    SqlQuery=SqlQuery+"'"+this->Account_no+"'";
    std::vector<std::string>ex=mydbSingleton::getInstance().listTable(SqlQuery);
    ex=mydbSingleton::getInstance().listTable(SqlQuery1);
    transactionHistory(this->Account_no,ToUser.Account_no,amount,"Transfer");
    return 0;
    }
    else return 1;
}

string bankAccounts::account_number(string User_id)
{
    string SqlQuery;
    SqlQuery="SELECT `Account_number`, `User_id`, `Balance` FROM `accounts` WHERE  User_id='";
    SqlQuery=SqlQuery+User_id+"'";
    std::vector<std::string>ex=mydbSingleton::getInstance().listTable(SqlQuery);
    this->Account_no=ex[0];
    return this->Account_no;
}

int bankAccounts::transactionHistory(string frmAccount_number,string toAccount_number,string amount,string type)
{
string SqlQuery;
SqlQuery="INSERT INTO `tansactionHistory`(`FrmAccount`, `ToAccount`, `Amount`, `Description`) VALUES ('";
SqlQuery=SqlQuery+frmAccount_number+"',";
SqlQuery=SqlQuery+"'"+toAccount_number+"',";
SqlQuery=SqlQuery+"'"+amount+"',";
SqlQuery=SqlQuery+"'"+type+"')";
std::vector<std::string>ex=mydbSingleton::getInstance().listTable(SqlQuery);
return 0;
}
int bankAccounts::create_account(string UId)
{
    string SqlQuery;
    SqlQuery="INSERT INTO `accounts` (`Account_number`, `User_id`, `Balance`) VALUES (NULL, '";
    SqlQuery=SqlQuery+UId+"', '0')";
    std::vector<std::string>ex=mydbSingleton::getInstance().listTable(SqlQuery);
    return 0;

}

#include "guardian.h"
#include <string>
#include "mydbsingleton.h"
using namespace std;
guardian::guardian()
{
    //ctor
}

guardian::~guardian()
{
    //dtor
}

void guardian::writeDetails(string First_name,string Last_name,string Address, string City,string State,string Pin,string Trans_pin,string Mobile,string Email,string DOB,string Password,string Blood_group,bool Login_status,string type,string Registration_number,string Guardian_name, string Guardian_id,string Guardian_contact)
{

this->Name_first=First_name;
this->Name_last=Last_name;
this->Addres=Address;
this->City=City;
this->State=State;
this->Trans_pin=Trans_pin;
this->Pin=Pin;
this->Mobile=Mobile;
this->Email=Email;
this->DOB=DOB;
this->Blood_group=Blood_group;
this->Password=Password;
this->Login_status=Login_status;
this->type=type;


}

void guardian::checkValidity(){

}


void guardian::readDb(string User_id)
{

}
void guardian::registration()
{


}
void guardian::writeDb()
{
 std::string SqlQuery;
    SqlQuery="INSERT INTO `user`(`Name_first`, `Name_last`, `Address`, `City`, `State`, `Pin`, `Mobile`, `Email`, `Password`, `Trans_pin`, `Blood_group`, `type`, `DOB`) VALUES (";
    SqlQuery=SqlQuery+"'"+this->user::Name_first+"',";
    SqlQuery=SqlQuery+"'"+this->Name_last+"',";
    SqlQuery=SqlQuery+"'"+this->Addres+"',";
    SqlQuery=SqlQuery+"'"+this->City+"',";
    SqlQuery=SqlQuery+"'"+this->State+"',";
    SqlQuery=SqlQuery+"'"+this->Pin+"',";
    SqlQuery=SqlQuery+"'"+this->Mobile+"',";
    SqlQuery=SqlQuery+"'"+this->Email+"',";
    SqlQuery=SqlQuery+"'"+this->Password+"',";
    SqlQuery=SqlQuery+"'"+this->Trans_pin+"',";
    SqlQuery=SqlQuery+"'"+this->Blood_group+"',";
    SqlQuery=SqlQuery+"'"+this->type+"',";
    SqlQuery=SqlQuery+"'"+this->DOB+"'";
    SqlQuery+=")";
    std::vector<std::string> ex = mydbSingleton::getInstance().listTable(SqlQuery);

}

string guardian::getUserId()
{
    return this->user_id;
}

void guardian::getDetails()
{
    string SqlQuery="SELECT `User_id` FROM `user` WHERE `Email`='";
SqlQuery=SqlQuery+this->Email+"'";
std::vector<std::string> ex = mydbSingleton::getInstance().listTable(SqlQuery);
this->user_id=ex[0];
this->readDb(this->user_id);
}

#include "admin.h"
#include "student.h"
#include "faculty.h"
#include "guardian.h"
#include "bankaccounts.h"
#include "mydbsingleton.h"

Admin::Admin()
{
    //ctor
this->Description="NULL";


}

Admin::~Admin()
{
    //dtor
}
void Admin::createUser(string User_type)
{

}

void Admin::readDb(string User_id)
{
string SqlQuery;
SqlQuery="SELECT `Name_first`, `Name_last`, `Address`, `City`, `State`, `Pin`, `Mobile`, `Email`, `DOB`, `Password`, `Trans_pin`, `Blood_group`, `type` FROM `user` WHERE  `User_id` ='";
SqlQuery=SqlQuery+User_id+"'";
std::vector <std::string> ex=mydbSingleton::getInstance().listTable(SqlQuery);
this->Name_first=ex[0];
this->Name_last=ex[1];
this->Addres=ex[2];
this->City=ex[3];
this->State=ex[4];

this->Pin=ex[5];
this->Mobile=ex[6];
this->Email=ex[7];
this->DOB=ex[9];
this->Blood_group=ex[11];
this->Password=ex[9];
this->Trans_pin=ex[10];
this->type=ex[12];
}

void Admin::getDetails()
{

}
void Admin::writeDb()
{

}
void Admin::writeDetails(string First_name,string Last_name,string Address, string City,string State,string Pin,string Trans_pin,string Mobile,string Email,string DOB,string Password,string Blood_group,bool Login_status,string type,string Registration_number,string Guardian_name, string Guardian_id,string Guardian_contact)
{


}
string Admin::getName()
{
    return this->Name_first;
}
string Admin::getUserId()
{
    return this->user_id;
}

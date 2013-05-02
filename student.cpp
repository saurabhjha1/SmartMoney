#include "student.h"
#include "mydbsingleton.h"

student::student()
{

}

student::~student()
{
    //dtor
}
void student::getDetails()
{
    string SqlQuery="SELECT `User_id` FROM `user` WHERE `Email`='";
SqlQuery=SqlQuery+this->Email+"'";
std::vector<std::string> ex = mydbSingleton::getInstance().listTable(SqlQuery);
this->user_id=ex[0];
this->readDb(this->user_id);

}
void student::writeDetails(string First_name,string Last_name,string Address, string City,string State,string Pin,string Trans_pin,string Mobile,string Email,string DOB,string Password,string Blood_group,bool Login_status,string type,string Registration_number,string Guardian_name, string Guardian_id,string Guardian_contact )
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
this->Registration_number=Registration_number;
this->Guardian_id=Guardian_id;
this->Guardian_name=Guardian_name;
this->Guardian_contact_number=Guardian_contact;
}


void student::checkValidity(){

}


void student::readDb(string User_id)
{
string SqlQuery;
SqlQuery="SELECT `Name_first`, `Name_last`, `Address`, `City`, `State`, `Pin`, `Mobile`, `Email`, `DOB`, `Password`, `Trans_pin`, `Blood_group`, `type` FROM `user` WHERE  `User_id` ='";
SqlQuery=SqlQuery+User_id+"'";
std::vector<std::string> ex=mydbSingleton::getInstance().listTable(SqlQuery);
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

    SqlQuery="SELECT `Registration_number`, `Guardian_name`, `Guardian_id`, `Guardian_contact` FROM `student` WHERE `user_id` ='";
    SqlQuery=SqlQuery+User_id+"'";

    ex=mydbSingleton::getInstance().listTable(SqlQuery);

this->Registration_number=ex[0];
this->Guardian_id=ex[2];
this->Guardian_name=ex[1];
this->Guardian_contact_number=ex[3];
}

void student::writeDb()
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
    // Get the user id of the current registred user id
    SqlQuery="select User_id from `user` where Email='";
    SqlQuery=SqlQuery+this->Email+"'";

    string uid;
     ex=mydbSingleton::getInstance().listTable(SqlQuery);
     uid=ex[0];

    SqlQuery="INSERT INTO `student`(`Registration_number`, `Guardian_name`, `Guardian_id`, `Guardian_contact`, `user_id`) VALUES (";
    SqlQuery=SqlQuery+"'"+this->Registration_number+"',";
    SqlQuery=SqlQuery+"'"+this->Guardian_name+"',";
    SqlQuery=SqlQuery+"'"+this->Guardian_id+"',";
    SqlQuery=SqlQuery+"'"+this->Guardian_contact_number+"',";
    SqlQuery=SqlQuery+"'"+uid+"')";

    mydbSingleton::getInstance().listTable(SqlQuery);
}

string student::getName()
{
    return this->Name_first;
}
string student::getUserId()
{
    return this->user_id;
}

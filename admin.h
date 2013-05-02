#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include<string>
using namespace std;

class Admin : public user
{

public:
    /** Default constructor */
    Admin();
    /** Default destructor */
    virtual ~Admin();
    Admin(string i) { this->user_id = i; }

   /** This function helps the Admin to create a new user account.*/
    void createUser(string User_type);
    void editDescription();
    /** The function get details from the objects of the admin class.*/
    void getDetails();
    /** Gets the account details of the student*/
    void getAccountDetails();
    /** Notifies the administrtor of the DD submitted*/
    void notifyDD();
    /** It allows the user to withdraw money for purchasing, submitting fees or fines etc*/
    void withdrawMoney(string account);
    /**This functions lets the user read from database as set by their privelages*/
    void readDb(string User_id);
    /**This functions lets the user read from database as set by their privelages*/
    void writeDb();
     /** Writes the details to the object*/
    void writeDetails(string First_name,string Last_name,string Address, string City,string State,string Pin,string Trans_pin,string Mobile,string Email,string DOB,string Password,string Blood_group,bool Login_status,string type,string Registration_number,string Guardian_name, string Guardian_id,string Guardian_contact);
    /** This function gets the first name of the admin*/
    string getName();
    /**This function get the user id of the current admin*/
    string getUserId();

protected:
private:
/** The role of the administrator actions */
string Description;
};

#endif // ADMIN_H

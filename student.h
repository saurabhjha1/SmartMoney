#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"


class student : public user
{
private:
    /** Registration number of the student. Must be of the format specified by the VIT for example 10BCE1089 ie year,batch,roll. */
    string Registration_number;
    /** The name of the guardian of the student. */
    string Guardian_name;
    /** Contact number of students guardian*/
    string Guardian_contact_number;
    /** Guardian Id of the guardian of the student. iMust be mentioned if guardian account exist.*/
    string Guardian_id;



public:
    /** Default constructor to set the default values of the class */
    student();

    student(string i) { this->user_id = i; }
    /** Default destructor */
    virtual ~student();
    /** The function get details from the objects of the guardian class.*/
    void getDetails();
    /** The function writes details from the objects of the guardian class.*/
    void writeDetails(string First_name,string Last_name,string Address, string City,string State,string Pin,string Trans_pin,string Mobile,string Email,string DOB,string Password,string Blood_group,bool Login_status,string type,string Registration_number,string Father_name, string Guardian_id,string Father_contact);
    /** The function checks the validity of the fields like Guardian_id,Registration_number,Guardian_contact_number*/
    void checkValidity();
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
    /**This function gets the name of the current student and returns it anywhere in program.*/
    string getName();
    /** To fetch the user is of the student*/
    string getUserId();




};

#endif // STUDENT_H

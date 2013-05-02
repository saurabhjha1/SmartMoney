#ifndef GUARDIAN_H
#define GUARDIAN_H

#include "user.h"


class guardian : public user
{
public:
    /** Default constructor */
    guardian();
    /** Default destructor */
   ~guardian();
    /** This function get the details of the Guardian required by the program elsewhere.*/
    void getDetails();
    /** This function writes the details of the Guardian required by the program elsewhere.*/
    void writeDetails(string First_name,string Last_name,string Address, string City,string State,string Pin,string Trans_pin,string Mobile,string Email,string DOB,string Password,string Blood_group,bool Login_status,string type,string Registration_number,string Guardian_name, string Guardian_id,string Guardian_contact);

    /** This function checks the details of the Guardian such as Guardian_id.*/
    void checkValidity();
    /** This function notifies the 0admin that the DD has been sent to the university/college. */
    void notify_DD();
        /**This functions lets the user read from database as set by their privelages*/
    void readDb(string User_id);
    /**This functions lets the user read from database as set by their privelages*/
    void writeDb();
        /** This function will allow the admin to get det details from new user during registration process.**/
    void registration();
    /** This function returns the User Id of the faculty*/
    string getUserId();




};

#endif // GUARDIAN_H

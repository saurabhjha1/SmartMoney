#ifndef FACULTY_H
#define FACULTY_H

#include "user.h"


class faculty : public user
{
    public:
        /** Default constructor */
        faculty();
        /** Default destructor */
        ~faculty();
        /** This fucntion gets the required details of the faculty whenever required.*/
        void getDetails();
        /** This fucntion writes the required details of the faculty whenever required.*/
        void writeDetails(string First_name,string Last_name,string Address, string City,string State,string Pin,string Trans_pin,string Mobile,string Email,string DOB,string Password,string Blood_group,bool Login_status,string type,string Registration_number,string Guardian_name, string Guardian_id,string Guardian_contact);
        /** This function checks the validity of the field such as User_id,Staff_code .*/
        void checkValidity();
        /**This functions lets the user read from database as set by their privelages*/
        void readDb(string User_id);
        /**This functions lets the user read from database as set by their privelages*/
        void writeDb();
        /** This function will allow the admin to get det details from new user during registration process.**/
        void registration();
        string getName();
        /** This function returns the User Id of the faculty*/
        string getUserId();

    protected:


    private:
     /** Staff code of the faculty/staff. Must be 5 digits long.*/
     string Staff_code;
     /** Department to which staff belongs. */
     string Department;

};

#endif // FACULTY_H

#ifndef USER_H
#define USER_H
#include <string>
using namespace std;
class user
{
protected:
    /*! Ten digit unique id only to be used by programmer*/
    string user_id;
    /*! First name of user*/
    string Name_first;
    /*! Last Name of user*/
    string Name_last;
    /*! Address of user such quarter number, street, post office */
    string Addres;
    /*! Home city of user*/
    string City;
    /*! Home state of user*/
    string State;
    /*! Pin Number of the place*/
    string Pin;
    /*! Transaction pin used for withdrawl of money or checking tansaction history. Must be a 4 digit number used for tansaction/withdrawl */
    string Trans_pin;
    /*! Must be 10 digit*/
    string Mobile;
    /*! E-mail ID of user. Format must be someone@somewhere.domain */
    string Email;
    /*! Date of Birth of User. Format must be yyyy-mm-dd*/
    string DOB;
    /*! Password for the user account */
    string Password;
    /*! Blood group of user */
    string Blood_group;
    /*! Maintains login status of user- 1.active session 0.logged out */
    bool Login_status;
    /*! User type 1. Student 2. Faculty 3. Guardian */
    string type;




public:
    /** Default constructor */
    user();


    /** Default destructor */
    virtual ~user();
    /** Sets the login status of user to true*/
    void login();
     /** Sets the login status of user to false*/
    void logout();
    /** Gets the details from the objects to be used other part of program */
    virtual void getDetails();
    /** Writes the details to the object*/
    virtual void writeDetails(string First_name,string Last_name,string Address, string City,string State,string Pin,string Trans_pin,string Mobile,string Email,string DOB,string Password,string Blood_group,bool Login_status,string type,string Registration_number,string Guardian_name, string Guardian_id,string Guardian_contact)=0;
      /** Checks the validity of details entered that includes pin,mobile,Email, and DOB */
    virtual void checkValidity();
    /**This functions lets the user read from database as set by their privelages*/
    virtual void readDb(string User_id);
    /**This functions lets the user read from database as set by their privelages*/
    virtual void writeDb()=0;

    inline const string& getLoginId() const { return this->user_id; }

    inline void setLoginId(const string& id) { this->user_id = id; }
        /*! To fetch the user id of current user*/
    virtual string getUserId()=0;

};

#endif // USER_H

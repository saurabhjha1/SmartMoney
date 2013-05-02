#ifndef BANKACCOUNTS_H
#define BANKACCOUNTS_H
#include <string>

using namespace std;
class bankAccounts
{
public:
    /** Default constructor */
    bankAccounts();
    /** Default destructor */
    virtual ~bankAccounts();
    /** This function allows to retrieve the details of the accounts.*/
    int get_details(string Account_number);
    /** This fucntion allows to create account as requested by the admin which he creates on rquest of the user.*/
    int create_account(string User_id);
    /** This fucntion allows to deposit money to account by Admin. After creating account it will call get_details() to reload the values in the object with new account number.*/
    int deposit(string frmAccount_number,string toAccount_number,string Amount);
    /** This function allows the withdrwal of money by Admin or user.*/
    int withdraw(string Account_number,string Amount );
    /** This function allows the modify the details of the accounts by admin.*/
    void modify_details(string Account_number,string Balance);
    /** This function checks the validity of the account number,User_id. */
    int checkValidity();
    /** This fucntion allows the user to update the transaction history.*/
    int transactionHistory(string frmAccount_number,string toAccount_number,string Amount,string type);
    /** This fuction allows the user to transfer the money */
    int transfer(string Account_number,string Amount );
    /** This function allows to get account id from user id. So that the user do not has to remember his account number */
    string account_number(string User_id);
    inline const double& getBalance() const { return this->Balance; }


protected:
private:
    /** The User_id with which it is associated.*/
    string User_id;
    /** The account number of the user. It must be 9 digits long.*/
    string Account_no;

    /** The balance amount in the account.*/
    double Balance;

};

#endif // BANKACCOUNTS_H

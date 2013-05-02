#ifndef MYDBSINGLETON_H
#define MYDBSINGLETON_H

#include <string>
#include <vector>
#include <mysql++.h>
/** This class allows only one instance of the SQL connection to run through out the program and also has a single interface to issue the SQL commands.
This class is based on singleton concept wherein only one object of the class can be created*/

class mydbSingleton
{

private:
    static mydbSingleton single;

    mysqlpp::Connection mConn;
    mydbSingleton();
public:
    /**This function allows programmer to fetch the instance of that single object*/
    static mydbSingleton& getInstance();
    /**This function handles all the SQL commands issued to the object*/
    std::vector<std::string> listTable(std::string myquery  );
};


#endif // MYDBSINGLETON_H

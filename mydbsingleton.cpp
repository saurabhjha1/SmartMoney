#include "mydbsingleton.h"
#include <string>
using namespace mysqlpp;

mydbSingleton mydbSingleton::single;

mydbSingleton& mydbSingleton::getInstance()
{
    return mydbSingleton::single;
}

mydbSingleton::mydbSingleton()
{
    //  str=_T("HELLO");

    this->mConn = mysqlpp::Connection(true);
    //cout << "Method of the mydbSingleton class" << endl;
    this->mConn.connect("SmartMoney", "localhost", "root", "root");
}

std::vector<std::string> mydbSingleton::listTable(std::string myquery)
{
;
//myquery="select * from student";
    std::vector<std::string> results;

    if (this->mConn.connected())
    {
        // Retrieve a subset of the sample stock table set up by resetdb
        // and display it.
        mysqlpp::Query query = this->mConn.query(myquery);
        if (mysqlpp::StoreQueryResult res = query.store())
        {
            mysqlpp::StoreQueryResult::const_iterator it;
            for (it = res.begin(); it != res.end(); ++it)
            {
               mysqlpp::Row row = *it;
               mysqlpp::Row::const_iterator res;
               for(res = row.begin(); res != row.end(); ++res) {
                    results.push_back(std::string((*res).c_str()));
                }
            }
        }
    }
    else {
    results.push_back("NOTHING TO DISPLAY");
    }


    return results;
}

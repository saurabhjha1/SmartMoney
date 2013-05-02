#ifndef MYFUNCTIONCLASS_H
#define MYFUNCTIONCLASS_H

#include <string>
class MyFunctionClass
{
    public:
        /** Default constructor */
        MyFunctionClass();
        /** Default destructor */
        ~MyFunctionClass();
        /** converts the wxtextctrl text to string text*/
        std::string ConvertToString(wxTextCtrl *text);


};

#endif // MYFUNCTIONCLASS_H

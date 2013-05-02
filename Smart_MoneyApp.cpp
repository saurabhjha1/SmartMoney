/***************************************************************
 * Name:      Smart_MoneyApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Saurabh Jha (saurabhjha2010@@gmail.com)
 * Created:   2011-10-29
 * Copyright: Saurabh Jha (http://saurabhjha.in)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Smart_MoneyApp.h"

//(*AppHeaders
#include "Smart_MoneyMain.h"
#include <wx/xrc/xmlres.h>
#include <wx/image.h>
//*)

IMPLEMENT_APP(Smart_MoneyApp);

bool Smart_MoneyApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    wxXmlResource::Get()->InitAllHandlers();
    wxsOK = wxsOK && wxXmlResource::Get()->Load(_T("NewUserForm.xrc"));
    wxsOK = wxsOK && wxXmlResource::Get()->Load(_T("NewRegisterForm.xrc"));
    wxsOK = wxsOK && wxXmlResource::Get()->Load(_T("TransactionForm.xrc"));
    if ( wxsOK )
    {
    	Smart_MoneyFrame* Frame = new Smart_MoneyFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}

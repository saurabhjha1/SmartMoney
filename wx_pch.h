/***************************************************************
 * Name:      wx_pch.h
 * Purpose:   Header to create Pre-Compiled Header (PCH)
 * Author:    Saurabh Jha (saurabhjha2010@@gmail.com)
 * Created:   2011-10-29
 * Copyright: Saurabh Jha (http://saurabhjha.in)
 * License:
 **************************************************************/
#include <string>
#ifndef WX_PCH_H_INCLUDED
#define WX_PCH_H_INCLUDED

// basic wxWidgets headers
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#ifdef WX_PRECOMP
// put here all your rarely-changing header files
#endif // WX_PRECOMP

#endif // WX_PCH_H_INCLUDED

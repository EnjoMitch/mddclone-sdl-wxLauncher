/***************************************************************
 * Name:      wx_pch.h
 * Purpose:   Header to create Pre-Compiled Header (PCH)
 * Author:     ()
 * Created:   2009-11-11
 * Copyright:  ()
 * License:
 **************************************************************/

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
    #include <wx/ffile.h>
    #include <wx/stdpaths.h>
    #include <wx/checkbox.h>
    #include <wx/sizer.h>
    #include <wx/listctrl.h>
    #include <wx/notebook.h>
    #include <wx/button.h>
    #include <wx/menu.h>
    #include <wx/panel.h>
    #include <wx/statusbr.h>
    #include <wx/frame.h>
    #include <wx/stattext.h>
    #include <wx/textctrl.h>
    #include <wx/choice.h>
#endif // WX_PRECOMP

#endif // WX_PCH_H_INCLUDED

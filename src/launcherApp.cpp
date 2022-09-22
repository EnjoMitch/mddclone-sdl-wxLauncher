/***************************************************************
 * Name:      launcherApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2009-06-14
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "launcherApp.h"
#include "launcherMain.h"

#ifndef WX_PRECOMP
//(*AppHeaders
#include "launcherMain.h"
#include <wx/image.h>
//*)
#endif

IMPLEMENT_APP(launcherApp);

bool launcherApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    //wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	launcherFrame* Frame = new launcherFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}

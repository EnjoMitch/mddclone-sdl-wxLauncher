/***************************************************************
 * Name:      launcherApp.h
 * Purpose:   Defines Application Class
 * Author:     ()
 * Created:   2009-06-14
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef LAUNCHERAPP_H
#define LAUNCHERAPP_H

#ifndef WX_PRECOMP
#include <wx/app.h>
#endif
class launcherApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // LAUNCHERAPP_H

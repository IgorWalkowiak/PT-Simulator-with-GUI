/***************************************************************
 * Name:      PTInterfaceApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Igor Walkowiak ()
 * Created:   2018-05-28
 * Copyright: Igor Walkowiak ()
 * License:
 **************************************************************/

#include "PTInterfaceApp.h"

//(*AppHeaders
#include "PTInterfaceMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(PTInterfaceApp);

bool PTInterfaceApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	PTInterfaceFrame* Frame = new PTInterfaceFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}

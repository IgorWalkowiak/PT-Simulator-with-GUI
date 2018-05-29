/***************************************************************
 * Name:      PTInterfaceMain.h
 * Purpose:   Defines Application Frame
 * Author:    Igor Walkowiak ()
 * Created:   2018-05-28
 * Copyright: Igor Walkowiak ()
 * License:
 **************************************************************/

#ifndef PTINTERFACEMAIN_H
#define PTINTERFACEMAIN_H

//(*Headers(PTInterfaceFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class PTInterfaceFrame: public wxFrame
{
    public:

        PTInterfaceFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~PTInterfaceFrame();

    private:

        //(*Handlers(PTInterfaceFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnSlider1CmdScroll(wxScrollEvent& event);
        void OnSlider2CmdScroll(wxScrollEvent& event);
        void OnTextCtrl3Text(wxCommandEvent& event);
        //*)

        //(*Identifiers(PTInterfaceFrame)
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL3;
        static const long ID_SLIDER1;
        static const long ID_SLIDER2;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL4;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(PTInterfaceFrame)
        wxButton* Button1;
        wxSlider* Slider1;
        wxSlider* Slider2;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        wxTextCtrl* TextCtrl4;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // PTINTERFACEMAIN_H

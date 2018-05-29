/***************************************************************
 * Name:      PTInterfaceMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Igor Walkowiak ()
 * Created:   2018-05-28
 * Copyright: Igor Walkowiak ()
 * License:
 **************************************************************/
#include <wx/wxprec.h>

#include "PTInterfaceMain.h"
#include <wx/msgdlg.h>
#include "ParTrajectory.h"

//(*InternalHeaders(PTInterfaceFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(PTInterfaceFrame)
const long PTInterfaceFrame::ID_BUTTON1 = wxNewId();
const long PTInterfaceFrame::ID_STATICTEXT1 = wxNewId();
const long PTInterfaceFrame::ID_STATICTEXT2 = wxNewId();
const long PTInterfaceFrame::ID_STATICTEXT3 = wxNewId();
const long PTInterfaceFrame::ID_STATICTEXT4 = wxNewId();
const long PTInterfaceFrame::ID_TEXTCTRL1 = wxNewId();
const long PTInterfaceFrame::ID_TEXTCTRL3 = wxNewId();
const long PTInterfaceFrame::ID_SLIDER1 = wxNewId();
const long PTInterfaceFrame::ID_SLIDER2 = wxNewId();
const long PTInterfaceFrame::ID_TEXTCTRL2 = wxNewId();
const long PTInterfaceFrame::ID_TEXTCTRL4 = wxNewId();
const long PTInterfaceFrame::idMenuQuit = wxNewId();
const long PTInterfaceFrame::idMenuAbout = wxNewId();
const long PTInterfaceFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PTInterfaceFrame,wxFrame)
    //(*EventTable(PTInterfaceFrame)
    //*)
END_EVENT_TABLE()

PTInterfaceFrame::PTInterfaceFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(PTInterfaceFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(338,224));
    Button1 = new wxButton(this, ID_BUTTON1, _("Simulate"), wxPoint(216,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("U angle"), wxPoint(48,64), wxSize(56,16), 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("U value"), wxPoint(48,40), wxSize(56,21), 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("W value"), wxPoint(48,120), wxSize(48,21), 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("W angle"), wxPoint(48,144), wxSize(56,24), 0, _T("ID_STATICTEXT4"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("0"), wxPoint(104,40), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("0"), wxPoint(104,120), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    Slider1 = new wxSlider(this, ID_SLIDER1, 0, 0, 360, wxPoint(104,64), wxSize(160,24), 0, wxDefaultValidator, _T("ID_SLIDER1"));
    Slider2 = new wxSlider(this, ID_SLIDER2, 0, 0, 360, wxPoint(104,144), wxSize(160,24), 0, wxDefaultValidator, _T("ID_SLIDER2"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("0"), wxPoint(272,64), wxSize(40,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, _("0"), wxPoint(272,144), wxSize(40,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PTInterfaceFrame::OnButton1Click);
    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PTInterfaceFrame::OnTextCtrl3Text);
    Connect(ID_SLIDER1,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&PTInterfaceFrame::OnSlider1CmdScroll);
    Connect(ID_SLIDER1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&PTInterfaceFrame::OnSlider1CmdScroll);
    Connect(ID_SLIDER2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&PTInterfaceFrame::OnSlider2CmdScroll);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PTInterfaceFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PTInterfaceFrame::OnAbout);
    //*)
}

PTInterfaceFrame::~PTInterfaceFrame()
{
    //(*Destroy(PTInterfaceFrame)
    //*)
}

void PTInterfaceFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void PTInterfaceFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void PTInterfaceFrame::OnButton1Click(wxCommandEvent& event)
{

    double Uangle=Slider1->GetValue();
    double Wangle=Slider2->GetValue();

    double UValue;
    double WValue;
    TextCtrl1->GetValue().ToDouble(&UValue);
    TextCtrl3->GetValue().ToDouble(&WValue);

    ParTrajectory* a=new ParTrajectory(Uangle,UValue,Wangle,WValue);
    delete a;

}

void PTInterfaceFrame::OnSlider1CmdScroll(wxScrollEvent& event)
{
    int angleU=Slider1->GetValue();
    wxString viewString=wxT("");
    viewString<<angleU;
    TextCtrl2->SetValue(viewString);


}

void PTInterfaceFrame::OnSlider2CmdScroll(wxScrollEvent& event)
{
    int angleU=Slider2->GetValue();
    wxString viewString=wxT("");
    viewString<<angleU;
    TextCtrl4->SetValue(viewString);
}

void PTInterfaceFrame::OnTextCtrl3Text(wxCommandEvent& event)
{
}

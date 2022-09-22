/***************************************************************
 * Name:      launcherMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2009-06-14
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "launcherMain.h"


#ifndef WX_PRECOMP
#include <wx/msgdlg.h>
//(*InternalHeaders(launcherFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)
#include <wx/ffile.h>
#include <wx/file.h>
#include <wx/stdpaths.h>
#endif

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _("-Windows");
#elif defined(__UNIX__)
        wxbuild << _("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _("-Unicode build");
#else
        wxbuild << _("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(launcherFrame)
const long launcherFrame::ID_CHOICE_LANG = wxNewId();
const long launcherFrame::ID_PANEL_GAME = wxNewId();
const long launcherFrame::ID_STATICTEXT1 = wxNewId();
const long launcherFrame::ID_CHOICE1 = wxNewId();
const long launcherFrame::ID_STATICTEXT2 = wxNewId();
const long launcherFrame::ID_TEXTCTRL_RESOL_W = wxNewId();
const long launcherFrame::ID_STATICTEXT3 = wxNewId();
const long launcherFrame::ID_TEXTCTRL_RESOL_H = wxNewId();
const long launcherFrame::ID_CHECKBOX_FULLSCREEN = wxNewId();
const long launcherFrame::ID_CHECKBOX_OPENGL = wxNewId();
const long launcherFrame::ID_CHECKBOX1 = wxNewId();
const long launcherFrame::ID_PANEL_VIDEO = wxNewId();
const long launcherFrame::ID_PANEL_SOUND = wxNewId();
const long launcherFrame::ID_TEXTCTRL1 = wxNewId();
const long launcherFrame::ID_LIST_AUTHORS = wxNewId();
const long launcherFrame::ID_PANEL2 = wxNewId();
const long launcherFrame::ID_NOTEBOOK1 = wxNewId();
const long launcherFrame::ID_BUTTON_LAUNCH = wxNewId();
const long launcherFrame::ID_PANEL1 = wxNewId();
const long launcherFrame::idMenuQuit = wxNewId();
const long launcherFrame::idMenuAbout = wxNewId();
const long launcherFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(launcherFrame,wxFrame)
    //(*EventTable(launcherFrame)
    //*)
END_EVENT_TABLE()

launcherFrame::launcherFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(launcherFrame)
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxMenuItem* MenuItem1;
    wxButton* m_butExit;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer10;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer11;
    wxBoxSizer* BoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxBoxSizer* BoxSizer9;
    wxBoxSizer* BoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer6;
    wxBoxSizer* BoxSizer8;
    wxTextCtrl* TextCtrl1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxStaticText* StaticText2;
    wxMenu* Menu2;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, _("MDDClone-SDL Launcher"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(493,415));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(184,160), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Notebook1 = new wxNotebook(Panel1, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
    m_panGame = new wxPanel(Notebook1, ID_PANEL_GAME, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_GAME"));
    BoxSizer10 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, m_panGame, _("Language"));
    m_choiceLang = new wxChoice(m_panGame, ID_CHOICE_LANG, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_LANG"));
    m_choiceLang->SetSelection( m_choiceLang->Append(_("English")) );
    m_choiceLang->Append(_("Danish"));
    m_choiceLang->Append(_("Dutch"));
    m_choiceLang->Append(_("French"));
    m_choiceLang->Append(_("German"));
    m_choiceLang->Append(_("Greek"));
    m_choiceLang->Append(_("Hungarian"));
    m_choiceLang->Append(_("Italian"));
    m_choiceLang->Append(_("Polish"));
    StaticBoxSizer3->Add(m_choiceLang, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer10->Add(StaticBoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_panGame->SetSizer(BoxSizer10);
    BoxSizer10->Fit(m_panGame);
    BoxSizer10->SetSizeHints(m_panGame);
    m_panVideo = new wxPanel(Notebook1, ID_PANEL_VIDEO, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_VIDEO"));
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, m_panVideo, _("Resolution"));
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(m_panVideo, ID_STATICTEXT1, _("Multiplier"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer5->Add(StaticText1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    m_choiceMultip = new wxChoice(m_panVideo, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    m_choiceMultip->SetSelection( m_choiceMultip->Append(_("1")) );
    m_choiceMultip->Append(_("2"));
    m_choiceMultip->Append(_("3"));
    m_choiceMultip->Append(_("4"));
    m_choiceMultip->Append(_("5"));
    m_choiceMultip->Append(_("6"));
    m_choiceMultip->Append(_("7"));
    m_choiceMultip->Append(_("8"));
    m_choiceMultip->Append(_("9"));
    m_choiceMultip->Append(_("10"));
    m_choiceMultip->SetToolTip(_("Sets multiples of original resolutions"));
    BoxSizer5->Add(m_choiceMultip, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer7 = new wxBoxSizer(wxVERTICAL);
    StaticText2 = new wxStaticText(m_panVideo, ID_STATICTEXT2, _("Width"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer7->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_txtResolW = new wxTextCtrl(m_panVideo, ID_TEXTCTRL_RESOL_W, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL_RESOL_W"));
    m_txtResolW->SetToolTip(_("Arbitrary window width"));
    BoxSizer7->Add(m_txtResolW, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(BoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8 = new wxBoxSizer(wxVERTICAL);
    StaticText3 = new wxStaticText(m_panVideo, ID_STATICTEXT3, _("Height"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer8->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_txtResolH = new wxTextCtrl(m_panVideo, ID_TEXTCTRL_RESOL_H, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL_RESOL_H"));
    m_txtResolH->SetToolTip(_("Arbitrary window height"));
    BoxSizer8->Add(m_txtResolH, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(BoxSizer8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, m_panVideo, _("Switches"));
    BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    m_chckFullscreen = new wxCheckBox(m_panVideo, ID_CHECKBOX_FULLSCREEN, _("Fullscreen"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_FULLSCREEN"));
    m_chckFullscreen->SetValue(false);
    BoxSizer9->Add(m_chckFullscreen, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_chckOpenGL = new wxCheckBox(m_panVideo, ID_CHECKBOX_OPENGL, _("OpenGL"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_OPENGL"));
    m_chckOpenGL->SetValue(true);
    m_chckOpenGL->SetToolTip(_("Use OpenGL rendering or software rendering\?"));
    BoxSizer9->Add(m_chckOpenGL, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_chckFrameskip = new wxCheckBox(m_panVideo, ID_CHECKBOX1, _("Frameskip"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    m_chckFrameskip->SetValue(false);
    m_chckFrameskip->SetToolTip(_("Should MDDC-SDL skip every second frame\?"));
    BoxSizer9->Add(m_chckFrameskip, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4->Add(StaticBoxSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_panVideo->SetSizer(BoxSizer4);
    BoxSizer4->Fit(m_panVideo);
    BoxSizer4->SetSizeHints(m_panVideo);
    m_panSound = new wxPanel(Notebook1, ID_PANEL_SOUND, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_SOUND"));
    m_panAbout = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer11 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer6 = new wxStaticBoxSizer(wxVERTICAL, m_panAbout, _("Game info"));
    TextCtrl1 = new wxTextCtrl(m_panAbout, ID_TEXTCTRL1, _("An SDL port of Mercenary, based on original games that were written by Paul Woakes and (C) 1986 Novagen.\nYou\'ll find very valuable informations about the game on a fan website:\nhttp://mercenarysite.free.fr/\nFeedback: \nSzymon \"Enjo\" Ender - ender-sz@go2.pl\nMDDClone Author - mddclone@hotmail.com\n\nInitiative not associated with Psygnosis or Sony."), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_WORDWRAP, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticBoxSizer6->Add(TextCtrl1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer11->Add(StaticBoxSizer6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, m_panAbout, _("People involved (* means that this person worked for Novagen)"));
    m_listAuthors = new wxListCtrl(m_panAbout, ID_LIST_AUTHORS, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_HRULES|wxLC_VRULES|wxSUNKEN_BORDER, wxDefaultValidator, _T("ID_LIST_AUTHORS"));
    StaticBoxSizer4->Add(m_listAuthors, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer11->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_panAbout->SetSizer(BoxSizer11);
    BoxSizer11->Fit(m_panAbout);
    BoxSizer11->SetSizeHints(m_panAbout);
    Notebook1->AddPage(m_panGame, _("Game"), false);
    Notebook1->AddPage(m_panVideo, _("Video"), false);
    Notebook1->AddPage(m_panSound, _("Sound"), false);
    Notebook1->AddPage(m_panAbout, _("About"), false);
    BoxSizer2->Add(Notebook1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    m_butLaunch = new wxButton(Panel1, ID_BUTTON_LAUNCH, _("Play"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_LAUNCH"));
    BoxSizer3->Add(m_butLaunch, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_butExit = new wxButton(Panel1, wxID_EXIT, _("Exit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_EXIT"));
    BoxSizer3->Add(m_butExit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer1);
    BoxSizer1->Fit(Panel1);
    BoxSizer1->SetSizeHints(Panel1);
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

    Connect(ID_CHOICE_LANG,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&launcherFrame::Onm_choiceLangSelect);
    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&launcherFrame::Onm_choiceMultipSelect1);
    Connect(ID_BUTTON_LAUNCH,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&launcherFrame::Onm_butLaunchClick1);
    Connect(wxID_EXIT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&launcherFrame::Onm_butExitClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&launcherFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&launcherFrame::OnAbout);
    //*)

    // TODO - get from file or controls
    m_bFullscreen = false;
    m_iMultipl = 1;

    CalcResolution();
    LoadConfig();
    InitAuthorsList();

}

launcherFrame::~launcherFrame()
{
  SaveConfig();
    //(*Destroy(launcherFrame)
    //*)
}

void launcherFrame::OnQuit(wxCommandEvent& event)
{
    Close();

}

void launcherFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void launcherFrame::InitAuthorsList()
{
  int i = 0;
  long tmp = 0;
  m_listAuthors->Hide();
  m_listAuthors->InsertColumn(i++, _("Person"),wxLIST_FORMAT_LEFT, 120);
  m_listAuthors->InsertColumn(i++, _("Role"),wxLIST_FORMAT_LEFT, 250);

  i = 0;
  tmp = m_listAuthors->InsertItem(i++, _("Szymon \"Enjo\" Ender"));
  m_listAuthors->SetItem(tmp, 1, _("SDL port, Polish translation (parts 1 and 2), testing"));
  tmp = m_listAuthors->InsertItem(i++, _("MDDClone Author"));
  m_listAuthors->SetItem(tmp, 1, _("Win32 port, project coordination"));

  tmp = m_listAuthors->InsertItem(i++, _("Simon Guyart"));
  m_listAuthors->SetItem(tmp, 1, _("Webmaster, French translation, testing, ideas"));
  tmp = m_listAuthors->InsertItem(i++, _("Paul Dixon"));
  m_listAuthors->SetItem(tmp, 1, _("Testing, ideas"));
  tmp = m_listAuthors->InsertItem(i++, _("Pawel Garycki"));
  m_listAuthors->SetItem(tmp, 1, _("Polish translation (part 3) testing, ideas"));
  tmp = m_listAuthors->InsertItem(i++, _("Vosla"));
  m_listAuthors->SetItem(tmp, 1, _("German translation"));
  tmp = m_listAuthors->InsertItem(i++, _("Alexander Gettinger"));
  m_listAuthors->SetItem(tmp, 1, _("German translation"));
  tmp = m_listAuthors->InsertItem(i++, _("Simone Gremmo"));
  m_listAuthors->SetItem(tmp, 1, _("Italian translation"));
  tmp = m_listAuthors->InsertItem(i++, _("Nick Kal"));
  m_listAuthors->SetItem(tmp, 1, _("Greek translation"));
  tmp = m_listAuthors->InsertItem(i++, _("Jacob Gunness"));
  m_listAuthors->SetItem(tmp, 1, _("Danish translation"));
  tmp = m_listAuthors->InsertItem(i++, _("Flemming Srrvin"));
  m_listAuthors->SetItem(tmp, 1, _("Danish translation"));
  tmp = m_listAuthors->InsertItem(i++, _("Gurlus Gully"));
  m_listAuthors->SetItem(tmp, 1, _("Danish translation"));
  tmp = m_listAuthors->InsertItem(i++, _("Anne Andelvan"));
  m_listAuthors->SetItem(tmp, 1, _("Dutch translation"));
  tmp = m_listAuthors->InsertItem(i++, _("Istvan Szulovszky"));
  m_listAuthors->SetItem(tmp, 1, _("Hungarian translation"));
  tmp = m_listAuthors->InsertItem(i++, _("Attilla"));
  m_listAuthors->SetItem(tmp, 1, _("Hungarian translation"));
  tmp = m_listAuthors->InsertItem(i++, _("Csipi"));
  m_listAuthors->SetItem(tmp, 1, _("Hungarian translation"));

  tmp = m_listAuthors->InsertItem(i++, _("Paul Woakes"));
  m_listAuthors->SetItem(tmp, 1, _("* Lead programmer, Novagen boss"));
  tmp = m_listAuthors->InsertItem(i++, _("Bruce Jordan RIP"));
  m_listAuthors->SetItem(tmp, 1, _("* Novagen boss #2"));
  tmp = m_listAuthors->InsertItem(i++, _("Mo Warden"));
  m_listAuthors->SetItem(tmp, 1, _("* Graphic designer"));
  tmp = m_listAuthors->InsertItem(i++, _("Tim Bosher"));
  m_listAuthors->SetItem(tmp, 1, _("* Public relations"));
  tmp = m_listAuthors->InsertItem(i++, _("Neil Toulouse"));
  m_listAuthors->SetItem(tmp, 1, _("* Design assistant"));
  tmp = m_listAuthors->InsertItem(i++, _("Nick Bacchus"));
  m_listAuthors->SetItem(tmp, 1, _("* Design assistant, testing and ideas for Win32 port"));
  tmp = m_listAuthors->InsertItem(i++, _("Ian Thompson-Yates "));
  m_listAuthors->SetItem(tmp, 1, _("*"));
  tmp = m_listAuthors->InsertItem(i++, _("Jack Moorby "));
  m_listAuthors->SetItem(tmp, 1, _("*"));
  tmp = m_listAuthors->InsertItem(i++, _("Peter Pachla"));
  m_listAuthors->SetItem(tmp, 1, _("* Programme assistant"));
  tmp = m_listAuthors->InsertItem(i++, _("Martin Stallard"));
  m_listAuthors->SetItem(tmp, 1, _("* Design assistant"));
  tmp = m_listAuthors->InsertItem(i++, _("Michael Rooke"));
  m_listAuthors->SetItem(tmp, 1, _("* Sound effects"));
  tmp = m_listAuthors->InsertItem(i++, _("Simon Berry"));
  m_listAuthors->SetItem(tmp, 1, _("* Music"));
  tmp = m_listAuthors->InsertItem(i++, _("Jason Martin"));
  m_listAuthors->SetItem(tmp, 1, _("*"));
  tmp = m_listAuthors->InsertItem(i++, _("Mark Bedford"));
  m_listAuthors->SetItem(tmp, 1, _("*"));
  tmp = m_listAuthors->InsertItem(i++, _("Eddie Fisher"));
  m_listAuthors->SetItem(tmp, 1, _("*"));
  tmp = m_listAuthors->InsertItem(i++, _("David Aubrey-Jones"));
  m_listAuthors->SetItem(tmp, 1, _("* converted Mercenary 1 to Spectrum and Amstrad"));
  tmp = m_listAuthors->InsertItem(i++, _("Tony Takoushi"));
  m_listAuthors->SetItem(tmp, 1, _("* ? not sure "));
  tmp = m_listAuthors->InsertItem(i++, _("Jonathon Wild"));
  m_listAuthors->SetItem(tmp, 1, _("Betatester at Psygnosis"));
  tmp = m_listAuthors->InsertItem(i++, _("Peter Gudynas"));
  m_listAuthors->SetItem(tmp, 1, _("Mercenary 1 illustration"));

  m_listAuthors->Show();
}



void launcherFrame::Onm_chckFullscreenClick(wxCommandEvent& event)
{

}

void launcherFrame::CalcResolution()
{
  wxString strRes;
  int mul = m_choiceMultip->GetSelection() + 1;
  strRes.Printf(_("%d"), 320 * mul );
  m_txtResolW->SetValue(strRes);
  strRes.Printf(_("%d"), 200 * mul );
  m_txtResolH->SetValue(strRes);
}

#define CFGFILE _("/.MDDC-SDL-launcherCfg.txt")
#define LANG wxString(_("LANGUAGE="))
#define FULLSCREEN wxString(_("FULLSCREEN=")) // fullscreen
#define OGL wxString(_("OPENGL="))
#define FRAMESKIP wxString(_("FRAMESKIP="))
#define RESOL_MULTIP wxString(_("RESOL_MULTIP=")) // resolution multiplier
#define W wxString(_("SCREEN_WIDTH="))
#define H wxString(_("SCREEN_HEIGHT="))
#define NL wxString(_("\n"))

bool launcherFrame::SaveConfig()
{
  wxString strPath = wxStandardPaths::Get().GetUserConfigDir() + CFGFILE;
  //wxFFile f(stdpaths.GetUserDataDir() + CFGFILE, _("w")); // dir must be created first
  wxFFile f(strPath, _("w"));

  if ( !f.IsOpened() )
  {
    wxMessageBox(_("Couldn't open file for writing"),_("Error"), wxICON_ERROR );
    return false;
  }
  f.Close();
  if ( ! wxFile::Exists(strPath) )
  {
    strPath = wxString(_T("./")) + CFGFILE; // fallback - try game directory
  }
  if ( ! f.Open(strPath, _("w")) )
  {
    wxMessageBox(_("Couldn't open file for writing"),_("Error"), wxICON_ERROR );
    return false;
  }

  wxString out;
  out += ( LANG + m_choiceLang->GetStringSelection() + NL ) ;
  out += ( FULLSCREEN + wxString::Format(_("%d"), m_chckFullscreen->IsChecked() ) + NL );
  out += ( OGL + wxString::Format(_("%d"), m_chckOpenGL->IsChecked() ) + NL );
  out += ( FRAMESKIP + wxString::Format(_("%d"), m_chckFrameskip->IsChecked() ) + NL );
  out += ( RESOL_MULTIP + wxString::Format(_("%d"), m_choiceMultip->GetSelection() ) + NL );
  out += ( W + m_txtResolW->GetValue() + NL );
  out += ( H + m_txtResolH->GetValue() + NL );

  if ( !f.Write( out ) )
  {
    wxMessageBox(_("Couldn't write to the file"),_("Error"), wxICON_ERROR );
    return false;
  }
  return true;
}

bool launcherFrame::LoadConfig()
{
  wxString strPath = wxStandardPaths::Get().GetUserConfigDir() + CFGFILE;
  if ( ! wxFile::Exists(strPath) )
  {
    strPath = wxString(_T("./")) + CFGFILE; // fallback - try game directory
    if ( ! wxFile::Exists(strPath) )
      return false;
  }
  //wxFFile f(stdpaths.GetUserDataDir() + CFGFILE, _("r")); // dir must be created first
  wxFFile f(strPath, _("r"));
  if ( !f.IsOpened() )
  {
    wxMessageBox(_("Couldn't open file for reading"),_("Error"), wxICON_ERROR );
    return false;
  }
  wxString strFile;
  if ( !f.ReadAll( &strFile ) )
  {
    wxMessageBox(_("Couldn't read from file"),_("Error"), wxICON_ERROR );
    return false;
  }
  wxString strRet;
  int ret = 0;

  strRet = GetStr(LANG, strFile);
  if ( strRet == wxEmptyString )  return false;
  else  m_choiceLang->SetStringSelection(strRet);

  ret = GetInt(FULLSCREEN, strFile);
  if ( ret == wxNOT_FOUND )  return false;
  else m_chckFullscreen->SetValue(ret);

  ret = GetInt(OGL, strFile);
  if ( ret == wxNOT_FOUND )  return false;
  else m_chckOpenGL->SetValue(ret);

  ret = GetInt(FRAMESKIP, strFile);
  if ( ret == wxNOT_FOUND )  return false;
  else m_chckFrameskip->SetValue(ret);

  ret = GetInt(RESOL_MULTIP, strFile);
  if ( ret == wxNOT_FOUND )  return false;
  else m_choiceMultip->SetSelection(ret);

  ret = GetInt(W, strFile);
  if ( ret == wxNOT_FOUND )  return false;
  else m_txtResolW->SetValue(wxString::Format(_("%d"),ret));

  ret = GetInt(H, strFile);
  if ( ret == wxNOT_FOUND )  return false;
  else m_txtResolH->SetValue(wxString::Format(_("%d"),ret));

  return true;
}

int launcherFrame::GetInt(const wxString & strTag, const wxString & strIn )
{
  int val = wxNOT_FOUND;
  wxString strMid, strNum;
  int i = 0;
  i = strIn.Find(strTag);

  if ( i == wxNOT_FOUND )
  {
    wxString strError(strTag);
    strError += _(" tag not found!");
    wxMessageBox( strError );
    return val;
  }
  strMid = strIn.Mid(i);
  int numStart = strMid.Find(_("=")) + 1;
  int numEnd = strMid.Find(_("\n"));
  strNum = strMid.Mid( numStart, numEnd - numStart );
  val = wxAtoi(strNum);
  return val;
}


wxString launcherFrame::GetStr(const wxString & strTag, const wxString & strIn)
{
  wxString strVal, strMid, strNum;

  int i = strIn.Find(strTag);
  if ( i == wxNOT_FOUND )
  {
    wxString strError(strTag);
    strError += _(" tag not found!");
    wxMessageBox( strError );
    return strVal;
  }
  strMid = strIn.Mid(i);
  int numStart = strMid.Find(_("=")) + 1;
  int numEnd = strMid.Find(_("\n"));
  strVal = strMid.Mid( numStart, numEnd - numStart );
  if ( strVal == wxEmptyString )
  {
    wxString strError(strTag);
    strError += _(" tag has incorrect value!");
    wxMessageBox( strError );
  }
  return strVal;
}

void launcherFrame::Onm_choiceMultipSelect(wxCommandEvent& event)
{
  CalcResolution();
}

void launcherFrame::OnNotebook1PageChanged(wxNotebookEvent& event)
{
}

void launcherFrame::Onm_butExitClick(wxCommandEvent& event)
{
  Close();
}

void launcherFrame::Onm_choiceMultipSelect1(wxCommandEvent& event)
{
  CalcResolution();
}

void launcherFrame::Onm_butLaunchClick1(wxCommandEvent& event)
{
#if defined(__WXMSW__)
  wxString argv = _("mddclone-sdl");
#else
  wxString argv = _("bash -c 'export LD_LIBRARY_PATH=lib:LD_LIBRARY_PATH && ./mddclone-sdl");
#endif

  if (m_chckOpenGL->IsChecked())
    argv += _("-ogl");
  else
    argv += _("-gfx");


  if (m_chckFullscreen->IsChecked())
    argv += _(" -f ");

  if (m_chckFrameskip->IsChecked())
    argv += _(" -k ");
  //int mul = m_choiceMultip->GetSelection() + 1;  // currently unused
  //argv += wxString::Format(_(" -s %d"), mul);

  argv += _(" -w ") + m_txtResolW->GetValue();
  argv += _(" -h ") + m_txtResolH->GetValue();

  argv += _(" -l ") + m_choiceLang->GetStringSelection();

#if defined(__WXMSW__)
#else
  argv += _("'"); // End the bash arguments
#endif
  //wxMessageBox(argv);
  wxExecute(argv);
}

void launcherFrame::Onm_choiceLangSelect(wxCommandEvent& event)
{
}


/***************************************************************
 * Name:      launcherMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2009-06-14
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef LAUNCHERMAIN_H
#define LAUNCHERMAIN_H

#ifndef WX_PRECOMP
//(*Headers(launcherFrame)
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
//*)
#endif
class launcherFrame: public wxFrame
{
    public:

        launcherFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~launcherFrame();

    private:

        void CalcResolution();
        bool SaveConfig();
        bool LoadConfig();
        void InitAuthorsList();
        int GetInt(const wxString & strTag, const wxString & strIn);
        wxString GetStr(const wxString & strTag, const wxString & strIn);
        //(*Handlers(launcherFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void Onm_chckFullscreenClick(wxCommandEvent& event);
        void Onm_butLaunchClick(wxCommandEvent& event);
        void Onm_choiceMultipSelect(wxCommandEvent& event);
        void OnNotebook1PageChanged(wxNotebookEvent& event);
        void Onm_butExitClick(wxCommandEvent& event);
        void Onm_choiceMultipSelect1(wxCommandEvent& event);
        void Onm_butLaunchClick1(wxCommandEvent& event);
        void Onm_choiceLangSelect(wxCommandEvent& event);
        //*)

        //(*Identifiers(launcherFrame)
        static const long ID_CHOICE_LANG;
        static const long ID_PANEL_GAME;
        static const long ID_STATICTEXT1;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL_RESOL_W;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL_RESOL_H;
        static const long ID_CHECKBOX_FULLSCREEN;
        static const long ID_CHECKBOX_OPENGL;
        static const long ID_CHECKBOX1;
        static const long ID_PANEL_VIDEO;
        static const long ID_PANEL_SOUND;
        static const long ID_TEXTCTRL1;
        static const long ID_LIST_AUTHORS;
        static const long ID_PANEL2;
        static const long ID_NOTEBOOK1;
        static const long ID_BUTTON_LAUNCH;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(launcherFrame)
        wxChoice* m_choiceLang;
        wxChoice* m_choiceMultip;
        wxPanel* Panel1;
        wxCheckBox* m_chckFrameskip;
        wxPanel* m_panVideo;
        wxStatusBar* StatusBar1;
        wxPanel* m_panSound;
        wxListCtrl* m_listAuthors;
        wxPanel* m_panGame;
        wxButton* m_butLaunch;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxPanel* m_panAbout;
        wxCheckBox* m_chckFullscreen;
        wxTextCtrl* m_txtResolW;
        wxCheckBox* m_chckOpenGL;
        wxTextCtrl* m_txtResolH;
        wxNotebook* Notebook1;
        //*)

        bool m_bFullscreen;
        int m_iMultipl;

        DECLARE_EVENT_TABLE()
};

#endif // LAUNCHERMAIN_H

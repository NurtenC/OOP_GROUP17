#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Tabs.H>
#include "GuiManager.h"

class HomepageGroup : public Fl_Group {
public:
    HomepageGroup(int x, int y, int w, int h, GuiManager* manager);

    void update();

private:
    GuiManager* guiManager;
    
    // mky eklendi: Artık "Welcome" yazısı için kullanılacak
    Fl_Box* welcomeLabel;  // <<--- Bu sayede .cpp dosyasında 'welcomeLabel' hatası almazsınız

    // Tarih/saat kutuları (sağ üst)
    Fl_Box* dateBox;
    Fl_Box* timeBox;

    // mky removed: Eski userNameLabel & budgetLabel kaldırıldı

    // User Info & Settings sekmesi (orta bölüm)
    Fl_Tabs* userTabs;

    // "User Info" sekmesi
    Fl_Group* userInfoGroup;
    Fl_Box* userInfoUsernameLabel;
    Fl_Box* userInfoBudgetLabel;

    // "Settings" sekmesi
    Fl_Group* userSettingsGroup;
    Fl_Input* settingsUsernameInput;
    Fl_Input* settingsPasswordInput;
    Fl_Input* settingsBudgetInput;
    Fl_Button* settingsSaveButton;
    Fl_Input* settingsPasswordConfirmInput; // Şifreyi tekrar girme alanı

    // Callback fonksiyonları
    static void updateTimeCallback(void *data);
    static void logoutCallback(Fl_Widget* widget, void* data);
    static void saveSettingsCallback(Fl_Widget* widget, void* data);
};

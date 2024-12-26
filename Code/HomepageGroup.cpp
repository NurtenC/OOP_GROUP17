#include "HomepageGroup.h"
#include "Date.h"
#include <Fl/fl_ask.H>
#include <FL/Fl_Tabs.H>    
#include <FL/Fl_Group.H>   
#include <FL/Fl_Input.H>   

HomepageGroup::HomepageGroup(int x, int y, int w, int h, GuiManager* manager)
    : Fl_Group(x, y, w, h), guiManager(manager)
{
    // "Welcome" yazısını Add menüsünün bitiminden 100 piksel sağa, pencere üstünden 100 piksel aşağıya koyalım
    welcomeLabel = new Fl_Box(
        165 + 100,  
        y + 100,     
        300, 50,
        "Welcome to Expense Tracker"
    );
    welcomeLabel->labelcolor(fl_rgb_color(0x77, 0x52, 0x9e));
    welcomeLabel->labelsize(28);
    welcomeLabel->labelfont(FL_COURIER_BOLD);
    welcomeLabel->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);

    // Tarih kutusu (sağ üst)
    dateBox = new Fl_Box(x + w - 210, y + 10, 80, 40);
    dateBox->box(FL_FLAT_BOX);
    dateBox->color(fl_rgb_color(0xa5, 0xbd, 0xfd));
    dateBox->labelsize(18);
    dateBox->labelfont(FL_HELVETICA);
    dateBox->labelcolor(fl_rgb_color(0x27, 0x29, 0x6d));
    dateBox->copy_label(guiManager->getExpenseTracker()->getDate()->getDateString().c_str());

    // Saat kutusu (sağ üst, tarih yanında)
    timeBox = new Fl_Box(x + w - 120, y + 10, 80, 40);
    timeBox->box(FL_FLAT_BOX);
    timeBox->color(fl_rgb_color(0xa5, 0xbd, 0xfd));
    timeBox->labelsize(18);
    timeBox->labelfont(FL_HELVETICA);
    timeBox->labelcolor(fl_rgb_color(0x27, 0x29, 0x6d));
    timeBox->copy_label(Date::getTimeStr(guiManager->getExpenseTracker()->getTime()).c_str());

    // Logout butonu (alt sağ)
    Fl_Button* logoutButton = new Fl_Button(x + w - 160, y + h - 50, 140, 35, "Log Out");
    logoutButton->labelsize(16);
    logoutButton->color(fl_rgb_color(0xdc, 0xb5, 0xff));
    logoutButton->color2(fl_rgb_color(0xff, 0xd3, 0xb6));
    logoutButton->callback(logoutCallback, this);

    // Sürekli zaman güncelleme
    Fl::add_timeout(0.001, updateTimeCallback, this);

    // User Info & Settings sekmelerini Add menüsünün bittiği (x=165) ve pencerenin altından biraz yukarıda başlatalım
    userTabs = new Fl_Tabs(165, y + 160, 620, 320, "User Info & Settings");
    userTabs->labelcolor(fl_rgb_color(0x77, 0x52, 0x9e));
    userTabs->labelfont(FL_COURIER_BOLD);
    userTabs->labelsize(18);

    // --- USER INFO SEKME ---
    userInfoGroup = new Fl_Group(165, y + 190, 620, 290, "User Info");
    userInfoGroup->labelcolor(fl_rgb_color(0x27, 0x29, 0x6d));
    userInfoGroup->labelfont(FL_COURIER_BOLD);
    userInfoGroup->labelsize(16);
    {
        // Username
        userInfoUsernameLabel = new Fl_Box(
            150 + 20,       // solda, 
            (y + 220),      
            200, 30,
            "Username:"
        );
        userInfoUsernameLabel->labelsize(14);

        // Budget
        userInfoBudgetLabel = new Fl_Box(
            150 + 20,
            (y + 260),
            200, 30,
            "Budget:"
        );
        userInfoBudgetLabel->labelsize(14);
    }
    userInfoGroup->end();

    // --- SETTINGS SEKME ---
    userSettingsGroup = new Fl_Group(165, y + 190, 620, 290, "Settings");
    userSettingsGroup->labelcolor(fl_rgb_color(0x27, 0x29, 0x6d));
    userSettingsGroup->labelfont(FL_COURIER_BOLD);
    userSettingsGroup->labelsize(16);
    {
        // Yeni Kullanıcı Adı
        settingsUsernameInput = new Fl_Input(
            350 + 20,  
            (y + 220),
            200, 30,
            "New Username:"
        );
        settingsUsernameInput->labelsize(14);

        // Yeni Şifre
        settingsPasswordInput = new Fl_Input(
            350 + 20,
            (y + 260),
            200, 30,
            "New Password:"
        );
        settingsPasswordInput->type(FL_SECRET_INPUT);
        settingsPasswordInput->labelsize(14);

        // Şifre Tekrar
        settingsPasswordConfirmInput = new Fl_Input(
            350 + 20,
            (y + 300),
            200, 30,
            "Confirm Password:"
        );
        settingsPasswordConfirmInput->type(FL_SECRET_INPUT);
        settingsPasswordConfirmInput->labelsize(14);

        // Yeni Budget
        settingsBudgetInput = new Fl_Input(
            350 + 20, 
            (y + 340),
            80, 30,
            "New Budget:"
        );
        settingsBudgetInput->labelsize(14);

        // Save Butonu (en sağ alt)
        settingsSaveButton = new Fl_Button(
            165 + 470,  
            (y + 360),  
            100, 35,
            "Save"
        );
        settingsSaveButton->labelsize(14);
        settingsSaveButton->color(fl_rgb_color(0xdc, 0xb5, 0xff));
        settingsSaveButton->callback(saveSettingsCallback, this);
    }
    userSettingsGroup->end();

    userTabs->end();
    end(); // Fl_Group end
}

// Zamanı düzenli güncelliyoruz
void HomepageGroup::updateTimeCallback(void *data)
{
    HomepageGroup* hp = static_cast<HomepageGroup*>(data);
    GuiManager* gm = hp->guiManager;
    ExpenseTracker* et = gm->getExpenseTracker();
    et->updateTime(100);

    auto timeAsInt = std::chrono::system_clock::to_time_t(et->getTime());
    auto timeStruct = *std::localtime(&timeAsInt);
    if (timeStruct.tm_mday != et->getDate()->getDay()) {
        et->updateDate(et->getTime());
    }

    hp->dateBox->copy_label(et->getDate()->getDateString().c_str());
    hp->timeBox->copy_label(Date::getTimeStr(et->getTime()).c_str());
    Fl::repeat_timeout(0.001, updateTimeCallback, data);
}

// Logout
void HomepageGroup::logoutCallback(Fl_Widget *widget, void *data)
{
    HomepageGroup* homepageGroup = static_cast<HomepageGroup*>(data);
    GuiManager* guiManager = homepageGroup->guiManager;
    ExpenseTracker* expenseTracker = guiManager->getExpenseTracker();

    expenseTracker->logout();
    fl_message("Logout successful! Goodbye!");
    guiManager->showStartScreen();
    guiManager->update();
}

// Arayüz güncellemesi (User Info sekmesine yazı yazdırıyoruz)
void HomepageGroup::update()
{
    if (userInfoUsernameLabel) {
        userInfoUsernameLabel->copy_label(
            ("Username: " + guiManager->getExpenseTracker()->getCurrentUsername()).c_str()
        );
    }
    if (userInfoBudgetLabel) {
        userInfoBudgetLabel->copy_label(
            ("Budget: " + guiManager->getExpenseTracker()->getBudgetAsString()).c_str()
        );
    }
}

// Ayarları kaydetme (Settings sekmesi)
void HomepageGroup::saveSettingsCallback(Fl_Widget* widget, void* data)
{
    HomepageGroup* hg = static_cast<HomepageGroup*>(data);
    GuiManager* gm = hg->guiManager;
    ExpenseTracker* et = gm->getExpenseTracker();

    // Kullanıcı giriş yapmamışsa
    if (!et || et->getCurrentUsername().empty()) {
        fl_alert("You must be logged in to update settings.");
        return;
    }

    std::string newUsername = hg->settingsUsernameInput->value();
    std::string newPassword = hg->settingsPasswordInput->value();
    std::string newPasswordConfirm = hg->settingsPasswordConfirmInput->value();
    std::string newBudgetStr = hg->settingsBudgetInput->value();

    // Her şey boşsa
    bool noInputProvided = (newUsername.empty() && newPassword.empty() && newBudgetStr.empty());
    if (noInputProvided) {
        fl_alert("No changes detected.");
        return;
    }

    // Şifre eşleşmesi
    if (!newPassword.empty() && newPassword != newPasswordConfirm) {
        fl_alert("Passwords do not match. Please try again.");
        return;
    }

    // Eski budget'i al (Register'da girilen veya sonradan güncellenen)
    double oldBudget = 0.0;
    {
        // getBudgetAsString() tipik olarak "Budget: $50" veya "$50" dönebilir
        // Dolayısıyla '$' karakterinin konumunu bulup ondan sonraki kısmı parse ediyoruz
        std::string currentBudgetStr = et->getBudgetAsString(); // Örn: "Budget: $50"
        size_t dollarPos = currentBudgetStr.find('$');
        if (dollarPos != std::string::npos) {
            std::string numberPart = currentBudgetStr.substr(dollarPos + 1);
            // "50"
            try {
                oldBudget = std::stod(numberPart);
            } catch (...) {
                oldBudget = 0.0;
            }
        }
        // Eğer '$' yoksa, belki "Budget: " bile yoksa, oldBudget 0.0 kalır
    }

    // Yeni budget parse ediyoruz veya eskisini koruyoruz
    double newBudget = oldBudget;
    if (!newBudgetStr.empty()) {
        try {
            newBudget = std::stod(newBudgetStr);
        } catch (...) {
            fl_alert("Budget must be a numeric value.");
            return;
        }
    }

    // Username / Password boşsa eskisini koru
    if (newUsername.empty()) {
        newUsername = et->getCurrentUsername();
    }
    if (newPassword.empty()) {
        newPassword = " ";
    }

    // ExpenseTracker'da güncelle
    bool success = et->updateCurrentUserInfo(newUsername, newPassword, newBudget);
    if (success) {
        fl_message("User info updated successfully!");
        gm->update();
    } else {
        fl_alert("Update failed! Possibly username already exists or invalid input.");
    }

    // Input alanlarını temizle
    hg->settingsUsernameInput->value("");
    hg->settingsPasswordInput->value("");
    hg->settingsPasswordConfirmInput->value("");
    hg->settingsBudgetInput->value("");
}

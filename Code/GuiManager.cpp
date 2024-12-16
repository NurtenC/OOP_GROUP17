#include "GuiManager.h"
#include "StartScreenGroup.h"
#include "LoginGroup.h"
#include "RegisterGroup.h"
#include "MainApplicationGroup.h"

GuiManager::GuiManager(ExpenseTracker* expenseTracker) {
    this->expenseTracker = expenseTracker;
    window = new Fl_Double_Window(xResolution, yResolution, "Expense Tracker");

    startScreenGroup = new StartScreenGroup(0, 0, xResolution, yResolution, this);
    
    loginGroup = new LoginGroup(0, 0, xResolution, yResolution, this);
    loginGroup->hide();

    registerGroup = new RegisterGroup(0, 0, xResolution, yResolution, this);
    registerGroup->hide();

    mainApplicationGroup = new MainApplicationGroup(0, 0, xResolution, yResolution, this);
    mainApplicationGroup->hide();

    window->end();
}

GuiManager::~GuiManager() {
    delete window;
}

void GuiManager::run() {
    window->show();
    Fl::run();
}

ExpenseTracker* GuiManager::getExpenseTracker() {
    return expenseTracker;
}

void GuiManager::showStartScreen() {
    loginGroup->hide();
    registerGroup->hide();
    mainApplicationGroup->hide();
    startScreenGroup->show();
}

void GuiManager::showLogin() {
    startScreenGroup->hide();
    registerGroup->hide();
    mainApplicationGroup->hide();
    loginGroup->show();
}

void GuiManager::showRegister() {
    startScreenGroup->hide();
    loginGroup->hide();
    mainApplicationGroup->hide();
    registerGroup->show();
}

void GuiManager::showMainApplication() {
    startScreenGroup->hide();
    loginGroup->hide();
    registerGroup->hide();
    mainApplicationGroup->show();
}

void GuiManager::showStartScreenCallback(Fl_Widget*, void* data) {
    GuiManager* gm = static_cast<GuiManager*>(data);
    gm->showStartScreen();
}

void GuiManager::showLoginCallback(Fl_Widget*, void* data) {
    GuiManager* gm = static_cast<GuiManager*>(data);
    gm->showLogin();
}

void GuiManager::showRegisterCallback(Fl_Widget*, void* data) {
    GuiManager* gm = static_cast<GuiManager*>(data);
    gm->showRegister();
}



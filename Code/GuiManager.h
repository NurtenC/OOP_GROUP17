#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include "ExpenseTracker.h"

class StartScreenGroup;
class MainApplicationGroup;
class LoginGroup;
class RegisterGroup;


class GuiManager {
public:
    GuiManager(ExpenseTracker* expenseTracker);
    ~GuiManager();
    void run();

    void showStartScreen();
    void showLogin();
    void showRegister();
    void showMainApplication();

    ExpenseTracker* getExpenseTracker();

    static void showStartScreenCallback(Fl_Widget*, void* data);
    static void showLoginCallback(Fl_Widget*, void* data);
    static void showRegisterCallback(Fl_Widget*, void* data); 

private:
    ExpenseTracker* expenseTracker;

    Fl_Double_Window* window;
    StartScreenGroup* startScreenGroup;
    LoginGroup* loginGroup;
    RegisterGroup* registerGroup;
    MainApplicationGroup* mainApplicationGroup;

    int xResolution = 800;
    int yResolution = 600;
};


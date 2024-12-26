/**
 * @file GuiManager.cpp
 * @brief Implements the GuiManager class for managing different GUI groups and the main application window.
 */

#include "GuiManager.h"
#include "StartScreenGroup.h"
#include "LoginGroup.h"
#include "RegisterGroup.h"
#include "MainApplicationGroup.h"

/**
 * @brief Constructs a GuiManager object.
 *
 * Initializes the GUI manager with the provided ExpenseTracker, sets up the main window,
 * and initializes all GUI groups (start screen, login, register, and main application).
 *
 * @param expenseTracker Pointer to the ExpenseTracker instance to be managed.
 */
GuiManager::GuiManager(ExpenseTracker *expenseTracker)
{
    // Color codes: #f48db4, #b6cdbd, #afc5ff, #8971d0, #ffaaa5, #a5bdfd
    this->expenseTracker = expenseTracker;
    window = new Fl_Double_Window(xResolution, yResolution, "Expense Tracker");
    window->color(fl_rgb_color(0xa5, 0xbd, 0xfd)); // Light blue background
    {
        // Initialize GUI groups
        startScreenGroup = new StartScreenGroup(0, 0, xResolution, yResolution, this);
        // startScreenGroup->hide(); // Uncomment if you want to hide the start screen initially

        loginGroup = new LoginGroup(0, 0, xResolution, yResolution, this);
        loginGroup->hide();

        registerGroup = new RegisterGroup(0, 0, xResolution, yResolution, this);
        registerGroup->hide();

        mainApplicationGroup = new MainApplicationGroup(0, 0, xResolution, yResolution, this);
        mainApplicationGroup->hide();
    }
    window->end();
}

/**
 * @brief Destructs the GuiManager object.
 *
 * Cleans up dynamically allocated memory for the main window.
 */
GuiManager::~GuiManager()
{
    delete window;
}

/**
 * @brief Runs the GUI application.
 *
 * Displays the main window and starts the FLTK event loop.
 */
void GuiManager::run()
{
    window->show();
    Fl::run();
}

/**
 * @brief Retrieves the ExpenseTracker instance.
 *
 * @return Pointer to the ExpenseTracker instance.
 */
ExpenseTracker *GuiManager::getExpenseTracker()
{
    return expenseTracker;
}

/**
 * @brief Displays the start screen GUI group.
 *
 * Hides all other GUI groups and shows the start screen group.
 */
void GuiManager::showStartScreen()
{
    loginGroup->hide();
    registerGroup->hide();
    mainApplicationGroup->hide();
    startScreenGroup->show();
}

/**
 * @brief Displays the login GUI group.
 *
 * Hides all other GUI groups and shows the login group.
 */
void GuiManager::showLogin()
{
    startScreenGroup->hide();
    registerGroup->hide();
    mainApplicationGroup->hide();
    loginGroup->show();
}

/**
 * @brief Displays the register GUI group.
 *
 * Hides all other GUI groups and shows the register group.
 */
void GuiManager::showRegister()
{
    startScreenGroup->hide();
    loginGroup->hide();
    mainApplicationGroup->hide();
    registerGroup->show();
}

/**
 * @brief Displays the main application GUI group.
 *
 * Hides all other GUI groups and shows the main application group.
 */
void GuiManager::showMainApplication()
{
    startScreenGroup->hide();
    loginGroup->hide();
    registerGroup->hide();
    mainApplicationGroup->show();
}

/**
 * @brief Callback function to show the start screen.
 *
 * Static function used as a callback to display the start screen when triggered by a widget.
 *
 * @param widget The widget triggering the callback.
 * @param data Pointer to the GuiManager instance.
 */
void GuiManager::showStartScreenCallback(Fl_Widget *, void *data)
{
    GuiManager *gm = static_cast<GuiManager *>(data);
    gm->showStartScreen();
}

/**
 * @brief Callback function to show the login screen.
 *
 * Static function used as a callback to display the login screen when triggered by a widget.
 *
 * @param widget The widget triggering the callback.
 * @param data Pointer to the GuiManager instance.
 */
void GuiManager::showLoginCallback(Fl_Widget *, void *data)
{
    GuiManager *gm = static_cast<GuiManager *>(data);
    gm->showLogin();
}

/**
 * @brief Callback function to show the register screen.
 *
 * Static function used as a callback to display the register screen when triggered by a widget.
 *
 * @param widget The widget triggering the callback.
 * @param data Pointer to the GuiManager instance.
 */
void GuiManager::showRegisterCallback(Fl_Widget *, void *data)
{
    GuiManager *gm = static_cast<GuiManager *>(data);
    gm->showRegister();
}

/**
 * @brief Updates the main application group.
 *
 * Calls the update method of the main application group to refresh its contents.
 */
void GuiManager::update()
{
    mainApplicationGroup->update();
}

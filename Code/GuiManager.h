/**
 * @file GuiManager.h
 * @brief Declares the GuiManager class for managing different GUI groups and the main application window.
 */

#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include "ExpenseTracker.h" 

class StartScreenGroup;
class MainApplicationGroup;
class LoginGroup;
class RegisterGroup;

/**
 * @class GuiManager
 * @brief Manages the graphical user interface groups and the main application window.
 *
 * The GuiManager class is responsible for initializing and controlling different GUI groups
 * such as the start screen, login, registration, and the main application interface.
 * It handles the navigation between these groups and interacts with the ExpenseTracker
 * to manage user data and financial information.
 */
class GuiManager {
public:
    /**
     * @brief Constructs a GuiManager object.
     *
     * Initializes the GUI manager with the provided ExpenseTracker, sets up the main window,
     * and initializes all GUI groups (start screen, login, register, and main application).
     *
     * @param expenseTracker Pointer to the ExpenseTracker instance to be managed.
     */
    GuiManager(ExpenseTracker* expenseTracker);

    /**
     * @brief Destructs the GuiManager object.
     *
     * Cleans up dynamically allocated memory for the main window and GUI groups.
     */
    ~GuiManager();

    /**
     * @brief Runs the GUI application.
     *
     * Displays the main window and starts the FLTK event loop.
     */
    void run();

    /**
     * @brief Displays the start screen GUI group.
     *
     * Hides all other GUI groups and shows the start screen group.
     */
    void showStartScreen();

    /**
     * @brief Displays the login GUI group.
     *
     * Hides all other GUI groups and shows the login group.
     */
    void showLogin();

    /**
     * @brief Displays the register GUI group.
     *
     * Hides all other GUI groups and shows the register group.
     */
    void showRegister();

    /**
     * @brief Displays the main application GUI group.
     *
     * Hides all other GUI groups and shows the main application group.
     */
    void showMainApplication();

    /**
     * @brief Retrieves the ExpenseTracker instance.
     *
     * @return Pointer to the ExpenseTracker instance.
     */
    ExpenseTracker* getExpenseTracker();

    /**
     * @brief Callback function to show the start screen.
     *
     * Static function used as a callback to display the start screen when triggered by a widget.
     *
     * @param widget The widget triggering the callback.
     * @param data Pointer to the GuiManager instance.
     */
    static void showStartScreenCallback(Fl_Widget*, void* data);

    /**
     * @brief Callback function to show the login screen.
     *
     * Static function used as a callback to display the login screen when triggered by a widget.
     *
     * @param widget The widget triggering the callback.
     * @param data Pointer to the GuiManager instance.
     */
    static void showLoginCallback(Fl_Widget*, void* data);

    /**
     * @brief Callback function to show the register screen.
     *
     * Static function used as a callback to display the register screen when triggered by a widget.
     *
     * @param widget The widget triggering the callback.
     * @param data Pointer to the GuiManager instance.
     */
    static void showRegisterCallback(Fl_Widget*, void* data); 

    /**
     * @brief Updates the main application group.
     *
     * Calls the update method of the main application group to refresh its contents.
     */
    void update();

private:
    ExpenseTracker* expenseTracker; ///< Pointer to the ExpenseTracker instance.

    Fl_Double_Window* window; ///< Pointer to the main application window.
    StartScreenGroup* startScreenGroup; ///< Pointer to the start screen GUI group.
    LoginGroup* loginGroup; ///< Pointer to the login GUI group.
    RegisterGroup* registerGroup; ///< Pointer to the register GUI group.
    MainApplicationGroup* mainApplicationGroup; ///< Pointer to the main application GUI group.

    int xResolution = 800; ///< Width of the main window.
    int yResolution = 600; ///< Height of the main window.
};

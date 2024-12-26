/**
 * @file MainApplicationGroup.h
 * @brief Declares the MainApplicationGroup class for managing the main application interface.
 */

#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Hold_Browser.H>
#include "GuiManager.h"
#include "HomepageGroup.h"
#include "AddGroup.h"
#include "ReportGroup.h"

/**
 * @class MainApplicationGroup
 * @brief Manages the main application interface, including navigation between different sections.
 *
 * The MainApplicationGroup class inherits from Fl_Group and provides a browser for navigating
 * between the Homepage, Add, and Report sections of the Expense Tracker application.
 * It handles the display and updating of these sections based on user interaction.
 */
class MainApplicationGroup : public Fl_Group {
public:
    /**
     * @brief Constructs a MainApplicationGroup object.
     *
     * Initializes the main application interface with a navigation browser and associated groups
     * for Homepage, Add, and Report sections. Sets up callbacks for handling navigation.
     *
     * @param x The x-coordinate of the group.
     * @param y The y-coordinate of the group.
     * @param w The width of the group.
     * @param h The height of the group.
     * @param manager Pointer to the GuiManager instance managing the GUI.
     */
    MainApplicationGroup(int x, int y, int w, int h, GuiManager* manager);
    
    /**
     * @brief Updates the contents of the main application groups.
     *
     * Calls the update methods of the ReportGroup and HomepageGroup to refresh their displayed information.
     */
    void update();

private:
    GuiManager* guiManager;               ///< Pointer to the GuiManager instance.
    Fl_Hold_Browser* browser;             ///< Browser widget for navigating between sections.
    Fl_Group* grp[3];                     ///< Array of groups for Homepage, Add, and Report sections.
    Fl_Button* logoutButton;              ///< Button to handle user logout.

    /**
     * @brief Callback function to handle navigation selection.
     *
     * This static function is triggered when a selection is made in the browser.
     * It shows the selected group and hides the others based on the user's choice.
     *
     * @param widget Pointer to the widget triggering the callback.
     * @param data Pointer to the MainApplicationGroup instance.
     */
    static void SelectGroup_CB(Fl_Widget* widget, void* data);
};

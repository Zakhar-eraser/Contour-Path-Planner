/*****************************************************************//**
 * \file   MainGUI.h
 * \brief  The header of the class responsible for all GUI in the programm
 * 
 * \author Ezard
 * \date   July 2023
 *********************************************************************/
#pragma once
#include <UnigineGui.h>
#include <UnigineWidgets.h>
#include "CreateProjectWindow.h"
#include <memory>

using namespace Unigine;

/**
 * Class that contain all "high-level" (statically placed on the main window)
 * GUI widgets of the programm.
 * WidgetVBox places on the highest level and serves as background color. It
 * has the only child - WidgetTabBox, which contains buttons, panels, viewports
 * and other non-moving guis.
 */
class MainGUI
{
public:
  MainGUI() = default;
  /**
   * The constructor creates high-level GUIs and attaches callback to buttons. 
   * \param gui Pointer on the main gui container
   */
  MainGUI(GuiPtr gui);
  ~MainGUI() = default;
  /**
   * Move assignment operator overload.
   * It intended for right memory transfer between objects of the class with
   * callbacks detaching
   * \param other rvalue reference of the class' object
   * \return 
   */
  MainGUI& operator=(MainGUI&& other) noexcept;
private:
  /**
   * Pointer on the main gui container.
   */
  GuiPtr gui;
  /**
   * Box vertical alignment widget.
   * Serves for background color. Contains all other widgets high-level widgets
   * within the programm
   */
  WidgetVBoxPtr background;
  /**
   * Main tab menu widget.
   * It contains "Projects manager", "Path planner" and "Flight" tabs
   */
  WidgetTabBoxPtr tabBoxMenu;
  /**
   * The button is responsible for openning "creating project" window.
   */
  WidgetButtonPtr createProjectBtn;
  /**
   * The button is responsible for opening "opening project" window.
   */
  WidgetButtonPtr openProjectBtn;

  /**
   * Smart pointer on "creating project" window widget's class.
   */
  std::unique_ptr<CreateProjectWindow> createProjectWindowPtr;

  /**
   * Enables "Create Project" button.
   */
  void EnableCreateProjectBtn();
  /**
   * Disables "Create Project" button.
   */
  void DisableCreateProjectBtn();
  /**
   * Enables "Open Project" button.
   */
  void EnableOpenProjectBtn();
  /**
   * Disables "Open Project" button.
   */
  void DisableOpenProjectBtn();

  /**
   * Sets up callbacks for all widgets.
   */
  void SetCallbacks();
  /**
   * Removes callback from all widgets.
   * 
   */
  void RemoveCallbacks();

  /**
   * Id of the "Create Project" button pressing callback.
   */
  void* createProjectBtnCbkId;
  /**
   * Callback of the "Create Project" button pressing event.
   * \param sender Pointer on the "Create Project" button
   */
  void CreateProjectBtnCallback(WidgetPtr sender);
};


/*****************************************************************//**
 * \file   CreateProjectWindow.h
 * \brief  This file contains CreateProjectWindow class definition
 * 
 * \author Ezard
 * \date   July 2023
 *********************************************************************/
#pragma once
#include <UnigineGui.h>
#include <UnigineWidgets.h>

using namespace Unigine;

/**
 * @brief The CreateProjectWindow class contains all information about widgets in "creating project" window.
 */
class CreateProjectWindow
{
public:

  CreateProjectWindow() = default;
  /**
   * @brief CreateProjectWindow constructor.
   * Creates and manage widgets and its callbacks inside the window such as WidgetButton, WidgetFileDialog
   * \param gui Pointer to the main GUI
   */
  CreateProjectWindow(GuiPtr gui);
  ~CreateProjectWindow() = default;
private:
  WidgetWindowPtr window;

};
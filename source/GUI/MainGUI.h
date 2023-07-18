#pragma once
#include <UnigineGui.h>
#include <UnigineWidgets.h>
#include "CreateProjectWindow.h"
#include <memory>

using namespace Unigine;

class MainGUI
{
public:
  MainGUI() = default;
  MainGUI(GuiPtr gui);
  ~MainGUI() = default;

  void Show();
  void Hide();
private:
  WidgetVBoxPtr background;
  WidgetTabBoxPtr tabBoxMenu;
  WidgetButtonPtr createProjectBtn;
  WidgetButtonPtr openProjectBtn;

  std::unique_ptr<CreateProjectWindow> createProjectWindowPtr;

  void SetCallbacks();
  void CreateProjectBtnCallback(WidgetPtr sender);
};


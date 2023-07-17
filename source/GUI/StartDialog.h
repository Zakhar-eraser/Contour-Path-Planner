#pragma once
#include <UnigineGui.h>
#include <UnigineWidgets.h>

using namespace Unigine;

class StartDialog
{
public:
  StartDialog() = default;
  StartDialog(GuiPtr gui);
  ~StartDialog() = default;
private:
  WidgetWindowPtr startWindow;
  WidgetButtonPtr createProjectBtn;
  WidgetButtonPtr openProjectBtn;
};


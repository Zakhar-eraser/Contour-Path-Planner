#include "CreateProjectWindow.h"

CreateProjectWindow::CreateProjectWindow(GuiPtr gui) {
  window = WidgetWindow::create(gui, "Creating project", 5, 10);
  window->setFlags(Gui::ALIGN_CENTER | Gui::ALIGN_OVERLAP);

  window->arrange();
  gui->addChild(window);
}
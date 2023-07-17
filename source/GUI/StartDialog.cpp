#include "StartDialog.h"

StartDialog::StartDialog(GuiPtr gui)
{
	startWindow = WidgetWindow::create(gui, "Project manager", 0, 5);
	startWindow->setFlags(Gui::ALIGN_CENTER | Gui::ALIGN_OVERLAP);

	createProjectBtn = WidgetButton::create(gui, "Create project");
	createProjectBtn->setFontSize(30);
	startWindow->addChild(createProjectBtn, Gui::ALIGN_EXPAND);

	openProjectBtn = WidgetButton::create(gui, "Open project");
	openProjectBtn->setFontSize(30);
	startWindow->addChild(openProjectBtn, Gui::ALIGN_EXPAND);

	gui->addChild(startWindow, Gui::ALIGN_EXPAND);
	startWindow->arrange();
}
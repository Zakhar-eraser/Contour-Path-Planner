#include "MainGUI.h"

MainGUI::MainGUI(GuiPtr gui)
{
	background = WidgetVBox::create(gui, 0, 0);
	background->setBackground(1);

	tabBoxMenu = WidgetTabBox::create(gui, 0, 5);
	tabBoxMenu->setFlags(Gui::ALIGN_CENTER | Gui::ALIGN_OVERLAP);

	tabBoxMenu->addTab("Projects manager");
	createProjectBtn = WidgetButton::create(gui, "Create project");
	createProjectBtn->setFontSize(30);
	tabBoxMenu->addChild(createProjectBtn, Gui::ALIGN_EXPAND);
	openProjectBtn = WidgetButton::create(gui, "Open project");
	openProjectBtn->setFontSize(30);
	tabBoxMenu->addChild(openProjectBtn, Gui::ALIGN_EXPAND);

	tabBoxMenu->addTab("Path planner");

	tabBoxMenu->addTab("Flight");

	tabBoxMenu->setCurrentTab(0);
	background->addChild(tabBoxMenu, Gui::ALIGN_EXPAND);
	gui->addChild(background, Gui::ALIGN_EXPAND);
	background->arrange();
}

void MainGUI::SetCallbacks() {
	createProjectBtn->addCallback(Gui::RELEASED, MakeCallback(this, &MainGUI::CreateProjectBtnCallback));

}

void MainGUI::CreateProjectBtnCallback(WidgetPtr sender) {
	if 
}

void MainGUI::Show() {

}

void MainGUI::Hide() {

}
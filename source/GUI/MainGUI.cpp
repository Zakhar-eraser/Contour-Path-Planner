#include "MainGUI.h"

MainGUI::MainGUI(GuiPtr gui)
{
	this->gui = gui;
	createProjectBtnCbkId = 0;

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

	SetCallbacks();
}

MainGUI& MainGUI::operator=(MainGUI&& other) noexcept
{
	if (this != &other)
	{
		other.RemoveCallbacks();
		gui = std::exchange(other.gui, nullptr);
		background = std::exchange(other.background, nullptr);
		tabBoxMenu = std::exchange(other.tabBoxMenu, nullptr);
		createProjectBtn = std::exchange(other.createProjectBtn, nullptr);
		openProjectBtn = std::exchange(other.openProjectBtn, nullptr);
		SetCallbacks();
	}
	return *this;
}

void MainGUI::SetCallbacks()
{
	createProjectBtnCbkId = createProjectBtn->addCallback(Gui::PRESSED, MakeCallback(this, &MainGUI::CreateProjectBtnCallback));
}

void MainGUI::RemoveCallbacks()
{
	createProjectBtn->removeCallback(Gui::PRESSED, createProjectBtnCbkId);
}

void MainGUI::CreateProjectBtnCallback(WidgetPtr sender) {
	if (createProjectWindowPtr)
	{
		createProjectWindowPtr->Show();
	}
	else
	{
		createProjectWindowPtr = std::make_unique<CreateProjectWindow>(gui);
	}
	DisableCreateProjectBtn();
	DisableOpenProjectBtn();
}

void MainGUI::EnableCreateProjectBtn()
{
	createProjectBtn->setEnabled(1);
}

void MainGUI::DisableCreateProjectBtn()
{
	createProjectBtn->setEnabled(0);
}

void MainGUI::EnableOpenProjectBtn()
{
	openProjectBtn->setEnabled(1);
}

void MainGUI::DisableOpenProjectBtn()
{
	openProjectBtn->setEnabled(0);
}
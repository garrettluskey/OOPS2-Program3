#include "stdafx.h"
#include "BattleBots.h"
using namespace System;
using namespace System::Windows::Forms;
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Lab5::MyForm form;
	Application::Run(%form);
}

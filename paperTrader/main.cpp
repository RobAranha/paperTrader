#include "tradingInterface.h"
#include<string>

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	paperTrader::tradingInterface form;
	Application::Run(% form);
}

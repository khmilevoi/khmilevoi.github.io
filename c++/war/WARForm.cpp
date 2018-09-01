#include <list>

#include "WAR.cpp"
#include "WARForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute] void Main(array<String ^> ^ args) {
	srand(time_t(NULL));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	WAR::WARForm form;
	Application::Run(% form);
}
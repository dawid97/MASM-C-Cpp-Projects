#include "stdafx.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	LottoApp::lotto nameObjectForm;
	Application::Run(%nameObjectForm);

    return 0;
}

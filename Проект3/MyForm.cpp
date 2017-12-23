#include "stdafx.h"
#include "MyForm.h"
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void Main() 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Проект3::MyForm form;
	Application::Run(%form);

}

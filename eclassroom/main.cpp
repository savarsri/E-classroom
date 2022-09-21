#include "LoginForm.h"
#include "Dashboard.h"
#include "RegisterForm.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	User^ user = nullptr;
	while (true) {
		eclassroom::LoginForm loginForm;
		loginForm.ShowDialog();

		if (loginForm.switchToRegister) {
			eclassroom::RegisterForm registerForm;
			registerForm.ShowDialog();

			if (registerForm.switchToLogin) {
				continue;
			}
			else
			{
				user = registerForm.user;
				break;
			}
		}
		else {
			user = loginForm.user;
			break;
		}
	}

	if (user != nullptr) {
		eclassroom::Dashboard dashboard(user);
		Application::Run(% dashboard);
	}

}
#pragma once
#include "User.h"

namespace eclassroom {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(void)
		{
			InitializeComponent();
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ tbName;
	protected:
	private: System::Windows::Forms::TextBox^ tbPassword;
	private: System::Windows::Forms::TextBox^ tbEmail;
	private: System::Windows::Forms::Button^ btnRegister;
	private: System::Windows::Forms::Button^ btnLoginRegisterForm;
	private: System::Windows::Forms::TextBox^ tbPRN;

	protected:

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterForm::typeid));
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->tbEmail = (gcnew System::Windows::Forms::TextBox());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->btnLoginRegisterForm = (gcnew System::Windows::Forms::Button());
			this->tbPRN = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// tbName
			// 
			this->tbName->BackColor = System::Drawing::Color::White;
			this->tbName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(132)));
			this->tbName->Location = System::Drawing::Point(129, 230);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(325, 27);
			this->tbName->TabIndex = 2;
			this->tbName->Text = L"Enter Name";
			this->tbName->Click += gcnew System::EventHandler(this, &RegisterForm::tbName_Click);
			this->tbName->TextChanged += gcnew System::EventHandler(this, &RegisterForm::tbName_TextChanged);
			// 
			// tbPassword
			// 
			this->tbPassword->BackColor = System::Drawing::Color::White;
			this->tbPassword->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(132)));
			this->tbPassword->Location = System::Drawing::Point(129, 541);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(324, 27);
			this->tbPassword->TabIndex = 2;
			this->tbPassword->Text = L"Password";
			this->tbPassword->Click += gcnew System::EventHandler(this, &RegisterForm::tbPassword_Click);
			this->tbPassword->TextChanged += gcnew System::EventHandler(this, &RegisterForm::textBox3_TextChanged);
			// 
			// tbEmail
			// 
			this->tbEmail->BackColor = System::Drawing::Color::White;
			this->tbEmail->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbEmail->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbEmail->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(132)));
			this->tbEmail->Location = System::Drawing::Point(129, 334);
			this->tbEmail->Name = L"tbEmail";
			this->tbEmail->Size = System::Drawing::Size(325, 27);
			this->tbEmail->TabIndex = 2;
			this->tbEmail->Text = L"Enter E-Mail";
			this->tbEmail->Click += gcnew System::EventHandler(this, &RegisterForm::tbEmail_Click);
			this->tbEmail->TextChanged += gcnew System::EventHandler(this, &RegisterForm::tbEmail_TextChanged);
			// 
			// btnRegister
			// 
			this->btnRegister->BackColor = System::Drawing::Color::Transparent;
			this->btnRegister->FlatAppearance->BorderSize = 0;
			this->btnRegister->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRegister->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegister->ForeColor = System::Drawing::Color::Transparent;
			this->btnRegister->Location = System::Drawing::Point(121, 636);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(347, 50);
			this->btnRegister->TabIndex = 3;
			this->btnRegister->UseVisualStyleBackColor = false;
			this->btnRegister->Click += gcnew System::EventHandler(this, &RegisterForm::btnRegister_Click);
			// 
			// btnLoginRegisterForm
			// 
			this->btnLoginRegisterForm->BackColor = System::Drawing::Color::Transparent;
			this->btnLoginRegisterForm->FlatAppearance->BorderSize = 0;
			this->btnLoginRegisterForm->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLoginRegisterForm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnLoginRegisterForm->ForeColor = System::Drawing::Color::Transparent;
			this->btnLoginRegisterForm->Location = System::Drawing::Point(790, 592);
			this->btnLoginRegisterForm->Name = L"btnLoginRegisterForm";
			this->btnLoginRegisterForm->Size = System::Drawing::Size(340, 50);
			this->btnLoginRegisterForm->TabIndex = 3;
			this->btnLoginRegisterForm->UseVisualStyleBackColor = false;
			this->btnLoginRegisterForm->Click += gcnew System::EventHandler(this, &RegisterForm::btnLoginRegisterForm_Click);
			// 
			// tbPRN
			// 
			this->tbPRN->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPRN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPRN->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(132)));
			this->tbPRN->Location = System::Drawing::Point(129, 438);
			this->tbPRN->Name = L"tbPRN";
			this->tbPRN->Size = System::Drawing::Size(300, 27);
			this->tbPRN->TabIndex = 4;
			this->tbPRN->Text = L"Enter 4 digit PRN";
			this->tbPRN->Click += gcnew System::EventHandler(this, &RegisterForm::tbPRN_Click);
			this->tbPRN->TextChanged += gcnew System::EventHandler(this, &RegisterForm::tbPRN_TextChanged);
			// 
			// RegisterForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1262, 753);
			this->Controls->Add(this->tbPRN);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->tbEmail);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->btnLoginRegisterForm);
			this->Controls->Add(this->btnRegister);
			this->DoubleBuffered = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"RegisterForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Register";
			this->Load += gcnew System::EventHandler(this, &RegisterForm::RegisterForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
		   public: bool switchToLogin = false;
				 public: User^ user = nullptr;
private: System::Void btnLoginRegisterForm_Click(System::Object^ sender, System::EventArgs^ e) {
	this->switchToLogin = true;
	this->Close();
}
private: System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ name = tbName->Text;
	String^ email = tbEmail->Text;
	String^ password = tbPassword->Text;
	String^ prn = tbPRN->Text;

	if (name->Length == 0 || email->Length == 0 || prn->Length==0 || password->Length == 0) {
		MessageBox::Show("Please enter the required details!", "Enter details", MessageBoxButtons::OK);
		return;
	}

	if (prn->Length != 4) {
		MessageBox::Show("Please enter 4-digit PRN!", "Enter PRN", MessageBoxButtons::OK);
		return;
	}

	prn = prn->ToLower();

	if (prn->Contains("a") || prn->Contains("b") || prn->Contains("c") || prn->Contains("d") || prn->Contains("e") || prn->Contains("f") || prn->Contains("g") || prn->Contains("h") || prn->Contains("i") || prn->Contains("j") || prn->Contains("k") || prn->Contains("l") || prn->Contains("m") || prn->Contains("n") || prn->Contains("o") || prn->Contains("p") || prn->Contains("q") || prn->Contains("r") || prn->Contains("s") || prn->Contains("t") || prn->Contains("u") || prn->Contains("v") || prn->Contains("w") || prn->Contains("x") || prn->Contains("y") || prn->Contains("z")) {
		MessageBox::Show("Please enter 4-digit PRN!", "Enter PRN", MessageBoxButtons::OK);
		return;
	}

	email = email->ToLower();

	try {
		String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
		SqlConnection sqlConn(connString);
		sqlConn.Open();

		String^ sqlQuery = "INSERT INTO users " + "(name, email, prn, password) VALUES " + "(@name, @email, @prn, @password);";
		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@name", name);
		command.Parameters->AddWithValue("@email", email);
		command.Parameters->AddWithValue("@prn", prn);
		command.Parameters->AddWithValue("@password", password);

		command.ExecuteNonQuery();

		user = gcnew User;
		user->name = name;
		user->email = email;
		user->prn = prn;
		user->password = password;

		this->Close();
	}
	catch (Exception^ ex) {
		MessageBox::Show("Failed to register new user", "Failed", MessageBoxButtons::OK);
	}

}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void panel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void RegisterForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbName_Click(System::Object^ sender, System::EventArgs^ e) {
	if (tbName->Text == "Enter Name")
	{
		tbName->Text = "";
	}
}
private: System::Void tbEmail_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbEmail_Click(System::Object^ sender, System::EventArgs^ e) {
	if (tbEmail->Text == "Enter E-Mail")
	{
		tbEmail->Text = "";
	}
}
private: System::Void tbPassword_Click(System::Object^ sender, System::EventArgs^ e) {
	if (tbPassword->Text == "Password")
	{
		tbPassword->Text = "";
	}
}
private: System::Void tbPRN_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbPRN_Click(System::Object^ sender, System::EventArgs^ e) {
	if (tbPRN->Text == "Enter 4 digit PRN")
	{
		tbPRN->Text = "";
	}
}
};
}

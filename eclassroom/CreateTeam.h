#pragma once
#include <string>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "User.h"

namespace eclassroom {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::Data::SqlClient;



	/// <summary>
	/// Summary for CreateTeam
	/// </summary>
	public ref class CreateTeam : public System::Windows::Forms::Form
	{
	public:
		User^ u = nullptr;
		CreateTeam(User^ user)
		{
			InitializeComponent();
			
			u = user;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CreateTeam()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ tbName;
	protected:

	protected:


	private: System::Windows::Forms::Button^ btnCreate;
	private: System::Windows::Forms::Button^ btnCancel;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CreateTeam::typeid));
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->btnCreate = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// tbName
			// 
			this->tbName->BackColor = System::Drawing::Color::White;
			this->tbName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbName->Location = System::Drawing::Point(137, 241);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(224, 27);
			this->tbName->TabIndex = 0;
			this->tbName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btnCreate
			// 
			this->btnCreate->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btnCreate->BackColor = System::Drawing::Color::Transparent;
			this->btnCreate->FlatAppearance->BorderSize = 0;
			this->btnCreate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCreate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreate->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->btnCreate->Location = System::Drawing::Point(92, 296);
			this->btnCreate->Name = L"btnCreate";
			this->btnCreate->Size = System::Drawing::Size(99, 31);
			this->btnCreate->TabIndex = 3;
			this->btnCreate->UseVisualStyleBackColor = false;
			this->btnCreate->Click += gcnew System::EventHandler(this, &CreateTeam::btnCreate_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->BackColor = System::Drawing::Color::Transparent;
			this->btnCancel->FlatAppearance->BorderSize = 0;
			this->btnCancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->Location = System::Drawing::Point(307, 298);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(97, 31);
			this->btnCancel->TabIndex = 3;
			this->btnCancel->UseVisualStyleBackColor = false;
			this->btnCancel->Click += gcnew System::EventHandler(this, &CreateTeam::btnCancel_Click);
			// 
			// CreateTeam
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(201)), static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(101)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(482, 453);
			this->ControlBox = false;
			this->Controls->Add(this->btnCreate);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->tbName);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"CreateTeam";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CreateTeam";
			this->Load += gcnew System::EventHandler(this, &CreateTeam::CreateTeam_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
		   
private: System::Void btnCreate_Click(System::Object^ sender, System::EventArgs^ e) {
	

	String^ name = tbName->Text;

	if (name->Length == 0) {
		MessageBox::Show("Please enter the name of the team!", "Enter Name", MessageBoxButtons::OK);
		return;
	}
	char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
							  'h', 'i', 'j', 'k', 'l', 'm', 'n',
							  'o', 'p', 'q', 'r', 's', 't', 'u',
							  'v', 'w', 'x', 'y', 'z' };

	string res = "";
	for (int i = 0; i < 6; i++)
		res = res + alphabet[rand() % 26];

	String^ code = gcnew String(res.data());
	String^ tempCode;
	

		try
		{
			String^ query = "CREATE TABLE " + code + "Message (messages varchar(max), time varchar(max));";
			String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQuery = query;
			SqlCommand command(sqlQuery, % sqlConn);
			command.ExecuteNonQuery();

			try {
				String^ sqlQuery = "Select teams from users where email=@email";
				SqlCommand command(sqlQuery, % sqlConn);
				command.Parameters->AddWithValue("@email", u->email);
				SqlDataReader^ reader;
				reader = command.ExecuteReader();
				if (reader->Read()) {
					if (reader["teams"]->ToString() == "NULL" || reader["teams"]->ToString() == "") {
						tempCode = "";
					}
					else {
						tempCode = reader["teams"]->ToString();
					}
				}
				else
				{
					MessageBox::Show("No data", "Failed", MessageBoxButtons::OK);
				}
				reader->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Failed to fetch previous codes", "Failed", MessageBoxButtons::OK);
			}

			try {

				String^ sqlQuery = "UPDATE users set teams=@teams where email=@email;";
				SqlCommand command(sqlQuery, % sqlConn);
				command.Parameters->AddWithValue("@teams", tempCode+code);
				command.Parameters->AddWithValue("@email", u->email);
				command.ExecuteNonQuery();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Failed to update data", "Failed", MessageBoxButtons::OK);
			}			

			try {
				String^ sqlQuery = "INSERT INTO teams (code, name, createdBy) VALUES " + "(@code, @name, @createdBy);";
				SqlCommand command(sqlQuery, % sqlConn);
				command.Parameters->AddWithValue("@code", code);
				command.Parameters->AddWithValue("@name", name);
				command.Parameters->AddWithValue("@createdBy", u->email);
				command.ExecuteNonQuery();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Failed to join the team", "Failed", MessageBoxButtons::OK);
			}

			sqlConn.Close();

		}
		catch (Exception^ ex)
		{
			//MessageBox::Show("Failed to create team message", "Failed", MessageBoxButtons::OK);
		}

		try {
			String^ query = "CREATE TABLE " + code + "Assignment (id int IDENTITY(1,1) NOT NULL,title varchar(50) NOT NULL, description varchar(max) NOT NULL, dueDate varchar(50) NOT NULL, dueTime varchar(50) NOT NULL, link varchar(max) NOT NULL, submitBy varchar(max), PRIMARY KEY CLUSTERED ([Id] ASC));";
			String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQuery = query;
			SqlCommand command(sqlQuery, % sqlConn);
			command.ExecuteNonQuery();

			sqlConn.Close();
			this->Close();

		}
		catch (Exception^ ex) 
		{
			MessageBox::Show("Failed to create room. Try Again!", "Failed", MessageBoxButtons::OK);
		}
	

}
private: System::Void CreateTeam_Load(System::Object^ sender, System::EventArgs^ e) {
}
};

}


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
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnCreate = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// tbName
			// 
			this->tbName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(130)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tbName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbName->Location = System::Drawing::Point(12, 214);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(458, 34);
			this->tbName->TabIndex = 0;
			this->tbName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(115, 162);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(236, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Enter Name of Team";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(62, 29);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(376, 100);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// btnCreate
			// 
			this->btnCreate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(130)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnCreate->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnCreate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreate->Location = System::Drawing::Point(199, 284);
			this->btnCreate->Name = L"btnCreate";
			this->btnCreate->Size = System::Drawing::Size(99, 41);
			this->btnCreate->TabIndex = 3;
			this->btnCreate->Text = L"Create";
			this->btnCreate->UseVisualStyleBackColor = false;
			this->btnCreate->Click += gcnew System::EventHandler(this, &CreateTeam::btnCreate_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(130)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnCancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->Location = System::Drawing::Point(192, 364);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(113, 41);
			this->btnCancel->TabIndex = 3;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = false;
			this->btnCancel->Click += gcnew System::EventHandler(this, &CreateTeam::btnCancel_Click);
			// 
			// CreateTeam
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(482, 453);
			this->ControlBox = false;
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnCreate);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tbName);
			this->MaximizeBox = false;
			this->Name = L"CreateTeam";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CreateTeam";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
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
	
	String^ query = "CREATE TABLE " + code + "Message (messages varchar(max));";

		try
		{
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
				String^ sqlQuery = "INSERT INTO teams (name, code, createdBy) VALUES " + "(@name, @code, @createdBy);";
				SqlCommand command(sqlQuery, % sqlConn);
				command.Parameters->AddWithValue("@name", name);
				command.Parameters->AddWithValue("@code", code);
				command.Parameters->AddWithValue("@createdBy", u->email);
				command.ExecuteNonQuery();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Failed to join the team", "Failed", MessageBoxButtons::OK);
			}

			sqlConn.Close();
			this->Close();

		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Failed to create team", "Failed", MessageBoxButtons::OK);
		}
	

}
};

}


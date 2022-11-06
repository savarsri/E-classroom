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
	/// Summary for CreateAssignment
	/// </summary>
	public ref class CreateAssignment : public System::Windows::Forms::Form
	{
	public:
		User^ u = nullptr;
		String^ code;
		CreateAssignment(User^ user,String^ teamCode)
		{
			InitializeComponent();
			u = user;
		    code = teamCode;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CreateAssignment()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tbTitle;
	private: System::Windows::Forms::RichTextBox^ tbDescription;
	private: System::Windows::Forms::DateTimePicker^ dtpDate;
	private: System::Windows::Forms::DateTimePicker^ dtpTime;
	private: System::Windows::Forms::RichTextBox^ tbLink;
	private: System::Windows::Forms::Button^ btnCreateAssignment;
	private: System::Windows::Forms::Button^ btnCancelAssignment;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CreateAssignment::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbTitle = (gcnew System::Windows::Forms::TextBox());
			this->tbDescription = (gcnew System::Windows::Forms::RichTextBox());
			this->dtpDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->dtpTime = (gcnew System::Windows::Forms::DateTimePicker());
			this->tbLink = (gcnew System::Windows::Forms::RichTextBox());
			this->btnCreateAssignment = (gcnew System::Windows::Forms::Button());
			this->btnCancelAssignment = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(394, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(181, 36);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Assignment";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(63, 109);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Title:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(63, 183);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(105, 25);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Desription:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(63, 338);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 25);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Due Date:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(594, 337);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(103, 25);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Due Time:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(63, 427);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(121, 25);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Upload Link:";
			// 
			// tbTitle
			// 
			this->tbTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbTitle->Location = System::Drawing::Point(208, 103);
			this->tbTitle->Name = L"tbTitle";
			this->tbTitle->Size = System::Drawing::Size(669, 34);
			this->tbTitle->TabIndex = 2;
			// 
			// tbDescription
			// 
			this->tbDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbDescription->Location = System::Drawing::Point(208, 183);
			this->tbDescription->Name = L"tbDescription";
			this->tbDescription->Size = System::Drawing::Size(669, 96);
			this->tbDescription->TabIndex = 3;
			this->tbDescription->Text = L"";
			// 
			// dtpDate
			// 
			this->dtpDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpDate->Location = System::Drawing::Point(208, 340);
			this->dtpDate->Name = L"dtpDate";
			this->dtpDate->Size = System::Drawing::Size(113, 22);
			this->dtpDate->TabIndex = 4;
			// 
			// dtpTime
			// 
			this->dtpTime->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->dtpTime->Location = System::Drawing::Point(752, 337);
			this->dtpTime->Name = L"dtpTime";
			this->dtpTime->Size = System::Drawing::Size(125, 22);
			this->dtpTime->TabIndex = 5;
			// 
			// tbLink
			// 
			this->tbLink->Location = System::Drawing::Point(208, 427);
			this->tbLink->Name = L"tbLink";
			this->tbLink->Size = System::Drawing::Size(669, 73);
			this->tbLink->TabIndex = 6;
			this->tbLink->Text = L"";
			// 
			// btnCreateAssignment
			// 
			this->btnCreateAssignment->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnCreateAssignment->Location = System::Drawing::Point(285, 564);
			this->btnCreateAssignment->Name = L"btnCreateAssignment";
			this->btnCreateAssignment->Size = System::Drawing::Size(109, 46);
			this->btnCreateAssignment->TabIndex = 7;
			this->btnCreateAssignment->Text = L"Create";
			this->btnCreateAssignment->UseVisualStyleBackColor = true;
			this->btnCreateAssignment->Click += gcnew System::EventHandler(this, &CreateAssignment::btnCreateAssignment_Click);
			// 
			// btnCancelAssignment
			// 
			this->btnCancelAssignment->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnCancelAssignment->Location = System::Drawing::Point(555, 564);
			this->btnCancelAssignment->Name = L"btnCancelAssignment";
			this->btnCancelAssignment->Size = System::Drawing::Size(109, 46);
			this->btnCancelAssignment->TabIndex = 7;
			this->btnCancelAssignment->Text = L"Cancel";
			this->btnCancelAssignment->UseVisualStyleBackColor = true;
			this->btnCancelAssignment->Click += gcnew System::EventHandler(this, &CreateAssignment::btnCancelAssignment_Click);
			// 
			// CreateAssignment
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(98)), static_cast<System::Int32>(static_cast<System::Byte>(124)),
				static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->ClientSize = System::Drawing::Size(934, 658);
			this->Controls->Add(this->btnCancelAssignment);
			this->Controls->Add(this->btnCreateAssignment);
			this->Controls->Add(this->tbLink);
			this->Controls->Add(this->dtpTime);
			this->Controls->Add(this->dtpDate);
			this->Controls->Add(this->tbDescription);
			this->Controls->Add(this->tbTitle);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CreateAssignment";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Create Assignment";
			this->Load += gcnew System::EventHandler(this, &CreateAssignment::CreateAssignment_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnCreateAssignment_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ date = dtpDate->Text;
		String^ time = dtpTime->Text;
		String^ title = tbTitle->Text;
		String^ description = tbDescription->Text;
		String^ link = tbLink->Text;

		if (date->Length == 0 || time->Length == 0 || title->Length == 0 || description->Length == 0 || link->Length == 0) {
			MessageBox::Show("Enter the required details!", "Details", MessageBoxButtons::OK);
		}
		else {

			try {
				String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
				SqlConnection sqlConn(connString);
				sqlConn.Open();

				String^ sqlQuery = "INSERT INTO "+ code +"Assignment (title, description, dueDate, dueTime, link) VALUES " + "(@title, @description, @dueDate, @dueTime, @link); ";
				SqlCommand command(sqlQuery, % sqlConn);

				
				command.Parameters->AddWithValue("@title", title);
				command.Parameters->AddWithValue("@description",description);
				command.Parameters->AddWithValue("@dueDate", date);
				command.Parameters->AddWithValue("@dueTime", time);
				command.Parameters->AddWithValue("@link", link);

				command.ExecuteNonQuery();

				sqlConn.Close();
				this->Close();

			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Failed to create assignment", "Failed", MessageBoxButtons::OK);
			}

		}

	}
private: System::Void btnCancelAssignment_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void CreateAssignment_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}

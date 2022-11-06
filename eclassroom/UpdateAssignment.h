#pragma once
#include "User.h"
#include "SubmitList.h"

namespace eclassroom {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;


	/// <summary>
	/// Summary for UpdateAssignment
	/// </summary>
	public ref class UpdateAssignment : public System::Windows::Forms::Form
	{
	public:
		User^ u = nullptr;
		String^ code;
		int id;
		String^ title;
		String^ description;
		String^ dueDate;
		String^ dueTime;
	private: System::Windows::Forms::Button^ btnSby;
	public:

	public:
		String^ link;

		UpdateAssignment(User^ user, String^ teamCode, int x)
		{
			InitializeComponent();
			u = user;
			code = teamCode;
			id = x;


			try {
				String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
				SqlConnection sqlConn(connString);
				sqlConn.Open();

				String^ sqlQuery = "Select title,description,dueDate,dueTime,link from " + code + "Assignment where id=@id";
				SqlCommand command(sqlQuery, % sqlConn);
				command.Parameters->AddWithValue("@id", id);
				SqlDataReader^ reader;
				reader = command.ExecuteReader();

				if (reader->Read()) {
					if (reader["title"]->ToString() == "NULL" || reader["title"]->ToString() == "" || reader["description"]->ToString() == "NULL" || reader["description"]->ToString() == "" || reader["dueDate"]->ToString() == "NULL" || reader["dueDate"]->ToString() == "" || reader["dueTime"]->ToString() == "NULL" || reader["dueTime"]->ToString() == "" || reader["link"]->ToString() == "NULL" || reader["link"]->ToString() == "") {

					}
					else {
						title = reader["title"]->ToString();
						description = reader["description"]->ToString();
						dueDate = reader["dueDate"]->ToString();
						dueTime = reader["dueTime"]->ToString();
						link = reader["link"]->ToString();
					}
				}
				else
				{
					MessageBox::Show("No data", "Failed", MessageBoxButtons::OK);
				}

				tbTitle->Text = title;
				tbDescription->Text = description;
				dtpDate->Text = dueDate;
				dtpTime->Text = dueTime;
				tbLink->Text = link;

				reader->Close();
				sqlConn.Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error", "Error");
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UpdateAssignment()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ btnModify;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::TextBox^ tbTitle;
	private: System::Windows::Forms::RichTextBox^ tbDescription;
	private: System::Windows::Forms::RichTextBox^ tbLink;
	private: System::Windows::Forms::DateTimePicker^ dtpDate;
	private: System::Windows::Forms::DateTimePicker^ dtpTime;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UpdateAssignment::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnModify = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->tbTitle = (gcnew System::Windows::Forms::TextBox());
			this->tbDescription = (gcnew System::Windows::Forms::RichTextBox());
			this->tbLink = (gcnew System::Windows::Forms::RichTextBox());
			this->dtpDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->dtpTime = (gcnew System::Windows::Forms::DateTimePicker());
			this->btnSby = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(16, 89);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Title:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(16, 143);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(165, 32);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Description:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(16, 292);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(141, 32);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Due Date:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(478, 290);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(144, 32);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Due Time:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(16, 367);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(75, 32);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Link:";
			// 
			// btnModify
			// 
			this->btnModify->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnModify->Location = System::Drawing::Point(216, 527);
			this->btnModify->Name = L"btnModify";
			this->btnModify->Size = System::Drawing::Size(115, 53);
			this->btnModify->TabIndex = 1;
			this->btnModify->Text = L"Modify";
			this->btnModify->UseVisualStyleBackColor = true;
			this->btnModify->Click += gcnew System::EventHandler(this, &UpdateAssignment::btnModify_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->Location = System::Drawing::Point(398, 527);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(115, 53);
			this->btnCancel->TabIndex = 1;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &UpdateAssignment::btnCancel_Click);
			// 
			// tbTitle
			// 
			this->tbTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbTitle->Location = System::Drawing::Point(187, 83);
			this->tbTitle->Name = L"tbTitle";
			this->tbTitle->Size = System::Drawing::Size(628, 38);
			this->tbTitle->TabIndex = 2;
			// 
			// tbDescription
			// 
			this->tbDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbDescription->Location = System::Drawing::Point(187, 143);
			this->tbDescription->Name = L"tbDescription";
			this->tbDescription->Size = System::Drawing::Size(628, 127);
			this->tbDescription->TabIndex = 3;
			this->tbDescription->Text = L"";
			// 
			// tbLink
			// 
			this->tbLink->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbLink->Location = System::Drawing::Point(187, 367);
			this->tbLink->Name = L"tbLink";
			this->tbLink->Size = System::Drawing::Size(628, 92);
			this->tbLink->TabIndex = 3;
			this->tbLink->Text = L"";
			// 
			// dtpDate
			// 
			this->dtpDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dtpDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpDate->Location = System::Drawing::Point(187, 290);
			this->dtpDate->Name = L"dtpDate";
			this->dtpDate->Size = System::Drawing::Size(176, 34);
			this->dtpDate->TabIndex = 4;
			// 
			// dtpTime
			// 
			this->dtpTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dtpTime->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->dtpTime->Location = System::Drawing::Point(628, 288);
			this->dtpTime->Name = L"dtpTime";
			this->dtpTime->Size = System::Drawing::Size(164, 34);
			this->dtpTime->TabIndex = 4;
			// 
			// btnSby
			// 
			this->btnSby->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSby->Location = System::Drawing::Point(581, 527);
			this->btnSby->Name = L"btnSby";
			this->btnSby->Size = System::Drawing::Size(146, 53);
			this->btnSby->TabIndex = 5;
			this->btnSby->Text = L"Submitted By";
			this->btnSby->UseVisualStyleBackColor = true;
			this->btnSby->Click += gcnew System::EventHandler(this, &UpdateAssignment::btnSby_Click);
			// 
			// UpdateAssignment
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(201)), static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(101)));
			this->ClientSize = System::Drawing::Size(856, 610);
			this->Controls->Add(this->btnSby);
			this->Controls->Add(this->dtpTime);
			this->Controls->Add(this->dtpDate);
			this->Controls->Add(this->tbLink);
			this->Controls->Add(this->tbDescription);
			this->Controls->Add(this->tbTitle);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnModify);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"UpdateAssignment";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Modify Assignment";
			this->Load += gcnew System::EventHandler(this, &UpdateAssignment::UpdateAssignment_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void btnModify_Click(System::Object^ sender, System::EventArgs^ e) {

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

			String^ sqlQuery = "UPDATE "+code+"Assignment set title=@title, description=@description, dueDate=@dueDate, dueTime=@dueTime, link=@link where id=@id;";
			SqlCommand command(sqlQuery, % sqlConn);

			
			command.Parameters->AddWithValue("@title", title);
			command.Parameters->AddWithValue("@description",description);
			command.Parameters->AddWithValue("@dueDate", date);
			command.Parameters->AddWithValue("@dueTime", time);
			command.Parameters->AddWithValue("@link", link);
			command.Parameters->AddWithValue("@id", id);
			command.ExecuteNonQuery();

			sqlConn.Close();
			this->Close();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Failed to modify assignment", "Failed", MessageBoxButtons::OK);
		}
	}

}
private: System::Void UpdateAssignment_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnSby_Click(System::Object^ sender, System::EventArgs^ e) {
	eclassroom::SubmitList submitList(code, id);
	submitList.ShowDialog();
}
};
}

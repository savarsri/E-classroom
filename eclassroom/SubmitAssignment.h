#pragma once
//compile with: /clr
#include "User.h"
#include <string>


namespace eclassroom {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace std;



	/// <summary>
	/// Summary for SubmitAssignment
	/// </summary>
	public ref class SubmitAssignment : public System::Windows::Forms::Form
	{
	public:
		User^ u = nullptr;
		String^ code;
		int id;
		String^ title;
		String^ description;
		String^ due;
	
	public:
		String^ link;
		String^ submitBy;
	
		   
		SubmitAssignment(User^ user, String^ teamCode, int x)
		{
			InitializeComponent();
			u = user;
			code = teamCode;
			id = x;

			try {
				String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
				SqlConnection sqlConn(connString);
				sqlConn.Open();

				String^ sqlQuery = "Select title,description,dueDate,dueTime,link from "+code+"Assignment where id=@id";
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
						due = reader["dueDate"]->ToString() + " " + reader["dueTime"]->ToString();
						link = reader["link"]->ToString();
					}
				}
				else
				{
					MessageBox::Show("No data", "Failed", MessageBoxButtons::OK);
				}

				lbTitle->Text = title;
				richTextBox1->Text = description;
				lbDue->Text = due;
				lbLink->Text = link;

				reader->Close();
				sqlConn.Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Failed to load assignment", "Failed", MessageBoxButtons::OK);
			}

			try {
				String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
				SqlConnection sqlConn(connString);
				sqlConn.Open();

				String^ sqlQuery = "Select submitBy from "+code+"Assignment where id=@id";
				SqlCommand command(sqlQuery, % sqlConn);
				command.Parameters->AddWithValue("@id", id);
				SqlDataReader^ reader;
				reader = command.ExecuteReader();
				if (reader->Read()) {
					if (reader["submitBy"]->ToString() == "NULL" || reader["submitBy"]->ToString() == "") {
						submitBy = "";
					}
					else {
						submitBy = reader["submitBy"]->ToString();
					}
				}
				else
				{
					MessageBox::Show("No data", "Failed", MessageBoxButtons::OK);
				}
				reader->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->ToString(), "Failed", MessageBoxButtons::OK);
			}

			if (submitBy->Contains(u->email->ToString())) {
				btnSubmit->Text = "Undo Submit";
			}


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SubmitAssignment()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ lbTitle;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lbDue;
	private: System::Windows::Forms::LinkLabel^ lbLink;
	private: System::Windows::Forms::Button^ btnSubmit;
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
			this->lbTitle = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbDue = (gcnew System::Windows::Forms::Label());
			this->lbLink = (gcnew System::Windows::Forms::LinkLabel());
			this->btnSubmit = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// lbTitle
			// 
			this->lbTitle->AutoSize = true;
			this->lbTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbTitle->Location = System::Drawing::Point(56, 27);
			this->lbTitle->Name = L"lbTitle";
			this->lbTitle->Size = System::Drawing::Size(93, 42);
			this->lbTitle->TabIndex = 0;
			this->lbTitle->Text = L"Title";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(57, 251);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Due on:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(57, 319);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(143, 32);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Upload in:";
			// 
			// lbDue
			// 
			this->lbDue->AutoSize = true;
			this->lbDue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbDue->Location = System::Drawing::Point(237, 251);
			this->lbDue->Name = L"lbDue";
			this->lbDue->Size = System::Drawing::Size(113, 32);
			this->lbDue->TabIndex = 0;
			this->lbDue->Text = L"Due on:";
			// 
			// lbLink
			// 
			this->lbLink->AutoSize = true;
			this->lbLink->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLink->Location = System::Drawing::Point(237, 319);
			this->lbLink->Name = L"lbLink";
			this->lbLink->Size = System::Drawing::Size(67, 32);
			this->lbLink->TabIndex = 1;
			this->lbLink->TabStop = true;
			this->lbLink->Text = L"Link";
			// 
			// btnSubmit
			// 
			this->btnSubmit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSubmit->Location = System::Drawing::Point(243, 413);
			this->btnSubmit->Name = L"btnSubmit";
			this->btnSubmit->Size = System::Drawing::Size(183, 72);
			this->btnSubmit->TabIndex = 2;
			this->btnSubmit->Text = L"Submit";
			this->btnSubmit->UseVisualStyleBackColor = true;
			this->btnSubmit->Click += gcnew System::EventHandler(this, &SubmitAssignment::btnSubmit_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->Location = System::Drawing::Point(512, 413);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(107, 50);
			this->btnCancel->TabIndex = 2;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &SubmitAssignment::btnCancel_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(63, 83);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(726, 138);
			this->richTextBox1->TabIndex = 3;
			this->richTextBox1->Text = L"";
			// 
			// SubmitAssignment
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(846, 497);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnSubmit);
			this->Controls->Add(this->lbLink);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lbDue);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbTitle);
			this->Name = L"SubmitAssignment";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Assignment";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e) {

	if (btnSubmit->Text == "Submit" || btnSubmit->Text == "Submit late") {

		submitBy = submitBy + u->email;
		try {
			String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQuery = "UPDATE " + code + "Assignment set submitBy=@sby where id=@id";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@sby", submitBy);
			command.Parameters->AddWithValue("@id", id);
			command.ExecuteNonQuery();

			sqlConn.Close();
			this->Close();

			btnSubmit->Text = "Undo Submit";
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->ToString(), "Failed", MessageBoxButtons::OK);
		}
	}
	else if (btnSubmit->Text=="Undo Submit")
	{
		int start;
		String^ newTemp;
		if (start < 0) {
		}
		else {
			start = submitBy->IndexOf(u->email->ToString());
			newTemp = submitBy->Remove(start, u->email->Length);
		}

		try {
			String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQuery = "UPDATE " + code + "Assignment set submitBy=@sby where id=@id";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@sby", newTemp);
			command.Parameters->AddWithValue("@id", id);
			command.ExecuteNonQuery();

			sqlConn.Close();
			this->Close();

			btnSubmit->Text = "Submit";

		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->ToString(), "Failed", MessageBoxButtons::OK);
		}
		
		
	}

	
}
};
}

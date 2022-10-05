#pragma once
#include "User.h"
#include "CreateTeam.h"

namespace eclassroom {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for Dashboard
	/// </summary>
	public ref class Dashboard : public System::Windows::Forms::Form
	{
	public:
		User^ u = nullptr;
		Dashboard(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			u = user;


			String^ codes;
			lvTeams->Items->Clear();

			try {
				String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
				SqlConnection sqlConn(connString);
				sqlConn.Open();
				String^ sqlQuery = "Select teams from users where email=@email";
				SqlCommand command(sqlQuery, % sqlConn);
				command.Parameters->AddWithValue("@email", u->email);
				SqlDataReader^ reader;
				reader = command.ExecuteReader();
				if (reader->Read()) {
					if (reader["teams"]->ToString() == "NULL" || reader["teams"]->ToString() == "") {

					}
					else {
						codes = reader["teams"]->ToString();
						int i = 0, a = 0;

						while (a == 0) {

							String^ tempCode = codes->Substring(i, 6);
							String^ teamName;

							try {
								String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
								SqlConnection sqlConn(connString);
								sqlConn.Open();
								String^ sqlQuery = "Select name from teams where code=@code";
								SqlCommand command(sqlQuery, % sqlConn);
								command.Parameters->AddWithValue("@code", tempCode);
								SqlDataReader^ reader;
								reader = command.ExecuteReader();

								if (reader->Read()) {
									if (reader["name"]->ToString() == "NULL" || reader["name"]->ToString() == "") {
										
									}
									else {
										teamName = reader["name"]->ToString();
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
								MessageBox::Show("Failed to fetch names", "Failed", MessageBoxButtons::OK);
							}

							ListViewItem^ lvi = gcnew ListViewItem(teamName, 0);
							lvTeams->Items->Add(lvi);

							i = i + 6;
							if (i + 6 > codes->Length)
							{
								a = 1;
								break;
							}

						}
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

			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Dashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbWelcome;
	private: System::Windows::Forms::Button^ btnNewTeam;
	protected:



	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ tbTeamCode;

	private: System::Windows::Forms::Label^ label1;



	private: System::Windows::Forms::ListView^ lvTeams;

	private: System::Windows::Forms::Button^ btnJoinTeam;
	private: System::Windows::Forms::Button^ btnRefresh;
	private: System::Windows::Forms::ColumnHeader^ ch_name;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Button^ btnSend;
private: System::Windows::Forms::RichTextBox^ tbMessage;
private: System::Windows::Forms::ListView^ lvMessage;
private: System::Windows::Forms::Label^ lbCode;

private: System::Windows::Forms::Label^ lbTeamName;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Dashboard::typeid));
			this->lbWelcome = (gcnew System::Windows::Forms::Label());
			this->btnNewTeam = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnRefresh = (gcnew System::Windows::Forms::Button());
			this->lvTeams = (gcnew System::Windows::Forms::ListView());
			this->ch_name = (gcnew System::Windows::Forms::ColumnHeader());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->lbCode = (gcnew System::Windows::Forms::Label());
			this->lbTeamName = (gcnew System::Windows::Forms::Label());
			this->lvMessage = (gcnew System::Windows::Forms::ListView());
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->tbMessage = (gcnew System::Windows::Forms::RichTextBox());
			this->btnJoinTeam = (gcnew System::Windows::Forms::Button());
			this->tbTeamCode = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbWelcome
			// 
			this->lbWelcome->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbWelcome->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbWelcome->Location = System::Drawing::Point(9, -3);
			this->lbWelcome->Name = L"lbWelcome";
			this->lbWelcome->Size = System::Drawing::Size(994, 122);
			this->lbWelcome->TabIndex = 0;
			this->lbWelcome->Text = L"Welcome";
			this->lbWelcome->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lbWelcome->Click += gcnew System::EventHandler(this, &Dashboard::label1_Click);
			// 
			// btnNewTeam
			// 
			this->btnNewTeam->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNewTeam->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNewTeam->Location = System::Drawing::Point(373, 210);
			this->btnNewTeam->Name = L"btnNewTeam";
			this->btnNewTeam->Size = System::Drawing::Size(253, 63);
			this->btnNewTeam->TabIndex = 2;
			this->btnNewTeam->Text = L"Create New Team";
			this->btnNewTeam->UseVisualStyleBackColor = true;
			this->btnNewTeam->Click += gcnew System::EventHandler(this, &Dashboard::button1_Click);
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->btnRefresh);
			this->panel1->Controls->Add(this->lvTeams);
			this->panel1->Location = System::Drawing::Point(-6, -2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(264, 670);
			this->panel1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(18, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 29);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Teams";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->Click += gcnew System::EventHandler(this, &Dashboard::label2_Click);
			// 
			// btnRefresh
			// 
			this->btnRefresh->BackColor = System::Drawing::Color::Transparent;
			this->btnRefresh->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRefresh.BackgroundImage")));
			this->btnRefresh->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnRefresh->Location = System::Drawing::Point(228, 11);
			this->btnRefresh->Name = L"btnRefresh";
			this->btnRefresh->Size = System::Drawing::Size(29, 29);
			this->btnRefresh->TabIndex = 2;
			this->btnRefresh->UseVisualStyleBackColor = false;
			this->btnRefresh->Click += gcnew System::EventHandler(this, &Dashboard::btnRefresh_Click);
			// 
			// lvTeams
			// 
			this->lvTeams->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(5)));
			this->lvTeams->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->ch_name });
			this->lvTeams->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lvTeams->ForeColor = System::Drawing::Color::White;
			this->lvTeams->HideSelection = false;
			this->lvTeams->Location = System::Drawing::Point(12, 46);
			this->lvTeams->MultiSelect = false;
			this->lvTeams->Name = L"lvTeams";
			this->lvTeams->Scrollable = false;
			this->lvTeams->Size = System::Drawing::Size(247, 615);
			this->lvTeams->TabIndex = 1;
			this->lvTeams->TileSize = System::Drawing::Size(242, 35);
			this->lvTeams->UseCompatibleStateImageBehavior = false;
			this->lvTeams->View = System::Windows::Forms::View::Tile;
			this->lvTeams->SelectedIndexChanged += gcnew System::EventHandler(this, &Dashboard::lvTeams_SelectedIndexChanged);
			// 
			// ch_name
			// 
			this->ch_name->Text = L"Teams";
			this->ch_name->Width = 242;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->lbCode);
			this->panel2->Controls->Add(this->lbTeamName);
			this->panel2->Controls->Add(this->lbWelcome);
			this->panel2->Controls->Add(this->lvMessage);
			this->panel2->Controls->Add(this->btnSend);
			this->panel2->Controls->Add(this->tbMessage);
			this->panel2->Controls->Add(this->btnJoinTeam);
			this->panel2->Controls->Add(this->tbTeamCode);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->btnNewTeam);
			this->panel2->Location = System::Drawing::Point(255, -2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1014, 670);
			this->panel2->TabIndex = 4;
			// 
			// lbCode
			// 
			this->lbCode->AutoSize = true;
			this->lbCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbCode->Location = System::Drawing::Point(27, 69);
			this->lbCode->Name = L"lbCode";
			this->lbCode->Size = System::Drawing::Size(48, 20);
			this->lbCode->TabIndex = 10;
			this->lbCode->Text = L"Code";
			this->lbCode->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->lbCode->Visible = false;
			// 
			// lbTeamName
			// 
			this->lbTeamName->AutoSize = true;
			this->lbTeamName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbTeamName->Location = System::Drawing::Point(21, 24);
			this->lbTeamName->Name = L"lbTeamName";
			this->lbTeamName->Size = System::Drawing::Size(182, 36);
			this->lbTeamName->TabIndex = 9;
			this->lbTeamName->Text = L"Team Name";
			this->lbTeamName->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->lbTeamName->Visible = false;
			// 
			// lvMessage
			// 
			this->lvMessage->HideSelection = false;
			this->lvMessage->Location = System::Drawing::Point(27, 125);
			this->lvMessage->Name = L"lvMessage";
			this->lvMessage->Size = System::Drawing::Size(852, 459);
			this->lvMessage->TabIndex = 8;
			this->lvMessage->UseCompatibleStateImageBehavior = false;
			this->lvMessage->View = System::Windows::Forms::View::Tile;
			this->lvMessage->Visible = false;
			// 
			// btnSend
			// 
			this->btnSend->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSend->Location = System::Drawing::Point(886, 606);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(109, 47);
			this->btnSend->TabIndex = 7;
			this->btnSend->Text = L"Send";
			this->btnSend->UseVisualStyleBackColor = true;
			this->btnSend->Visible = false;
			this->btnSend->Click += gcnew System::EventHandler(this, &Dashboard::btnSend_Click);
			// 
			// tbMessage
			// 
			this->tbMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbMessage->Location = System::Drawing::Point(27, 606);
			this->tbMessage->Name = L"tbMessage";
			this->tbMessage->Size = System::Drawing::Size(852, 47);
			this->tbMessage->TabIndex = 6;
			this->tbMessage->Text = L"";
			this->tbMessage->Visible = false;
			// 
			// btnJoinTeam
			// 
			this->btnJoinTeam->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJoinTeam->Location = System::Drawing::Point(447, 426);
			this->btnJoinTeam->Name = L"btnJoinTeam";
			this->btnJoinTeam->Size = System::Drawing::Size(109, 42);
			this->btnJoinTeam->TabIndex = 5;
			this->btnJoinTeam->Text = L"Join";
			this->btnJoinTeam->UseVisualStyleBackColor = true;
			this->btnJoinTeam->Click += gcnew System::EventHandler(this, &Dashboard::btnJoinTeam_Click);
			// 
			// tbTeamCode
			// 
			this->tbTeamCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbTeamCode->Location = System::Drawing::Point(373, 361);
			this->tbTeamCode->Name = L"tbTeamCode";
			this->tbTeamCode->Size = System::Drawing::Size(253, 34);
			this->tbTeamCode->TabIndex = 4;
			this->tbTeamCode->Text = L"Enter Team Code";
			this->tbTeamCode->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(475, 308);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 29);
			this->label1->TabIndex = 3;
			this->label1->Text = L"OR";
			// 
			// Dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1262, 663);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Name = L"Dashboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dashboard";
			this->Load += gcnew System::EventHandler(this, &Dashboard::Dashboard_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Dashboard_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		eclassroom::CreateTeam createTeam(u);
		createTeam.ShowDialog();
	}
	private: System::Void btnJoinTeam_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ teamCode = tbTeamCode->Text;
		if (teamCode->Length == 0) {
			MessageBox::Show("Please enter the team code!", "Enter Code", MessageBoxButtons::OK);
			return;
		}

		String^ tempCode;

		try {
			String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			//String^ sqlQuery = "INSERT INTO "+ teamCode + " (users)VALUES " + "(@users);";
			//SqlCommand command(sqlQuery, % sqlConn);
			//command.Parameters->AddWithValue("@users", u->email);
			//command.ExecuteNonQuery();

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
				command.Parameters->AddWithValue("@teams", tempCode + teamCode);
				command.Parameters->AddWithValue("@email", u->email);
				command.ExecuteNonQuery();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Failed to update data", "Failed", MessageBoxButtons::OK);
			}
			MessageBox::Show("Team Joined!", "Successful", MessageBoxButtons::OK);
			tbTeamCode->Clear();
			sqlConn.Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Failed to join the team", "Failed", MessageBoxButtons::OK);
		}
	}

private: System::Void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e) {
	
	
	String^ codes;
	lvTeams->Items->Clear();

	try {
		String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
		SqlConnection sqlConn(connString);
		sqlConn.Open();
		String^ sqlQuery = "Select teams from users where email=@email";
		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@email", u->email);
		SqlDataReader^ reader;
		reader = command.ExecuteReader();
		if (reader->Read()) {
			if (reader["teams"]->ToString() == "NULL" || reader["teams"]->ToString() == "") {
				
			}
			else {
				codes = reader["teams"]->ToString();
				int i = 0, a = 0;

				while (a == 0) {

					String^ tempCode = codes->Substring(i, 6);
					String^ teamName;

					try {
						String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
						SqlConnection sqlConn(connString);
						sqlConn.Open();
						String^ sqlQuery = "Select name from teams where code=@code";
						SqlCommand command(sqlQuery, % sqlConn);
						command.Parameters->AddWithValue("@code", tempCode);
						SqlDataReader^ reader;
						reader = command.ExecuteReader();

						if (reader->Read()) {
							if (reader["name"]->ToString() == "NULL" || reader["name"]->ToString() == "") {

							}
							else {
								teamName = reader["name"]->ToString();
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
						MessageBox::Show("Failed to fetch names", "Failed", MessageBoxButtons::OK);
					}

					ListViewItem^ lvi = gcnew ListViewItem(teamName, 0);
					lvTeams->Items->Add(lvi);

					i = i + 6;
					if (i + 6 > codes->Length)
					{
						a = 1;
						break;
					}
				}
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

	
		
}
	   public: String^ tempCode;

private: System::Void lvTeams_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (lvTeams->SelectedItems->Count==1)
	{
		tbMessage->Clear();
		
		String^ indexValue = lvTeams->SelectedIndices[0].ToString();
		int index = Int64::Parse(indexValue);

		String^ codes;

		try {
			String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();
			String^ sqlQuery = "Select teams from users where email=@email";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@email", u->email);
			SqlDataReader^ reader;
			reader = command.ExecuteReader();
			if (reader->Read()) {
				if (reader["teams"]->ToString() == "NULL" || reader["teams"]->ToString() == "") {

				}
				else {
					codes = reader["teams"]->ToString();
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

		tempCode = codes->Substring(index*6, 6);

		String^ teamName;

		try {
			String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();
			String^ sqlQuery = "Select name from teams where code=@code";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@code", tempCode);
			SqlDataReader^ reader;
			reader = command.ExecuteReader();

			if (reader->Read()) {
				if (reader["name"]->ToString() == "NULL" || reader["name"]->ToString() == "") {

				}
				else {
					teamName = reader["name"]->ToString();
				}
			}
			else
			{
				MessageBox::Show("No data", "Failed", MessageBoxButtons::OK);
			}
			reader->Close();
			sqlConn.Close();

		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Failed to fetch names", "Failed", MessageBoxButtons::OK);
		}

		lbTeamName->Text = teamName;
		lbCode->Text = "Code: "+tempCode;

		lbWelcome->Visible = false;
		btnNewTeam->Visible = false;
		btnJoinTeam->Visible = false;
		label1->Visible = false;
		tbTeamCode->Visible = false;
		tbMessage->Visible = true;
		btnSend->Visible = true;
		lvMessage->Visible = true;
		lbTeamName->Visible = true;
		lbCode->Visible = true;


	}
	
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	lbWelcome->Visible = true;
	btnNewTeam->Visible = true;
	btnJoinTeam->Visible = true;
	label1->Visible = true;
	tbTeamCode->Visible = true;
	tbMessage->Visible = false;
	btnSend->Visible = false;
	lvMessage->Visible = false;
	lbTeamName->Visible = false;
	lbCode->Visible = false;
}
private: System::Void btnSend_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ message = tbMessage->Text;
	

	if (message->Length==NULL) {
	}
	else {
		try {
			String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();
			String^ sqlQuery = "INSERT INTO " + tempCode + "Message (messages) VALUES " + "(@messages);";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@messages", message);
			command.ExecuteNonQuery();
			tbMessage->Clear();
			sqlConn.Close();

		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Failed to send message", "Failed", MessageBoxButtons::OK);
		}
	}

	
}
};
}

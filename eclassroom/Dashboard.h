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
		Dashboard(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			lbWelcome->Text = "Welcome " + user->name;
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
	protected:


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ListView^ listView1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
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
			this->lbWelcome->Location = System::Drawing::Point(264, -2);
			this->lbWelcome->Name = L"lbWelcome";
			this->lbWelcome->Size = System::Drawing::Size(994, 122);
			this->lbWelcome->TabIndex = 0;
			this->lbWelcome->Text = L"Welcome";
			this->lbWelcome->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lbWelcome->Click += gcnew System::EventHandler(this, &Dashboard::label1_Click);
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(373, 210);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(253, 63);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Create New Team";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Dashboard::button1_Click);
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->listView1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(-6, -2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(264, 670);
			this->panel1->TabIndex = 3;
			// 
			// listView1
			// 
			this->listView1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(19, 44);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(236, 609);
			this->listView1->TabIndex = 1;
			this->listView1->UseCompatibleStateImageBehavior = false;
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
			this->label2->TabIndex = 0;
			this->label2->Text = L"Teams";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Location = System::Drawing::Point(255, -2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1014, 670);
			this->panel2->TabIndex = 4;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(373, 361);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(253, 34);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"Enter Team Code";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			// button2
			// 
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(444, 414);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(108, 44);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Join";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Dashboard::button1_Click);
			// 
			// Dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1262, 663);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->lbWelcome);
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

		eclassroom::CreateTeam createTeam;
		createTeam.ShowDialog();
	}
	};
}

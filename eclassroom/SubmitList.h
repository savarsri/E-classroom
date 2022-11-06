#pragma once
#include "User.h"
#include <string>
#include <iostream>


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
	/// Summary for SubmitList
	/// </summary>
	public ref class SubmitList : public System::Windows::Forms::Form
	{
	public:
		String^ code;
		int id;
		String^ submitBy;
		int len;
		int num;
		int* sby = (int*)malloc(num * sizeof(int));

	public: void bubbleSort(int arr[], int n)
	{
		int i, j;
		bool swapped;
		for (i = 0; i < n - 1; i++)
		{
			swapped = false;
			for (j = 0; j < n - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap(arr[j], arr[j + 1]);
					swapped = true;
				}
			}

			if (swapped == false)
				break;
		}
	}

		SubmitList(String^ teamCode, int x)
		{
			InitializeComponent();
			code = teamCode;
			id = x;

			try {
				String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
				SqlConnection sqlConn(connString);
				sqlConn.Open();

				String^ sqlQuery = "Select submitBy from " + code + "Assignment where id=@id";
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

			len = submitBy->Length;
			num = len / 4;
			if (len == 0) {

			}
			else {

				int i = 0, j = 0;
				while (i < len) {
					String^ temp = submitBy->Substring(i, 4);
					int tempPrn = Int64::Parse(temp);
					sby[j] = tempPrn;
					i = i + 4;
					j++;
				}

			}
			bubbleSort(sby, num);

				lvSby->Clear();
				String^ connString = "Data Source=localhost\\DurgaSQL;Initial Catalog=eclassroom;Integrated Security=True";
				SqlConnection^ sqlConn = gcnew SqlConnection(connString);
				sqlConn->Open();

				lvSby->Columns->Add("PRN",150);
				int i;
				for (i = 0; i < num; i++) {
					lvSby->Items->Add(sby[i].ToString());
					
				}
			

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SubmitList()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^ lvSby;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SubmitList::typeid));
			this->lvSby = (gcnew System::Windows::Forms::ListView());
			this->SuspendLayout();
			// 
			// lvSby
			// 
			this->lvSby->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lvSby->HideSelection = false;
			this->lvSby->Location = System::Drawing::Point(48, 28);
			this->lvSby->Name = L"lvSby";
			this->lvSby->Size = System::Drawing::Size(233, 499);
			this->lvSby->TabIndex = 0;
			this->lvSby->UseCompatibleStateImageBehavior = false;
			this->lvSby->View = System::Windows::Forms::View::Details;
			// 
			// SubmitList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(201)), static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(101)));
			this->ClientSize = System::Drawing::Size(335, 561);
			this->Controls->Add(this->lvSby);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"SubmitList";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SubmitList";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

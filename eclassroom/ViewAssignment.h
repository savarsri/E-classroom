#pragma once

namespace eclassroom {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ViewAssignment1
	/// </summary>
	public ref class ViewAssignment1 : public System::Windows::Forms::Form
	{
	public:
		int id;
		ViewAssignment1()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ViewAssignment1()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// ViewAssignment1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(934, 658);
			this->Name = L"ViewAssignment1";
			this->Text = L"Assignment";
			this->Load += gcnew System::EventHandler(this, &ViewAssignment1::ViewAssignment1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ViewAssignment1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}

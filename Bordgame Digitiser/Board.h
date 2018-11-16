#pragma once

namespace BordgameDigitiser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Board
	/// </summary>
	public ref class Board : public System::Windows::Forms::Form
	{
	public:
		Board(void)
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
		~Board()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::VScrollBar^  vScrollBar1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Panel^  panel3;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->vScrollBar1 = (gcnew System::Windows::Forms::VScrollBar());
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(21, 23);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(960, 960);
			this->panel1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->vScrollBar1);
			this->panel2->Controls->Add(this->richTextBox1);
			this->panel2->Location = System::Drawing::Point(1012, 23);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(789, 1281);
			this->panel2->TabIndex = 1;
			// 
			// panel3
			// 
			this->panel3->Location = System::Drawing::Point(21, 1008);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(959, 295);
			this->panel3->TabIndex = 2;
			// 
			// richTextBox1
			// 
			this->richTextBox1->AccessibleName = L"gameLog";
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(789, 1280);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// vScrollBar1
			// 
			this->vScrollBar1->Location = System::Drawing::Point(755, 0);
			this->vScrollBar1->Name = L"vScrollBar1";
			this->vScrollBar1->Size = System::Drawing::Size(34, 1280);
			this->vScrollBar1->TabIndex = 1;
			// 
			// Board
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1825, 1332);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"Board";
			this->Text = L"Board";
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

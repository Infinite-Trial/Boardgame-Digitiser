#pragma once


#include <iostream>
#include <ctype.h>
namespace BordgameDigitiser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for Board
	/// </summary>
	public ref class Board : public System::Windows::Forms::Form
	{
	public:
		Board(void)
		{
			InitializeComponent();
			//vector <string> gameLogText;
			// string gameLogText[200];
			//std::string iCallBullshit;
			for (int i = 0; i < 200; i++) {
				gameLog->Items->Add(i);
			}
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





	private: System::Windows::Forms::Panel^  panel3;

	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::ListBox^  gameLog;
	private: System::Windows::Forms::Panel^  panel2;







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
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->gameLog = (gcnew System::Windows::Forms::ListBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
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
			// panel3
			// 
			this->panel3->Location = System::Drawing::Point(21, 1008);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(959, 295);
			this->panel3->TabIndex = 2;
			// 
			// gameLog
			// 
			this->gameLog->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gameLog->FormattingEnabled = true;
			this->gameLog->ItemHeight = 31;
			this->gameLog->Location = System::Drawing::Point(0, 0);
			this->gameLog->Name = L"gameLog";
			this->gameLog->ScrollAlwaysVisible = true;
			this->gameLog->Size = System::Drawing::Size(789, 1275);
			this->gameLog->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->gameLog);
			this->panel2->Location = System::Drawing::Point(1012, 22);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(789, 1281);
			this->panel2->TabIndex = 1;
			// 
			// Board
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1825, 1343);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(6);
			this->MinimumSize = System::Drawing::Size(1851, 1414);
			this->Name = L"Board";
			this->Padding = System::Windows::Forms::Padding(20);
			this->Text = L"Board";
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

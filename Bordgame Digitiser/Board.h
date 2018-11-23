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

	private: System::Windows::Forms::PictureBox^  pictureBox1;









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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Board::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->gameLog = (gcnew System::Windows::Forms::ListBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(20, 20);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1920, 1920);
			this->panel1->TabIndex = 0;
			// 
			// panel3
			// 
			this->panel3->Location = System::Drawing::Point(1980, 1490);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1240, 450);
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
			this->gameLog->Size = System::Drawing::Size(1240, 1430);
			this->gameLog->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->gameLog);
			this->panel2->Location = System::Drawing::Point(1980, 20);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1240, 1430);
			this->panel2->TabIndex = 1;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(240, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(240, 240);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// Board
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(2574, 2089);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(6);
			this->MinimumSize = System::Drawing::Size(1851, 1414);
			this->Name = L"Board";
			this->Padding = System::Windows::Forms::Padding(20);
			this->Text = L"Board";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

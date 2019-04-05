#pragma once


#include "UIBoard.h"

namespace BordgameDigitiser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for UIMenu
	/// </summary> Syst
	public ref class UIMenu : public System::Windows::Forms::Form

	{
	public:
		UIMenu(void)
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
		~UIMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  startButton;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  debugModeButton;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Button^  button2;

	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UIMenu::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->debugModeButton = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->startButton);
			this->panel1->Location = System::Drawing::Point(2340, 1650);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(800, 250);
			this->panel1->TabIndex = 0;
			// 
			// startButton
			// 
			this->startButton->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->startButton->Location = System::Drawing::Point(0, 0);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(800, 250);
			this->startButton->TabIndex = 1;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &UIMenu::startButton_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->debugModeButton);
			this->panel2->Location = System::Drawing::Point(100, 1650);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(800, 250);
			this->panel2->TabIndex = 2;
			// 
			// debugModeButton
			// 
			this->debugModeButton->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->debugModeButton->Location = System::Drawing::Point(0, 0);
			this->debugModeButton->Name = L"debugModeButton";
			this->debugModeButton->Size = System::Drawing::Size(800, 250);
			this->debugModeButton->TabIndex = 1;
			this->debugModeButton->Text = L"Debug-Mode";
			this->debugModeButton->UseVisualStyleBackColor = true;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->button1);
			this->panel3->Location = System::Drawing::Point(100, 1350);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(250, 250);
			this->panel3->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(250, 250);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = true;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->button2);
			this->panel4->Location = System::Drawing::Point(2890, 1350);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(250, 250);
			this->panel4->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(0, 0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(250, 250);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &UIMenu::button2_Click);
			// 
			// UIMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(3214, 1989);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->MaximumSize = System::Drawing::Size(3240, 2060);
			this->MinimumSize = System::Drawing::Size(3238, 2060);
			this->Name = L"UIMenu";
			this->Padding = System::Windows::Forms::Padding(20);
			this->Text = L"Menu";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void startButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
		//BordgameDigitiser::UIBoard^ formBoard = gcnew UIBoard;
		//formBoard->Show();
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	};
}


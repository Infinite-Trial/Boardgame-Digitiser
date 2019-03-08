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
	private: System::Windows::Forms::Panel^  chessBoardPanel;
	protected:

	private: System::Windows::Forms::Panel^  buttonPanel;
	protected:

	protected:







	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::ListBox^  gameLog;
	private: System::Windows::Forms::Panel^  gameLogPanel;

	private: System::Windows::Forms::PictureBox^  blackKnight1;

	private: System::Windows::Forms::PictureBox^  blackRook1;
	private: System::Windows::Forms::PictureBox^  blackPawn5;
	private: System::Windows::Forms::PictureBox^  blackPawn6;
	private: System::Windows::Forms::PictureBox^  blackPawn7;
	private: System::Windows::Forms::PictureBox^  blackPawn8;








	private: System::Windows::Forms::PictureBox^  blackBishop1;

	private: System::Windows::Forms::PictureBox^  blackQueen;
	private: System::Windows::Forms::PictureBox^  blackKing;
	private: System::Windows::Forms::PictureBox^  blackBishop2;
	private: System::Windows::Forms::PictureBox^  blackKnight2;
	private: System::Windows::Forms::PictureBox^  blackRook2;
	private: System::Windows::Forms::PictureBox^  blackPawn1;
	private: System::Windows::Forms::PictureBox^  blackPawn2;
	private: System::Windows::Forms::PictureBox^  blackPawn3;
	private: System::Windows::Forms::PictureBox^  blackPawn4;
	private: System::Windows::Forms::PictureBox^  whitePawn5;
	private: System::Windows::Forms::PictureBox^  whitePawn6;
	private: System::Windows::Forms::PictureBox^  whitePawn7;
	private: System::Windows::Forms::PictureBox^  whitePawn8;
	private: System::Windows::Forms::PictureBox^  whiteBishop1;
	private: System::Windows::Forms::PictureBox^  whiteQueen;
	private: System::Windows::Forms::PictureBox^  whiteKing;
	private: System::Windows::Forms::PictureBox^  whiteBishop2;
	private: System::Windows::Forms::PictureBox^  whiteKnight2;
	private: System::Windows::Forms::PictureBox^  whiteRook2;




















	private: System::Windows::Forms::PictureBox^  whitePawn1;
	private: System::Windows::Forms::PictureBox^  whitePawn2;
	private: System::Windows::Forms::PictureBox^  whitePawn3;
	private: System::Windows::Forms::PictureBox^  whitePawn4;
	private: System::Windows::Forms::PictureBox^  whiteRook1;
	private: System::Windows::Forms::PictureBox^  whiteKnight1;
private: System::Windows::Forms::Button^  nächsterZugButton;

private: System::Windows::Forms::Button^  zurückButton;


private: System::Windows::Forms::Panel^  panel1;















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
			this->chessBoardPanel = (gcnew System::Windows::Forms::Panel());
			this->whitePawn1 = (gcnew System::Windows::Forms::PictureBox());
			this->whitePawn2 = (gcnew System::Windows::Forms::PictureBox());
			this->whitePawn3 = (gcnew System::Windows::Forms::PictureBox());
			this->whitePawn4 = (gcnew System::Windows::Forms::PictureBox());
			this->whitePawn5 = (gcnew System::Windows::Forms::PictureBox());
			this->whitePawn6 = (gcnew System::Windows::Forms::PictureBox());
			this->whitePawn7 = (gcnew System::Windows::Forms::PictureBox());
			this->whitePawn8 = (gcnew System::Windows::Forms::PictureBox());
			this->whiteRook1 = (gcnew System::Windows::Forms::PictureBox());
			this->whiteRook2 = (gcnew System::Windows::Forms::PictureBox());
			this->whiteBishop1 = (gcnew System::Windows::Forms::PictureBox());
			this->whiteBishop2 = (gcnew System::Windows::Forms::PictureBox());
			this->whiteKnight1 = (gcnew System::Windows::Forms::PictureBox());
			this->whiteKnight2 = (gcnew System::Windows::Forms::PictureBox());
			this->whiteQueen = (gcnew System::Windows::Forms::PictureBox());
			this->whiteKing = (gcnew System::Windows::Forms::PictureBox());
			this->blackPawn1 = (gcnew System::Windows::Forms::PictureBox());
			this->blackPawn2 = (gcnew System::Windows::Forms::PictureBox());
			this->blackPawn3 = (gcnew System::Windows::Forms::PictureBox());
			this->blackPawn4 = (gcnew System::Windows::Forms::PictureBox());
			this->blackPawn5 = (gcnew System::Windows::Forms::PictureBox());
			this->blackPawn6 = (gcnew System::Windows::Forms::PictureBox());
			this->blackPawn7 = (gcnew System::Windows::Forms::PictureBox());
			this->blackPawn8 = (gcnew System::Windows::Forms::PictureBox());
			this->blackRook1 = (gcnew System::Windows::Forms::PictureBox());
			this->blackRook2 = (gcnew System::Windows::Forms::PictureBox());
			this->blackKnight1 = (gcnew System::Windows::Forms::PictureBox());
			this->blackKnight2 = (gcnew System::Windows::Forms::PictureBox());
			this->blackBishop1 = (gcnew System::Windows::Forms::PictureBox());
			this->blackBishop2 = (gcnew System::Windows::Forms::PictureBox());
			this->blackQueen = (gcnew System::Windows::Forms::PictureBox());
			this->blackKing = (gcnew System::Windows::Forms::PictureBox());
			this->buttonPanel = (gcnew System::Windows::Forms::Panel());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->gameLog = (gcnew System::Windows::Forms::ListBox());
			this->gameLogPanel = (gcnew System::Windows::Forms::Panel());
			this->nächsterZugButton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->zurückButton = (gcnew System::Windows::Forms::Button());
			this->chessBoardPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteRook1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteRook2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteBishop1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteBishop2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteKnight1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteKnight2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteQueen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteKing))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackRook1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackRook2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackKnight1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackKnight2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackBishop1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackBishop2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackQueen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackKing))->BeginInit();
			this->buttonPanel->SuspendLayout();
			this->gameLogPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// chessBoardPanel
			// 
			this->chessBoardPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"chessBoardPanel.BackgroundImage")));
			this->chessBoardPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->chessBoardPanel->Controls->Add(this->whitePawn1);
			this->chessBoardPanel->Controls->Add(this->whitePawn2);
			this->chessBoardPanel->Controls->Add(this->whitePawn3);
			this->chessBoardPanel->Controls->Add(this->whitePawn4);
			this->chessBoardPanel->Controls->Add(this->whitePawn5);
			this->chessBoardPanel->Controls->Add(this->whitePawn6);
			this->chessBoardPanel->Controls->Add(this->whitePawn7);
			this->chessBoardPanel->Controls->Add(this->whitePawn8);
			this->chessBoardPanel->Controls->Add(this->whiteRook1);
			this->chessBoardPanel->Controls->Add(this->whiteRook2);
			this->chessBoardPanel->Controls->Add(this->whiteBishop1);
			this->chessBoardPanel->Controls->Add(this->whiteBishop2);
			this->chessBoardPanel->Controls->Add(this->whiteKnight1);
			this->chessBoardPanel->Controls->Add(this->whiteKnight2);
			this->chessBoardPanel->Controls->Add(this->whiteQueen);
			this->chessBoardPanel->Controls->Add(this->whiteKing);
			this->chessBoardPanel->Controls->Add(this->blackPawn1);
			this->chessBoardPanel->Controls->Add(this->blackPawn2);
			this->chessBoardPanel->Controls->Add(this->blackPawn3);
			this->chessBoardPanel->Controls->Add(this->blackPawn4);
			this->chessBoardPanel->Controls->Add(this->blackPawn5);
			this->chessBoardPanel->Controls->Add(this->blackPawn6);
			this->chessBoardPanel->Controls->Add(this->blackPawn7);
			this->chessBoardPanel->Controls->Add(this->blackPawn8);
			this->chessBoardPanel->Controls->Add(this->blackRook1);
			this->chessBoardPanel->Controls->Add(this->blackRook2);
			this->chessBoardPanel->Controls->Add(this->blackKnight1);
			this->chessBoardPanel->Controls->Add(this->blackKnight2);
			this->chessBoardPanel->Controls->Add(this->blackBishop1);
			this->chessBoardPanel->Controls->Add(this->blackBishop2);
			this->chessBoardPanel->Controls->Add(this->blackQueen);
			this->chessBoardPanel->Controls->Add(this->blackKing);
			this->chessBoardPanel->Location = System::Drawing::Point(20, 20);
			this->chessBoardPanel->Name = L"chessBoardPanel";
			this->chessBoardPanel->Size = System::Drawing::Size(1920, 1920);
			this->chessBoardPanel->TabIndex = 0;
			// 
			// whitePawn1
			// 
			this->whitePawn1->BackColor = System::Drawing::Color::Transparent;
			this->whitePawn1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whitePawn1.BackgroundImage")));
			this->whitePawn1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whitePawn1->Location = System::Drawing::Point(0, 1440);
			this->whitePawn1->Name = L"whitePawn1";
			this->whitePawn1->Size = System::Drawing::Size(240, 240);
			this->whitePawn1->TabIndex = 1;
			this->whitePawn1->TabStop = false;
			this->whitePawn1->Click += gcnew System::EventHandler(this, &Board::pictureBox27_Click);
			// 
			// whitePawn2
			// 
			this->whitePawn2->BackColor = System::Drawing::Color::Transparent;
			this->whitePawn2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whitePawn2.BackgroundImage")));
			this->whitePawn2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whitePawn2->Location = System::Drawing::Point(240, 1440);
			this->whitePawn2->Name = L"whitePawn2";
			this->whitePawn2->Size = System::Drawing::Size(240, 240);
			this->whitePawn2->TabIndex = 2;
			this->whitePawn2->TabStop = false;
			this->whitePawn2->Click += gcnew System::EventHandler(this, &Board::pictureBox28_Click);
			// 
			// whitePawn3
			// 
			this->whitePawn3->BackColor = System::Drawing::Color::Transparent;
			this->whitePawn3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whitePawn3.BackgroundImage")));
			this->whitePawn3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whitePawn3->Location = System::Drawing::Point(480, 1440);
			this->whitePawn3->Name = L"whitePawn3";
			this->whitePawn3->Size = System::Drawing::Size(240, 240);
			this->whitePawn3->TabIndex = 3;
			this->whitePawn3->TabStop = false;
			this->whitePawn3->Click += gcnew System::EventHandler(this, &Board::pictureBox29_Click);
			// 
			// whitePawn4
			// 
			this->whitePawn4->BackColor = System::Drawing::Color::Transparent;
			this->whitePawn4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whitePawn4.BackgroundImage")));
			this->whitePawn4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whitePawn4->Location = System::Drawing::Point(720, 1440);
			this->whitePawn4->Name = L"whitePawn4";
			this->whitePawn4->Size = System::Drawing::Size(240, 240);
			this->whitePawn4->TabIndex = 4;
			this->whitePawn4->TabStop = false;
			this->whitePawn4->Click += gcnew System::EventHandler(this, &Board::pictureBox30_Click);
			// 
			// whitePawn5
			// 
			this->whitePawn5->BackColor = System::Drawing::Color::Transparent;
			this->whitePawn5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whitePawn5.BackgroundImage")));
			this->whitePawn5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whitePawn5->Location = System::Drawing::Point(960, 1440);
			this->whitePawn5->Name = L"whitePawn5";
			this->whitePawn5->Size = System::Drawing::Size(240, 240);
			this->whitePawn5->TabIndex = 5;
			this->whitePawn5->TabStop = false;
			this->whitePawn5->Click += gcnew System::EventHandler(this, &Board::pictureBox17_Click);
			// 
			// whitePawn6
			// 
			this->whitePawn6->BackColor = System::Drawing::Color::Transparent;
			this->whitePawn6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whitePawn6.BackgroundImage")));
			this->whitePawn6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whitePawn6->Location = System::Drawing::Point(1200, 1440);
			this->whitePawn6->Name = L"whitePawn6";
			this->whitePawn6->Size = System::Drawing::Size(240, 240);
			this->whitePawn6->TabIndex = 6;
			this->whitePawn6->TabStop = false;
			this->whitePawn6->Click += gcnew System::EventHandler(this, &Board::pictureBox18_Click);
			// 
			// whitePawn7
			// 
			this->whitePawn7->BackColor = System::Drawing::Color::Transparent;
			this->whitePawn7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whitePawn7.BackgroundImage")));
			this->whitePawn7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whitePawn7->Location = System::Drawing::Point(1440, 1440);
			this->whitePawn7->Name = L"whitePawn7";
			this->whitePawn7->Size = System::Drawing::Size(240, 240);
			this->whitePawn7->TabIndex = 7;
			this->whitePawn7->TabStop = false;
			this->whitePawn7->Click += gcnew System::EventHandler(this, &Board::pictureBox19_Click);
			// 
			// whitePawn8
			// 
			this->whitePawn8->BackColor = System::Drawing::Color::Transparent;
			this->whitePawn8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whitePawn8.BackgroundImage")));
			this->whitePawn8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whitePawn8->Location = System::Drawing::Point(1680, 1440);
			this->whitePawn8->Name = L"whitePawn8";
			this->whitePawn8->Size = System::Drawing::Size(240, 240);
			this->whitePawn8->TabIndex = 8;
			this->whitePawn8->TabStop = false;
			this->whitePawn8->Click += gcnew System::EventHandler(this, &Board::pictureBox20_Click);
			// 
			// whiteRook1
			// 
			this->whiteRook1->BackColor = System::Drawing::Color::Transparent;
			this->whiteRook1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whiteRook1.BackgroundImage")));
			this->whiteRook1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whiteRook1->Location = System::Drawing::Point(0, 1680);
			this->whiteRook1->Name = L"whiteRook1";
			this->whiteRook1->Size = System::Drawing::Size(240, 240);
			this->whiteRook1->TabIndex = 9;
			this->whiteRook1->TabStop = false;
			// 
			// whiteRook2
			// 
			this->whiteRook2->BackColor = System::Drawing::Color::Transparent;
			this->whiteRook2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whiteRook2.BackgroundImage")));
			this->whiteRook2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whiteRook2->Location = System::Drawing::Point(1680, 1680);
			this->whiteRook2->Name = L"whiteRook2";
			this->whiteRook2->Size = System::Drawing::Size(240, 240);
			this->whiteRook2->TabIndex = 10;
			this->whiteRook2->TabStop = false;
			// 
			// whiteBishop1
			// 
			this->whiteBishop1->BackColor = System::Drawing::Color::Transparent;
			this->whiteBishop1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whiteBishop1.BackgroundImage")));
			this->whiteBishop1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whiteBishop1->Location = System::Drawing::Point(480, 1680);
			this->whiteBishop1->Name = L"whiteBishop1";
			this->whiteBishop1->Size = System::Drawing::Size(240, 240);
			this->whiteBishop1->TabIndex = 11;
			this->whiteBishop1->TabStop = false;
			// 
			// whiteBishop2
			// 
			this->whiteBishop2->BackColor = System::Drawing::Color::Transparent;
			this->whiteBishop2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whiteBishop2.BackgroundImage")));
			this->whiteBishop2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whiteBishop2->Location = System::Drawing::Point(1200, 1680);
			this->whiteBishop2->Name = L"whiteBishop2";
			this->whiteBishop2->Size = System::Drawing::Size(240, 240);
			this->whiteBishop2->TabIndex = 12;
			this->whiteBishop2->TabStop = false;
			// 
			// whiteKnight1
			// 
			this->whiteKnight1->BackColor = System::Drawing::Color::Transparent;
			this->whiteKnight1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whiteKnight1.BackgroundImage")));
			this->whiteKnight1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whiteKnight1->Location = System::Drawing::Point(240, 1680);
			this->whiteKnight1->Name = L"whiteKnight1";
			this->whiteKnight1->Size = System::Drawing::Size(240, 240);
			this->whiteKnight1->TabIndex = 13;
			this->whiteKnight1->TabStop = false;
			// 
			// whiteKnight2
			// 
			this->whiteKnight2->BackColor = System::Drawing::Color::Transparent;
			this->whiteKnight2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whiteKnight2.BackgroundImage")));
			this->whiteKnight2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whiteKnight2->Location = System::Drawing::Point(1440, 1680);
			this->whiteKnight2->Name = L"whiteKnight2";
			this->whiteKnight2->Size = System::Drawing::Size(240, 240);
			this->whiteKnight2->TabIndex = 14;
			this->whiteKnight2->TabStop = false;
			// 
			// whiteQueen
			// 
			this->whiteQueen->BackColor = System::Drawing::Color::Transparent;
			this->whiteQueen->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whiteQueen.BackgroundImage")));
			this->whiteQueen->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whiteQueen->Location = System::Drawing::Point(720, 1680);
			this->whiteQueen->Name = L"whiteQueen";
			this->whiteQueen->Size = System::Drawing::Size(240, 240);
			this->whiteQueen->TabIndex = 15;
			this->whiteQueen->TabStop = false;
			// 
			// whiteKing
			// 
			this->whiteKing->BackColor = System::Drawing::Color::Transparent;
			this->whiteKing->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whiteKing.BackgroundImage")));
			this->whiteKing->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whiteKing->Location = System::Drawing::Point(960, 1680);
			this->whiteKing->Name = L"whiteKing";
			this->whiteKing->Size = System::Drawing::Size(240, 240);
			this->whiteKing->TabIndex = 16;
			this->whiteKing->TabStop = false;
			// 
			// blackPawn1
			// 
			this->blackPawn1->BackColor = System::Drawing::Color::Transparent;
			this->blackPawn1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blackPawn1.BackgroundImage")));
			this->blackPawn1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->blackPawn1->Location = System::Drawing::Point(0, 240);
			this->blackPawn1->Name = L"blackPawn1";
			this->blackPawn1->Size = System::Drawing::Size(240, 240);
			this->blackPawn1->TabIndex = 17;
			this->blackPawn1->TabStop = false;
			// 
			// blackPawn2
			// 
			this->blackPawn2->BackColor = System::Drawing::Color::Transparent;
			this->blackPawn2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blackPawn2.BackgroundImage")));
			this->blackPawn2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->blackPawn2->Location = System::Drawing::Point(240, 240);
			this->blackPawn2->Name = L"blackPawn2";
			this->blackPawn2->Size = System::Drawing::Size(240, 240);
			this->blackPawn2->TabIndex = 18;
			this->blackPawn2->TabStop = false;
			// 
			// blackPawn3
			// 
			this->blackPawn3->BackColor = System::Drawing::Color::Transparent;
			this->blackPawn3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blackPawn3.BackgroundImage")));
			this->blackPawn3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->blackPawn3->Location = System::Drawing::Point(480, 240);
			this->blackPawn3->Name = L"blackPawn3";
			this->blackPawn3->Size = System::Drawing::Size(240, 240);
			this->blackPawn3->TabIndex = 19;
			this->blackPawn3->TabStop = false;
			// 
			// blackPawn4
			// 
			this->blackPawn4->BackColor = System::Drawing::Color::Transparent;
			this->blackPawn4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blackPawn4.BackgroundImage")));
			this->blackPawn4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->blackPawn4->Location = System::Drawing::Point(720, 240);
			this->blackPawn4->Name = L"blackPawn4";
			this->blackPawn4->Size = System::Drawing::Size(240, 240);
			this->blackPawn4->TabIndex = 20;
			this->blackPawn4->TabStop = false;
			// 
			// blackPawn5
			// 
			this->blackPawn5->BackColor = System::Drawing::Color::Transparent;
			this->blackPawn5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blackPawn5.BackgroundImage")));
			this->blackPawn5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->blackPawn5->Location = System::Drawing::Point(960, 240);
			this->blackPawn5->Name = L"blackPawn5";
			this->blackPawn5->Size = System::Drawing::Size(240, 240);
			this->blackPawn5->TabIndex = 21;
			this->blackPawn5->TabStop = false;
			// 
			// blackPawn6
			// 
			this->blackPawn6->BackColor = System::Drawing::Color::Transparent;
			this->blackPawn6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blackPawn6.BackgroundImage")));
			this->blackPawn6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->blackPawn6->Location = System::Drawing::Point(1200, 240);
			this->blackPawn6->Name = L"blackPawn6";
			this->blackPawn6->Size = System::Drawing::Size(240, 240);
			this->blackPawn6->TabIndex = 22;
			this->blackPawn6->TabStop = false;
			// 
			// blackPawn7
			// 
			this->blackPawn7->BackColor = System::Drawing::Color::Transparent;
			this->blackPawn7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blackPawn7.BackgroundImage")));
			this->blackPawn7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->blackPawn7->Location = System::Drawing::Point(1440, 240);
			this->blackPawn7->Name = L"blackPawn7";
			this->blackPawn7->Size = System::Drawing::Size(240, 240);
			this->blackPawn7->TabIndex = 23;
			this->blackPawn7->TabStop = false;
			this->blackPawn7->Click += gcnew System::EventHandler(this, &Board::pictureBox14_Click);
			// 
			// blackPawn8
			// 
			this->blackPawn8->BackColor = System::Drawing::Color::Transparent;
			this->blackPawn8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blackPawn8.BackgroundImage")));
			this->blackPawn8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->blackPawn8->Location = System::Drawing::Point(1680, 240);
			this->blackPawn8->Name = L"blackPawn8";
			this->blackPawn8->Size = System::Drawing::Size(240, 240);
			this->blackPawn8->TabIndex = 24;
			this->blackPawn8->TabStop = false;
			// 
			// blackRook1
			// 
			this->blackRook1->BackColor = System::Drawing::Color::Transparent;
			this->blackRook1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blackRook1.BackgroundImage")));
			this->blackRook1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->blackRook1->Location = System::Drawing::Point(0, 0);
			this->blackRook1->Name = L"blackRook1";
			this->blackRook1->Size = System::Drawing::Size(240, 240);
			this->blackRook1->TabIndex = 25;
			this->blackRook1->TabStop = false;
			// 
			// blackRook2
			// 
			this->blackRook2->BackColor = System::Drawing::Color::Transparent;
			this->blackRook2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blackRook2.BackgroundImage")));
			this->blackRook2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->blackRook2->Location = System::Drawing::Point(1680, 0);
			this->blackRook2->Name = L"blackRook2";
			this->blackRook2->Size = System::Drawing::Size(240, 240);
			this->blackRook2->TabIndex = 26;
			this->blackRook2->TabStop = false;
			// 
			// blackKnight1
			// 
			this->blackKnight1->BackColor = System::Drawing::Color::Transparent;
			this->blackKnight1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blackKnight1.BackgroundImage")));
			this->blackKnight1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->blackKnight1->Location = System::Drawing::Point(240, 0);
			this->blackKnight1->Name = L"blackKnight1";
			this->blackKnight1->Size = System::Drawing::Size(240, 240);
			this->blackKnight1->TabIndex = 27;
			this->blackKnight1->TabStop = false;
			// 
			// blackKnight2
			// 
			this->blackKnight2->BackColor = System::Drawing::Color::Transparent;
			this->blackKnight2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blackKnight2.BackgroundImage")));
			this->blackKnight2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->blackKnight2->Location = System::Drawing::Point(1440, 0);
			this->blackKnight2->Name = L"blackKnight2";
			this->blackKnight2->Size = System::Drawing::Size(240, 240);
			this->blackKnight2->TabIndex = 28;
			this->blackKnight2->TabStop = false;
			// 
			// blackBishop1
			// 
			this->blackBishop1->BackColor = System::Drawing::Color::Transparent;
			this->blackBishop1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blackBishop1.BackgroundImage")));
			this->blackBishop1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->blackBishop1->Location = System::Drawing::Point(480, 0);
			this->blackBishop1->Name = L"blackBishop1";
			this->blackBishop1->Size = System::Drawing::Size(240, 240);
			this->blackBishop1->TabIndex = 29;
			this->blackBishop1->TabStop = false;
			// 
			// blackBishop2
			// 
			this->blackBishop2->BackColor = System::Drawing::Color::Transparent;
			this->blackBishop2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blackBishop2.BackgroundImage")));
			this->blackBishop2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->blackBishop2->Location = System::Drawing::Point(1200, 0);
			this->blackBishop2->Name = L"blackBishop2";
			this->blackBishop2->Size = System::Drawing::Size(240, 240);
			this->blackBishop2->TabIndex = 30;
			this->blackBishop2->TabStop = false;
			// 
			// blackQueen
			// 
			this->blackQueen->BackColor = System::Drawing::Color::Transparent;
			this->blackQueen->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blackQueen.BackgroundImage")));
			this->blackQueen->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->blackQueen->Location = System::Drawing::Point(720, 0);
			this->blackQueen->Name = L"blackQueen";
			this->blackQueen->Size = System::Drawing::Size(240, 240);
			this->blackQueen->TabIndex = 31;
			this->blackQueen->TabStop = false;
			// 
			// blackKing
			// 
			this->blackKing->BackColor = System::Drawing::Color::Transparent;
			this->blackKing->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blackKing.BackgroundImage")));
			this->blackKing->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->blackKing->Location = System::Drawing::Point(960, 0);
			this->blackKing->Name = L"blackKing";
			this->blackKing->Size = System::Drawing::Size(240, 240);
			this->blackKing->TabIndex = 32;
			this->blackKing->TabStop = false;
			// 
			// buttonPanel
			// 
			this->buttonPanel->Controls->Add(this->zurückButton);
			this->buttonPanel->Controls->Add(this->nächsterZugButton);
			this->buttonPanel->Location = System::Drawing::Point(1980, 1730);
			this->buttonPanel->Name = L"buttonPanel";
			this->buttonPanel->Size = System::Drawing::Size(1240, 210);
			this->buttonPanel->TabIndex = 300;
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
			this->gameLog->Size = System::Drawing::Size(1240, 1399);
			this->gameLog->TabIndex = 101;
			// 
			// gameLogPanel
			// 
			this->gameLogPanel->Controls->Add(this->gameLog);
			this->gameLogPanel->Location = System::Drawing::Point(1980, 20);
			this->gameLogPanel->Name = L"gameLogPanel";
			this->gameLogPanel->Size = System::Drawing::Size(1240, 1450);
			this->gameLogPanel->TabIndex = 101;
			// 
			// nächsterZugButton
			// 
			this->nächsterZugButton->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nächsterZugButton->Location = System::Drawing::Point(0, 0);
			this->nächsterZugButton->Name = L"nächsterZugButton";
			this->nächsterZugButton->Size = System::Drawing::Size(610, 210);
			this->nächsterZugButton->TabIndex = 301;
			this->nächsterZugButton->Text = L"Nächster Zug";
			this->nächsterZugButton->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(1980, 1470);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1240, 220);
			this->panel1->TabIndex = 301;
			// 
			// zurückButton
			// 
			this->zurückButton->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->zurückButton->Location = System::Drawing::Point(630, 0);
			this->zurückButton->Name = L"zurückButton";
			this->zurückButton->Size = System::Drawing::Size(610, 210);
			this->zurückButton->TabIndex = 302;
			this->zurückButton->Text = L"Zurück zum Hauptmenü";
			this->zurückButton->UseVisualStyleBackColor = true;
			// 
			// Board
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(3214, 2089);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->buttonPanel);
			this->Controls->Add(this->gameLogPanel);
			this->Controls->Add(this->chessBoardPanel);
			this->Margin = System::Windows::Forms::Padding(6);
			this->MinimumSize = System::Drawing::Size(1851, 1414);
			this->Name = L"Board";
			this->Padding = System::Windows::Forms::Padding(20);
			this->Text = L"Board";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Board::Board_Load);
			this->chessBoardPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteRook1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteRook2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteBishop1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteBishop2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteKnight1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteKnight2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteQueen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteKing))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackRook1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackRook2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackKnight1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackKnight2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackBishop1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackBishop2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackQueen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackKing))->EndInit();
			this->buttonPanel->ResumeLayout(false);
			this->gameLogPanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox27_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void pictureBox28_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void pictureBox29_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void pictureBox30_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void pictureBox17_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void pictureBox18_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void pictureBox19_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void pictureBox20_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void pictureBox14_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Board_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}

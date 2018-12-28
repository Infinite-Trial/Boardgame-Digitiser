#pragma once

namespace BordgameDigitiser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UIMenu
	/// </summary>
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
			this->SuspendLayout();
			// 
			// UIMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(3214, 2089);
			this->DoubleBuffered = true;
			this->MaximumSize = System::Drawing::Size(3240, 2160);
			this->MinimumSize = System::Drawing::Size(3238, 2078);
			this->Name = L"UIMenu";
			this->Padding = System::Windows::Forms::Padding(20);
			this->Text = L"UIMenu";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

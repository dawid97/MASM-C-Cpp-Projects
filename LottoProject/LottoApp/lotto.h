#pragma once
#include<Windows.h>
#include <msclr/lock.h>


typedef int(_stdcall *MyProc1) (int*generatedNumbers, int*numbersFromFile);
typedef int(_stdcall *MyProc2) (int*numbersOfWins, int*winForOnePerson,int poolOfMoney);


namespace LottoApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Diagnostics;
	using namespace System::Windows::Forms;
	using namespace System::Threading;
	using namespace std;
	using namespace System::Collections::Generic;
	using namespace msclr;


	/// <summary>
	/// Summary for lotto
	/// </summary>
	public ref class lotto : public System::Windows::Forms::Form
	{
	private: int* numbersOfWins;
	private: int* numbers;
	private: cli::array<String^>^ tmp;
	private: bool libAsmChecked;
	private: bool libCppChecked;
	private: List<Tuple<String^, bool>^> ^files;

	private: int poolOfMoney;

	private: List<String^>^ ticketsWon6;
	private: List<String^>^ ticketsWon5;
	private: List<String^>^ ticketsWon4;
	private: List<String^>^ ticketsWon3;

	private: int* winForOnePerson;
	private: int numberOfThreads;
	private: int numberOfDone;

	private: MyProc1 IloscTrafien;
	private: MyProc2 ObliczCeny;
	private: List<Thread^>^ threads;



	private: System::Windows::Forms::TextBox^  MoneyTextBox;

	private: System::Windows::Forms::Label^  MoneyLabel;
	private: System::Windows::Forms::TextBox^  MoneyFor6TextBox;
	private: System::Windows::Forms::TextBox^  MoneyFor5TextBox;
	private: System::Windows::Forms::TextBox^  MoneyFor4TextBox;
	private: System::Windows::Forms::TextBox^  MoneyFor3TextBox;
	private: System::Windows::Forms::Label^  MoneyFor6Label;
	private: System::Windows::Forms::Label^  MoneyFor5Label;
	private: System::Windows::Forms::Label^  MoneyFor4Label;

	private: System::Windows::Forms::Button^  DirectoryButton;
	private: System::Windows::Forms::Button^  NumbersButton;
	private: System::Windows::Forms::Button^  PoolOfMoneyButton;
	private: System::Windows::Forms::RadioButton^  AsmLibraryButton;
	private: System::Windows::Forms::RadioButton^  CppLibraryButton;
	private: System::Windows::Forms::Label^  LibraryLabel;
	private: System::Windows::Forms::ComboBox^  ThreatsComboBox;
	private: System::Windows::Forms::Label^  ThreadsLabel;
	private: System::Windows::Forms::Label^  DirectoryLabel;
	private: System::Windows::Forms::Label^  TimeCppLabel;
	private: System::Windows::Forms::Label^  TimeAsmLabel;
	private: System::Windows::Forms::TextBox^  TimeCppTextBox;
	private: System::Windows::Forms::TextBox^  TimeAsmTextBox;
	private: System::Windows::Forms::Label^  WinNumbersLabel;





	private: System::Windows::Forms::Label^  MoneyFor3Label;

	public:
		lotto(void)
		{
			InitializeComponent();
			poolOfMoney = 0;
			libAsmChecked = false;
			libCppChecked = false;
			ThreatsComboBox->Text = "1";
			numbersOfWins = nullptr;
			numbers = nullptr;
			winForOnePerson = nullptr;
			IloscTrafien = 0;
			ObliczCeny = 0;
			numberOfThreads = 1;
			numberOfDone = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~lotto()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::OpenFileDialog^  myDialog;

	private: System::Windows::Forms::Button^  Check;


	private: System::Windows::Forms::TextBox^  Number1TextBox;
	private: System::Windows::Forms::TextBox^  Number2TextBox;
	private: System::Windows::Forms::TextBox^  Number3TextBox;
	private: System::Windows::Forms::TextBox^  Number4TextBox;
	private: System::Windows::Forms::TextBox^  Number5TextBox;
	private: System::Windows::Forms::TextBox^  Number6TextBox;


	private: System::Windows::Forms::Label^  Number1Label;
	private: System::Windows::Forms::Label^  Number2Label;
	private: System::Windows::Forms::Label^  Number3Label;
	private: System::Windows::Forms::Label^  Number4Label;
	private: System::Windows::Forms::Label^  Number5Label;
	private: System::Windows::Forms::Label^  Number6Label;


	private: System::Windows::Forms::Label^  NumberOf6Label;
	private: System::Windows::Forms::Label^  NumberOf5Label;
	private: System::Windows::Forms::Label^  NumberOf4Label;
	private: System::Windows::Forms::Label^  NumberOf3Label;

	private: System::Windows::Forms::TextBox^  NumberOf6TextBox;
	private: System::Windows::Forms::TextBox^  NumberOf5TextBox;
	private: System::Windows::Forms::TextBox^  NumberOf4TextBox;
	private: System::Windows::Forms::TextBox^  NumberOf3TextBox;


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
			this->myDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->Number2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Number3TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Number4TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Number5TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Number6TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Number1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Number1Label = (gcnew System::Windows::Forms::Label());
			this->Number2Label = (gcnew System::Windows::Forms::Label());
			this->Number3Label = (gcnew System::Windows::Forms::Label());
			this->Number4Label = (gcnew System::Windows::Forms::Label());
			this->Number5Label = (gcnew System::Windows::Forms::Label());
			this->Number6Label = (gcnew System::Windows::Forms::Label());
			this->Check = (gcnew System::Windows::Forms::Button());
			this->NumberOf6TextBox = (gcnew System::Windows::Forms::TextBox());
			this->NumberOf6Label = (gcnew System::Windows::Forms::Label());
			this->NumberOf5Label = (gcnew System::Windows::Forms::Label());
			this->NumberOf5TextBox = (gcnew System::Windows::Forms::TextBox());
			this->NumberOf4Label = (gcnew System::Windows::Forms::Label());
			this->NumberOf4TextBox = (gcnew System::Windows::Forms::TextBox());
			this->NumberOf3Label = (gcnew System::Windows::Forms::Label());
			this->NumberOf3TextBox = (gcnew System::Windows::Forms::TextBox());
			this->MoneyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MoneyLabel = (gcnew System::Windows::Forms::Label());
			this->MoneyFor6TextBox = (gcnew System::Windows::Forms::TextBox());
			this->MoneyFor5TextBox = (gcnew System::Windows::Forms::TextBox());
			this->MoneyFor4TextBox = (gcnew System::Windows::Forms::TextBox());
			this->MoneyFor3TextBox = (gcnew System::Windows::Forms::TextBox());
			this->MoneyFor6Label = (gcnew System::Windows::Forms::Label());
			this->MoneyFor5Label = (gcnew System::Windows::Forms::Label());
			this->MoneyFor4Label = (gcnew System::Windows::Forms::Label());
			this->MoneyFor3Label = (gcnew System::Windows::Forms::Label());
			this->DirectoryButton = (gcnew System::Windows::Forms::Button());
			this->NumbersButton = (gcnew System::Windows::Forms::Button());
			this->PoolOfMoneyButton = (gcnew System::Windows::Forms::Button());
			this->AsmLibraryButton = (gcnew System::Windows::Forms::RadioButton());
			this->CppLibraryButton = (gcnew System::Windows::Forms::RadioButton());
			this->LibraryLabel = (gcnew System::Windows::Forms::Label());
			this->ThreatsComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ThreadsLabel = (gcnew System::Windows::Forms::Label());
			this->DirectoryLabel = (gcnew System::Windows::Forms::Label());
			this->TimeCppLabel = (gcnew System::Windows::Forms::Label());
			this->TimeAsmLabel = (gcnew System::Windows::Forms::Label());
			this->TimeCppTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TimeAsmTextBox = (gcnew System::Windows::Forms::TextBox());
			this->WinNumbersLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// myDialog
			// 
			this->myDialog->FileName = L"myDialog";
			// 
			// Number2TextBox
			// 
			this->Number2TextBox->Location = System::Drawing::Point(77, 108);
			this->Number2TextBox->Name = L"Number2TextBox";
			this->Number2TextBox->ReadOnly = true;
			this->Number2TextBox->Size = System::Drawing::Size(33, 20);
			this->Number2TextBox->TabIndex = 4;
			// 
			// Number3TextBox
			// 
			this->Number3TextBox->Location = System::Drawing::Point(125, 108);
			this->Number3TextBox->Name = L"Number3TextBox";
			this->Number3TextBox->ReadOnly = true;
			this->Number3TextBox->Size = System::Drawing::Size(33, 20);
			this->Number3TextBox->TabIndex = 5;
			// 
			// Number4TextBox
			// 
			this->Number4TextBox->Location = System::Drawing::Point(174, 108);
			this->Number4TextBox->Name = L"Number4TextBox";
			this->Number4TextBox->ReadOnly = true;
			this->Number4TextBox->Size = System::Drawing::Size(33, 20);
			this->Number4TextBox->TabIndex = 6;
			// 
			// Number5TextBox
			// 
			this->Number5TextBox->Location = System::Drawing::Point(223, 108);
			this->Number5TextBox->Name = L"Number5TextBox";
			this->Number5TextBox->ReadOnly = true;
			this->Number5TextBox->Size = System::Drawing::Size(33, 20);
			this->Number5TextBox->TabIndex = 7;
			// 
			// Number6TextBox
			// 
			this->Number6TextBox->Location = System::Drawing::Point(271, 108);
			this->Number6TextBox->Name = L"Number6TextBox";
			this->Number6TextBox->ReadOnly = true;
			this->Number6TextBox->Size = System::Drawing::Size(33, 20);
			this->Number6TextBox->TabIndex = 8;
			// 
			// Number1TextBox
			// 
			this->Number1TextBox->Location = System::Drawing::Point(28, 108);
			this->Number1TextBox->Name = L"Number1TextBox";
			this->Number1TextBox->ReadOnly = true;
			this->Number1TextBox->Size = System::Drawing::Size(33, 20);
			this->Number1TextBox->TabIndex = 9;
			// 
			// Number1Label
			// 
			this->Number1Label->AutoSize = true;
			this->Number1Label->Location = System::Drawing::Point(25, 83);
			this->Number1Label->Name = L"Number1Label";
			this->Number1Label->Size = System::Drawing::Size(16, 13);
			this->Number1Label->TabIndex = 11;
			this->Number1Label->Text = L"1:";
			// 
			// Number2Label
			// 
			this->Number2Label->AutoSize = true;
			this->Number2Label->Location = System::Drawing::Point(75, 83);
			this->Number2Label->Name = L"Number2Label";
			this->Number2Label->Size = System::Drawing::Size(16, 13);
			this->Number2Label->TabIndex = 12;
			this->Number2Label->Text = L"2:";
			// 
			// Number3Label
			// 
			this->Number3Label->AutoSize = true;
			this->Number3Label->Location = System::Drawing::Point(123, 83);
			this->Number3Label->Name = L"Number3Label";
			this->Number3Label->Size = System::Drawing::Size(16, 13);
			this->Number3Label->TabIndex = 13;
			this->Number3Label->Text = L"3:";
			// 
			// Number4Label
			// 
			this->Number4Label->AutoSize = true;
			this->Number4Label->Location = System::Drawing::Point(171, 83);
			this->Number4Label->Name = L"Number4Label";
			this->Number4Label->Size = System::Drawing::Size(16, 13);
			this->Number4Label->TabIndex = 14;
			this->Number4Label->Text = L"4:";
			// 
			// Number5Label
			// 
			this->Number5Label->AutoSize = true;
			this->Number5Label->Location = System::Drawing::Point(221, 83);
			this->Number5Label->Name = L"Number5Label";
			this->Number5Label->Size = System::Drawing::Size(16, 13);
			this->Number5Label->TabIndex = 15;
			this->Number5Label->Text = L"5:";
			// 
			// Number6Label
			// 
			this->Number6Label->AutoSize = true;
			this->Number6Label->Location = System::Drawing::Point(269, 83);
			this->Number6Label->Name = L"Number6Label";
			this->Number6Label->Size = System::Drawing::Size(16, 13);
			this->Number6Label->TabIndex = 16;
			this->Number6Label->Text = L"6:";
			// 
			// Check
			// 
			this->Check->Location = System::Drawing::Point(162, 462);
			this->Check->Name = L"Check";
			this->Check->Size = System::Drawing::Size(75, 23);
			this->Check->TabIndex = 17;
			this->Check->Text = L"SprawdŸ";
			this->Check->UseVisualStyleBackColor = true;
			this->Check->Click += gcnew System::EventHandler(this, &lotto::Check_Click);
			// 
			// NumberOf6TextBox
			// 
			this->NumberOf6TextBox->Location = System::Drawing::Point(28, 237);
			this->NumberOf6TextBox->Name = L"NumberOf6TextBox";
			this->NumberOf6TextBox->ReadOnly = true;
			this->NumberOf6TextBox->Size = System::Drawing::Size(62, 20);
			this->NumberOf6TextBox->TabIndex = 18;
			// 
			// NumberOf6Label
			// 
			this->NumberOf6Label->AutoSize = true;
			this->NumberOf6Label->Location = System::Drawing::Point(25, 220);
			this->NumberOf6Label->Name = L"NumberOf6Label";
			this->NumberOf6Label->Size = System::Drawing::Size(41, 13);
			this->NumberOf6Label->TabIndex = 19;
			this->NumberOf6Label->Text = L"Ilosc 6:";
			// 
			// NumberOf5Label
			// 
			this->NumberOf5Label->AutoSize = true;
			this->NumberOf5Label->Location = System::Drawing::Point(25, 282);
			this->NumberOf5Label->Name = L"NumberOf5Label";
			this->NumberOf5Label->Size = System::Drawing::Size(41, 13);
			this->NumberOf5Label->TabIndex = 21;
			this->NumberOf5Label->Text = L"Ilosc 5:";
			// 
			// NumberOf5TextBox
			// 
			this->NumberOf5TextBox->Location = System::Drawing::Point(28, 298);
			this->NumberOf5TextBox->Name = L"NumberOf5TextBox";
			this->NumberOf5TextBox->ReadOnly = true;
			this->NumberOf5TextBox->Size = System::Drawing::Size(62, 20);
			this->NumberOf5TextBox->TabIndex = 20;
			// 
			// NumberOf4Label
			// 
			this->NumberOf4Label->AutoSize = true;
			this->NumberOf4Label->Location = System::Drawing::Point(25, 341);
			this->NumberOf4Label->Name = L"NumberOf4Label";
			this->NumberOf4Label->Size = System::Drawing::Size(41, 13);
			this->NumberOf4Label->TabIndex = 23;
			this->NumberOf4Label->Text = L"Ilosc 4:";
			// 
			// NumberOf4TextBox
			// 
			this->NumberOf4TextBox->Location = System::Drawing::Point(28, 357);
			this->NumberOf4TextBox->Name = L"NumberOf4TextBox";
			this->NumberOf4TextBox->ReadOnly = true;
			this->NumberOf4TextBox->Size = System::Drawing::Size(62, 20);
			this->NumberOf4TextBox->TabIndex = 22;
			// 
			// NumberOf3Label
			// 
			this->NumberOf3Label->AutoSize = true;
			this->NumberOf3Label->Location = System::Drawing::Point(25, 401);
			this->NumberOf3Label->Name = L"NumberOf3Label";
			this->NumberOf3Label->Size = System::Drawing::Size(41, 13);
			this->NumberOf3Label->TabIndex = 25;
			this->NumberOf3Label->Text = L"Ilosc 3:";
			// 
			// NumberOf3TextBox
			// 
			this->NumberOf3TextBox->Location = System::Drawing::Point(28, 417);
			this->NumberOf3TextBox->Name = L"NumberOf3TextBox";
			this->NumberOf3TextBox->ReadOnly = true;
			this->NumberOf3TextBox->Size = System::Drawing::Size(62, 20);
			this->NumberOf3TextBox->TabIndex = 24;
			// 
			// MoneyTextBox
			// 
			this->MoneyTextBox->Location = System::Drawing::Point(78, 23);
			this->MoneyTextBox->Name = L"MoneyTextBox";
			this->MoneyTextBox->ReadOnly = true;
			this->MoneyTextBox->Size = System::Drawing::Size(179, 20);
			this->MoneyTextBox->TabIndex = 28;
			// 
			// MoneyLabel
			// 
			this->MoneyLabel->AutoSize = true;
			this->MoneyLabel->Location = System::Drawing::Point(27, 26);
			this->MoneyLabel->Name = L"MoneyLabel";
			this->MoneyLabel->Size = System::Drawing::Size(31, 13);
			this->MoneyLabel->TabIndex = 29;
			this->MoneyLabel->Text = L"Pula:";
			// 
			// MoneyFor6TextBox
			// 
			this->MoneyFor6TextBox->Location = System::Drawing::Point(153, 237);
			this->MoneyFor6TextBox->Name = L"MoneyFor6TextBox";
			this->MoneyFor6TextBox->ReadOnly = true;
			this->MoneyFor6TextBox->Size = System::Drawing::Size(102, 20);
			this->MoneyFor6TextBox->TabIndex = 30;
			// 
			// MoneyFor5TextBox
			// 
			this->MoneyFor5TextBox->Location = System::Drawing::Point(153, 298);
			this->MoneyFor5TextBox->Name = L"MoneyFor5TextBox";
			this->MoneyFor5TextBox->ReadOnly = true;
			this->MoneyFor5TextBox->Size = System::Drawing::Size(102, 20);
			this->MoneyFor5TextBox->TabIndex = 31;
			// 
			// MoneyFor4TextBox
			// 
			this->MoneyFor4TextBox->Location = System::Drawing::Point(154, 357);
			this->MoneyFor4TextBox->Name = L"MoneyFor4TextBox";
			this->MoneyFor4TextBox->ReadOnly = true;
			this->MoneyFor4TextBox->Size = System::Drawing::Size(101, 20);
			this->MoneyFor4TextBox->TabIndex = 32;
			// 
			// MoneyFor3TextBox
			// 
			this->MoneyFor3TextBox->Location = System::Drawing::Point(153, 417);
			this->MoneyFor3TextBox->Name = L"MoneyFor3TextBox";
			this->MoneyFor3TextBox->ReadOnly = true;
			this->MoneyFor3TextBox->Size = System::Drawing::Size(102, 20);
			this->MoneyFor3TextBox->TabIndex = 33;
			// 
			// MoneyFor6Label
			// 
			this->MoneyFor6Label->AutoSize = true;
			this->MoneyFor6Label->Location = System::Drawing::Point(151, 220);
			this->MoneyFor6Label->Name = L"MoneyFor6Label";
			this->MoneyFor6Label->Size = System::Drawing::Size(62, 13);
			this->MoneyFor6Label->TabIndex = 34;
			this->MoneyFor6Label->Text = L"Wygrana 6:";
			// 
			// MoneyFor5Label
			// 
			this->MoneyFor5Label->AutoSize = true;
			this->MoneyFor5Label->Location = System::Drawing::Point(151, 282);
			this->MoneyFor5Label->Name = L"MoneyFor5Label";
			this->MoneyFor5Label->Size = System::Drawing::Size(62, 13);
			this->MoneyFor5Label->TabIndex = 35;
			this->MoneyFor5Label->Text = L"Wygrana 5:";
			// 
			// MoneyFor4Label
			// 
			this->MoneyFor4Label->AutoSize = true;
			this->MoneyFor4Label->Location = System::Drawing::Point(151, 341);
			this->MoneyFor4Label->Name = L"MoneyFor4Label";
			this->MoneyFor4Label->Size = System::Drawing::Size(62, 13);
			this->MoneyFor4Label->TabIndex = 36;
			this->MoneyFor4Label->Text = L"Wygrana 4:";
			// 
			// MoneyFor3Label
			// 
			this->MoneyFor3Label->AutoSize = true;
			this->MoneyFor3Label->Location = System::Drawing::Point(151, 401);
			this->MoneyFor3Label->Name = L"MoneyFor3Label";
			this->MoneyFor3Label->Size = System::Drawing::Size(62, 13);
			this->MoneyFor3Label->TabIndex = 37;
			this->MoneyFor3Label->Text = L"Wygrana 3:";
			// 
			// DirectoryButton
			// 
			this->DirectoryButton->Location = System::Drawing::Point(152, 173);
			this->DirectoryButton->Name = L"DirectoryButton";
			this->DirectoryButton->Size = System::Drawing::Size(104, 23);
			this->DirectoryButton->TabIndex = 39;
			this->DirectoryButton->Text = L"Otwórz";
			this->DirectoryButton->UseVisualStyleBackColor = true;
			this->DirectoryButton->Click += gcnew System::EventHandler(this, &lotto::DirectoryButton_Click);
			// 
			// NumbersButton
			// 
			this->NumbersButton->Location = System::Drawing::Point(327, 108);
			this->NumbersButton->Name = L"NumbersButton";
			this->NumbersButton->Size = System::Drawing::Size(75, 23);
			this->NumbersButton->TabIndex = 40;
			this->NumbersButton->Text = L"Otwórz";
			this->NumbersButton->UseVisualStyleBackColor = true;
			this->NumbersButton->Click += gcnew System::EventHandler(this, &lotto::NumbersButton_Click);
			// 
			// PoolOfMoneyButton
			// 
			this->PoolOfMoneyButton->Location = System::Drawing::Point(329, 23);
			this->PoolOfMoneyButton->Name = L"PoolOfMoneyButton";
			this->PoolOfMoneyButton->Size = System::Drawing::Size(75, 23);
			this->PoolOfMoneyButton->TabIndex = 41;
			this->PoolOfMoneyButton->Text = L"Otwórz";
			this->PoolOfMoneyButton->UseVisualStyleBackColor = true;
			this->PoolOfMoneyButton->Click += gcnew System::EventHandler(this, &lotto::PoolOfMoneyButton_Click);
			// 
			// AsmLibraryButton
			// 
			this->AsmLibraryButton->AutoSize = true;
			this->AsmLibraryButton->Location = System::Drawing::Point(27, 176);
			this->AsmLibraryButton->Name = L"AsmLibraryButton";
			this->AsmLibraryButton->Size = System::Drawing::Size(45, 17);
			this->AsmLibraryButton->TabIndex = 42;
			this->AsmLibraryButton->Text = L"Asm";
			this->AsmLibraryButton->UseVisualStyleBackColor = true;
			this->AsmLibraryButton->CheckedChanged += gcnew System::EventHandler(this, &lotto::AsmLibraryButton_CheckedChanged);
			// 
			// CppLibraryButton
			// 
			this->CppLibraryButton->AutoSize = true;
			this->CppLibraryButton->Location = System::Drawing::Point(78, 176);
			this->CppLibraryButton->Name = L"CppLibraryButton";
			this->CppLibraryButton->Size = System::Drawing::Size(44, 17);
			this->CppLibraryButton->TabIndex = 43;
			this->CppLibraryButton->Text = L"Cpp";
			this->CppLibraryButton->UseVisualStyleBackColor = true;
			this->CppLibraryButton->CheckedChanged += gcnew System::EventHandler(this, &lotto::CppLibraryButton_CheckedChanged);
			// 
			// LibraryLabel
			// 
			this->LibraryLabel->AutoSize = true;
			this->LibraryLabel->Location = System::Drawing::Point(24, 160);
			this->LibraryLabel->Name = L"LibraryLabel";
			this->LibraryLabel->Size = System::Drawing::Size(56, 13);
			this->LibraryLabel->TabIndex = 44;
			this->LibraryLabel->Text = L"Biblioteka:";
			// 
			// ThreatsComboBox
			// 
			this->ThreatsComboBox->DropDownHeight = 120;
			this->ThreatsComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ThreatsComboBox->FormattingEnabled = true;
			this->ThreatsComboBox->IntegralHeight = false;
			this->ThreatsComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(64) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26",
					L"27", L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40", L"41", L"42", L"43", L"44",
					L"45", L"46", L"47", L"48", L"49", L"50", L"51", L"52", L"53", L"54", L"55", L"56", L"57", L"58", L"59", L"60", L"61", L"62",
					L"63", L"64"
			});
			this->ThreatsComboBox->Location = System::Drawing::Point(293, 176);
			this->ThreatsComboBox->Name = L"ThreatsComboBox";
			this->ThreatsComboBox->Size = System::Drawing::Size(108, 21);
			this->ThreatsComboBox->TabIndex = 45;
			this->ThreatsComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &lotto::ThreatsComboBox_SelectedIndexChanged);
			// 
			// ThreadsLabel
			// 
			this->ThreadsLabel->AutoSize = true;
			this->ThreadsLabel->Location = System::Drawing::Point(290, 160);
			this->ThreadsLabel->Name = L"ThreadsLabel";
			this->ThreadsLabel->Size = System::Drawing::Size(38, 13);
			this->ThreadsLabel->TabIndex = 46;
			this->ThreadsLabel->Text = L"W¹tki:";
			// 
			// DirectoryLabel
			// 
			this->DirectoryLabel->AutoSize = true;
			this->DirectoryLabel->Location = System::Drawing::Point(150, 157);
			this->DirectoryLabel->Name = L"DirectoryLabel";
			this->DirectoryLabel->Size = System::Drawing::Size(97, 13);
			this->DirectoryLabel->TabIndex = 47;
			this->DirectoryLabel->Text = L"Katalog wejœciowy:";
			// 
			// TimeCppLabel
			// 
			this->TimeCppLabel->AutoSize = true;
			this->TimeCppLabel->Location = System::Drawing::Point(290, 341);
			this->TimeCppLabel->Name = L"TimeCppLabel";
			this->TimeCppLabel->Size = System::Drawing::Size(55, 13);
			this->TimeCppLabel->TabIndex = 48;
			this->TimeCppLabel->Text = L"Czas Cpp:";
			// 
			// TimeAsmLabel
			// 
			this->TimeAsmLabel->AutoSize = true;
			this->TimeAsmLabel->Location = System::Drawing::Point(290, 401);
			this->TimeAsmLabel->Name = L"TimeAsmLabel";
			this->TimeAsmLabel->Size = System::Drawing::Size(56, 13);
			this->TimeAsmLabel->TabIndex = 49;
			this->TimeAsmLabel->Text = L"Czas Asm:";
			// 
			// TimeCppTextBox
			// 
			this->TimeCppTextBox->Location = System::Drawing::Point(293, 357);
			this->TimeCppTextBox->Name = L"TimeCppTextBox";
			this->TimeCppTextBox->ReadOnly = true;
			this->TimeCppTextBox->Size = System::Drawing::Size(109, 20);
			this->TimeCppTextBox->TabIndex = 50;
			// 
			// TimeAsmTextBox
			// 
			this->TimeAsmTextBox->Location = System::Drawing::Point(293, 417);
			this->TimeAsmTextBox->Name = L"TimeAsmTextBox";
			this->TimeAsmTextBox->ReadOnly = true;
			this->TimeAsmTextBox->Size = System::Drawing::Size(109, 20);
			this->TimeAsmTextBox->TabIndex = 51;
			// 
			// WinNumbersLabel
			// 
			this->WinNumbersLabel->AutoSize = true;
			this->WinNumbersLabel->Location = System::Drawing::Point(24, 61);
			this->WinNumbersLabel->Name = L"WinNumbersLabel";
			this->WinNumbersLabel->Size = System::Drawing::Size(104, 13);
			this->WinNumbersLabel->TabIndex = 52;
			this->WinNumbersLabel->Text = L"Liczby wygrywaj¹ce:";
			// 
			// lotto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(418, 493);
			this->Controls->Add(this->WinNumbersLabel);
			this->Controls->Add(this->TimeAsmTextBox);
			this->Controls->Add(this->TimeCppTextBox);
			this->Controls->Add(this->TimeAsmLabel);
			this->Controls->Add(this->TimeCppLabel);
			this->Controls->Add(this->DirectoryLabel);
			this->Controls->Add(this->ThreadsLabel);
			this->Controls->Add(this->ThreatsComboBox);
			this->Controls->Add(this->LibraryLabel);
			this->Controls->Add(this->CppLibraryButton);
			this->Controls->Add(this->AsmLibraryButton);
			this->Controls->Add(this->PoolOfMoneyButton);
			this->Controls->Add(this->NumbersButton);
			this->Controls->Add(this->DirectoryButton);
			this->Controls->Add(this->MoneyFor3Label);
			this->Controls->Add(this->MoneyFor4Label);
			this->Controls->Add(this->MoneyFor5Label);
			this->Controls->Add(this->MoneyFor6Label);
			this->Controls->Add(this->MoneyFor3TextBox);
			this->Controls->Add(this->MoneyFor4TextBox);
			this->Controls->Add(this->MoneyFor5TextBox);
			this->Controls->Add(this->MoneyFor6TextBox);
			this->Controls->Add(this->MoneyLabel);
			this->Controls->Add(this->MoneyTextBox);
			this->Controls->Add(this->NumberOf3Label);
			this->Controls->Add(this->NumberOf3TextBox);
			this->Controls->Add(this->NumberOf4Label);
			this->Controls->Add(this->NumberOf4TextBox);
			this->Controls->Add(this->NumberOf5Label);
			this->Controls->Add(this->NumberOf5TextBox);
			this->Controls->Add(this->NumberOf6Label);
			this->Controls->Add(this->NumberOf6TextBox);
			this->Controls->Add(this->Check);
			this->Controls->Add(this->Number6Label);
			this->Controls->Add(this->Number5Label);
			this->Controls->Add(this->Number4Label);
			this->Controls->Add(this->Number3Label);
			this->Controls->Add(this->Number2Label);
			this->Controls->Add(this->Number1Label);
			this->Controls->Add(this->Number1TextBox);
			this->Controls->Add(this->Number6TextBox);
			this->Controls->Add(this->Number5TextBox);
			this->Controls->Add(this->Number4TextBox);
			this->Controls->Add(this->Number3TextBox);
			this->Controls->Add(this->Number2TextBox);
			this->Name = L"lotto";
			this->Text = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &lotto::lotto_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void loadNumbers()
	{
		if (numbers)
		{
			delete numbers;
			numbers = nullptr;
		}

		//resetowanie okienek poszczegolnych wygranych
		resetNumbersOfWins();
		resetPricesForWins();

		//reset okienek poszczegolnych czasow
		resetTimersTextBoxes();

		FileInfo^ fileInfo;
		TextReader^ reader;
		int number;
		int counter = 0;
		numbers = new int[6];


		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
		openFileDialog->Filter = "Txt Files (*.txt)|*.txt";
		openFileDialog->ShowDialog();

		String^ filename = openFileDialog->FileName;

		try {
			fileInfo = gcnew FileInfo(filename);
			reader = File::OpenText(filename);

			if (fileInfo->Length > 22)
			{
				delete numbers;
				throw gcnew FileLoadException("Plik ma za du¿y rozmiar.");
			}


			while (reader->Peek() >= 0)
			{
				counter++;

				if (counter > 6)
				{
					delete numbers;
					throw gcnew FormatException("W pliku znajduje siê za du¿o liczb.");
				}

				number = int::Parse(reader->ReadLine());

				if (number > 49 || number < 1)
				{
					delete numbers;
					throw gcnew FormatException("Liczby w pliku musz¹ byæ z zakresu od 1 do 49");
				}

				for(int i=0;i<6;i++)
				{
					if (numbers[i] == number)
					{
						delete numbers;
						throw gcnew FormatException("W pliku liczby nie mog¹ siê powtarzaæ.");
					}
				}

				numbers[counter-1] = number;
			}

			if (counter < 6)
			{
				delete numbers;
				throw gcnew ArgumentNullException("Za ma³o argumentów w pliku");
			}
		}
		catch (ArgumentNullException^ argumentNullException) //za malo argumentow w pliku
		{
			MessageBox::Show(argumentNullException->Message);
			numbers = nullptr;
		}
		catch (FileLoadException^ fileLoadException) //za duzy rozmiar pliku
		{
			MessageBox::Show(fileLoadException->Message);
			numbers = nullptr;
		}
		catch (FormatException^ formatException) //bledny format pliku
		{
			MessageBox::Show(formatException->Message);
			numbers = nullptr;
		}
		catch (ArgumentException^ argumentException)  //bledny format sciezki
		{
			MessageBox::Show(argumentException->Message);
			numbers = nullptr;
		}
	}

	private: System::Void setNumbers()
	{
		if (numbers==nullptr)
			return;

		List<TextBox^>^ textBoxes = gcnew List<TextBox^>();
		textBoxes->Add(Number1TextBox);
		textBoxes->Add(Number2TextBox);
		textBoxes->Add(Number3TextBox);
		textBoxes->Add(Number4TextBox);
		textBoxes->Add(Number5TextBox);
		textBoxes->Add(Number6TextBox);

		for (int i = 0; i < 6; i++)
			textBoxes[i]->Text = numbers[i].ToString();
	}

	private: System::Void DirectoryButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//resetowanie okienek poszczegolnych wygranych
		resetNumbersOfWins();
		resetPricesForWins();

		//reset okienek poszczegolnych czasow
		resetTimersTextBoxes();

		files = gcnew List<Tuple<String^, bool>^>;

		FolderBrowserDialog^ folderBrowserDialog = gcnew FolderBrowserDialog();
		folderBrowserDialog->ShowDialog();

		String^ pth = folderBrowserDialog->SelectedPath;

		try
		{
			DirectoryInfo^ directoryInfo = gcnew DirectoryInfo(pth);
			tmp = Directory::GetFiles(pth, "*.txt");

			for (int i = 0; i < tmp->Length; i++)
			{
				files->Add(gcnew Tuple<String^, bool>(tmp[i], false));
			}
		}
		catch (ArgumentException^ argumentException) //bledny format sciezki
		{
			MessageBox::Show(argumentException->Message);
		}
	}

	private: System::Void resetFiles()
	{
		for (int i = 0; i < files->Count; i++)
		{
			String^s = files[i]->Item1;
			files->RemoveAt(i);
			files->Insert(i, gcnew Tuple<String^, bool>(s, false));
		}
	}

	private: System::Void NumbersButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		loadNumbers();
		setNumbers();
	}

	private: System::Void loadPoolOfMoney()
	{
		//resetowanie okienek poszczegolnych wygranych
		resetNumbersOfWins();
		resetPricesForWins();

		//reset okienek poszczegolnych czasow
		resetTimersTextBoxes();

		FileInfo^ fileInfo;
		TextReader^ reader;
		int money;
		int counter = 0;

		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
		openFileDialog->Filter = "Txt Files (*.txt)|*.txt";
		openFileDialog->ShowDialog();

		String^ pth = openFileDialog->FileName;

		try {
			fileInfo = gcnew FileInfo(pth);
			reader = File::OpenText(pth);

			if (fileInfo->Length > 12)
			{
				throw gcnew FileLoadException("Plik ma za du¿y rozmiar.");
			}


			while (reader->Peek() >= 0)
			{
				counter++;

				if (counter > 1)
				{
					throw gcnew FormatException("W pliku znajduje siê za du¿o liczb.");
				}

				money = int::Parse(reader->ReadLine());

				if (money < 5000000)
				{
					throw gcnew FormatException("Pola pieniedzy nie moze byc mniejsza niz 5 mln.");
				}

				if (money > 100000000)
				{
					throw gcnew FormatException("Pola pieniedzy nie moze byc wieksza niz 100 mln.");
				}
			}

			if (counter < 1)
			{
				throw gcnew ArgumentNullException("Brak poli pieniedzy w pliku.");
			}

			poolOfMoney = money;
		}
		catch (ArgumentNullException^ argumentNullException) //za malo argumentow w pliku
		{
			MessageBox::Show(argumentNullException->Message);
		}
		catch (FileLoadException^ fileLoadException) //za duzy rozmiar pliku
		{
			MessageBox::Show(fileLoadException->Message);
		}
		catch (FormatException^ formatException) //bledny format pliku
		{
			MessageBox::Show(formatException->Message);
		}
		catch (ArgumentException^ argumentException)  //bledny format sciezki
		{
			MessageBox::Show(argumentException->Message);
		}
	}

	private: System::Void setPoolOfMoney()
	{
		if (poolOfMoney == 0)
			return;

		MoneyTextBox->Text = poolOfMoney.ToString();
	}

	private: int* getArrayOfNumbersFromFile(String^pth)
	{
		FileInfo^ fileInfo;
		TextReader^ reader;
		int* numbersFromFile = new int[6];
		int number;

		try
		{
			fileInfo = gcnew FileInfo(pth);

			if (fileInfo->Length > 24)
			{
				delete numbersFromFile;
				throw gcnew FileLoadException("Plik "+pth+" ma za du¿y rozmiar.");
			}


			reader = File::OpenText(pth);

			int counter = 0;

			while (reader->Peek() >= 0)
			{
				counter++;

				if (counter > 6)
				{
					delete numbersFromFile;
					throw gcnew FormatException("W pliku "+pth+" znajduje siê za du¿o liczb.");
				}


				number = int::Parse(reader->ReadLine());

				if (number > 49 || number < 1)
				{
					delete numbersFromFile;
					throw gcnew FormatException("Liczby w pliku "+pth+" musz¹ byæ z zakresu od 1 do 49");
				}


				for(int i=0;i<6;i++)
				{
					if (numbersFromFile[i] == number)
					{
						//delete numbersFromFile;
						//throw gcnew FormatException("W pliku "+pth+" liczby nie mog¹ siê powtarzaæ.");
					}
				}

				numbersFromFile[counter - 1] = number;
			}

			if (counter < 6)
			{
				delete numbersFromFile;
				throw gcnew ArgumentNullException("Za ma³o argumentów w pliku "+pth);
			}

			return numbersFromFile;
		}
		catch (ArgumentNullException^ argumentNullException) //za malo argumentow w pliku
		{
			MessageBox::Show(argumentNullException->Message);
			return nullptr;
		}
		catch (ArgumentException^ argumentException)  //bledny format sciezki
		{
			//MessageBox::Show(argumentException->Message);
			//return nullptr;
		}
		catch (FormatException^ formatException) //bledny format pliku
		{
			MessageBox::Show(formatException->Message);
			return nullptr;
		}
		catch (FileLoadException^ fileLoadException) //za duzy rozmiar pliku
		{
			MessageBox::Show(fileLoadException->Message);
			return nullptr;
		}
		catch (FileNotFoundException^ fileNotFoundException) //nie znaleziono pliku
		{
			MessageBox::Show(fileNotFoundException->Message);
			return nullptr;
		}
	}

	private: void calculateNumbersOfWin()
	{

		int* currentNumbersFromFile = nullptr;

		int result;

		String^s = "";

		try {
			lock l(this);
			for (int i = 0; i < files->Count; i++)
			{
				if (files[i]->Item2 == false)
				{
					s = files[i]->Item1;


					files->Remove(files[i]);
					files->Add(gcnew Tuple<String^, bool>(s, true));

					break;
				}
			}

			currentNumbersFromFile = getArrayOfNumbersFromFile(s);
		}
		catch (...)
		{
			MessageBox::Show("Couldn't acquire lock!");
		}

		if (currentNumbersFromFile == nullptr)
			return;

		//Asm lub Cpp
		result = IloscTrafien(numbers, currentNumbersFromFile);

		try {
			lock l(this);
			if (result == 6)
			{
				numbersOfWins[0] += 1;
				ticketsWon6->Add(s);
			}
			else if (result == 5)
			{
				numbersOfWins[1] += 1;
				ticketsWon5->Add(s);
			}
			else if (result == 4)
			{
				numbersOfWins[2] += 1;
				ticketsWon4->Add(s);
			}
			else if (result == 3)
			{
				numbersOfWins[3] += 1;
				ticketsWon3->Add(s);
			}
		}
		catch (...)
		{
			MessageBox::Show("Couldn't acquire lock!");
		}

		if (currentNumbersFromFile)
		{
			delete currentNumbersFromFile;
			currentNumbersFromFile = nullptr;
		}
	}

	private: System::Void Check_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (files == nullptr || files->Count == 0)
		{
			MessageBox::Show("Nie wybrano katalogu lub katalog jest pusty.");
			return;
		}

		if (numbers == nullptr)
		{
			MessageBox::Show("Nie wybrano liczb wygrywajacych.");
			return;
		}

		if (poolOfMoney == 0)
		{
			MessageBox::Show("Nie wybrano poli pieniedzy.");
			return;
		}

		if (IloscTrafien == nullptr)
		{
			MessageBox::Show("Nie wybrano biblioteki");
			return;
		}

		if (numbersOfWins)
		{
			delete numbersOfWins;
			numbersOfWins = nullptr;
		}

		numbersOfWins = new int[4];

		numberOfDone = 0;

		ticketsWon6 = gcnew List<String^>();
		ticketsWon5 = gcnew List<String^>();
		ticketsWon4 = gcnew List<String^>();
		ticketsWon3 = gcnew List<String^>();

		for (int i = 0; i < 4; i++)
		{
			numbersOfWins[i] = 0;
		}



		if (numberOfThreads > files->Count)
			numberOfThreads = files->Count;

		Stopwatch^ watch = Stopwatch::StartNew();

		threads = gcnew List<Thread^>();

		for (int i = 0; i < numberOfThreads; i++)
		{
			threads->Add(gcnew Thread(gcnew ThreadStart(this, &lotto::calculateNumbersOfWin)));
		}

		

		for (int i = 0; i < numberOfThreads; i++)
		{
			threads[i]->Start();
			if (numberOfThreads == 1)
				threads[i]->Join();
		}

		numberOfDone = numberOfThreads;



		while (numberOfDone < files->Count)
		{
			for (int i = 0; i < numberOfThreads; i++)
			{
				if (threads[i]->IsAlive == false)
				{

					threads[i] = gcnew Thread(gcnew ThreadStart(this, &lotto::calculateNumbersOfWin));
					threads[i]->Start();

					if (numberOfThreads == 1)
						threads[i]->Join();

					numberOfDone += 1;

					if (numberOfDone == files->Count)
					{
						break;
					}

				}
			}
		}

		for (int i = 0; i < numberOfThreads; i++)
		{
			threads[i]->Join();
		}


		setNumbersOfWins();
		calculatePricesForWins(); 
		setPricesForWins(); 

		watch->Stop();
		long long elapsedMs = watch->ElapsedMilliseconds;

		if (libCppChecked)
		{
			TimeCppTextBox->Text = elapsedMs.ToString();
		}
		if (libAsmChecked)
		{
			TimeAsmTextBox->Text = elapsedMs.ToString();
		}

		resetFiles();
	}

	private: System::Void resetTimersTextBoxes()
	{
		TimeAsmTextBox->Text = "";
		TimeCppTextBox->Text = "";
	}

	private: System::Void setNumbersOfWins()
	{
		if (numbersOfWins == nullptr)
			return;

		List<TextBox^>^ textBoxes = gcnew List<TextBox^>();
		textBoxes->Add(NumberOf6TextBox);
		textBoxes->Add(NumberOf5TextBox);
		textBoxes->Add(NumberOf4TextBox);
		textBoxes->Add(NumberOf3TextBox);

		for (int i = 0; i < 4; i++)
		{
			textBoxes[i]->Text = numbersOfWins[i].ToString();
		}

	}

	private: System::Void resetNumbersOfWins()
	{
		List<TextBox^>^ textBoxes = gcnew List<TextBox^>();
		textBoxes->Add(NumberOf6TextBox);
		textBoxes->Add(NumberOf5TextBox);
		textBoxes->Add(NumberOf4TextBox);
		textBoxes->Add(NumberOf3TextBox);

		for (int i = 0; i < 4; i++)
		{
			textBoxes[i]->Text = "";
		}
	}

	private: System::Void resetPricesForWins()
	{
		List<TextBox^>^ textBoxes = gcnew List<TextBox^>();
		textBoxes->Add(MoneyFor6TextBox);
		textBoxes->Add(MoneyFor5TextBox);
		textBoxes->Add(MoneyFor4TextBox);
		textBoxes->Add(MoneyFor3TextBox);

		for (int i = 0; i < 4; i++)
		{
			textBoxes[i]->Text = "";
		}
	}

	private: System::Void PoolOfMoneyButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		loadPoolOfMoney();
		setPoolOfMoney();
	}

	private: System::Void AsmLibraryButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		//resetowanie okienek poszczegolnych wygranych
		resetNumbersOfWins();
		resetPricesForWins();
		
		HINSTANCE uchwytDLL = 0;
		uchwytDLL = LoadLibraryA("ASM_DLL.dll");

		if (!uchwytDLL)
		{
			MessageBox::Show("nie ma biblioteki asm");
			return;
		}

		IloscTrafien = (MyProc1)GetProcAddress(uchwytDLL, "MyProc1");
		ObliczCeny = (MyProc2)GetProcAddress(uchwytDLL, "MyProc2");
		
		libAsmChecked = true;
		libCppChecked = false;
	}

	private: System::Void CppLibraryButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		//resetowanie okienek poszczegolnych wygranych
		resetNumbersOfWins();
		resetPricesForWins();

		HINSTANCE uchwytDLL = 0;
		uchwytDLL = LoadLibraryA("CPP_DLL.dll");
		
		if (!uchwytDLL)
		{
			MessageBox::Show("nie ma biblioteki cpp");
			return;
		}
		
		IloscTrafien = (MyProc1)GetProcAddress(uchwytDLL, "numberOfHits");
		ObliczCeny = (MyProc2)GetProcAddress(uchwytDLL, "calculatePrices");

		libCppChecked = true;
		libAsmChecked = false;
	}

	private: void calculatePricesForWins()
	{
		if (winForOnePerson)
		{
			delete winForOnePerson;
			winForOnePerson = nullptr;
		}

		if (numbersOfWins == nullptr)
			return;

		winForOnePerson = new int[4];

		ObliczCeny(numbersOfWins, winForOnePerson,poolOfMoney);
	}

	private: void setPricesForWins()
	{
		if (winForOnePerson == nullptr)
			return;

		List<TextBox^>^ textBoxes = gcnew List<TextBox^>();
		textBoxes->Add(MoneyFor6TextBox);
		textBoxes->Add(MoneyFor5TextBox);
		textBoxes->Add(MoneyFor4TextBox);
		textBoxes->Add(MoneyFor3TextBox);

		for (int i = 0; i < 4; i++)
		{
			if (winForOnePerson[i] == 0)
			{
				textBoxes[i]->Text = "";
			}
			else
			{
				textBoxes[i]->Text = winForOnePerson[i].ToString();
			}
		}
	}

	private: System::Void saveResultsToFile()
	{
		if (numbersOfWins == nullptr)
			return;

		if (winForOnePerson == nullptr)
			return;

		DateTime dateTime = DateTime::Now;

		String^tmp = dateTime.ToString();

		cli::array<Char>^chars = { ' ',':' };
		cli::array<String^>^split = tmp->Split(chars);

		String^filename = "Results " + split[0] + " " + split[1] + "." + split[2] + "." + split[3] + ".txt";

		StreamWriter^outFile = gcnew StreamWriter(filename);

		outFile->WriteLine("Kumulacja: " + poolOfMoney.ToString());
		outFile->WriteLine();

		outFile->Write("Liczby: ");
		for (int i = 0; i < 6;i++)
		{
			outFile->Write(numbers[i] + " ");
		}
		outFile->WriteLine();
		outFile->WriteLine();

		outFile->WriteLine("Ilosc szostek: " + numbersOfWins[0]);
		outFile->WriteLine("Ilosc piatek: " + numbersOfWins[1]);
		outFile->WriteLine("Ilosc czworek: " + numbersOfWins[2]);
		outFile->WriteLine("Ilosc trojek: " + numbersOfWins[3]);
		outFile->WriteLine();

		outFile->WriteLine("Wygrana 6: " + winForOnePerson[0]);
		outFile->WriteLine("Wygrana 5: " + winForOnePerson[1]);
		outFile->WriteLine("Wygrana 4: " + winForOnePerson[2]);
		outFile->WriteLine("Wygrana 3: " + winForOnePerson[3]);
		outFile->WriteLine();

		outFile->WriteLine("Szostki:");
		outFile->WriteLine();
		for each(String^element in ticketsWon6)
		{
			outFile->WriteLine(element);
		}
		outFile->WriteLine(" ");
		outFile->WriteLine("Piatki:");
		outFile->WriteLine(" ");
		for each(String^element in ticketsWon5)
		{
			outFile->WriteLine(element);
		}
		outFile->WriteLine();
		outFile->WriteLine("Czworki:");
		outFile->WriteLine();
		for each(String^element in ticketsWon4)
		{
			outFile->WriteLine(element);
		}
		outFile->WriteLine();
		outFile->WriteLine("Trojki:");
		outFile->WriteLine();
		for each(String^element in ticketsWon3)
		{
			outFile->WriteLine(element);
		}

		outFile->Close();
	}

	private: System::Void ThreatsComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		numberOfThreads = int::Parse(ThreatsComboBox->SelectedItem->ToString());

		//reset okienk poszczegolnych wygranych
		resetNumbersOfWins();
		resetPricesForWins();

		//reset okienek poszczegolnych czasow
		resetTimersTextBoxes();
	}

private: System::Void lotto_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

	if (numbers)
	{
		delete numbers;
		numbers = nullptr;
	}

	if (winForOnePerson)
	{
		delete winForOnePerson;
		winForOnePerson = nullptr;
	}

	if (numbersOfWins)
	{
		delete numbersOfWins;
		numbersOfWins = nullptr;
	}
}


};
}

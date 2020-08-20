#pragma once
#include <string>
#include <chrono>
#include <msclr\marshal_cppstd.h>
#include "Manazer.h"
#include "Oblast.h"
#include "Obec.h"

namespace ObertaJurajAUS2
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
		}

		//==================================================MOJE PUBLIC
		void SetManazer(Manazer* m) { m_manazer = m; }


		//=============================================================

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ programToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ukoncitToolStripMenuItem;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	private: System::Windows::Forms::GroupBox^ Zoradenie;

	private: System::Windows::Forms::Button^ ZoradenieButton;
	private: System::Windows::Forms::GroupBox^ Filtre;

	private: System::Windows::Forms::CheckBox^ Kolo2;

	private: System::Windows::Forms::CheckBox^ Kolo1;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ UcastDo;

	private: System::Windows::Forms::TextBox^ UcastOd;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ PocetDo;

	private: System::Windows::Forms::TextBox^ PocetOd;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ NazovBox;

	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::ListView^ MainListView;

	private: System::Windows::Forms::ColumnHeader^ Nazov;
	private: System::Windows::Forms::ColumnHeader^ NazovOkres;
	private: System::Windows::Forms::ColumnHeader^ NazovKraj;
	private: System::Windows::Forms::ColumnHeader^ PocetVolicov1;
	private: System::Windows::Forms::ColumnHeader^ PocetVolicov2;
	private: System::Windows::Forms::ColumnHeader^ VydaneObalky1;
	private: System::Windows::Forms::ColumnHeader^ VydaneObalky2;
	private: System::Windows::Forms::ColumnHeader^ Ucast1;
	private: System::Windows::Forms::ColumnHeader^ Ucast2;
	private: System::Windows::Forms::ColumnHeader^ OdovzdaneObalky1;
	private: System::Windows::Forms::ColumnHeader^ OdovzdaneObalky2;
	private: System::Windows::Forms::ColumnHeader^ PlatneHlasy1;
	private: System::Windows::Forms::ColumnHeader^ PlatneHlasy2;
	private: System::Windows::Forms::RadioButton^ ZoradUcast;

	private: System::Windows::Forms::RadioButton^ ZoradVolici;

	private: System::Windows::Forms::RadioButton^ ZoradNazov;
	private: System::Windows::Forms::CheckBox^ ZoradZostupne;
	private: System::Windows::Forms::ColumnHeader^ FilterHodnota;

	private: System::Windows::Forms::RadioButton^ SettingObec;
	private: System::Windows::Forms::RadioButton^ SettingOkres;
	private: System::Windows::Forms::RadioButton^ SettingKraj;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ PrislusnostBox;

	private: System::Windows::Forms::ColumnHeader^ PocetVolicovS;
	private: System::Windows::Forms::GroupBox^  groupVypis;

			 //==================================================MOJE PRIVATE
			 Manazer* m_manazer;

			 void Filtruj();
			
			 void Vypis(structures::List<Oblast*>* listToShow);
			 void VypisObce(structures::List<Obec*>* listToShow);

			 //=============================================================


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
			 void InitializeComponent(void)
			 {
				 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				 this->programToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->ukoncitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->Zoradenie = (gcnew System::Windows::Forms::GroupBox());
				 this->ZoradZostupne = (gcnew System::Windows::Forms::CheckBox());
				 this->ZoradUcast = (gcnew System::Windows::Forms::RadioButton());
				 this->ZoradVolici = (gcnew System::Windows::Forms::RadioButton());
				 this->ZoradNazov = (gcnew System::Windows::Forms::RadioButton());
				 this->ZoradenieButton = (gcnew System::Windows::Forms::Button());
				 this->Filtre = (gcnew System::Windows::Forms::GroupBox());
				 this->Kolo2 = (gcnew System::Windows::Forms::CheckBox());
				 this->Kolo1 = (gcnew System::Windows::Forms::CheckBox());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->UcastDo = (gcnew System::Windows::Forms::TextBox());
				 this->UcastOd = (gcnew System::Windows::Forms::TextBox());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->PocetDo = (gcnew System::Windows::Forms::TextBox());
				 this->PocetOd = (gcnew System::Windows::Forms::TextBox());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->NazovBox = (gcnew System::Windows::Forms::TextBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->MainListView = (gcnew System::Windows::Forms::ListView());
				 this->Nazov = (gcnew System::Windows::Forms::ColumnHeader());
				 this->NazovOkres = (gcnew System::Windows::Forms::ColumnHeader());
				 this->NazovKraj = (gcnew System::Windows::Forms::ColumnHeader());
				 this->PocetVolicov1 = (gcnew System::Windows::Forms::ColumnHeader());
				 this->PocetVolicov2 = (gcnew System::Windows::Forms::ColumnHeader());
				 this->PocetVolicovS = (gcnew System::Windows::Forms::ColumnHeader());
				 this->Ucast1 = (gcnew System::Windows::Forms::ColumnHeader());
				 this->Ucast2 = (gcnew System::Windows::Forms::ColumnHeader());
				 this->VydaneObalky1 = (gcnew System::Windows::Forms::ColumnHeader());
				 this->VydaneObalky2 = (gcnew System::Windows::Forms::ColumnHeader());
				 this->OdovzdaneObalky1 = (gcnew System::Windows::Forms::ColumnHeader());
				 this->OdovzdaneObalky2 = (gcnew System::Windows::Forms::ColumnHeader());
				 this->PlatneHlasy1 = (gcnew System::Windows::Forms::ColumnHeader());
				 this->PlatneHlasy2 = (gcnew System::Windows::Forms::ColumnHeader());
				 this->FilterHodnota = (gcnew System::Windows::Forms::ColumnHeader());
				 this->SettingObec = (gcnew System::Windows::Forms::RadioButton());
				 this->SettingOkres = (gcnew System::Windows::Forms::RadioButton());
				 this->SettingKraj = (gcnew System::Windows::Forms::RadioButton());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->PrislusnostBox = (gcnew System::Windows::Forms::TextBox());
				 this->groupVypis = (gcnew System::Windows::Forms::GroupBox());
				 this->menuStrip1->SuspendLayout();
				 this->Zoradenie->SuspendLayout();
				 this->Filtre->SuspendLayout();
				 this->groupVypis->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // menuStrip1
				 // 
				 this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->programToolStripMenuItem });
				 this->menuStrip1->Location = System::Drawing::Point(0, 0);
				 this->menuStrip1->Name = L"menuStrip1";
				 this->menuStrip1->Size = System::Drawing::Size(1211, 24);
				 this->menuStrip1->TabIndex = 0;
				 this->menuStrip1->Text = L"menuStrip1";
				 // 
				 // programToolStripMenuItem
				 // 
				 this->programToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ukoncitToolStripMenuItem });
				 this->programToolStripMenuItem->Name = L"programToolStripMenuItem";
				 this->programToolStripMenuItem->Size = System::Drawing::Size(65, 20);
				 this->programToolStripMenuItem->Text = L"Program";
				 // 
				 // ukoncitToolStripMenuItem
				 // 
				 this->ukoncitToolStripMenuItem->Name = L"ukoncitToolStripMenuItem";
				 this->ukoncitToolStripMenuItem->Size = System::Drawing::Size(180, 22);
				 this->ukoncitToolStripMenuItem->Text = L"Ukoncit";
				 this->ukoncitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ukoncitToolStripMenuItem_Click);
				 // 
				 // Zoradenie
				 // 
				 this->Zoradenie->Controls->Add(this->ZoradZostupne);
				 this->Zoradenie->Controls->Add(this->ZoradUcast);
				 this->Zoradenie->Controls->Add(this->ZoradVolici);
				 this->Zoradenie->Controls->Add(this->ZoradNazov);
				 this->Zoradenie->Location = System::Drawing::Point(492, 27);
				 this->Zoradenie->Name = L"Zoradenie";
				 this->Zoradenie->Size = System::Drawing::Size(151, 93);
				 this->Zoradenie->TabIndex = 13;
				 this->Zoradenie->TabStop = false;
				 this->Zoradenie->Text = L"Zoradenie";
				 // 
				 // ZoradZostupne
				 // 
				 this->ZoradZostupne->AutoSize = true;
				 this->ZoradZostupne->Location = System::Drawing::Point(68, 21);
				 this->ZoradZostupne->Name = L"ZoradZostupne";
				 this->ZoradZostupne->Size = System::Drawing::Size(71, 17);
				 this->ZoradZostupne->TabIndex = 4;
				 this->ZoradZostupne->Text = L"Zostupne";
				 this->ZoradZostupne->UseVisualStyleBackColor = true;
				 // 
				 // ZoradUcast
				 // 
				 this->ZoradUcast->AutoSize = true;
				 this->ZoradUcast->Location = System::Drawing::Point(6, 65);
				 this->ZoradUcast->Name = L"ZoradUcast";
				 this->ZoradUcast->Size = System::Drawing::Size(53, 17);
				 this->ZoradUcast->TabIndex = 3;
				 this->ZoradUcast->TabStop = true;
				 this->ZoradUcast->Text = L"Ucast";
				 this->ZoradUcast->UseVisualStyleBackColor = true;
				 // 
				 // ZoradVolici
				 // 
				 this->ZoradVolici->AutoSize = true;
				 this->ZoradVolici->Location = System::Drawing::Point(6, 43);
				 this->ZoradVolici->Name = L"ZoradVolici";
				 this->ZoradVolici->Size = System::Drawing::Size(50, 17);
				 this->ZoradVolici->TabIndex = 2;
				 this->ZoradVolici->TabStop = true;
				 this->ZoradVolici->Text = L"Volici";
				 this->ZoradVolici->UseVisualStyleBackColor = true;
				 // 
				 // ZoradNazov
				 // 
				 this->ZoradNazov->AutoSize = true;
				 this->ZoradNazov->Checked = true;
				 this->ZoradNazov->Location = System::Drawing::Point(6, 20);
				 this->ZoradNazov->Name = L"ZoradNazov";
				 this->ZoradNazov->Size = System::Drawing::Size(56, 17);
				 this->ZoradNazov->TabIndex = 1;
				 this->ZoradNazov->TabStop = true;
				 this->ZoradNazov->Text = L"Nazov";
				 this->ZoradNazov->UseVisualStyleBackColor = true;
				 // 
				 // ZoradenieButton
				 // 
				 this->ZoradenieButton->Location = System::Drawing::Point(9, 58);
				 this->ZoradenieButton->Name = L"ZoradenieButton";
				 this->ZoradenieButton->Size = System::Drawing::Size(100, 23);
				 this->ZoradenieButton->TabIndex = 0;
				 this->ZoradenieButton->Text = L"&Aplikuj";
				 this->ZoradenieButton->UseVisualStyleBackColor = true;
				 this->ZoradenieButton->Click += gcnew System::EventHandler(this, &MainForm::ZoradenieButton_Click);
				 // 
				 // Filtre
				 // 
				 this->Filtre->Controls->Add(this->Kolo2);
				 this->Filtre->Controls->Add(this->Kolo1);
				 this->Filtre->Controls->Add(this->label7);
				 this->Filtre->Controls->Add(this->label5);
				 this->Filtre->Controls->Add(this->ZoradenieButton);
				 this->Filtre->Controls->Add(this->label6);
				 this->Filtre->Controls->Add(this->UcastDo);
				 this->Filtre->Controls->Add(this->UcastOd);
				 this->Filtre->Controls->Add(this->label4);
				 this->Filtre->Controls->Add(this->label3);
				 this->Filtre->Controls->Add(this->PocetDo);
				 this->Filtre->Controls->Add(this->PocetOd);
				 this->Filtre->Controls->Add(this->label2);
				 this->Filtre->Controls->Add(this->NazovBox);
				 this->Filtre->Controls->Add(this->label1);
				 this->Filtre->Location = System::Drawing::Point(12, 27);
				 this->Filtre->Name = L"Filtre";
				 this->Filtre->Size = System::Drawing::Size(474, 93);
				 this->Filtre->TabIndex = 12;
				 this->Filtre->TabStop = false;
				 this->Filtre->Text = L"Filtre";
				 // 
				 // Kolo2
				 // 
				 this->Kolo2->AutoSize = true;
				 this->Kolo2->Location = System::Drawing::Point(412, 62);
				 this->Kolo2->Name = L"Kolo2";
				 this->Kolo2->Size = System::Drawing::Size(56, 17);
				 this->Kolo2->TabIndex = 15;
				 this->Kolo2->Text = L"2.Kolo";
				 this->Kolo2->UseVisualStyleBackColor = true;
				 // 
				 // Kolo1
				 // 
				 this->Kolo1->AutoSize = true;
				 this->Kolo1->Checked = true;
				 this->Kolo1->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->Kolo1->Location = System::Drawing::Point(412, 36);
				 this->Kolo1->Name = L"Kolo1";
				 this->Kolo1->Size = System::Drawing::Size(56, 17);
				 this->Kolo1->TabIndex = 14;
				 this->Kolo1->Text = L"1.Kolo";
				 this->Kolo1->UseVisualStyleBackColor = true;
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Location = System::Drawing::Point(266, 18);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(73, 13);
				 this->label7->TabIndex = 13;
				 this->label7->Text = L"Úèas volièov";
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Location = System::Drawing::Point(266, 63);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(27, 13);
				 this->label5->TabIndex = 12;
				 this->label5->Text = L"Do: ";
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Location = System::Drawing::Point(266, 37);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(27, 13);
				 this->label6->TabIndex = 11;
				 this->label6->Text = L"Od: ";
				 // 
				 // UcastDo
				 // 
				 this->UcastDo->Location = System::Drawing::Point(299, 60);
				 this->UcastDo->Name = L"UcastDo";
				 this->UcastDo->Size = System::Drawing::Size(100, 20);
				 this->UcastDo->TabIndex = 10;
				 // 
				 // UcastOd
				 // 
				 this->UcastOd->Location = System::Drawing::Point(299, 34);
				 this->UcastOd->Name = L"UcastOd";
				 this->UcastOd->Size = System::Drawing::Size(100, 20);
				 this->UcastOd->TabIndex = 9;
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(121, 63);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(27, 13);
				 this->label4->TabIndex = 8;
				 this->label4->Text = L"Do: ";
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Location = System::Drawing::Point(121, 37);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(27, 13);
				 this->label3->TabIndex = 7;
				 this->label3->Text = L"Od: ";
				 // 
				 // PocetDo
				 // 
				 this->PocetDo->Location = System::Drawing::Point(154, 60);
				 this->PocetDo->Name = L"PocetDo";
				 this->PocetDo->Size = System::Drawing::Size(100, 20);
				 this->PocetDo->TabIndex = 6;
				 // 
				 // PocetOd
				 // 
				 this->PocetOd->Location = System::Drawing::Point(154, 34);
				 this->PocetOd->Name = L"PocetOd";
				 this->PocetOd->Size = System::Drawing::Size(100, 20);
				 this->PocetOd->TabIndex = 4;
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(121, 16);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(72, 13);
				 this->label2->TabIndex = 3;
				 this->label2->Text = L"Poèet volièov";
				 // 
				 // NazovBox
				 // 
				 this->NazovBox->Location = System::Drawing::Point(9, 34);
				 this->NazovBox->Name = L"NazovBox";
				 this->NazovBox->Size = System::Drawing::Size(100, 20);
				 this->NazovBox->TabIndex = 2;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(6, 18);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(38, 13);
				 this->label1->TabIndex = 1;
				 this->label1->Text = L"Názov";
				 // 
				 // MainListView
				 // 
				 this->MainListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(15)
				 {
					 this->Nazov, this->NazovOkres,
						 this->NazovKraj, this->PocetVolicov1, this->PocetVolicov2, this->PocetVolicovS, this->Ucast1, this->Ucast2, this->VydaneObalky1,
						 this->VydaneObalky2, this->OdovzdaneObalky1, this->OdovzdaneObalky2, this->PlatneHlasy1, this->PlatneHlasy2, this->FilterHodnota
				 });
				 this->MainListView->FullRowSelect = true;
				 this->MainListView->GridLines = true;
				 this->MainListView->Location = System::Drawing::Point(12, 126);
				 this->MainListView->Name = L"MainListView";
				 this->MainListView->Size = System::Drawing::Size(1187, 466);
				 this->MainListView->TabIndex = 11;
				 this->MainListView->UseCompatibleStateImageBehavior = false;
				 this->MainListView->View = System::Windows::Forms::View::Details;
				 // 
				 // Nazov
				 // 
				 this->Nazov->Text = L"Názov";
				 this->Nazov->Width = 98;
				 // 
				 // NazovOkres
				 // 
				 this->NazovOkres->Text = L"Názov Okresu";
				 this->NazovOkres->Width = 102;
				 // 
				 // NazovKraj
				 // 
				 this->NazovKraj->Text = L"Názov Kraju";
				 this->NazovKraj->Width = 73;
				 // 
				 // PocetVolicov1
				 // 
				 this->PocetVolicov1->Text = L"1.Poèet Volièov";
				 this->PocetVolicov1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->PocetVolicov1->Width = 89;
				 // 
				 // PocetVolicov2
				 // 
				 this->PocetVolicov2->Text = L"2.Poèet Volièov";
				 this->PocetVolicov2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->PocetVolicov2->Width = 87;
				 // 
				 // PocetVolicovS
				 // 
				 this->PocetVolicovS->Text = L"Spolu";
				 this->PocetVolicovS->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 // 
				 // Ucast1
				 // 
				 this->Ucast1->Text = L"1.Úèas";
				 this->Ucast1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->Ucast1->Width = 51;
				 // 
				 // Ucast2
				 // 
				 this->Ucast2->Text = L"2.Úèas";
				 this->Ucast2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->Ucast2->Width = 50;
				 // 
				 // VydaneObalky1
				 // 
				 this->VydaneObalky1->Text = L"1.Vydané obálky";
				 this->VydaneObalky1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->VydaneObalky1->Width = 92;
				 // 
				 // VydaneObalky2
				 // 
				 this->VydaneObalky2->Text = L"2.Vydané obálky";
				 this->VydaneObalky2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->VydaneObalky2->Width = 92;
				 // 
				 // OdovzdaneObalky1
				 // 
				 this->OdovzdaneObalky1->Text = L"1.Odovzd. obálky";
				 this->OdovzdaneObalky1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->OdovzdaneObalky1->Width = 96;
				 // 
				 // OdovzdaneObalky2
				 // 
				 this->OdovzdaneObalky2->Text = L"2.Odovzd. obálky";
				 this->OdovzdaneObalky2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->OdovzdaneObalky2->Width = 94;
				 // 
				 // PlatneHlasy1
				 // 
				 this->PlatneHlasy1->Text = L"1.Hlasy";
				 this->PlatneHlasy1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->PlatneHlasy1->Width = 47;
				 // 
				 // PlatneHlasy2
				 // 
				 this->PlatneHlasy2->Text = L"2.Hlasy";
				 this->PlatneHlasy2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->PlatneHlasy2->Width = 49;
				 // 
				 // FilterHodnota
				 // 
				 this->FilterHodnota->Text = L"Filter";
				 this->FilterHodnota->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				 this->FilterHodnota->Width = 86;
				 // 
				 // SettingObec
				 // 
				 this->SettingObec->AutoSize = true;
				 this->SettingObec->Checked = true;
				 this->SettingObec->Location = System::Drawing::Point(7, 20);
				 this->SettingObec->Name = L"SettingObec";
				 this->SettingObec->Size = System::Drawing::Size(51, 17);
				 this->SettingObec->TabIndex = 14;
				 this->SettingObec->TabStop = true;
				 this->SettingObec->Text = L"Obec";
				 this->SettingObec->UseVisualStyleBackColor = true;
				 // 
				 // SettingOkres
				 // 
				 this->SettingOkres->AutoSize = true;
				 this->SettingOkres->Location = System::Drawing::Point(7, 42);
				 this->SettingOkres->Name = L"SettingOkres";
				 this->SettingOkres->Size = System::Drawing::Size(53, 17);
				 this->SettingOkres->TabIndex = 15;
				 this->SettingOkres->Text = L"Okres";
				 this->SettingOkres->UseVisualStyleBackColor = true;
				 // 
				 // SettingKraj
				 // 
				 this->SettingKraj->AutoSize = true;
				 this->SettingKraj->Location = System::Drawing::Point(6, 64);
				 this->SettingKraj->Name = L"SettingKraj";
				 this->SettingKraj->Size = System::Drawing::Size(43, 17);
				 this->SettingKraj->TabIndex = 16;
				 this->SettingKraj->Text = L"Kraj";
				 this->SettingKraj->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 this->SettingKraj->UseVisualStyleBackColor = true;
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->Location = System::Drawing::Point(728, 27);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(87, 13);
				 this->label8->TabIndex = 16;
				 this->label8->Text = L"Príslušnos obce";
				 // 
				 // PrislusnostBox
				 // 
				 this->PrislusnostBox->Location = System::Drawing::Point(731, 47);
				 this->PrislusnostBox->Name = L"PrislusnostBox";
				 this->PrislusnostBox->Size = System::Drawing::Size(128, 20);
				 this->PrislusnostBox->TabIndex = 17;
				 // 
				 // groupVypis
				 // 
				 this->groupVypis->Controls->Add(this->SettingOkres);
				 this->groupVypis->Controls->Add(this->SettingObec);
				 this->groupVypis->Controls->Add(this->SettingKraj);
				 this->groupVypis->Location = System::Drawing::Point(649, 28);
				 this->groupVypis->Name = L"groupVypis";
				 this->groupVypis->Size = System::Drawing::Size(72, 92);
				 this->groupVypis->TabIndex = 18;
				 this->groupVypis->TabStop = false;
				 this->groupVypis->Text = L"Výpis";
				 // 
				 // MainForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1211, 604);
				 this->Controls->Add(this->groupVypis);
				 this->Controls->Add(this->PrislusnostBox);
				 this->Controls->Add(this->label8);
				 this->Controls->Add(this->Zoradenie);
				 this->Controls->Add(this->Filtre);
				 this->Controls->Add(this->MainListView);
				 this->Controls->Add(this->menuStrip1);
				 this->MainMenuStrip = this->menuStrip1;
				 this->Name = L"MainForm";
				 this->Text = L"Semestralna Praca 2";
				 this->menuStrip1->ResumeLayout(false);
				 this->menuStrip1->PerformLayout();
				 this->Zoradenie->ResumeLayout(false);
				 this->Zoradenie->PerformLayout();
				 this->Filtre->ResumeLayout(false);
				 this->Filtre->PerformLayout();
				 this->groupVypis->ResumeLayout(false);
				 this->groupVypis->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void ukoncitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Application::Exit();
	}
	private: System::Void ZoradenieButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Filtruj();
	}
};
}

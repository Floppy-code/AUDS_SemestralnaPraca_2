#include "stdafx.h"
#include "MainForm.h"
#include "Filter.h"
#include "structures/table/sorted_sequence_table.h"
#include "structures/list/array_list.h"
#include "Quick_sort.h"
#include <iostream>
#include <string>
#include <locale>
#include <chrono>

using namespace ObertaJurajAUS2;

void ObertaJurajAUS2::MainForm::Filtruj()
{
	std::wstring nazov = msclr::interop::marshal_as<std::wstring>(NazovBox->Text);
	std::wstring pocetVolicOd = msclr::interop::marshal_as<std::wstring>(PocetOd->Text);
	std::wstring pocetVolicDo = msclr::interop::marshal_as<std::wstring>(PocetDo->Text);
	std::wstring ucastVolicOd = msclr::interop::marshal_as<std::wstring>(UcastOd->Text);
	std::wstring ucastVolicDo = msclr::interop::marshal_as<std::wstring>(UcastDo->Text);
	int kolo = 3;
	if (Kolo1->Checked == true && Kolo2->Checked == true) { kolo = 3; }
	else if (Kolo1->Checked == true) { kolo = 1; }
	else if (Kolo2->Checked == true) { kolo = 2; }

	bool smer = !ZoradZostupne->Checked;
	if (PrislusnostBox->Text != gcnew System::String(""))
	{
		std::wstring prislusnost = msclr::interop::marshal_as<std::wstring>(PrislusnostBox->Text);
		structures::ArrayList<Obec*>* obce = dynamic_cast<structures::ArrayList<Obec*>*>(m_manazer->FilterPrislusnost(prislusnost, pocetVolicOd, pocetVolicDo, ucastVolicOd, ucastVolicDo, kolo));
		if (obce->size() > 0)
		{
			if (ZoradNazov->Checked)
			{
				KriteriumNazov<std::wstring, Obec*>* kriteriumNazov = new KriteriumNazov<std::wstring, Obec*>;
				QuickSort<std::wstring, Obec*>* qSortNazov = new QuickSort<std::wstring, Obec*>;
				qSortNazov->SortString(*obce, *kriteriumNazov, smer);
				delete kriteriumNazov;
				delete qSortNazov;
			}
			else if (ZoradVolici->Checked)
			{
				KriteriumVolici<int, Obec*>* kriteriumVolici = new KriteriumVolici<int, Obec*>;
				kriteriumVolici->SetKolo(kolo);
				QuickSort<int, Obec*>* qSortVolici = new QuickSort<int, Obec*>;
				qSortVolici->Sort(*obce, *kriteriumVolici, smer);
				delete kriteriumVolici;
				delete qSortVolici;
			}
			else if (ZoradUcast->Checked)
			{
				KriteriumUcast<double, Obec*>* kriteriumUcast = new KriteriumUcast<double, Obec*>;
				kriteriumUcast->SetKolo(kolo);
				QuickSort<double, Obec*>* qSortUcast = new QuickSort<double, Obec*>;
				qSortUcast->Sort(*obce, *kriteriumUcast, smer);
				delete kriteriumUcast;
				delete qSortUcast;
			}
		}
		this->VypisObce(obce);
		delete obce;
	}
	else if (SettingObec->Checked)
	{
		structures::ArrayList<Obec*>* obce = dynamic_cast<structures::ArrayList<Obec*>*>(m_manazer->FilterObce(nazov, pocetVolicOd, pocetVolicDo, ucastVolicOd, ucastVolicDo, kolo));
		if (obce->size() != 0)
		{
			if (ZoradNazov->Checked)
			{
				KriteriumNazov<std::wstring, Obec*>* kriteriumNazov = new KriteriumNazov<std::wstring, Obec*>;
				QuickSort<std::wstring, Obec*>* qSortNazov = new QuickSort<std::wstring, Obec*>;
				qSortNazov->SortString(*obce, *kriteriumNazov, smer);
				delete kriteriumNazov;
				delete qSortNazov;
			}
			else if (ZoradVolici->Checked)
			{
				KriteriumVolici<int, Obec*>* kriteriumVolici = new KriteriumVolici<int, Obec*>;
				kriteriumVolici->SetKolo(kolo);
				QuickSort<int, Obec*>* qSortVolici = new QuickSort<int, Obec*>;
				qSortVolici->Sort(*obce, *kriteriumVolici, smer);
				delete kriteriumVolici;
				delete qSortVolici;
			}
			else if (ZoradUcast->Checked)
			{
				KriteriumUcast<double, Obec*>* kriteriumUcast = new KriteriumUcast<double, Obec*>;
				kriteriumUcast->SetKolo(kolo);
				QuickSort<double, Obec*>* qSortUcast = new QuickSort<double, Obec*>;
				qSortUcast->Sort(*obce, *kriteriumUcast, smer);
				delete kriteriumUcast;
				delete qSortUcast;
			}
		}
		this->VypisObce(obce);
		delete obce;
	}
	else if (SettingOkres->Checked)
	{
		structures::ArrayList<Oblast*>* okresy = dynamic_cast<structures::ArrayList<Oblast*>*>(m_manazer->FilterOkresy(nazov, pocetVolicOd, pocetVolicDo, ucastVolicOd, ucastVolicDo, kolo));
		if (okresy->size() != 0)
		{
			if (ZoradNazov->Checked)
			{
				KriteriumNazov<std::wstring, Oblast*>* kriteriumNazov = new KriteriumNazov<std::wstring, Oblast*>;
				QuickSort<std::wstring, Oblast*>* qSortNazov = new QuickSort<std::wstring, Oblast*>;
				qSortNazov->SortString(*okresy, *kriteriumNazov, smer);
				delete kriteriumNazov;
				delete qSortNazov;
			}
			else if (ZoradVolici->Checked)
			{
				KriteriumVolici<int, Oblast*>* kriteriumVolici = new KriteriumVolici<int, Oblast*>;
				kriteriumVolici->SetKolo(kolo);
				QuickSort<int, Oblast*>* qSortVolici = new QuickSort<int, Oblast*>;
				qSortVolici->Sort(*okresy, *kriteriumVolici, smer);
				delete kriteriumVolici;
				delete qSortVolici;
			}
			else if (ZoradUcast->Checked)
			{
				KriteriumUcast<double, Oblast*>* kriteriumUcast = new KriteriumUcast<double, Oblast*>;
				kriteriumUcast->SetKolo(kolo);
				QuickSort<double, Oblast*>* qSortUcast = new QuickSort<double, Oblast*>;
				qSortUcast->Sort(*okresy, *kriteriumUcast, smer);
				delete kriteriumUcast;
				delete qSortUcast;
			}
		}
		this->Vypis(okresy);
		delete okresy;
	}
	else if (SettingKraj->Checked)
	{
		structures::ArrayList<Oblast*>* kraje = dynamic_cast<structures::ArrayList<Oblast*>*>(m_manazer->FilterKraje(nazov, pocetVolicOd, pocetVolicDo, ucastVolicOd, ucastVolicDo, kolo));
		if (kraje->size() != 0)
		{
			if (ZoradNazov->Checked)
			{
				KriteriumNazov<std::wstring, Oblast*>* kriteriumNazov = new KriteriumNazov<std::wstring, Oblast*>;
				QuickSort<std::wstring, Oblast*>* qSortNazov = new QuickSort<std::wstring, Oblast*>;
				qSortNazov->SortString(*kraje, *kriteriumNazov, smer);
				delete kriteriumNazov;
				delete qSortNazov;
			}
			else if (ZoradVolici->Checked)
			{
				KriteriumVolici<int, Oblast*>* kriteriumVolici = new KriteriumVolici<int, Oblast*>;
				kriteriumVolici->SetKolo(kolo);
				QuickSort<int, Oblast*>* qSortVolici = new QuickSort<int, Oblast*>;
				qSortVolici->Sort(*kraje, *kriteriumVolici, smer);
				delete kriteriumVolici;
				delete qSortVolici;
			}
			else if (ZoradUcast->Checked)
			{
				KriteriumUcast<double, Oblast*>* kriteriumUcast = new KriteriumUcast<double, Oblast*>;
				kriteriumUcast->SetKolo(kolo);
				QuickSort<double, Oblast*>* qSortUcast = new QuickSort<double, Oblast*>;
				qSortUcast->Sort(*kraje, *kriteriumUcast, smer);
				delete kriteriumUcast;
				delete qSortUcast;
			}
		}
		this->Vypis(kraje);
		delete kraje;
	}
}

void ObertaJurajAUS2::MainForm::Vypis(structures::List<Oblast*>* listToShow)
{
	int kolo = 3;
	if (Kolo1->Checked == true && Kolo2->Checked == true) { kolo = 3; }
	else if (Kolo1->Checked == true) { kolo = 1; }
	else if (Kolo2->Checked == true) { kolo = 2; }

	//KriteriumNazov<std::wstring, Obec*>* nazovObec = new KriteriumNazov<std::wstring, Obec*>;
	KriteriumNazov<std::wstring, Oblast*>* nazovOblast = new KriteriumNazov<std::wstring, Oblast*>;
	KriteriumVolici<int, Oblast*>* volici = new KriteriumVolici<int, Oblast*>;
	volici->SetKolo(1);
	KriteriumVydaneObalky<int, Oblast*>* vydaneObalky = new KriteriumVydaneObalky<int, Oblast*>;
	vydaneObalky->SetKolo(1);
	KriteriumUcast<double, Oblast*>* ucast = new KriteriumUcast<double, Oblast*>;
	ucast->SetKolo(1);
	KriteriumOdovzdaneObalky<int, Oblast*>* odovzdaneObalky = new KriteriumOdovzdaneObalky<int, Oblast*>;
	odovzdaneObalky->SetKolo(1);
	KriteriumHlasyOdovzdane<int, Oblast*>* odovzdaneHlasy = new KriteriumHlasyOdovzdane<int, Oblast*>;
	odovzdaneHlasy->SetKolo(1);

	MainListView->Items->Clear();	//Vycistenie ListView

	if (SettingOkres->Checked)		//Vypis okresu do ListView
	{
		for (auto okres : *listToShow)
		{
			Oblast* kraj = okres->GetVyssiaJednotka();

			ListViewItem^ item = gcnew ListViewItem(gcnew System::String(""));
			item->SubItems->Add(gcnew System::String(nazovOblast->Ohodnot(okres).c_str()));
			item->SubItems->Add(gcnew System::String(nazovOblast->Ohodnot(kraj).c_str()));
			volici->SetKolo(1);
			item->SubItems->Add(gcnew System::String(volici->Ohodnot(okres).ToString("### ### ###")));
			volici->SetKolo(2);
			item->SubItems->Add(gcnew System::String(volici->Ohodnot(okres).ToString("### ### ###")));
			volici->SetKolo(3);
			item->SubItems->Add(gcnew System::String(volici->Ohodnot(okres).ToString("### ### ###")));
			ucast->SetKolo(1);
			item->SubItems->Add(gcnew System::String(ucast->Ohodnot(okres).ToString("#.##") + "%"));
			ucast->SetKolo(2);
			item->SubItems->Add(gcnew System::String(ucast->Ohodnot(okres).ToString("#.##") + "%"));
			vydaneObalky->SetKolo(1);
			item->SubItems->Add(gcnew System::String(vydaneObalky->Ohodnot(okres).ToString("### ### ###")));
			vydaneObalky->SetKolo(2);
			item->SubItems->Add(gcnew System::String(vydaneObalky->Ohodnot(okres).ToString("### ### ###")));
			odovzdaneObalky->SetKolo(1);
			item->SubItems->Add(gcnew System::String(odovzdaneObalky->Ohodnot(okres).ToString("### ### ###")));
			odovzdaneObalky->SetKolo(2);
			item->SubItems->Add(gcnew System::String(odovzdaneObalky->Ohodnot(okres).ToString("### ### ###")));
			odovzdaneHlasy->SetKolo(1);
			item->SubItems->Add(gcnew System::String(odovzdaneHlasy->Ohodnot(okres).ToString("### ### ###")));
			odovzdaneHlasy->SetKolo(2);
			item->SubItems->Add(gcnew System::String(odovzdaneHlasy->Ohodnot(okres).ToString("### ### ###")));
			if (ZoradNazov->Checked)
			{
				item->SubItems->Add(gcnew System::String(nazovOblast->Ohodnot(okres).c_str()));
			}
			else if (ZoradVolici->Checked)
			{
				switch (kolo)
				{
				case 1:
					volici->SetKolo(1);
					break;
				case 2:
					volici->SetKolo(2);
					break;
				case 3:
					volici->SetKolo(3);
					break;
				}
				item->SubItems->Add(gcnew System::String(volici->Ohodnot(okres).ToString("### ### ###")));
			}
			else if (ZoradUcast->Checked)
			{
				switch (kolo)
				{
				case 1:
					ucast->SetKolo(1);
					break;
				case 2:
					ucast->SetKolo(2);
					break;
				}
				item->SubItems->Add(gcnew System::String(ucast->Ohodnot(okres).ToString("#.##") + "%"));
			}
			MainListView->Items->Add(item);
		}
	}
	else if (SettingKraj->Checked)	//Vypis kraju do List View
	{
		for (auto kraj : *listToShow)
		{
			ListViewItem^ item = gcnew ListViewItem(gcnew System::String(""));
			item->SubItems->Add(gcnew System::String(""));
			item->SubItems->Add(gcnew System::String(nazovOblast->Ohodnot(kraj).c_str()));
			volici->SetKolo(1);
			item->SubItems->Add(gcnew System::String(volici->Ohodnot(kraj).ToString("### ### ###")));
			volici->SetKolo(2);
			item->SubItems->Add(gcnew System::String(volici->Ohodnot(kraj).ToString("### ### ###")));
			volici->SetKolo(3);
			item->SubItems->Add(gcnew System::String(volici->Ohodnot(kraj).ToString("### ### ###")));
			ucast->SetKolo(1);
			item->SubItems->Add(gcnew System::String(ucast->Ohodnot(kraj).ToString("#.##") + "%"));
			ucast->SetKolo(2);
			item->SubItems->Add(gcnew System::String(ucast->Ohodnot(kraj).ToString("#.##") + "%"));
			vydaneObalky->SetKolo(1);
			item->SubItems->Add(gcnew System::String(vydaneObalky->Ohodnot(kraj).ToString("### ### ###")));
			vydaneObalky->SetKolo(2);
			item->SubItems->Add(gcnew System::String(vydaneObalky->Ohodnot(kraj).ToString("### ### ###")));
			odovzdaneObalky->SetKolo(1);
			item->SubItems->Add(gcnew System::String(odovzdaneObalky->Ohodnot(kraj).ToString("### ### ###")));
			odovzdaneObalky->SetKolo(2);
			item->SubItems->Add(gcnew System::String(odovzdaneObalky->Ohodnot(kraj).ToString("### ### ###")));
			odovzdaneHlasy->SetKolo(1);
			item->SubItems->Add(gcnew System::String(odovzdaneHlasy->Ohodnot(kraj).ToString("### ### ###")));
			odovzdaneHlasy->SetKolo(2);
			item->SubItems->Add(gcnew System::String(odovzdaneHlasy->Ohodnot(kraj).ToString("### ### ###")));

			if (ZoradNazov->Checked)
			{
				item->SubItems->Add(gcnew System::String(nazovOblast->Ohodnot(kraj).c_str()));
			}
			else if (ZoradVolici->Checked)
			{
				switch (kolo)	//1 - prve kolo, 2 - druhe kolo, 3 - sucet oboch kol (v pripade ucasti musi byt ucast v intervale pre obe kola)
				{
				case 1:
					volici->SetKolo(1);
					break;
				case 2:
					volici->SetKolo(2);
					break;
				case 3:
					volici->SetKolo(3);
					break;
				}
				item->SubItems->Add(gcnew System::String(volici->Ohodnot(kraj).ToString("### ### ###")));
			}
			else if (ZoradUcast->Checked)
			{
				switch (kolo)
				{
				case 1:
					ucast->SetKolo(1);
					break;
				case 2:
					ucast->SetKolo(2);
					break;
				}
				item->SubItems->Add(gcnew System::String(ucast->Ohodnot(kraj).ToString("#.##") + "%"));
			}
			MainListView->Items->Add(item);
		}
	}

	delete nazovOblast;
	delete volici;
	delete vydaneObalky;
	delete ucast;
	delete odovzdaneObalky;
	delete odovzdaneHlasy;
}

void ObertaJurajAUS2::MainForm::VypisObce(structures::List<Obec*>* listToShow)
{
	int kolo = 3;
	if (Kolo1->Checked == true && Kolo2->Checked == true) { kolo = 3; }
	else if (Kolo1->Checked == true) { kolo = 1; }
	else if (Kolo2->Checked == true) { kolo = 2; }

	KriteriumNazov<std::wstring, Obec*>* nazovObec = new KriteriumNazov<std::wstring, Obec*>;
	KriteriumNazov<std::wstring, Oblast*>* nazovOblast = new KriteriumNazov<std::wstring, Oblast*>;
	KriteriumVolici<int, Obec*>* volici = new KriteriumVolici<int, Obec*>;
	KriteriumVydaneObalky<int, Obec*>* vydaneObalky = new KriteriumVydaneObalky<int, Obec*>;
	KriteriumUcast<double, Obec*>* ucast = new KriteriumUcast<double, Obec*>;
	KriteriumOdovzdaneObalky<int, Obec*>* odovzdaneObalky = new KriteriumOdovzdaneObalky<int, Obec*>;
	KriteriumHlasyOdovzdane<int, Obec*>* odovzdaneHlasy = new KriteriumHlasyOdovzdane<int, Obec*>;

	MainListView->Items->Clear();	//Vycistenie ListView
	for (auto obec : *listToShow)
	{
		Oblast* okres = obec->GetOkres();
		Oblast* kraj = obec->GetKraj();

		ListViewItem^ item = gcnew ListViewItem(gcnew System::String(obec->GetNazov().c_str()));
		item->SubItems->Add(gcnew System::String(nazovOblast->Ohodnot(okres).c_str()));
		item->SubItems->Add(gcnew System::String(nazovOblast->Ohodnot(kraj).c_str()));
		volici->SetKolo(1);
		item->SubItems->Add(gcnew System::String(volici->Ohodnot(obec).ToString("### ###")));
		volici->SetKolo(2);
		item->SubItems->Add(gcnew System::String(volici->Ohodnot(obec).ToString("### ###")));
		volici->SetKolo(3);
		item->SubItems->Add(gcnew System::String(volici->Ohodnot(obec).ToString("### ###")));
		ucast->SetKolo(1);
		item->SubItems->Add(gcnew System::String(ucast->Ohodnot(obec).ToString("#.##") + "%"));
		ucast->SetKolo(2);
		item->SubItems->Add(gcnew System::String(ucast->Ohodnot(obec).ToString("#.##") + "%"));
		vydaneObalky->SetKolo(1);
		item->SubItems->Add(gcnew System::String(vydaneObalky->Ohodnot(obec).ToString("### ###")));
		vydaneObalky->SetKolo(2);
		item->SubItems->Add(gcnew System::String(vydaneObalky->Ohodnot(obec).ToString("### ###")));
		odovzdaneObalky->SetKolo(1);
		item->SubItems->Add(gcnew System::String(odovzdaneObalky->Ohodnot(obec).ToString("### ###")));
		odovzdaneObalky->SetKolo(2);
		item->SubItems->Add(gcnew System::String(odovzdaneObalky->Ohodnot(obec).ToString("### ###")));
		odovzdaneHlasy->SetKolo(1);
		item->SubItems->Add(gcnew System::String(odovzdaneHlasy->Ohodnot(obec).ToString("### ###")));
		odovzdaneHlasy->SetKolo(2);
		item->SubItems->Add(gcnew System::String(odovzdaneHlasy->Ohodnot(obec).ToString("### ###")));

		if (ZoradNazov->Checked)
		{
			item->SubItems->Add(gcnew System::String(nazovObec->Ohodnot(obec).c_str()));
		}
		else if (ZoradVolici->Checked)
		{
			switch (kolo)
			{
			case 1:
				volici->SetKolo(1);
				break;
			case 2:
				volici->SetKolo(2);
				break;
			case 3:
				volici->SetKolo(3);
				break;

			}
			item->SubItems->Add(gcnew System::String(volici->Ohodnot(obec).ToString("### ### ###")));
		}
		else if (ZoradUcast->Checked)
		{
			switch (kolo)
			{
			case 1:
				ucast->SetKolo(1);
				break;
			case 2:
				ucast->SetKolo(2);
				break;
			}
			item->SubItems->Add(gcnew System::String(ucast->Ohodnot(obec).ToString("#.##") + "%"));
		}
		MainListView->Items->Add(item);
	}

	delete nazovObec;
	delete nazovOblast;
	delete volici;
	delete vydaneObalky;
	delete ucast;
	delete odovzdaneObalky;
	delete odovzdaneHlasy;
}
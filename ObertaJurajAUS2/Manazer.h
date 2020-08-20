#pragma once
#include <fstream>
#include <iostream>
#include "structures/table/sorted_sequence_table.h"
#include "structures/list/array_list.h"
#include "Obec.h"
#include "Oblast.h"
#include "Kriterium.h"


class Manazer
{
public:
	Manazer();
	~Manazer();
	
	void NacitajDataKraj();
	void NacitajDataOkres();
	void NacitajDataObec();

	structures::List<Obec*>* FilterObce(std::wstring nazov, std::wstring pocetOd, std::wstring pocetDo, std::wstring ucastOd, std::wstring ucastDo, int kolo);
	structures::List<Oblast*>* FilterOkresy(std::wstring nazov, std::wstring pocetOd, std::wstring pocetDo, std::wstring ucastOd, std::wstring ucastDo, int kolo);
	structures::List<Oblast*>* FilterKraje(std::wstring nazov, std::wstring pocetOd, std::wstring pocetDo, std::wstring ucastOd, std::wstring ucastDo, int kolo);
	structures::List<Obec*>* FilterPrislusnost(std::wstring nazov, std::wstring pocetOd, std::wstring pocetDo, std::wstring ucastOd, std::wstring ucastDo, int kolo);

private:
	structures::SortedSequenceTable<int, Obec*>* m_obce;
	structures::SortedSequenceTable<int, Oblast*>* m_okresy;
	structures::SortedSequenceTable<int, Oblast*>* m_kraje;

	structures::SortedSequenceTable<std::wstring, Oblast*>* m_nOkresy;
	structures::SortedSequenceTable<std::wstring, Oblast*>* m_nKraje;
};
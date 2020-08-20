#include <sstream>
#include <string>
#include <algorithm>
#include <codecvt>
#include "Manazer.h"
#include "Filter.h"

Manazer::Manazer()
{
	m_obce = new structures::SortedSequenceTable<int, Obec*>();
	m_okresy = new structures::SortedSequenceTable<int, Oblast*>();
	m_kraje = new structures::SortedSequenceTable<int, Oblast*>();

	m_nOkresy = new structures::SortedSequenceTable<std::wstring, Oblast*>();
	m_nKraje = new structures::SortedSequenceTable<std::wstring, Oblast*>();
}

Manazer::~Manazer()
{
	for (auto objekt : *m_obce)
	{
		delete objekt->accessData();
	}
	for (auto objekt : *m_okresy)
	{
		delete objekt->accessData();
	}
	for (auto objekt : *m_kraje)
	{
		delete objekt->accessData();
	}
	delete m_obce;
	delete m_okresy;
	delete m_kraje;

	delete m_nOkresy;
	delete m_nKraje;
}

void Manazer::NacitajDataKraj()
{
	const std::string Kolo1Kraje = "res/1Kolo/tab02a.csv";
	const std::string Kolo2Kraje = "res/2Kolo/tab02a.csv";

	std::string fileToLoad;

	for (size_t j = 1; j < 3; j++)	//j - kolo ktoré sa naèítava
	{
		j == 1 ? fileToLoad = Kolo1Kraje : fileToLoad = Kolo2Kraje;
		std::wifstream input(fileToLoad);
		input.imbue(std::locale("sk_SK"));

		if (input.is_open())
		{
			while (!input.eof())
			{
				std::wstring riadok;
				std::getline(input, riadok);
				if (riadok.length() > 5)	//Kontrola èi je riadok použite¾ný
				{
					std::wstringstream stringStr(riadok);	//Delenie textu
					std::wstring token;

					int kod, pocetVolicov, pocetObalokVyd, pocetObalokOdovzd, pocetHlasovKand;
					double ucastVolicov;
					std::wstring nazov;

					int const k_kodKraju = 0;
					int const k_nazovKraju = 1;
					int const k_pocetVolicov = 3;
					int const k_pocetObalokVyd = 4;
					int const k_ucast = 5;
					int const k_pocetObalokOdo = 6;
					int const k_pocetHlasov = 8;

					for (size_t i = 0; std::getline(stringStr, token, L';'); i++)
					{
						switch (i)
						{
						case k_kodKraju:
							kod = std::stoi(token);
							break;
						case k_nazovKraju:
							nazov = token;
							break;
						case k_pocetVolicov:
							pocetVolicov = std::stoi(token);
							break;
						case k_pocetObalokVyd:
							pocetObalokVyd = std::stoi(token);
							break;
						case k_ucast:
							std::replace(token.begin(), token.end(), ',', '.');
							ucastVolicov = std::stod(token);
							break;
						case k_pocetObalokOdo:
							pocetObalokOdovzd = std::stoi(token);
							break;
						case k_pocetHlasov:
							pocetHlasovKand = std::stoi(token);
							break;
						}
					}
					if (j == 1)
					{
						Oblast* o = new Oblast(kod, nazov, 0);
						o->SetPocetOdovzdanychHlasov(1, pocetHlasovKand);
						o->SetPocetOdovzdanychObalok(1, pocetObalokOdovzd);
						o->SetPocetVydanychObalok(1, pocetObalokVyd);
						o->SetPocetZapisanychVolicov(1, pocetVolicov);
						o->SetUcastVolicov(1, ucastVolicov);
						m_kraje->insert(kod, o);
					}
					else
					{
						Oblast* o;
						m_kraje->tryFind(kod, o);
						o->SetPocetOdovzdanychHlasov(2, pocetHlasovKand);
						o->SetPocetOdovzdanychObalok(2, pocetObalokOdovzd);
						o->SetPocetVydanychObalok(2, pocetObalokVyd);
						o->SetPocetZapisanychVolicov(2, pocetVolicov);
						o->SetUcastVolicov(2, ucastVolicov);
					}
				}
			}
		}
	}

	for (auto kraj : *m_kraje)
	{
		m_nKraje->insert(kraj->accessData()->GetNazov(), kraj->accessData());
	}

	//Debug
	//std::wcout << "Nacitanych: " << m_kraje->size() << " krajov" << "\n";
}

void Manazer::NacitajDataOkres()
{
	const std::string Kolo1Okresy = "res/1Kolo/tab02c.csv";
	const std::string Kolo2Okresy = "res/2Kolo/tab02c.csv";

	std::string fileToLoad;

	for (size_t j = 1; j < 3; j++)
	{
		j == 1 ? fileToLoad = Kolo1Okresy : fileToLoad = Kolo2Okresy;
		std::wifstream input(fileToLoad);
		input.imbue(std::locale("sk_SK"));

		if (input.is_open())
		{
			while (!input.eof())
			{
				std::wstring riadok;
				std::getline(input, riadok);
				if (riadok.length() > 5)
				{
					std::wstringstream stringStr(riadok);	//Delenie textu
					std::wstring token;

					int kod, pocetVolicov, pocetObalokVyd, pocetObalokOdovzd, pocetHlasovKand;
					double ucastVolicov;
					std::wstring nazov;

					const int k_kodOkresu = 4;
					const int k_nazovOkresu = 5;
					const int k_pocetVolicov = 7;
					const int k_pocetObalokVyd = 8;
					const int k_ucast = 9;
					const int k_pocetObalokOdo = 10;
					const int k_pocetHlasov = 12;

					for (size_t i = 0; std::getline(stringStr, token, L';'); i++)
					{
						switch (i)
						{
						case k_kodOkresu:
							kod = std::stoi(token);
							break;
						case k_nazovOkresu:
							nazov = token;
							break;
						case k_pocetVolicov:
							pocetVolicov = std::stoi(token);
							break;
						case k_pocetObalokVyd:
							pocetObalokVyd = std::stoi(token);
							break;
						case k_ucast:
							std::replace(token.begin(), token.end(), ',', '.');
							ucastVolicov = std::stod(token);
							break;
						case k_pocetObalokOdo:
							pocetObalokOdovzd = std::stoi(token);
							break;
						case k_pocetHlasov:
							pocetHlasovKand = std::stoi(token);
							break;
						}
					}
					if (j == 1)
					{
						Oblast* k;
						Oblast* o = new Oblast(kod, nazov, 1);
						m_kraje->tryFind((kod / 100), k);
						o->SetVyssiaJednotka(k);
						o->SetPocetOdovzdanychHlasov(1, pocetHlasovKand);
						o->SetPocetOdovzdanychObalok(1, pocetObalokOdovzd);
						o->SetPocetVydanychObalok(1, pocetObalokVyd);
						o->SetPocetZapisanychVolicov(1, pocetVolicov);
						o->SetUcastVolicov(1, ucastVolicov);
						m_okresy->insert(kod, o);
					}
					else
					{
						Oblast* o;
						m_okresy->tryFind(kod, o);
						o->SetPocetOdovzdanychHlasov(2, pocetHlasovKand);
						o->SetPocetOdovzdanychObalok(2, pocetObalokOdovzd);
						o->SetPocetVydanychObalok(2, pocetObalokVyd);
						o->SetPocetZapisanychVolicov(2, pocetVolicov);
						o->SetUcastVolicov(2, ucastVolicov);
					}
				}
			}
		}
	}

	for (auto okres : *m_okresy)
	{
		m_nOkresy->insert(okres->accessData()->GetNazov(), okres->accessData());
	}

	//Debug
	//std::wcout << "Nacitanych: " << m_okresy->size() << " okresov" << "\n";
}

void Manazer::NacitajDataObec()
{
	const std::string Kolo1Obce = "res/1Kolo/tab02d.csv";
	const std::string Kolo2Obce = "res/2Kolo/tab02d.csv";

	std::string fileToLoad;

	for (size_t j = 1; j < 3; j++)
	{
		j == 1 ? fileToLoad = Kolo1Obce : fileToLoad = Kolo2Obce;
		std::wifstream input(fileToLoad);
		input.imbue(std::locale("sk_SK"));

		if (input.is_open())
		{
			while (!input.eof())
			{
				std::wstring riadok;
				std::getline(input, riadok);
				if (riadok.length() > 5)
				{
					std::wstringstream stringStr(riadok);	//Delenie textu
					std::wstring token;

					int kod, pocetVolicov, pocetObalokVyd, pocetObalokOdovzd, pocetHlasovKand, kod_okres, kod_kraj;
					double ucastVolicov;
					std::wstring nazov;

					const int k_kodKraja = 0;
					const int k_kodOkresu = 4;
					const int k_kodObce = 6;
					const int k_nazovObce = 7;
					const int k_pocetVolicov = 9;
					const int k_pocetObalokVyd = 10;
					const int k_ucast = 11;
					const int k_pocetObalokOdo = 12;
					const int k_pocetHlasov = 14;

					for (size_t i = 0; std::getline(stringStr, token, L';'); i++)
					{
						switch (i)
						{
						case k_kodKraja:
							kod_kraj = std::stoi(token);
							break;
						case k_kodOkresu:
							kod_okres = std::stoi(token);
							break;
						case k_kodObce:
							kod = std::stoi(token);
							break;
						case k_nazovObce:
							nazov = token;
							break;
						case k_pocetVolicov:
							pocetVolicov = std::stoi(token);
							break;
						case k_pocetObalokVyd:
							pocetObalokVyd = std::stoi(token);
							break;
						case k_ucast:
							std::replace(token.begin(), token.end(), ',', '.');
							ucastVolicov = std::stod(token);
							break;
						case k_pocetObalokOdo:
							pocetObalokOdovzd = std::stoi(token);
							break;
						case k_pocetHlasov:
							pocetHlasovKand = std::stoi(token);
							break;
						}
					}
					if (j == 1)
					{
						Oblast* kraj;
						m_kraje->tryFind(kod_kraj, kraj);
						Oblast* okres;
						m_okresy->tryFind(kod_okres, okres);
						Obec* o = new Obec(kod, nazov, kraj, okres);
						o->SetPocetOdovzdanychHlasov(1, pocetHlasovKand);
						o->SetPocetOdovzdanychObalok(1, pocetObalokOdovzd);
						o->SetPocetVydanychObalok(1, pocetObalokVyd);
						o->SetPocetZapisanychVolicov(1, pocetVolicov);
						o->SetUcastVolicov(1, ucastVolicov);
						m_obce->insert(kod, o);
					}
					else
					{
						Obec* o;
						m_obce->tryFind(kod, o);
						o->SetPocetOdovzdanychHlasov(2, pocetHlasovKand);
						o->SetPocetOdovzdanychObalok(2, pocetObalokOdovzd);
						o->SetPocetVydanychObalok(2, pocetObalokVyd);
						o->SetPocetZapisanychVolicov(2, pocetVolicov);
						o->SetUcastVolicov(2, ucastVolicov);
					}
				}
			}
		}
	}
	//Debug
	//std::wcout << "Nacitanych: " << m_obce->size() << " obci" << "\n";
}

structures::List<Obec*>* Manazer::FilterObce(std::wstring nazov, std::wstring pocetOd, std::wstring pocetDo, std::wstring ucastOd, std::wstring ucastDo, int kolo)
{
	bool nazovBool = false;
	bool pocet = false;
	bool ucast = false;

	//Zistenie filtrov
	std::wstring emptyString = L"";
	if (nazov != emptyString) { nazovBool = true; }
	if (pocetOd != emptyString || pocetDo != emptyString) { pocet = true; }
	if (ucastOd != emptyString || ucastDo != emptyString) { ucast = true; }

	structures::ArrayList<Obec*>* obce = new structures::ArrayList<Obec*>();	//Kopia vsetkych pointerov na obce
	//for (auto obec : *m_obce)
	//{
	//	Obec* o = obec->accessData();
	//	obce->add(o);
	//}

	KriteriumNazov<std::wstring, Obec*>* kritNazov = new KriteriumNazov<std::wstring, Obec*>();
	FilterNazov<std::wstring, Obec*>* filterNazov = new FilterNazov<std::wstring, Obec*>();

	KriteriumVolici<int, Obec*>* kritPocetVol = new KriteriumVolici<int, Obec*>();
	Filter_Fi<int, Obec*>* filterPocetVol = new Filter_Fi<int, Obec*>();

	KriteriumUcast<double, Obec*>* kritUcast = new KriteriumUcast<double, Obec*>();
	Filter_Fi<double, Obec*>* filterUcast = new Filter_Fi<double, Obec*>();

	if (nazovBool)
	{
		filterNazov->SetAlfa(nazov);
	}

	if (pocet)
	{
		kritPocetVol->SetKolo(kolo);
		try
		{
			filterPocetVol->SetAlfa(std::stoi(pocetOd));
			filterPocetVol->SetBeta(std::stoi(pocetDo));
		}
		catch (std::invalid_argument e)
		{
			std::cout << "Nespravny vstup!\n";
		}
	}

	if (ucast)
	{
		kritUcast->SetKolo(kolo);
		try
		{
			filterUcast->SetAlfa(std::stod(ucastOd));
			filterUcast->SetBeta(std::stod(ucastDo));
		}
		catch (std::invalid_argument e)
		{
			std::cout << "Nespravny vstup!\n";
		}
	}

	for (auto obec : *m_obce)
	{
		Obec* o = obec->accessData();
		bool pass = true;
		if (nazovBool) { pass = pass && filterNazov->Ohodnot(o, *kritNazov); }
		if (pocet) { pass = pass && filterPocetVol->Ohodnot(o, *kritPocetVol); }
		if (ucast && kolo == 3)
		{
			kritUcast->SetKolo(1);
			pass = pass && filterUcast->Ohodnot(o, *kritUcast);
			kritUcast->SetKolo(2);
			pass = pass && filterUcast->Ohodnot(o, *kritUcast);
		}
		else
		{
			if (ucast) { pass = pass && filterUcast->Ohodnot(o, *kritUcast); }
		}

		if (pass)
		{
			obce->add(o);
		}
	}

	//std::cout << "**Velkost: " << obce->size() << "\n";

	delete kritNazov;
	delete filterNazov;

	delete kritPocetVol;
	delete kritUcast;

	delete filterPocetVol;
	delete filterUcast;

	return obce;
}

structures::List<Oblast*>* Manazer::FilterOkresy(std::wstring nazov, std::wstring pocetOd, std::wstring pocetDo, std::wstring ucastOd, std::wstring ucastDo, int kolo)
{
	bool nazovBool = false;
	bool pocet = false;
	bool ucast = false;

	//Zistenie filtrov
	std::wstring emptyString = L"";
	if (nazov != emptyString) { nazovBool = true; }
	if (pocetOd != emptyString || pocetDo != emptyString) { pocet = true; }
	if (ucastOd != emptyString || ucastDo != emptyString) { ucast = true; }

	structures::ArrayList<Oblast*>* okresy = new structures::ArrayList<Oblast*>();	//Kopia vsetkych pointerov na obce

	KriteriumNazov<std::wstring, Oblast*>* kritNazov = new KriteriumNazov<std::wstring, Oblast*>();
	FilterNazov<std::wstring, Oblast*>* filterNazov = new FilterNazov<std::wstring, Oblast*>();

	KriteriumVolici<int, Oblast*>* kritPocetVol = new KriteriumVolici<int, Oblast*>();
	Filter_Fi<int, Oblast*>* filterPocetVol = new Filter_Fi<int, Oblast*>();

	KriteriumUcast<double, Oblast*>* kritUcast = new KriteriumUcast<double, Oblast*>();
	Filter_Fi<double, Oblast*>* filterUcast = new Filter_Fi<double, Oblast*>();

	if (nazovBool)
	{
		filterNazov->SetAlfa(nazov);
	}

	if (pocet)
	{
		kritPocetVol->SetKolo(kolo);
		try
		{
			filterPocetVol->SetAlfa(std::stoi(pocetOd));
			filterPocetVol->SetBeta(std::stoi(pocetDo));
		}
		catch (std::invalid_argument e)
		{
			std::cout << "Nespravny vstup!\n";
		}
	}

	if (ucast)
	{
		kritUcast->SetKolo(kolo);
		try
		{
			filterUcast->SetAlfa(std::stod(ucastOd));
			filterUcast->SetBeta(std::stod(ucastDo));
		}
		catch (std::invalid_argument e)
		{
			std::cout << "Nespravny vstup!\n";
		}
	}

	for (auto okres : *m_okresy)
	{
		Oblast* o = okres->accessData();
		bool pass = true;
		if (nazovBool) { pass = pass && filterNazov->Ohodnot(o, *kritNazov); }
		if (pocet) { pass = pass && filterPocetVol->Ohodnot(o, *kritPocetVol); }
		if (ucast && kolo == 3)
		{
			kritUcast->SetKolo(1);
			pass = pass && filterUcast->Ohodnot(o, *kritUcast);
			kritUcast->SetKolo(2);
			pass = pass && filterUcast->Ohodnot(o, *kritUcast);
		}
		else
		{
			if (ucast) { pass = pass && filterUcast->Ohodnot(o, *kritUcast); }
		}

		if (pass)
		{
			okresy->add(o);
		}
	}

	delete kritNazov;
	delete filterNazov;

	delete kritPocetVol;
	delete kritUcast;

	delete filterPocetVol;
	delete filterUcast;

	return okresy;
}

structures::List<Oblast*>* Manazer::FilterKraje(std::wstring nazov, std::wstring pocetOd, std::wstring pocetDo, std::wstring ucastOd, std::wstring ucastDo, int kolo)
{
	bool nazovBool = false;
	bool pocet = false;
	bool ucast = false;

	//Zistenie filtrov
	std::wstring emptyString = L"";
	if (nazov != emptyString) { nazovBool = true; }
	if (pocetOd != emptyString || pocetDo != emptyString) { pocet = true; }
	if (ucastOd != emptyString || ucastDo != emptyString) { ucast = true; }

	structures::ArrayList<Oblast*>* kraje = new structures::ArrayList<Oblast*>();	//Kopia vsetkych pointerov na obce

	KriteriumNazov<std::wstring, Oblast*>* kritNazov = new KriteriumNazov<std::wstring, Oblast*>();
	FilterNazov<std::wstring, Oblast*>* filterNazov = new FilterNazov<std::wstring, Oblast*>();

	KriteriumVolici<int, Oblast*>* kritPocetVol = new KriteriumVolici<int, Oblast*>();
	Filter_Fi<int, Oblast*>* filterPocetVol = new Filter_Fi<int, Oblast*>();

	KriteriumUcast<double, Oblast*>* kritUcast = new KriteriumUcast<double, Oblast*>();
	Filter_Fi<double, Oblast*>* filterUcast = new Filter_Fi<double, Oblast*>();

	if (nazovBool)
	{
		filterNazov->SetAlfa(nazov);
	}

	if (pocet)
	{
		kritPocetVol->SetKolo(kolo);
		try
		{
			filterPocetVol->SetAlfa(std::stoi(pocetOd));
			filterPocetVol->SetBeta(std::stoi(pocetDo));
		}
		catch (std::invalid_argument e)
		{
			std::cout << "Nespravny vstup!\n";
		}
	}

	if (ucast)
	{
		kritUcast->SetKolo(kolo);
		try
		{
			filterUcast->SetAlfa(std::stod(ucastOd));
			filterUcast->SetBeta(std::stod(ucastDo));
		}
		catch (std::invalid_argument e)
		{
			std::cout << "Nespravny vstup!\n";
		}
	}

	for (auto kraj : *m_kraje)
	{
		Oblast* o = kraj->accessData();
		bool pass = true;
		if (nazovBool) { pass = pass && filterNazov->Ohodnot(o, *kritNazov); }
		if (pocet) { pass = pass && filterPocetVol->Ohodnot(o, *kritPocetVol); }
		if (ucast && kolo == 3)
		{
			kritUcast->SetKolo(1);
			pass = pass && filterUcast->Ohodnot(o, *kritUcast);
			kritUcast->SetKolo(2);
			pass = pass && filterUcast->Ohodnot(o, *kritUcast);
		}
		else
		{
			if (ucast) { pass = pass && filterUcast->Ohodnot(o, *kritUcast); }
		}

		if (pass)
		{
			kraje->add(o);
		}
	}

	delete kritNazov;
	delete filterNazov;

	delete kritPocetVol;
	delete kritUcast;

	delete filterPocetVol;
	delete filterUcast;

	return kraje;
}

structures::List<Obec*>* Manazer::FilterPrislusnost(std::wstring nazov, std::wstring pocetOd, std::wstring pocetDo, std::wstring ucastOd, std::wstring ucastDo, int kolo)
{
	bool pocet = false;
	bool ucast = false;

	//Zistenie filtrov
	std::wstring emptyString = L"";
	if (pocetOd != emptyString || pocetDo != emptyString) { pocet = true; }
	if (ucastOd != emptyString || ucastDo != emptyString) { ucast = true; }

	structures::ArrayList<Obec*>* obce = new structures::ArrayList<Obec*>;

	KriteriumVolici<int, Obec*>* kritPocetVol = new KriteriumVolici<int, Obec*>();
	Filter_Fi<int, Obec*>* filterPocetVol = new Filter_Fi<int, Obec*>();

	KriteriumUcast<double, Obec*>* kritUcast = new KriteriumUcast<double, Obec*>();
	Filter_Fi<double, Obec*>* filterUcast = new Filter_Fi<double, Obec*>();

	KriteriumPrislusnost<bool, Obec*>* kritPrislusnost = new KriteriumPrislusnost<bool, Obec*>;
	Filter_fi<bool, Obec*>* filterPrislusnost = new Filter_fi<bool, Obec*>;

	//Zistenie pointeru na okres/kraj
	Oblast* oblast = nullptr;
	bool foundOkres = m_nOkresy->tryFind(nazov, oblast);
	bool foundKraj = m_nKraje->tryFind(nazov, oblast);

	if (foundOkres || foundKraj)
	{
		kritPrislusnost->SetOblast(oblast);
		filterPrislusnost->SetAlfa(true);
	}
	else
	{
		std::cout << "Okres/Kraj nenajdeny!\n";

		delete kritPocetVol;
		delete filterPocetVol;
		delete kritUcast;
		delete filterUcast;
		delete kritPrislusnost;
		delete filterPrislusnost;

		obce->clear();

		return obce;
	}

	if (pocet)
	{
		kritPocetVol->SetKolo(kolo);
		try
		{
			filterPocetVol->SetAlfa(std::stoi(pocetOd));
			filterPocetVol->SetBeta(std::stoi(pocetDo));
		}
		catch (std::invalid_argument e)
		{
			std::cout << "Nespravny vstup!\n";
		}
	}

	if (ucast)
	{
		kritUcast->SetKolo(kolo);
		try
		{
			filterUcast->SetAlfa(std::stod(ucastOd));
			filterUcast->SetBeta(std::stod(ucastDo));
		}
		catch (std::invalid_argument e)
		{
			std::cout << "Nespravny vstup!\n";
		}
	}


	for (auto obec : *m_obce)
	{
		Obec* o = obec->accessData();
		bool pass = true;
		pass = pass && filterPrislusnost->Ohodnot(o, *kritPrislusnost);
		if (pocet) { pass = pass && filterPocetVol->Ohodnot(o, *kritPocetVol); }
		if (ucast && kolo == 3)
		{
			kritUcast->SetKolo(1);
			pass = pass && filterUcast->Ohodnot(o, *kritUcast);
			kritUcast->SetKolo(2);
			pass = pass && filterUcast->Ohodnot(o, *kritUcast);
		}
		else
		{
			if (ucast) { pass = pass && filterUcast->Ohodnot(o, *kritUcast); }
		}

		if (pass)
		{
			obce->add(o);
		}
	}

	delete kritPocetVol;
	delete filterPocetVol;

	delete kritUcast;
	delete filterUcast;

	delete kritPrislusnost;
	delete filterPrislusnost;

	return obce;
}
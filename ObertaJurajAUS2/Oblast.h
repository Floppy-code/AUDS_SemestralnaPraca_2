#pragma once
#include <string>
#include "structures/array/array.h"

class Oblast
{
public:
	Oblast(int kod, std::wstring nazov, int typ);
	Oblast(Oblast& other);
	~Oblast();

	std::wstring GetNazov() { return m_nazov; }
	int GetKod() { return m_kod; }
	//bool IsKraj() { return m_typ == 0; };
	void SetPocetZapisanychVolicov(int kolo, int pocet) { (*m_pocetZapVolicov)[kolo - 1] = pocet; }
	void SetPocetVydanychObalok(int kolo, int pocet) { (*m_pocetVydaObalok)[kolo - 1] = pocet; }
	void SetPocetOdovzdanychObalok(int kolo, int pocet) { (*m_pocetOdovObalok)[kolo - 1] = pocet; }
	void SetUcastVolicov(int kolo, double pocet) { (*m_ucastVolicov)[kolo - 1] = pocet; }
	void SetPocetOdovzdanychHlasov(int kolo, int pocet) { (*m_pocetOdovHlasov)[kolo - 1] = pocet; }
	void SetVyssiaJednotka(Oblast* o) { m_vyssiaJednotka = o; }

	int GetPocetZapisanychVolicov(int kolo);
	int GetPocetVydanychObalok(int kolo);
	int GetPocetOdovzdanychObalok(int kolo);
	double GetUcastVolicov(int kolo);
	int GetPocetOdovzdanychHlasov(int kolo) { return (*m_pocetOdovHlasov)[kolo - 1]; }
	Oblast* GetVyssiaJednotka() { return m_vyssiaJednotka; }

private:
	std::wstring m_nazov;
	int m_kod;
	int m_typ = -1;	//0 - kraj, 1 - okres
	structures::Array<int>* m_pocetZapVolicov;	//0 - prve kolo, 1 - druhe kolo
	structures::Array<int>* m_pocetVydaObalok;
	structures::Array<int>* m_pocetOdovObalok;
	structures::Array<double>* m_ucastVolicov;
	structures::Array<int>* m_pocetOdovHlasov;
	Oblast* m_vyssiaJednotka;
};
#pragma once
#include <string>
#include "structures/array/array.h"
#include "Oblast.h"

class Obec
{
public:
	Obec(int kod, std::wstring nazov, Oblast* kraj, Oblast* okres);
	Obec(Obec& other);
	~Obec();
	std::wstring GetNazov() { return m_nazov; }
	int GetKod() { return m_kod; }

	Oblast* GetKraj() { return m_kraj; }
	Oblast* GetOkres() { return m_okres; }

	void SetPocetZapisanychVolicov(int kolo, int pocet) { (*m_pocetZapVolicov)[kolo - 1] = pocet; }
	void SetPocetVydanychObalok(int kolo, int pocet) { (*m_pocetVydaObalok)[kolo - 1] = pocet; }
	void SetPocetOdovzdanychObalok(int kolo, int pocet) { (*m_pocetOdovObalok)[kolo - 1] = pocet; }
	void SetUcastVolicov(int kolo, double pocet) { (*m_ucastVolicov)[kolo - 1] = pocet; }
	void SetPocetOdovzdanychHlasov(int kolo, int pocet) { (*m_pocetOdovHlasov)[kolo - 1] = pocet; }

	int GetPocetZapisanychVolicov(int kolo);
	int GetPocetVydanychObalok(int kolo);
	int GetPocetOdovzdanychObalok(int kolo);
	double GetUcastVolicov(int kolo);
	int GetPocetOdovzdanychHlasov(int kolo) { return (*m_pocetOdovHlasov)[kolo - 1]; }

	bool PatriDoVyssiehoCelku(Oblast* oblast) { return m_kraj == oblast || m_okres == oblast; }

private:
	std::wstring m_nazov;
	int m_kod;
	Oblast* m_kraj;
	Oblast* m_okres;
	structures::Array<int>* m_pocetZapVolicov;	//0 - prve kolo, 1 - druhe kolo
	structures::Array<int>* m_pocetVydaObalok;
	structures::Array<int>* m_pocetOdovObalok;
	structures::Array<double>* m_ucastVolicov; 
	structures::Array<int>* m_pocetOdovHlasov;
};
#include "Obec.h"

Obec::Obec(int kod, std::wstring nazov, Oblast * kraj, Oblast * okres) :
	m_kod(kod),
	m_nazov(nazov),
	m_kraj(kraj),
	m_okres(okres)
{
	m_pocetZapVolicov = new structures::Array<int>(2);	//2 kola
	m_pocetVydaObalok = new structures::Array<int>(2);
	m_pocetOdovObalok = new structures::Array<int>(2);
	m_ucastVolicov = new structures::Array<double>(2);
	m_pocetOdovHlasov = new structures::Array<int>(2);
}

Obec::Obec(Obec& other) :
	m_kod(other.m_kod),
	m_nazov(other.m_nazov),
	m_pocetZapVolicov(other.m_pocetZapVolicov),
	m_pocetVydaObalok(other.m_pocetVydaObalok),
	m_pocetOdovObalok(other.m_pocetOdovObalok),
	m_ucastVolicov(other.m_ucastVolicov),
	m_pocetOdovHlasov(other.m_pocetOdovHlasov),
	m_okres(other.m_okres),
	m_kraj(other.m_kraj)
{
}

Obec::~Obec()
{
	delete m_pocetZapVolicov;
	delete m_pocetVydaObalok;
	delete m_pocetOdovObalok;
	delete m_ucastVolicov;
	delete m_pocetOdovHlasov;
}

int Obec::GetPocetZapisanychVolicov(int kolo)
{
	if (kolo == 3) {
		return (*m_pocetZapVolicov)[0] + (*m_pocetZapVolicov)[1]; //0 - prve kolo, 1 - druhe kolo
	}
	return (*m_pocetZapVolicov)[kolo - 1];
}

int Obec::GetPocetVydanychObalok(int kolo)
{
	if (kolo == 3) {
		return (*m_pocetVydaObalok)[0] + (*m_pocetVydaObalok)[1];
	}
	return (*m_pocetVydaObalok)[kolo - 1];
}

int Obec::GetPocetOdovzdanychObalok(int kolo)
{
	if (kolo == 3) {
		return (*m_pocetOdovObalok)[0] + (*m_pocetOdovObalok)[1];
	}
	return (*m_pocetOdovObalok)[kolo - 1];
}

double Obec::GetUcastVolicov(int kolo)
{
	if (kolo == 3) {
		return (*m_ucastVolicov)[1];
	}
	return (*m_ucastVolicov)[kolo - 1];
}

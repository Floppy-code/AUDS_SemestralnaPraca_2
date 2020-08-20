#include "Oblast.h"
#include <iostream>

Oblast::Oblast(int kod, std::wstring nazov, int typ) :
	m_kod(kod),
	m_nazov(nazov),
	m_typ(typ)
{
	m_pocetZapVolicov = new structures::Array<int>(2);
	m_pocetVydaObalok = new structures::Array<int>(2);
	m_pocetOdovObalok = new structures::Array<int>(2);
	m_ucastVolicov = new structures::Array<double>(2);
	m_pocetOdovHlasov = new structures::Array<int>(2);
}

Oblast::Oblast(Oblast & other) :
	m_kod(other.m_kod),
	m_nazov(other.m_nazov),
	m_typ(other.m_typ),
	m_pocetZapVolicov(other.m_pocetZapVolicov),
	m_pocetVydaObalok(other.m_pocetVydaObalok),
	m_pocetOdovObalok(other.m_pocetOdovObalok),
	m_ucastVolicov(other.m_ucastVolicov),
	m_pocetOdovHlasov(other.m_pocetOdovHlasov)
{
}

Oblast::~Oblast()
{
	delete m_pocetZapVolicov;
	delete m_pocetVydaObalok;
	delete m_pocetOdovObalok;
	delete m_ucastVolicov;
	delete m_pocetOdovHlasov;
}

int Oblast::GetPocetZapisanychVolicov(int kolo)
{
	if (kolo == 3) {
		return (*m_pocetZapVolicov)[0] + (*m_pocetZapVolicov)[1];
	}
	return (*m_pocetZapVolicov)[kolo - 1];
}

int Oblast::GetPocetVydanychObalok(int kolo)
{
	if (kolo == 3) {
		return (*m_pocetVydaObalok)[0] + (*m_pocetVydaObalok)[1];
	}
	return (*m_pocetVydaObalok)[kolo - 1];
}

int Oblast::GetPocetOdovzdanychObalok(int kolo)
{
	if (kolo == 3) {
		return (*m_pocetOdovObalok)[0] + (*m_pocetOdovObalok)[1];
	}
	return (*m_pocetOdovObalok)[kolo - 1];
}

double Oblast::GetUcastVolicov(int kolo)
{
	if (kolo == 3)
	{
		return (*m_ucastVolicov)[1];
	}
	return (*m_ucastVolicov)[kolo - 1];
}

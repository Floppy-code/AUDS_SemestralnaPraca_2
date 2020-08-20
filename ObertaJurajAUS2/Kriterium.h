#pragma once

template<typename T, typename O>
class Kriterium
{
public:
	virtual T Ohodnot(O& object) = 0;
};

template<typename T, typename O>
class KriteriumNazov : public Kriterium<T, O>
{
public:
	T Ohodnot(O& objekt) override { return objekt->GetNazov(); }
};

template<typename T, typename O>
class KriteriumPrislusnost : public Kriterium<T, O>
{
public:
	T Ohodnot(O& objekt) override { return objekt->PatriDoVyssiehoCelku(m_oblast); }
	void SetOblast(Oblast* o) { m_oblast = o; }
private:
	Oblast* m_oblast;
};

template<typename T, typename O>
class KriteriumVolici : public Kriterium<T, O>
{
public:
	T Ohodnot(O& objekt) override { return objekt->GetPocetZapisanychVolicov(m_kolo); }
	void SetKolo(int kolo) { m_kolo = kolo; }
private:
	int m_kolo;
};

template<typename T, typename O>
class KriteriumVydaneObalky : public Kriterium <T, O>
{
public:
	T Ohodnot(O& objekt) override { return objekt->GetPocetVydanychObalok(m_kolo); }
	void SetKolo(int kolo) { m_kolo = kolo; }
private:
	int m_kolo;
};

template<typename T, typename O>
class KriteriumUcast : public Kriterium <T, O>
{
public:
	T Ohodnot(O& objekt) override { return objekt->GetUcastVolicov(m_kolo); }
	void SetKolo(int kolo) { m_kolo = kolo; }
private:
	int m_kolo;
};

template<typename T, typename O>
class KriteriumOdovzdaneObalky : public Kriterium <T, O>
{
public:
	T Ohodnot(O& objekt) override { return objekt->GetPocetOdovzdanychObalok(m_kolo); }
	void SetKolo(int kolo) { m_kolo = kolo; }
private:
	int m_kolo;
};

template<typename T, typename O>
class KriteriumHlasyOdovzdane : public Kriterium<T, O>
{
public:
	T Ohodnot(O& objekt) override { return objekt->GetPocetOdovzdanychHlasov(m_kolo); }
	void SetKolo(int kolo) { m_kolo = kolo; }
private:
	int m_kolo;
};

//template<typename T, typename O>
//class KriteriumHlasyOdovzdane : public Kriterium <T, O>
//{
//	T
//};

//KriterumMeno

//KriteriumHlasyZiskane
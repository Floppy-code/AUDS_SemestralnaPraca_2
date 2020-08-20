#pragma once
#include <string>

template<typename T, typename O>
class Filter
{
	virtual bool Ohodnot(O& o, Kriterium<T, O>& c) = 0;
};

template<typename T, typename O>
class Filter_fi : public Filter<T, O>
{
public:
	bool Ohodnot(O& objekt, Kriterium<T, O>& crit) override { return crit.Ohodnot(objekt) == m_alfa; }
	void SetAlfa(T a) { m_alfa = a; }
private:
	T m_alfa;
};

template<typename T, typename O>
class Filter_Fi : public Filter<T, O>
{
public:
	bool Ohodnot(O& objekt, Kriterium<T, O>& crit) override
	{
		T result = crit.Ohodnot(objekt);
		return result >= m_alfa && result <= m_beta;
	}
	void SetAlfa(T alfa) { m_alfa = alfa; }
	void SetBeta(T beta) { m_beta = beta; }
private:
	T m_alfa;
	T m_beta;
};

template<typename T, typename O>
class FilterNazov : public Filter<T, O>
{
public:
	bool Ohodnot(O& objekt, Kriterium<T, O>& crit) override { return crit.Ohodnot(objekt).find(m_alfa) != std::string::npos; }
	void SetAlfa(T a) { m_alfa = a; }
private:
	T m_alfa;
};
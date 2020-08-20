#pragma once
#include "structures/list/array_list.h"
#include "Kriterium.h"
#include <clocale>
#include <cwchar>


template<typename T, typename O>
class QuickSort
{
public:
	void Sort(structures::List<O>& list, Kriterium<T, O>& krit, bool zostupne);
	void SortString(structures::List<O>& list, Kriterium<T, O>& krit, bool zostupne); //Len pre UTF-8 wstringy so slovenskym std::locale

private:
	void Quick(int min, int max, structures::List<O>& list, Kriterium<T, O>& krit);
	void QuickString(int min, int max, structures::List<O>& list, Kriterium<T, O>& krit);	//Len pre UTF-8 wstringy so slovenskym std::locale

	bool m_zostupne;	
};

template<typename T, typename O>
inline void QuickSort<T, O>::Sort(structures::List<O>& list, Kriterium<T, O>& krit, bool zostupne)
{
	m_zostupne = zostupne;
	Quick(0, list.size() - 1, list, krit);
}

template<typename T, typename O>
inline void QuickSort<T, O>::Quick(int min, int max, structures::List<O>& list, Kriterium<T, O>& krit)
{
	T pivot = krit.Ohodnot(list[(min + max) / 2]);
	int left = min;
	int right = max;

	do
	{
		if (m_zostupne)
		{
			while (krit.Ohodnot(list[left]) < pivot)
			{
				left++;
			}
			while (krit.Ohodnot(list[right]) > pivot)
			{
				right--;
			}
		}
		else
		{
			while (krit.Ohodnot(list[left]) > pivot)
			{
				left++;
			}
			while (krit.Ohodnot(list[right]) < pivot)
			{
				right--;
			}
		}
		if (left <= right)
		{
			std::swap(list[left], list[right]);
			left++;
			right--;
		}
	} while (left <= right);
	if (min < right)
	{
		Quick(min, right, list, krit);
	}
	if (left < max)
	{
		Quick(left, max, list, krit);
	}
}

template<typename T, typename O>
inline void QuickSort<T, O>::SortString(structures::List<O>& list, Kriterium<T, O>& krit, bool zostupne)
{
	std::setlocale(LC_ALL, "sk_SK.utf8");
	m_zostupne = zostupne;
	QuickString(0, list.size() - 1, list, krit);
}

template<typename T, typename O>
inline void QuickSort<T, O>::QuickString(int min, int max, structures::List<O>& list, Kriterium<T, O>& krit)
{
	T pivot = krit.Ohodnot(list[(min + max) / 2]);
	int left = min;
	int right = max;

	do
	{
		if (m_zostupne)
		{
			while (std::wcscoll(krit.Ohodnot(list[left]).c_str(), pivot.c_str()) < 0)
			{
				left++;
			}
			while (std::wcscoll(krit.Ohodnot(list[right]).c_str(), pivot.c_str()) > 0)
			{
				right--;
			}
		}
		else
		{
			while (std::wcscoll(krit.Ohodnot(list[left]).c_str(), pivot.c_str()) > 0)
			{
				left++;
			}
			while (std::wcscoll(krit.Ohodnot(list[right]).c_str(), pivot.c_str()) < 0)
			{
				right--;
			}
		}
		if (left <= right)
		{
			std::swap(list[left], list[right]);
			left++;
			right--;
		}
	} while (left <= right);
	if (min < right)
	{
		QuickString(min, right, list, krit);
	}
	if (left < max)
	{
		QuickString(left, max, list, krit);
	}
}

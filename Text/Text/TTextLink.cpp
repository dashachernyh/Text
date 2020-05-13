#include<string>
#include<iostream>
using namespace std;
#include"TTextLink.h"
#include "TText.h"
TTextLink::TTextLink(const char *_str, TTextLink *_pNext, TTextLink *_pDown)
{
	pNext = _pNext;
	pDown = _pDown;
	if (_str == NULL) str[0] = '/0';
	else
		strcpy_s(str, _str);
}

void* TTextLink::operator new(size_t size)
{
	TTextLink *pLink = MemHeader.pFree;
	if (MemHeader.pFree != NULL) MemHeader.pFree = pLink->pNext;
	return pLink;
}

//освобождение звена
void TTextLink::operator delete(void *pMem)
{
	TTextLink *pLink = (TTextLink *)pMem;   //преобразования типа
	pLink->pNext = MemHeader.pFree;
	MemHeader.pFree = pLink;   //становится первым свободным звеном
}

//выделение памяти: массив списков
void TTextLink::InitMemSystem(int size)
{
	MemHeader.pFirst = (TTextLink *) new char[sizeof(TTextLink)*size];
	MemHeader.pFree = MemHeader.pFirst;
	MemHeader.pLast = MemHeader.pFirst + (size - 1);
	TTextLink *pLink = MemHeader.pFirst;
	for (int i = 0; i < size - 1; i++)
	{
	    pLink->str[0] = '\0';
		pLink->pNext = pLink + 1;
		pLink++;
	} 
	pLink->pNext = NULL;

}

void TTextLink::PrintFreeLink()
{
	cout << "List of free links" << endl;
	for (TTextLink *pLink = MemHeader.pFree; pLink != NULL; pLink=pLink->pNext)
	{
		cout << pLink->str << endl;
	}
}

void TTextLink::MemCleaner(TText& txt)
{
	for (txt.Reset(); !txt.IsEnd(); txt.GoNext())
	{
		string tmp = "&&&";
		tmp += txt.GetLink();
		txt.SetLink(tmp);
	}
	TTextLink *pLink;
	for (pLink=MemHeader.pFree; pLink!=NULL;pLink=pLink->pNext)
	{
		string tmp1 = "&&&";
		tmp1 +=string(pLink->str);
		
		strncpy_s(pLink->str, tmp1.c_str(),80);
	}
	//сборка мусора
	for (pLink = MemHeader.pFirst; pLink<=MemHeader.pLast; pLink++)
	{
		if (strstr(pLink->str, "&&&") != NULL)
		{
			strcpy_s(pLink->str, pLink->str + 3);
		}
		else
		{
			delete pLink;
		}
	}
}
#pragma once
#include<string>
#include<iostream>
using namespace std;
#define MemSize 100

class TTextLink;
class TText;

struct TTextMem
{
	TTextLink* pFirst;   //указатель на первое звено
	TTextLink* pLast;    //указатель а последнее звено
	TTextLink* pFree;   //указатель на первое свободное звено
	friend class TTextLink;
};
class TTextLink
{
protected:
	static TTextMem MemHeader;  //система управления памятью 
	TTextLink *pNext, *pDown;   // указатели тек. звена на след уровень и подуровень
	char str[81];               //поле для хранение строки текста
public:
	TTextLink(const char *_str = NULL, TTextLink *_pNext = NULL, TTextLink *_pDown = NULL); //конструктор
	~TTextLink() {}  //деструктор

	static 	void InitMemSystem(int size = MemSize);  //инициализация памяти 
	void* operator new(size_t size);                 //выделение памяти под звено
	void operator delete (void *pMem);               //освобождение памяти под звено
	static void PrintFreeLink();                     //печать свободных звеньев
	static void MemCleaner(TText& txt);              //сборка муссора
	
	friend ostream& operator <<(ostream& os, const TTextLink& Link)
	{
		return os << Link.str;
	}
protected:
	friend class TText;
};
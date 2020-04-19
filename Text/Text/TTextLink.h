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
	
	static TTextMem MemHeader;
public:
	TTextLink *pNext, *pDown;
	char str[81];
	TTextLink(const char *_str = NULL, TTextLink *_pNext = NULL, TTextLink *_pDown = NULL);
	~TTextLink() {}
	static 	void InitMemSystem(int size = MemSize);
	void* operator new(size_t size);
	void operator delete (void *pMem);
	static void PrintFreeLink();
	static void MemCleaner(TText& txt);   //сборка муссора
	friend ostream& operator <<(ostream& os, const TTextLink& Link)
	{
		return os << Link.str;
	}
};
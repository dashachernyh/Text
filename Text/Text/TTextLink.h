#pragma once
#include<stralign.h>
#include<iostream>
using namespace std;
class TTextLink
{
public:
	TTextLink *pNext, *pDown;
	char str[81];
	TTextLink(char *_str = NULL, TTextLink *_pNext = NULL, TTextLink *_pDown = NULL);
	~TTextLink() {}
};
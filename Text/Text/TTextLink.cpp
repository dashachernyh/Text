#include<string.h>
#include<iostream>
using namespace std;
#include"TTextLink.h"
TTextLink::TTextLink(char *_str, TTextLink *_pNext, TTextLink *_pDown)
{
	pNext = _pNext;
	pDown = _pDown;
	if (_str == NULL) str[0] = '/0';
	else
		strcpy(str, _str);
}
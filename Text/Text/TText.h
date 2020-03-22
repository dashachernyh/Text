#pragma once
#include"TTextLink.h"
#include"TStack.h"
#include<string.h>
class TText
{
private:
	TTextLink *pFirst, *pCurr;
	TStack <TTextLink> Stack;
public:
	TText();
	~TText() {};
	void GoFirstLink();
	void GoNextLink();
	void GoDownLink();
	void GoPrevLink();
	void SetLink(string str1);
	string GetLink();
};
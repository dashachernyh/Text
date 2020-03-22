#include"TTextLink.h"
#include"TStack.h"
#include"TText.h"
TText::TText()
{
	pFirst = NULL;
	Stack.ClearSt();
}
void TText::GoFirstLink()
{
	pCurr = pFirst;
	Stack.ClearSt();
}
void TText::GoNextLink()
{

	if (!pCurr) throw - 1;
	if (pCurr->pNext == NULL) return;
	/*?*/Stack.Push(*pCurr);
	pCurr = pCurr->pNext;
}
void TText::GoDownLink()
{
	if (!pCurr) throw - 1;
	if (pCurr->pDown == NULL) return;
	/*?*/Stack.Push(*pCurr);
	pCurr = pCurr->pDown;
}
void TText::GoPrevLink()
{
	if (pCurr == NULL) throw - 1;
	if (Stack.IsEmpty()) return;
	/*?*/*pCurr = Stack.Pop();
}
void TText::SetLink(string str1)
{
	if (!pCurr) throw - 1;
	strcpy(pCurr->str, str1.c_str());
}
string TText::GetLink()
{
	return string(pCurr->str);
}
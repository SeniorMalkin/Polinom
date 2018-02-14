#include "TPolinom.h"


TPolinom::TPolinom( ):_TList_Head<TMonom>()
{
	pHead ->val.coeff=0;
	pHead->val.index=-1;

}
/*
TPolinom::TPolinom(int monom[][2], int nm)
{
	TMonom mon;
	mon.coeff = monom[0][1];
	mon.index = monom[0][2];
	insfirst(mon);
	for (int i = 1; i < nm - 1; i++)
	{
		mon.coeff = monom[i][1];
		mon.index = monom[i][2];
		sortins(mon);
	}

}
*/
TPolinom::TPolinom(TMonom el[], int nm):_TList_Head<TMonom>()
{
	pHead ->val.coeff=0;
	pHead->val.index=-1;
	for(int i=0;i<size;i++)
		inslast(el[i]);
}
TPolinom::TPolinom(TPolinom &pol)
{
	for (pol.Reset(); !pol.IsEnd(); pol.GoNext())
	{
		insbyorder(pCurr->val);
	}
}
void TPolinom::insbyorder(const TMonom& tm)
{
	for(Reset(); !IsEnd(); GoNext())
	{
		if(GetCurr()==tm)
		{
			pCurr->val.coeff+=tm.coeff;
			if(pCurr->val.coeff==0)
				delcurr();
			return;
		}
		if(GetCurr()<tm)
		{
			inscurr(tm);
			return;
		}
		inslast(tm);
	}

}

TPolinom::~TPolinom()
{
	
}
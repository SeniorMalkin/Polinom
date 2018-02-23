#include "stdafx.h"
#include "Polinom.h"
#pragma once

ostream& operator << (ostream &ostr, const TMonom& mon)
{
	ostr << mon.coeff << "X^" << (mon.x) << "Y^" << (mon.y) << "Z^" << mon.z;
	return ostr;
}
ostream& operator << (ostream &ostr, Polinom& pol)
{
	int i = 0;
	for (pol.Reset(); !pol.IsEnd(); pol.GoNext())
	{
		if (pol.GetCurr().coeff > 0 && i != 0)
			ostr << " + " << pol.GetCurr();
		if (pol.GetCurr().coeff < 0 && i != 0)
			ostr << " " << pol.GetCurr();
		if (i == 0)
		{
			ostr << pol.GetCurr();
			i++;
		}
	}
	return ostr;
}
Polinom::Polinom() :_TList_Head<TMonom>()
{
	pHead->val.coeff = 0;
	pHead->val.x = -1;
	pHead->val.y = -1;
	pHead->val.z = -1;

}
Polinom::Polinom(TMonom el[], int nm) :_TList_Head<TMonom>()
{
	pHead->val.coeff = 0;
	pHead->val.x = -1;
	pHead->val.y = -1;
	pHead->val.z = -1;
	for (int i = 0; i<nm; i++)
		inslast(el[i]);
}
Polinom::Polinom(Polinom &pol) :_TList_Head<TMonom>()
{
	pHead->val.coeff = 0;
	pHead->val.x = -1;
	pHead->val.y = -1;
	pHead->val.z = -1;
	for (pol.Reset(); !pol.IsEnd(); pol.GoNext())
	{
		inslast(pol.pCurr->val);
	}
}
void Polinom::insbyorder(const TMonom& tm)
{
	for (Reset(); !IsEnd(); GoNext())
	{
		if (GetCurr() == tm)
		{
			pCurr->val.coeff += tm.coeff;
			if (pCurr->val.coeff == 0)
				delcurr();
			return;
		}
		if (GetCurr()<tm)
		{
			inscurr(tm);
			return;
		}
		inslast(tm);
	}

} 
Polinom  Polinom::operator+(Polinom &q)
{
	Polinom* result;
	result = new Polinom();
	Reset();
	q.Reset();
	while (!q.IsEnd() || !IsEnd())
	{
		TMonom buf;
		if (GetCurr() == q.GetCurr())
		{
				buf.coeff = pCurr->val.coeff + q.pCurr->val.coeff;
				buf.x = GetCurr().x;
				buf.y = GetCurr().y;
				buf.z = GetCurr().z;
				if (buf.coeff == 0)
					{
						GoNext();
						q.GoNext();
					}
				else
					{
						result->inslast(buf);
						GoNext();
						q.GoNext();
					}

		}
		else
		{
				if (GetCurr() < q.GetCurr())
					{
						result->inslast(q.pCurr->val);
						GoNext();
						q.GoNext();
					}
				else
					{
						result->inslast(pCurr->val);
					}
		}
	}
	return *result;
}
Polinom  Polinom::operator-(Polinom &q)
{
	Polinom* result;
	result = new Polinom();
	Reset();
	q.Reset();
	while (!q.IsEnd() || !IsEnd())
	{
		TMonom buf;
		if (GetCurr() == q.GetCurr())
		{
			buf.coeff = pCurr->val.coeff - q.pCurr->val.coeff;
			buf.x = GetCurr().x;
			buf.y = GetCurr().y;
			buf.z = GetCurr().z;
			if (buf.coeff == 0)
			{
				GoNext();
				q.GoNext();
			}
			else
			{
				result->inslast(buf);
				GoNext();
				q.GoNext();
			}

		}
		else
		{
			if (GetCurr() < q.GetCurr())
			{
				buf = q.pCurr->val;
				buf.coeff = (-buf.coeff);
				result->inslast(buf);
				GoNext();
				q.GoNext();
			}
			else
			{
				result->inslast(pCurr->val);
			}
		}
	}
	return *result;
}
Polinom & Polinom::operator=(Polinom &q)
{
	dellist();
	for (q.Reset(); !q.IsEnd(); q.GoNext())
	{
		inslast(q.GetCurr());
	}
	return *this;

}
Polinom::~Polinom()
{
}

#include "TPolinom.h"



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
TPolinom::TPolinom(const TPolinom &pol)
{
	for (pol.Reset(); !pol.IsEnd(); GoNext())
	{

	}
}

TPolinom::~TPolinom()
{
}
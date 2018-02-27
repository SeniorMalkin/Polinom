// _Polinom_.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "Polinom.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	TMonom * mon, *mon1;
	
	mon = new TMonom[2];
	mon1 = new TMonom[2];
	mon1[0].coeff = mon[0].coeff = 13;
	mon1[0].x = 8; mon[0].x = 7;
	mon1[0].y = 8; mon[0].y = 7;
	mon1[0].z = 4; mon[0].z = 3;
	mon1[1].coeff = mon[1].coeff = 5;
	mon1[1].x = 8; mon[1].x = 7;
	mon1[1].y = 1; mon[1].y = 0;
	mon1[1].z = 4; mon[1].z = 3;
	/*
	mon[2].coeff = -3;
	mon1[2].coeff = 3;
	mon1[2].x = 7; mon[2].x = 6;
	mon1[2].y = 6; mon[2].y = 5;
	mon1[2].z = 4; mon[2].z = 3;
	mon1[3].coeff = mon[3].coeff = 21;
	mon1[3].x = 5; mon[3].x = 4;
	mon1[3].y = 8; mon[3].y = 7;
	mon1[3].z = 3; mon[3].z = 2;
	mon1[4].coeff = mon[4].coeff = -7;
	mon1[4].x = 4; mon[4].x = 3;
	mon1[4].y = 4; mon[4].y = 3;
	mon1[4].z = 4; mon[4].z = 3;
	mon1[5].coeff = 27;
	mon1[5].x = 2;
	mon1[5].y = 3;
	mon1[5].z = 11;
	*/
	Polinom pol = Polinom(mon, 2);
	Polinom pol1 = Polinom(mon1, 2);
	cout << pol << endl;
	cout << pol1 << endl;
	Polinom a;
	//pol1 = (pol + pol1);
	a = pol1 * pol;
    cout  << endl << a;

	//cin >> a;
    return 0;
}


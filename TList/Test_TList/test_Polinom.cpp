#include "gtest.h"
#include "../_Polinom_/Polinom.h"
#include "../_Polinom_/Polinom.cpp"
#include <iostream>
using namespace std;
TEST(_Polinom_, can_create_a_polinom_of_array_monoms)
{
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
	EXPECT_NO_THROW(Polinom qu(mon,2));
}
TEST(_Polinom_, can_create_copy_of_polinom)
{
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
	Polinom qu(mon, 2);
	EXPECT_EQ(Polinom(qu),qu);
}
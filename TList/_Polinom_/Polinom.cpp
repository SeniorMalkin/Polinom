#include "stdafx.h"
#include "Polinom.h"
#include <regex>
#pragma once

istream& operator >> (istream&istr,  TMonom& mon)
{
	string str;
	string mystr[4];
	cmatch result;
	regex regular("([\\d-{0,1}]+)");
	istr >> str;
	int i = 0;
	while (regex_search(str.c_str(), result, regular))
	{
		mystr[i] = result[0];
		str = result.suffix();
		i++;
	}
	mon.coeff = atoi(mystr[0].c_str());
	mon.x = atoi(mystr[1].c_str());
	mon.y = atoi(mystr[2].c_str());
	mon.z = atoi(mystr[3].c_str());
	return istr;

}
ostream& operator << (ostream &ostr, const TMonom& mon)
{
	
	switch (mon.x)
	{
		case 0:  //X^0
		{
			switch (mon.y)
			{
			case 0: //x^0Y^0Z
			{
				switch (mon.z)
				{

				case 0: //X^0Y^0Z^0
				{
					ostr << mon.coeff;
					break;
				}
				case 1: //X^0Y^0Z
				{
					ostr << mon.coeff << "*Z";
					break;
				}
				default://X^Y^0Z^a
				{
					ostr << mon.coeff << "*Z^" << mon.z;
					break;
				}
				}
				break;
			}

			case 1://X^0YZ..
			{
				switch (mon.z)
				{

				case 0:
				{
					ostr << mon.coeff << "*Y";
					break;
				}
				case 1:
				{
					ostr << mon.coeff << "*Y" << "Z";
					break;
				}
				default:
				{
					ostr << mon.coeff << "*Y" << "Z^" << mon.z;
					break;
				}
				}
				break;
			}
			default: //X^0Y^aZ..
			{
				switch (mon.z)
				{

				case 0:
				{
					ostr << mon.coeff << "*Y^"<< mon.y;
					break;
				}
				case 1:
				{
					ostr << mon.coeff << "*Y^" << mon.y << "Z";
					break;
				}
				default:
				{
					ostr << mon.coeff << "*Y^" << mon.y << "Z^" << mon.z;
					break;
				}
				}
				break;
			}
			}
			break;
		}
		case 1:
		{
			switch (mon.y)
			{
			case 0: //XY^0Z
			{
				switch (mon.z)
				{

				case 0: //XY^0Z^0
				{
					ostr << mon.coeff << "*X";
					break;
				}
				case 1: //XY^0Z
				{
					ostr << mon.coeff << "*X" << "Z";
					break;
				}
				default://XY^0Z^a
				{
					ostr << mon.coeff << "*X" << "Z^" << mon.z;
					break;
				}
				}
				break;
			}

			case 1://XYZ..
			{
				switch (mon.z)
				{

				case 0:
				{
					ostr << mon.coeff << "*X" << "Y";
					break;
				}
				case 1:
				{
					ostr << mon.coeff << "*X" << "Y" << "Z";
					break;
				}
				default:
				{
					ostr << mon.coeff << "*X" << "Y" << "Z^" << mon.z;
					break;
				}
				}
				break;
			}
			default: //XY^aZ..
			{
				switch (mon.z)
				{

				case 0:
				{
					ostr << mon.coeff << "*X" << "Y^" << mon.y;
					break;
				}
				case 1:
				{
					ostr << mon.coeff << "*X" << "Y^" << mon.y << "Z";
					break;
				}
				default:
				{
					ostr << mon.coeff << "*X" << "Y^" << mon.y << "Z^" << mon.z;
					break;
				}
				}
				break;
			}
			}
			break;
		}
		default:
		{
			switch (mon.y)
			{
			case 0: //x^0Y^0Z
			{
				switch (mon.z)
				{

				case 0: //X^0Y^0Z^0
				{
					ostr << mon.coeff << "*X^" << mon.x;
					break;
				}
				case 1: //X^0Y^0Z
				{
					ostr << mon.coeff << "*X^" << mon.x << "Z";
					break;
				}
				default://X^Y^0Z^a
				{
					ostr << mon.coeff << "*X^" << mon.x << "Z^" << mon.z;
					break;
				}
				}
				break;
			}

			case 1://X^0YZ..
			{
				switch (mon.z)
				{

				case 0:
				{
					ostr << mon.coeff << "*X^" << mon.x << "Y";
					break;
				}
				case 1:
				{
					ostr << mon.coeff << "*X^" << mon.x << "Y" << "Z";
					break;
				}
				default:
				{
					ostr << mon.coeff << "*X^" << mon.x << "Y" << "Z^" << mon.z;
					break;
				}
				}
				break;
			}
			default: //X^0Y^aZ..
			{
				switch (mon.z)
				{

				case 0:
				{
					ostr << mon.coeff << "*X^" << mon.x << "Y^" << mon.y;
					break;
				}
				case 1:
				{
					ostr << mon.coeff << "*X^" << mon.x << "Y^" << mon.y << "Z";
					break;
				}
				default:
				{
					ostr << mon.coeff << "*X^" << mon.x << "Y^" << mon.y << "Z^" << mon.z;
					break;
				}
				}
				break;
			}
			}
			break;
		}
	}
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
istream& operator >> (istream& istr, Polinom& pol)
{
	string str;
	TMonom mon;
	cout << "„исло мономов в полиноме?" << endl;
	istr >> str;
	cout << "¬ведите мономы вида: Coeff.Deg_X.Deg_Y.Deg_Z"<< endl;
	int i = atoi(str.c_str());
	while (i != 0)
	{
		istr >> mon;
		pol.insbyorder(mon);
		i--;
	}
	cout << pol << endl;
	return istr;
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
	if (IsEmpty())
	{
		insfirst(tm);
	}
	else
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
			if (GetCurr() < tm)
			{
				inscurr(tm);
				return;
			}
			inslast(tm);
			return;
		}
	}

} 
Polinom Polinom::operator*(int q)
{
	Reset();
	while (!IsEnd())
	{
		pCurr->val.coeff = pCurr->val.coeff*q;
		GoNext();
	}
	return *this;
}
Polinom Polinom::operator*(TMonom& q)
{
	Reset();
	while (!IsEnd())
	{
		pCurr->val.coeff = pCurr->val.coeff*q.coeff;
		pCurr->val.x = pCurr->val.x + q.x;
		pCurr->val.y = pCurr->val.y + q.y;
		pCurr->val.z = pCurr->val.z + q.z;
		GoNext();
	}
	return *this;
}
Polinom Polinom::operator*(Polinom& q)
{
	Polinom* result;
	result = new Polinom();
	
	Reset();
	q.Reset();
	while (!IsEnd())
	{
		while (!q.IsEnd())
		{
			TMonom buf;
			buf.coeff = q.pCurr->val.coeff*pCurr->val.coeff;
			buf.x = q.pCurr->val.x+pCurr->val.x;
			buf.y = q.pCurr->val.y+pCurr->val.y;
			buf.z = q.pCurr->val.z+pCurr->val.z;
			result->insbyorder(buf);
			q.GoNext();
		}
		q.Reset();
		GoNext();
	}
	return *result;
}
bool Polinom::operator==(Polinom &q)
{
	if (this == &q)
		return true;
	if (size != q.size)
		return false;
	else
	{
		while (!IsEnd())
		{
			if (!(pCurr->val == q.pCurr->val))
				return false;
			GoNext();
			q.GoNext();
		}
		return true;
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
						q.GoNext();
					}
				else
					{
						result->inslast(pCurr->val);
						GoNext();
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
				q.GoNext();
			}
			else
			{
				buf = pCurr->val;
				result->inslast(buf);
				GoNext();
			}
		}
	}
	return *result;
}
Polinom & Polinom::operator=(Polinom& q)
{
	if (this == &q)
		return *this;
	dellist();
	for (q.Reset(); !q.IsEnd(); q.GoNext())
	{
		inslast(q.GetCurr());
	}
	return *this;

}

void Polinom::magic(string st)
{
	string str1 = st;
	string str = st;
	cmatch result;
	list<string> mylist;
	list<string> mylist1;
	regex regular("([\\dx{0,1}y{0,1}z{0,1}\^{0,1}]+)");
	regex regular1("- ([\\dx{0,1}y{0,1}z{0,1}\^{0,1}]+)");
	regex mon("([\\d-{0,1}]+)");
	regex reg_x("x^([\\dx]+)");
	regex reg_y("([\\dy{1}\^{0,1}]+)");
	regex reg_z("([\\dz{1}\^{0,1}]+)");
	while (regex_search(str1.c_str(), result, regular))
	{
		mylist.push_back(result[0]);
		str1 = result.suffix();
	}
	while (regex_search(str.c_str(), result, regular1))
	{
		mylist1.push_back(result[0]);
		str = result.suffix();
	}
	list<string>::iterator i, j;
	i = mylist.begin();
	j = mylist1.begin();
	while (i != mylist.end())
	{
		if((!mylist1.empty()))
		if (("- " + (*i)).compare((*j)) == 0)
		{
			(*i).insert((*i).begin(), '-');
			++j;
		}

		++i;
	}
	i = mylist.begin();
	int k = 0;
	int c = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	TMonom tmp;
	while (i != mylist.end())
	{
		str1 = (*i);
		/*int j = 0;
		while (j != str1.size())
		{
			if (str1[j] == 'x' || str1[j] == 'y' || str1[j] == 'z')
				break;
			j++;
		}
		c = atoi(str1.substr(0, j).c_str());
		str1 = str1.substr(j, str1.size());
		string buf = str1;
		regex_search(str1.c_str(), result, reg_x);
		
		x = atoi(result[0].str().substr(2, result[0].str().size()).c_str());
		buf = result.suffix();
			
		
		regex_search(buf.c_str(), result, reg_y);
		
		y = atoi(result[0].str().substr(2, result[0].str().size()).c_str());
		buf = result.suffix();
		
		regex_search(buf.c_str(), result, reg_z);
		
	    z = atoi(result[0].str().substr(2, result[0].str().size()).c_str());
			*/
		
		while (regex_search(str1.c_str(), result, mon))
		{
			switch (k)
			{
			case 0:
			{
				c = atoi((result[0].str()).c_str());
				break;
			}
			case 1:
			{
				x = atoi((result[0].str()).c_str());
				break;
			}
			case 2:
			{
				y = atoi((result[0].str()).c_str());
				break;
			}
			case 3:
			{
				z = atoi((result[0].str()).c_str());
			}
			}
			str1 = result.suffix();
			k++;
		}
		tmp.coeff = c;
		tmp.x = x;
		tmp.y = y;
		tmp.z = z;
		insbyorder(tmp);
		k = 0;
		++i;
	}
}
string Polinom::str(void)
{
	string result;
	Reset();
	int i = 0;
	while (!IsEnd())
	{
		if (i == 0)
		{
			result += to_string((int)(pCurr->val.coeff));
			switch (pCurr->val.x)
			{
			case 0:
				break;
			case 1:
				result += "x";
				break;
			default:
				result += "x^";
				result += to_string(pCurr->val.x);
				break;
			}
			switch (pCurr->val.y)
			{
			case 0:
				break;
			case 1:
				result += "y";
				break;
			default:
				result += "y^";
				result += to_string(pCurr->val.y);
				break;
			}
			switch (pCurr->val.z)
			{
			case 0:
				break;
			case 1:
				result += "z";
				break;
			default:
				result += "z^";
				result += to_string(pCurr->val.z);
				break;
			}
			i++;
			GoNext();
			continue;
		}

		if (pCurr->val.coeff < 0)
		{
			result += " ";
			result+= to_string((int)pCurr->val.coeff);
			switch (pCurr->val.x)
			{
			case 0:
				break;
			case 1:
				result += "x";
				break;
			default:
				result += "x^";
				result += to_string(pCurr->val.x);
				break;
			}
			switch (pCurr->val.y)
			{
			case 0:
				break;
			case 1:
				result += "y";
				break;
			default:
				result += "y^";
				result += to_string(pCurr->val.y);
				break;
			}
			switch (pCurr->val.z)
			{
			case 0:
				break;
			case 1:
				result += "z";
				break;
			default:
				result += "z^";
				result += to_string(pCurr->val.z);
				break;
			}
			i++;
			GoNext();
		}
		else
		{
			result += " + ";
			result += to_string((int)pCurr->val.coeff);
			switch (pCurr->val.x)
			{
			case 0:
				break;
			case 1:
				result += "x";
				break;
			default:
				result += "x^";
				result += to_string(pCurr->val.x);
				break;
			}
			switch (pCurr->val.y)
			{
			case 0:
				break;
			case 1:
				result += "y";
				break;
			default:
				result += "y^";
				result += to_string(pCurr->val.y);
				break;
			}
			switch (pCurr->val.z)
			{
			case 0:
				break;
			case 1:
				result += "z";
				break;
			default:
				result += "z^";
				result += to_string(pCurr->val.z);
				break;
			}
			GoNext();
		}
	}
	return result;
}
Polinom::~Polinom()
{
}

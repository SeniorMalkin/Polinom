#pragma once
#include "_TList_.h"
//����� �������� ( ����� )
struct TMonom
{
	double coeff; //����������� ��� �����
	int index;    //������� �������� ������ (x*100 + y*10 +z)
};

//***********************************************************

bool operator < (const TMonom& t1, const TMonom& t2)
{
	if (t2.index > t1.index)
		return true;
	else
		return false;
}

//***********************************************************

bool operator > (const TMonom& t1, const TMonom& t2)
{
	if (t2.index < t1.index)
		return true;
	else
		return false;
}

//***********************************************************

bool operator == (const TMonom& t1, const TMonom& t2)
{
	if (t2.index == t1.index)
		return true;
	else
		return false;
}

//************************************************************

bool operator <= (const TMonom& t1, const TMonom& t2)
{
	if ((t2.index == t1.index) || (t2.index > t1.index))
		return true;
	else
		return false;
}

//************************************************************

//����������� ������
template <class T>
class _TList_Head : public _TList_<T>
{
protected:
	TLink<T>*   pHead;                        //�������� �����
public:
	                                        
	_TList_Head(void):_TList_<T>()               // �������� �������� �������� (������ ������)
	{
		pHead = new TLink<TMonom>;
		pStop = pHead;
		pHead->pNext = pHead;
	}

	~_TList_Head(void)
	{
		delete pHead;
	}
	void insfirst(const T& a)               // ���������� ������� ����� ����� ������
	{
		_TList_::insfirst(a);
		pHead->pNext = pFirst;
	}
	void delfirst()                         // ���������� �������� ������� �����
	{
		_TList_::delfirst();
		pHead->pNext = pFirst;
	}
};

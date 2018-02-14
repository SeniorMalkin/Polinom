#pragma once
#include <iostream>
//********************************************************************
//Звено списка

template <class T>
struct TLink
{
	T val;            //Значение хранящееся в звене
	TLink* pNext;     //Указатель на следующий элемент списка
};


//********************************************************************
//Класс линейных списков
template <class T>
class _TList_
{
protected:
	TLink<T> *pFirst, // указатель на первое звено списка
		     *pPrew,  // указатель на звено предшествуещее текущему
		     *pCurr,  // указатель на текущее звено 
		     *pLast,  // указатель на последнее звено списка
		     *pStop;  // переменная сигнализирующая об окончании списка
	int size;         // размер  списка
	int pos;          // номер текущего звена

public:
	_TList_();
	~_TList_();
	bool IsEmpty       ( void );   // список пуст?
	int  GetListLength ( void ) { return size; }   // число звеньев в списке
	T    GetPrew       ( void );   // получить значение предществующего звена
	void GetList       ( void );   // вывести список
	void sortins(const T& el);
	//Текущее звено
	T    SetCurr    ( int pos );   // установить текущее звено
	T    GetCurr    ( void );      // получить значение текущего звена
	int  GetCurrPos ( void ) { return pos; }     // получить номер текущего звена
	void Reset      ( void );      // перейти к началу списка
	void GoNext     ( void );      // перейти к следующему звену
	bool IsEnd      ( void );      // конец списка?

	//Вставка звеньев
	void insfirst (const T& el); // перед первым
	void inslast  (const T& el);   // последним
	void inscurr  (const T& el);   // текущим

	//Удаление звеньев
	void delfirst ( void );        // первого
	void delcurr  ( void );        // текущего
	void dellist  ( void );        // удаление всего списка
};

template <class T>
_TList_<T>::_TList_()
{
	size = pos = 0;
	pFirst = pPrew = pCurr = pLast = pStop = NULL;
}

//******************************************************

template <class T>
_TList_<T>::~_TList_()
{
	if (pFirst != pStop)
	{
		TLink<T> * buf;
		pCurr = pFirst;
		pPrew = pStop;
		while (pCurr->pNext != pStop)
		{
			buf = pCurr;
			pCurr = pCurr->pNext;
			delete buf;
		}
		delete pCurr;
	}
}

//******************************************************

template <class T>
bool _TList_<T>::IsEmpty()
{
	if ((pFirst == pStop) && (pLast == pStop))
		return true;
	return false;
}

//******************************************************

template <class T>
 void _TList_<T>::insfirst (const T& el)
{
TLink<T>* tmp = new TLink<T>;
tmp->val = el;
tmp->pNext = pFirst;
if (pFirst == pStop)
{
	pFirst = pLast = pCurr = tmp;
	pos = 0;
}
else
{
	pFirst = tmp;
	pos++;
}
size++;
}

//*****************************************************

 template <class T>
 void _TList_<T>::inslast(const T& el)
 {
	 TLink<T>* tmp = new TLink<T>;
	 tmp->val = el;
	 tmp->pNext = pStop;
	 if (pFirst == pStop)
	 {
		 pFirst = pLast = pCurr = tmp;
		 pos = 0;
	 }
	 else
	 {
		 pLast->pNext = tmp;
		 pLast = tmp;
	 }
	 size++;
 }

//******************************************************

  template <class T>
  void _TList_<T>::inscurr(const T& el)
  {
	  if (pCurr == pFirst)
		  insfirst(el);
	  else
	  {
		  if (pCurr == pStop)
			  inslast(el);
		  else
		  {
			  TLink<T>* tmp = new TLink<T>;
			  tmp->val = el;
			  tmp->pNext = pCurr;
			  pPrew->pNext = tmp;
			  pCurr = tmp;
		  }
	  }
	  size++;
}

//******************************************************
  template <class T>
  void _TList_<T>::Reset ( void )
  {
	  pos = 0;
	  pCurr = pFirst;
	  pPrew = pStop;

  }

//*******************************************************

  template <class T>
  void _TList_<T>::GoNext()
  {
	  pPrew = pCurr;
	  pCurr = pCurr->pNext;
	  pos++;
  }

  //******************************************************

  template <class T>
  bool _TList_<T>::IsEnd( void )
  {
	  return (pCurr == pStop);
  }

  //******************************************************

  template <class T>
  void _TList_<T>::delfirst(void)
  {
	  if (size == 1)
	  {
		  delete pFirst;
		  pFirst = pCurr = pLast = pPrew = pStop;
		  pos = 0;
	  }
  
	  else
	  {
		  TLink<T> * buf = pFirst;
		  pFirst = pFirst -> pNext;
		  delete buf;
		  pos--;
	  }
	  size--;
  }

//*********************************************************

  template <class T>
  void _TList_<T>::delcurr(void)
  {
	  if (size == 1)
	  {
		  delete pFirst;
		  pFirst = pCurr = pLast = pPrew = pStop;
		  pos = 0;
	  }

	  else
	  {
		  pCurr = pCurr-> pNext;
		  delete pPrew->pNext;
		  pPrew->pNext=pCurr;
		 
	  }
	  size--;
  }

//******************************************************

  template <class T>
  void _TList_<T>::dellist(void)
  {
	  if (pFirst != pStop)
	  {
		  TLink<T> * buf;
		  pCurr = pFirst;
		  pPrew = pStop;
		  while (pCurr->pNext != pStop)
		  {
			  buf = pCurr;
			  pCurr = pCurr->pNext;
			  delete buf;
		  }
		  delete pCurr;
	  }
	  pFirst = pCurr = pLast = pStop;
	  pos = 0;
	  size = 0;
  }

//*****************************************************

  template <class T>
  T _TList_<T>::GetCurr(void)
  {
	  return pCurr->val;
  }

//*****************************************************

  template <class T>
  T    _TList_<T>::SetCurr(int pos1)
  {
	  Reset();
	  while (pos != pos1)
	  {
		  TLink<T>* buf = pCurr;
		  pCurr = pCurr -> pNext;
		  pPrew = buf;
		  pos++;
	  }
	  return GetCurr();
  }

//*****************************************************

  template <class T>
  T _TList_<T>::GetPrew()
  {
	  return pPrew->val;
  }
  
//*******************************************************

  template <class T>
  void _TList_<T>::GetList()
  {
	  cout << endl << "List:" << endl;
	  for (Reset(); !IsEnd(); GoNext())
		  cout << GetCurr()<<" ";
	  cout << endl;
	  Reset();
  }
  
//*******************************************************

  template <class T>
  void _TList_<T>::sortins(const T& el)
  {
	  int flag = 0;
	  int flag1 = 0;

	  for (Reset(); !IsEnd(); GoNext())
	  {
		  if (!IsEmpty())
		  {
			  if (GetCurrPos() == 0)
			  {
				  if (el <= GetCurr())
				  {
					  insfirst(el);
					  flag1++;
					  break;
				  }
			  }
			  else
			  {
				  if (GetCurr() == el)
				  {
					  inscurr(el);
					  flag1++;
					  break;
				  }
				  if ((el > GetPrew()) && (el < GetCurr()))
				  {
					  inscurr(el);
					  flag1++;
					  break;
				  }
			  }
		  }
		  else
		  {
			  insfirst(el);
			  flag1++;
			  break;
		  }

	  }
	  if (flag1 == 0)
		  inslast(el);
	  Reset();
  }
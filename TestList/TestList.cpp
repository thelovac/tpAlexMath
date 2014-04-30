#include "TestList.h"
#include <assert.h>
#include <iostream>

TestList::TestList(void)
{
	RunAllTests();
}


TestList::~TestList(void)
{
}

void TestList::RunAllTests()
{
	testPushBack();
	testGetNbElements();
	testIsEmpty();
	testClear();
	testInsert();
	testErase();
}

void TestList::testPushBack()
{
	//Tests de Pushback()
	List<int>* liste = new List<int>;
	int a = 10;

	liste->PushBack(&a);
	assert(*(liste->Begin()->Element)==10);
}

void TestList::testGetNbElements()
{
	//Test de GetNbElements()
	List<int>* liste = new List<int>;
	int a = 10;
	int b = 20;

	liste->PushBack(&a);
	liste->PushBack(&b);

	assert(liste->GetNbElements()==2);
}

void TestList::testIsEmpty()
{
	//Test de IsEmpty();
	List<int>* liste = new List<int>;

	assert(liste->IsEmpty()==true);

	int a = 10;
	int b = 20;

	liste->PushBack(&a);
	liste->PushBack(&b);

	assert(liste->IsEmpty()==false);

}

void TestList::testClear()
{
	//Test de Clear();
	List<int>* liste = new List<int>;

	liste->Clear();

	assert(liste->IsEmpty()==true);

	int a = 10;
	int b = 20;

	liste->PushBack(&a);
	liste->PushBack(&b);

	liste->Clear();

	assert(liste->IsEmpty()==true);

}

void TestList::testInsert()
{
	//Test de Insert()
	List<int>* liste = new List<int>;
	Iterator<int>* _i = new Iterator<int>;

	int a = 10;
	int b = 20;

	liste->PushBack(&a);
	_i->SetCurrent(liste->Begin());

	liste->Insert(&b, *_i);

	assert(*(liste->Begin()->Element)==20);

}

void TestList::testErase()
{
	//Test de Erase()
	List<int>* liste = new List<int>;
	Iterator<int>* _i = new Iterator<int>;

	int a = 10;

	liste->PushBack(&a);
	_i->SetCurrent(liste->Begin());
	
	liste->Erase(*_i);

	assert(liste->IsEmpty()==true);

	int b = 20;
	int c = 30;

	liste->PushBack(&a);

	_i->SetCurrent(liste->Begin());

	liste->Insert(&b, *_i);
	liste->Insert(&c, *_i);

	_i->SetCurrent(liste->Begin()->Next);

	liste->Erase(*_i);
	
	assert(liste->GetNbElements() == 2);

	_i->SetCurrent(liste->End());

	liste->Erase(*_i);

	assert(liste->Begin()==liste->End());

}
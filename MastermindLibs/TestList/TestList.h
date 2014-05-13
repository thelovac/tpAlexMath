#pragma once
#include "List.h"
class TestList
{
public:
    TestList(void);
    ~TestList(void);

    void RunAllTests();

private:
	void testPushBack();
	void testGetNbElements();
	void testIsEmpty();
	void testClear();
	void testInsert();
	void testErase();
};


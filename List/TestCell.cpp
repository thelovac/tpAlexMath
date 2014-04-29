#include"TestCell.h"
#include"Cell.h"



TestCell::TestCell()
{

	runAllTest();
	delete this;


}


template <class TYPE>
void TestCell::runAllTest()
{

	Cell* test = new Cell;
	assert(test.Element =! NULL);
	delete test;

}
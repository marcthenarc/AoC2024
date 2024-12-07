#include "src/d1/d1.h"
#include "src/d2/d2.h"
#include "src/d3/d3.h"
#include "src/d4/d4.h"

//#define TEST 
#ifdef TEST
#define DATA "data_test/"
#else
#define DATA "data/"
#endif

int main()
{
	// Day 1
	d1p1(DATA "d1.txt");
	d1p2(DATA "d1.txt");

	// Day 2
	d2p1(DATA "d2.txt");
	d2p2(DATA "d2.txt");

	// Day 3
	d3p1(DATA "d3.txt");
	d3p2(DATA "d3.txt");

	 // Day 4
	d4p1(DATA "d4.txt");
#ifdef TEST
	d4p2(DATA "d4-2.txt");
#else
	d4p2(DATA "d4.txt");
#endif
}

#include "src/d1/d1.h"
#include "src/d2/d2.h"

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
}

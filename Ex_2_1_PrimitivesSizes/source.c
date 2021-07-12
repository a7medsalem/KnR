/*
*	Summary
*	- print size of primitive types using sizeof() and limits.h
*/


#include <stdio.h>
#include <limits.h>


int power(int, int);

int main() 
{


	printf("\n\n\tSize of int [%d]\n", sizeof(int));
	// -1 from power for the sign bite, -1 from result for zero
	printf("\tInt max value +%d\n", 1 * power(2, sizeof(int) * 8 - 1) - 1);
	printf("\tInt min value %d\n", -1 * power(2, sizeof(int) * 8 - 1));
	printf("\tInt max unsigned value +%u\n", power(2, sizeof(int) * 8) -1);
	printf("\n\t=== Using limits.h ===\n");
	printf("\tINT_MAX value : +%d\n", INT_MAX);
	printf("\tINT_MIN value : %d\n", INT_MIN);
	printf("\tUINT_MAX value : +%u\n", UINT_MAX);

	printf("\n=============================================\n");

	printf("\n\n\tSize of short [%d]\n", sizeof(short));
	// -1 from power for the sign bite, -1 from result for zero
	printf("\tShort max value +%d\n", 1 * power(2, sizeof(short) * 8 - 1) - 1);
	printf("\tShort min value %d\n", -1 * power(2, sizeof(short) * 8 - 1));
	printf("\tShort max unsigned value +%u\n", 1 * power(2, sizeof(short) * 8) - 1);
	printf("\n\t=== Using limits.h ===\n");
	printf("\tSHRT_MIN value : %d\n", SHRT_MIN);
	printf("\tSHRT_MAX value : +%d\n", SHRT_MAX);
	printf("\tUSHRT_MAX value : +%u\n", USHRT_MAX);

	printf("\n=============================================\n");

	printf("\n\n\tSize of char [%d]\n", sizeof(char));
	// -1 from power for the sign bite, -1 from result for zero
	printf("\tChar max value +%d\n", 1 * power(2, sizeof(char) * 8 - 1) - 1);
	printf("\tChar min value %d\n", -1 * power(2, sizeof(char) * 8 - 1));
	printf("\n\t=== Using limits.h ===\n");
	printf("\tCHAR_MIN value : %d\n", CHAR_MIN);
	printf("\tCHAR_MAX value : +%d\n", CHAR_MAX);

	printf("\n=============================================\n");

	printf("\n\n\tSize of long [%d]\n", sizeof(long));
	// -1 from power for the sign bite, -1 from result for zero
	printf("\tLong max value +%d\n", 1 * power(2, sizeof(long) * 8 - 1) - 1);
	printf("\tLong min value %d\n", -1 * power(2, sizeof(long) * 8 - 1));
	printf("\n\t=== Using limits.h ===\n");
	printf("\tLONG_MIN value : %d\n", LONG_MIN);
	printf("\tLONG_MAX value : +%d\n", LONG_MAX);

	return 0;
}


int power(int base, int power) 
{
	int result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= base;
	}

	return result;
}
/*
*	Summary
*	- kick start and print some messages.
*	- include standard input/out header.
*/


#include <stdio.h>

int main() {

	// print hello world message with normal way
	printf("hello, world \n");

	// this will print all printfs in the same line, cause there is not \n char between them
	printf("Try ");
	printf("it ");
	printf("in ");
	printf("seprate ");
	printf("lines\n");

	/*
	* define the string [or char array] by two ways, they are pretty the same thing :
	*	using an array[] varible,
	*	using a pointer to an array of chars.
	* 
	* every thing define inside "double quotes", it's trun to char[] ends with '\0' char automatically		
	*/
	char message[] = "Try it in an array\n";
	char* otherOne = "Try it in a pointer\n";

	// use %s to print the char array varible
	printf("%s", message);
	printf("%s", otherOne);
}
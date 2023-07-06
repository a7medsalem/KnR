/*
*	Summary
*	- use getchar(), putchar().
*	- use EOF.
*/



#include <stdio.h>

int main() {

	printf("Enter a char ");
	const int c = getchar() != EOF;
	printf("(char != EOF) is %d", c);

	int input;
	while ((input = getchar()) != EOF)
		// this put the input in stdout, when press enter it will print it again on the screen, or it can print it to file not screen :)
		putchar(input); 
}
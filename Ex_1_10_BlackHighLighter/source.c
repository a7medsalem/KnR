/*
*	Summary
*	- type down \t \\ \b special characters.
*/


#include <stdio.h>

int main() {

	int  c;

	while ((c = getchar()) != EOF)
	{
		// must press enter to take all inputs in count
		if (c == '\t') 
		{
			putchar('\\');
			putchar('t');
		}
		else if (c == '\\') 
		{
			putchar('\\');
			putchar('\\');
		}
		else if (c == '\b') 
		{
			putchar('\\');
			putchar('b');
		}
		else {
			putchar(c);
		}
	}

}
/*
*	Summary
*	- type down \t \\ \b special characters.
*/


#include <stdio.h>

int main() {

	int  c;

	printf("Enter a text to print it with special characters (\\t, \\, \\b).\n");
	printf("\"To finish typing, enter EOF (Ctrl+Z in Windows) in empty line then press Enter or quite the app (Ctrl+C)\"\n\n");

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
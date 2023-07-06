/*
*	Summary
*	- squeeze function to remove some chars from given string.
*/

#include <stdio.h>

void squeeze(const char s1[], const char s2[]);

void main()
{
	char testString[] = "Some text to test the function";
	char chars[] = "xsc";

	printf("\n\tThe text to squeeze is \"%s\" by removing those characters \"%s\"\n", testString, chars);
	squeeze(testString, chars);
	printf("\tResult is \"%s\"\n", testString);
}

void squeeze(char s1[], const char s2[])
{
	int i1, i2, j;
	char c;

	i2 = 0;
	while ((c = s2[i2++]) != '\0')
	{
		for (i1 = j = 0; s1[i1] != '\0'; i1++)
		{
			if (s1[i1] != c)
				s1[j++] = s1[i1];
		}
		s1[j] = '\0';
	}
}
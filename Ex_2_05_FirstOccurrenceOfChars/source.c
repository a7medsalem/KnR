/*
*	Summary
*	- get the index of the first occurrence of any char from s2 in s1.
*/


#include <stdio.h>

int indexOf(const char s1[], const char s2[]);

void main()
{
	char testString[] = "Some text to test the function";
	char chars[] = "xsc";

	printf("\n\tSearch in \"%s\" for the first occurrence of those characters \"%s\"\n", testString, chars);
	const int index = indexOf(testString, chars);

	if(index != -1)
		printf("\tThe first occurrence of any char from \"%s\" in target text is at index %d\n", chars, index);
	else
		printf("\tThere is no occurrence of any char from \"%s\" in \"%s\"\n", chars, testString);
}

int indexOf(const char s1[], const char s2[])
{
	int i, j;
	char c1, c2;

	i = 0;
	while((c1 = s1[i++]) != '\0')
	{
		j = 0;
		while((c2 = s2[j++]) != '\0')
		{
			if(c1 == c2)
			{
				return i;
			}
		}
	}

	return -1;
}
/*
*	Summary
*	- read lines from file using freopne()/fclose().
*	- find longest line in given file and print line and its chars count.
*/


#include <stdio.h>

#define MAXLINE 1000

int getLine(char[], int);
void copy(char[], char[]);


int main() {

	FILE* file = freopen("testfile.txt", "r", stdin);

	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];


	max = 0;
	while ((len = getLine(line, MAXLINE)) > 0)
	{
		if (len > max) {
			max = len;
			copy(line, longest);
		}
	}


	if (max > 0)
		printf("\n\n\tThe longest line has %d chars\n\n%s\n\n", max, longest);

	fclose(stdin);
	return 0;
}


int getLine(char line[], int limit) {

	int c = '\0', i = 0;
	for (; i < limit-1 && (c=getchar())!=EOF && c!='\n'; i++)
		line[i] = c;
	
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';


	if (i == limit - 1) {
		while ((c = getchar()) != EOF && c != '\n')
			i++;
	}

	return i;
}

void copy(char from[], char to[]) {
	
	int counter;

	counter = 0;
	while ((to[counter] = from[counter]) != '\0')
	{
		counter++;
	}
}

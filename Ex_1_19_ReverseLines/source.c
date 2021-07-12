/*
*	Summary
*	- reverse line from end to start.
*/


#include <stdio.h>

#define MAXLINE 1000
#define PRINTLIMIT 80

int getLine(char[], int);
void reverse(char[], char[]);


int main() {

	FILE* file = freopen("testfile.txt", "r", stdin);

	int len;
	char line[MAXLINE];
	char reversed[MAXLINE];


	while ((len = getLine(line, MAXLINE)) > 0)
	{
		reverse(line, reversed);
		printf("%s", reversed);
	}


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

void reverse(char original[], char reversed[]) {
	int length;

	length = 0;
	while (original[length] != '\0')
		length++;

	int i;
	for (i = 0; i < length-1; i++)
	{
		// length -2 to skip \n and \0
		reversed[i] = original[length-2 -i];
	}
	reversed[i] = '\n';
	reversed[++i] = '\0';
}


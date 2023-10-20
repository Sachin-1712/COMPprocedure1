
#include <stdio.h>
#include <string.h>

void concatStrings(char* s, char* s1)
{
	int i;

	int j = strlen(s);

	for (i = 0; s1[i] != '\0'; i++) {
		s[i + j] = s1[i];
	}

	s[i + j] = '\0';

	return;
}

int main()
{

	char s[50], s1[50];

	printf("Enter the first string: ");
	scanf("%s", s);

	printf("Enter the second string: ");
	scanf("%s", s1);
	concatStrings(s, s1);

	printf("Concatenated String is: '%s'\n", s);

	return 0;
}

#include <stdio.h>
#include <string.h>

// EXERCISE 1
int IsPalindrome(char *word)
{
	int length = 0;
	char letter = word[0];
	while (letter != '\0') {
		length++;
		letter = word[length];
	}
	for (int i = 0; i < length; i++) {
		if (word[i] != word[length - (1 + i)]) {
			return 0;
		}
	}
	return 1;
}

// EXERCISE 2
void Capitalise(char *phrase)
{
	int i = 0;
	char letter = phrase[0];
	while (letter != '\0') {
		if (letter >= 'a' && letter <= 'z') {
			if (i == 0) {
				phrase[i] = phrase[i] - ('a' - 'A');
			}
			else if (phrase[i - 1] == ' ') {
				phrase[i] = phrase[i] - ('a' - 'A');
			}
		}
		i++;
		letter = phrase[i];
	}
}

// EXERCISE 3
int WordMatchesPattern(char *word, char *pattern)
{
	int wlength = 0;
	char wletter = word[0];
	while (wletter != '\0') {
		wlength++;
		wletter = word[wlength];
	}
	int plength = 0;
	char pletter = pattern[0];
	while (pletter != '\0') {
		plength++;
		pletter = pattern[plength];
	}
	if (wlength != plength) {
		return 0;
	}
	for (int i = 0; i < wlength; i++) {
		if (pattern[i] != '-' && pattern[i] != word[i]) {
			return 0;
		}
	}
	return 1;
}

/**************************************************************************************
YOU DO NOT NEED TO MODIFY ANY CODE BELOW HERE.
The code below defines the main() function that *calls* the WordMatchesPattern() function
you must define above.  Feel free to examine the code below, but you should not make
any changes to the following code.
**************************************************************************************/
int main(void)
{

	char word1[100] = "noon";
	char word2[100] = "not";

	printf("EXERCISE 1\n");
	printf("%d ", IsPalindrome(word1));
	printf("%d ", IsPalindrome(word2));

	printf("\n\nEXERCISE 2\n");
	char song[1000] = "god of nations at thy feet";
	char here[1000] = "The University of Auckland";
	char also[1000] = "a,b,c      888       d!e!f";

	Capitalise(song);
	Capitalise(here);
	Capitalise(also);

	printf("%s \n", song);
	printf("%s \n", here);
	printf("%s \n", also);

	printf("\n\nEXERCISE 3\n");

	char word[100] = "apple";
	char pattern[100] = "a-p-e";
	printf("%d", WordMatchesPattern(word, pattern));

	return 0;
}


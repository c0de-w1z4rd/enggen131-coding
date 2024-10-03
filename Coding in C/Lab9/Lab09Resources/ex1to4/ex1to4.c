#include <stdio.h>

/* This file contains the function definitions for Lab 9.
Initially, each function definition is "commented out".
This means that a comment (//) is used to remove the code
from the program.  When you are ready to implement a task,
just "un-comment" it, and then write some test code in the
main function to test it.  When you are ready, you can then
mark your function using CodeRunner - remember you only need
to submit the function definition to CodeRunner.
*/

int CountOnes(int values[], int numValues)
{
	int instances, i;
	instances = 0;
	for (i = 0; i < numValues; i++) {
		if (values[i] == 1) {
			instances++;
		}
	}
	return instances;
}


int LastIndexOf(int search, int values[], int numValues)
{
	int position = -1;
	for (int i = 0; i < numValues; i++) {
		if (values[i] == search) {
			position = i;
		}
	}
	return position;
}


int SignBalance(int values[])
{
	int tally, value, i, total;
	tally = 0;
	value = 1;
	i = 0;
	total = 0;
	while (value != 0) {
		value = values[i];
		if (value < 0) {
			tally--;
		}
		if (value > 0) {
			tally++;
		}
		i++;
	}
	if (tally > 0) {
		total = 1;
	}
	if (tally < 0) {
		total = -1;
	}
	return total;
}



void ReverseArray(int* values, int length)
{
	int reverse[100];
	for (int i = (length - 1); i >= 0; i--) {
		reverse[i] = values[length - (i + 1)];
	}
	for (int i = 0; i < length; i++) {
		values[i] = reverse[i];
	}
}




/* Here is the main function for the program.  You should write
your own test code, which calls the lab functions with various inputs,
into the main function */
int main(void)
{
	printf("Hi there!  Nice to see you.\n");
	printf("Here is a test program for Lab 9.\n");
	int testArray[10] = {0};
	testArray[0] = 1;
	testArray[1] = 2;
	testArray[2] = 3;
	testArray[3] = -3;
	testArray[4] = 7;
	testArray[5] = 0;
	ReverseArray(testArray, 6);
	printf("%d %d %d %d %d %d", testArray[0], testArray[1], testArray[2], testArray[3], testArray[4], testArray[5]);
	return 0;
}


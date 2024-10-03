#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void PrintXs(int howMany)
{
	int i;
	for (i = 0; i < howMany; i++) {
		printf("X");
	}
	return;
}

int main(void)
{
	FILE* fp;
	char filename[200];
	int scores[11] = { 0 };
	int score = 0;
	int result, number;

	printf("Enter filename:\n");
	scanf("%s", filename);
	fp = fopen(filename, "r");

	result = fscanf(fp, "%d", &score);
	while (result != EOF) {
		number = score / 10;
		scores[number] = scores[number] + 1;
		result = fscanf(fp, "%d", &score);
	}
	printf("0  : ");
	PrintXs(scores[0]);

	printf("\n10 : ");
	PrintXs(scores[1]);

	printf("\n20 : ");
	PrintXs(scores[2]);

	printf("\n30 : ");
	PrintXs(scores[3]);

	printf("\n40 : ");
	PrintXs(scores[4]);

	printf("\n50 : ");
	PrintXs(scores[5]);

	printf("\n60 : ");
	PrintXs(scores[6]);

	printf("\n70 : ");
	PrintXs(scores[7]);

	printf("\n80 : ");
	PrintXs(scores[8]);

	printf("\n90 : ");
	PrintXs(scores[9]);

	printf("\n100: ");
	PrintXs(scores[10]);

	fclose(fp);
	return 0;
}
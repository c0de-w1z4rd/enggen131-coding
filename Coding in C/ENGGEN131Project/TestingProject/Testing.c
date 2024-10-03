# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

typedef struct {
	int width;
	int height;
} Rectangle;

void PrintSquare(int n)
{
	printf("%d", n * n);
}

int Square(int n)
{
	int result;
	result = n * n;
	return result;
}

int LargerRectangle(Rectangle r1, Rectangle r2)
{
	int area1, area2, result;
	area1 = r1.width * r1.height;
	area2 = r2.width * r2.height;
	if (area1 > area2) {
		result = area1;
	}
	else {
		result = area2;
	}
	return result;
}

int SumBetween(int low, int high)
{
	int sum, i;
	sum = 0;
	for (i = low; i <= high; i++) {
		sum = sum + i;
	}
	return sum;
}

int LargestRoom(int carpetArea)
{
	int size = 1;
	while ((size * size) <= carpetArea) {
		size++;
	}
	return (size - 1);
}

int MiddleOfThree(int a, int b, int c)
{
	int middle;
	if ((a <= b && a >= c) || (a <= c && a >= b)) {
		middle = a;
	}
	if ((b <= a && b >= c) || (b <= c && b >= a)) {
		middle = b;
	}
	if ((c <= b && c >= a) || (c <= a && c >= b)) {
		middle = c;
	}
	return middle;
}

int main(void)
{
	int result = MiddleOfThree(7, 5, 4);
	printf("Result = %d", result);
	return 0;
}
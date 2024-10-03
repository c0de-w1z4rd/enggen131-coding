#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_ROWS 8
#define NUM_COLS 8

#define SPACE 0
#define WALL -1
#define EXIT -2

void InitialiseRoad(int road[NUM_ROWS][NUM_COLS], char side, int pos)
{
	// Makes the road, using constants to define what the walls are made of.
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			if (i == 0 || i == (NUM_ROWS - 1) || j == 0 || j == (NUM_COLS - 1)) {
				road[i][j] = WALL;
			}
			else {
				road[i][j] = SPACE;
			}
		}
	}
	// The position of the exit is on the side stated by the side variable (NESW)
	// and pos number of tiles away from the top or left, depending on side
	if (side == 'N') {
		road[0][pos] = EXIT;
	}
	else if (side == 'S') {
		road[NUM_ROWS - 1][pos] = EXIT;
	}
	else if (side == 'W') {
		road[pos][0] = EXIT;
	}
	else {
		road[pos][NUM_COLS - 1] = EXIT;
	}
}

void PrintRoad(int road[NUM_ROWS][NUM_COLS])
{
	// Prints the road. Also uses the constants to define what each character means
	// That said, the printed result is hardcoded.
	int i, j;
	for (i = 0; i < NUM_ROWS; i++) {
		for (j = 0; j < NUM_COLS; j++) {
			if (road[i][j] == WALL) {
				printf("#");
			}
			else if (road[i][j] == SPACE) {
				printf(" ");
			}
			else if (road[i][j] == EXIT) {
				printf("O");
			}
			else {
				printf("%c", road[i][j]);
			}
		}
		// Almost forgot to split the lines.
		printf("\n");
	}
}

double PercentUsed(int road[NUM_ROWS][NUM_COLS])
{
	// Checks how much of the internal area is taken up by cars
	int area = (NUM_ROWS - 2) * (NUM_COLS - 2);
	int filled = 0;
	int i, j;
	// Using nested loop
	for (i = 1; i < (NUM_ROWS - 1); i++) {
		for (j = 1; j < (NUM_COLS - 1); j++) {
			if (road[i][j] != SPACE) {
				filled++;
			}
		}
	}
	// Returning as a percentage (out of 100)
	return 100 * (double)filled / (double)area;
}

void AddCar(int road[NUM_ROWS][NUM_COLS], int row, int col, int size)
{
	// Makes a car, if one isn't in the space it wants to take up
	char letter = 'A';
	int i, j;
	// Step one: Check which letter should be used via nested loop
	// Note use of internal space, to avoid checking walls and exit
	for (i = 1; i < (NUM_ROWS - 1); i++) {
		for (j = 1; j < (NUM_COLS - 1); j++) {
			// This sets letter to one higher than highest existing character within internal space
			// Also recognises and ignores empty space character in case space gets changed to be higher than capital letters
			if (road[i][j] >= letter && road[i][j] != SPACE) {
				letter = road[i][j] + 1;
			}
		}
	}
	// For this next part, I'll divide the code into two parts depending on whether it's vertical or horizontal.
	if (size > 0) {
		// Positive integer == oriented horizontally
		// Check if space is clear and not outside boundaries (don't want unlikely garbage values messing things up)
		for (i = col; i < (col + size); i++) {
			if (road[row][i] != SPACE || row > NUM_ROWS || row < 0 || i > NUM_COLS || i < 0) {
				return; // Exits function without running anything ahead
			}
		}
		// Space is valid, so now actually put the car there
		for (i = col; i < (col + size); i++) {
			road[row][i] = letter;
		}
	}
	else {
		// Negative integer == oriented vertically
		// To avoid anything messing up due to negative size, I'll first invert size
		size = -1 * size;
		// Now the same thing as for positive size, but on the vertical axis instead
		// Note that use of j is arbitrary to distinguish it from i in the horizontal section
		for (j = row; j < (row + size); j++) {
			if (road[j][col] != SPACE || j > NUM_ROWS || j < 0 || col > NUM_COLS || col < 0) {
				return;
			}
		}
		for (j = row; j < (row + size); j++) {
			road[j][col] = letter;
		}
	}
}

void FindCar(int road[NUM_ROWS][NUM_COLS], char move, int *rowStart, int *colStart, int *rowEnd, int *colEnd)
{
	// Finds and places the positions of two ends of a car in the pointer variables
	int i, j;
	*rowStart = NUM_ROWS;
	*colStart = NUM_COLS;
	// Searches through sequentially
	for (i = 1; i < (NUM_ROWS - 1); i++) {
		for (j = 1; j < (NUM_COLS - 1); j++) {
			if (road[i][j] == move) {
				// Extra code will be needed to ensure the first ones found stay in the start variables
				if (i < *rowStart) {
					*rowStart = i;
				}
				if (j < *colStart) {
					*colStart = j;
				}
				// End variables will just be the last ones seen (due to how the loops are set up)
				*rowEnd = i;
				*colEnd = j;
			}
		}
	}
}

int MoveCar(int road[NUM_ROWS][NUM_COLS], int r0, int c0, int r1, int c1)
{
	// Takes the car with the given positional coordinates and moves it
	// Always moves left or up if able to
	// Returns 1 if car hits exit or 0 otherwise
	// I'll start by figuring out if it's vertical or horizontal
	if (r0 == r1) {
		// horizontal (everything on the same row)
		// Step 2 is to check if the car should be moving left, right or not at all
		// Followed by moving it as far as it will go
		if (road[r0][c0 - 1] == SPACE) {
			while (road[r0][c0 - 1] == SPACE) {
				road[r0][c0 - 1] = road[r0][c0]; // That's the letter of the car
				road[r0][c1] = SPACE; // Car adds one on left and removes one on right - effectively shifts left
				c0 = c0 - 1;
				c1 = c1 - 1; // Updates internal parameters for next loop
			} // At the end of this loop it should have moved as far as it can
			if (road[r0][c0 - 1] == EXIT) {
				return 1; // If this triggers, car has exited and game is won
			}
			else {
				return 0; // Either a wall or another car block further movement
			}
		}
		else if (road[r0][c1 + 1] == SPACE) {
			// Same as above loop, but to the right instead of the left
			while (road[r0][c1 + 1] == SPACE) {
				road[r0][c1 + 1] = road[r0][c1];
				road[r0][c0] = SPACE; // Car adds one on right and removes one on left to simulate shifting right
				c0 = c0 + 1;
				c1 = c1 + 1; // Updates internal parameters for next loop
			} // At the end of this loop it should have moved as far as it can
			if (road[r0][c1 + 1] == EXIT) {
				return 1; // If this triggers, car has exited and game is won
			}
			else {
				return 0; // Either a wall or another car block further movement
			}
		}
		else {
			// Nothing triggered - car can't move so just return 0
			return 0;
		}
	}
	else {
		// vertical (change in rows)
		// Check if car can move up. If so, move up. If not, check if can move down. If so, move down. If not, exit loop.
		if (road[r0 - 1][c0] == SPACE) { // Check if it can move up
			while (road[r0 - 1][c0] == SPACE) { // It can move up, so keep running until it can't
				road[r0 - 1][c0] = road[r0][c0]; // Move top up by one
				road[r1][c0] = SPACE; // Cut off bottom
				r0 = r0 - 1; // Update new top and bottom parameters
				r1 = r1 - 1;
			}
			if (road[r0 - 1][c0] == EXIT) { // Car exits - game is won
				return 1;
			}
			else {
				return 0;
			}
		}
		else if (road[r1 + 1][c0] == SPACE) { // Can't move up but can move down
			while (road[r1 + 1][c0] == SPACE) { // Run until it can't move down
				road[r1 + 1][c0] = road[r1][c0];
				road[r0][c0] = SPACE; // Car is moved down by one
				r0 = r0 + 1;
				r1 = r1 + 1; // Update car position parameters
			}
			if (road[r1 + 1][c0] == EXIT) { // Car has hit exit
				return 1;
			}
			else { // Car has not hit exit
				return 0;
			}
		}
		else { // This triggers because the car cannot move in either direction
			return 0;
		}
	}
}


/***********************************************************/
/***********************************************************/
/******* A SIMPLE MAIN FUNCTION TO TEST YOUR PROGRESS ******/
/***********************************************************/
/***********************************************************/

/* You should add your own tests in here */
int main(void)
{
	int road[NUM_ROWS][NUM_COLS];
	int rowA, colA, rowB, colB, result;

	/* Simple test code for Tasks 1 and 2 */
	InitialiseRoad(road, 'E', 3);
	PrintRoad(road);
	AddCar(road, 3, 1, 2);
	AddCar(road, 2, 4, -4);
	AddCar(road, 5, 3, 3);
	AddCar(road, 6, 3, 3);
	PrintRoad(road);
	printf("Percent used: %f\n", PercentUsed(road));

	FindCar(road, 'A', &rowA, &colA, &rowB, &colB);
	result = MoveCar(road, rowA, colA, rowB, colB);
	printf("A moved: %d\n", result);

	FindCar(road, 'B', &rowA, &colA, &rowB, &colB);
	result = MoveCar(road, rowA, colA, rowB, colB);
	printf("B moved: %d\n", result);

	FindCar(road, 'C', &rowA, &colA, &rowB, &colB);
	result = MoveCar(road, rowA, colA, rowB, colB);
	printf("C moved: %d\n", result);

	PrintRoad(road);

	return 0;
}

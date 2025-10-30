// Hallie Gurr - CS 135
	// Final Project (Week 10: 7/17-7/26/2024)
		// Description: Half of Battleship

#include <stdio.h>
#define GRID_SIZE 10
#define FLEET_FILE "easy.txt"

// FUNCTION PROTOTYPES
void initGrid(char board[][GRID_SIZE]);
void loadFleet(FILE *file, char fleet[][GRID_SIZE]);
void displayGrid(char board[][GRID_SIZE]);
void playerGuess(int *row, int *col);
void updateGrid(int row, int col, char board[][GRID_SIZE], char fleet[][GRID_SIZE]);
int gameOver(char fleet[][GRID_SIZE]);

// MAIN FUNCTION
int main(){
	char board[GRID_SIZE][GRID_SIZE];
	char fleet[GRID_SIZE][GRID_SIZE];
	int row, col;
	int shots = 0;
	int game = 0;
	char playAgain;
	
	do{
		printf("\n*****LET'S PLAY BATSHIP*****\n\n");
	
		initGrid(board);
	
		FILE *file;
		file = fopen(FLEET_FILE, "r");
		if(file == NULL){
			printf("File cannot open.\n");
			return 1;	
		}
		loadFleet(file, fleet);
		fclose(file);
	
		do{
			displayGrid(board);
			playerGuess(&row, &col);
			updateGrid(row, col, board, fleet);
			shots++;
			game = gameOver(fleet);
		} while (game == 0);
	
	printf("It took %d turns for you to hit 31 spots and destroy all the ships\n", shots);
	
		printf("Play again? (Y/N) ");
		scanf(" %c", &playAgain);
	} while (playAgain == 'Y');
	
	return 0;
}

// FUNCTION DEFINITIONS
void initGrid(char board[][GRID_SIZE]){
	for(int row = 0; row < GRID_SIZE; row++){
		for(int col = 0; col < GRID_SIZE; col++){
			board[row][col] = ' ';
		}
	}
}

void loadFleet(FILE *file, char fleet[][GRID_SIZE]){
	char placements[GRID_SIZE + 1];
	
	for(int row = 0; row < GRID_SIZE; row++){
		if(fgets(placements, sizeof(placements), file) != NULL){
			for(int col = 0; col < GRID_SIZE; col++){
			fleet[row][col] = placements[col];
			}
		}
	}
}

void displayGrid(char board[][GRID_SIZE]){
	// Column Letters
	printf("   ");
	for(int col = 0; col < GRID_SIZE; col++){
		printf("%c ", 'A' + col);
	}
	printf("\n");
	// Row Numbers
	for(int row = 0; row < GRID_SIZE; row++){
		if(row < 9){
			printf("%d  ", row + 1);
		} else {
			printf("%d ", row + 1);
		}
		for(int col = 0; col < GRID_SIZE; col++){
			printf("%c ", board[row][col]);
		}
	printf("\n");
	}
}

void playerGuess(int *row, int *col){
	char letter;
	printf("        FIRE AWAY!\n");
	printf("(enter a spot in the grid like A1) ");
	scanf(" %c%d", &letter, row);
	*col = letter - 'A';
	(*row)--;
	
	while(*row < 0 || *row >= GRID_SIZE || *col < 0 || *col >= GRID_SIZE){
	printf("\nInvalid column letter. Try again!\n");
	printf("(enter a spot in the grid like A1) ");
	scanf(" %c%d", &letter, row);
	*col = letter - 'A';
	(*row)--;
	printf("\n");
	}
}

void updateGrid(int row, int col, char board[][GRID_SIZE], char fleet[][GRID_SIZE]){
	if(fleet[row][col] == 'S'){
		board[row][col] = 'X';
	} else {
		board[row][col] = 'O';
	}
}

int gameOver(char fleet[][GRID_SIZE]){
	for (int row = 0; row < GRID_SIZE; row++){
		for (int col = 0; col < GRID_SIZE; col++){
			if(fleet[row][col] == 'S'){
				return 0;
			}
		}
	}
	return 1;
}

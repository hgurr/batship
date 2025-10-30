# Batship — A Simplified Battleship Game in C

## Overview
**Batship** is a lightweight terminal-based game inspired by *Battleship*.  
The program simulates one half of the classic game: the user plays against a fixed board and attempts to locate and "hit" all ship positions using 2D coordinate input.

The project demonstrates:
- Implementation of **2D arrays** in C  
- Use of **loops, conditionals, and functions** for control flow  
- Real-time **board updates** and **input validation**  
- Modular design with multiple functions beyond `main()`

---

## Objective
Develop a grid-based guessing game that:
- Tracks hits and misses on a 2D grid  
- Displays an updated game board after each move  
- Ends when all ship segments are hit  
- Allows the player to replay after completing a round  

---

## Features
- **Grid-based playfield** represented with a 2D array  
- **Player interaction** through terminal input  
- **Input validation** for coordinate range  
- **Real-time visual feedback:**  
  - `X` → hit  
  - `O` → miss  
  - `.` → untouched cell  
- **Replay option** after a completed game  

---

## Example Gameplay

```

## Welcome to Batship!

Current Board:
. . . . .
. . . . .
. . . . .
. . . . .
. . . . .

Enter coordinates to fire (row col): 2 3
Miss!

Current Board:
. . . . .
. . . . .
. . . O .
. . . . .
. . . . .

Enter coordinates to fire (row col): 1 1
Hit!

Current Board:
. . . . .
. X . . .
. . . O .
. . . . .
. . . . .

You’ve sunk all the ships!
Your score: 14 moves
Play again? (y/n): y

````

---

## Implementation Details

**Language:** C  
**File:** `batship.c`  
**Compilation Command:**
```bash
gcc -o batship batship.c
````

**Run:**

```bash
./batship
```

---

## Functional Breakdown

The program consists of at least **five functions in addition to `main()`**.
Example design:

| Function            | Purpose                                                     |
| ------------------- | ----------------------------------------------------------- |
| `initializeBoard()` | Sets up the 2D array with blank cells and hidden ships.     |
| `displayBoard()`    | Prints the current visible game state (hits/misses).        |
| `getPlayerMove()`   | Prompts and validates user input.                           |
| `processMove()`     | Determines if a hit or miss occurred and updates the board. |
| `checkWin()`        | Checks if all ships have been hit.                          |
| `playAgain()`       | Handles replay logic.                                       |

All 2D arrays are indexed from `0` to `size - 1`.

---

## Restrictions and Design Rules

To ensure the program focuses on fundamental C concepts, the following constraints were followed:

### Allowed Libraries

* `<stdio.h>`
* `<stdbool.h>`

### Not Used

* Any other external or helper libraries
* Dynamic memory allocation
* Global variables for game logic

### Required Design Choices

* At least **5 user-defined functions** beyond `main()`
* Use **2D arrays in conventional index form** (`board[row][col]`)
* Input validation ensures:

  * Rows and columns are within valid range
  * User re-prompts if values are out of bounds

---

## Data Representation

| Symbol | Meaning      |
| ------ | ------------ |
| `.`    | Unfired cell |
| `X`    | Hit          |
| `O`    | Miss         |

Internally, ships can be represented by integer or boolean values within a hidden 2D array (e.g., `1` = ship, `0` = empty).

---

## Example Board Setup

For simplicity, ship locations may be hardcoded:

```c
int ships[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 0, 0, 0, 0},
    {0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0}
};
```

---

## Future Enhancements

* Randomized ship placement
* Two-player mode
* Scoring persistence between games
* Dynamic grid sizing

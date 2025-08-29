#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>  // For Sleep()

using namespace std;

const int ROWS = 10;
const int COLS = 20;
const char EMPTY = ' ';
const char BOMB = 'O';
const char SHIP = '^';

void initializeGrid(char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = EMPTY;
        }
    }
}

void displayGrid(char grid[ROWS][COLS], int shipPos) {
    system("CLS");  // Clear the screen

    // Display the grid with bombs and ship
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    // Display the ship's position at the bottom
    for (int j = 0; j < COLS; j++) {
        if (j == shipPos)
            cout << SHIP;
        else
            cout << EMPTY;
    }
    cout << endl;
}

void dropBomb(char grid[ROWS][COLS]) {
    int col = rand() % COLS;
    grid[0][col] = BOMB;  // Drop bomb in the top row
}

void moveBombs(char grid[ROWS][COLS]) {
    for (int i = ROWS - 1; i > 0; i--) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i - 1][j] == BOMB) {
                grid[i][j] = BOMB;        // Move the bomb down
                grid[i - 1][j] = ' ';   // Clear the previous position
            }
        }
    }
}

bool checkCollision(char grid[ROWS][COLS], int shipPos, int &score) {
    for (int j = 0; j < COLS; j++) {
        if (grid[ROWS - 1][j] == BOMB) {
            if (j == shipPos) {
                score++;
                grid[ROWS - 1][j] = EMPTY;  // Clear the bomb after collision
                return true;  // Game Over on collision
            }
        }
    }
    return false;
}

int main() {
    char grid[ROWS][COLS];
    int shipPos = COLS / 2; // Start in the middle
    int score = 0;
    bool gameOver = false;

    srand(time(0)); // Seed random number generator

    initializeGrid(grid);

    // Drop a bomb at the start
    dropBomb(grid);

    while (!gameOver) {
        moveBombs(grid);  // Move all bombs down

        displayGrid(grid, shipPos);  // Display the grid
        cout << "Score: " << score << endl;
        cout << "Move ship with 'a' (left) and 'd' (right). Press 'q' to quit." << endl;

        // Input handling using standard cin (blocking)
        char input;
        if (cin.peek() != EOF) {
            cin >> input;  // Get user input

            if (input == 'a' && shipPos > 0) {
                shipPos--;  // Move ship left
            }
            else if (input == 'd' && shipPos < COLS - 1) {
                shipPos++;  // Move ship right
            }
            else if (input == 'q') {
                gameOver = true;  // Exit the game
                cout << "Game Over! Final Score: " << score << endl;
                break;
            }
        }

        // Drop a new bomb every time through the loop
        dropBomb(grid);

        gameOver = checkCollision(grid, shipPos, score);  // Check for collisions

        Sleep(100);  // Sleep for 100 milliseconds (you can adjust this to control game speed)
    }

    return 0;
}

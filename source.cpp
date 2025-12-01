#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

/* Global variable */
bool isGameOver = false;

class SnakeGame {
private:
    const int width = 80;
    const int height = 20;

    int headX, headY;
    int fruitX, fruitY;
    int playerScore;
    int snakeTailX[200], snakeTailY[200];
    int snakeTailLen;

    enum snakeDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    snakeDirection dir;

public:
    SnakeGame() {
        isGameOver = false;
        playerScore = 0;

        headX = width / 2;
        headY = height / 2;

        fruitX = rand() % (width - 2) + 1;
        fruitY = rand() % (height - 1);

        snakeTailLen = 0;
        dir = STOP;
    }

    void gameBoard(const string &playerName) {
       // system("cls");
       clearScreenWithoutFlicker();


        cout << playerName << "'s Score: " << playerScore << "\n";

        for (int i = 0; i < width + 2; i++)
            cout << "-";
        cout << "\n";

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {

                if (j == 0) cout << "|";

                if (i == headY && j == headX)
                    cout << "O";     // head
                else if (i == fruitY && j == fruitX)
                    cout << "#";     // fruit
                else {
                    bool printed = false;
                    for (int k = 0; k < snakeTailLen; k++) {
                        if (snakeTailX[k] == j && snakeTailY[k] == i) {
                            cout << "o";
                            printed = true;
                        }
                    }
                    if (!printed) cout << " ";
                }

                if (j == width - 1) cout << "|";
            }
            cout << "\n";
        }

        for (int i = 0; i < width + 2; i++) cout << "-";
        cout << "\n";

        cout.flush();
    }

    void processInput() {
        if (_kbhit()) {
            int key = _getch();     //getting special key for using arrow keys

            if (key == 224) {      // special arrow key detected
                key = _getch();    // read real arrow code

                switch (key) {
                case 75: if (dir != RIGHT)
                            dir = LEFT;
                        break;
                case 77: if (dir != LEFT)
                            dir = RIGHT;
                        break;
                case 72: if (dir != DOWN)
                            dir = UP;
                        break;
                case 80: if (dir != UP)
                            dir = DOWN;
                        break;
                }
            }
            else if (key == 'x' || key == 'X')
                isGameOver = true;
        }
    }

    void updateGame() {
        // Tail follows the head
        int prevX = headX;
        int prevY = headY;

        for (int i = 0; i < snakeTailLen; i++) {
            int tempX = snakeTailX[i];
            int tempY = snakeTailY[i];

            snakeTailX[i] = prevX;
            snakeTailY[i] = prevY;

            prevX = tempX;
            prevY = tempY;
        }

        // Updating head position
        switch (dir) {
            case LEFT:  headX--; break;
            case RIGHT: headX++; break;
            case UP:    headY--; break;
            case DOWN:  headY++; break;
            default: break;
        }

        // Wall collision
        if (headX < 0 || headX >= width || headY < 0 || headY >= height)
            isGameOver = true;

        // Self collision
        for (int i = 0; i < snakeTailLen; i++) {
            if (snakeTailX[i] == headX && snakeTailY[i] == headY)
                isGameOver = true;
        }

        // Fruit eaten
        if (headX == fruitX && headY == fruitY) {
            snakeTailLen++;

            fruitX = rand() % (width - 2) + 1;
            fruitY = rand() % height;

            playerScore += 10;
        }
    }

    int setDifficulty() {
        cout << "\nSET DIFFICULTY"
             << "\n1: Easy"
             << "\n2: Medium"
             << "\n3: Hard"
             << "\nChoose Difficulty: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: return 150;
            case 2: return 100;
            case 3: return 60;
            default: return 100;
        }
    }

    void clearScreenWithoutFlicker() {
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
};

int main() {
    SnakeGame game;
    string playerName;

    cout << "Enter Player Name: ";
    cin >> playerName;

    int speed = game.setDifficulty();

    while (!isGameOver) {
        game.gameBoard(playerName);
        game.processInput();
        game.updateGame();
        Sleep(speed);
    }

    cout << "\nGAME OVER!\n";

    return 0;
}

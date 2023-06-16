#include <conio.h>
#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;
bool      gameOver;
const int width  = 30;
const int height = 30;
int       x, y, fruitX, fruitY, score;
int       tailX[100], tailY[100];
int       nTail;
enum eDirecton {
    STOP = 0, // No direction
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirecton dir;

void Setup()
{
    // Initialize global variables
    gameOver = false;
    dir      = STOP;
    x        = width / 2;
    y        = height / 2;
    fruitX   = rand() % width;
    fruitY   = rand() % height;
    nTail    = 0;
    score    = 0;
}

void Draw()
{
    system("cls"); // Clear screen
    cout << endl;
    cout << " ";
    // Print top border
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    // Traverse 2-dimensional array, which is the grid of the game
    // Print out each element based on their coordinates
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                // Print left border
                cout << "#";
            if (i == y && j == x)
                // Print snake head
                cout << "O";
            else if (i == fruitY && j == fruitX)
                // Print fruit
                cout << "F";
            else {
                // Print snake body
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    // Check among all cells of snake's tail,
                    // if cell is indeed a tail, print it
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        print = true;
                    }
                }
                // If nothing was printed, print a space instead
                // This aligns the grid
                if (!print) cout << " ";
            }
            // Print right border
            if (j == width - 1) cout << "#";
        }
        cout << endl;
    }

    cout << " ";
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;
    cout << " Score:" << score << endl;
}

void Input()
{
    // Read keys if any key was pressed
    if (_kbhit()) {
        switch (_getch()) {
        case 'b':
            dir = LEFT;
            break;
        case 'm':
            dir = RIGHT;
            break;
        case 'j':
            dir = UP;
            break;
        case 'n':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        default:
            break;
        }
    }
}

void Logic()
{
    // The following operation "pushes" the current position to the `tails` array
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    // Set the first variable of the tails to the current position
    tailX[0] = x;
    tailY[0] = y;
    // Shift every element at position `i-1` to position `i`, starting from i=1
    for (int i = 1; i < nTail; i++) {
        // This looks like:
        //
        // a = b;
        // b = c;
        // c = a;
        //
        // This cascading type of assignment is a swap between a and b.
        // This would swap tail[i-1] with tail[i], starting from i=1
        prev2X   = tailX[i];
        prev2Y   = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX    = prev2X;
        prevY    = prev2Y;
    }
    // After saving the current position,
    // move the head of the snake to the new coordinate designated by the keypress
    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    // User loses if the head of the snake hits the border
    if (x > width || x < 0 || y > height || y < 0) gameOver = true;

    // Make the snake wrap around from the otherside if the snake hits the boundary
    //
    // if (x >= width) x = 0; else if (x < 0) x = width - 1;
    // if (y >= height) y = 0; else if (y < 0) y = height - 1;

    // User loses if the snake touches itself
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y) gameOver = true;

    // If current position is a fruit
    if (x == fruitX && y == fruitY) {
        srand(time(0)); // Random seed value for rand based on time
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

int main()
{
    // Learn more about this https://stackoverflow.com/a/31165481/16509232
    // It is suggested to use flush
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Set the display mode of the console (i.e. the size of the display)
    system("MODE con cols=24 lines=25");
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(10); // Sleep for 10 (ms? not sure)
    }
    printf("game over");
    return 0;
}

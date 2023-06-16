#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h> // To make spawn value more random
using namespace std;
bool gameOver;
const int width = 30;
const int height = 30;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    nTail = 0;
    score = 0;
}
void Draw()//caution the snake
{
    system("cls"); //system("clear");
    cout << endl;
    cout << " ";
    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    cout << " ";
    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;
    cout << " Score:" << score << endl;
}
void Input()
{
    if (_kbhit())//check keyboard
    {
        switch (_getch())
        {
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
{   //**
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    //move
    for (int i = 1; i < nTail; i++)
    {//0 1
        prev2X = tailX[i];//1
        prev2Y = tailY[i];
        tailX[i] = prevX;//next=prev
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;//prev++
    }
    switch (dir)
    {
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
    if (x > width || x < 0 || y > height || y < 0)
      gameOver = true;
    //if (x >= width) x = 0; else if (x < 0) x = width - 1;
    //if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    if (x == fruitX && y == fruitY)
    {
        srand(time(0)); // Random seed value for rand based on time
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}
int main()
{
    //Will make cout much faster
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    system("MODE con cols=24 lines=25");
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(10); //sleep(10);
    }
    printf("game over");
    return 0;
}

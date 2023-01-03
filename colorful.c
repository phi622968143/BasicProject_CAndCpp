#include <stdio.h>
#include <windows.h>   // WinApi header
#include <stdlib.h>
#include <time.h>

int main()
{
  HANDLE  hConsole;
  int k;
  srand( time(NULL) );
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//call the service of controller

  // you can loop k higher to see more color choices
  while(k=rand()%256)
  {
    SetConsoleTextAttribute(hConsole, k);
    printf("%3d  %s", k, "I want to be nice today!");
     Sleep(1000);  // delay the speed of loop excute
     system("cls");
  }
  return 0;
}

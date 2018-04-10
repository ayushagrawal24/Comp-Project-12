#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

using namespace std;

//GLOBALS

struct Pos{
   int i, j;
} pos = {12, 19};

//2D space of the game. Stores objects
int space[25][50] = {};

//shifts the values by one
void Move(char ch){
   //left
   if (ch == 'a'){
      for(int r = pos.i; r <= pos.i+1; r++){
         for (int c = pos.j; c <= pos.j+6; c++)
            space[r][c] = space[r][c+1];
      }
      pos.j--;
   }
   //up
   else if (ch == 'w'){
      for(int c = pos.j; c <= pos.j+6; c++){
         for (int r = pos.i-2; r <= pos.i+2; r++)
            space[r][c] = space[r+1][c];
      }
      pos.i--;
   }
   //right
   if (ch == 'd'){
      for(int r = pos.i; r <= pos.i+1; r++){
         for (int c = pos.j+7; c >= pos.j; c--)
            space[r][c] = space[r][c-1];
      }
      pos.j++;
   }
   //down
   else if (ch == 's'){
      for(int c = pos.j; c <= pos.j+6; c++){
         for (int r = pos.i+2; r >= pos.i; r--)
            space[r][c] = space[r-1][c];
      }
      pos.i++;
   }
}

char ReturnChar(int x){
   if (x == 1)
      return '/';
   else if (x == 2)
      return '\\';
   else if (x == 3)
      return '_';
   else if (x == 4)
      return '|';

   return ' ';
}

void DisplaySpace(){

   for (int i = 0; i < 25; i++){
      for (int j = 0; j < 50; j++){
         cout << ReturnChar(space[i][j]);
      }
      cout << "\n";
   }
}

int main(){

   //user input
   char inp;

   //initialising position of spacecraft elements
   space[12][22] = 1;
   space[13][21] = 1;        // forward slash - '/'

   space[12][23] = 2;        // backward slash - '\'
   space[13][24] = 2;

   space[13][22] = 3;        // underscore - '_'
   space[13][23] = 3;

   space[13][20] = 4;        // vertical bar - '|'
   space[13][25] = 4;

   /* spacecraft:
        /\
      |/__\|
   */

   for (int i = 0; i < 100; i++){
      DisplaySpace();
      //Sleep(10);
      if (kbhit()){
         inp = getch();
         Move(inp);
      }
      system("cls");
   }

   return 0;
}

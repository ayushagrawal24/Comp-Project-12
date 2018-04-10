#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define spacecraft s

using namespace std;

//GLOBALS

struct Pos{
   int i, j;
};

class Space{
   static char ReturnChar(int);

protected:
   static int area[25][50];
   void Move(char, Pos&, int, int);

public:
   static void DisplaySpace();
   Space(){
      for(int i = 0; i < 25; i++){
         for (int j = 0; j < 50; j++){
            area[i][j] = 0;
         }
      }
   }
};

int Space::area[25][50] = {};


//shifts the values by one
void Space::Move(char ch, Pos &pos, int h, int w){
   //left - a
   if (ch == 'a'){
      for(int r = pos.i; r < pos.i + h; r++){
         for (int c = pos.j; c <= pos.j+w; c++)
            area[r][c] = area[r][c+1];
      }
      pos.j--;
   }
   //up - w
   else if (ch == 'w'){
      for(int c = pos.j; c <= pos.j+w; c++){
         for (int r = pos.i-1; r < pos.i+h; r++)
            area[r][c] = area[r+1][c];
      }
      pos.i--;
   }
   //right - d
   if (ch == 'd'){
      for(int r = pos.i; r < pos.i+h; r++){
         for (int c = pos.j+w+1; c >= pos.j; c--)
            area[r][c] = area[r][c-1];
      }
      pos.j++;
   }
   //down
   else if (ch == 's'){
      for(int c = pos.j; c <= pos.j+w; c++){
         for (int r = pos.i+h; r >= pos.i; r--)
            area[r][c] = area[r-1][c];
      }
      pos.i++;
   }
}


char Space::ReturnChar(int x){
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


void Space::DisplaySpace(){

   cout << "|";
   for(int i = 0; i < 50; i++)
      cout << "-";
   cout << "|\n";

   for (int i = 0; i < 25; i++){
      cout << "|";
      for (int j = 0; j < 50; j++){
         cout << ReturnChar(area[i][j]);
      }
      cout << "|\n";
   }

   cout << "|";
   for(int i = 0; i < 50; i++)
      cout << "-";
   cout << "|\n";
}


class Spacecraft : public Space{
   int height, width;
   Pos pos;

public:
   void Move(char);
   Spacecraft(int h, int w){
      height = h;
      width = w;
      pos = {22, 19};

      area[22][22] = 1;
      area[23][21] = 1;        // forward slash - '/'

      area[22][23] = 2;        // backward slash - '\'
      area[23][24] = 2;

      area[23][22] = 3;        // underscore - '_'
      area[23][23] = 3;

      area[23][20] = 4;        // vertical bar - '|'
      area[23][25] = 4;
   }
};

void Spacecraft::Move(char ch){
   Space::Move(ch, pos, height, width);
}

int main(){

   //user input
   char inp;

   Spacecraft spacecraft(2, 6);

   for (int i = 0; i < 100; i++){
      Space::DisplaySpace();
      Sleep(1000);
      if (kbhit()){
         inp = getch();
         spacecraft.Move(inp);
      }
      system("cls");
   }

   return 0;
}

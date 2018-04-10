#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define rows 25
#define cols 80

using namespace std;

//GLOBALS

struct Pos{
   int i, j;
};

class Space{
   static char ReturnChar(int);

protected:
   static char area[rows][cols];
   void Move(char, Pos&, int, int);

public:
   static void DisplaySpace();
   Space(){
      for(int i = 0; i < rows; i++){
         for (int j = 0; j < cols; j++){
            area[i][j] = ' ';
         }
      }
   }
};

char Space::area[rows][cols] = {};


//shifts the values by one
void Space::Move(char ch, Pos &pos, int h, int w){

   //left - a
   if (ch == 'a' && pos.j >= 0){
      for(int r = pos.i; r < pos.i + h; r++){
         for (int c = pos.j; c <= pos.j+w; c++)
            area[r][c] = area[r][c+1];
      }
      pos.j--;
   }
   //right - d
   else if (ch == 'd' && pos.j + w + 1 < cols){
      for(int r = pos.i; r < pos.i+h; r++){
         for (int c = pos.j+w+1; c >= pos.j; c--)
            area[r][c] = area[r][c-1];
      }
      pos.j++;
   }
}


void Space::DisplaySpace(){

   cout << "|";
   for(int i = 0; i < cols; i++)
      cout << "-";
   cout << "|\n";

   for (int i = 0; i < rows; i++){
      cout << "|";
      for (int j = 0; j < cols; j++){
         cout << area[i][j];
      }
      cout << "|\n";
   }

   cout << "|";
   for(int i = 0; i < cols; i++)
      cout << "-";
   cout << "|\n";
}


class Spacecraft : public Space{
   int height, width;
   Pos pos;

public:
   void Control(char);
   void Shoot();
   Spacecraft(){
      height = 2;
      width = 6;
      pos = {22, 34};

      area[22][37] = '/';
      area[23][36] = '/';        // forward slash - '/'

      area[22][38] = '\\';        // backward slash - '\'
      area[23][39] = '\\';

      area[23][37] = '_';        // underscore - '_'
      area[23][38] = '_';

      area[23][35] = '|';        // vertical bar - '|'
      area[23][40] = '|';
   }
};

void Spacecraft::Control(char ch){
   if(ch == 'a' || ch == 'd')
      Move(ch, pos, height, width);
   else if(ch == ' ')
      Shoot();
}

int main(){

   //user input
   char inp;

   Spacecraft spacecraft;

   for (int i = 0; i < 1000; i++){
      Space::DisplaySpace();
      Sleep(100);
      if (kbhit()){
         inp = getch();
         spacecraft.Control(inp);
      }
      system("cls");
   }

   return 0;
}

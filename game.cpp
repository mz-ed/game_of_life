#include<raylib.h>
#include <iostream>
#include "simulation.hpp"

int main(){
    Color darkgreen = Color{20,160,133,200};

    const int screenwidth = 750;

    const int screenhight = 750;
    int FPS = 12;
    const int CELL_SIZE = 25 ;
   
    InitWindow(screenwidth,screenhight,"Game of life");
    SetTargetFPS(FPS);
    Simulation simulation(screenwidth,screenhight,CELL_SIZE); 
   


  

      while(WindowShouldClose() == false){
      simulation.Update();
      BeginDrawing();
      ClearBackground(GRAY);
      simulation.Draw();
      EndDrawing();  
      }

       CloseWindow();
}

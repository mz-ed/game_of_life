#include<raylib.h>
#include "simulation.hpp"

int main(){
    Color darkgreen = Color{20,160,133,200};

    const int screenwidth = 750;
    const int screenhight = 750;
    int FPS = 60;
    const int CELL_SIZE = 25 ;
   
    InitWindow(screenwidth,screenhight,"Game of life");
    SetTargetFPS(FPS);
    Simulation simulation(screenwidth,screenhight,CELL_SIZE); 
   

    simulation.SetCellValue(1,1,1);
    simulation.SetCellValue(2,1,2);
      while(WindowShouldClose() == false){
      BeginDrawing();
      ClearBackground(GRAY);
      simulation.Draw();
      EndDrawing();  
      }

       CloseWindow();
}

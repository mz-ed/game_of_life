#include<raylib.h>
#include <iostream>
#include "simulation.hpp"

int main(){
    Color darkgreen = Color{20,160,133,200};

    const int screenwidth = 1200;

    const int screenhight = 800;
    int FPS = 12;
    const int CELL_SIZE = 4 ;
   
    InitWindow(screenwidth,screenhight,"Game of life");
    SetTargetFPS(FPS);
    Simulation simulation(screenwidth,screenhight,CELL_SIZE); 
    simulation.Start();
      while(WindowShouldClose() == false){

      if(IsKeyPressed(KEY_SPACE) && simulation.IsRunning() == false)
      {
          simulation.Start();
          SetWindowTitle("Game of life is running ...");
        }else if(IsKeyPressed(KEY_SPACE) && simulation.IsRunning() == true)
        {
            simulation.Stop();
            SetWindowTitle("Game of life is paused ...");
        }
      
      if(IsKeyPressed(KEY_UP))
      {
          FPS += 3;
          SetTargetFPS(FPS);
      }
      if(IsKeyPressed(KEY_DOWN))
      {
          FPS -= 3;
          SetTargetFPS(FPS);
      }

      simulation.Update();
      BeginDrawing();
      ClearBackground(GRAY);
      simulation.Draw();
      EndDrawing();  
      }

       CloseWindow();
}

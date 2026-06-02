#pragma once
#include "grid.hpp"

class Simulation
{
    public:
        Simulation(int width, int height,int cellSize)
        : grid(width, height, cellSize) , tempGrid(width, height, cellSize), run(false) {grid.FillRandom();};
        void Draw();
        void SetCellValue(int row, int column, int value);
        int CountLiveNieghbors(int row, int columns);
        void Update();
        bool IsRunning() {return run;}
        void Start() {run = true;}
        void Stop() {run = false;}
    private:
        Grid grid;
        Grid tempGrid;
        bool run;
};

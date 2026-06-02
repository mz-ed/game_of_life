#pragma once
#include "grid.hpp"

class Simulation
{
    public:
        Simulation(int width, int height,int cellSize)
        : grid(width, height, cellSize) , tempGrid(width, height, cellSize) {grid.FillRandom();};
        void Draw();
        void SetCellValue(int row, int column, int value);
        int CountLiveNieghbors(int row, int columns);
        void Update();
    private:
        Grid grid;
        Grid tempGrid;

};

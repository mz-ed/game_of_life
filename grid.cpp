#include <raylib.h>
#include "grid.hpp"


void Grid::Draw()
{
for( int row = 0 ; row < rows ; row++)
    for( int column = 0; column < columns ; column++ )
    {
      Color color = cells[row][column] ? Color {0, 255, 0, 255} : Color {55, 55, 55, 55};
      DrawRectangle(column * cellSize , row * cellSize , cellSize - 1, cellSize - 1, color);
    }

}
void Grid::SetValue(int row, int column, int value)
{
    if(row >= 0 && row < rows && column >= 0 && column < columns )
    {
        cells[row][column] = value;

    }
}

int Grid::Getvalue(int row , int column)
{
    if(IsWithinBounds(row, column))
    {
        return cells[row][column];
    }
    return 0 ;
}

bool Grid::IsWithinBounds(int row , int column){
    if(row >= 0 && row < rows && column >= 0 && column < columns )
    { 
        return true; 
    }
        return false;

}

void Grid::FillRandom()
{
 for(int row = 0 ; row < rows; row++)
    {
      for(int column = 0 ; column < columns; column++)
        {
            int randomstate = GetRandomValue(0, 4);
            cells[row][column] = (randomstate == 4) ? 1 : 0;
        }
    }
}

#include "simulation.hpp"
#include <vector>
#include <utility>

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value)
{
    grid.SetValue(row, column, value); 

}

int Simulation::CountLiveNieghbors(int row, int column)
{
   int LiveNeighbors = 0;
   std::vector<std::pair<int, int>> neighboroffset = 
   {
       {0,1},
       {0,-1},
       {1,0},
       {-1,0},
       {-1,-1},
       {1,1},
       {-1,1},
       {1,-1}
   };
  
  for(const auto& offset : neighboroffset)
  {
      int neighborsrow = (row + offset.first + grid.Getrows()) % grid.Getrows() ;
      int neighborscolumn = (column + offset.second + grid.Getcolumns()) % grid.Getcolumns() ;
      LiveNeighbors += grid.Getvalue(neighborsrow  , neighborscolumn);
  }

  return LiveNeighbors;
}

void Simulation::Update()
{
    for(int row = 0 ; row < grid.Getrows(); row++)
    {
        for(int column = 0 ; column < grid.Getcolumns(); column++)
        {
            int liveneighbors = CountLiveNieghbors(row,column);
            int cellval = grid.Getvalue(row , column);
            if(cellval == 1)
            {
                if(liveneighbors > 3 || liveneighbors < 2)
                { 
                    tempGrid.SetValue(row , column , 0);
                }else
                {
                    tempGrid.SetValue(row , column , 1);
                }
            }else{
                if(liveneighbors == 3){
                    tempGrid.SetValue(row , column , 1);
                }else{
                    tempGrid.SetValue(row , column , 0);
                }

            }
        }
    }

    grid = tempGrid;

}




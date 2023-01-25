#include <cstdio>
#include <vector>

int searchMax(std::vector<std::vector<int>>& grid, int& xMax, int& yMax, int x, int y)
{
    return grid[y][x]--
        + ((y-1 >= 0 && grid[y-1][x] == 1) ? searchMax(grid, xMax, yMax, x, y-1) : 0)
        + ((y+1 <= yMax && grid[y+1][x] == 1) ? searchMax(grid, xMax, yMax, x, y+1) : 0)
        + ((x-1 >= 0 && grid[y][x-1] == 1) ? searchMax(grid, xMax, yMax, x-1, y) : 0)
        + ((x+1 <= xMax && grid[y][x+1] == 1) ? searchMax(grid, xMax, yMax, x+1, y) : 0);
}

int searchOnes(std::vector<std::vector<int>>& grid, int& xMax, int& yMax, int x, int y, int& acc, int &aux)
{
    if (grid[y][x] == 1)
    {
        aux = searchMax(grid, xMax, yMax, x, y);
        acc = (acc < aux) ? aux : acc;
    }

    --grid[y][x];

    if (y-1 >= 0 && grid[y-1][x] >= 0)
        searchOnes(grid, xMax, yMax, x, y-1, acc, aux);
    if (y+1 <= yMax && grid[y+1][x] >= 0)
        searchOnes(grid, xMax, yMax, x, y+1, acc, aux);
    if (x-1 >= 0 && grid[y][x-1] >= 0)
        searchOnes(grid, xMax, yMax, x-1, y, acc, aux);
    if (x+1 <= xMax && grid[y][x+1] >= 0)
        searchOnes(grid, xMax, yMax, x+1, y, acc, aux);

    return acc;
}

int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
{
    int x = grid[0].size() - 1;
    int y = grid.size() - 1;
    int acc = 0;
    int aux = 0;

    return searchOnes(grid, x, y, grid[0].size()/2, grid.size()/2, acc, aux);
}

int main(int argc, char** argv)
{
    std::vector<std::vector<int>> grid = std::vector<std::vector<int>>({
            std::vector<int>({0,0,0,0,0,0,0,0})
    });

    printf("%d\n", maxAreaOfIsland(grid));

    return 0;
}

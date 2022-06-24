#include "graphs.h"
#include <vector>

using namespace std;


int Graph::numIslands(vector<vector<char>>& grid){
    int n_island = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(!visited[i][j] && grid[i][j] == '1'){
                numIslandsHelper(grid, visited, i, j);
                n_island += 1;
            }
        }
    }
    return n_island;
}


void Graph::numIslandsHelper(vector<vector<char>> &grid, vector<vector<bool>> &visited, int m, int n){
    if(m < 0 || n < 0 || m > grid.size() - 1 || n > grid[0].size() - 1 || grid[m][n] == '0' || visited[m][n])
        return;

    visited[m][n] = true;   
    numIslandsHelper(grid, visited, m + 1, n);
    numIslandsHelper(grid, visited, m - 1, n);
    numIslandsHelper(grid, visited, m, n + 1);
    numIslandsHelper(grid, visited, m, n - 1);
}
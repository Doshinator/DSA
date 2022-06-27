#include "graphs.h"
#include <vector>
#include <unordered_map>

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


Graph::Node* Graph::cloneGraph(Node* node){
    // map node -> new copy
    if(!node)
        return NULL;
    
    if(copies.find(node) == copies.end()){
        copies[node] = new Node(node->val);
        for(int i = 0; i < node->neighbors.size(); i++){
            copies[node]->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
    }
    return copies[node];
}

int Graph::maxAreaOfIsland(vector<vector<int>>& grid){
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int count = 0;
    int res = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 1 && !visited[i][j])
                maxAreaOfIslandHelper(grid, visited, i, j, count, res);
        }
    }
    return res;
}

void Graph::maxAreaOfIslandHelper(vector<vector<int>> &grid, vector<vector<bool>> &visited, int m, int n, int &count, int &res){
    if(m < 0 || n < 0 || m > grid.size() - 1 || n > grid[0].size() - 1 || grid[m][n] == 0 || visited[m][n])
        return;

    visited[m][n] = true;
    count += 1;
    res = std::max(res, count);
    maxAreaOfIslandHelper(grid, visited, m+1, n, count, res);
    maxAreaOfIslandHelper(grid, visited, m-1, n, count, res);
    maxAreaOfIslandHelper(grid, visited, m, n+1, count, res);
    maxAreaOfIslandHelper(grid, visited, m, n-1, count, res);
}

int Graph::maxAreaOfIslandHelper(vector<vector<int>> &grid, vector<vector<bool>> &visited, int m, int n){
    if(m < 0 || n < 0 || m > grid.size() - 1 || n > grid[0].size() - 1 || grid[m][n] == 0 || visited[m][n])
        return 0;

    return 1 + 
        maxAreaOfIslandHelper(grid, visited, m+1, n) + 
        maxAreaOfIslandHelper(grid, visited, m-1, n) + 
        maxAreaOfIslandHelper(grid, visited, m, n+1) + 
        maxAreaOfIslandHelper(grid, visited, m, n-1);
}
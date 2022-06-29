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

    visited[m][n] = true;
    return 1 + 
        maxAreaOfIslandHelper(grid, visited, m+1, n) + 
        maxAreaOfIslandHelper(grid, visited, m-1, n) + 
        maxAreaOfIslandHelper(grid, visited, m, n+1) + 
        maxAreaOfIslandHelper(grid, visited, m, n-1);
}


vector<vector<int>> Graph::pacificAtlantic(vector<vector<int>> &heights){
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));

    vector<vector<int>> ans;

    for(int i = 0; i < m; i++){
        pacificAtlanticHelper(heights, pacific, i, 0, INT_MIN);
        pacificAtlanticHelper(heights, atlantic, i, n-1, INT_MIN);
    }

    for(int i = 0; i < n; i++){
        pacificAtlanticHelper(heights, pacific, 0, i, INT_MIN);
        pacificAtlanticHelper(heights, atlantic, m-1, i, INT_MIN);
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(pacific[i][j] && atlantic[i][j])
                ans.push_back({i,j});
        }
    }

    return ans;
}

void Graph::pacificAtlanticHelper(vector<vector<int>> &heights, vector<vector<bool>> &visited, int m, int n, int val){
    if(m < 0 || n < 0 || m > heights.size() - 1|| n > heights[0].size() - 1 || 
        visited[m][n] || heights[m][n] < val)
        return;

    visited[m][n] = true;
    pacificAtlanticHelper(heights, visited, m+1, n, heights[m][n]);
    pacificAtlanticHelper(heights, visited, m-1, n, heights[m][n]);
    pacificAtlanticHelper(heights, visited, m, n+1, heights[m][n]);
    pacificAtlanticHelper(heights, visited, m, n-1, heights[m][n]);
}

void Graph::surroundingRegion(vector<vector<char>> &board){
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for(int i = 0; i < m; i++){
        // dfs the boarder and mark all O that can't be changed as 'visited'
        surroundingRegionHelper(board, visited, i, 0);
        surroundingRegionHelper(board, visited, i, n-1);
    }
    
    for(int i = 0; i < n; i++){
        surroundingRegionHelper(board, visited, 0, i);
        surroundingRegionHelper(board, visited, m-1, i);
    }


    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j])
                board[i][j] = '1';
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            if(board[i][j] == '1')
                board[i][j] = 'O';
        }
    }
}

void Graph::surroundingRegionHelper(vector<vector<char>> &board, vector<vector<bool>> &visited, int m, int n){
    if(m < 0 || n < 0 || m > board.size() - 1 || n > board[0].size() - 1 || 
        visited[m][n] || board[m][n] != 'O')
        return;
    
    visited[m][n] = true;
    surroundingRegionHelper(board, visited, m+1, n);    
    surroundingRegionHelper(board, visited, m-1, n);
    surroundingRegionHelper(board, visited, m, n+1);
    surroundingRegionHelper(board, visited, m, n-1);
}

int Graph::orangesRotting(vector<vector<int>> &grid){

}
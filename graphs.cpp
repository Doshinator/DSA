#include "graphs.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

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
    int m = grid.size(), n = grid[0].size();
    int minutes = -1, freshOrange = 0;
    queue<vector<int>> q;
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1)
                freshOrange++;
            if(grid[i][j] == 2)
                q.push({i,j});
        }
    }

    while(!q.empty()){
        minutes++;
        vector<int> curr;
        for(int i = 0, n = q.size(); i < n; i++){
            curr = q.front(); q.pop();
            for(int j = 0; j < dir.size(); j++){
                int m = curr[0] + dir[j][0];
                int n = curr[1] + dir[j][1];

                if(m < 0 || n < 0 || m > grid.size() - 1 || n > grid[0].size() - 1 || grid[m][n] != 1)
                    continue;
                
                grid[m][n] = 2;
                q.push({m,n});
                freshOrange--;
            }
        }
    }

    if(freshOrange > 0) return -1;
    return minutes == -1? 0 : minutes;
}


void Graph::wallsAndGates(vector<vector<int>> &rooms){
    // Explanation:
    // the 2D grid is:
    // INF  -1  0  INF
    // INF INF INF  -1
    // INF  -1 INF  -1
    //   0  -1 INF INF
    // the answer is:
    //   3  -1   0   1
    //   2   2   1  -1
    //   1  -1   2  -1
    //   0  -1   3   4

    vector<vector<int>> res (rooms.size(), vector<int>(rooms[0].size(), 2147483647));
    for(int i = 0; i < rooms.size(); i++){
        for(int j = 0; j < rooms[0].size(); j++){
            if(rooms[i][j] == 0){
                vector<vector<bool>> visited(rooms.size(), vector<bool>(rooms[0].size(), false));
                wallsAndGatesHelper(rooms, res, visited, i, j, 0);
            }
        }
    }
}

void Graph::wallsAndGatesHelper(vector<vector<int>> &rooms, vector<vector<int>> &res, vector<vector<bool>> &visited, int m, int n, int distance){
    if(m < 0 || n < 0 || m > rooms.size() - 1 || n > rooms[0].size() - 1 || visited[m][n] || rooms[m][n] == -1)
        return;

    if(distance >= res[m][n])
        return;
    
    res[m][n] = distance;
    visited[m][n] = true;
    wallsAndGatesHelper(rooms, res, visited, m+1, n, distance + 1);
    wallsAndGatesHelper(rooms, res, visited, m-1, n, distance + 1);
    wallsAndGatesHelper(rooms, res, visited, m, n+1, distance + 1);
    wallsAndGatesHelper(rooms, res, visited, m, n-1, distance + 1);
}

bool Graph::courseScheduler(int numCourses, vector<vector<int>> &prerequisites){
    int cleared = 0;
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses);
    // setting up adj list + indegree
    for(int i = 0; i < prerequisites.size(); i++){
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        inDegree[prerequisites[i][0]]++;
    }
    // q init
    queue<int> q;
    for(int i = 0; i < inDegree.size(); i++){
        if(inDegree[i] == 0)
            q.push(i);
    }
    //bfs
    while(!q.empty()){
        int curr = q.front(); q.pop(); cleared++;
        vector<int> neighbors = graph[curr];
        for(int j = 0; j < neighbors.size(); j++){
            inDegree[neighbors[j]]--;

            if(inDegree[neighbors[j]] == 0)
                q.push(neighbors[j]);
        }
    }
    return numCourses == cleared? true : false;
}

vector<int> findOrdercCourseSchedule(int numCourses, vector<vector<int>> &prerequisites){
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);
    vector<int> res;
    int cleared = 0;
    // input [[1,0],[2,0],[3,1],[3,2]]
    // output [0,2,1,3]
    for(int i = 0; i < prerequisites.size(); i++){
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indegree[prerequisites[i][0]]++;
    }

    queue<int> q;
    for(int i = 0; i < indegree.size(); i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int curr = q.front(); q.pop(); cleared++;
        res.push_back(curr);
        vector<int> neighbors = graph[curr];
        for(int i = 0; i < neighbors.size(); i++){
            indegree[neighbors[i]]--;
            if(indegree[neighbors[i]] == 0)
                q.push(neighbors[i]);
        }

    }

    if(numCourses == cleared)
        return res;

    return {};
}
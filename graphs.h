#include <vector>
#include <unordered_map>

using namespace std;

class Graph{
    public:
    int numIslands(vector<vector<char>> &grid);
    void numIslandsHelper(vector<vector<char>> &grid, vector<vector<bool>> &visited, int m, int n);

    class Node {
        public:
        int val;
        vector<Node*> neighbors;
        Node() {
            val = 0;
            neighbors = vector<Node*>();
        }
        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }
        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    };
    Node* cloneGraph(Node* node);
    unordered_map<Node*, Node*> copies;

    int maxAreaOfIsland(vector<vector<int>>& grid);
    void maxAreaOfIslandHelper(vector<vector<int>> &grid, vector<vector<bool>> &visited, int m, int n, int &count, int &res);
    int maxAreaOfIslandHelper(vector<vector<int>> &grid, vector<vector<bool>> &visited, int m, int n);

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights);
    void pacificAtlanticHelper(vector<vector<int>> &heights, vector<vector<bool>> &visited, int m, int n, int val);

    void surroundingRegion(vector<vector<char>> &board);
    void surroundingRegionHelper(vector<vector<char>> &board, vector<vector<bool>> &visited, int m, int n);

    int orangesRotting(vector<vector<int>> &grid);
    
    void wallsAndGates(vector<vector<int>> &rooms);
    void wallsAndGatesHelper(vector<vector<int>> &rooms, vector<vector<int>> &res, vector<vector<bool>> &visited, int m, int n, int distance);

    bool courseScheduler(int numCourses, vector<vector<int>> &prerequisites);
};
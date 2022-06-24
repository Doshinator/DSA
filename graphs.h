#include <vector>

using namespace std;

class Graph{
    public:
    int numIslands(vector<vector<char>> &grid);
    void numIslandsHelper(vector<vector<char>> &grid, vector<vector<bool>> &visited, int m, int n);
};
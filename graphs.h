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
};
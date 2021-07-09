#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    DFS(grid, i, j);
                }
            }
        }
        return count;
    }
    void BFS(int i, int j, vector<vector<char>>& grid)
    {
        queue<vector<int>> nodes;
        nodes.push({ i, j });
        vector<vector<int>> directions =
        {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };
        while (!nodes.empty())
        {
            vector<int> node = nodes.front();
            nodes.pop();
            grid[node[0]][node[1]] = '0';
            for (int dir = 0; dir < directions.size(); dir++)
            {
                int newI = node[0] + directions[dir][0];
                int newJ = node[1] + directions[dir][1];
                if (newI < 0 || newI >= grid.size() || newJ < 0 || newJ >= grid[0].size())
                {
                    continue;
                }
                if (grid[newI][newJ] == '1')
                {
                    nodes.push({ newI, newJ });
                    grid[newI][newJ] = '0';
                }
            }
        }
        return;
    }

    void DFS(vector<vector<char>>& grid, int i, int j)
    {
        if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0) { return; }
        if (grid[i][j] == '0') { return; }
        grid[i][j] = '0';
        vector<vector<int>> directions =
        {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };
        for (int dir = 0; dir < directions.size(); dir++)
        {
            DFS(grid, i + directions[dir][0], j + directions[dir][1]);
        }
    }
};
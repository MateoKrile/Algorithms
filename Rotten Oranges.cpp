#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    const int ROTTEN = 2;
    const int FRESH = 1;
    const int EMPTY = 0;
    const vector<pair<int, int>> directions =
    {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
    };

    int orangesRotting(vector<vector<int>>& grid)
    {
        if ( grid.size() == 0 || grid[0].size()==0 ) { return 0; }

        queue<pair<int, int>> rotten;
        int fresh_cnt = 0;
        
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == ROTTEN)
                {
                    rotten.push({ i, j });
                }
                else if (grid[i][j] == FRESH)
                {
                    fresh_cnt++;
                }
            }
        }
        int minutes = 0;
        int leftInCycle = rotten.size();

        while (!rotten.empty())
        {
            if (leftInCycle == 0)
            {
                leftInCycle = rotten.size();
                minutes++;
            }

            pair<int, int> currentOrange = rotten.front();
            rotten.pop();
            leftInCycle--;
            for (pair<int, int> move : directions)
            {
                int newRow = currentOrange.first + move.first;
                int newCol = currentOrange.second + move.second;
                if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size())
                {
                    continue;
                }
                else if(grid[newRow][newCol] == FRESH)
                {
                    fresh_cnt--;
                    grid[newRow][newCol] = 2;
                    rotten.push({ newRow, newCol });
                }
            }
        }
        if (fresh_cnt > 0)
        {
            return -1;
        }
        return minutes;
    }
};

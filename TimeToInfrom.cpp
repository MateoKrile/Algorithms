#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; i++)
        {
            if( manager[i] == -1 ) { continue; }
            adjList[manager[i]].push_back(i);
        }
        return DFS(headID, adjList, informTime);
    }

    void baseDFS(int vtx, vector<vector<int>>& graph, vector<int>& values, vector<int>& seen)
    {
        values.push_back(vtx);
        seen[vtx] = true;
        

        vector<int> connections = graph[vtx];
        for (int i = 0; i < connections.size(); i++)
        {
            int connection = connections[i];
            if (!seen[connection])
            {
                baseDFS(connection, graph, values, seen);
            }
        }
    }
    int DFS(int currentId, vector<vector<int>>& adjList, vector<int>& informTime) 
    {
        if (adjList[currentId].size()== 0) 
        {
            return 0;
        }

        int max = 0;
        vector<int> subordinates = adjList[currentId];
        for (int i = 0; i < subordinates.size(); i++) {
            max = std::max(max, DFS(subordinates[i], adjList, informTime));
        }

        return max + informTime[currentId];
    }
};
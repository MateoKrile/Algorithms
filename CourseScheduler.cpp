#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        //vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (int prereq = 0; prereq < prerequisites.size(); prereq++)
        {
            //adjList[prerequisites[prereq][1]].push_back(prerequisites[prereq][0]);
            inDegree[prerequisites[prereq][0]]++;
        }
        //First solution
        //return BFS();
        //Optimal solution
        return TopologicalSort(inDegree, prerequisites, numCourses);
    }

    vector<int> traversalBFS(int n, int vertex, vector<vector<int>>& graph) 
    {
        vector<bool> seen(n, false);
        queue<int> queue;
        queue.push(vertex);
        vector<int> values;

        while (!queue.empty()) {
            int vertex = queue.front();
            queue.pop();
            values.push_back(vertex);
            seen[vertex] = true;

            vector<int> connections = graph[vertex];
            for (int i = 0; i < connections.size(); i++) {
                int connection = connections[i];
                if (!seen[connection]) {
                    queue.push(connection);
                }
            }
        }
        return values;
    }

    bool TopologicalSort(vector<int>& inDegree, vector<vector<int>>& prereqs, int numCourses)
    {
        stack<int> zeroes;
        for (int i = 0; i < inDegree.size(); i++)
        {
            if (!inDegree[i])
            {
                zeroes.push(i);
            }
        }

        int count = 0;

        while (!zeroes.empty())
        {
            int course = zeroes.top();
            zeroes.pop();
            count++;
            for (vector<int> pair : prereqs)
            {
                if (course == pair[1])
                {
                    inDegree[pair[0]]--;
                    if (!inDegree[pair[0]])
                    {
                        zeroes.push(pair[0]);
                    }
                }
            }
        }
        return count == numCourses;
    }
};
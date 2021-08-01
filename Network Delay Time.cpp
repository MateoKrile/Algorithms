#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {   
        //Bellman-Ford Algoritm
        vector<int> distances(n, INT_MAX);
        distances[k - 1] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int count = 0;
            for (vector<int> edge : times)
            {
                if (distances[edge[0] - 1] != INT_MAX && distances[edge[0] - 1] + edge[2] < distances[edge[1] - 1])
                {
                    distances[edge[1] - 1] = distances[edge[0] - 1] + edge[2];
                    count++;
                }
            }
            if (count == 0) { break; }
        }
        auto res = max_element(distances.begin(), distances.end());
        return *res == INT_MAX ? -1 : *res;
    }
};
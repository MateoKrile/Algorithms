#include <vector>;
#include <algorithm>;
using namespace std;

class Solution 
{
public:
    int maxArea(vector<int>& heights) {
        int p1 = 0;
        int p2 = heights.size() - 1;
        int max_area = 0;
        while(p1 < p2)
        {
            int height = min(heights[p1], heights[p2]);
            int width = p2-p1;
            max_area = max(max_area, width*height);
            if(heights[p1] > heights[p2])
            {
                p2--;
            }
            else
            {
                p1++;
            }
        }
        return max_area;
    }
};
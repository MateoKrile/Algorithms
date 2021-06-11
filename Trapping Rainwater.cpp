#include <vector>;
#include <algorithm>;

using namespace std;

class Solution
{
public:
    int trap(vector<int>& heights)
    {
        int maxLeft = 0;
        int maxRight = 0;
        int water = 0;
        int left = 0;
        int right = heights.size()-1;
        while(left<right)
        {
            if(heights[left] <= heights[right])
            {
                if(maxLeft > heights[left])
                {
                    water += maxLeft - heights[left];
                }
                else
                {
                    maxLeft = heights[left];
                }
                left++;
            }
            else
            {
                if(maxRight > heights[right])
                {
                    water += maxRight-heights[right];
                }
                else
                {
                    maxRight = heights[right];
                }
                right--;
            }
        }
        return water;
    }
};
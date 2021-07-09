#include <vector>;

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int size = nums.size();
        if (size == 0) { return{ -1,-1 }; }
        int idx = BinarySearch(nums, target, 0, size-1);
        if (idx == -1)
        {
            return { -1, -1 };
        }
        int leftPtr = idx, rightPtr = idx+1;
        int tempLeft = leftPtr, tempRight = rightPtr;
        while (leftPtr != -1)
        {
            tempLeft = leftPtr;
            leftPtr = BinarySearch(nums, target, 0, tempLeft-1);
        }
        while (rightPtr != -1)
        {
            tempRight = rightPtr;
            rightPtr = BinarySearch(nums, target, tempRight, size-1);
        }
        return {tempLeft, tempRight};
    }
    //O(log n)
    int BinarySearch(vector<int>& array, int target, int start, int end)
    {
        int left = start, right = end;
        while (left <= right)
        {
            int mid = floor((left + right) / 2);
            if (array[mid] == target)
            {
                return mid;
            }
            else if (array[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};
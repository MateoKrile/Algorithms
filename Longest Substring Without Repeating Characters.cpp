#include <string>;
#include <unordered_map>;
#include <algorithm>;

using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.length()<=1) { return s.length(); }
        int longest = 0;
        int left = 0, right = 0;
        unordered_map<char, int> charMap;
        for(right ; right<s.length(); right++)
        {
            if(charMap.find(s[right]) != charMap.end() && charMap[s[right]] >= left)
            {
                left = charMap[s[right]] + 1;
            }
            charMap[s[right]] = right;
            longest = max(longest, left-right+1);
        }
        return longest;
    }
};
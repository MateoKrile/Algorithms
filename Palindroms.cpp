#include <string>;

using namespace std;

class Solution {
public:
    string transform(string& s)
    {
        string str;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122 ||s[i]>=48 && s[i]<=57)
            {
                str+=tolower(s[i]);
            }
        }
        return str;
    }
    bool isPalindrome(string s) 
    {
        s = transform(s);
        int left = 0, right = s.length()-1;
        while(left<=right)
        {
            if(s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;   
    }
};
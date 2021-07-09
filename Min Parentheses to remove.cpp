#include <stack>;
#include <string>:

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> indecies;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(')
            {
                indecies.push(i);
            }
            else if(s[i]==')')
            {
                if(indecies.empty()) { s[i] = 0; }
                else
                {
                    indecies.pop();;
                }
            }
        }
        while(!indecies.empty())
        {
            s[indecies.top()] = 0;
            indecies.pop();
        }
        s.erase(remove(s.begin(), s.end(), 0), s.end());
        return s;
    }
};
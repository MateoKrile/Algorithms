#include <stack>;
#include <string>;
#include <unordered_map>;

using namespace std;

class Solution {
public:
    bool isValid(string s) 
    {
        if(s.length() == 0) { return true; }
        if(s.length() == 1) { return false; }
        unordered_map<char, char> parentheses = 
            {
            {'{','}'}, 
            {'[',']'}, 
            {'(',')'}
            };
        stack<char> seen;
        for(int i=0; i<s.length(); i++)
        {
            if(parentheses[s[i]])
            {
                seen.push(s[i]);
            }
            else if(s[i]=='}' || s[i]==']' || s[i]==')' )
            {
                if(seen.empty()) { return false; }
                char poped = seen.top();
                char correct = parentheses[poped];
                if(s[i] != correct) { return false;}
                else { seen.pop(); }
            }
        }
        return seen.size() == 0;
    }
};
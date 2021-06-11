#include <string>;

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        int ps = s.length()-1;
        int pt = t.length()-1;
        int backspaceS = 0, backspaceT = 0;
        while(ps >= 0 || pt >= 0)
        {
            while(ps>=0)
            {
                if(s[ps]=='#')
                {
                    backspaceS ++;
                    ps--;
                }
                else if(backspaceS>0)
                {
                    backspaceS--;
                    ps--;
                }
                else
                {
                    break;
                }
            }
            while(pt>=0)
            {
                if(t[pt]=='#')
                {
                    backspaceT++;
                    pt--;
                }
                else if(backspaceT>0)
                {
                    backspaceT--;
                    pt--;
                }
                else
                {
                    break;
                }
            }
            if(ps>=0 && pt >= 0 && s[ps]!=t[pt]) { return false; }
            if((ps>=0) != (pt>=0)) { return false; }
            ps--;
            pt--;
        }
        return true;
    }
};
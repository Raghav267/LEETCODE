#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> um;
    int l = 0, maxLEngth = 0;
    for (int r = 0; r < s.length(); r++)
    {
        auto it = um.find(s[r]);
        if (it != um.end() && um[s[r]] >= l)
        {
            l = um[s[r]] + 1;
        }
        um[s[r]] = r;
        maxLEngth = max(maxLEngth, r - l + 1);
    }
    return maxLEngth;
}
int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);
}
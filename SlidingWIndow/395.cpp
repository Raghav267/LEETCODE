#include <bits/stdc++.h>
using namespace std;
int longestSubstring(string s, int k)
{
    if (k > s.length())
        return 0;
    unordered_map<char, int> um;

    for (auto ch : s)
    {
        um[ch]++;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (um[s[i]] < k)
        {
            int left = longestSubstring(s.substr(0, i), k);
            int right = longestSubstring(s.substr(i + 1), k);
            return max(left, right);
        }
    }
    return s.length();
}
int main()
{
    string s = "aaabb";
    int k = 3;
    return 0;
}
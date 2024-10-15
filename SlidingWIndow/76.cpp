#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t)
{
    if (s.length() < t.length())
        return "";

    unordered_map<char, int> t_map;
    for (int i = 0; i < t.length(); i++)
    {
        t_map[t[i]]++;
    }

    int l = 0, r = 0, completed = t_map.size(), formed = 0;
    int minLen = INT_MAX;
    int min_left = 0, min_right = 0;
    unordered_map<char, int> w_map;

    for (r = 0; r < s.length(); r++)
    {
        char c = s[r];
        w_map[c]++;

        if (t_map.count(c) && w_map[c] == t_map[c])
        {
            formed++;
        }

        while (l <= r && completed == formed)
        {
            // update the formed window length;
            if (r - l + 1 < minLen)
            {
                minLen = r - l + 1;
                min_left = l;
                min_right = r;
            }

            // shrink the window
            char left_char = s[l];
            w_map[left_char]--;
            if (t_map.count(left_char) && w_map[left_char] < t_map[left_char])
            {
                formed--;
            }
            l++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(min_left, minLen);
}
int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t);
    return 0;
}
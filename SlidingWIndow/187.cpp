#include <bits/stdc++.h>
using namespace std;
vector<string> findRepeatedDnaSequences(string s)
{
    vector<string> res;
    if (s.length() < 10)
        return res;

    unordered_set<string> seen, repeated;

    for (int i = 0; i < s.length() - 10; i++)
    {
        string current = s.substr(i, 10);

        if (seen.find(current) != seen.end())
        {
            repeated.insert(current);
        }
        else
        {
            seen.insert(current);
        }
    }

    for (auto str : repeated)
    {
        res.push_back(str);
    }

    return res;
}
int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> ans = findRepeatedDnaSequences(s);
    for (auto value : ans)
    {
        cout << value << " " << endl;
    }
    return 0;
}
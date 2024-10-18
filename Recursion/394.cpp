#include <bits/stdc++.h>
using namespace std;
string helper(string s, int &index)
{
    if (index >= s.length())
        return "";
    string ans = "";
    int k = 0;
    while (index < s.length())
    {
        char ch = s[index];
        if (isdigit(ch))
        {
            while (index < s.length() && isdigit(s[index]))
            {
                k = k * 10 + (s[index] - '0');
                index++;
            }
        }
        else if (ch == '[')
        {
            index++;
            string recString = helper(s, index);
            for (int i = 0; i < k; i++)
            {
                ans += recString;
            }
            k = 0;
        }
        else if (ch == ']')
        {
            index++;
            return ans;
        }
        else
        {
            ans += ch;
            index++;
        }
    }
    return ans;
}
string decodeString(string s)
{
    int index = 0;
    return helper(s, index);
}
int main()
{
    string s = "3[a]2[bc]";
    cout << decodeString(s);
    return 0;
}
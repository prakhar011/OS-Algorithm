#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int k, n;
char helper(unordered_set<char> &st, string s, int i)
{
    unordered_map<char, int> pageRequirementOrder;
    for (auto pageInFrame : st)
    {
        for (int it = i + 1; it < n; it++)
        {
            if (s[it] == pageInFrame && pageRequirementOrder.find(pageInFrame) == pageRequirementOrder.end())
            {
                pageRequirementOrder[pageInFrame] = it;
            }
        }
    }
    char discard;
    int max = -1;

    for (auto pageInFrame : st)
    {
        if (pageRequirementOrder.find(pageInFrame) == pageRequirementOrder.end())
        {
            discard = pageInFrame;
            break;
        }
        else
        {
            if (pageRequirementOrder[pageInFrame] > max)
            {
                max = pageRequirementOrder[pageInFrame];
                discard = pageInFrame;
            }
        }
    }
    return discard;
}

int main()
{
    string s;
    cin >> s;
    n = s.length();
    cin >> k;
    int count = 0;
    unordered_set<char> st;
    int i = 0;

    for (i = 0; i < n; i++)
    {
        if (st.find(s[i]) == st.end())
        {
            count++;
            if (st.size() < k)
            {
                st.insert(s[i]);
            }
            else
            {
                char discard = helper(st, s, i);
                st.erase(discard);
                st.insert(s[i]);
            }
        }
        else
        {
            continue;
        }
    }
    cout << count << endl;
}

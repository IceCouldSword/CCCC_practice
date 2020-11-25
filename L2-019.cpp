#include<bits/stdc++.h>
using namespace std;
vector<pair<string, int> > vec;
vector<string> ans;
int main()
{
    int n, m, num, sum = 0;
    double avg;
    string s;
    cin >> n;
    getchar();
    getline(cin, s);
    cin >> m;
    string name;
    for(int i = 0; i < m; i++)
    {
        cin >> name >> num;
        vec.push_back(make_pair(name, num));
        sum += num;
    }
    avg = sum * 1.0 / m;
    for(auto &e : vec)
    {
        if(e.second > avg && (s.find(e.first) == s.npos))
            ans.push_back(e.first);
    }
    if(ans.size())
    {
        sort(ans.begin(), ans.end());
        for(auto &e : ans)
            cout << e << endl;
    }
    else
        cout << "Bing Mei You" << endl;
    system("pause");
}
#include<bits/stdc++.h>
using namespace std;
class person
{
    public:
    string name;
    int num;
    set<int> data;
}per[105];
bool operator < (person &a, person &b)
{
    if(a.data.size() == b.data.size())
        return (a.data.size() * 1.0 / a.num) >  (b.data.size() * 1.0 / b.num);
    return a.data.size() > b.data.size();
}
int main()
{
    int n, data, num;
    string name;
    cin >> n;
    for(int i = 0; i < n;i++)
    {
        cin >> per[i].name >> per[i].num;
        for(int j = 0; j < per[i].num; j++)
        {
            cin >> data;
            per[i].data.insert(data);
        }
    }
    sort(per, per + n);
    if(n >= 3)
        for(int i = 0; i < 3; i++)
        {
            if(i != 0) cout << " ";
            cout << per[i].name;
        }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(i != 0) cout << " ";
            cout << per[i].name;
        }
        cout << " ";
        for(int i = 0; i < 3 - n; i++)
        {
            if(i != 0) cout << " ";
            cout << "-";
        }
    }
    system("pause");
}
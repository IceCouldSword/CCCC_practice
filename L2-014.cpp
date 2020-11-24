#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, num;
    cin >> n;
    set<int> s;
    while(n--)
    {
        cin >> num;
        
        if(s.upper_bound(num) != s.end())
        {
            s.erase(s.upper_bound(num));
            s.insert(num);
        }
        else
            s.insert(num);
    }
    cout << s.size() << endl;
    system("pause");
}
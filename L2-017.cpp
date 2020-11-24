#include<bits/stdc++.h>
using namespace std;
int per[100005];
int main()
{
    int n, out = 0, in = 0, diff, sumout = 0, sumin = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> per[i];
    }   
    sort(per, per + n, greater<int>());
    if(n % 2 != 0)
    {
        for(int i = 0; i < n / 2 + 1; i++)
        {
            out++;
            sumout += per[i];
        }   
        for(int i = n / 2 + 1; i < n; i++)
        {
            in++;
            sumin += per[i];
        }
    }
    else
    {
        for(int i = 0; i < n / 2; i++)
        {
            out++;
            sumout += per[i];
        }   
        for(int i = n / 2; i < n; i++)
        {
            in++;
            sumin += per[i];
        }
    }
    diff = sumout - sumin;
    cout << "Outgoing #: " << out << endl;
    cout << "Introverted #: " << in << endl;
    cout << "Diff = " << diff << endl;
    system("pause");
}
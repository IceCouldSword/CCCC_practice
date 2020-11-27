#include<bits/stdc++.h>
using namespace std;
int main()
{
    int pa, pb, num[2] = {0}, flag;
    cin >> pa >> pb;
    for(int i = 0; i < 3; i++)
    {
        cin >> flag;
        if(flag) num[1]++;
        else num[0]++;
    }
    if(pa > pb && num[0] > 0) cout << "The winner is a: " << pa << " + " << num[0];
    else if(pa < pb && num[0] == 3) cout << "The winner is a: " << pa << " + " << num[0];
    else if(pb > pa && num[1] > 0) cout << "The winner is b: " << pb << " + " << num[1];
    else if(pb < pa && num[1] == 3) cout << "The winner is b: " << pb << " + " << num[1];
    system("pause");
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b, c;
    cin >> n;
    while(n--)
    {
        cin >> a >> b >> c;
        if(a == 0) //女
        {
            if(b > 129) cout << "ni li hai!";
            else if(b < 129) cout << "duo chi yu!";
            else cout << "wan mei!";
            if(c > 25) cout << "shao chi rou!";
            else if(c < 25) cout << "duo chi rou!";
            else cout << "wan mei!";
        } 
        else
        {
            if(b > 130) cout << "ni li hai!";
            else if(b < 130) cout << "duo chi yu!";
            else cout << "wan mei!";
            if(c > 27) cout << "shao chi rou!";
            else if(c < 27) cout << "duo chi rou!";
            else cout << "wan mei!";
        }
        cout << endl;
    }
    system("pause");
}
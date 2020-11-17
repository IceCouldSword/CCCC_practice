#include<bits/stdc++.h>
using namespace std;
vector<string> vec;
int main() 
{  
    int l, n, pos;
    cin >> l >> n;
    string s;
    string end;
    for(int i = 0; i < l; i++)
    {
        s += 'a';
        end += 'z';
    }
    pos = s.size() - 1;
    for(int i = 0; i < pow(26, l); i++)
    { 
        //cout << s << " ";
        vec.push_back(s);
        s[pos]++;
        if(s[pos] == 'z')
        {
            //cout << s << endl;
            vec.push_back(s);
            if(s == end) {cout << i << endl;break;}
            for(int j = pos; j >=0; j--)
            {
                if(s[j] == 'z') s[j] = 'a';
                else {s[j]++; break;}
            }
        }
    }
    int size = vec.size();
    cout << vec[size - n];
    system("pause");
}
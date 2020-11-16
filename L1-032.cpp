#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char ch;
    cin >> n;
    getchar(); //吸收空格
    cin >> ch;
    getchar(); //吸收回车
    vector<char> vec;
    char temp;
    while(1)
    {
        temp = getchar();
        if(temp == 10) break;
        vec.push_back(temp);
    }
    int len = vec.size();
    if(n > len)
        vec.insert(vec.begin(), n - len, ch);
    else if(n < len)
        vec.erase(vec.begin(), vec.begin() + len - n);
    auto it = vec.begin();
    for(auto &e : vec)
        cout << e;
    system("pause");
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> vec;
    string temp;
    while(1)
    {
        cin >> temp;
        vec.push_back(temp);
        if(temp == ".") break;
    }
    if(vec.size() <= 2)
        cout << "Momo... No one is for you ...";
    else if(vec.size() > 2 && vec.size() <= 14)
        cout << vec[1] << " is the only one for you...";
    else
        cout << vec[1] << " and " << vec[13] << " are inviting you to dinner...";
    system("pause");
}
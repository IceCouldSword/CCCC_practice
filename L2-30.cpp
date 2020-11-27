#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    string father;
    int sex;
};
unordered_map<string, node> m;  //unordered_map 查找效率更高  用map会超时
int judge(string s1, string s2)
{
    int i = 1, j;
    for(string f1 = s1; !f1.empty(); f1 = m[f1].father, i++)
    {
        j = 1;
        for(string f2 = s2; !f2.empty(); f2 = m[f2].father, j++)
        {
            if(i >= 5 && j >= 5) return 1;
            if(f1 == f2 && (i < 5 || j < 5)) return 0;
        }
    }
    return 1;
}
int main()
{
    int n, k;
    cin >> n;
    string fname, lname, temp;
    for(int i = 0; i < n; i++)
    {
        cin >> fname >> lname;
        if(lname.back() == 'm')
            m[fname].sex = 1; //男祖先
        else if(lname.back() == 'f')
            m[fname].sex = 2; //女祖先
        else if(lname.back() == 'n')
        {
            temp = lname.substr(0, lname.size() - 4);
            m[fname].sex = 1;
            m[fname].father = temp;
        }
        else if(lname.back() == 'r')
        {
            temp = lname.substr(0, lname.size() - 7);
            m[fname].sex = 2;
            m[fname].father = temp;
        }
    }
    cin >> k;
    string f1, l1, f2, l2;
    for(int i = 0; i < k; i++)
    {
        cin >> f1 >> l1 >> f2 >> l2;
        if(m.find(f1) == m.end() || m.find(f2) == m.end())
            cout << "NA" << endl;
        else if(m[f1].sex == m[f2].sex)
            cout << "Whatever" << endl;
        else if(judge(f1, f2) == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    system("pause");
}
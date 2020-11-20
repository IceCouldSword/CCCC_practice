#include<bits/stdc++.h>
using namespace std;
bool ismark(char c)
{
    if((c > 'z' || c < 'a') && (c > '9' || c < '0') && c != ' ' && c != 'I')
        return true;
    else return false;
}
void replace(string &s, string a, string b)
{
    int i = -1;
    while(1)
    {
        i = s.find(a, i + 1);
        if(i == s.npos) break;
        if(a == "I")
        {
        if(s.find("I can") != s.npos)
                i = s.find("I can") + 5;
        else if(s.find("I could") != s.npos) 
                i = s.find("I could") + 7;
        else if ((s[i - 1] == ' ' || ismark(s[i - 1])) && (s[i+a.size()] == ' ' || ismark(s[i+a.size()])) && i != 0 && i != s.size() - 1)
            s.replace(i, a.size(), b);
        else if(i == 0 && (s[i+a.size()] == ' ' || ismark(s[i+a.size()])))
            s.replace(i, a.size(), b);
        else if(i == s.size() - 1 && (s[i - 1] == ' ' || ismark(s[i - 1])))
            s.replace(i, a.size(), b);
        else continue;
        }
        else
        {
            if ((s[i - 1] == ' ' || ismark(s[i - 1])) && (s[i+a.size()] == ' ' || ismark(s[i+a.size()])) && i != 0 && i != s.size() - 1)
                s.replace(i, a.size(), b);
            else if(i == 0 && (s[i+a.size()] == ' ' || ismark(s[i+a.size()])))
                s.replace(i, a.size(), b);
            else if(i == s.size() - 1 && (s[i - 1] == ' ' || ismark(s[i - 1])))
                s.replace(i, a.size(), b);
            else continue;
        }
        
    }
}
int main()
{
    int n, num = 0;
    cin >> n;
    getchar();
    string s;
    string temp;
    while(n--)
    {
        getline(cin, s);
        cout << s << endl;
        cout << "AI: ";
        temp = "";
        num = -1;
        for(int i = 0; i < s.size(); i++) //去多余空格
        {
            if(temp[num] != s[i])
            {
                num++;
                temp += s[i];
            }
            else if(temp[num] == s[i] && s[i] != ' ')
            {
                num++;
                temp += s[i];
            }
        }
        if(temp[0] == ' ') //去行首
            temp.replace(temp.find_first_of(" "), 1, "");
        if(temp[temp.size() - 1] == ' ') //去行尾
            temp.replace(temp.find_last_of(" "), 1, "");
        for(int i = 0; i < temp.size(); i++) //改大小写
            if(temp[i] >= 'A' && temp[i] <= 'Z' && temp[i] != 'I')
                temp[i] = temp[i] + 32;
        for(int i = 0; i < temp.size(); i++) //去标点
        {
            if(ismark(temp[i]) && temp[i - 1] == ' ')
                temp.replace(i - 1, 1, "");
        }
        replace(temp, "can you", "I can");
        replace(temp, "could you", "I could");
        replace(temp, "I", "you");
        replace(temp, "me", "you");
        int pos = temp.find("?");
        while(pos != temp.npos)
        {   
            temp.replace(pos, 1, "!");
            pos = temp.find("?");
        }
        cout << temp << endl;
    }
    system("pause");
}

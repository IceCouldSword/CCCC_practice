#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<char> ch;
    char c;
    int size = 0;
    while(1)
    {
        scanf("%c", &c);
        ch.push_back(c);
        if(c == 10) break;
        size++;
    }
    for(int i = 0; i < size; i++)
    {
        int num = 0;
        if(ch[i] == '6')
        {
            for(int j = i; j < size; j++)
            {
                if(ch[j] != '6') break;
                num++;
            }
            if(num > 3 && num <= 9)
            {
                ch[i] = '9';
                auto it = ch.begin() + i + 1;
                for(int j = i; j < i + num - 1; j++,it++)
                {
                    it = ch.erase(it);
                    it--;
                }
            }
            else if(num > 9)
            {
                ch[i] = '2';
                ch[i+1] = '7';
                auto it = ch.begin() + i + 2;
                for(int j = i; j < i + num - 2; j++,it++)
                {
                    it = ch.erase(it);
                    it--;
                }
            }
        }
    }
    for(auto &e : ch)
        cout << e;
    system("pause");
}
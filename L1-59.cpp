#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    getchar();
    string ch;
    int size = 0, flag = 0, num = 0;
    while(n--)
    {
        flag = size = num = 0;
        getline(cin, ch);
        for(int i = 0; i < ch.size(); i++)
            if(ch[i] == ',' && ch[i - 1] == 'g' && ch[i - 2] == 'n' && ch[i - 3] == 'o')
                flag++;
        if(ch[ch.size() - 2] == 'g' && ch[ch.size() - 3] == 'n' && ch[ch.size() - 4] == 'o')
            flag++;
        if(flag == 2)
        {
            for(int i = ch.size() - 1; i >=0; i--)
            {
                if(ch[i] == ' ') num++;
                if(num == 3) 
                {
                    num = i;
                    break;
                }
            }
            for(int i = 0; i <= num; i++)
                cout << ch[i];
            cout << "qiao ben zhong." << endl;
        }
        else 
            cout << "Skipped" << endl;
    }
    system("pause");
}
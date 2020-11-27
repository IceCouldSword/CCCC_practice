#include<bits/stdc++.h>
using namespace std;
class student
{
    public:
    string mail;
    int score;
    int rank;
}stu[10005];
bool operator < (student &a, student &b)
{
    if(a.score == b.score)
        return a.mail < b.mail;
    return a.score > b.score;
}
int main()
{
    int n, g, k, sum = 0;
    cin >> n >> g >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> stu[i].mail >> stu[i].score;
        if(stu[i].score >= g && stu[i].score <= 100)
            sum += 50;
        else if(stu[i].score >= 60 && stu[i].score < g)
            sum += 20;
    }
    sort(stu, stu + n);
    cout << sum << endl;
    stu[0].rank = 1;
    for(int i = 1; i < n; i++)
    {
        if(stu[i].score == stu[i - 1].score)
            stu[i].rank = stu[i - 1].rank;
        else
            stu[i].rank = i + 1;
    }
    for(int i = 0; stu[i].rank <= k && i < n; i++)
        cout << stu[i].rank << " " << stu[i].mail << " " << stu[i].score << endl;
    system("pause");
}
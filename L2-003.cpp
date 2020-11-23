#include<bits/stdc++.h>
using namespace std;
class good
{
    public:
    double num;
    double money;
    double price;
};
bool operator < (good a, good b)
{
    return a.price > b.price;
}
good goods[1005];
int main()
{
    int n, d;
    double sum = 0;
    cin >> n >> d;
    for(int i = 0; i < n; i++)
        cin >> goods[i].num;
    for(int i = 0; i < n; i++)
        cin >> goods[i].money;
    for(int i = 0; i < n; i++)
        goods[i].price = goods[i].money / goods[i].num;
    sort(goods, goods + n);
    for(int i = 0; i < n; i++)
    {
        if(d <= goods[i].num)
        {
            sum += goods[i].price * d;
            d -= goods[i].num;
        }
        else
        {
            sum += goods[i].money;
            d -= goods[i].num;
        }
        if(d <= 0)
            break;
    }
    printf("%.2lf", sum);
    system("pause");
}
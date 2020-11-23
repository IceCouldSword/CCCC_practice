#include<bits/stdc++.h>
using namespace std;
class person
{
	public:
	int id;
	int money;
	int cnt;
};
vector<person> vec;
void swap(person &a,person &b)
{
	int tempid, tempmoney, tempcnt;
	tempid = a.id; a.id = b.id; b.id = tempid;
	tempmoney = a.money; a.money = b.money; b.money = tempmoney;
	tempcnt = a.cnt; a.cnt = b.cnt; b.cnt = tempcnt;
}
int main()
{
	int n, id, money, cnt, summoney;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		person temp;
		temp.id = i + 1;
		temp.money = 0;
		temp.cnt = 0;
		vec.push_back(temp);
	}
	for(int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		for(int j = 0; j < k; j++)
		{
			cin >> id >> money;
			vec[id-1].money += money;
			vec[id-1].cnt ++;
			summoney += money;
		}
		vec[i].money -= summoney;
		summoney = 0;
	}
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n-1; j++)
		{
			if(vec[j].money < vec[j+1].money)
				swap(vec[j],vec[j+1]);
			if(vec[j].money == vec[j+1].money && vec[j].cnt < vec[j+1].cnt)
				swap(vec[j],vec[j+1]);
			if(vec[j].money == vec[j+1].money && vec[j].cnt == vec[j+1].cnt && vec[j].id > vec[j].id)
				swap(vec[j],vec[j+1]);
		}
	}
	auto it = vec.begin();
	for(int i = 0; it != vec.end(); i++,it++)
	{
		cout << vec[i].id << " " ;
		printf("%.2lf\n", vec[i].money / 100.0);
	}
}
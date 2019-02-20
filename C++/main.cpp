#include<iostream>
using namespace std; 
namespace ICBC
{
	int balance=2000;
	void save()
	{
		int a;
		cout << "存入金额" << endl;
		cin >> a;
		balance += a;
	}
	void draw()
	{
		int a;
		cout << "取款金额" << endl;
		cin >> a;
		balance -= a;
		cout << "余额"<<balance << endl;
	}
}
namespace ABC
{
	int balance=4000;
	void draw()
	{
		int a;
		cout << "取款金额" << endl;
		cin >> a;
		balance -= a;
		cout << "余额" << balance << endl;
	}
	void save()
	{
		int a;
		cout << "存入金额" << endl;
		cin >> a;
		balance += a;
	}
}
int main()
{
	
	ICBC::save();
	ICBC::draw();
	ABC::save();
	ABC::draw();
	return 0;
}
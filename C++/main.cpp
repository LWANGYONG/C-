#include<iostream>
using namespace std; 
namespace ICBC
{
	int balance=2000;
	void save()
	{
		int a;
		cout << "������" << endl;
		cin >> a;
		balance += a;
	}
	void draw()
	{
		int a;
		cout << "ȡ����" << endl;
		cin >> a;
		balance -= a;
		cout << "���"<<balance << endl;
	}
}
namespace ABC
{
	int balance=4000;
	void draw()
	{
		int a;
		cout << "ȡ����" << endl;
		cin >> a;
		balance -= a;
		cout << "���" << balance << endl;
	}
	void save()
	{
		int a;
		cout << "������" << endl;
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
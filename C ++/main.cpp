#include<iostream>
using namespace std; 
namespace ICBC
{
	int balance=2000;
	void save()
	{
		int a;
		cout << "´æÈë½ð¶î" << endl;
		cin >> a;
		balance += a;
	}
	void draw()
	{
		int a;
		cout << "È¡¿î½ð¶î" << endl;
		cin >> a;
		balance -= a;
		cout << "Óà¶î"<<balance << endl;
	}
}
namespace ABC
{
	int balance=4000;
	void draw()
	{
		int a;
		cout << "È¡¿î½ð¶î" << endl;
		cin >> a;
		balance -= a;
		cout << "Óà¶î" << balance << endl;
	}
	void save()
	{
		int a;
		cout << "´æÈë½ð¶î" << endl;
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

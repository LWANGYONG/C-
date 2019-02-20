#pragma once
#include<string>
using std::string;
struct MonkeyKingBar
{
	int weght;
	int length;
	MonkeyKingBar(int weght=0, int length=0)
	{
		this->weght = weght;
		this->length = length;
	}

};
class Monkey
{
	string m_name;
	MonkeyKingBar* mkb;
public:
	Monkey(string name);
	Monkey(Monkey const& that);
	void introduce() const;
	~Monkey();
	Monkey(string name, int age);
};


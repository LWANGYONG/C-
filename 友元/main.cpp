#include <iostream>
using namespace std;
class Integer 
{
	int m_data;
public:
	Integer(int data);
	~Integer ();
	Integer& operator+(Integer& other) //类内
	{
		m_data += other.m_data;
		return *this;
	}
	int getData() { return m_data; }
	int setData(int data) { m_data = data; }
	//友元函数-类外实现
	friend Integer operator %(Integer& a, Integer& b);
	//友元函数-类内实现
	friend Integer operator *(Integer& a, Integer& b)
	{

		int c = a.m_data*b.m_data;
		Integer temp(c);
		return temp;
	}
};
Integer& operator-(Integer& a,Integer& b)//类外
{
	int c =a.getData() - b.getData();
	//a.setData(c);
	Integer temp(c);//创建一个临时对象temp，保存c的值
	return temp;
}

Integer operator %(Integer& a, Integer& b)
{
	int c = a.m_data%b.m_data;
	Integer temp(c);
	return temp;
}

Integer ::Integer (int data)
{
	 m_data = data; 
}

Integer ::~Integer ()
{
}
int main()
{
	Integer A(10);
	Integer B(5);
	Integer C = A * B;
	cout << "c=" << C.getData() << endl;
	return 0;
}
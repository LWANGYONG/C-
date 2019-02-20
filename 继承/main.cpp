#include<iostream>
#include <string>
using namespace std;
#if 0
class Human
{
public:
	Human()
	{
		cout << "Human this:" << this << endl;
	}
	Human(int age,string name,int gender):m_age(age),m_name(name),m_gender(gender){}
	void eat(string food)
	{
		cout << m_name << "吃了" << food << endl;
	}
	void sleep()
	{
		cout << m_name << "睡了" << endl;
	}
private:
	int m_age;
protected:
	string m_name;
public:
	int m_gender;
};//基类

class Student :public Human
{
public:
	Student():m_ID(0)
	{
		//基类中的私有成员，在子类中存在但是不能调用
		//m_age = 10;
		//基类中的保护成员，在子类中可以访问
		m_name = "张三";
		//基类中的公有成员，在子类中可以访问
		m_gender = 0;
	}
private:
	int m_ID;
public:
	//同名隐藏 子类中定义基类中同名的公有成员或保护成员 
	int sleep;
};

class parent
{
private:
	parent() {}
};

class son :public parent
{

};
int main()
{
	Student s1;
	//private 只能自身访问
	//s1.m_age 

	//protected 只能自身访问和子类访问
	//s1.m_name ="张三"
	//public 谁都可以访问
	s1.m_gender = 1;
	cout << "human 大小：" << sizeof(Human) << endl;
	cout << "Student 大小：" << sizeof(Student) << endl;
	//s1.sleep()
   // 公有继承子类对象任何时候都可以被当作基类类型对象
	Human h1 = s1;
	cout << &s1 << endl;

	Human* ph = &s1;
	Human& rh = h1;
	//基类指针或者引用指向或者引用是基类还是子类，不能光看声明类型
	//基类对象不能隐式转换子类对象
	Human h2;
	//Student s2 = h2;

	//son so;
	return 0;
}
#endif //继承概念和构造顺序
#if 0
class Human
{
public:
	Human()
	{
		cout << "Human this:" << this << endl;
	}
	Human(int age, string name, int gender) :m_age(age), m_name(name), m_gender(gender) { cout << "Human 三参:" << this << endl; }
	Human(int age)
	{
		cout << "Human 单参:" << this << endl;
	}
	void eat(string food)
	{
		cout << m_name << "吃了" << food << endl;
	}
	void sleep()
	{
		cout << m_name << "睡了" << endl;
	}
private:
	int m_age;
protected:
	string m_name;
public:
	int m_gender;
};//基类

class Student :public Human
{
public:
	//默认调用无参构造
	Student():m_ID(0){}
	Student(int age, string name, int gender,int ID) :Human(age, name, gender), m_ID(0)
	{
		cout << "Student 的构造" << this << endl;
	}
private:
	int m_ID;
}; 

int main()
{
	Student s1(1,"里斯",1,23);
	return 0;
}
#endif//初始化列表显示调用基类构造
#if 1
class Telephone
{
public:
	Telephone()
	{
		cout << "Telephone 构造" << endl;
	}
	void call()
	{
		cout << "打电话" << endl;
	}
	int m_t;
};
class Camera
{
public:
	Camera()
	{
		cout << "Camera 构造" << endl;
	}
	void photo()
	{
		cout << "照相" << endl;
	}
	int m_c;
};
class Ipod
{
public:
	Ipod()
	{
		cout << "Ipod 构造" << endl;
	}
	void music()
	{
		cout << "听歌" << endl;
	}
	int m_i;
};
class IphoeXs:public Telephone,public Camera,public Ipod
{
public:
	IphoeXs()
	{
		cout << "IphoneXs 构造" << endl;
	}
	int i;
};
int main()
{
	IphoeXs ipx;
	ipx.call();
	ipx.photo();
	ipx.music();
	cout << "---------------------" << endl;

	//基类指针指向子类对象
	Telephone* t = &ipx; //公有继承 皆然性  子类IS A 父类
	Camera* c = &ipx;    //公有继承 皆然性  子类IS A 父类
	Ipod *i = &ipx;      //公有继承 皆然性  子类IS A 父类
	cout << t << " " << c << " " << i << " " << endl;
	return 0;
}
#endif//多继承
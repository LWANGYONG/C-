#include<iostream>
#include<string>
using namespace std;
#if 0
class GirlFriend
{
	string m_name;
	int* p_age;
	string m_job;

public:
	//void init(string name, int age, string job)
	//{
	//	m_name = name;
	//	p_age = new int(age);
	//	//*p_age = *age;
	//	m_job = job;
	//}

	//构造函数   
	GirlFriend()
	{
		m_name = "张三";
		p_age = new int(18);
		m_job = "老师";
	}

	//构造函数重载   申请
	GirlFriend(string name, int age, string job)
	{
		m_name = name;
		p_age = new int(age);
		m_job = job;
	}

	//~GirlFriend(){} 默认
	~GirlFriend()//析构  释放（堆区）
	{
		delete p_age;
		p_age = NULL;
		cout << "析构函数" << endl;
	}
	void introduce()
	{
		cout << "我叫" << m_name << ",我今年" << *p_age << "岁，我的职业是" << m_job << endl;
	}

};

int main()
{
	GirlFriend gf1;//自动调用构造函数
	gf1.introduce();

	GirlFriend* pgf2 = new GirlFriend;
	pgf2->introduce();
	delete pgf2;
	pgf2 = NULL;

	GirlFriend gf3("李四", 18, "wunv");
	gf3.introduce();

	GirlFriend gf4 = GirlFriend("李四", 20, "wunv");
	gf4.introduce();

	GirlFriend gf5 = GirlFriend("李四", 22, "wunv");
	gf5.introduce();

	GirlFriend gf6 = GirlFriend{ "李四", 24, "wunv" };
	gf6.introduce();
	//----------------------------------------------
	//堆区
	GirlFriend* pgf7 = new GirlFriend("小王", 18, "123");
	pgf7->introduce();

	GirlFriend* pgf8 = new GirlFriend{ "小王", 20, "123" };
	pgf8->introduce();
	delete pgf7;
	pgf7 = NULL;
	delete pgf8;
	pgf8 = NULL;
	return 0;
}
#endif//构造和析构
#if 0
class A
{
	//类的大小 = 成员变量的大小之和  类就是成员变量的集合
	int num;
	char c;
	void func() 
	{
		int age = 1;
	}//函数不占内存（代码区）
};

class B{};

class C
{
public:
	C() { cout << "C构造" << endl; }
	~C() { cout << "C析构" << endl; }
};
class D
{
public:
	D() { cout << "D构造" << endl; }
	~D() { cout << "D析构" << endl; }
	C c;
};
class E
{
public:
	E() { cout << "E构造" << endl; }
	~E() { cout << "E析构" << endl; }
	D d;
};
int main()
{
	A a;
	cout << sizeof(a) << endl;
	B b;//空类用1个字节保存地址
	cout << sizeof(b) << endl;

	E*pe = new E;
	//创建E类型对像指针     1 分配E内存   2构造成员d  3执行E构造代码
	                                  // 1分配D内存  2 构造成员c 3执行D构造代码
	                                                 //1分配c内存 2执行c构造代码
	delete pe;

	//析构E                1 执行E析构代码   2 析构成员d  3释放E的内存
	                                  //  1 执行D析构代码   2 析构成员c  3释放D的内存
	                                          // 1 执行C析构代码  2释放C的内存
	pe = NULL;
	return 0;
}
#endif//构造析构顺序
#if 0
class GirlFriend
{
	string m_name;
	int* p_age;
	string m_job;

public:

	//构造函数   
	GirlFriend()
	{
		m_name = "张三";
		p_age = new int(18);
		m_job = "老师";
	}

	//构造函数重载   申请
	GirlFriend(string name, int age, string job):m_name(name),p_age(new int (age)),m_job(job)//初始化列表
	{
		//赋值
		/*m_name = name;
		p_age = new int(age);
		m_job = job;*/
	}

	//~GirlFriend(){} 默认
	~GirlFriend()//析构  释放（堆区）
	{
		delete p_age;
		p_age = NULL;
		cout << "析构函数" << endl;
	}
	void introduce()
	{
		cout << "我叫" << m_name << ",我今年" << *p_age << "岁，我的职业是" << m_job << endl;
	}

};

class A
{
	int a;
	int b;
public:
	//初始化列表的初始化顺序与出书和列表的位置无关，与变量的声明顺序有关
	A() :a(10), b(a) 
	{
		cout << "a:" << a <<",b:"<<b<< endl;
	}
};
int main()
{
	int num1 = 10;//初始化
	num1 = 20;//赋值
	int * p = new int(4);
	*p = num1;
	delete p;
	p = NULL;
	A a1;
	return 0;
}
#endif // 初始化列表
#if 1
class Student 
{
	string m_name;
	int m_age;
public:
	//Student() {}
	//this  当前调用对象指针    实参是调用对象地址   形参是this
	Student(string name, int age) :m_name(name), m_age(age)
	{
		cout <<"this:"<< this << endl;
	}
	~Student()
	{
		cout << "析构this:" << this << endl;
	}
	void introdece()
	{
		cout << "我叫：" << m_name << ",今年" << m_age << "岁。" << endl;
	}
};

int main()
{
	Student stu1("小三",18);
	stu1.introdece();
	cout <<"stu1:"<< &stu1 << endl;
	Student stu2("小二", 28);
	stu2.introdece();
	cout <<"stu2:"<< &stu2 << endl;
	return 0;
}
#endif // this 指针

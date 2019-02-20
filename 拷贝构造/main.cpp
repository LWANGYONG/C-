#include<iostream>
#include<string>
using namespace std;

#if 0
//交叉类
class Teacher; //短时声明
//后面实现函数


class Student
{
public:
	// 参数声明 不关心参数内容 只关心参数类型
	void ask(Teacher* teacher, string question);    //向谁提问 提问内容
	/*{
		cout << "问题是：" << question << endl;
		teacher->reply("我也不知道");
	}*/
};

class Teacher
{
private:
	string m_answer;

public:
	void educate(Student* stu)
	{
		stu->ask(this, "什么是this指针");
		cout << "回答：" << m_answer << endl;
	}
	void reply(string answer)
	{
		m_answer = answer;
	}
};
	// 参数声明 不关心参数内容 只关心参数类型
void Student::ask(Teacher* teacher, string question)    //向谁提问 提问内容
{
	cout << "问题是：" << question << endl;
	teacher->reply("我也不知道");
}

int main()
{
	Teacher teacher;
	Student student;
	teacher.educate(&student);


	return 0;
}

#endif // this 指针的使用

#if 1
/* 常成员变量
   必须使用初始化列表初始化
   */
class A
{
	const int m_a;//常成员变量
public:
	A():m_a(10) // 初始化
	{
		//cout << m_a << endl;
	}
	A(int data) :m_a(data)// 用data初始化m_a
	{

	}
};
/*常成员函数
  成员函数形参表后 函数体前加const  修饰是this指针
  函数原型相同的成员函数 ，常版本和非常版本构成重载
  常成员函数不能调用非常成员函数 ，非常成员函数可以调用常成员函数,如果有重载版本的非常函数，优先调用非常函数
  常成员内部无法修改成员变量的值, 除非使用关键字mutable
  */
class Human
{
	string m_name;
	 mutable int m_age;
	 //mutable 可以在常成员中修改被其修饰的值
public:
	Human(string name, int age) :m_name(name), m_age(age)
	{

	}
	void print(/*Human * const this*/) 
	{
		//this = NULL;
        this->m_age++;
		cout << m_name << "," << ++m_age << endl;
		this->foo();
		foo();
	}
	void print(/*const Human * const this*/) const//加const防止修改
	{
		//this = NULL;
		//this->m_age++;
		cout << m_name << "," <</*++*/m_age << endl;
		//常函数中不能调用非常函数
		//this->foo();
		foo();
	}
	void foo()
	{
		cout << "foo" << endl;

	}
	void foo() const
	{
		cout << " const foo" << endl;
	}
}; 

/*
*常对象
* 被const修饰的对象 意味着对象不可以改内容
* 常对象能不能调用非常成员函数？
* 常对象			意味着对象不可以改内容           read only
* 非常成员函数		意味着可以通过函数修改对象内容    read  write
*
* 常对象不能调用非常成员函数，只能调用常函数
*
* 普通对象能不能调用常成员函数？
* 普通对象         意味着对象可以改内容               read  write
* 常成员函数       意味着不可以通过函数修改对象内容    read only
* 非常成员函数	   意味着可以通过函数修改对象内容      read  write
*
* 普通对象可以调用常函数，如果有重载版本的非常函数，优先非常
*
* 编译器认为缩小权限是安全的，扩大权限是危险的，优先选择最合适的
*/
int main()
{
	A a;//调用无参构造
	A a1(20);//调用单参构造

	Human h1("xiaowang", 18);
	h1.print();
	h1.print();

	const Human h2("123", 18);//常对象
	int num = 10;
	int * const p = &num;  //修饰的是（*）指针 不可改指针类型 不可改内容
	//p = NULL;
	*p = 20;

	int const * p1 = &num; //修饰的是 int  不可改int类型 不可改内容
	const int * p2 = &num; //修饰的是 int  不可改int类型 不可改内容
	
	return 0;
}
#endif // 常成员，常对象
 


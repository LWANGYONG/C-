#include<iostream>
#include<string>
using namespace std;

#if 0
//������
class Teacher; //��ʱ����
//����ʵ�ֺ���


class Student
{
public:
	// �������� �����Ĳ������� ֻ���Ĳ�������
	void ask(Teacher* teacher, string question);    //��˭���� ��������
	/*{
		cout << "�����ǣ�" << question << endl;
		teacher->reply("��Ҳ��֪��");
	}*/
};

class Teacher
{
private:
	string m_answer;

public:
	void educate(Student* stu)
	{
		stu->ask(this, "ʲô��thisָ��");
		cout << "�ش�" << m_answer << endl;
	}
	void reply(string answer)
	{
		m_answer = answer;
	}
};
	// �������� �����Ĳ������� ֻ���Ĳ�������
void Student::ask(Teacher* teacher, string question)    //��˭���� ��������
{
	cout << "�����ǣ�" << question << endl;
	teacher->reply("��Ҳ��֪��");
}

int main()
{
	Teacher teacher;
	Student student;
	teacher.educate(&student);


	return 0;
}

#endif // this ָ���ʹ��

#if 1
/* ����Ա����
   ����ʹ�ó�ʼ���б��ʼ��
   */
class A
{
	const int m_a;//����Ա����
public:
	A():m_a(10) // ��ʼ��
	{
		//cout << m_a << endl;
	}
	A(int data) :m_a(data)// ��data��ʼ��m_a
	{

	}
};
/*����Ա����
  ��Ա�����βα�� ������ǰ��const  ������thisָ��
  ����ԭ����ͬ�ĳ�Ա���� �����汾�ͷǳ��汾��������
  ����Ա�������ܵ��÷ǳ���Ա���� ���ǳ���Ա�������Ե��ó���Ա����,��������ذ汾�ķǳ����������ȵ��÷ǳ�����
  ����Ա�ڲ��޷��޸ĳ�Ա������ֵ, ����ʹ�ùؼ���mutable
  */
class Human
{
	string m_name;
	 mutable int m_age;
	 //mutable �����ڳ���Ա���޸ı������ε�ֵ
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
	void print(/*const Human * const this*/) const//��const��ֹ�޸�
	{
		//this = NULL;
		//this->m_age++;
		cout << m_name << "," <</*++*/m_age << endl;
		//�������в��ܵ��÷ǳ�����
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
*������
* ��const���εĶ��� ��ζ�Ŷ��󲻿��Ը�����
* �������ܲ��ܵ��÷ǳ���Ա������
* ������			��ζ�Ŷ��󲻿��Ը�����           read only
* �ǳ���Ա����		��ζ�ſ���ͨ�������޸Ķ�������    read  write
*
* �������ܵ��÷ǳ���Ա������ֻ�ܵ��ó�����
*
* ��ͨ�����ܲ��ܵ��ó���Ա������
* ��ͨ����         ��ζ�Ŷ�����Ը�����               read  write
* ����Ա����       ��ζ�Ų�����ͨ�������޸Ķ�������    read only
* �ǳ���Ա����	   ��ζ�ſ���ͨ�������޸Ķ�������      read  write
*
* ��ͨ������Ե��ó���������������ذ汾�ķǳ����������ȷǳ�
*
* ��������Ϊ��СȨ���ǰ�ȫ�ģ�����Ȩ����Σ�յģ�����ѡ������ʵ�
*/
int main()
{
	A a;//�����޲ι���
	A a1(20);//���õ��ι���

	Human h1("xiaowang", 18);
	h1.print();
	h1.print();

	const Human h2("123", 18);//������
	int num = 10;
	int * const p = &num;  //���ε��ǣ�*��ָ�� ���ɸ�ָ������ ���ɸ�����
	//p = NULL;
	*p = 20;

	int const * p1 = &num; //���ε��� int  ���ɸ�int���� ���ɸ�����
	const int * p2 = &num; //���ε��� int  ���ɸ�int���� ���ɸ�����
	
	return 0;
}
#endif // ����Ա��������
 


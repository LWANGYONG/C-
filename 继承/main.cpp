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
		cout << m_name << "����" << food << endl;
	}
	void sleep()
	{
		cout << m_name << "˯��" << endl;
	}
private:
	int m_age;
protected:
	string m_name;
public:
	int m_gender;
};//����

class Student :public Human
{
public:
	Student():m_ID(0)
	{
		//�����е�˽�г�Ա���������д��ڵ��ǲ��ܵ���
		//m_age = 10;
		//�����еı�����Ա���������п��Է���
		m_name = "����";
		//�����еĹ��г�Ա���������п��Է���
		m_gender = 0;
	}
private:
	int m_ID;
public:
	//ͬ������ �����ж��������ͬ���Ĺ��г�Ա�򱣻���Ա 
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
	//private ֻ���������
	//s1.m_age 

	//protected ֻ��������ʺ��������
	//s1.m_name ="����"
	//public ˭�����Է���
	s1.m_gender = 1;
	cout << "human ��С��" << sizeof(Human) << endl;
	cout << "Student ��С��" << sizeof(Student) << endl;
	//s1.sleep()
   // ���м̳���������κ�ʱ�򶼿��Ա������������Ͷ���
	Human h1 = s1;
	cout << &s1 << endl;

	Human* ph = &s1;
	Human& rh = h1;
	//����ָ���������ָ����������ǻ��໹�����࣬���ܹ⿴��������
	//�����������ʽת���������
	Human h2;
	//Student s2 = h2;

	//son so;
	return 0;
}
#endif //�̳и���͹���˳��
#if 0
class Human
{
public:
	Human()
	{
		cout << "Human this:" << this << endl;
	}
	Human(int age, string name, int gender) :m_age(age), m_name(name), m_gender(gender) { cout << "Human ����:" << this << endl; }
	Human(int age)
	{
		cout << "Human ����:" << this << endl;
	}
	void eat(string food)
	{
		cout << m_name << "����" << food << endl;
	}
	void sleep()
	{
		cout << m_name << "˯��" << endl;
	}
private:
	int m_age;
protected:
	string m_name;
public:
	int m_gender;
};//����

class Student :public Human
{
public:
	//Ĭ�ϵ����޲ι���
	Student():m_ID(0){}
	Student(int age, string name, int gender,int ID) :Human(age, name, gender), m_ID(0)
	{
		cout << "Student �Ĺ���" << this << endl;
	}
private:
	int m_ID;
}; 

int main()
{
	Student s1(1,"��˹",1,23);
	return 0;
}
#endif//��ʼ���б���ʾ���û��๹��
#if 1
class Telephone
{
public:
	Telephone()
	{
		cout << "Telephone ����" << endl;
	}
	void call()
	{
		cout << "��绰" << endl;
	}
	int m_t;
};
class Camera
{
public:
	Camera()
	{
		cout << "Camera ����" << endl;
	}
	void photo()
	{
		cout << "����" << endl;
	}
	int m_c;
};
class Ipod
{
public:
	Ipod()
	{
		cout << "Ipod ����" << endl;
	}
	void music()
	{
		cout << "����" << endl;
	}
	int m_i;
};
class IphoeXs:public Telephone,public Camera,public Ipod
{
public:
	IphoeXs()
	{
		cout << "IphoneXs ����" << endl;
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

	//����ָ��ָ���������
	Telephone* t = &ipx; //���м̳� ��Ȼ��  ����IS A ����
	Camera* c = &ipx;    //���м̳� ��Ȼ��  ����IS A ����
	Ipod *i = &ipx;      //���м̳� ��Ȼ��  ����IS A ����
	cout << t << " " << c << " " << i << " " << endl;
	return 0;
}
#endif//��̳�
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

	//���캯��   
	GirlFriend()
	{
		m_name = "����";
		p_age = new int(18);
		m_job = "��ʦ";
	}

	//���캯������   ����
	GirlFriend(string name, int age, string job)
	{
		m_name = name;
		p_age = new int(age);
		m_job = job;
	}

	//~GirlFriend(){} Ĭ��
	~GirlFriend()//����  �ͷţ�������
	{
		delete p_age;
		p_age = NULL;
		cout << "��������" << endl;
	}
	void introduce()
	{
		cout << "�ҽ�" << m_name << ",�ҽ���" << *p_age << "�꣬�ҵ�ְҵ��" << m_job << endl;
	}

};

int main()
{
	GirlFriend gf1;//�Զ����ù��캯��
	gf1.introduce();

	GirlFriend* pgf2 = new GirlFriend;
	pgf2->introduce();
	delete pgf2;
	pgf2 = NULL;

	GirlFriend gf3("����", 18, "wunv");
	gf3.introduce();

	GirlFriend gf4 = GirlFriend("����", 20, "wunv");
	gf4.introduce();

	GirlFriend gf5 = GirlFriend("����", 22, "wunv");
	gf5.introduce();

	GirlFriend gf6 = GirlFriend{ "����", 24, "wunv" };
	gf6.introduce();
	//----------------------------------------------
	//����
	GirlFriend* pgf7 = new GirlFriend("С��", 18, "123");
	pgf7->introduce();

	GirlFriend* pgf8 = new GirlFriend{ "С��", 20, "123" };
	pgf8->introduce();
	delete pgf7;
	pgf7 = NULL;
	delete pgf8;
	pgf8 = NULL;
	return 0;
}
#endif//���������
#if 0
class A
{
	//��Ĵ�С = ��Ա�����Ĵ�С֮��  ����ǳ�Ա�����ļ���
	int num;
	char c;
	void func() 
	{
		int age = 1;
	}//������ռ�ڴ棨��������
};

class B{};

class C
{
public:
	C() { cout << "C����" << endl; }
	~C() { cout << "C����" << endl; }
};
class D
{
public:
	D() { cout << "D����" << endl; }
	~D() { cout << "D����" << endl; }
	C c;
};
class E
{
public:
	E() { cout << "E����" << endl; }
	~E() { cout << "E����" << endl; }
	D d;
};
int main()
{
	A a;
	cout << sizeof(a) << endl;
	B b;//������1���ֽڱ����ַ
	cout << sizeof(b) << endl;

	E*pe = new E;
	//����E���Ͷ���ָ��     1 ����E�ڴ�   2�����Աd  3ִ��E�������
	                                  // 1����D�ڴ�  2 �����Աc 3ִ��D�������
	                                                 //1����c�ڴ� 2ִ��c�������
	delete pe;

	//����E                1 ִ��E��������   2 ������Աd  3�ͷ�E���ڴ�
	                                  //  1 ִ��D��������   2 ������Աc  3�ͷ�D���ڴ�
	                                          // 1 ִ��C��������  2�ͷ�C���ڴ�
	pe = NULL;
	return 0;
}
#endif//��������˳��
#if 0
class GirlFriend
{
	string m_name;
	int* p_age;
	string m_job;

public:

	//���캯��   
	GirlFriend()
	{
		m_name = "����";
		p_age = new int(18);
		m_job = "��ʦ";
	}

	//���캯������   ����
	GirlFriend(string name, int age, string job):m_name(name),p_age(new int (age)),m_job(job)//��ʼ���б�
	{
		//��ֵ
		/*m_name = name;
		p_age = new int(age);
		m_job = job;*/
	}

	//~GirlFriend(){} Ĭ��
	~GirlFriend()//����  �ͷţ�������
	{
		delete p_age;
		p_age = NULL;
		cout << "��������" << endl;
	}
	void introduce()
	{
		cout << "�ҽ�" << m_name << ",�ҽ���" << *p_age << "�꣬�ҵ�ְҵ��" << m_job << endl;
	}

};

class A
{
	int a;
	int b;
public:
	//��ʼ���б�ĳ�ʼ��˳���������б��λ���޹أ������������˳���й�
	A() :a(10), b(a) 
	{
		cout << "a:" << a <<",b:"<<b<< endl;
	}
};
int main()
{
	int num1 = 10;//��ʼ��
	num1 = 20;//��ֵ
	int * p = new int(4);
	*p = num1;
	delete p;
	p = NULL;
	A a1;
	return 0;
}
#endif // ��ʼ���б�
#if 1
class Student 
{
	string m_name;
	int m_age;
public:
	//Student() {}
	//this  ��ǰ���ö���ָ��    ʵ���ǵ��ö����ַ   �β���this
	Student(string name, int age) :m_name(name), m_age(age)
	{
		cout <<"this:"<< this << endl;
	}
	~Student()
	{
		cout << "����this:" << this << endl;
	}
	void introdece()
	{
		cout << "�ҽУ�" << m_name << ",����" << m_age << "�ꡣ" << endl;
	}
};

int main()
{
	Student stu1("С��",18);
	stu1.introdece();
	cout <<"stu1:"<< &stu1 << endl;
	Student stu2("С��", 28);
	stu2.introdece();
	cout <<"stu2:"<< &stu2 << endl;
	return 0;
}
#endif // this ָ��

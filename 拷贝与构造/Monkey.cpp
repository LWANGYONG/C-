#include "Monkey.h"
#include<iostream>
Monkey::Monkey(string name)
{
	m_name = name;
	mkb = new MonkeyKingBar(20,40);
}

Monkey::Monkey(Monkey const & that)
{
	this->m_name = that.m_name;
#if 0 
	//ϵͳĬ�Ͽ���������ǳ����
	this->mkb = that.mkb;
#endif // ǳ���� ������ַ

#if 1
	//�����ָ����� �����Ҷ�̬�ڴ���䣬�����Ҫ��һ���������캯����
	//1.��������Դ
	this->mkb = new MonkeyKingBar;
	//2.��������Դ
	memcpy(this->mkb, that.mkb, sizeof(/**(that.mkb)*/MonkeyKingBar));//memcpy(������Ŀ���ڴ��׵�ַ��������Դ�ڴ��׵�ַ�������ֽڴ�С)
#endif // ���  �����ڴ�
	std::cout << "��������" << std::endl;
}

void Monkey::introduce() const
{
	std::cout << "�ҽ�" << m_name << ",�ҵĽ𹿰�" << mkb->weght << "�أ�" << mkb->length << "��" << std::endl;
}

Monkey::~Monkey()
{
	if (mkb)
	{
		delete mkb;
		mkb = NULL;
	}
	std::cout << "����" << std::endl;
}

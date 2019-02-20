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
	//系统默认拷贝构造是浅拷贝
	this->mkb = that.mkb;
#endif // 浅拷贝 拷贝地址

#if 1
	//类带有指针变量 ，并且动态内存分配，则必须要有一个拷贝构造函数。
	//1.分配新资源
	this->mkb = new MonkeyKingBar;
	//2.拷贝新资源
	memcpy(this->mkb, that.mkb, sizeof(/**(that.mkb)*/MonkeyKingBar));//memcpy(拷贝的目标内存首地址，拷贝的源内存首地址，拷贝字节大小)
#endif // 深拷贝  拷贝内存
	std::cout << "拷贝构造" << std::endl;
}

void Monkey::introduce() const
{
	std::cout << "我叫" << m_name << ",我的金箍棒" << mkb->weght << "重，" << mkb->length << "长" << std::endl;
}

Monkey::~Monkey()
{
	if (mkb)
	{
		delete mkb;
		mkb = NULL;
	}
	std::cout << "析构" << std::endl;
}

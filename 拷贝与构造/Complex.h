#pragma once
class Complex
{
	double m_real;
	double m_vir;
public:
	//无参构造
	/*
	 * 如果创建一个类没有写任何的构造函数，编译器会自动生成默认无参构造函数，函数体为空 只为了成员变量申请内存
	 *
	 * 一旦写了任何形式的构造函数，编译不再提供
	 * 如果还想用无参构造 需要自己提供无参构造
	 */
	Complex();

	//单参构造函数 参数不是同类型的 类型转换构造函数
	//explicit 防止类型隐式转换
    explicit Complex(double real);

	//单参构造函数 参数是同类型的   拷贝（赋值）构造函数
	//用一个构造好的同类型对象去构造一个新的对象
	//当你不提供拷贝构造函数 编译器会给你提供一个默认的拷贝构造函数
	//默认拷贝构造  复制 只是简单的成员变量值的复制
	Complex(Complex const& that);

	~Complex();
	void print() const;
};


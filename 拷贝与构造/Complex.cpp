#include "Complex.h"
#include<iostream>


Complex::Complex()
{
	m_real = 0;
	m_vir = 0;
	std::cout << "无参构造" << std::endl;
}

Complex::Complex(double real) 
{
	m_real = real;
	m_vir = 0;
	std::cout << "单参构造" << std::endl;
}


Complex::Complex(Complex const& that)
{
	this->m_real = that.m_real;
	this->m_vir = that.m_vir;
	std::cout << "拷贝构造" << std::endl;
}

Complex::~Complex()
{

}

void Complex::print() const
{
	std::cout << m_real << "+" << m_vir <<"i"<< std::endl;
}

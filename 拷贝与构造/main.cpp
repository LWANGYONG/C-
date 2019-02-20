#include<iostream>
#include"Complex.h"
#include"Monkey.h"
using namespace std;

#if 0
int main()
{
	Complex cp1;
	cp1.print();
	Complex cp2(2);
	cp2.print();
	//隐式将int 转换成Comple 因为comple 提供单参构造 参数类型为int
	//Complex cp3 = 4;//Complex cp3 =Complex(4);
	//cp3.print();

	//Complex cp4 = "123";
	//Complex cp5 = '1';

	Complex cp3(cp2);
	cp3.print();
	Complex cp4 = cp3;
	cp4.print();
	cout << "-------------------" << endl;
	//堆区
	Complex* pcp = new Complex(cp2);
	pcp->print();

	getchar();
	return 0;
}
#endif//类型转换构造函数  拷贝构造函数
#if 0
int main()
{
	Monkey*pm1=new Monkey("sunwukong");
	pm1->introduce();
	Monkey*pm2 = new Monkey(*pm1);
	pm2->introduce();
	delete pm1;
	pm1 = NULL;
	delete pm2;
	pm2 = NULL;
	return 0;
}
#endif//浅拷贝 和 深拷贝
#if 0
int main()
{
	int a;

}

#endif // 0
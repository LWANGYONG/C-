#include<iostream>
void sum(int a, int b,int& c)
{
	 c = a + b; 
}
void sum(int a, int b, int* c)
{
	*c = a + b;
}

int main() 
{
	int num1, num2, num;
	num1 = 40;
	num2 = 60;
	sum(num1, num2,num);
	std::cout << num << std::endl; 
	sum(num1, num2, &num);
	std::cout << num << std::endl;
	return 0;
}
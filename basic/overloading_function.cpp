/*
	函数重载
		在同一个作用域内，可以声明几个功能类似的同名函数，
		但是这些同名函数的形式参数（指参数的个数、类型或者顺序）必须不同。
*/
#include <iostream>
using namespace std;

class printData
{
public:
	void print(int i)
	{
		cout << "Printing int: " << i << endl;
	}

	void print(double f)
	{
		cout << "Printing float: " << f << endl;
	}

	void print(char c[])
	{
		cout << "Printing character: " << c << endl;
	}
};

int main(void)
{
	printData pd;

	// Call print to print integer
	pd.print(5);
	// Call print to print float
	pd.print(500.263);
	// Call print to print character
	char str[] = "C string";
	pd.print(str);

	return 0;
}
/*
	C++ 基本语法
	面向对象四大特性：封装、抽象、继承、多态
*/
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

// #define预处理器
// 定义常量
#define LENGTH 10

// 变量声明
extern int a, b;

// 函数声明
int add(int a, int b);

int main()
{
	// 输出语句
	cout << "hello cpp" << endl;

	/*
		基本的内置数据类型
		bool, char, int, float, double, void, wchar_t

		类型修饰符
		signed, unsigned, short, long
		允许在 char、int 和 double 数据类型前放置修饰符
	*/
	cout << "================ 各种数据类型的大小 ==============" << endl;
	cout << "Size of bool : " << sizeof(bool) << endl;
	cout << "Size of char : " << sizeof(char) << endl;
	cout << "Size of int : " << sizeof(int) << endl;
	cout << "Size of short int : " << sizeof(short int) << endl;
	cout << "Size of long int : " << sizeof(long int) << endl;
	cout << "Size of float : " << sizeof(float) << endl;
	cout << "Size of double : " << sizeof(double) << endl;
	cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;

	/*
		数据类型别名
		typedef int new_int;
	*/
	typedef int new_int;
	cout << "Size of new_int : " << sizeof(new_int) << endl;

	/*
		C++ 变量
		作用域：在函数或一个代码块内部声明的变量，称为局部变量;
		在函数参数的定义中声明的变量，称为形式参数;
		在所有函数外部声明的变量，称为全局变量。

		当局部变量被定义时，系统不会对其初始化。
		定义全局变量时，系统会自动初始化为下列值：
		数据类型	初始化默认值
		int	       0
		char	   '\0'
		float	   0
		double	   0
		pointer	   NULL
	*/
	cout << "================ 变量的声明、定义、初始化 ==============" << endl;
	// 变量定义
	int a, b;

	// 变量初始化
	a = 10;
	b = 20;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	cout << "================ 常量的定义 ==============" << endl;
	const int WIDTH = 5;
	cout << "LENGTH = " << LENGTH << endl;
	cout << "WIDTH = " << WIDTH << endl;

	cout << "================ 函数的声明、定义、调用 ==============" << endl;
	cout << "a + b = " << add(a, b) << endl;

	cout << "================ 数组 ==============" << endl;
	// 同时定义初始化
	int arr1[3] = {3, 2, 1};
	cout << "arr1[0] = " << arr1[0] << endl;
	// 先定义，后初始化
	double arr2[3];
	arr2[0] = 100.99;
	cout << "arr2[0] = " << arr2[0] << endl;
	// 根据初始化列表，确定数组大小
	double arr3[] = {1.2, 2.2, 3.3, 4.5};
	cout << "arr3[0] = " << arr3[0] << endl;
	cout << "arr3 = " << arr3 << endl;

	cout << "================ 字符串 ==============" << endl;
	// C风格字符串
	char str[] = "C string";
	cout << "str = " << str << ", str length = " << strlen(str) << endl;
	// C++的string类
	string str2 = "C++ string";
	cout << "str2 = " << str2 << ", str2 length = " << str2.size() << endl;

	/*
		指针是一个变量，其值为另一个变量的地址
	*/
	cout << "================ 指针 ==============" << endl;
	cout << "变量a的地址：" << &a << endl;
	int *ip = &a;
	cout << "pointer ip = " << ip << endl;
	cout << "a = " << *ip << endl;

	/*
		引用是某个已存在变量的另一个名字

		引用与指针的三点不同：
		不存在空引用。引用必须连接到一块合法的内存。
		一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
		引用必须在创建时被初始化。指针可以在任何时间被初始化。
	*/
	cout << "================ 引用 ==============" << endl;
	int &ra = a;
	ra = 20;
	cout << "ra = " << ra << ", a = " << a << endl;

	cout << "================ 日期、时间 ==============" << endl;
	// 基于当前系统的当前日期/时间
	time_t now = time(0);
	cout << "1970年1月1日到目前经过的秒数:" << now << endl;
	// 输出
	tm *ltm = localtime(&now);
	cout << 1900 + ltm->tm_year << 1 + ltm->tm_mon << ltm->tm_mday << endl;
}

// 函数定义
int add(int a, int b)
{
	return a + b;
}
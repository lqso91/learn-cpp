/*
	C++ 继承
	
		已有的类称为基类，新建的类称为派生类。

	继承形式
		class derived-class: access-specifier base-class
		访问修饰符 access-specifier 是 public、protected 或 private， 默认为 private
		公有继承（public）：当一个类派生自公有基类时，
			基类的公有成员也是派生类的公有成员，
			基类的保护成员也是派生类的保护成员，
			基类的私有成员不能直接被派生类访问，但是可以通过调用基类的公有和保护成员来访问。
		保护继承（protected）： 当一个类派生自保护基类时，
			基类的公有和保护成员将成为派生类的保护成员。
		私有继承（private）：当一个类派生自私有基类时，
			基类的公有和保护成员将成为派生类的私有成员。

	访问控制
		访问	  public	protected	private
		同一个类    yes	       yes	      yes
		派生类      yes	       yes	      no
		外部的类    yes	        no	       no
*/

#include <iostream>

using namespace std;

// 基类
class Shape
{
public:
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}

protected:
	int width;
	int height;
};

// 基类 PaintCost
class PaintCost
{
public:
	int getCost(int area)
	{
		return area * 70;
	}
};

// 派生类
class Rectangle : public Shape
{
public:
	int getArea()
	{
		return (width * height);
	}
};

// 多继承
class RectanglePaint : public Shape, public PaintCost
{
public:
	int getArea()
	{
		return (width * height);
	}
};

int main(void)
{
	// 单继承
	Rectangle rect;

	rect.setWidth(5);
	rect.setHeight(7);

	// 输出对象的面积
	cout << "单继承 Total area: " << rect.getArea() << endl;

	// 多继承
	RectanglePaint paintRect;
	int area;

	paintRect.setWidth(5);
	paintRect.setHeight(7);

	area = paintRect.getArea();

	// 输出对象的面积
	cout << "多继承 Total area: " << paintRect.getArea() << endl;

	// 输出总花费
	cout << "多继承 Total paint cost: $" << paintRect.getCost(area) << endl;

	return 0;
}
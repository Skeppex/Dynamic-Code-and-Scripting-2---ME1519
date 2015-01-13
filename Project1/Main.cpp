#include <iostream>
#include <string>
using namespace std;

//abstract base class
class Shape{
protected:
	string name;

public:
	Shape(string s)
	{	name = s;	}
	void setName(string s)
	{	name = s;	}
	string getName() const
	{	return name;	}

	//pure virtual function (making class and child classes abstract, allowing polymorphism) Goes for child classes aswell for access
	virtual double getArea() const = 0;

};

//first child class
class Circle : public Shape
{
	double radius;

public:

	Circle();
	Circle(string n, double r) : Shape(n)
		{	radius = r;	}
	void setRadius(double r)
		{	radius = r;	}
	double getRadius() const
		{	return radius;	}
	
	virtual double getArea() const
	{	return 3.14159 * radius * radius;	}
};


//second child class
class Rectangle : public Shape
{
	double length, width;

public:
	Rectangle(string n, double l, double w) : Shape(n)
		{	length = l; width = w;	}

		void setLength(double l)
		{	length = l;	}
		void setWidth(double w)
		{	width = w;	}
		double getLength() const
		{	return length;	}
		double getWidth() const
		{	return width;	}

		virtual double getArea() const
		{	return length * width;	}
};


//third child class
class Triangle : public Shape{
	double base, width;

public:
	Triangle(string n, double b, double w) : Shape(n)
		{	base = b; width = w;	}

	 double getArea() const
	{	return 0.5 * base * width;	}
};


int main()
{
	double c1, r1, r2, t1, t2;

	//call class name and value
	Circle c("Circle", 3.1);
	//changes classname
	c.setName("Circle!");
	//prints out Name, Radius and Area
	cout << c.getName() << endl;
	cout << "The Radius is: " << c.getRadius() << endl;
	cout << "The Area is: " << c.getArea() << endl;

	//pretty much the same as above
	Rectangle r("Rectangle", 4.2, 2.5);
	cout << r.getName() << endl;
	//besides calling two in one line here
	cout <<"The Width and Length is: " << r.getWidth() << " " << r.getLength() << endl;
	cout << r.getArea() << endl;

	//only has area printed out
	Triangle t("Triangle", 4, 3);
	cout << t.getName() << endl;
	cout << "The Area is: " << t.getArea() << endl;
	
	//set new values into array
	//Circle value
	cout << "Enter new circle value" << endl;
	cout << "First value: " << endl; 
	//cin = input aka set value
	cin >> c1;
	//Rectangle value
	cout << "Enter new Rectangle value" << endl;
	cout << "First value: " << endl;
	cin >> r1;
	cout << "Second value: " << endl;
	cin >> r2;
	//Triangle value
	cout << "Enter new Triangle value" << endl;
	cout << "First value: " << endl;
	cin >> t1;
	cout << "Second value: " << endl;
	cin >> t2;

	//Array for new values
	Shape* shapes[3] = {
		new Circle ("circle", c1),
		new Rectangle ("Rectangle", r1, r2), 
		new Triangle ("Triangle", t1, t2)
	};

	//print area of all shapes in array
	for (int i = 0; i < 3; i++)
		cout << "Shape " << i << " area=" << shapes[i]->getArea() << endl;



	return 0;
}

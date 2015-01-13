#include <iostream>
#include <string>
using namespace std;

//base class
class Shape{
protected:
	string name;


public:
	Shape(string s)
	{
		name = s;
	}

	void setName(string s)
	{
		name = s;
	}

	string getName() const
	{
		return name;
	}

};
//first child class

int Main()
{
	Shape s("Foo");
	cout << s.getName() << endl;

	return 0;
}

#include <iostream>

class test
{
	private:
		int a;
	public:
		test()
		{
			a = 0;
		}
		void setValue(int v)
		{
			a = v;
		}
		void Display()
		{
			std::cout << a << std::endl;
		}
};

int main()
{
	test a;
	test b;

	a.setValue(6);
	b.setValue(9);
	a.Display();
	b.Display();
}

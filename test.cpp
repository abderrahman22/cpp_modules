#include <iostream>

using namespace std;

class number
{
	public:
		int n;
		number(int z)
		{
			n = z;
		}
		number operator+(number &j)
		{
			std::cout << this->n << std::endl;
			std::cout << j.n << std::endl;
			return (this->n + j.n);
		}
		bool operator==(number &j)
		{
			cout << "overload == called" << endl;
			cout << "n " << this->n << endl;
			cout << "j.n " << j.n <<  endl;
			if (j.n == n)
			{
				return true;
			}
			else
				return false;
		}
};

int main()
{
	number a(10);
	number b(7);

	number c = b + a;
	cout << c.n << endl;
	number d(77);
	if (c == d)
	{
		cout << "true" << endl;
		return 1;
	}
	else
	{
		cout << "false" << endl;
		return -1;
	}
}

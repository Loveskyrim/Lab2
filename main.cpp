// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//


#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <string>


class ME
{
private:
	std::string name;
	int num;
public:
	ME()
{
	num=0;
	name="default";
}

	ME(int a, std::string b)
	{
		num=a;
		name=b;
	}

	ME(const ME& src)
	{
		num=src.num;
		name=src.name ;
	}

void getData()
{ 
	std::cout << "name: ";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin,name);
	std::cout << "number: ";
	std::cin >> num;
}

void showMe() const
{
	std::cout << "name:" << name;
	std::cout << "number:" << num;
}

bool check(int a) const
{
	switch(num)
	{
	case 1: if (a>0) return true; else return false; break; 
	case 2: if (a>1) return true; else return false; break;
	case 3: if (a>2) return true; else return false; break;
	case 4: if (a>3) return true; else return false; break;
	case 5: if (a>4) return true; else return false; break;
	default: return false;
	}
}

void printMe(std::ostream& out)
{
	out << "class name: ME" << '\n' << 'num ' << num <<'\n';
	out << "names" << name;
}


};

int main()
{
	int n;
	int cl;
	std::cout << "n = " ;
	std::cin >> n;
	ME* mes = new ME[n];
	for (int i=0; i<n; i++)
	{
		std::cout << i+1 << "\n";
		mes[i].getData();
	}
	std::cout << "Class: ";
	std::cin >> cl;
	for (int i=0; i<n; i++)
		if (mes[i].check(cl))
		{
			std::cout << i+1 << "\n";
			mes[i].showMe();
		}
	delete [] mes;
	system ("pause");
	return 0;
}

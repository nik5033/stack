#include "Complex.h"

class Union
{
private:
	Number<double> type1;
	Number<int> type2;
	Complex type3;
	int flag;
public:
	void Enter();
	double Module();
	Number <double> Get1();
	Number <int> Get2();
	Complex Get3();
	int Get_Flag();
	void operator=(Union &other);
	bool operator==(Union other);
	void Set(Number<double> type);
	void Set(Number<int> type);
	void Set(Complex type);
	void Show();
};

void Union::Enter()
{
	int choice;
	while (true)
	{
		cout << "\nЦелый или вещественный тип?(1,0)\n";
		cin >> choice;
		if (!cin || (choice != 1 && choice != 0))
		{
			cout << "Ошибка!!! Повторите ввод\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	switch (choice)
	{
	case 1:
	{
		int im; int real;
		while (true)
		{
			cout << "Действительная часть:";
			cin >> real;
			if (!cin)
			{
				cout << "Ошибка!!! Повторите ввод\n";
				cin.clear();
				while (cin.get() != '\n');
			}
			else break;
		}
		while (true)
		{
			cout << endl << "Мнимая часть:";
			cin >> im;
			if (!cin)
			{
				cout << "Ошибка!!! Повторите ввод\n";
				cin.clear();
				while (cin.get() != '\n');
			}
			else break;
		}
		if (im == 0)
		{
			Number<int> Num;
			Num.Set(real);
			Set(Num);
		}
		else
		{
			Complex Num;
			Num.Set(real, im);
			Set(Num);
		}
		break;
	}
	case 2:
	{
		double im; double real;
		while (true)
		{
			cout << "Действительная часть:";
			cin >> real;
			if (!cin)
			{
				cout << "Ошибка!!! Повторите ввод\n";
				cin.clear();
				while (cin.get() != '\n');
			}
			else break;

		}
		while (true)
		{
			cout << endl << "Мнимая часть:";
			cin >> im;
			if (!cin)
			{
				cout << "Ошибка!!! Повторите ввод\n";
				cin.clear();
				while (cin.get() != '\n');
			}
			else break;
		}
		if (im == 0)
		{
			Number<double> Num;
			Num.Set(real);
			Set(Num);
		}
		else
		{
			Complex Num;
			Num.Set(real, im);
			Set(Num);
		}
		break;
	}
	}
}

double Union::Module()
{
	switch (flag)
	{
	case 1:
		return type1.Get_Module();
		break;
	case 2:
		return type2.Get_Module();
		break;
	case 3:
		return type3.Get_Module();
		break;
	default:
		return -1;
	}
}

Number <double> Union::Get1()
{
	return type1;
}

Number <int> Union::Get2()
{
	return type2;
}

Complex Union::Get3()
{
	return type3;
}

int Union::Get_Flag()
{
	return flag;
}

void Union:: operator=(Union &other)
{
	switch (other.flag)
	{
	case 1:
		this->type1.Set(other.type1.Get_Real());
		break;
	case 2:
		this->type2.Set(other.type2.Get_Real());
		break;
	case 3:
		this->type3.Set(other.type3.Get_Real(), other.type3.Get_Im());
		break;
	}
	this->flag = other.flag;
}
bool Union:: operator==(Union other)
{
	switch (flag)
	{
	case 1:
		switch (other.Get_Flag())
		{
		case 1:
			if (this->type1.Get_Real() == other.type1.Get_Real())
				return true;
			else return false;
		case 2:
			if (this->type1.Get_Real() == other.type2.Get_Real())
				return true;
			else return false;
		case 3:
			return false;
		}
	case 2:
		switch (other.Get_Flag())
		{
		case 1:
			if (this->type2.Get_Real() == other.type1.Get_Real())
				return true;
			else return false;
		case 2:
			if (this->type2.Get_Real() == other.type2.Get_Real())
				return true;
			else return false;
		case 3:
			return false;
		}
	case 3:
		switch (other.Get_Flag())
		{
		case 1:
			return false;
		case 2:
			return false;
		case 3:
			if (this->type3.Get_Real() == other.type3.Get_Real() && this->type3.Get_Im() == other.type3.Get_Im())
				return true;
			else return false;
		}
	}
}

void Union::Set(Number<double> type)
{
	type1 = type;
	flag = 1;
}
void Union::Set(Number<int> type)
{
	type2 = type;
	flag = 2;
}
void Union::Set(Complex type)
{
	type3 = type;
	flag = 3;
}
void Union::Show()
{
	switch (flag)
	{
	case 1:
		type1.Show_Num();
		break;
	case 2:
		type2.Show_Num();
		break;
	case 3:
		type3.Show_Num();
		break;
	}
}
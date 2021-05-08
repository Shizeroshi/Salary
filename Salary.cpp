#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class SalaryH
{
	int perHour;
	
public:
	int GetPerHour()const
	{
		return perHour;
	}
	void SetPerHour(int perHour)
	{
		this->perHour = perHour;
	}
	SalaryH()
	{
		this->perHour = 10;
		cout << "ConstructorDH:\t" << this << endl;
	}
	SalaryH(int perHour)
	{
		this->perHour = perHour;
		cout << "ConstructorH:\t" << this << endl;
	}
	~SalaryH()
	{
		cout << "DestructorH:\t" << this << endl;
	}

};

class SalaryM
{
	int perMounth;
public:
	int GetPerMounth()const
	{
		return perMounth;
	}
	void SetPerMounth(int perMounth)
	{
		this->perMounth = perMounth;
	}
	SalaryM()
	{
		this->perMounth = 1000;
		cout << "ConstructorDM:\t" << this << endl;
	}
	SalaryM(int perMounth)
	{
		this->perMounth = perMounth;
		cout << "ConstructorM:\t" << this << endl;
	}
	~SalaryM()
	{
		cout << "DestructorM:\t" << this << endl;
	}
};

class SalaryA
{
	int SalarySum;
public:
	int GetSalarySum()const
	{
		return SalarySum;
	}
	void SetSalarySum(int SalarySum)
	{
		this->SalarySum = SalarySum;
	}
	SalaryA()
	{
		this->SalarySum = 0;
		cout << "ConstructorDA:\t" << this << endl;
	}
	SalaryA(int SalarySum)
	{
		this->SalarySum = SalarySum;
		cout << "ConstructorA:\t" << this << endl;
	}
	~SalaryA()
	{
		cout << "DestructorA:\t" << this << endl;
	}
};

ostream& operator<<(ostream& os, const SalaryH& obj)
{
	return os << obj.GetPerHour();
}

ostream& operator<<(ostream& os, const SalaryM& obj)
{
	return os << obj.GetPerMounth();
}

ostream& operator<<(ostream& os, const SalaryA& obj)
{
	return os << obj.GetSalarySum();
}

SalaryH operator*(SalaryH left, SalaryH right)
{
	SalaryH result;
	result.SetPerHour(left.GetPerHour() * right.GetPerHour());
	return result;
}

SalaryM operator*(SalaryM left, SalaryM right)
{
	SalaryM result;
	result.SetPerMounth(left.GetPerMounth() * right.GetPerMounth());
	return result;
}

SalaryA operator*(SalaryA left, SalaryA right)
{
	SalaryA result;
	result.SetSalarySum(left.GetSalarySum() * right.GetSalarySum());
	return result;
}

SalaryA operator+(SalaryM left, SalaryH right)
{
	SalaryA result;
	result.SetSalarySum(left.GetPerMounth() + right.GetPerHour());
	return result;
}

int main()
{
	setlocale(LC_ALL, "");
	system("color 0A");

	SalaryH Employee; // $10 - Почасовая оплата
	SalaryM Employee2; // $1000 - Постоянная оплата одного сотрудника (помесячно я так понимаю)

	SalaryH HourSalaryForDay = Employee * 8; // Зарплата одного сотрудника с почасовой оплатой за 1 рабочий день - 80
	SalaryH HourSalaryForDayAllEmployees = HourSalaryForDay * 15; // Зарплата всех сотрудников с почасовой оплатой за день - 1 200
	SalaryH HourSalaryForMounth = HourSalaryForDay * 30; // Зарплата одного сотрудника с почасовой оплатой за месяц - 2 400
	SalaryH HourSalaryForMounthAllEmployees = HourSalaryForDayAllEmployees * 30; // Зарплата всех сотрудников с почасовой оплатой за месяц - 36 000

	SalaryM MounthSalaryAllEmployees = Employee2 * 15; // Зарплата всех сотрудников с постоянной оплатой - 15 000

	SalaryA SalaryAllEmployees = MounthSalaryAllEmployees + HourSalaryForMounthAllEmployees; // Зарплата всех сотрудников - 51 000

	cout << endl;
	cout << "-----------------------------------------------------------\n";
	cout << "Зарплата одного сотрудника с почасовой оплатой за 1 рабочий день: $" << HourSalaryForDay << endl;
	cout << "Зарплата всех сотрудников с почасовой оплатой за день: $" << HourSalaryForDayAllEmployees << endl;
	cout << "Зарплата одного сотрудника с почасовой оплатой за месяц: $" << HourSalaryForMounth << endl;
	cout << "Зарплата всех сотрудников с почасовой оплатой за месяц: $" << HourSalaryForMounthAllEmployees << endl;
	cout << "-----------------------------------------------------------\n";
	cout << "Зарплата всех сотрудников с постоянной оплатой: $" << MounthSalaryAllEmployees << endl;
	cout << "-----------------------------------------------------------\n";
	cout << "Зарплата всех сотрудников: $" << SalaryAllEmployees << endl;
	cout << "-----------------------------------------------------------\n";
	cout << endl;
}
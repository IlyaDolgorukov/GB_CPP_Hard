#include <iostream>
#include <string>
#include <optional>

using namespace std;

class Person
{
private:
	string lastname, firstname;
	optional<string> middlename;

public:
	Person(string ln, string fn) : lastname(ln), firstname(fn) {}
	Person(string ln, string fn, string mn) : lastname(ln), firstname(fn), middlename(mn)
	{
		if (mn == "-") {
			middlename = nullopt;
		}
	}

	// bool operator< (const Person &p1, const Person &p2)
	// {

	// }

	// bool operator== (const Person &p1, const Person &p2)  << "\t" << pers.middlename.has_value() ? pers.middlename : ""
	// {

	// }

	friend ostream& operator<<(ostream &os, const Person &pers);
};

ostream& operator<<(ostream &os, const Person &pers)
{
	return os << "test" << pers.lastname << "\t" << pers.firstname;
}

int main(int argc, char const *argv[])
{
	Person p1("Pupkin", "Vasiliy", "Petrovich");
	Person p2("Sidorov", "John", "-");
	Person p3("Ivanov", "Ivan", "Ivanovich");

	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;

	return 0;
}

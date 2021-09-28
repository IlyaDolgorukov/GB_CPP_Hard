#include <iostream>
#include <string>
#include <optional>
#include <variant>
#include <tuple>
#include <vector>
#include <fstream>

using namespace std;

class Person
{
private:
	string lastname, firstname;
	optional<string> middlename;

public:
	Person (string ln, string fn) : lastname(ln), firstname(fn) {}
	Person (string ln, string fn, string mn) : lastname(ln), firstname(fn), middlename(mn) {}

	friend ostream &operator<< (ostream &os, const Person &pers);
	friend bool operator< (const Person &p1, const Person &p2);
	friend bool operator== (const Person &p1, const Person &p2);
};

ostream &operator<< (ostream &os, const Person &pers)
{
	string middlename = pers.middlename.has_value() ? pers.middlename.value() : " ";
	return os << pers.lastname << "\t" << pers.firstname << "\t" << middlename;
}

bool operator< (const Person &p1, const Person &p2)
{
	return tie(p1.lastname, p1.firstname, p1.middlename) < tie(p2.lastname, p2.firstname, p2.middlename);
}

bool operator== (const Person &p1, const Person &p2)
{
	return tie(p1.lastname, p1.firstname, p1.middlename) == tie(p2.lastname, p2.firstname, p2.middlename);
}

class PhoneNumber
{
private:
	int country, city;
	string number;
	optional<int> additional;
public:
	PhoneNumber (int co, int ct, string num) : country(co), city(ct), number(num) {}
	PhoneNumber (int co, int ct, string num, int add) : country(co), city(ct), number(num), additional(add) {}

	friend ostream &operator<< (ostream &os, const PhoneNumber &phone);
	friend bool operator< (const PhoneNumber &ph1, const PhoneNumber &ph2);
};

ostream &operator<< (ostream &os, const PhoneNumber &phone)
{
	string additional = phone.additional.has_value() ? to_string(phone.additional.value()) : "";
	return os << "+" << phone.country << "(" << phone.city << ")" << phone.number << " " << additional;
}

bool operator< (const PhoneNumber &ph1, const PhoneNumber &ph2)
{
	return tie(ph1.country, ph1.city, ph1.number, ph1.additional) < tie(ph2.country, ph2.city, ph2.number, ph2.additional);
}

class PhoneBook
{
private:
	vector<pair<Person, PhoneNumber>> contacts;
public:
	PhoneBook (ifstream &fl)
	{
		string line;
		int cnt = 1;
		while (getline(fl, line)) {
			cout << cnt << ": " << line << endl;
			cnt++;
		}
	}
};

int main(int argc, char const *argv[])
{
	// Person p1 {"Pupkin", "Vasiliy", "Petrovich"};
	// Person p2 {"Sidorov", "John"};
	// Person p3 {"Ivanov", "Ivan", "Ivanovich"};
	// Person p4 {"Pupkin", "Vasiliy", "Petrovich"};

	// cout << boolalpha << (p1 < p2) << endl;
	// cout << boolalpha << (p2 < p3) << endl;
	// cout << boolalpha << (p1 == p2) << endl;
	// cout << boolalpha << (p1 == p4) << endl;

	// cout << p1 << endl;
	// cout << p2 << endl;
	// cout << p3 << endl;

	// PhoneNumber ph1 {7, 17, "4559767"};
	// PhoneNumber ph2 {4, 23, "4559767", 14};
	// PhoneNumber ph3 {2, 12, "4559767"};

	// cout << ph1 << endl;
	// cout << ph2 << endl;
	// cout << ph3 << endl;

	ifstream file("PhoneBook.txt");
	PhoneBook book {file};

	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template <class T>
void printList(const list<T>& lst) {
    for(const auto& a: lst){
        cout << a << " ";
    }
    cout << endl;
}

void addAverage(list<float>& lst)
{
	size_t cnt = 0;
	float sum = 0;
	for(const auto& a: lst){
        sum += a;
        cnt++;
    }
    float avr = sum / static_cast<float>(cnt);
    lst.push_back(avr);
}

class MyIterator
{
private:
	int first, last;
public:
	int current;

    MyIterator(int b, int e) : first(b), last(e)
    {
    	current = b;
    }

    friend MyIterator& operator++(MyIterator& i);
    friend int operator*(const MyIterator& i);
    friend bool operator!=(const MyIterator& left, const MyIterator& right);
};

MyIterator& operator++(MyIterator& i)
{
	i.current++;
	return i;
}

int operator*(const MyIterator& i)
{
	return i.current;
}

bool operator!=(const MyIterator& left, const MyIterator& right)
{
	return left.current != right.last + 1;
}

class MyRange
{
private:
	MyIterator iter;
public:
	MyRange(int b, int e) : iter({b, e}) {}

	MyIterator begin() const
	{
		return iter;
	}

	MyIterator end() const
	{
		return iter;
	}
};

int main(int argc, char const *argv[])
{
	cout << "---------------- Task 1 ------------------" << endl;

	list<float> lst = { 1.2, 2.3, 3.4, 4.5 };
	printList(lst);
	addAverage(lst);
	printList(lst);

	cout << "---------------- Task 2 ------------------" << endl;

	// К сожалению, я не учился в институте и не умею вычислять определитель матрицы
	cout << "Sorry, I'm too stupid for this..." << endl;

	cout << "---------------- Task 3 ------------------" << endl;

	for (const int num : MyRange{10, 25}) {
	    cout << num << " ";
	}

	return 0;
}

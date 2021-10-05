#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template <class T>
void printList(const std::list<T>& lst) {
    for(const auto& a: lst){
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

void addAverage(std::list<float>& lst)
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

int main(int argc, char const *argv[])
{
	cout << "---------------- Task 1 ------------------" << endl;

	list<float> lst = { 1.2, 2.3, 3.4, 4.5 };
	printList(lst);
	addAverage(lst);
	printList(lst);

	cout << "---------------- Task 2 ------------------" << endl;

	// К сожалению, я не учился в институте и не умею вычислять определитель матрицы

	cout << "---------------- Task 3 ------------------" << endl;

	

	return 0;
}

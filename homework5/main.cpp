#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

template <typename T, template<typename> class Container>
void printData(const Container<T>& data) {
    for(const auto& a: data){
        cout << a << " ";
    }
    cout << endl;
}

template <typename T, template<typename> class Container>
void printUnique(Container<T>& data) {
    set<T> st;
    copy(data.begin(), data.end(), inserter(st, st.end()));
    copy(st.begin(), st.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
}

int main(int argc, char const *argv[])
{
	cout << "---------------- Task 1 ------------------" << endl;

	vector<string> nums = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

	vector<string> vec(50);
	generate(vec.begin(), vec.end(), [nums]() {
		int index = 1 + rand() % 10;
		return nums[index - 1];
	});
	cout << "Vector all:" << endl;
	printData(vec);
	cout << "Vector unique:" << endl;
	printUnique(vec);

	cout << endl;

	deque<string> dec(50);
	generate(dec.begin(), dec.end(), [nums]() {
		int index = 1 + rand() % 10;
		return nums[index - 1];
	});
	cout << "Deque all:" << endl;
	printData(dec);
	cout << "Deque unique:" << endl;
	printUnique(dec);

	cout << endl;

	list<string> lst(50);
	generate(lst.begin(), lst.end(), [nums]() {
		int index = 1 + rand() % 10;
		return nums[index - 1];
	});
	cout << "List all:" << endl;
	printData(lst);
	cout << "List unique:" << endl;
	printUnique(lst);
	

	return 0;
}

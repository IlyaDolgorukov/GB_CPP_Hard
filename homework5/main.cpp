#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

template <typename T, template<typename> class Container>
void printData(const Container<T>& data)
{
    for(const auto& a: data){
        cout << a << " ";
    }
    cout << endl;
}

template <typename T, template<typename> class Container>
void printUnique(Container<T>& data)
{
    set<T> st;
    copy(data.begin(), data.end(), inserter(st, st.end()));
    copy(st.begin(), st.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
}

void ltrim(string &s)
{
	s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void printSentences(const string& inp)
{
	stringstream ss(inp);
	string sentence;
	char delim = '.';
	priority_queue<pair<int, string>> q;
	while(getline(ss, sentence, delim)) {
		ltrim(sentence);
		q.push({sentence.size(), sentence});
	}
	while (!q.empty()) {
		cout << q.top().second << endl;
		q.pop();
	}
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
	cout << endl;

	cout << "---------------- Task 2 ------------------" << endl;

	cout << "Please enter a few sentences separated by dots:" << endl;
	string input;
	getline(cin, input);
	printSentences(input);

	return 0;
}

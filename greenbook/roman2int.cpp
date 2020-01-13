#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	unordered_map<char, int> dict = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};
	string s;
	cin >> s;

	stack<int> values;
	for (int i = 0; i < s.length(); ++i)
	{
		int val = dict.at(s[i]);
		while(!values.empty() && values.top() < val)
		{
			val -= values.top();
			values.pop();
		}
		values.push(val);
	}
	int accum = 0;
	while (!values.empty())
	{
		accum += values.top();
		values.pop();
	}
	cout << accum << endl;
	return 0;
}

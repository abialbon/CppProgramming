#include <iostream>

using namespace std;

void print_binary(int i)
{
	while(i)
	{
		cout << i % 2;
		i /= 2;
	}
	cout << endl;
}

int main() 
{
	print_binary(243);
	return 0;
}


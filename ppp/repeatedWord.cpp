#include<iostream>
#include<string>

using namespace std;

int main() {
	string previous = " ";
	string current;

	while(std::cin>>current) {
		if(previous==current) {
			cout << "Repeated word " << current << "\n";
		}
		else if(current == "stop") {
			return 0;
		}
		previous = current;
	}
}

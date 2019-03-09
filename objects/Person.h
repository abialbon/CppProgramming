#include <string>
#ifndef PERSON // If not defined
#define PERSON

class Person{
private:
	std::string firstname;
	std::string lastname;
	int age;
public:
	Person(int a, std::string first, std::string last);
	~Person();
	void describe_person();
}; // Colon here is very important

#endif /* PERSON */

// Basic object construction and class definitions

#include <iostream>
#include <string>
#include "Person.h"

int main()
{
	Person p1(28, "Peter", "Pan");
	Person p2(30, "Good", "Fellow");
	p1.describe_person();
	p2.describe_person();
	return 0;
}

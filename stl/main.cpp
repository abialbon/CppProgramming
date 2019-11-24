#include <iostream>
#include <vector>
#include <string>

class Person {
public:
    std::string name;
};

int main() {
    std::vector<int> scores;
    scores.push_back(28);
    scores.push_back(98);
    scores.push_back(77);
    scores.push_back(49);

    int sum = 0;
    for (auto i = scores.begin(); i != scores.end(); ++i) {
        sum += *i;
    }
    // A better way to write the same loop would be
    int sum1 = 0;
    for (int& score : scores) sum1 += score;

    std::cout << sum / scores.size() << std::endl;
    std::cout << sum1 / scores.size() << std::endl;
    // Reverse iteration
    for (auto i = scores.rbegin(); i != scores.rend(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    // Yet another way of iterating
    for (int i = 0; i < scores.size(); ++i)
    {
        std::cout << scores[i] << " ";
    }
    std::cout << std::endl;

    std::vector<Person> pv;
    Person p1;
    Person p2;
    p1.name = "Paul";
    p2.name = "Peter";
    pv.push_back(p1);
    pv.push_back(p2);

    pv[0].name = "Abialbon";

    std::cout << p1.name << std::endl;
    std::cout << pv[0].name << std::endl;

    return 0;
}
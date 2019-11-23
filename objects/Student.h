#include <string>

class Student {
    private:
        int studnetNo;
        std::string firstName;
        std::string lastName;
        std::string type;
        int fee;
        int paid;
        std::string email;

    public:
        Student(std::string first, std::string last, std::string type, int fee, int paid, std::string email);
        std::string getName();
        int find_balance();
        std::string print_email();
        void pay_fee(int amt);
};
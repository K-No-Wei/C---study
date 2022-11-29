#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    int age;
public:
    Person(int age, string name):age(age),name(name){};
    Person(){};
    ~Person(){};
    bool operator==(Person &p1){
        return p1.age == this->age && p1.name == this->name;
    }

    void operator()(){
        
    }
};

int main() {
    Person p1(1, "zlw");
    Person p2(1, "zl");
    cout << (p1 == p2);
    return 0;
}
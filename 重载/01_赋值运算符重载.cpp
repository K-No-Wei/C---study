#include<iostream>

using namespace std;

class Person
{
private:
    /* data */
public:
    Person(/* args */);
    ~Person();
    int m_Age;
    Person& operator=(const Person &p1){
        this->m_Age = p1.m_Age + 10;
        return *this;
    }
    Person(const Person &p){
        this->m_Age = p.m_Age + 10;
    }
};

Person::Person(/* args */)
{
}

Person::~Person()
{
    this->m_Age = 0;
}

int main(){
    Person p1;
    p1.m_Age = 10;
    Person p2 = p1;
    cout << p2.m_Age;
    system("pause");
    return 0;
}
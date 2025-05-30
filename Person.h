#ifndef PERSON_H
#define PERSON

#include <string>

class Person{
    protected:
    std::string name;
    int id;
    std::string role;

    public:
    //constructors
    Person();
    Person(std::string _name,int _id, std::string _role);
    virtual ~Person();

    virtual double calculatePay() = 0;
    virtual void showInfo() = 0;
};

#endif
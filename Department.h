#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <Person.h>
#include <vector>

class Department{
    private:
    std::string name;
    std::vector<Person*> members;

    public:
    Department(std::string name);
    ~Department();

    void addMember(Person* member);
    double calculateDepartmentPay();
    void showDepartmentInfo();
};

#endif
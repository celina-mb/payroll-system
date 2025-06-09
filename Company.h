#pragma once
#include <vector>
#include "Department.h"

class Company{
    private:
    std::string name;
    std::vector<Department*> departments;

    public:
    Company(std::string name);

    void addDepartment(Department* dept);
    void removeDepartment(std::string id);
    float calculateCompanyPay();
    std::string displayInfo();
    bool operator==(Company& comp2);
};

#pragma once
#include <Employee.h>
#include <vector>

class Department{
    private:
    std::string name;
    std::string id;
    std::vector<Employee*> employees;

    public:
    Department(std::string name, std::string id);

    void addEmployee(Employee* employee);
    void removeEmployee(std::string employeeID);
    float calculateDepartmentPay();
    std::string displayInfo();
};

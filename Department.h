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

    std::string getDepartmentName();
    std::string getDepartmentID();
    std::vector<Employee*> getEmployees();

    void addEmployee(Employee* emp);
    void removeEmployee(std::string empID);
    float calculateDepartmentPay();
    std::string displayInfo();
};

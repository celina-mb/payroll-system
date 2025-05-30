#ifndef EMPLOYEE_H
#define EMPLOYEE

#include <string>
#include "Person.h"

class Employee : public Person{
    private:
    double hourlyWage;
    double hoursWorked;

    public:
    Employee();
    Employee(std::string& name_, int _id, std::string& _role, double _hourlyWage, double _hoursWorked);
    double calculatePay() override;
    string getRole();
    void showInfo() override;
    void setHoursWrkd(double);
};

#endif
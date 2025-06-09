#pragma once

#include <string>

class Employee{
    protected:
    std::string name;
    std::string id;
    int workingDays;
    float baseSalary;

    public:
    //constructor
    Employee(std::string name, std::string id, int workingDays, float baseSalary);
    std::string getName();
    std::string getID();

    //virtual methods, will be overriden by subclasses
    virtual float calculatePay() = 0;
    virtual std::string displayInfo() = 0;
};

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
    int getWorkingDays();
    float getBaseSalary();

    //setters for attributes that might change over time
    void setWorkingDays(int);
    void setBaseSalary(float);

    //method to be overloaded by subclasses
    float calculateSalary();

    //virtual method, will be overriden by subclasses
    virtual std::string displayInfo() = 0;
};

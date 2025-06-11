#pragma once
#include "Employee.h"

class Boss : public Employee{ //inheritance
    private:
    float bonus;

    public:
    Boss(std::string name, std::string id, int workingDays, float baseSalary, float bonus);
    
    void setBonus(float qty);
    float calculateSalary(float tax); //receives float (tax) as a 0.15, not percentually
    std::string displayInfo() override; //overriding the pure virtual method declared in Employee
};


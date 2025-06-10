#pragma once
#include "Employee.h"

class Boss : public Employee{
    private:
    float bonus;

    public:
    Boss(std::string name, std::string id, int workingDays, float baseSalary, float bonus);
    
    void setBonus(float qty);
    float calculateSalary(float tax);
    std::string displayInfo() override;
};


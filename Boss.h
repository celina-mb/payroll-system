#pragma once
#include "Employee.h"

class Boss : public Employee{
    private:
    float bonus;

    public:
    Boss(std::string name, std::string id);
    
    void setBonus(float qty);
    float calculatePay() override;
    float calculatePay(float tax);
    std::string displayInfo() override;
};


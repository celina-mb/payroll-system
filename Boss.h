#ifndef BOSS_H
#define BOSS

#include <string>
#include "Person.h"
using namespace std;

class Boss : public Person{
    private:
    double bonus;
    double baseSalary;

    public:
    Boss(string& name, int id, string& role, double bonus, double baseSalary);
    double calculatePay() override;
    void showInfo() override;
    void setBonus(double _bonus);
};
#endif


#ifndef COMPANY_H
#define COMPANY_H

#include "Department.h"
#include <vector>

class Company{
    private:
    std::vector<Department*> personnel;

    public:
    ~Company();

    void addDepartment(Department* dept);
    void removeDepartment(int index);
    double calculateCompanyPay();
    void showCompanyInfo();
};

#endif
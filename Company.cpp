#include "Company.h"

Company::Company(std::string name){
    this-> name = name;
}

//this is necesary for displaying the company's payroll in main
std::string Company::getName(){
    return name;
}

void Company::addDepartment(Department* d){
    departments.push_back(d);
}

//removes a department by looping through the vector's elements until it finds the one that matches the function's input
void Company::removeDepartment(std::string dID){
    for (auto i = departments.begin(); i!=departments.end(); ++i){
        if ((*i)->getDepartmentID() == dID){
            departments.erase(i);
            return;
        }
    }
}

//cummulative for all salaries within departments (departments within a company)
float Company::calculateCompanySalaries(){
    float salaries = 0.0f;
    for (Department* d: departments){
        salaries += d->calculateDepartmentPay();
    }
    return salaries;
}

//uses the displayInfo method found in department, with a for loop
std::string Company::displayInfo(){
    std::string aux = std::string("-------------------------\n") + "COMPANY INFORMATION\n" + std::string("-------------------------\n")+ "Company Name: "+ name+ " \n"+"Total Departments: "+std::to_string(departments.size()) + "\n";
    for (Department* d : departments){
        aux += d->displayInfo() + "\n" + std::string("-------------------------\n");
    }
    return aux;
}

//operator overloading
bool Company::operator==(Company& other){
    return (this-> departments.size()==other.departments.size());
}

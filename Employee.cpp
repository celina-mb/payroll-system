 #include "Employee.h"

 Employee::Employee(std::string name, std::string id, int workingDays, float baseSalary){
    this-> name = name;
    this-> id = id;
    this-> workingDays = workingDays;
    this-> baseSalary = baseSalary;
}

std::string Employee::getName(){
    return name;
}

std::string Employee::getID(){
    return id;
}

int Employee::getWorkingDays(){
    return workingDays;
}

float Employee::getBaseSalary(){
    return baseSalary;
}

void Employee::setWorkingDays(int d){
    workingDays = d;
}

void Employee::setBaseSalary(float s){
    baseSalary = s;
}

float Employee:: calculateSalary(){
    return workingDays*baseSalary;
}

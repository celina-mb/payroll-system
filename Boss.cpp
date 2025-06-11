#include "Boss.h"

//constructor
Boss::Boss(std::string name, std::string id, int workingDays, float baseSalary, float bonus): Employee(name, id, workingDays, baseSalary) {
    this-> bonus = bonus;
}

//setter for Bonus as it might change over time
void Boss::setBonus(float qty){
    bonus = qty;
}

/*no need for a getter method here, as all the information will be displayed through a string 
also, no external classes for which the attributes are private will need access to the private
attributes*/

//method overloading
float Boss::calculateSalary(float tax){ //receives tax as a float number, not percentage
    return (baseSalary+bonus)*tax;
}

//method overriding
std::string Boss::displayInfo(){
    std::string msg = "Boss : "+ name + " |ID: "+ id+ " |Working Days: "+ std::to_string(workingDays)+ " |Base Salary: "+ std::to_string(baseSalary)+ "| Pay: "+  std::to_string(calculateSalary(0.15));
    return msg;
}

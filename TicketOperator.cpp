#include "TicketOperator.h"

TicketOperator::TicketOperator(std::string name, std::string id, int workingDays, float baseSalary, int ticketsProcessed, float commissionPerTicket)
:Employee(name, id, workingDays, baseSalary){
    this-> ticketsProcessed = ticketsProcessed;
    this-> commissionPerTicket = commissionPerTicket;
}

float TicketOperator::calculateSalary(int tax){
    float pay = (workingDays*baseSalary) + (ticketsProcessed*commissionPerTicket);
    float taxes = pay * (tax/100);
    return pay-taxes;
}

std::string TicketOperator::displayInfo(){
    std::string msg = "Ticket Operator: " + name + " |ID: " + id + " |Working Days: " + std::to_string(workingDays) + " |Base Salary: " + std::to_string(baseSalary) + "| Pay: " + std::to_string(calculateSalary(20));
    return msg;
}

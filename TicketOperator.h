#pragma once
#include "Employee.h"

class TicketOperator : public Employee{
    private:
    int ticketsProcessed;
    float commissionPerTicket;

    public:
    TicketOperator(std::string name, std::string id, int workingDays, float baseSalary);
    void setTicketDetails(int tickets, float commission);
    float calculatePay() override;
    std::string showInfo() override;
};

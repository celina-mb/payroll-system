#pragma once

#include <string>
#include "Employ.h"

class TicketOperator : public Employee{
    private:
    int ticketsProcessed;
    float commissionPerTicket;

    public:
    TicketOperator(std::string name, std::string id, int workingDays, float baseSalary);
    void setTicketDetails(int, float);
    double calculatePay() override;
    void showInfo() override;
};

#include "Employee.h"
#include "Boss.h"
#include "TicketOperator.h"
#include "Company.h"
#include "Department.h"
#include <iostream>
using namespace std;

int main(){

    Company* comp = nullptr;
    vector <Department*> departments;

    int choice = 0;
    while (choice!=14){
        cout << "\n===== Payroll Management System =====\n";
        cout << "1. View Department Details\n";
        cout << "2. View Company Details\n";
        cout << "3. Add Boss to Department\n";
        cout << "4. Remove Boss from Department\n";
        cout << "5. Add Ticket Operator to Department\n";
        cout << "6. Remove Ticket Operator from Department\n";
        cout << "7. Create Department\n";
        cout << "8. Remove Department\n";
        cout << "9. View Department Info\n";
        cout << "10. Create Company\n";
        cout << "11. View Company Info \n";
        cout << "12. View Company Payroll \n";
        cout << "13. Compare Departments\n";
        cout << "14. Exit the program \n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice==1){ //department details
            for (auto* d: departments){ //goes over each Department pointer in the vector
                cout<<d-> displayInfo()<<"\n";
            }
        }

        else if (choice==2){ //company details
            if (comp){ //checks for a Company
                cout<< comp-> displayInfo();
            }

            else{ //in case Company is a null pointer
                cout<<"There exists no company yet.\n";
            }
        }

        else if (choice==3){ //add Boss to Department
            if (departments.empty()){
                cout<<"Create a department first! \n";
                continue;
            }

            string name, id;
            int days;
            float base, bonus;

            cin.ignore();
            cout<< "Enter Boss name: ";
            getline(cin, name);
            cout<< "Enter Boss ID: ";
            getline(cin, id);
            cout<< "Working days (numerically): ";
            cin >> days;
            cout << "Base salary: ";
            cin >> base;
            cout<<"Bonus: ";
            cin >> bonus;

            Boss* boss = new Boss (name, id, days, base, bonus);

            cin.ignore();
            string dID;
            cout << "Assign to (Department ID): ";
            getline(cin, dID);

            bool found = false; //control in case 
            for (auto* d : departments) {
                if (d->getDepartmentID() == dID) {
                    d->addEmployee(boss);
                    cout << "Boss added to department.\n";
                    found = true;
                    break;
                }
            }
            if (!found){
                cout <<"Department not found \n";
            }
        }

        else if (choice==4){
            string dID, bID; //department id and boss id, respectively
            cin.ignore();
            cout<<"Enter department ID: ";
            getline(cin,dID);
            cout<<"Enter Boss ID to remove:";
            getline(cin,bID);
            for (auto*d: departments){
                if (d-> getDepartmentID() == dID){
                    d->removeEmployee(bID);
                    cout<< "Boss removed \n";
                }
                else{
                    cout<<"Boss not found \n";
                }
            }

        }
        
        else if (choice==5){
            if (departments.empty()){
                cout<<"Create a department first!!\n";
                continue;
            }

            string name, id;
            int days, tickets;
            float base, commission;

            cin.ignore();
            cout << "Enter Ticket Operator name: ";
            getline(cin, name);
            cout << "Enter ID:";
            getline(cin, id);
            cout << "Working Days: ";
            cin >> days;
            cout << "Base Salary: ";
            cin >> base;
            cout << "Tickets processed: ";
            cin >> tickets;
            cout << "Commission per ticket: ";
            cin >> commission;

            TicketOperator* tO = new TicketOperator(name, id, days, base, tickets, commission);

            cin.ignore();
            cout << "Assign to (Department ID):  ";
            string dID;
            getline(cin, dID);

            bool found = false;
            for (auto* d : departments) {
                if (d->getDepartmentID() == dID) {
                    d->addEmployee(tO);
                    cout << "Ticket Operator added to department.\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Department not found :( \n";
            }
        }

        else if (choice==6){ //remove employee
            string dID, tOID; //department id, ticket operator id respectively
            cin.ignore();
            cout<<"Enter department ID: ";
            getline(cin,dID);
            cout<<"Enter Ticket Operator ID to remove:";
            getline(cin,tOID);
            for (auto*d: departments){
                if (d-> getDepartmentID() == dID){
                    d->removeEmployee(tOID);
                    cout<< "Ticket Operator removed \n";
                }
                else{
                    cout<<"Ticket Operator not found \n";
                }
            }
        }

        else if (choice==7){
            string name, id;
            cin.ignore(1000, '\n');
            cout << "Enter Department Name: ";
            getline(cin, name);
            cout << "Enter Department ID: ";
            getline(cin, id);
            Department* d = new Department(name, id);
            departments.push_back(d);
            if (comp) comp->addDepartment(d);
            cout << "Department created.\n";
        }

        else if (choice==8){
            string id;
            cin.ignore(1000, '\n');
            cout<<"Enter Department ID to remove: ";
            getline(cin,id);
            for (auto i = departments.begin(); i!=departments.end(); i++) {
                if ((*i)-> getDepartmentID() == id){
                    if (comp) comp->removeDepartment(id);
                        delete *i;
                        departments.erase(i);
                        cout << "Department removed.\n";
                }
        
            }
        }

        else if (choice==9){
            string id;
            cin.ignore(1000, '\n');
            cout << "Enter Department ID: ";
            getline(cin, id);
            for (auto*d : departments){
                if (d-> getDepartmentID()==id){
                    cout<< d->displayInfo();
                }
            }
        }

        else if (choice == 10){
            if (comp){
                cout << "Company already exists :( \n";
            }
            string compName;
            cin.ignore();
            cout<<"Enter Company name: ";
            getline(cin, compName);
            comp = new Company(compName);
            cout << "Company created. \n";

        }

        else if (choice == 11){
            if (comp) {
                cout << comp-> displayInfo() << "\n";
            }
            else{
                cout<<" No company created. Create a company first!!! \n";
            }
        }

        else if (choice==12){
            if (comp) {
                cout << "-----Company Payroll-----\n";
                cout<<comp-> getName()<<"\n";
                cout<< "----------------\n";

                float total = 0;

                for (int i = 0; i < departments.size(); i++) {
                    Department* d = departments[i];
            
                    cout << "Department: " << d->getDepartmentName() << "\n";
                    cout << "ID: " << d->getDepartmentID() << "\n";
                    cout << "----------------\n";

                    float dTotal = 0;
                    vector<Employee*> employees = d->getEmployees();
            
                    if (employees.empty()) {
                        cout << "Start by adding a Boss or a Ticket Operator!!\n";
                    } else {
                        for (int j = 0; j < employees.size(); j++) {
                            Employee* employee = employees[j];
                            float salary = employee->calculateSalary();
                            dTotal += salary;

                            cout << employee->getName() << "\n";
                            cout << "ID: " << employee->getID() << "\n";

                            //to avoid errors, bosses' IDs start with capital B
                            if (employee->getID()[0] == 'B') { 
                                cout << "Position: Boss\n";
                            } else {
                                cout << "Position: Ticket Operator\n";
                            }

                            cout << "Salary: $" << salary << "\n";
                            cout << "----------------\n";
                        }
                    }

                    cout << "Department Total: $" << dTotal << "\n";
                    total += dTotal;
                    cout << "----------------\n";
                }

                cout << "Company total: $" << total << "\n";
                cout << "----------------\n";
            }
            else{
                cout<<" No company created. Create a company first!!! \n";
            }
        }

        else if (choice==13){
            if (departments.size()<2){
                cout << "Two departments needed for comparison.\n";
            }
        
            string id1, id2;
            cin.ignore(1000, '\n');
            cout<< "Enter first Department's ID: ";
            getline (cin, id1);
            cout<< "Enter second Department's ID: ";
            getline (cin, id2);
            Department *d1 = nullptr, *d2 = nullptr;
            for (auto*d : departments){
                if (d->getDepartmentID()== id1){
                    d1 = d;
                }
                if (d->getDepartmentID() == id2){
                    d2 =d;
                }
            }
            if (d1 && d2){ //this checks for a null pointer
                if (d1->calculateDepartmentPay() == d2->calculateDepartmentPay()){
                    cout << "Both department's have the same payroll. \n";
                } else {
                    cout << "Departments have different payrolls. \n";
                }
                
            } else {
                cout << "Comparison couldn't be processed (Invalid Department IDs). \n";
            }
        }
        else if (choice==14){
            cout <<"Exiting the program, bye bye.\n";
        }

        else{
            cout<<"Invalid choice. Retry. \n";
        }
    }

    return 0;
}

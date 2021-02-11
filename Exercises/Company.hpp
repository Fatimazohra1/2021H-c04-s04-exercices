///
/// Une compagnie avec des employés et des départements.
///

#pragma once


#include <cstddef>
#include <cstdint>

#include <string>
#include <vector>
#include <memory>

#include "Employee.hpp"
#include "Department.hpp"

using namespace std;


const int numEmployeesMax = 256;

class Company {
public:
	Company();
	Company(const string& name, const string& presidentName, double presidentSalary = 0.0);
	~Company();

	const string& getName() const;
	const Employee& getPresident() const;
	Employee& getPresident();
	int getNumEmployees() const;

	Employee* getEmployee(const string& name);
	Department* getDepartment(const string& name);
	void addEmployee(const string& name, double salary);
	void addEmployee(unique_ptr<Employee> employee);
	void addDepartment(const string& name);
	void addEmployeeToDepartment(const string& employee, const string& department);
	void print() const;

private:
	string name_ = "Unnamed";
	Employee president_;
	vector<unique_ptr<Employee>> employees_;
	vector<unique_ptr<Department>> departments_;
};
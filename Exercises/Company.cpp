///
/// Une compagnie avec des employés.
///


#include <cstddef>
#include <cstdint>

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <utility>

#include <cppitertools/range.hpp>

#include "Employee.hpp"

#include "Company.hpp"

using namespace std;
using namespace iter;


// TODO: Les définitions.

Company::Company() {
	cout << "Company()" << "\n";
}

Company::Company(const string& name, const string& presidentName, double presidentSalary)
: name_(name),
  president_(presidentName, presidentSalary) {
	cout << "Company(const string&, const string&, double)" << "\n";
}

Company::~Company() {
	// Pas nécessaire de faire quoique ce soit grâce aux unique_ptr.
	cout << "~Company() : " << name_ << "\n";
}

const string& Company::getName() const {
	return name_;
}

const Employee& Company::getPresident() const {
	return president_;
}

Employee& Company::getPresident() {
	return president_;
}

int Company::getNumEmployees() const {
	return (int)employees_.size();
}

Employee* Company::getEmployee(const string& name) {
	for (auto&& e : employees_)
		if (e->getName() == name)
			return e.get();
	return nullptr;
}

Department* Company::getDepartment(const string& name) {
	for (auto&& d : departments_)
		if (d->getName() == name)
			return d.get();
	return nullptr;
}

void Company::addEmployee(const string& name, double salary) {
	employees_.push_back(make_unique<Employee>(name, salary));
}

void Company::addEmployee(unique_ptr<Employee> employee) {
	employees_.push_back(move(employee));
}

void Company::addDepartment(const string& name) {
	departments_.push_back(make_unique<Department>(name));
}

void Company::addEmployeeToDepartment(const string& employee, const string& department) {
	Employee* empl = getEmployee(employee);
	Department* dpt = getDepartment(department);
	if (empl == nullptr or dpt == nullptr)
		return;
	dpt->addEmployee(empl);
}

void Company::print() const {
	cout << "Name: " << name_ << "\n"
	     << "President: " << president_.getName() << "\n"
	     << "Employees (" << getNumEmployees() << "):" << "\n";
	for (auto&& e : employees_)
		cout << "  " << e->getName() << " (" << e->getSalary() << ")" << "\n";
}

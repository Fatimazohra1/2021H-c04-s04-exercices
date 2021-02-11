///
/// Département dans une compagnie.
///


#include <cstddef>
#include <cstdint>

#include <string>
#include <vector>

#include "Employee.hpp"
#include "Department.hpp"

using namespace std;


Department::Department(const string& name)
: name_(name) { }

const string& Department::getName() const {
	return name_;
}

int Department::getNumEmployees() const {
	return (int)employees_.size();
}

void Department::addEmployee(Employee* employee) {
	employees_.push_back(employee);
}

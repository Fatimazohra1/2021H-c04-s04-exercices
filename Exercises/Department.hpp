///
/// Département dans une compagnie.
///

#pragma once


#include <cstddef>
#include <cstdint>

#include <string>
#include <vector>

#include "Employee.hpp"

using namespace std;


class Department {
public:
	Department(const string& name);

	const string& getName() const;
	int getNumEmployees() const;

	void addEmployee(Employee* employee);

private:
	string name_;
	vector<Employee*> employees_;
};


///
/// Classe d'employé dans une compagnie.
///

#pragma once


#include <cstddef>
#include <cstdint>

#include <string>

using namespace std;


class Employee {
public:
	Employee();
	Employee(const string& name, double salary = 0.0);
	~Employee();

	double getSalary() const;
	const string& getName() const;
	void setSalary(double salary);

private:
	string name_ = "N/A";
	double salary_ = 42.0;
};


///
/// Ce projet utilise quelques librairies disponibles sur Vcpkg et permet entre autre d'en tester le bon fonctionnement.
///


#include <cstddef>
#include <cstdint>

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <span>
#include <utility>

#include <cppitertools/range.hpp>
#include <cppitertools/enumerate.hpp>
#include <cppitertools/zip.hpp>

#include "Company.hpp"

using namespace std;
using namespace iter;


void runPointersExample() {
	
}

void runCompanyExample() {
	Company stonks("Stonks LLC", "chosson");
	stonks.getPresident().setSalary(69'420);
	stonks.addEmployee("Foo", 69);
	stonks.addEmployee("Bar", 42);
	stonks.addEmployee("Qux", 9000);
	auto spam = make_unique<Employee>("Spam", 1337);
	stonks.addEmployee(move(spam));
	auto eggs = make_unique<Employee>("Eggs", 0xDEAD);
	stonks.addEmployee(move(eggs));
	cout << spam.get() << " " << eggs.get() << "\n";

	stonks.addDepartment("Chunky Services");
	stonks.addEmployeeToDepartment("Foo", "Chunky Services");
	stonks.addEmployeeToDepartment("Bar", "Chunky Services");

	cout << "- - - - - - - - - - -" << "\n";
}


int main() {
	runCompanyExample();
	cout << "\n\n";
}


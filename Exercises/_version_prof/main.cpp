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
#include "Fraction.hpp"
#include "Vector.hpp"

using namespace std;
using namespace iter;


void fn(int* arg) {
	*arg *= 2;
}

void runPointersExample() {
	class Spam {
	public:
		Spam() { cout << "Spam()" << "\n"; }
		Spam(int m) : m_(m) { cout << "Spam(int)" << "\n"; }
		~Spam() { cout << "~Spam() : " << m_ << "\n"; }

		int getM() const { return m_; }

	private:
		int m_ = 0;
	};

	auto foo1 = make_unique<int>(42);
	fn(foo1.get());
	cout << foo1.get() << "\n";

	auto foo = make_unique<Spam>();
	auto bar = make_unique<Spam>(42);
	unique_ptr<Spam> qux;
	cout << "foo: " << foo.get() << ", " << foo->getM() << "\n"
	     << "bar: " << bar.get() << ", " << bar->getM() << "\n"
	     << "qux: " << qux.get() << "\n";
	foo.reset();
	qux = move(bar);
	cout << "foo: " << foo.get() << "\n"
	     << "bar: " << bar.get() << "\n"
	     << "qux: " << qux.get() << ", " << qux->getM() << "\n";
	bar = make_unique<Spam>(0xDEADBEEF);
	cout << "foo: " << foo.get() << "\n"
	     << "bar: " << bar.get() << ", " << bar->getM() << "\n"
	     << "qux: " << qux.get() << ", " << qux->getM() << "\n";

	auto eggs = make_unique<Spam[]>(4);
	cout << "eggs: " << eggs.get() << "\n";
	eggs.reset();
	cout << "eggs: " << eggs.get() << "\n";

	auto ptr = make_shared<int>();
	cout << "Nb : " << ptr.use_count() << endl;
	auto ptr2 = ptr;
	cout << "Nb : " << ptr.use_count() << endl;
	ptr.reset();
	cout << "Nb : " << ptr.use_count() << endl;
	cout << "Nb : " << ptr2.use_count() << endl;

	cout << "- - - - - - - - - - -" << "\n";
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

void runFractionExample() {
	Fraction foo(42, -4);
	Fraction bar = 10;
	Fraction qux = bar;
	qux += -5;
	qux += bar += Fraction(1, 2);

	cout << "foo        = " << foo << "\n"
	     << "bar        = " << bar << "\n"
	     << "qux        = " << qux << "\n"
	     << "-foo       = " << -foo << "\n"
	     << "foo + bar  = " << (foo + bar) << "\n"
	     << "foo + -bar = " << (foo + -bar) << "\n"
	     << "bar        = " << bar << "\n"
	     << "bar++      = " << bar++ << "\n"
	     << "bar        = " << bar << "\n"
	     << "++bar      = " << ++bar << "\n";
}

void runVectorExample() {
	int values[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	Vector foo(span(values, 8));
	Vector bar = foo;
	cout << "foo: " << foo.getData() << ", " << foo << "\n";
	cout << "bar: " << bar.getData() << ", " << bar << "\n";
	foo[0] = 42;
	Vector qux = move(bar);
	cout << "bar: " << bar.getData() << ", " << bar << "\n";
	cout << "qux: " << qux.getData() << ", " << qux << "\n";
}


int main() {
	//runPointersExample();
	//cout << "\n\n\n";
	//runCompanyExample();
	//cout << "\n\n\n";
	//runFractionExample();
	//cout << "\n\n\n";
	runVectorExample();
}


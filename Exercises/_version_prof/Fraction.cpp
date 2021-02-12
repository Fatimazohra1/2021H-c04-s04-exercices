///
/// Exemple de classe de fraction (numérateur/dénominateur) avec opérateurs arithmétiques.
///


#include <cstddef>
#include <cstdint>

#include <algorithm>
#include <utility>
#include <cmath>
#include <numeric>

#include "Fraction.hpp"

using namespace std;


Fraction::Fraction(int numer, int denom)
: numer_(numer),
  denom_(denom) {
	simplify();
}

double Fraction::getReal() const {
	return (double)numer_ / denom_;
}

Fraction& Fraction::increment() {
	numer_ += denom_;
	return *this;
}

Fraction Fraction::operator+() const {
	return *this;
}

Fraction Fraction::operator-() const {
	Fraction result = *this;
	result.numer_ = -result.numer_;
	return result;
}

// Version préfixe (++foo)
Fraction& Fraction::operator++() {
	return increment();
}

// Version postsfixe (foo++)
Fraction Fraction::operator++(int) {
	auto old = *this;
	++(*this);
	return old;
}

Fraction Fraction::operator+(const Fraction& rhs) const {
	return {numer_ * rhs.denom_ + rhs.numer_ * denom_, denom_ * rhs.denom_};
}

Fraction Fraction::operator+(int rhs) const {
	Fraction result = *this; // La copie ne fait pas la simplification (on n'a pas écrit nous-même ce constructeur).
	result.numer_ += rhs * denom_;
	return result;
}

Fraction& Fraction::operator+=(const Fraction& rhs) {
	*this = *this + rhs;
	return *this;
}

Fraction& Fraction::operator+=(int rhs) {
	*this = *this + rhs;
	return *this;
}

void Fraction::simplify() {
	int div = gcd(numer_, denom_);
	numer_ = (int)copysign(numer_ / div, numer_ / denom_);
	denom_ = abs(denom_ / div);
}


Fraction operator+(int lhs, const Fraction& rhs) {
	return rhs + lhs;
}

ostream& operator<<(ostream& lhs, const Fraction& rhs) {
	return lhs << rhs.numer_ << "/" << rhs.denom_;
}

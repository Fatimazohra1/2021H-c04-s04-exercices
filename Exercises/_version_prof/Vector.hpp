///
/// Exemple des slides sur la copie d'objet.
///

#pragma once


#include <cstddef>
#include <cstdint>

#include <memory>
#include <utility>
#include <iostream>
#include <span>

#include <cppitertools/itertools.hpp>

using namespace std;
using namespace iter;


class Vector {
public:
	Vector() = default; // Petit truc pour dire au compilateur de générer pour nous le ctor par défaut.
	Vector(const Vector& other); // Par copie
	Vector(Vector&& other); // Par déplacement (ou par move)
	Vector(span<const int> values);
	~Vector();

	Vector& operator=(const Vector& other);
	Vector& operator=(Vector&& other);

	int* getData();
	const int* getData() const;
	int getSize() const;

	void resize(int size);

	int& operator[](int index);
	const int& operator[](int index) const;

	friend ostream& operator<<(ostream& lhs, const Vector& rhs);

private:
	unique_ptr<int[]> values_;
	int size_ = 0;
};


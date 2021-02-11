///
/// Exemple des slides sur la copie d'objet.
///

#pragma once


#include <cstddef>
#include <cstdint>

#include <memory>
#include <utility>
#include <iostream>

#include <cppitertools/itertools.hpp>

using namespace std;
using namespace iter;


class Vector {
public:
	Vector() = default;

	Vector(const Vector& other) {
		// On laisse l'initialisation par d�faut puis on r�utilise l'op�rateur d'affectation.
		*this = other;
		// On a techniquement une double initialisation, mais on sait que c'est trival dans ce cas et �a simplifie le code vu qu'on a besoin d'�tre dans un �tat valide pour appeler resize().
	}

	Vector(Vector&& other) {
		// On laisse l'initialisation par d�faut puis on r�utilise l'op�rateur d'affectation par d�placement (� move �).
		*this = move(other);
	}

	Vector(span<const int> values) {
		// Pour copier d'un tableau donn�, on utilise notre resize() puis on copie. L'initialisation par d�faut des membres se fait avant.
		resize((int)values.size());
		for (auto&& [i, v] : enumerate(values))
			values_[i] = v;
	}

	~Vector() {
		// Pour d�sallouer, on r�utilise notre resize().
		resize(0);
	}

	Vector& operator=(const Vector& other) {
		// On v�rifie qu'on ne copie pas dans nous-m�me.
		if (&other == this)
			return *this;
		// Pourrait optimiser en ne r�allouant pas si on a l'espace suffisant.
		delete[] values_;
		values_ = new int[other.size_];
		for (int i : range(other.size_))
			values_[i] = other.values_[i];
		size_ = other.size_;
		// On veut permettre l'affectation en cascade.
		return *this;
	}

	Vector& operator=(Vector&& other) {
		delete[] values_;
		// On � vole � les ressources de l'autre objet.
		values_ = other.values_;
		size_ = other.size_;
		// On remet � z�ro l'autre objet (donc dans un �tat valide).
		other.values_ = nullptr;
		other.size_ = 0;
		// On veut permettre l'affectation en cascade.
		return *this;
	}

	int* getData() {
		return values_;
	}

	const int* getData() const {
		return values_;
	}

	int getSize() const {
		return size_;
	}

	void resize(int size) {
		auto old = values_;
		values_ = nullptr;
		// Redimensionner � 0 fait juste d�sallouer le contenu.
		if (size != 0) {
			// On alloue et on copie les anciennes donn�es.
			values_ = new int[size];
			// Si on redimensionne � plus petit, on copie juste les donn�es qui entre (d'o� le min).
			for (int i : range(min(size_, size)))
				values_[i] = old[i];
		}
		size_ = size;
		delete[] old;
	}

	int& operator[](int index) {
		return values_[index];
	}

	const int& operator[](int index) const {
		return values_[index];
	}

private:
	int* values_ = nullptr;
	int size_ = 0;
};


ostream& operator<<(ostream& lhs, const Vector& rhs) {
	lhs << "[";
	for (auto i : range(rhs.getSize())) {
		lhs << rhs[i];
		if (i != rhs.getSize() - 1)
			lhs << " ";
	}
	lhs << "]";
	return lhs;
}

#ifndef MATRIX_ANA_H
#define MATRIX_ANA_H

#include <iosfwd>

class MatrixAnA {
public:
	MatrixAnA();
	MatrixAnA(const int size1, const int size2);
	MatrixAnA(const MatrixAnA& obj);
	~MatrixAnA();
	MatrixAnA& operator=(const MatrixAnA& obj);
	bool operator==(const MatrixAnA& obj) const;
	bool operator!=(const MatrixAnA& obj) const { return !operator==(obj); }
	int& element(const int i, const int j);
	void resize(const int iNew, const int jNew);
private:
	void copy(const MatrixAnA& obj, const int i1, const int i2, const int j1, const int j2);
	int size1_{ 0 };
	int size2_{ 0 };
	int* data_{ nullptr };
	int** pointers_{ nullptr };
};

#endif
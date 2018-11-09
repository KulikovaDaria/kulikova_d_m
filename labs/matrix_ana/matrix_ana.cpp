#include "matrix_ana.h"

#include <iostream>
#include <sstream>

MatrixAnA::MatrixAnA() {
	data_ = new int[0];
	pointers_ = &data_;
}



MatrixAnA::MatrixAnA(int size1, int size2)
	: size1_(size1), size2_(size2) {
	data_ = new int[size1 * size2];
	pointers_ = new int*[size1];
	for (int i = 0; i < size1; ++i) {
		*(pointers_ + i) = (data_ + i * size2);
	}
}



MatrixAnA::MatrixAnA(const MatrixAnA& obj) {
	*this = obj;
}



MatrixAnA::~MatrixAnA() {
	size1_ = 0;
	size2_ = 0;
	delete[] pointers_;
	delete[] data_;
	pointers_ = nullptr;
	data_ = nullptr;
}



MatrixAnA& MatrixAnA::operator=(const MatrixAnA& obj) {
	size1_ = obj.size1_;
	size1_ = obj.size2_;
	data_ = new int[size1_ * size2_];
	pointers_ = new int*[size1_];
	this->copy(obj, 0, size1_, 0, size2_);
	return *this;
}



bool MatrixAnA::operator==(const MatrixAnA& obj) const {
	bool ans = false;
	if ((size1_ == obj.size1_) && (size2_ == obj.size2_)) {
		ans = true;
		for (int i = 0; i < size1_; ++i) {
			for (int j = 0; j < size2_; ++j) {
				if (*(*(pointers_ + i) + j) != *(*(obj.pointers_ + i) + j)) {
					ans = false;
					break;
				}
			}
		}
	}
	return ans;
}



int& MatrixAnA::element(const int i, const int j) {
	return *(*(pointers_ + i) + j);
}



/*void MatrixAnA::resize(const int newSize) {
	MatrixAnA tmp(newSize);

}*/



void MatrixAnA::copy(const MatrixAnA& obj, const int i1, const int i2, const int j1, const int j2) {
	for (int i = i1; i < i2; ++i) {
		for (int j = j1; j < j2; ++j) {
			*(*(pointers_ + i) + j) = *(*(obj.pointers_ + i) + j);
		}
	}
}
#ifndef MATRIX_ANA_H
#define MATRIX_ANA_H
#include <iosfwd>

class MatrixAnA {
public:
  MatrixAnA();
  MatrixAnA(const ptrdiff_t i_size, const ptrdiff_t j_size);
  MatrixAnA(const MatrixAnA& obj);
  ~MatrixAnA();
  MatrixAnA& operator=(const MatrixAnA& obj);
  bool operator==(const MatrixAnA& obj) const;
  bool operator!=(const MatrixAnA& obj) const;
  int& GetEl(const ptrdiff_t i, const ptrdiff_t j);
  void Resize(const ptrdiff_t i_new, const ptrdiff_t j_new);
  void Reserve(const ptrdiff_t i_new, const ptrdiff_t j_new);
  ptrdiff_t RowSize() const;
  ptrdiff_t  ColumnSize() const;

private:
  ptrdiff_t i_size_ {0};
  ptrdiff_t j_size_ {0};
  ptrdiff_t i_capacity_ {0};
  ptrdiff_t j_capacity_ {0};
  int* data_ {nullptr};
};

void Copy(const int* const first, const ptrdiff_t i_size,
    const ptrdiff_t j_size, int* const data, const ptrdiff_t j_cap);

#endif

#ifndef MATRIX_ANA_H
#define MATRIX_ANA_H
#include <iosfwd>

class MatrixAnA {
public:
  MatrixAnA() = default;
  MatrixAnA(const ptrdiff_t i_size, const ptrdiff_t j_size);
  MatrixAnA(const MatrixAnA& obj);
  ~MatrixAnA() noexcept;
  MatrixAnA& operator=(const MatrixAnA& obj);
  bool operator==(const MatrixAnA& obj) const;
  bool operator!=(const MatrixAnA& obj) const;
  int& Element(const ptrdiff_t i, const ptrdiff_t j);
  void Resize(const ptrdiff_t i_new, const ptrdiff_t j_new);
  void Reserve(const ptrdiff_t i_new, const ptrdiff_t j_new);
  ptrdiff_t RowSize() const noexcept;
  ptrdiff_t  ColumnSize() const noexcept;
  std::ostream& WriteTo(std::ostream& ostrm) const;

private:
  static void Copy(const MatrixAnA& from, int* const data,
      const ptrdiff_t j_cap);
  ptrdiff_t i_size_ {0};
  ptrdiff_t j_size_ {0};
  ptrdiff_t i_capacity_ {0};
  ptrdiff_t j_capacity_ {0};
  int* data_ {nullptr};
};

inline std::ostream& operator<<(std::ostream& ostrm, const MatrixAnA& obj) {
  return obj.WriteTo(ostrm);
}

#endif

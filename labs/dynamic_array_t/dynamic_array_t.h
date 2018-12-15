#ifndef DYNAMIC_ARRAY_T_H
#define DYNAMIC_ARRAY_T_H
#include <iosfwd>
#include <string>

template<typename T>
class DynamicArrayT {
public:
  DynamicArrayT() = default;
  explicit DynamicArrayT(const ptrdiff_t size);
  DynamicArrayT(const DynamicArrayT& obj);
  ~DynamicArrayT() noexcept;
  DynamicArrayT& operator=(const DynamicArrayT& obj);
  bool operator==(const DynamicArrayT& obj) const;
  bool operator!=(const DynamicArrayT& obj) const;
  T& operator[](const ptrdiff_t i) const;
  ptrdiff_t Size() const noexcept;
  void Resize(const ptrdiff_t new_size);
  void Reserve(const ptrdiff_t new_capacity);
  void PushBack(const T a);
  void PopBack() noexcept;
  std::ostream& WriteTo(std::ostream& ostrm) const;

private:
  static void Copy(const T* const first, const ptrdiff_t size, T* const data);
  ptrdiff_t size_ {0};
  ptrdiff_t capacity_ {0};
  T* data_ {nullptr};
};

template<typename T>
inline std::ostream& operator<<(std::ostream& ostrm,
    const DynamicArrayT<T>& obj) {
  return obj.WriteTo(ostrm);
}



template<typename T>
DynamicArrayT<T>::DynamicArrayT(const ptrdiff_t size)
  : size_(size), capacity_(size) {
  if (size < 0) {
    throw std::length_error("Size can't be < 0");
  }
  data_ = new T[size];
  for (ptrdiff_t i = 0; i < size; ++i) {
    *(data_ + i) = 0;
  }
}



DynamicArrayT<std::string>::DynamicArrayT(const ptrdiff_t size)
  : size_(size), capacity_(size) {
  if (size < 0) {
    throw std::length_error("Size can't be < 0");
  }
  data_ = new std::string[size];
  for (ptrdiff_t i = 0; i < size; ++i) {
    *(data_ + i) = "";
  }
}



DynamicArrayT<char>::DynamicArrayT(const ptrdiff_t size)
  : size_(size), capacity_(size) {
  if (size < 0) {
    throw std::length_error("Size can't be < 0");
  }
  data_ = new char[size];
  for (ptrdiff_t i = 0; i < size; ++i) {
    *(data_ + i) = ' ';
  }
}



template<typename T>
DynamicArrayT<T>::DynamicArrayT(const DynamicArrayT<T>& obj)
  : size_(obj.size_), capacity_(obj.size_), data_(new T[obj.size_]) {
  Copy(obj.data_, obj.size_, data_);
}



template<typename T>
DynamicArrayT<T>::~DynamicArrayT() noexcept {
  delete[] data_;
  data_ = nullptr;
}



template<typename T>
DynamicArrayT<T>& DynamicArrayT<T>::operator=(const DynamicArrayT<T>& obj) {
  if (this != &obj) {
    if (capacity_ < obj.size_) {
      Resize(obj.size_);
    }
    Copy(obj.data_, obj.size_, data_);
    size_ = obj.size_;
  }
  return *this;
}



template<typename T>
bool DynamicArrayT<T>::operator==(const DynamicArrayT<T>& obj) const {
  if (this == &obj) {
    return true;
  }
  bool check = false;
  if (size_ == obj.size_) {
    for (ptrdiff_t i = 0; (i < size_) && (*(data_ + i) == *(obj.data_ + i) ?
      check = true : check = false); ++i) {
    }
  }
  return check;
}



bool DynamicArrayT<double>::operator==(const DynamicArrayT<double>& obj)
    const {
  if (this == &obj) {
    return true;
  }
  bool check = false;
  const double eps(0.0001);
  if (size_ == obj.size_) {
    for (ptrdiff_t i = 0; (i < size_) && ((std::abs(*(data_ + i)
        - *(obj.data_ + i)) < eps) ? check = true : check = false); ++i) {
    }
  }
  return check;
}



template<typename T>
bool DynamicArrayT<T>::operator!=(const DynamicArrayT<T>& obj) const {
  return !operator==(obj);
}



template<typename T>
T& DynamicArrayT<T>::operator[](const ptrdiff_t i) const {
  if ((i < 0) || (i >= size_)) {
    throw std::out_of_range("Invalid index");
  }
  return *(data_ + i);
}



template<typename T>
ptrdiff_t DynamicArrayT<T>::Size() const noexcept {
  return size_;
}



template<typename T>
void DynamicArrayT<T>::Resize(const ptrdiff_t new_size) {
  if (new_size < 0) {
    throw std::length_error("Size can't be < 0");
  }
  if (capacity_ < new_size) {
    Reserve(new_size);
  }
  size_ = new_size;
}



template<typename T>
void DynamicArrayT<T>::Reserve(const ptrdiff_t new_capacity) {
  if (new_capacity < 0) {
    throw std::length_error("Size can't be < 0");
  }
  if (capacity_ < new_capacity) {
    T* new_data(new T[new_capacity]);
    Copy(data_, size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
  }
}



template<typename T>
void DynamicArrayT<T>::PushBack(const T a) {
  if (capacity_ < size_ + 1) {
    Reserve(size_ + 1);
  }
  *(data_ + size_) = a;
  ++size_;
}



template<typename T>
void DynamicArrayT<T>::PopBack() noexcept {
  --size_;
}



template<typename T>
void DynamicArrayT<T>::Copy(const T* const first, const ptrdiff_t size,
    T* const data) {
  for (ptrdiff_t i = 0; i < size; ++i) {
    *(data + i) = *(first + i);
  }
}



template<typename T>
std::ostream& DynamicArrayT<T>::WriteTo(std::ostream& ostrm) const {
  ostrm << '{';
  for (ptrdiff_t i = 0; i < size_; ++i) {
    ostrm << *(data_ + i);
    if (i < size_ - 1) {
      ostrm << ", ";
    }
  }
  ostrm << '}';
  return ostrm;
}

#endif

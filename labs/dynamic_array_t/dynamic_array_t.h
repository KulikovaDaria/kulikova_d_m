#ifndef DYNAMIC_ARRAY_T_H
#define DYNAMIC_ARRAY_T_H
#include <iosfwd>

template<typename T>
class DynamicArrayT {
public:
	DynamicArrayT();
	DynamicArrayT(const ptrdiff_t size);
	DynamicArrayT(const DynamicArrayT& obj);
	~DynamicArrayT() noexcept;
	DynamicArrayT& operator=(const DynamicArrayT& obj);
	bool operator==(const DynamicArrayT& obj) const noexcept;
	bool operator!=(const DynamicArrayT& obj) const noexcept  { return !operator==(obj);  };
	T& operator[](const ptrdiff_t i) const;
	ptrdiff_t Size() const noexcept ;
	void Resize(const ptrdiff_t new_size);
  void Reserve(const ptrdiff_t new_capacity);
	void PushBack(const T a);
	void PopBack() noexcept;
  std::ostream& WriteTo(std::ostream& ostrm) const;
private:
	ptrdiff_t size_{0};
  ptrdiff_t capacity_{0};
	T* data_{nullptr};
};

template<typename T>
void Copy(const T* const first, const ptrdiff_t size, T* const data_);

template<typename T>
inline std::ostream& operator<<(std::ostream& ostrm, const DynamicArrayT<T>& obj) {
  return obj.WriteTo(ostrm);
}



template<typename T>
DynamicArrayT<T>::DynamicArrayT()
  :data_(new T[0]) {
}



template<typename T>
DynamicArrayT<T>::DynamicArrayT(const ptrdiff_t size)
  : size_(0), capacity_(size), data_(new T[size]) {
}



template<typename T>
DynamicArrayT<T>::DynamicArrayT(const DynamicArrayT<T>& obj)
  : size_(obj.size_), capacity_(obj.size_), data_(new T[obj.size_]) {
  Copy(obj.data_, obj.size_, data_);
}



template<typename T>
DynamicArrayT<T>::~DynamicArrayT() noexcept {
  size_ = 0;
  capacity_ = 0;
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
bool DynamicArrayT<T>::operator==(const DynamicArrayT<T>& obj) const noexcept {
  if (size_ == obj.size_) {
    for (ptrdiff_t i = 0; i < size_; ++i) {
      if (*(data_ + i) != *(obj.data_ + i)) {
        return false;
      }
    }
    return true;
  }
  return false;
}



bool DynamicArrayT<double>::operator==(const DynamicArrayT<double>& obj) const noexcept {
  const double eps(0.0001);
  if (size_ == obj.size_) {
    for (ptrdiff_t i = 0; i < size_; ++i) {
      if (*(data_ + i) - *(obj.data_ + i) > eps) {
        return false;
      }
    }
    return true;
  }
  return false;
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
  if (capacity_ < new_size) {
    Reserve(new_size);
  }
  size_ = new_size;
}



template<typename T>
void DynamicArrayT<T>::Reserve(const ptrdiff_t new_capacity) {
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
void Copy(const T* const first, const ptrdiff_t size, T* const data_) {
  for (ptrdiff_t i = 0; i < size; ++i) {
    *(data_ + i) = *(first + i);
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

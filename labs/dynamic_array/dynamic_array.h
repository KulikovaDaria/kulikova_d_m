#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <iosfwd>

class DynamicArray {
public:
	DynamicArray();
	DynamicArray(const ptrdiff_t size);
	DynamicArray(const DynamicArray& obj);
	~DynamicArray() noexcept;
	DynamicArray& operator=(const DynamicArray& obj);
	bool operator==(const DynamicArray& obj) const noexcept;
	bool operator!=(const DynamicArray& obj) const noexcept  { return !operator==(obj);  };
	int& operator[](const ptrdiff_t i) const;
	ptrdiff_t Size() const noexcept ;
	void Resize(const ptrdiff_t new_size);
  void Reserve(const ptrdiff_t new_capacity);
	void PushBack(const int a);
	void PopBack() noexcept;
  std::ostream& WriteTo(std::ostream& ostrm) const;
private:
	ptrdiff_t size_{0};
  ptrdiff_t capacity_{0};
	int* data_{nullptr};
};

void Copy(const int* const first, const ptrdiff_t size, int* const data_);

inline std::ostream& operator<<(std::ostream& ostrm, const DynamicArray& obj) {
  return obj.WriteTo(ostrm);
}

#endif

#include "stack_on_list.h"

#include <iostream>
#include <stdexcept>

StackOnList::StackOnList(const StackOnList& obj) {
  this->data_ = obj.data_;
}



StackOnList& StackOnList::operator=(const StackOnList& obj) {
  if (this != &obj) {
    Swap(StackOnList(obj));
  }
  return *this;
}



StackOnList::~StackOnList() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}



void StackOnList::Push(const int value) {
  data_ = new Node(value, data_);
}



void StackOnList::Pop() noexcept {
  if (nullptr != data_) {
    data_ = data_->next;
  }
}



int StackOnList::Top() const {
  if (nullptr == data_) {
    throw std::logic_error("Try to get top from empty stack.");
  }
  return data_->data;
}



bool StackOnList::IsEmpty() const noexcept {
  return nullptr == data_;
}



void StackOnList::Swap(StackOnList& rhs) noexcept {
  std::swap(this->data_, rhs.data_);
}



std::ostream& StackOnList::WriteTo(std::ostream& ostrm) const {
  Node* printed_node(data_);
  ostrm << '{';
  while (printed_node)
  {
    ostrm << printed_node->data;
    printed_node = printed_node->next;
    if (printed_node) {
      ostrm << ", ";
    }
  }
  ostrm << '}';
  return ostrm;
}
#include "stack_on_list.h"
#include <iostream>
#include <exception>

StackOnList::StackOnList(const StackOnList& obj) {
  Node* p_obj = obj.data_;
  data_ = new Node;
  Node* p_this = data_;
  while (p_obj != nullptr) {
    p_this->data = p_obj->data;
    p_obj = p_obj->next;
    if (p_obj != nullptr) {
      p_this->next = new Node;
      p_this = p_this->next;
    }
  }
}



StackOnList& StackOnList::operator=(const StackOnList& obj) {
  if (this != &obj) {
    Node* p_obj(obj.data_);
    if (nullptr == data_ && nullptr != obj.data_) {
      data_ = new Node;
    }
    Node* p_this(data_);
    while (p_obj != nullptr) {
      p_this->data = p_obj->data;
      p_obj = p_obj->next;
      if (nullptr == p_this->next && p_obj != nullptr) {
        p_this->next = new Node;
      }
      if (p_obj != nullptr) {
        p_this = p_this->next;
      }
    }
    if (p_this->next != nullptr) {
      Node* node_deleted(p_this->next);
      p_this->next = nullptr;
      delete node_deleted;
    }
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
    Node* node_deleted(data_);
    data_ = data_->next;
    delete node_deleted;
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




std::ostream& StackOnList::WriteTo(std::ostream& ostrm) const {
  Node* printed_node(data_);
  ostrm << '{';
  while (printed_node) {
    ostrm << printed_node->data;
    printed_node = printed_node->next;
    if (printed_node) {
      ostrm << ", ";
    }
  }
  ostrm << '}';
  return ostrm;
}

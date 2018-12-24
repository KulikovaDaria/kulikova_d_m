#include "priority_queue.h"
#include <iostream>
#include <exception>

PriorityQueue::PriorityQueue(const PriorityQueue& obj) {
  Node* p_obj(obj.data_);
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



PriorityQueue& PriorityQueue::operator=(const PriorityQueue& obj) {
  if (this != &obj) {
    Node* p_obj(obj.data_);
    if (nullptr == data_ && nullptr != p_obj) {
      data_ = new Node;
    }
    Node* p_this(data_);
    while (nullptr != p_obj) {
      p_this->data = p_obj->data;
      p_obj = p_obj->next;
      if (nullptr == p_this->next && nullptr != p_obj) {
        p_this->next = new Node;
      }
      if (nullptr != p_obj) {
        p_this = p_this->next;
      }
    }
    if (nullptr != p_this->next) {
      Node* node_deleted(p_this->next);
      p_this->next = nullptr;
      delete node_deleted;
    }
  }
  return *this;
}



PriorityQueue::~PriorityQueue() {
  while (!IsEmpty()) {
    Pop();
  }
}



void PriorityQueue::Push(const int key, const int val) {
  if (nullptr != data_) {
    if (data_->data.key >= key) {
      Node* p(data_);
      while (nullptr != p->next && p->next->data.key >= key) {
        p = p->next;
      }

      p->next = new Node(key, val, p->next);
    } else {
      data_ = new Node(key, val, data_);
    }
  } else {
    data_ = new Node(key, val);
  }
}



void PriorityQueue::Pop() noexcept {
  if (nullptr != data_) {
    Node* node_deleted(data_);
    data_ = data_->next;
    delete node_deleted;
  }
}



int PriorityQueue::Top() const {
  if (nullptr == data_) {
    throw std::logic_error("Try to get top from empty queue.");
  }
  return data_->data.val;
}



bool PriorityQueue::IsEmpty() const noexcept {
  return nullptr == data_;
}



std::ostream& PriorityQueue::WriteTo(std::ostream& ostrm) const {
  ostrm << '{';
  Node* printed_node(data_);
  while (nullptr != printed_node) {
    ostrm << printed_node->data.val;
    printed_node = printed_node->next;
    if (nullptr != printed_node) {
      ostrm << ", ";
    }
  }
  ostrm << '}';
  return ostrm;
}

// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 public:
 TStack(): top(-1) {}
 T get() {
 return a[top];
 }
 bool Empty() {
 return (top == -1);
 }
 bool Full() {
 return (top == size - 1);
 }
 void pop() {
 if (!Empty())
 top--;
 }
 void push(T x) {
 if (!Full()) {
 top++;
 a[top] = x;
 }
 }

 private:
  T a[size] = {0};
  int top = 0;     
};
#endif  // INCLUDE_TSTACK_H_

#include "TStack.h"

template <class T>
TStack<T>::TStack(int _size = MAX_MEM_SIZE) {
  if (_size <= 0) { size = MAX_MEM_SIZE; } else { size = _size; }
  dataCount = 0;
  top = -1;
  pMem = new T[size];
}

template <class T>
TStack<T>::~TStack() {
  size = 0;
  dataCount = 0;
  top = 0;
  if (pMem != nullptr) { delete[] pMem; }
  pMem = nullptr;
}

template <class T>
int TStack<T>::IsEmpty() const { return (dataCount == 0); }

template <class T>
int TStack<T>::IsFull() const { return (dataCount == size); }

template <class T>
void TStack<T>::Push(const T& val) {
  if (IsFull()) { throw "Cannot insert more elements in stack"; }
  pMem[++top] = val;
  dataCount++;
}

template <class T>
T TStack<T>::Pop(void) {
  if (IsEmpty()) { throw "No elements left in stack"; }
  dataCount--;
  return pMem[top--];
}
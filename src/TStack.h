#pragma once

#ifndef __TStack_H__
#define __TStack_H__

const int MAX_MEM_SIZE = 25; // Максимальный размер памяти для стека

template <class T>
class TStack {
protected:
  T* pMem; // Указатель на массив элементов
  int size; // Размер памяти для СД
  int dataCount; // Количество элементов в СД
  int top; // Индекс вершины стека
public:
  TStack(int _size = MAX_MEM_SIZE); // Конструктор
  ~TStack(); // Деструктор

  int IsEmpty() const; // Проверка пустоты
  int IsFull() const; // Проверка переполнения

  void Push(const T& val);// Добавить значение
  virtual T Pop(); // Извлечь значение
};

#endif
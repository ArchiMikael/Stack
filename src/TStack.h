#pragma once

#ifndef __TStack_H__
#define __TStack_H__

const int MAX_MEM_SIZE = 25; // ������������ ������ ������ ��� �����

template <class T>
class TStack {
protected:
  T* pMem; // ��������� �� ������ ���������
  int size; // ������ ������ ��� ��
  int dataCount; // ���������� ��������� � ��
  int top; // ������ ������� �����
public:
  TStack(int _size = MAX_MEM_SIZE); // �����������
  ~TStack(); // ����������

  int IsEmpty() const; // �������� �������
  int IsFull() const; // �������� ������������

  void Push(const T& val);// �������� ��������
  virtual T Pop(); // ������� ��������
};

#endif
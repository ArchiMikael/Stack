#pragma once

#ifndef __TFormula_H__
#define __TFormula_H__

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class TFormula {
private:
  string infix; // ������� ������
  string postfix; // ����������� ������
  vector<char> lexems; // �������
  map<char, int> priority; // ���������� ��������
  map<char, double> operands; // �������� ���������

  void Parse(); // ������ ������
  void ToPostfix(); // ������� � ����������� �����
public:
  TFormula(string _infix); // �����������

  string GetInfix() const { return infix; } // ������� ��������� �����
  string GetPostfix() const; // ������� ����������� �����
  vector<char> GetOperands() const; // ������� ���������

  double Calculate(const map<char, double>& _operands); // ���������� ����������
};

#endif
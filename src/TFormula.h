#pragma once

#ifndef __TFormula_H__
#define __TFormula_H__

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class TFormula {
private:
  string infix; // Входная строка
  string postfix; // Постфиксная запись
  vector<char> lexems; // Лексемы
  map<char, int> priority; // Приоритеты операций
  map<char, double> operands; // Значения операндов

  void Parse(); // Разбор строки
  void ToPostfix(); // Перевод в постфиксную форму
public:
  TFormula(string _infix); // Конструктор

  string GetInfix() const { return infix; } // Возврат инфиксной формы
  string GetPostfix() const; // Возврат постфиксной формы
  vector<char> GetOperands() const; // Возврат операндов

  double Calculate(const map<char, double>& _operands); // Вычисление результата
};

#endif
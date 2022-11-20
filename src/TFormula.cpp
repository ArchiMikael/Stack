#include "TFormula.h"
#include "TStack.h"
#include "TStack.cpp"

void TFormula::Parse()
{
  size_t i = 0;
  while (i < infix.length())
  {
    switch (infix[i])
    {
    case '@': case '#': case '&': case '$': case '!': case '%': case '|': case '~': case '?': case '>': case '<': case ':': case ';':
      throw "Unknown symbol in expression";
      break;
    case 'c':
      if (i < infix.length() - 3)
      {
        if (infix[i + 1] == 'o' && infix[i + 2] == 's')
        {
          lexems.push_back('@');
          i += 2;
        }
        else { lexems.push_back(infix[i]); }
      }
      else { lexems.push_back(infix[i]); }
      break;
    case 's':
      if (i < infix.length() - 3)
      {
        if (infix[i + 1] == 'i' && infix[i + 2] == 'n')
        {
          lexems.push_back('#');
          i += 2;
        }
        else { lexems.push_back(infix[i]); }
      }
      else { lexems.push_back(infix[i]); }
      break;
    default:
      lexems.push_back(infix[i]);
    }
    i++;
  }
}

void TFormula::ToPostfix()
{
  Parse();
  TStack<char> st;
  char stackItem;
  for (char item : lexems)
  {
    switch (item)
    {
    case '(':
      st.Push(item);
      break;
    case ')':
      stackItem = st.Pop();
      while (stackItem != '(')
      {
        postfix += stackItem;
        stackItem = st.Pop();
      }
      break;
    case '+': case '-': case '*': case '/': case '^': case '@': case '#':
      while (!st.IsEmpty())
      {
        stackItem = st.Pop();
        if (priority[item] <= priority[stackItem]) { postfix += stackItem; }
        else {
          st.Push(stackItem);
          break;
        }
      }
      st.Push(item);
      break;
    default:
      operands.insert({ item, 0.0 });
      postfix += item;
    }
  }
  while (!st.IsEmpty())
  {
    stackItem = st.Pop();
    postfix += stackItem;
  }
}

TFormula::TFormula(string _infix) : infix(_infix)
{
  priority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}, {'@', 3}, {'#', 3} };
  ToPostfix();
}

string TFormula::GetPostfix() const
{
  string Result;
  for (char c : postfix)
  {
    switch (c)
    {
    case '@':
      Result += 'c';
      Result += 'o';
      Result += 's';
      break;
    case '#':
      Result += 's';
      Result += 'i';
      Result += 'n';
      break;
    default:
      Result += c;
    }
  }
  return Result;
}

vector<char> TFormula::GetOperands() const
{
  vector<char> op;
  for (const auto& item : operands) { op.push_back(item.first); }
  return op;
}

double TFormula::Calculate(const map<char, double>& _operands)
{
  for (auto& val : _operands)
  {
    try
    {
      operands.at(val.first) = val.second;
    }
    catch (out_of_range &e) { }
  }
  TStack<double> st;
  double l_operand, r_operand;
  for (char lexem : postfix)
  {
    switch (lexem)
    {
    case '+':
      r_operand = st.Pop();
      l_operand = st.Pop();
      st.Push(l_operand + r_operand);
      break;
    case '-':
      r_operand = st.Pop();
      l_operand = st.Pop();
      st.Push(l_operand - r_operand);
      break;
    case '*':
      r_operand = st.Pop();
      l_operand = st.Pop();
      st.Push(l_operand * r_operand);
      break;
    case '/':
      r_operand = st.Pop();
      l_operand = st.Pop();
      st.Push(l_operand / r_operand);
      break;
    case '^':
      r_operand = st.Pop();
      l_operand = st.Pop();
      st.Push(pow(l_operand, r_operand));
      break;
    case '@':
      r_operand = st.Pop();
      st.Push(cos(r_operand));
      break;
    case '#':
      r_operand = st.Pop();
      st.Push(sin(r_operand));
      break;
    default:
      st.Push(operands[lexem]);
    }
  }
  return st.Pop();
}
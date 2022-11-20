#include <iostream>
#include "TStack.h"

using namespace std;

void main() {
  TStack<char> st;
  cout << 't' << 'e' << 's' << 't' << endl;
  st.Push('t');
  st.Push('e');
  st.Push('s');
  st.Push('t');
  for (int i = 0; i < 4; i++) { cout << st.Pop(); }
}
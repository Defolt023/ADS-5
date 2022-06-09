// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
std::string infx2pstfx(std::string inf) {
  std::string s = "";
  TStack<char, 100> Stack;
  std::map<char, int> Prior;
  Prior['('] = 0;
  Prior[')'] = 0;
  Prior['+'] = 1;
  Prior['-'] = 1;
  Prior['*'] = 2;
  Prior['/'] = 2;
  for (int i = 0; i < inf.size(); i++) {
  if (Prior.find(inf[i]) == Prior.end()) {
  s += inf[i];
  s += ' ';
  } else {
  if (inf[i] == ')') {
  while (Stack.get() != '(') {
  s += Stack.get();
  s += ' ';
  Stack.pop();
  }
  Stack.pop();
  } else {
  if (inf[i] == '(' || Stack.Empty()) {
  Stack.push(inf[i]);
  } else {
  if (Prior[inf[i]] > Prior[Stack.get()]) {
  Stack.push(inf[i]);
  } else {
  while (Prior[inf[i]] <= Prior[Stack.get()]) {
  if (!Stack.Empty()) {
  s += Stack.get();
  s += ' ';
  Stack.pop();
  }
  }
  Stack.push(inf[i]);
  }
  }
  }
  }
  }
  while (!Stack.Empty()) {
  s += Stack.get();
  s += ' ';
  Stack.pop();
  }
  s.pop_back();
  return s;
}
int eval(std::string pref) {
  TStack<int, 100> Stack;
  int val1, val2, result, i = 0;
  while (i < pref.size()) {
  if (pref[i] >= '0') {
  Stack.push(pref[i] - '0');
  } else {
  if (pref[i] != ' ') {
  val2 = Stack.get();
  Stack.pop();
  val1 = Stack.get();
  Stack.pop();
  switch (pref[i]) {
  case '+':
  result = val1 + val2;
  break;
  case '-':
  result = val1 - val2;
  break;
  case '*':
  result = val1 * val2;
  break;
  case '/':
  result = val1 / val2;
  break;
  }
  Stack.push(result);
  }
  }
  i++;
  }
  return Stack.get();
}

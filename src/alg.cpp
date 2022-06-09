// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
std::string infx2pstfx(std::string inf) {
std::string s = "";
  TStack<char, 100> Stack;
  std::map<char, int> Prior;
  Prior[')'] = 0;
  Prior['('] = 0;
  Prior['-'] = 1;
  Prior['*'] = 2;
  Prior['+'] = 1;
  Prior['/'] = 2;
  for (int j = 0; j < inf.size(); j++) {
  if (Prior.find(inf[j]) == Prior.end()) {
  s += inf[j];
  s += ' ';
  } else {
  if (inf[j] == ')') {
  while (Stack.get() != '(') {
  s += Stack.get();
  s += ' ';
  Stack.pop();
  }
  Stack.pop();
  } else {
  if (inf[j] == '(' || Stack.Empty()) {
  Stack.push(inf[j]);
  } else {
  if (Prior[inf[j]] > Prior[Stack.get()]) {
  Stack.push(inf[j]);
  } else {
  while (Prior[inf[j]] <= Prior[Stack.get()]) {
  if (!Stack.Empty()) {
  s += Stack.get();
  s += ' ';
  Stack.pop();
  }
  }
  Stack.push(inf[j]);
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
  int val1, val2, result, j = 0;
  while (j < pref.size()) {
  if (pref[j] >= '0') {
  Stack.push(pref[j] - '0');
  } else {
  if (pref[j] != ' ') {
  val2 = Stack.get();
  Stack.pop();
  val1 = Stack.get();
  Stack.pop();
  switch (pref[j]) {
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

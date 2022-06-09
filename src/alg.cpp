// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include <iostream>
#include "tstack.h"

int operationss(char pr) {
    switch (pr) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '+':
      return 2;
    case '-':
      return 2;
    case '*':
      return 3;
    case '/':
      return 3;
    default:
        return -1;
    }
}
int calc(char a, int b, int c) {
    switch (a) {
    case '+':
        return b + c;
            break;
    case '-':
        return b - c;
            break;
    case '*':
        return b * c;
            break;
    case '/':
        return b / c;
            break;
    default:
        return 0;
    }
}
std::string infx2pstfx(std::string inf) {
  TStack <char, 100> strin1;
  std::string strin;
  for (size_t i = 0; i < inf.size(); i++) {
    if ((operationss(inf[i]) == -1) && (operationss(inf[i]) != 1)) {
      if (!strin.empty() && operat(inf[i - 1]) != -1) {
        strin.push_back(' ');
      }
      strin.push_back(inf[i]);
    } else if ((operationss(inf[i]) > operationss(strin1.get()))
               || (strin1.isEmpty()) || (operationss(inf[i]) == 0)) {
      strin1.push(inf[i]);
    } else {
      if (operationss(inf[i]) == 1) {
        while (operationss(strin1.get()) != 0) {
          strin.push_back(' ');
          strin.push_back(strin1.get());
          strin1.pop();
        }
        strin1.pop();
      } else {
        while (operationss(strin1.get()) >= operationss(inf[i])) {
          strin.push_back(' ');
          strin.push_back(strin1.get());
          strin1.pop();
        }
        strin1.push(inf[i]);
      }
    }
  }
  while (!strin1.isEmpty()) {
    strin.push_back(' ');
    if (operationss(strin1.get()) != 0) {
      strin.push_back(strin1.get());
    }
    strin1.pop();
  }
  return strin;
}

int eval(std::string postov) {
    TStack<int, 100> strin2;
    int z = 0;
    int x = 0;
    int y = 0;
for (int i = 0; i < postov.length(); i++) {
        if ((operationss(postov[i]) == -1) && postov[i] != ' ') {
            strin2.push(postov[i] - '0');
        } else if (operationss(postov[i]) > 1) {
            y = strin2.get();
            strin2.pop();
            x = strin2.get();
            strin2.pop();
            strin2.push(calc(postov[i], x, y));
        }
    }
    z = strin2.get();
  return z;
}

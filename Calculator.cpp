#include <complex.h>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <stack>

using namespace std;

const int kIn = 0;
const int kOut = 1;
const int kMaxLength = 1e7 + 10;

stack<char> opt;
stack<double> val;
int LargeNumberFactorial[kMaxLength];
char opt_set[10] = "+-*/()=.";

int level(char theOpt);
bool in_set(char theChar);
bool del_space(string &theString);
string to_string(int theInt);
bool change(string &from, string &to);
bool compute(string &theExp);
int Judge_rectangle(string &theStr);
double cal_rect_number(string &theStr, int theInt);
bool Judge_factorial(string &theStr);
int cal_factorial(int theInt);
int cal_factorial_number(string &theStr);

int main() {
  cout << "Welcome to the calculator.\n";
  cout << "You can use this calculator to do some simple calculations.\n";
  cout << "If you want to exit, type :exit...\n";
  while (1) {
    string init_exp;
    cout << "-- Please enter the expression:";
    cin >> init_exp;
    if (init_exp == string("exit")) {
      cout << "Thank you for your use...\n";
      break;
    } else if (Judge_rectangle(init_exp) != 0) {
      double res = 0;
      res = cal_rect_number(init_exp, Judge_rectangle(init_exp));
      if (res) {
        cout << "The result is:" << fixed << setprecision(9) << res << '\n';
      }
    } else if (Judge_factorial(init_exp)) {
      int n = cal_factorial_number(init_exp);
      cout << "The result is:";
      for (int i = cal_factorial(n); i > 0; i--) {
        cout << LargeNumberFactorial[i];
      }
      cout << '\n';
    } else {
      cin.clear();
      cin.sync();
      while (!opt.empty()) {
        opt.pop();
      }
      while (!val.empty()) {
        val.pop();
      }
      del_space(init_exp);
      string cng_exp;
      cng_exp.clear();
      change(init_exp, cng_exp);
      compute(cng_exp);
      double stdans = val.top();
      cout << "The result is:" << (double)stdans << '\n';
    }
  }
  return 0;
}

int level(char theOpt) {
  switch (theOpt) {
  case '(':
    return 0;
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case ')':
    return 3;
  }
}

bool in_set(char theChar) {
  for (int i = 0; i < 8; i++) {
    if (theChar == opt_set[i]) {
      return 1;
    }
  }
  return 0;
}

bool del_space(string &theString) {
  string res;
  for (int i = 0; i < theString.length(); i++) {
    if (in_set(theString[i]) || isdigit(theString[i])) {
      res += theString[i];
    } else if (theString[i] == ' ') {
    } else {
      cout << "The enter is Wrong" << '\n';
      return 0;
    }
  }
  theString = res;
  return 1;
}

string to_string(int theInt) {
  if (theInt == 0) {
    return string("0");
  }
  bool neg = 0;
  if (theInt < 0) {
    neg = 1;
    theInt = -theInt;
  }
  string res;
  while (theInt != 0) {
    char c = (theInt % 10) + '0';
    res = c + res;
    theInt /= 10;
  }
  if (neg) {
    res = '-' + res;
  }
  return res;
}

bool change(string &from, string &to) {
  int theInt = 0;
  int state = kOut;
  char c;

  for (int i = 0; i < from.length(); i++) {
    c = from[i];
    if (isdigit(c)) {
      to = to + c;
      theInt *= 10;
      theInt += c - '0';
      state = kIn;
    } else {
      if (state == kIn && c == '.') {
        to = to + '.';
        theInt = 0;
        continue;
      }
      if (state == kIn && c != '.') {
        to += ' ';
        theInt = 0;
      }
      if (c == '=') {
        break;
      } else if (c == '(') {
        opt.push(c);
      } else if (c == ')') {
        while (!opt.empty() && opt.top() != '(') {
          to += opt.top();
          to += ' ';
          opt.pop();
        }
        opt.pop();
      } else {
        while (1) {
          if (opt.empty() || opt.top() == '(') {
            opt.push(c);
          } else if (level(c) > level(opt.top())) {
            opt.push(c);
          } else {
            to += opt.top();
            to += ' ';
            opt.pop();
            continue;
          }
          break;
        }
      }
      state = kOut;
    }
  }
  while (!opt.empty()) {
    to += opt.top();
    to += ' ';
    opt.pop();
  }
  return 1;
}

bool compute(string &theExp) {
  int theInt = 0;
  int state = kOut;
  char c;
  bool dot = 0;
  double count = 1.0;
  for (int i = 0; i < theExp.length(); i++) {
    c = theExp[i];
    if (isdigit(c) || c == '.') {
      if (isdigit(c)) {
        theInt *= 10;
        theInt += c - '0';
        state = kIn;
        if (dot == 1) {
          count *= 10.0;
        }
      }
      if (c == '.') {
        dot = 1;
        continue;
      }
    } else {
      dot = 0;
      double ans = theInt / count;
      count = 1.0;
      if (state == kIn) {
        val.push(ans);
        theInt = 0;
      }
      double x, y;
      if (c != ' ') {
        x = val.top();
        val.pop();
        y = val.top();
        val.pop();

        switch (c) {
        case '+':
          val.push(x + y);
          break;
        case '-':
          val.push(y - x);
          break;
        case '*':
          val.push(x * y);
          break;
        case '/':
          val.push(y / x);
          break;
        default:
          cout << "Unknown Error!" << '\n';
        }
      }
      state = kOut;
    }
  }
  return 1;
}

int Judge_rectangle(string &theStr) {
  string str1 = "sin";
  string str2 = "cos";
  string str3 = "tan";
  string str4 = "arcsin";
  string str5 = "arccos";
  string str6 = "arctan";
  const char *show1, *show2, *show3, *show4, *show5, *show6;
  show4 = strstr(theStr.c_str(), str4.c_str());
  if (show4 != NULL) {
    return 4;
  }
  show5 = strstr(theStr.c_str(), str5.c_str());
  if (show5 != NULL) {
    return 5;
  }
  show6 = strstr(theStr.c_str(), str6.c_str());
  if (show6 != NULL) {
    return 6;
  }
  show1 = strstr(theStr.c_str(), str1.c_str());
  if (show1 != NULL) {
    return 1;
  }
  show2 = strstr(theStr.c_str(), str2.c_str());
  if (show2 != NULL) {
    return 2;
  }
  show3 = strstr(theStr.c_str(), str3.c_str());
  if (show3 != NULL) {
    return 3;
  }
  return 0;
}

double cal_rect_number(string &theStr, int theInt) {
  int number = 0;
  for (int i = 0; theStr[i] != ')'; i++) {
    if (isdigit(theStr[i])) {
      number *= 10;
      number += theStr[i] - '0';
    }
  }
  double ans = 0.0;
  switch (theInt) {
  case 1:
    ans = sin(number);
    break;
  case 2:
    ans = cos(number);
    break;
  case 3:
    ans = tan(number);
    break;
  case 4:
    ans = asin(number);
    break;
  case 5:
    ans = acos(number);
    break;
  case 6:
    ans = atan(number);
    break;
  default:
    return 0;
    break;
  }
  return ans;
}
bool Judge_factorial(string &theStr) {
  int len = theStr.length();
  for (int i = 0; i < len; i++) {
    if (theStr[i] == '!') {
      return 1;
    }
  }
  return 0;
}
int cal_factorial_number(string &theStr) {
  int number = 0;
  for (int i = 0; theStr[i] != '!'; i++) {
    if (isdigit(theStr[i])) {
      number *= 10;
      number += theStr[i] - '0';
    }
  }
  return number;
}

int cal_factorial(int theInt) {
  LargeNumberFactorial[0] = LargeNumberFactorial[1] = 1;
  int digit = 1;
  for (int i = 1; i <= theInt; i++) {
    for (int j = 1; j <= digit; j++) {
      LargeNumberFactorial[j] *= i;
    }
    for (int j = 1; j <= digit; j++) {
      if (LargeNumberFactorial[j] > 10) {
        for (int k = 1; k <= digit; k++) {
          if (LargeNumberFactorial[digit] > 9) {
            digit++;
          }
          LargeNumberFactorial[k + 1] += LargeNumberFactorial[k] / 10;
          LargeNumberFactorial[k] %= 10;
        }
      }
    }
  }
  return digit;
}
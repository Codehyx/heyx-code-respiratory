/*
* bigInt
?  让大整数类型能像整型一样轻松使用
?    by heyx
*/
#include <iostream>

namespace Integer {
const std::string symbol = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
template <size_t kMaxLength, int binary, typename T> class BigInt {
private:
  T n, num[kMaxLength];
  bool f;

public:
  BigInt() { Init(); }
  T &operator[](int i) { return num[i]; }
  void Init() {
    n = f = 1;
    fill(num, num + kMaxLength, 0);
  }
  friend std::istream &operator>>(std::istream &tempStream, BigInt &num) {
    std::string s;
    tempStream >> s;
    num.n = s.size();
    if (s[0] == '-') {
      num.f = 0;
      num.n--, s.erase(0, 1);
    }
    for (int i = 0; i < num.n; i++) {
      num[i] = (s[num.n - i - 1] >= 'A' && s[num.n - i - 1] <= 'Z'
                  ? s[num.n - i - 1] - 'A' + 10
                  : s[num.n - i - 1] - '0');
    }
    return tempStream;
  }
  friend std::ostream &operator<<(std::ostream &tempStream, BigInt num) {
    for (; num.n > 1 && !num[num.n - 1]; num.n--) {
    }
    if (!num.f) {
      tempStream << '-';
    }
    for (int i = num.n - 1; i >= 0; i--) {
      tempStream << symbol[num[i]];
    }
    return tempStream;
  }
  void operator=(int x) {
    Init();
    if (!x) {
      return;
    }
    if (x < 0) {
      x = -x, f = 0;
    }
    n = 0;
    while (x) {
      num[n++] = x % binary;
      x /= binary;
    }
  }
  void operator=(std::string x) {
    Init();
    int st = 0;
    if (x[0] == '-') {
      f = 0, st++;
    }
    n = 0;
    int len = x.size();
    for (int i = st; i < len; i++) {
      num[n++] = x[len - i - 1] - '0';
    }
  }
  void operator=(BigInt x) {
    Init();
    n = x.n;
    f = x.f;
    for (int i = 0; i < n; i++) {
      num[i] = x[i];
    }
  }
  bool operator==(BigInt x) {
    if (n != x.n) {
      return 0;
    }
    for (int i = n - 1; i >= 0; i++) {
      if (num[i] != x[i]) {
        return 0;
      }
    }
    return 1;
  }
  bool operator!=(BigInt x) { return !operator==(x); }
  bool operator<(BigInt x) {
    if (n == x.n) {
      for (int i = n - 1; i >= 0; i--) {
        if (num[i] != x[i]) {
          return num[i] < x[i];
        }
      }
    }
    return n < x.n;
  }
  bool operator>(BigInt x) {
    if (n == x.n) {
      for (int i = n - 1; i >= 0; i--) {
        if (num[i] != x[i]) {
          return num[i] > x[i];
        }
      }
    }
    return n > x.n;
  }
  bool operator<=(BigInt x) { return !operator>(x); }
  bool operator>=(BigInt x) { return !operator<(x); }
  bool operator!() {
    if (n != 1) {
      return 0;
    }
    return !num[0];
  }
  bool operator==(int x) {
    BigInt y;
    y = x;
    return operator==(y);
  }
  bool operator!=(int x) {
    BigInt y;
    y = x;
    return operator!=(y);
  }
  bool operator<(int x) {
    BigInt y;
    y = x;
    return operator<(y);
  }
  bool operator>(int x) {
    BigInt y;
    y = x;
    return operator>(y);
  }
  bool operator<=(int x) {
    BigInt y;
    y = x;
    return operator<=(y);
  }
  bool operator>=(int x) {
    BigInt y;
    y = x;
    return operator>=(y);
  }
  BigInt ChangeBinary(BigInt &num) {
    BigInt ans;
    ans[0] = 0, ans.n = 1;
    for (int i = 0; i < num.n; i++) {
      ans = ans * binary;
      ans = ans + num[i];
    }
    num.n = ans.n;
    return ans;
  }
  BigInt operator+(BigInt x) {
    BigInt y;
    y.n = max(n, x.n);
    int s = 0;
    for (int i = 0; i < y.n; i++) {
      s += num[i] + x.num[i];
      y.num[i] = s % binary;
      s /= binary;
    }
    for (; s; s /= binary) {
      y.num[y.n++] += s % binary;
    }
    return y;
  }
  void operator+=(BigInt x) {
    BigInt z = *this;
    *this = z + x;
  }
  void operator+=(int x) {
    BigInt z = *this;
    *this = z + x;
  }
  BigInt operator+(int x) {
    BigInt y;
    y = x;
    return operator+(y);
  }
  BigInt operator-(BigInt x) {
    BigInt y, z = *this;
    if (z < x) {
      y.f = 0, swap(z, x);
    }
    y.n = z.n;
    for (int i = 0; i < y.n; i++) {
      if (z.num[i] < x[i]) {
        z[i + 1]--;
        z[i] += binary;
      }
      y[i] = z[i] - x[i];
    }
    for (; !y[y.n - 1] && y.n > 1; y.n--) {
    }
    return y;
  }
  void operator-=(BigInt x) {
    BigInt z = *this;
    *this = z - x;
  }
  void operator-=(int x) {
    BigInt z = *this;
    *this = z - x;
  }
  BigInt operator-(int x) {
    BigInt y;
    y = x;
    return operator-(y);
  }
  BigInt operator*(BigInt x) {
    BigInt y;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < x.n; j++) {
        y[i + j] += num[i] * x[j];
      }
    }
    y.n = n + x.n;
    for (int i = 0; i < y.n - 1; i++) {
      y[i + 1] += y[i] / binary, y[i] %= binary;
    }
    for (; !y.num[y.n - 1] && y.n > 1; y.n--) {
    }
    return y;
  }
  void operator*=(BigInt x) {
    BigInt z = *this;
    *this = z * x;
  }
  void operator*=(int x) {
    BigInt z = *this;
    *this = z * x;
  }
  BigInt operator*(int x) {
    BigInt y;
    y = x;
    return operator*(y);
  }
  BigInt operator/(BigInt x) {
    BigInt y, z = *this;
    if (x == y) {
      return x;
    }
    if (binary != 10) {
      x = ChangeBinary(x), z = ChangeBinary(z);
    }
    y.n = z.n - x.n + 1;
    for (int i = y.n - 1; i >= 0; i--) {
      BigInt t = x << i;
      for (; z >= t; z -= t) {
        y.num[i]++;
      }
    }
    for (; !y.num[y.n - 1] && y.n > 1; y.n--) {
    }
    return y;
  }
  void operator/=(BigInt x) {
    BigInt z = *this;
    *this = z / x;
  }
  void operator/=(int x) {
    BigInt z = *this;
    *this = z / x;
  }
  BigInt operator/(int x) {
    BigInt y;
    y = x;
    return operator/(y);
  }
  BigInt operator%(BigInt x) {
    BigInt z = *this;
    return z - z / x * x;
  }
  void operator%=(BigInt x) {
    BigInt z = *this;
    *this = z % x;
  }
  void operator%=(int x) {
    BigInt z = *this;
    *this = z % x;
  }
  BigInt operator%(int x) {
    BigInt y;
    y = x;
    return operator%(y);
  }
  BigInt operator<<(int l) {
    BigInt x;
    for (int i = 0; i < n; i++) {
      x[i + l] = num[i];
    }
    x.n = n + l;
    return x;
  }
  BigInt operator>>(int l) {
    BigInt x;
    x.n = n - l;
    for (int i = 0; i < x.n; i++) {
      x[i] = num[i + l];
    }
    return x;
  }
};
};
#include <iostream>

using namespace std;

string s;
bool ans;
int status;

int main() {
  cin >> s;
  int l = s.size();
  for (int i = 0; i < l; i++) {
    if (status) {
      if (s[i] == '(') {
        int x = 1;
        while (x) {
          i++;
          if (s[i] == '(') {
            x++;
          }
          if (s[i] == ')') {
            x--;
          }
        }
      } else if (status == 1 && s[i] == '|' || s[i] == ')') {
        status = 0;
      }
    } else {
      if (s[i] == '1') {
        ans = 1;
      }
      if (s[i] == '0') {
        ans = 0;
      }
      if (s[i] == '&' && ans == 0) {
        status = 1;
      }
      if (s[i] == '|' && ans == 1) {
        status = 2;
      }
    }
  }
  cout << ans;
  return 0;
}
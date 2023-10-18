// ? By Luogu __YLX
#include <bits/stdc++.h>
#include <conio.h>
#include <direct.h>
#include <windows.h>

using namespace std;

const int kMaxN = 1e5 + 5;
const int kMaxLength = 1 << 11;

int lc = 1;
float line[kMaxN];
string file;
bool CtrlA = 0;

// * Get clipboard content
string GetCB() {
  string s;
  if (OpenClipboard(NULL)) {
    HGLOBAL hMem = GetClipboardData(CF_TEXT);
    if (NULL != hMem) {
      s = (char *)GlobalLock(hMem);
      GlobalUnlock(hMem);
    }
    CloseClipboard();
  }
  return s;
}

// * Get running path
string Path() {
  char res[kMaxLength];
  _getcwd(res, kMaxLength);
  string p = res;
  return p;
}

// * Use i as a buffer to process the character c
void cl(string &i, char c) {
  if (c == '\b') { // Backspace
    if (CtrlA) {
      CtrlA = 0;
      fill(&line[1], &line[lc + 1], 0);
      lc = 1;
      i = "";
      system("cls");
      return;
    }
    int l = i.size() - 1, p = 1;
    if (!i.empty()) {
      if (i[l] < 0) {
        l--, p = 2;
      }
      i.erase(l, p);
    }
    for (int i = 1; i <= p; i++) {
      cout << '\b';
    }
    for (int i = 1; i <= p; i++) {
      cout << ' ';
    }
    for (int i = 1; i <= p; i++) {
      cout << '\b';
    }
    line[lc]--;
    if (line[lc] == -1) {
      line[lc] = 0;
      if (lc >= 2) {
        lc--;
      }
    }
    system("cls");
    cout << i;
  } else if (isalpha(c)) { /// Alpha
    if (CtrlA) {
      CtrlA = 0;
      fill(&line[1], &line[lc + 1], 0);
      lc = 1;
      i = "";
      system("cls");
    }
    i += c;
    line[lc]++;
  } else if (c == 13) { /// Enter
    if (CtrlA) {
      CtrlA = 0;
      fill(&line[1], &line[lc + 1], 0);
      lc = 1;
      i = "";
      system("cls");
    }
    i += '\n';
    cout << '\n';
    lc++;
    if (lc == kMaxN) {
      exit(0);
    }
  } else if (c == 9) { // Tab
    if (CtrlA) {
      CtrlA = 0;
      fill(&line[1], &line[lc + 1], 0);
      lc = 1;
      i = "";
      system("cls");
    }
    line[lc] += 2;
    i += "  ";
    cout << "  ";
  } else if (c == 22) { // Ctrl + V
    if (CtrlA) {
      CtrlA = 0;
      fill(&line[1], &line[lc + 1], 0);
      lc = 1;
      i = "";
      system("cls");
    }
    string cb = GetCB();
    for (int l = 0; l < cb.size(); l++) {
      cl(i, cb[l]);
      putchar(cb[l]);
    }
  } else if (c == 19) { // Ctrl + S
    system("title saving...");
    ofstream f(file);
    f << i;
    f.close();
    system("title done.");
    string title =
        "Save complete.\nLine number:" + to_string(lc) + "\nFile name:" + file;
    MessageBox(NULL, title.c_str(), "Message", MB_OK | MB_ICONINFORMATION);
    CtrlA = 0;
  } else if (c > 255 || c < 0) { // Processing Chinese
    putchar(c);
    i += c;
    line[lc]++;
  } else if (c == 1) {
    CtrlA = !CtrlA;
  }
}

// * FK-File Edit implementation
void ide() {
  cout << "+-----------------------------------------------------------+\n";
  cout << "|                      FK-File Edit 2.0                     |\n";
  cout << "|                         By  __YLX                         |\n";
  cout << "+-----------------------------------------------------------+\n";
  cout << "|                      Tips:                                |\n";
  cout << "|                        Press Any Key to                   |\n";
  cout << "|                          start your edit.                 |\n";
  cout << "+-----------------------------------------------------------+\n";
  cout << "Running Path: " << Path() << '\n';
  while (1) {
    if (_kbhit()) {
      system("cls");
      return;
    }
  }
}

// * Save files
void seFile() {
  char ch;
  cout << "File Name (Press Ctrl + Z and then press Enter):\n";
  while ((ch = getchar()) != EOF) {
    file += ch;
  }
  for (int i = 0; i < file.size(); i++) {
    while (file[i] == '\n') {
      file.erase(i, 1);
    }
  }
  if (file.find('.') == string::npos) {
    file += ".txt";
  }
  char one = toupper(file[0]);
  if (one != 'C' && one != 'D' && one != 'E' && one != 'F' && one != 'G' &&
      one != 'H') {
    file = Path() + file;
  }
  cout << "done.";
  Sleep(500);
  system("cls");
  return;
}

// * Main function
int main() {
  ide();
  seFile();
  char ch = 0;
  while (cin >> ch) {
    string c = "";
    cl(c, ch);
  }
  return 0;
}
// Powered by __YLX
#include <bits/stdc++.h>
#include <conio.h>
#include "cons.h"

using namespace std;

int main() {
	Login();
	ide();
	seFile();
	string i;
	while(1) {
		if(CtrlA) {
			system("title [文件全选中]");
		} else {
			string cmd = "title " + file + "   lines:" + to_string(lc) + "    " + to_string(line[lc]);
			system(cmd.c_str());
		}
		int c = _getch();
		cl(i, c);
	}
	return 0;
}

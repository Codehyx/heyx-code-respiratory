// Powered by __YLX
#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<direct.h>

using namespace std;
const int N = 1e5 + 5;

struct User {
	string name;
	string op;
	void get() {
		if(name == "hyx" || name == "ylx") {
			op = "Admin";
		} else if(name == "Japan") {
			op = "F**K";
		} else {
			op = "User";
		}
	}
	int Op() {
		if(op == "F**K") {
			return 7;
		} else if(op == "Admin") {
			return 13;
		} else {
			return 9;
		}
	}
} Now;
int lc = 1;
int line[N];
string file;
bool CtrlA = 0;
bool tmp = 0;

void COLOR_PRINT(const char* s, int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
	printf("%s", s);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}
void COLOR_PRINT(const char s, int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
	printf("%c", s);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}

void NGGYU() {
	system("title 你被骗力（喜）");
	system("cls");
	ifstream l("NeverGonnaGiveYouUp.txt");
	string s;
	while(getline(l, s)) {
		int color = 1;
		for(int i = 0; i < s.size(); i++, color++) {
			if(color == 0) color = 1;
			COLOR_PRINT(s[i], color);
			Sleep(20);
		}
		putchar('\n');
		Sleep(1000);
	}
	system("pause");
	system("cls");
}
string GetCB() {
	string s;
	if(OpenClipboard(NULL)) {
		HGLOBAL hMem = GetClipboardData(CF_TEXT);
		if(NULL != hMem) {
			s = (char*)GlobalLock(hMem);
			GlobalUnlock(hMem);
		}
		CloseClipboard();
	}
	return s;
}

string Path() {
	char res[2048];
	_getcwd(res, 2048);
	string p = res;
	return p;
}

void cl(string &i, char c) {
	if(c == '\b') { // Backspace
		if(CtrlA) {
			CtrlA = 0;
			fill(&line[1], &line[lc + 1], 0);
			lc = 1;
			i = "";
			system("cls");
			return;
		}
		int l = i.size() - 1, p = 1;
		if(!i.empty()) {
			if(i[l] < 0) {
				l--, p = 2;
			}
			i.erase(l, p);
		}
		for(int i = 1; i <= p; i++) {
			cout << '\b';
		}
		for(int i = 1; i <= p; i++) {
			cout << ' ';
		}
		for(int i = 1; i <= p; i++) {
			cout << '\b';
		}
		line[lc]--;
		if(line[lc] <= -1) {
			line[lc] = 0;
			if(lc >= 2) {
				lc--;
			}
			system("cls");
			cout << i;
		}
		if(line[lc] >= 79) {
			if(!i.empty()) {
				system("cls");
				cout << i;
			}
		}
	} else if(c >= 32 && c <= 126) { // Alpha
		if(CtrlA) {
			CtrlA = 0;
			fill(&line[1], &line[lc + 1], 0);
			lc = 1;
			i = "";
			system("cls");
		}
		i += c;
		putchar(c);
		line[lc]++;
	} else if(c == 13) { // Enter
		if(CtrlA) {
			CtrlA = 0;
			fill(&line[1], &line[lc + 1], 0);
			lc = 1;
			i = "";
			system("cls");
		}
		i += '\n';
		cout << '\n';
		lc++;
		if(lc == N) {
			exit(0);
		}
	} else if(c == 9) {	// Tab
		if(CtrlA) {
			CtrlA = 0;
			fill(&line[1], &line[lc + 1], 0);
			lc = 1;
			i = "";
			system("cls");
		}
		line[lc] += 2;
		i += "  ";
		cout << "  ";
	} else if(c == 22) { // Ctrl + V
		if(!tmp){
			int c = MessageBox(NULL, "请确认您要复制的文本的换行符是\\n（也就是LF格式），否则会让FK-FILE Edit出现Bug", "Warning", MB_OKCANCEL|MB_ICONWARNING);
			if(c != 1){
				return;
			}
			tmp = 1;
		}
		if(CtrlA) {
			CtrlA = 0;
			fill(&line[1], &line[lc + 1], 0);
			lc = 1;
			i = "";
			system("cls");
		}
		string cb = GetCB();
		for(int l = 0; l < cb.size(); l++) {
			cl(i, cb[l]);
		}
	} else if(c == 19) { // Ctrl + S
		system("title saving...");
		ofstream f(file);
		f << i;
		f.close();
		system("title done.");
		string title = "保存完成\n行数：" + to_string(lc) + "\n文件名：" + file;
		MessageBox(NULL, title.c_str(), "Message", MB_OK|MB_ICONINFORMATION);
		CtrlA = 0;
	} else if(c > 255 || c < 0) { // 处理中文
		putchar(c);
		i += c;
		line[lc] ++;
	} else if(c == 1) {
		CtrlA = !CtrlA;
	}
	if(i[i.size() - 1] && i[i.size() - 2] == 'L' && i[i.size() - 3] == 'Y') {
		if(line[lc] >= 80) {
			i.erase(i.size() - 4, 3);
			system("cls");
			cout << i;
			COLOR_PRINT("YLX", 2);
			i += "YLX";
		} else {
			cout << "\b\b\b";
			COLOR_PRINT("YLX", 2);
		}
	}
	;
}
void ide() {
	string title = "Welcome " + Now.name + ", you are ";
	system(("title " + title + Now.op).c_str());
	cout << title;
	COLOR_PRINT((Now.op + '\n').c_str(), Now.Op());
	cout << "+--------------------------------------------------+\n";
	cout << "|               ";COLOR_PRINT("FK-File Edit 2.0", 27); cout << "                   |\n";
	cout << "|                  By  __YLX                       |\n";
	cout << "+--------------------------------------------------+\n";
	cout << "|";
	COLOR_PRINT("Tips:", 11);
	cout << "                                             |\n";
	cout << "|  1:Press Any Key to ";
	COLOR_PRINT("start", 2);
	cout << "...                     |\n";
	cout << "|  2:But please don\'t press Alt + A!!!             |\n";
	cout << "|  3:";
	COLOR_PRINT("You can write your words on note.ms/YLX", 6);
	cout << " =)    |\n";
	cout << "|  4:%%%__LZH__                                    |\n";
	cout << "|  5:If you want get the program code, please find |\n";
	cout << "|     ";
	COLOR_PRINT("__YLX", 2);
	cout << " on ";
	COLOR_PRINT("www.luogu.com.cn", 11);
	cout << "=)                  |\n";
	cout << "|  6:Quick to %%%";
	COLOR_PRINT("hyx0201", 4);
	cout << " !!!!                      |\n";
	cout << "|  7:__YLX的英文技术最菜！！！！！！！！！！！！！ |\n";
	cout << "+--------------------------------------------------+\n";
	cout << "Running Path: " << Path() << '\n';
	while(1) {
		if(_kbhit()) {
			if(_getch() == 97) {
				NGGYU();
				Sleep(50);
			}
			system("cls");
			return;
		}
	}
}

void ColorSet() {
	cout << "Please select a word color:\n";
	cout << "0:Black\n";
 	cout << "1:Blue\n";
 	cout << "2:Green\n";
 	cout << "3:Light green\n";
 	cout << "4:Red\n";
 	cout << "5:Purple\n";
 	cout << "6:Yellow\n";
 	cout << "7:White\n";
 	cout << "8:Gray\n";
 	cout << "9:Baby blue\n";
 	cout << "A:Baby green\n";
 	cout << "B:Baby light green\n";
 	cout << "C:Baby red\n";
 	cout << "D:Baby purple\n";
 	cout << "E:Baby yellow\n";
 	cout << "F:Brilliant white\n";
 	string s, yhy;
	getline(cin, s);
 	if (isdigit(s[0]) || isalpha(s[0])) {
 		yhy = s;
 		s = "color " + s;
 		system(s.c_str());
 		cout << '\n';
	} else {
		cout << "Fail!The Word Color is Normal Color!\n";
		yhy = "0";
	}
	cout << "Please select a background color:\n";
	cout << "0:Black\n";
 	cout << "1:Blue\n";
 	cout << "2:Green\n";
 	cout << "3:Light green\n";
 	cout << "4:Red\n";
 	cout << "5:Purple\n";
 	cout << "6:Yellow\n";
 	cout << "7:White\n";
 	cout << "8:Gray\n";
 	cout << "9:Baby blue\n";
 	cout << "A:Baby green\n";
 	cout << "B:Baby light green\n";
 	cout << "C:Baby red\n";
 	cout << "D:Baby purple\n";
 	cout << "E:Baby yellow\n";
 	cout << "F:Brilliant white\n";
 	string srs;
 	getline(cin, srs);
	if (isdigit(srs[0]) || isalpha(srs[0])) {
		srs = "color " + srs + yhy;
		system(srs.c_str());
		cout << '\n';
	} else {
		cout << "Fail!The Background Color is Normal Color!\n";
	}
}

void seFile() {
	char ch;
	cout << "File Name(按Ctrl + Z后按Enter结束)：\n";
	while((ch = getchar()) != EOF) {
		file += ch;
	}
	for(int i = 0; i < file.size(); i++) {
		while(file[i] == '\n') {
			file.erase(i, 1);
		}
	}
	if(file.find('.') == string::npos) {
		file += ".txt";
	}
	char one = toupper(file[0]);
	if(one != 'C' && one != 'D' && one != 'E' && one != 'F' && one != 'G' && one != 'H') {
		file = Path() + '\\' + file;
	}
	cout << "done.\n";
	Sleep(200);
	system("cls");
	cout << "Tips:\n";
	cout << "    You can press [ESC] to close the file, but it doesn\'t save the File!\n";
	cout << '.';
	Sleep(200);
	cout << '.';
	Sleep(200);
	cout << '.';
	Sleep(200);
	cout << '\n';
	ColorSet();
	Sleep(1000);
	system("cls");
	return;
}
void first() {
	User tmp;
	cout << "您似乎是第一次登陆，或者您篡改了options.log。\n";
	cout << "用户名：";
	cin >> tmp.	name;
	tmp.get();
	cout << "Done\n";
	ofstream l("options.log");
	l << "[UserName]" << '\n' << tmp.name << '\n' << "[Level]\n" << tmp.op << '\n';
	Now = tmp;
	l.close();
	system("cls");
}
void Login() {
	ifstream l("options.log");
	vector<string>info;
	string s;
	while(getline(l, s)) {
		info.push_back(s);
	}
	if(info.size() < 4 || info[0] != "[UserName]" || info[2] != "[Level]") {
		first();
	} else {
		Now.name = info[1];
		Now.get();
		if(Now.op != info[3]) {
			first();
		}
	}
	l.close();
}
void Load() {
	Sleep(500);
	system(("dir " + Path()).c_str());
	system(("tree /A " + Path()).c_str());
	COLOR_PRINT((to_string(time(0)) + "\n").c_str(), 7);
	Sleep(500);
	system("cls");
}
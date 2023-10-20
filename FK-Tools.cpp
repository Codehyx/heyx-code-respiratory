// 编码需设置为 WINDOWS-936
#include <bits/stdc++.h>
#include <conio.h>
#include <direct.h>
#include <windows.h>

using namespace std;

const int kMaxN = 1e6 + 10;

struct Users {
	string name;
	string op;
	void GetOp() {
		if (name == "hyx" || name == "ylx") {
			op = "Administrator";
		} else if (name == "Japan") {
			op = "Fuck";
		} else {
			op = "User";
		}
	}
	int OpColor() {
		if (op == "Administrator") {
			return 13;
		} else if (op == "Fuck") {
			return 7;
		} else {
			return 9;
		}
	}
} NowUsr;

struct PassW {
	string webs;
	string name;
	string passw;
} NowAccount, TempArr[kMaxN];

struct WebS {
	string name;
	string site;
	string star;
} NowSite, TmpArr[kMaxN];

int Count1, Count2;

void COLOR_PRINT(const char *s, int color) {
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

void FirstUse() {
	Users tempUsr;
	cout << "您似乎是第一次使用，或修改了 profile.log\n";
	cout << "输入您的用户名：";
	cin >> tempUsr.name;
	tempUsr.GetOp();
	cout << "DONE\n";
	ofstream proEdit("profile.log");
	proEdit << "[UserName]\n" << tempUsr.name << '\n' << "[UserType]\n" << tempUsr.op;
	NowUsr = tempUsr;
	proEdit.close();
	system("cls");
}

void Login() {
  ifstream proIn("profile.log");
  vector<string> usrInfo;
  string s;
  while (getline(proIn, s)) {
    usrInfo.push_back(s);
  }
  if (usrInfo.size() < 4 || usrInfo[0] != "[UserName]" || usrInfo[2] != "[UserType]") {
    FirstUse();
  } else {
    NowUsr.name = usrInfo[1];
    NowUsr.GetOp();
    if (NowUsr.op != usrInfo[3]) {
      FirstUse();
    }
  }
  proIn.close();
}

void printUI() {
	string tit = "Welcome " + NowUsr.name + ", you are ";
  system(("title " + tit + NowUsr.op).c_str());
  cout << tit;
  COLOR_PRINT((NowUsr.op + '\n').c_str(), NowUsr.OpColor());
  cout << "+--------------------------------------------------+\n";
  cout << "|                 ";
  COLOR_PRINT("FK-Tools 1.0", 27);
  cout << "                     |\n";
  cout << "|                    By  hyx                       |\n";
  cout << "+--------------------------------------------------+\n";
}

void Main();
void PassWM();
void WebSM();

/* FK-PassWM - Password Manager */
void Init_PassWM() {
	ifstream tempStr("passwm-name.txt");
	for (; getline(tempStr, TempArr[Count1].name); Count1++) {
		if (Count1 == 0) {
			Count1 = 1;
		}
	}
	tempStr.close();
	ifstream tempStr2("passwm-pass.txt");
	Count1 = 0;
	for (; getline(tempStr2, TempArr[Count1].passw); Count1++) {
		if (Count1 == 0) {
			Count1 = 1;
		}
	}
	tempStr2.close();
	ifstream tempStr3("passwm-webs.txt");
	Count1 = 0;
	for (; getline(tempStr3, TempArr[Count1].webs); Count1++) {
		if (Count1 == 0) {
			Count1 = 1;
		}
	}
	tempStr3.close();
}

void MP_PassWM() {
	NowAccount = {"", "", ""};
  cout << "+--------------------------------------------------+\n";
  cout << "|  Manage password                                 |\n";
  cout << "+--------------------------------------------------+\n";
  cout << "  Website Name:";
  getchar();
  char ch = getchar();
  while (ch != EOF) {
  	if (ch != '\n') {
  		NowAccount.webs += ch;
		}
  	ch = getchar();
	}
  system("cls");
  cout << "+--------------------------------------------------+\n";
  cout << "|  Manage password                                 |\n";
  cout << "+--------------------------------------------------+\n";
  cout << "  Account Name:";
	cin >> NowAccount.name;
	system("cls");
  cout << "+--------------------------------------------------+\n";
  cout << "|  Manage password                                 |\n";
  cout << "+--------------------------------------------------+\n";
  cout << "  Password:";
  ch = getchar();
  while (ch != EOF) {
  	if (ch != '\n') {
  		NowAccount.passw += ch;
		}
  	ch = getchar();
	}
  cout << "Loading";
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cout << '.';
      Sleep(200);
    }
    cout << "\b\b\b   \b\b\b";
  }
	if (Count1 + 1 > kMaxN) {
		cout << "Too many passwords are stored.";
	} else {
		ofstream passwMg0("passwm-webs.txt", ofstream::app);
		passwMg0 << NowAccount.webs << '\n';
		passwMg0.close();
		ofstream passwMg1("passwm-name.txt", ofstream::app);
		passwMg1 << NowAccount.name << '\n';
		passwMg1.close();
	  ofstream passwMg2("passwm-pass.txt", ofstream::app);
		passwMg2 << NowAccount.passw << '\n';
		passwMg2.close();
		TempArr[++Count1] = {NowAccount.webs, NowAccount.name, NowAccount.passw};
	}
  system("cls");
  PassWM();
}

void FP_PassWM() {
  cout << "+--------------------------------------------------+\n";
  cout << "|  Find password                                   |\n";
  cout << "+--------------------------------------------------+\n";
  cout << "  Website Name:";
  getchar();
	char ch = getchar();
	string s = "";
	while (ch != EOF) {
		if (ch != '\n') {
			s += ch;
		}
		ch = getchar();
	}
	Init_PassWM();
	int findFlag = 0;
	for (int i = 1; i <= Count1; i++) {
		if (TempArr[i].webs == s) {
			findFlag++;
			cout << "Account " << findFlag << ":\n" << "Account Name:" << TempArr[i].name << '\n' << "Password:" << TempArr[i].passw << '\n';
		}
	}
	if (!findFlag) {
		cout << "Not Found!";
	}
	system("pause");
	system("cls");
	PassWM();
}

void EP_PassWM() {
  cout << "+--------------------------------------------------+\n";
  cout << "|  Edit password                                   |\n";
  cout << "+--------------------------------------------------+\n";
  for (int i = 1; i <= Count1; i++) {
		cout << "Account " << i << ":\n";
		cout << "Web-Site:" << TempArr[i].webs << ' ' << "Account Name:" << TempArr[i].name << ' ' << "Password:" << TempArr[i].passw << '\n';
	}
	cout << "Enter the password number you want to change. 0 means no change:\n";
	int num;
	for (cin >> num; num; cin >> num){
		cout << "Enter the variable you want to change (1 ~ 3.Web-Site, Name, Password):\n";
		int id;
		cin >> id;
		cout << "Change to:";
		string s;
		char ch = getchar();
		while (ch != EOF) {
			if (ch != '\n') {
				s += ch;
			}
			ch = getchar();
		}
		if (id == 1) {
			TempArr[num].webs = s;
		} else if (id == 2) {
			TempArr[num].name = s;
		} else {
			TempArr[num].passw = s;
		}
		cout << "Completed.\n";
		cout << "Enter the password number you want to change. 0 means no change:\n";
	}
	system("pause");
	system("cls");
	PassWM();
}

void PassWM() {
  cout << "+--------------------------------------------------+\n";
  cout << "|          ";
  COLOR_PRINT("FK-PassWM - Password Manager", 1);
  cout << "            |\n";
  cout << "+--------------------------------------------------+\n";
  cout << "+--------------------------------------------------+\n";
  cout << "|";
  COLOR_PRINT("Options:", 11);
  cout << "                                          |\n";
  cout << "|  1:";
  COLOR_PRINT("Manage password", 1);
  cout << "                               |\n";
  cout << "|  2:";
	COLOR_PRINT("Find password", 2);
	cout << "                                 |\n";
  cout << "|  3:";
	COLOR_PRINT("Edit password", 3);
	cout << "                                 |\n";
	cout << "|  4:";
	COLOR_PRINT("Go back", 4);
	cout << "                                       |\n";
  cout << "+--------------------------------------------------+\n";
	COLOR_PRINT("Input options id:", 1);
	int id;
	cin >> id;
	system("cls");
	if (id == 1) {
		MP_PassWM();
	} else if (id == 2){
		FP_PassWM();
	} else if (id == 3){
		EP_PassWM();
	} else {
		Main();
	}
}
/* ------------------------------------------------------------------ */

/* FK-WebSM - Website Manager */
void Init_WebSM() {
	ifstream tempStr1("websm-name.txt");
	for (; getline(tempStr1, TmpArr[Count2].name); Count2++) {
		if (Count2 == 0) {
			Count2 = 1;
		}
	}
	tempStr1.close();
	ifstream tempStr2("websm-site.txt");
	Count2 = 0;
	for (; getline(tempStr2, TmpArr[Count2].site); Count2++) {
		if (Count2 == 0) {
			Count2 = 1;
		}
	}
	tempStr2.close();
	ifstream tempStr3("websm-star.txt");
	Count2 = 0;
	for (; getline(tempStr3, TmpArr[Count2].star); Count2++) {
		if (Count2 == 0) {
			Count2 = 1;
		}
	}
	tempStr3.close();
}

void MW_WebSM() {
  cout << "+--------------------------------------------------+\n";
  cout << "|  Manage website                                  |\n";
  cout << "+--------------------------------------------------+\n";
  cout << "  Website Name:";
	getchar();
	char ch = getchar();
	while (ch != EOF) {
		if (ch != '\n') {
			NowSite.name += ch;
		}
		ch = getchar();
	}
	system("cls");
  cout << "+--------------------------------------------------+\n";
  cout << "|  Manage website                                  |\n";
  cout << "+--------------------------------------------------+\n";
  cout << "  Web Site:";
	cin >> NowSite.site;
	system("cls");
  cout << "+--------------------------------------------------+\n";
  cout << "|  Manage website                                  |\n";
  cout << "+--------------------------------------------------+\n";
	cout << "  Star this Web-Site? (Yes or No):";
	cin >> NowSite.star;
  cout << "Loading";
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cout << '.';
      Sleep(200);
    }
    cout << "\b\b\b   \b\b\b";
  }
  if (Count2 + 1 > kMaxN) {
  	cout << "Too many sites are stored.";
	} else {
		ofstream websmMg0("websm-name.txt", ofstream::app);
	  websmMg0 << NowSite.name << '\n';
		websmMg0.close();
	  ofstream websmMg1("websm-site.txt", ofstream::app);
	  websmMg1 << NowSite.site << '\n';
		websmMg1.close();
		ofstream websmMg2("websm-star.txt", ofstream::app);
		websmMg2 << NowSite.star << '\n';
		websmMg2.close();
		TmpArr[++Count2] = {NowSite.name, NowSite.site, NowSite.star};
	}
	system("cls");
	WebSM();
}

void FW_WebSM() {
  cout << "+--------------------------------------------------+\n";
  cout << "|  Find website                                    |\n";
  cout << "+--------------------------------------------------+\n";
  cout << "  Website Name:";
  getchar();
  char ch = getchar();
	string s;
	while (ch != EOF) {
		if (ch != '\n') {
			s += ch;
		}
		ch = getchar();
	}
	Init_WebSM();
	bool findFlag = 0;
	for (int i = 1; i <= Count2; i++) {
		if (TmpArr[i].name == s) {
			findFlag = 1;
			cout << "The Web-Site is " << TmpArr[i].site << ", you are" << (TmpArr[i].star == "Yes" ? " " : " not ") << "stared this Web-Site.\n";
			cout << "Open this Web-Site? (Yes or No):";
			string yn;
			cin >> yn;
			if (yn == "Yes") {
				string Com = "start " + TmpArr[i].site;
				system(Com.c_str());
			}
			break;
		}
	}
	if (!findFlag) {
		cout << "Not Found\n";
	}
	system("pause");
	system("cls");
	WebSM();
}

void EW_WebSM() {
  cout << "+--------------------------------------------------+\n";
  cout << "|  Edit website                                    |\n";
  cout << "+--------------------------------------------------+\n";
  for (int i = 1; i <= Count2; i++) {
  	cout << "Account " << i << ":\n";
  	cout << "Name:" << TmpArr[i].name << ' ' << "Web-Site:" << TmpArr[i].site << ' ' << "Star:" << TmpArr[i].star << '\n';
	}
	cout << "Enter the password number you want to change. 0 means no change:\n";
	int num;
	for (cin >> num; num; cin >> num) {
		cout << "Enter the variable you want to change (1 ~ 3.Name, Web-Site, Star):\n";
		int id;
		cin >> id;
		cout << "Change to:";
		string s;
		char ch = getchar();
		while (ch != EOF) {
			if (ch != '\n') {
				s += ch;
			}
			ch = getchar();
		}
		if (id == 1) {
			TmpArr[num].name = s;
		} else if (id == 2) {
			TmpArr[num].site = s;
		} else {
			TmpArr[num].star = s;
		}
		cout << "Completed.\n";
		cout << "Enter the password number you want to change. 0 means no change:\n";
	}
	system("pause");
	system("cls");
	WebSM();
}

void WebSM() {
  cout << "+--------------------------------------------------+\n";
  cout << "|           ";
  COLOR_PRINT("FK-WebSM - Website Manager", 2);
  cout << "             |\n";
  cout << "+--------------------------------------------------+\n";
  cout << "+--------------------------------------------------+\n";
  cout << "|";
  COLOR_PRINT("Options:", 11);
  cout << "                                          |\n";
  cout << "|  1:";
	COLOR_PRINT("Manage website", 1);
	cout << "                                |\n";
	cout << "|  2:";
	COLOR_PRINT("Find website", 2);
	cout << "                                  |\n";
	cout << "|  3:";
	COLOR_PRINT("Go back", 3);
	cout << "                                       |\n";
  cout << "+--------------------------------------------------+\n";
	COLOR_PRINT("Input options id:", 1);
	int id;
	cin >> id;
	system("cls");
	if (id == 1) {
		MW_WebSM();
	} else if (id == 2) {
		FW_WebSM();
	} else {
		Main();
	}
}
/* ------------------------------------------------------------------ */

/* Main */
void Main() {
	printUI();
  cout << "+--------------------------------------------------+\n";
  cout << "|";
  COLOR_PRINT("Options:", 11);
  cout << "                                          |\n";
  cout << "|  1:";
  COLOR_PRINT("FK-PassWM - Password Manager", 1);
  cout << "                  |\n";
  cout << "|  2:";
  COLOR_PRINT("FK-WebSM - Website Manager", 2);
  cout << "                    |\n";
	cout << "|  3:";
	COLOR_PRINT("Exit", 3);
	cout << "                                          |\n";
	cout << "+-------------------------------------------------+\n";
	COLOR_PRINT("Input options id:", 1);
	int id;
	cin >> id;
	Init_PassWM(), Init_WebSM();
	if (id == 1) {
		system("cls");
		PassWM();
	} else if (id == 2) {
		system("cls");
		WebSM();
	} else {
		exit(0);
	}
}

int main() {
	Login();
	Main();
	return 0;
}
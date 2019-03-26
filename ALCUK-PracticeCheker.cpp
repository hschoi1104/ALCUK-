#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
struct node {
	string name;
	string ban;
	int done;
};
vector<vector<string>> v;
map<string, node>m;
int probnum = 0;
int people = 0;
int seniercutline = 0, senierbasiccutline = 0, juniercutline = 0, practicetype = 0;
int t = 0;
string s;
void input() {
	cout << "과제수행인원 : ";
	cin >> people;
	cout << "과제 종류 입력 1. 시니어\n 2. 시니어기초\n3. 주니어\n4.대회\n";
	cin >> practicetype;
	if (practicetype == 1 || practicetype == 4) {
		cout << "시니어 커트라인 : ";
		cin >> seniercutline;
	}
	if (practicetype == 2 || practicetype == 4) {
		cout << "시니어기초 커트라인 : ";
		cin >> seniercutline;
	}
	if (practicetype == 3 || practicetype == 4) {
		cout << "주니어 커트라인 : ";
		cin >> juniercutline;
	}
	cin >> s;
	probnum = s.length() - 10;
}
void output() {
	if (practicetype == 1 || practicetype == 4) {
		printf("======================시니어================================\n");
		for (auto it = m.begin(); it != m.end(); it++) {
			if (it->second.ban == "시니어" && it->second.done < seniercutline) {
				cout << it->second.name << " " << seniercutline - it->second.done << "개 미달\n";
			}
		}
	}
	if (practicetype == 2 || practicetype == 4) {
		printf("======================시니어기초============================\n");
		for (auto it = m.begin(); it != m.end(); it++) {
			if (it->second.ban == "시니어기초" && it->second.done < senierbasiccutline) {
				cout << it->second.name << " " << senierbasiccutline - it->second.done << "개 미달\n";
			}
		}
	}
	if (practicetype == 3 || practicetype == 4) {
		printf("======================주니어================================\n");
		for (auto it = m.begin(); it != m.end(); it++) {
			if (it->second.ban == "주니어" &&it->second.done < juniercutline) {
				cout << it->second.name << " " << juniercutline - it->second.done << "개 미달\n";
			}
		}
	}
	printf("============================================================\n");
}
void initdata() {
	m.insert({ "kimcoding" ,{"김정훈","시니어심화" } });
	m.insert({ "gktgnjftm" ,{"이윤석","시니어심화" } });
	m.insert({ "h0ng" ,{"조재홍","시니어심화" } });
	m.insert({ "leethyun" ,{"이태현","시니어심화" } });
	m.insert({ "antdkfa" ,{"백재상","시니어심화" } });
	m.insert({ "hschoi1104" ,{"최현석","시니어심화" } });
	m.insert({ "maum97" ,{"황수민","시니어심화" } });
	m.insert({ "winterlood" ,{"이정환","시니어심화" } });
	m.insert({ "gjdms611" ,{"허은지","시니어심화" } });
	m.insert({ "cbj2741" ,{"김기헌","시니어" } });
	m.insert({ "ip99202" ,{"한장희","시니어" } });
	m.insert({ "vividswan" ,{"박수환","시니어" } });
	m.insert({ "whdauddbs" ,{"윤종명","시니어" } });
	m.insert({ "caindy" ,{"박도윤","시니어" } });
	m.insert({ "kimdae963" ,{"김대희","시니어" } });
	m.insert({ "fullmoon5110" ,{"이지윤","시니어" } });
	m.insert({ "chan120317" ,{"김혜수","시니어" } });
	m.insert({ "rabbitmjh" ,{"민지홍","시니어" } });
	m.insert({ "spdlqjqkqh" ,{"김진경","시니어" } });
	m.insert({ "wldbs2043" ,{"김지윤","시니어" } });
	m.insert({ "lejj0106" ,{"이은진","시니어기초" } });
	m.insert({ "wldbs2043" ,{"김지윤","시니어" } });
	m.insert({ "vegatrash" ,{"정래광","시니어" } });
	m.insert({ "damin8" ,{"신다민","시니어기초" } });
	m.insert({ "sg05138" ,{"김효빈","시니어기초" } });
	m.insert({ "hi2yeoni" ,{"조희연","시니어기초" } });
	m.insert({ "yoonfy4280" ,{"윤태수","시니어기초" } });
	m.insert({ "subni9511" ,{"주수빈","시니어기초" } });

	m.insert({ "dokdo2013" ,{"조현우","주니어" } });
	m.insert({ "sojang2000" ,{"오소정","주니어" } });
	m.insert({ "00chrislee" ,{"이현서","주니어" } });
	m.insert({ "sincerelyeloise" ,{"윤지영","주니어" } });
	m.insert({ "ssonggary" ,{"송예찬","주니어" } });
	m.insert({ "limik1004" ,{"임익주","주니어" } });
	m.insert({ "xogur1685" ,{"윤태혁","주니어" } });
	m.insert({ "wnsgus821" ,{"임준현","주니어" } });
	m.insert({ "jgk07014" ,{"김진원","주니어" } });
	m.insert({ "jihee0602" ,{"조지희","주니어" } });
	m.insert({ "swyr1016" ,{"선우예림","주니어" } });
	m.insert({ "xb205" ,{"이준영","주니어" } });
	m.insert({ "zzikbu" ,{"이승민","주니어" } });
	m.insert({ "koaru103" ,{"장지연","주니어" } });
}
int main() {
	initdata();
	v.resize(100);
	input();
	//결과 입력부
	getline(cin, s);
	while (t++ < people) {
		string id;
		int done = 0;
		getline(cin, s);
		//id추출
		if (t < 10) {
			for (int i = 1; i < s.length(); i++) {
				if (s[i] != ' ')id += s[i];
				else break;
			}
		}
		else {
			for (int i = 2; i < s.length(); i++) {
				if (s[i] != ' ')id += s[i];
				else break;
			}
		}
		id.pop_back();
		//푼문제수 추출
		for (int i = s.length(); i >= 0; i--) {
			if (s[i] == '/') {
				if (s[i - 2] == '0') done = 10;
				done += s[i - 2] - '0';
				break;
			}
		}
		//커트라인과 대조
		m.find(id)->second.done = done;
	}
	output();
	return 0;
}


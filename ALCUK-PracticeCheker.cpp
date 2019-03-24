#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
vector<vector<string>> v;
vector<string>senier;
vector<string>senierbasic;
vector<string>junier;
map<string, pair<string, string>>m;
int probnum = 0;
int people = 0;
int seniercutline = 0, senierbasiccutline = 0, juniercutline = 0;
int t = 0;
string s;
void input() {
	cout << "과제수행인원 : ";
	cin >> people;
	cout << "시니어 커트라인 : ";
	cin >> seniercutline;
	cout << "시니어기초 커트라인 : ";
	cin >> seniercutline;
	cout << "주니어 커트라인 : ";
	cin >> juniercutline;
	cin >> s;
	probnum = s.length() - 10;
}
void initdata() {
	m.insert({ "kimcoding" ,{"김정훈","시니어" } });
	m.insert({ "gktgnjftm" ,{"이윤석","시니어" } });
	m.insert({ "h0ng" ,{"조재홍","시니어" } });
	m.insert({ "leethyun" ,{"이태현","시니어" } });
	m.insert({ "antdkfa" ,{"백재상","시니어" } });
	m.insert({ "hschoi1104" ,{"최현석","시니어" } });
	m.insert({ "maum97" ,{"황수민","시니어" } });
	m.insert({ "winterlood" ,{"이정환","시니어" } });
	m.insert({ "gjdms611" ,{"허은지","시니어" } });
	m.insert({ "cbj2741" ,{"김기헌","시니어" } });
	m.insert({ "ip99202" ,{"한장희","시니어" } });
	m.insert({ "vividswan" ,{"박수환","시니어" } });
	m.insert({ "whdauddbs" ,{"윤종명","시니어" } });
	m.insert({ "acruxdy" ,{"김도엽","시니어" } });
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
				done = s[i - 2] - '0';
				break;
			}
		}
		//커트라인과 대조
		string ban = (m.find(id)->second.second);
		if (ban == "시니어") {
			if (done < seniercutline) {
				string r;
				if (m.find(id) != m.end()) {
					r += (m.find(id)->second.first);
					r += " ";
					r += seniercutline - done + '0';
					r += "개 미달";
					senier.push_back(r);
				}
			}
		}
		if (ban == "시니어기초") {
			if (done < senierbasiccutline) {
				string r;
				if (m.find(id) != m.end()) {
					r += (m.find(id)->second.first);
					r += " ";
					r += senierbasiccutline - done + '0';
					r += "개 미달";
					senierbasic.push_back(r);
				}
			}
		}
		if (ban == "주니어") {
			if (done < juniercutline) {
				string r;
				if (m.find(id) != m.end()) {
					r += (m.find(id)->second.first);
					r += " ";
					r += juniercutline - done + '0';
					r += "개 미달";
					junier.push_back(r);
				}
			}
		}
	}
	printf("======================시니어================================\n");
	cout << "시니어 과제 제출인원" << senier.size() << endl;
	for (int i = 0; i < senier.size(); i++) {
		cout << senier[i] << endl << endl;
	}
	printf("======================시니어기초============================\n");
	for (int i = 0; i < senierbasic.size(); i++) {
		cout << senierbasic[i] << endl << endl;
	}
	printf("======================주니어================================\n");
	for (int i = 0; i < junier.size(); i++) {
		cout << junier[i] << endl << endl;
	}
	printf("============================================================\n");
	return 0;
}


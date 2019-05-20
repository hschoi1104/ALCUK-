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
map<string, node>m;
string s;
int probnum = 0, people = 0, t = 0;
int seniercutline = 0, senierbasiccutline = 0, juniercutline = 0, practicetype = 0;

void input() {
	cout << "���������ο� : ";
	cin >> people;
	cout << "���� ���� �Է�\n1. �ôϾ�\n2. �ôϾ����\n3. �ִϾ�\n4.��ȸ\n";
	cin >> practicetype;
	if (practicetype == 1 || practicetype == 4) {
		cout << "�ôϾ� ĿƮ���� : ";
		cin >> seniercutline;
	}
	if (practicetype == 2 || practicetype == 4) {
		cout << "�ôϾ���� ĿƮ���� : ";
		cin >> senierbasiccutline;
	}
	if (practicetype == 3 || practicetype == 4) {
		cout << "�ִϾ� ĿƮ���� : ";
		cin >> juniercutline;
	}
	cin >> s;
	probnum = s.length() - 10;
}
void output() {
	if (practicetype == 1 || practicetype == 4) {
		printf("======================�ôϾ�================================\n");
		for (auto it = m.begin(); it != m.end(); it++) {
			if (it->second.ban == "�ôϾ�" && it->second.done < seniercutline) {
				cout << it->second.name << " " << seniercutline - it->second.done << "�� �̴�\n";
			}
		}
	}
	if (practicetype == 2 || practicetype == 4) {
		printf("======================�ôϾ����============================\n");
		for (auto it = m.begin(); it != m.end(); it++) {
			if (it->second.ban == "�ôϾ����" && it->second.done < senierbasiccutline) {
				cout << it->second.name << " " << senierbasiccutline - it->second.done << "�� �̴�\n";
			}
		}
	}
	if (practicetype == 3 || practicetype == 4) {
		printf("======================�ִϾ�================================\n");
		for (auto it = m.begin(); it != m.end(); it++) {
			if (it->second.ban == "�ִϾ�" && it->second.done < juniercutline) {
				cout << it->second.name << " " << juniercutline - it->second.done << "�� �̴�\n";
			}
		}
	}
	printf("============================================================\n");
}
void initdata() {
	m.insert({ "kimcoding" ,{"������","�ôϾ��ȭ" } });
	m.insert({ "gktgnjftm" ,{"������","�ôϾ��ȭ" } });
	m.insert({ "h0ng" ,{"����ȫ","�ôϾ��ȭ" } });
	m.insert({ "leethyun" ,{"������","�ôϾ��ȭ" } });
	m.insert({ "antdkfa" ,{"�����","�ôϾ��ȭ" } });
	m.insert({ "hschoi1104" ,{"������","�ôϾ��ȭ" } });
	m.insert({ "maum97" ,{"Ȳ����","�ôϾ��ȭ" } });
	m.insert({ "gjdms611" ,{"������","�ôϾ��ȭ" } });
	m.insert({ "winterlood" ,{"����ȯ","�ôϾ�" } });
	m.insert({ "cbj2741" ,{"�����","�ôϾ�" } });
	m.insert({ "ip99202" ,{"������","�ôϾ�" } });
	m.insert({ "vividswan" ,{"�ڼ�ȯ","�ôϾ�" } });
	m.insert({ "whdauddbs" ,{"������","�ôϾ�" } });
	m.insert({ "caindy" ,{"�ڵ���","�ôϾ�" } });
	m.insert({ "kimdae963" ,{"�����","�ôϾ�" } });
	m.insert({ "fullmoon5110" ,{"������","�ôϾ�" } });
	m.insert({ "chan120317" ,{"������","�ôϾ�" } });
	m.insert({ "rabbitmjh" ,{"����ȫ","�ôϾ�" } });
	m.insert({ "spdlqjqkqh" ,{"������","�ôϾ�" } });
	m.insert({ "wldbs2043" ,{"������","�ôϾ����" } });
	m.insert({ "lejj0106" ,{"������","�ôϾ����" } });
	m.insert({ "vegatrash" ,{"������","�ôϾ����" } });
	m.insert({ "damin8" ,{"�Ŵٹ�","�ôϾ����" } });
	m.insert({ "sg05138" ,{"��ȿ��","�ôϾ����" } });
	m.insert({ "hi2yeoni" ,{"����","�ôϾ����" } });
	m.insert({ "yoonfy4280" ,{"���¼�","�ôϾ����" } });
	m.insert({ "subni9511" ,{"�ּ���","�ôϾ����" } });

	m.insert({ "dokdo2013" ,{"������","�ִϾ�" } });
	m.insert({ "sojang2000" ,{"������","�ִϾ�" } });
	m.insert({ "00chrislee" ,{"������","�ִϾ�" } });
	m.insert({ "sincerelyeloise" ,{"������","�ִϾ�" } });
	m.insert({ "ssonggary" ,{"�ۿ���","�ִϾ�" } });
	m.insert({ "jgk07014" ,{"������","�ִϾ�" } });
	m.insert({ "swyr1016" ,{"���쿹��","�ִϾ�" } });
	m.insert({ "xb205" ,{"���ؿ�","�ִϾ�" } });
	m.insert({ "koaru103" ,{"������","�ִϾ�" } });
}
int main() {
	initdata();
	input();
	//��� �Էº�
	getline(cin, s);
	while (t++ < people) {
		string id;
		int done = 0;
		getline(cin, s);
		//id����
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
		//Ǭ������ ����
		for (int i = s.length(); i >= 0; i--) {
			if (s[i] == '/') {
				if (s[i - 2] == '0') done = 10;
				done += s[i - 2] - '0';
				break;
			}
		}
		//ĿƮ���ΰ� ����
		m.find(id)->second.done = done;
	}
	output();
	return 0;
}


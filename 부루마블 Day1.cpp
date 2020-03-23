#include <iostream>
#include <random>
#include <ctime>

using namespace std;

bool bankrupty = 0;
int welfare = 0;

class Player {
public:
	Player();
	string* Cities;
	int GetMoney()const ;
	void ChangeMoney(int a);
	void move(int a);
	void location();
	void GetSalary();
	void Dice();
	void GoldKey();
	void isbankrupty();
	void desertisland();
	void donate();
	void Getwelfare();

private:
	int money;
	int loc;
	int isdesertisland;
};

class City {
public:
	City() :certi(0), hotel(0), building(0),villa(0) {}
protected :
	bool certi;
	int hotel;
	int building;
	int villa;
};

class Taipei : public City{
public:
	string str_1 = "Taipei";
	void Lo_Taipei(Player *p) {
		int a;
		if (certi == 0) {
			cout << "Ÿ�̺��̸� ��ڽ��ϱ�?" << endl;
			cout << "1. ��� 2. �����ʴ´�" << endl;
			cin >> a;
			if (a == 1) {
				certi = 1;
				p->ChangeMoney(-50000);
				p->Cities->append(str_1);
				cout << "Ÿ�̺��̸� ����ϴ�." << endl;
			}
		}
		else {
			if (p->Cities->find("Taipei") == true) {
				cout << "�ǹ��� ���ڽ��ϱ�?" << endl;
				cout << "1. ���� �ʴ´� 2. ȣ���� ���´�(7��5õ��) 3. ������ ���´�(5����) 4. ���� ���´�(2��5õ��)" << endl;
				cin >> a;
				switch (a) {
				case 1:
					cout << "�ǹ��� ���� �ʾҽ��ϴ�" << endl;
					break;
				case 2:
					p->ChangeMoney(-75000);
					hotel++;
					cout << "ȣ���� ��������ϴ�." << endl;
					break;
				case 3:
					p->ChangeMoney(-50000);
					building++;
					cout << "������ ��������ϴ�." << endl;
					break;
				case 4:
					p->ChangeMoney(-25000);
					villa++;
					cout << "���� ��������ϴ�." << endl;
					break;
				}
			}
			else {
				int cost = (hotel * 90000) + (building * 60000) + (villa * 30000) + 12000;
				p->ChangeMoney(-cost);
			}
		}
	}
};
class SpecialCity {
public:

protected:
	bool certi;
};

void Map() {
	cout << "                                                  �� �� �� ��                                                 " << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|��ȸ����||�ο��뽺|| Ȳ  �� || ��  �� || �õ�� || ��  �� || �Ͽ��� || ������ ||�� ���� || ��  �� || ��  �� |" << endl;
	cout << "|  ���  ||���̷���||        || ��  �� ||        ||        ||        ||        ||�ں���ȣ|| ��  �� ||        |" << endl;
	cout << "| ����ó || 22���� || ��  �� || 24���� || 24���� || 50���� || 26���� || 26���� || 30���� || 28���� || ��  �� |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| ��Ÿ�� |                                                                                          | ��  �� |" << endl;
	cout << "|        |                                                                                          |        |" << endl;
	cout << "| 20���� |                                                                                          | 30���� |" << endl;
	cout << "----------                                                                                          ----------" << endl;
	cout << "| ������ |                                                                                          | ��  �� |" << endl;
	cout << "|        |                                                                                          | ���ȣ |" << endl;
	cout << "| 18���� |                                                                                          | 45���� |" << endl;
	cout << "----------                                                                                          ----------" << endl;
	cout << "| Ȳ  �� |                                                                                          | ��  �� |" << endl;
	cout << "|        |                                                                                          |        |" << endl;
	cout << "| ��  �� |                                                                                          | 32���� |" << endl;
	cout << "----------                                                                                          ----------" << endl;
	cout << "| ��  �� |                                                                                          | ��  �� |" << endl;
	cout << "|        |                                                                                          |        |" << endl;
	cout << "| 18���� |                                                                                          | 30���� |" << endl;
	cout << "----------                                                                                          ----------" << endl;
	cout << "| ���� |                                                                                          | Ȳ  �� |" << endl;
	cout << "| ������ |                                                                                          |        |" << endl;
	cout << "| 20���� |                                                                                          | ��  �� |" << endl;
	cout << "----------                                                                                          ----------" << endl;
	cout << "| ��  �� |                                                                                          | ��  �� |" << endl;
	cout << "| Ȧ  �� |                                                                                          |        |" << endl;
	cout << "| 16���� |                                                                                          | 35���� |" << endl;
	cout << "----------                                                                                          ----------" << endl;
	cout << "| ��  �� |                                                                                          | ��  �� |" << endl;
	cout << "| ��  �� |                                                                                          |        |" << endl;
	cout << "| 16���� |                                                                                          | 35���� |" << endl;
	cout << "----------                                                                                          ----------" << endl;
	cout << "| Ȳ  �� |                                                                                          |��ȸ����|" << endl;
	cout << "|        |                                                                                          | ��  �� |" << endl;
	cout << "| ��  �� |                                                                                          | 15���� |" << endl;
	cout << "----------                                                                                          ----------" << endl;
	cout << "| ���׳� |                                                                                          | ��  �� |" << endl;
	cout << "|        |                                                                                          |        |" << endl;
	cout << "| 14���� |                                                                                          | 100����|" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|        || ��  �� || ī�̷� || Ȳ  �� || ��  �� || ��  �� || ���Ҷ� || ����¡ || Ȳ  �� || Ÿ  �� ||        |" << endl;
	cout << "| ���ε� || ź  �� ||        ||        || ��  �� ||        ||        ||        ||        || ��  �� || ��  �� |" << endl;
	cout << "|        || 12���� || 10���� || ��  �� || 10���� || 20���� || 8 ���� || 8 ���� || ��  �� || 5 ���� ||        |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
}

int main() {
	Map();
	Player* p1 = new Player();
	Player* p2 = new Player();
	while (bankrupty == 0) {
		p1->Dice();
		p2->Dice();
	}
}

Player::Player() { money = 2500000; loc = 0; isdesertisland = 0; Cities = NULL; }
int Player::GetMoney() const { return money; }
void Player::ChangeMoney(int a) { money += a; }
void Player::move(int a) { loc += a; 
	if (loc < 0) loc += 40;
	if (loc >= 40) { loc -= 40; GetSalary(); }
	location(); 
}
void Player::GetSalary() { money += 200000; cout << "���� 20������ �޾ҽ��ϴ�." << endl; }
void Player::location(){
	switch (loc) {
	case 0:
		cout << "player�� ��ġ�� '���' �Դϴ�." << endl;
		break;
	case 1:
		cout << "player�� ��ġ�� 'Ÿ�̺���' �Դϴ�." << endl;
		
		break;
	case 2:
		cout << "player�� ��ġ�� 'Ȳ�ݿ���' �Դϴ�." << endl;
		GoldKey();
		break;
	case 3:
		cout << "player�� ��ġ�� '����¡' �Դϴ�." << endl;
		break;
	case 4:
		cout << "player�� ��ġ�� '���Ҷ�' �Դϴ�." << endl;
		break;
	case 5:
		cout << "player�� ��ġ�� '����' �Դϴ�." << endl;
		break;
	case 6:
		cout << "player�� ��ġ�� '�̰�����' �Դϴ�." << endl;
		break;
	case 7:
		cout << "player�� ��ġ�� 'Ȳ�ݿ���' �Դϴ�." << endl;
		GoldKey();
		break;
	case 8:
		cout << "player�� ��ġ�� 'ī�̷�' �Դϴ�." << endl;
		break;
	case 9:
		cout << "player�� ��ġ�� '�̽�ź��' �Դϴ�." << endl;
		break;
	case 10:
		cout << "player�� ��ġ�� '���ε�' �Դϴ�." << endl;
		desertisland();
		break;
	case 11:
		cout << "player�� ��ġ�� '���׳�' �Դϴ�." << endl;
		break;
	case 12:
		cout << "player�� ��ġ�� 'Ȳ�ݿ���' �Դϴ�." << endl;
		GoldKey();
		break;
	case 13:
		cout << "player�� ��ġ�� '�����ϰ�' �Դϴ�." << endl;
		break;
	case 14:
		cout << "player�� ��ġ�� '����Ȧ��' �Դϴ�." << endl;
		break;
	case 15:
		cout << "player�� ��ġ�� '���忩����' �Դϴ�." << endl;
		break;
	case 16:
		cout << "player�� ��ġ�� '����' �Դϴ�." << endl;
		break;
	case 17:
		cout << "player�� ��ġ�� 'Ȳ�ݿ���' �Դϴ�." << endl;
		GoldKey();
		break;
	case 18:
		cout << "player�� ��ġ�� '������' �Դϴ�." << endl;
		break;
	case 19:
		cout << "player�� ��ġ�� '��Ÿ��' �Դϴ�." << endl;
		break;
	case 20:
		cout << "player�� ��ġ�� '��ȸ������� ����ó' �Դϴ�." << endl;
		break;
	case 21:
		cout << "player�� ��ġ�� '�ο��뽺���̷���' �Դϴ�." << endl;
		break;
	case 22:
		cout << "player�� ��ġ�� 'Ȳ�ݿ���' �Դϴ�." << endl;
		GoldKey();
		break;
	case 23:
		cout << "player�� ��ġ�� '���Ŀ��' �Դϴ�." << endl;
		break;
	case 24:
		cout << "player�� ��ġ�� '�õ��' �Դϴ�." << endl;
		break;
	case 25:
		cout << "player�� ��ġ�� '�λ�' �Դϴ�." << endl;
		break;
	case 26:
		cout << "player�� ��ġ�� '�Ͽ���' �Դϴ�." << endl;
		break;
	case 27:
		cout << "player�� ��ġ�� '������' �Դϴ�." << endl;
		break;
	case 28:
		cout << "player�� ��ġ�� '�� �����ں��� ȣ' �Դϴ�." << endl;
		break;
	case 29:
		cout << "player�� ��ġ�� '���帮��' �Դϴ�." << endl;
		break;
	case 30:
		cout << "player�� ��ġ�� '���ֿ���' �Դϴ�." << endl;
		break;
	case 31:
		cout << "player�� ��ġ�� '����' �Դϴ�." << endl;
		break;
	case 32:
		cout << "player�� ��ġ�� '�ݷҺ��ȣ' �Դϴ�." << endl;
		break;
	case 33:
		cout << "player�� ��ġ�� '�ĸ�' �Դϴ�." << endl;
		break;
	case 34:
		cout << "player�� ��ġ�� '�θ�' �Դϴ�." << endl;
		break;
	case 35:
		cout << "player�� ��ġ�� 'Ȳ�ݿ���' �Դϴ�." << endl;
		GoldKey();
		break;
	case 36:
		cout << "player�� ��ġ�� '����' �Դϴ�." << endl;
		break;
	case 37:
		cout << "player�� ��ġ�� '����' �Դϴ�." << endl;
		break;
	case 38:
		cout << "player�� ��ġ�� '��ȸ�������' �Դϴ�." << endl;
		donate();
		break;
	case 39:
		cout << "player�� ��ġ�� '����' �Դϴ�." << endl;
		break;
	}
}
void Player::Dice() {
	int a, b;
	int stack = 0;
	srand(time(NULL));
	a = rand() % 6 + 1;
	b = rand() % 6 + 1;
	cout << "�ֻ��� ���� " << a << "�� " << b << " �� " << a + b << "�� ���Խ��ϴ�" << endl;
	if (isdesertisland==1){
		if (a == b) { isdesertisland = 0; }
		else { stack++; }
		if (stack == 3) { isdesertisland = 0; stack = 0; }
	}
	else {
		move(a+b);
		/*if (a == b) {
			cout << "������ ���Խ��ϴ�. �ֻ����� �ѹ� �� �����ϴ�." << endl;
			Dice();
		}*/
	}
}
void Player::GoldKey() {
	srand(time(NULL));
	int a;
	a = rand() % 7 ;
	cout << "Ȳ�ݿ��踦 �̾ҽ��ϴ�." << endl;
	switch (a) {
	case 0:
		cout << "������ ���� : ������ 5������ �����ϼ���." << endl;
		money -= 50000;
		isbankrupty();
		break;
	case 1:
		cout << "���Ǵ�÷ : ���ǿ� ��÷�Ǿ� ��÷�� 20������ �޽��ϴ�." << endl;
		money += 200000;
		break;
	case 2:
		cout << "��� : �ڵ������ֿ��� ����Ͽ� 10������ �޽��ϴ�." << endl;
		money += 100000;
		break;
	case 3:
		cout << "�ؿ����� : �б� ��ϱ� 10������ ���ÿ�." << endl;
		money -= 100000;
		isbankrupty();
		break;
	case 4:
		cout << "���ε��� ���ÿ�." << endl;
		loc = 10;
		desertisland();
		break;
	case 5:
		cout << "�ڷ� ��ĭ���ÿ�." << endl;
		move(-3);
		break;
	case 6:
		cout << "������ ��ĭ���ÿ�." << endl;
		move(3);
		break;
	}
}
void Player::isbankrupty() {
	if (money < 0) { cout << "�Ļ��Դϴ�." << endl; bankrupty = 1; }
}
void Player::desertisland() {
	isdesertisland = 1;
	cout << "���ε��� �������ϴ�. " << endl;
}
void Player::donate() {
	welfare += 150000;
	money -= 150000;
	isbankrupty();
}
void Player::Getwelfare() {
	money += welfare;
	welfare = 0;
}

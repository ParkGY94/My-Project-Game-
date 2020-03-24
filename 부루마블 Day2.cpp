#include <iostream>
#include <random>
#include <ctime>
#include<windows.h>

using namespace std;

bool bankrupty = 0;
int welfare = 0;

class City {
public:
	City(int price):price(price),certi(0), hotel(0), building(0), villa(0), 
		cost((hotel * 1.6 * price) + (building * 1.1 * price) + (villa * 0.6 * price) + (price * 0.25)){
	}
	int Getprice() const { return price; }
	int Gethotel() const { return hotel; }
	int Getbuilding() const { return building; }
	int Getvilla() const { return villa; }
	bool Getcerti() const { return certi; }
	void Changecerti() { certi = !certi; }
	void Changehotel(int a) { hotel += a; }
	void Changebuilding(int a) { building += a; }
	void Changevilla(int a) { villa += a; }
	int cost;
private:
	bool certi;
	int price;
	int hotel;
	int building;
	int villa;
};
City City1[23] = {
	City(50000), City(80000), City(80000), City(100000), City(100000), City(120000), City(140000), City(160000),
	City(160000), City(180000), City(180000), City(200000), City(220000), City(240000), City(240000), City(260000),
	City(260000), City(280000), City(300000), City(320000), City(320000), City(350000), City(350000)
};

class SpecialCity {
public:

private:
	bool certi;
};

class Player {
public:
	Player();
	int Cities[23];
	int GetMoney()const ;
	void ChangeMoney(int a);
	void move(int a, Player *p);
	void location(Player *p);
	void GetSalary();
	void Dice(Player *p);
	void GoldKey(Player *p);
	void isbankrupty();
	void desertisland();
	void donate();
	void Getwelfare();
	void Paycost(Player *p, City City_) {
		p->ChangeMoney(City_.cost);
		ChangeMoney(-(City_.cost));
		isbankrupty();
		cout << "��� ���ÿ� ������ " << City_.cost << "���� ��뿡�� �����մϴ�." << endl;
	}
	void Loc_city(City City_, int n, Player *p) {
		int a;
		if (City_.Getcerti() == 0) {
			cout << "���ø� ��ڽ��ϱ�?" << endl;
			cout << "1. ��� 2. �����ʴ´�" << endl;
			cin >> a;
			if (a == 1) {
				City_.Changecerti();
				ChangeMoney(-(City_.Getprice()));
				Cities[n] = 1;
				cout << "���ø� ����ϴ�." << endl;
			}
		}
		else {
			if (Cities[n] == 1) {
				cout << "�ǹ��� ���ڽ��ϱ�?" << endl;
				cout << "ȣ��" << (City_.Getprice() * 1.5) << "��, ����" << City_.Getprice() << "��, ����" << City_.Getprice() << "�� �Դϴ�." << endl;
				cout << "1. ���� �ʴ´� 2. ȣ���� ���´� 3. ������ ���´� 4. ���� ���´�" << endl;
				cin >> a;
				switch (a) {
				case 1:
					cout << "�ǹ��� ���� �ʾҽ��ϴ�" << endl;
					break;
				case 2:
					ChangeMoney(-(City_.Getprice() * 1.5));
					City_.Changehotel(1);
					cout << "ȣ���� ��������ϴ�." << endl;
					break;
				case 3:
					ChangeMoney(-City_.Getprice());
					City_.Changebuilding(1);
					cout << "������ ��������ϴ�." << endl;
					break;
				case 4:
					ChangeMoney(-(City_.Getprice()*0.5));
					City_.Changebuilding(1);
					cout << "���� ��������ϴ�." << endl;
					break;
				}
			}
			else {
				Paycost(p, City1[n]);
			}
		}
	}
private:
	int money;
	int loc;
	int isdesertisland;
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
		p1->Dice(p2);
		p2->Dice(p1);
	}
}

Player::Player() { money = 2500000; loc = 0; isdesertisland = 0; Cities[22] ={0}; }
int Player::GetMoney() const { return money; }
void Player::ChangeMoney(int a) { money += a; }
void Player::move(int a, Player *p) { 
	loc += a; 
	if (loc < 0) loc += 40;
	if (loc >= 40) { loc -= 40; GetSalary(); }
	location(p); 
}
void Player::GetSalary() { money += 200000; cout << "���� 20������ �޾ҽ��ϴ�." << endl; }
void Player::location(Player *p){
	switch (loc) {
	case 0:
		cout << "plyer�� ��ġ�� '���' �Դϴ�." << endl;
		break;
	case 1:
		cout << "player�� ��ġ�� 'Ÿ�̺���' �Դϴ�." << endl;
		Loc_city(City1[0], 0, p);
		break;
	case 2:
		cout << "player�� ��ġ�� 'Ȳ�ݿ���' �Դϴ�." << endl;
		GoldKey(p);
		break;
	case 3:
		cout << "player�� ��ġ�� '����¡' �Դϴ�." << endl;
		Loc_city(City1[1], 1, p);
		break;
	case 4:
		cout << "player�� ��ġ�� '���Ҷ�' �Դϴ�." << endl;
		Loc_city(City1[2], 2, p);
		break;
	case 5:
		cout << "player�� ��ġ�� '����' �Դϴ�." << endl;
		break;
	case 6:
		cout << "player�� ��ġ�� '�̰�����' �Դϴ�." << endl;
		Loc_city(City1[3], 3, p);
		break;
	case 7:
		cout << "player�� ��ġ�� 'Ȳ�ݿ���' �Դϴ�." << endl;
		GoldKey(p);
		break;
	case 8:
		cout << "player�� ��ġ�� 'ī�̷�' �Դϴ�." << endl;
		Loc_city(City1[4], 4, p);
		break;
	case 9:
		cout << "player�� ��ġ�� '�̽�ź��' �Դϴ�." << endl;
		Loc_city(City1[5], 5, p);
		break;
	case 10:
		cout << "player�� ��ġ�� '���ε�' �Դϴ�." << endl;
		desertisland();
		break;
	case 11:
		cout << "player�� ��ġ�� '���׳�' �Դϴ�." << endl;
		Loc_city(City1[6], 6, p);
		break;
	case 12:
		cout << "player�� ��ġ�� 'Ȳ�ݿ���' �Դϴ�." << endl;
		GoldKey(p);
		break;
	case 13:
		cout << "player�� ��ġ�� '�����ϰ�' �Դϴ�." << endl;
		Loc_city(City1[7], 7, p);
		break;
	case 14:
		cout << "player�� ��ġ�� '����Ȧ��' �Դϴ�." << endl;
		Loc_city(City1[8], 8, p);
		break;
	case 15:
		cout << "player�� ��ġ�� '���忩����' �Դϴ�." << endl;
		break;
	case 16:
		cout << "player�� ��ġ�� '����' �Դϴ�." << endl;
		Loc_city(City1[9], 9, p);
		break;
	case 17:
		cout << "player�� ��ġ�� 'Ȳ�ݿ���' �Դϴ�." << endl;
		GoldKey(p);
		break;
	case 18:
		cout << "player�� ��ġ�� '������' �Դϴ�." << endl;
		Loc_city(City1[10], 10, p);
		break;
	case 19:
		cout << "player�� ��ġ�� '��Ÿ��' �Դϴ�." << endl;
		Loc_city(City1[11], 11, p);
		break;
	case 20:
		cout << "player�� ��ġ�� '��ȸ������� ����ó' �Դϴ�." << endl;
		break;
	case 21:
		cout << "player�� ��ġ�� '�ο��뽺���̷���' �Դϴ�." << endl;
		Loc_city(City1[12], 12, p);
		break;
	case 22:
		cout << "player�� ��ġ�� 'Ȳ�ݿ���' �Դϴ�." << endl;
		GoldKey(p);
		break;
	case 23:
		cout << "player�� ��ġ�� '���Ŀ��' �Դϴ�." << endl;
		Loc_city(City1[13], 13, p);
		break;
	case 24:
		cout << "player�� ��ġ�� '�õ��' �Դϴ�." << endl;
		Loc_city(City1[14], 14, p);
		break;
	case 25:
		cout << "player�� ��ġ�� '�λ�' �Դϴ�." << endl;
		break;
	case 26:
		cout << "player�� ��ġ�� '�Ͽ���' �Դϴ�." << endl;
		Loc_city(City1[15], 15, p);
		break;
	case 27:
		cout << "player�� ��ġ�� '������' �Դϴ�." << endl;
		Loc_city(City1[16], 16, p);
		break;
	case 28:
		cout << "player�� ��ġ�� '�� �����ں��� ȣ' �Դϴ�." << endl;
		break;
	case 29:
		cout << "player�� ��ġ�� '���帮��' �Դϴ�." << endl;
		Loc_city(City1[17], 17, p);
		break;
	case 30:
		cout << "player�� ��ġ�� '���ֿ���' �Դϴ�." << endl;
		break;
	case 31:
		cout << "player�� ��ġ�� '����' �Դϴ�." << endl;
		Loc_city(City1[18], 18, p);
		break;
	case 32:
		cout << "player�� ��ġ�� '�ݷҺ��ȣ' �Դϴ�." << endl;
		break;
	case 33:
		cout << "player�� ��ġ�� '�ĸ�' �Դϴ�." << endl;
		Loc_city(City1[19], 19, p);
		break;
	case 34:
		cout << "player�� ��ġ�� '�θ�' �Դϴ�." << endl;
		Loc_city(City1[20], 20 ,p);
		break;
	case 35:
		cout << "player�� ��ġ�� 'Ȳ�ݿ���' �Դϴ�." << endl;
		GoldKey(p);
		break;
	case 36:
		cout << "player�� ��ġ�� '����' �Դϴ�." << endl;
		Loc_city(City1[21], 21, p);
		break;
	case 37:
		cout << "player�� ��ġ�� '����' �Դϴ�." << endl;
		Loc_city(City1[22], 22, p);
		break;
	case 38:
		cout << "player�� ��ġ�� '��ȸ�������' �Դϴ�." << endl;
		donate();
		break;
	case 39:
		cout << "player�� ��ġ�� '����' �Դϴ�." << endl;
		break;
	}
	cout << endl;
}
void Player::Dice(Player *p) {
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
		move((a+b),p);
		/*if (a == b) {
			cout << "������ ���Խ��ϴ�. �ֻ����� �ѹ� �� �����ϴ�." << endl;
			Dice();
		}*/
	}
}
void Player::GoldKey(Player *p) {
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
		move(-3, p);
		break;
	case 6:
		cout << "������ ��ĭ���ÿ�." << endl;
		move(3, p);
		break;
	}
	Sleep(1000);
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

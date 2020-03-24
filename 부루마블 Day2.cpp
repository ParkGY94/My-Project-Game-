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
		cout << "상대 도시에 도착해 " << City_.cost << "원을 상대에게 지불합니다." << endl;
	}
	void Loc_city(City City_, int n, Player *p) {
		int a;
		if (City_.Getcerti() == 0) {
			cout << "도시를 사겠습니까?" << endl;
			cout << "1. 산다 2. 사지않는다" << endl;
			cin >> a;
			if (a == 1) {
				City_.Changecerti();
				ChangeMoney(-(City_.Getprice()));
				Cities[n] = 1;
				cout << "도시를 샀습니다." << endl;
			}
		}
		else {
			if (Cities[n] == 1) {
				cout << "건물을 짓겠습니까?" << endl;
				cout << "호텔" << (City_.Getprice() * 1.5) << "원, 빌딩" << City_.Getprice() << "원, 빌라" << City_.Getprice() << "원 입니다." << endl;
				cout << "1. 짓지 않는다 2. 호텔을 짓는다 3. 빌딩을 짓는다 4. 빌라를 짓는다" << endl;
				cin >> a;
				switch (a) {
				case 1:
					cout << "건물을 짓지 않았습니다" << endl;
					break;
				case 2:
					ChangeMoney(-(City_.Getprice() * 1.5));
					City_.Changehotel(1);
					cout << "호텔을 만들었습니다." << endl;
					break;
				case 3:
					ChangeMoney(-City_.Getprice());
					City_.Changebuilding(1);
					cout << "빌딩을 만들었습니다." << endl;
					break;
				case 4:
					ChangeMoney(-(City_.Getprice()*0.5));
					City_.Changebuilding(1);
					cout << "빌라를 만들었습니다." << endl;
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
	cout << "                                                  부 루 마 블                                                 " << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|사회복지||부에노스|| 황  금 || 상  파 || 시드니 || 부  산 || 하와이 || 리스본 ||퀸 엘리 || 마  드 || 우  주 |" << endl;
	cout << "|  기금  ||아이레스||        || 울  로 ||        ||        ||        ||        ||자베스호|| 리  드 ||        |" << endl;
	cout << "| 접수처 || 22만원 || 열  쇠 || 24만원 || 24만원 || 50만원 || 26만원 || 26만원 || 30만원 || 28만원 || 여  행 |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| 오타와 |                                                                                          | 도  쿄 |" << endl;
	cout << "|        |                                                                                          |        |" << endl;
	cout << "| 20만원 |                                                                                          | 30만원 |" << endl;
	cout << "----------                                                                                          ----------" << endl;
	cout << "| 베를린 |                                                                                          | 콜  롬 |" << endl;
	cout << "|        |                                                                                          | 비아호 |" << endl;
	cout << "| 18만원 |                                                                                          | 45만원 |" << endl;
	cout << "----------                                                                                          ----------" << endl;
	cout << "| 황  금 |                                                                                          | 파  리 |" << endl;
	cout << "|        |                                                                                          |        |" << endl;
	cout << "| 열  쇠 |                                                                                          | 32만원 |" << endl;
	cout << "----------                                                                                          ----------" << endl;
	cout << "| 베  른 |                                                                                          | 로  마 |" << endl;
	cout << "|        |                                                                                          |        |" << endl;
	cout << "| 18만원 |                                                                                          | 30만원 |" << endl;
	cout << "----------                                                                                          ----------" << endl;
	cout << "| 콩고드 |                                                                                          | 황  금 |" << endl;
	cout << "| 여객기 |                                                                                          |        |" << endl;
	cout << "| 20만원 |                                                                                          | 열  쇠 |" << endl;
	cout << "----------                                                                                          ----------" << endl;
	cout << "| 스  톡 |                                                                                          | 런  던 |" << endl;
	cout << "| 홀  름 |                                                                                          |        |" << endl;
	cout << "| 16만원 |                                                                                          | 35만원 |" << endl;
	cout << "----------                                                                                          ----------" << endl;
	cout << "| 코  펜 |                                                                                          | 뉴  욕 |" << endl;
	cout << "| 하  겐 |                                                                                          |        |" << endl;
	cout << "| 16만원 |                                                                                          | 35만원 |" << endl;
	cout << "----------                                                                                          ----------" << endl;
	cout << "| 황  금 |                                                                                          |사회복지|" << endl;
	cout << "|        |                                                                                          | 기  금 |" << endl;
	cout << "| 열  쇠 |                                                                                          | 15만원 |" << endl;
	cout << "----------                                                                                          ----------" << endl;
	cout << "| 아테네 |                                                                                          | 서  울 |" << endl;
	cout << "|        |                                                                                          |        |" << endl;
	cout << "| 14만원 |                                                                                          | 100만원|" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|        || 이  스 || 카이로 || 황  금 || 싱  가 || 제  주 || 마닐라 || 베이징 || 황  금 || 타  이 ||        |" << endl;
	cout << "| 무인도 || 탄  불 ||        ||        || 포  르 ||        ||        ||        ||        || 베  이 || 출  발 |" << endl;
	cout << "|        || 12만원 || 10만원 || 열  쇠 || 10만원 || 20만원 || 8 만원 || 8 만원 || 열  쇠 || 5 만원 ||        |" << endl;
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
void Player::GetSalary() { money += 200000; cout << "월급 20만원을 받았습니다." << endl; }
void Player::location(Player *p){
	switch (loc) {
	case 0:
		cout << "plyer의 위치는 '출발' 입니다." << endl;
		break;
	case 1:
		cout << "player의 위치는 '타이베이' 입니다." << endl;
		Loc_city(City1[0], 0, p);
		break;
	case 2:
		cout << "player의 위치는 '황금열쇠' 입니다." << endl;
		GoldKey(p);
		break;
	case 3:
		cout << "player의 위치는 '베이징' 입니다." << endl;
		Loc_city(City1[1], 1, p);
		break;
	case 4:
		cout << "player의 위치는 '마닐라' 입니다." << endl;
		Loc_city(City1[2], 2, p);
		break;
	case 5:
		cout << "player의 위치는 '제주' 입니다." << endl;
		break;
	case 6:
		cout << "player의 위치는 '싱가포르' 입니다." << endl;
		Loc_city(City1[3], 3, p);
		break;
	case 7:
		cout << "player의 위치는 '황금열쇠' 입니다." << endl;
		GoldKey(p);
		break;
	case 8:
		cout << "player의 위치는 '카이로' 입니다." << endl;
		Loc_city(City1[4], 4, p);
		break;
	case 9:
		cout << "player의 위치는 '이스탄불' 입니다." << endl;
		Loc_city(City1[5], 5, p);
		break;
	case 10:
		cout << "player의 위치는 '무인도' 입니다." << endl;
		desertisland();
		break;
	case 11:
		cout << "player의 위치는 '아테네' 입니다." << endl;
		Loc_city(City1[6], 6, p);
		break;
	case 12:
		cout << "player의 위치는 '황금열쇠' 입니다." << endl;
		GoldKey(p);
		break;
	case 13:
		cout << "player의 위치는 '코펜하겐' 입니다." << endl;
		Loc_city(City1[7], 7, p);
		break;
	case 14:
		cout << "player의 위치는 '스톡홀름' 입니다." << endl;
		Loc_city(City1[8], 8, p);
		break;
	case 15:
		cout << "player의 위치는 '콩고드여객기' 입니다." << endl;
		break;
	case 16:
		cout << "player의 위치는 '베른' 입니다." << endl;
		Loc_city(City1[9], 9, p);
		break;
	case 17:
		cout << "player의 위치는 '황금열쇠' 입니다." << endl;
		GoldKey(p);
		break;
	case 18:
		cout << "player의 위치는 '베를린' 입니다." << endl;
		Loc_city(City1[10], 10, p);
		break;
	case 19:
		cout << "player의 위치는 '오타와' 입니다." << endl;
		Loc_city(City1[11], 11, p);
		break;
	case 20:
		cout << "player의 위치는 '사회복지기금 접수처' 입니다." << endl;
		break;
	case 21:
		cout << "player의 위치는 '부에노스아이레스' 입니다." << endl;
		Loc_city(City1[12], 12, p);
		break;
	case 22:
		cout << "player의 위치는 '황금열쇠' 입니다." << endl;
		GoldKey(p);
		break;
	case 23:
		cout << "player의 위치는 '상파울로' 입니다." << endl;
		Loc_city(City1[13], 13, p);
		break;
	case 24:
		cout << "player의 위치는 '시드니' 입니다." << endl;
		Loc_city(City1[14], 14, p);
		break;
	case 25:
		cout << "player의 위치는 '부산' 입니다." << endl;
		break;
	case 26:
		cout << "player의 위치는 '하와이' 입니다." << endl;
		Loc_city(City1[15], 15, p);
		break;
	case 27:
		cout << "player의 위치는 '리스본' 입니다." << endl;
		Loc_city(City1[16], 16, p);
		break;
	case 28:
		cout << "player의 위치는 '퀸 엘리자베스 호' 입니다." << endl;
		break;
	case 29:
		cout << "player의 위치는 '마드리드' 입니다." << endl;
		Loc_city(City1[17], 17, p);
		break;
	case 30:
		cout << "player의 위치는 '우주여행' 입니다." << endl;
		break;
	case 31:
		cout << "player의 위치는 '도쿄' 입니다." << endl;
		Loc_city(City1[18], 18, p);
		break;
	case 32:
		cout << "player의 위치는 '콜롬비아호' 입니다." << endl;
		break;
	case 33:
		cout << "player의 위치는 '파리' 입니다." << endl;
		Loc_city(City1[19], 19, p);
		break;
	case 34:
		cout << "player의 위치는 '로마' 입니다." << endl;
		Loc_city(City1[20], 20 ,p);
		break;
	case 35:
		cout << "player의 위치는 '황금열쇠' 입니다." << endl;
		GoldKey(p);
		break;
	case 36:
		cout << "player의 위치는 '런던' 입니다." << endl;
		Loc_city(City1[21], 21, p);
		break;
	case 37:
		cout << "player의 위치는 '뉴욕' 입니다." << endl;
		Loc_city(City1[22], 22, p);
		break;
	case 38:
		cout << "player의 위치는 '사회복지기금' 입니다." << endl;
		donate();
		break;
	case 39:
		cout << "player의 위치는 '서울' 입니다." << endl;
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
	cout << "주사위 값이 " << a << "와 " << b << " 총 " << a + b << "가 나왔습니다" << endl;
	if (isdesertisland==1){
		if (a == b) { isdesertisland = 0; }
		else { stack++; }
		if (stack == 3) { isdesertisland = 0; stack = 0; }
	}
	else {
		move((a+b),p);
		/*if (a == b) {
			cout << "더블이 나왔습니다. 주사위를 한번 더 던집니다." << endl;
			Dice();
		}*/
	}
}
void Player::GoldKey(Player *p) {
	srand(time(NULL));
	int a;
	a = rand() % 7 ;
	cout << "황금열쇠를 뽑았습니다." << endl;
	switch (a) {
	case 0:
		cout << "병원비 지불 : 병원비 5만원을 지불하세요." << endl;
		money -= 50000;
		isbankrupty();
		break;
	case 1:
		cout << "복권당첨 : 복권에 당첨되어 당첨금 20만원을 받습니다." << endl;
		money += 200000;
		break;
	case 2:
		cout << "우승 : 자동차경주에서 우승하여 10만원을 받습니다." << endl;
		money += 100000;
		break;
	case 3:
		cout << "해외유학 : 학교 등록금 10마원을 내시오." << endl;
		money -= 100000;
		isbankrupty();
		break;
	case 4:
		cout << "무인도로 가시오." << endl;
		loc = 10;
		desertisland();
		break;
	case 5:
		cout << "뒤로 세칸가시오." << endl;
		move(-3, p);
		break;
	case 6:
		cout << "앞으로 세칸가시오." << endl;
		move(3, p);
		break;
	}
	Sleep(1000);
}
void Player::isbankrupty() {
	if (money < 0) { cout << "파산입니다." << endl; bankrupty = 1; }
}
void Player::desertisland() {
	isdesertisland = 1;
	cout << "무인도에 갇혔습니다. " << endl;
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

#include <iostream>
#include <time.h>
#include <string>
#include <list>

using namespace std;

class Weapon;
class Monster;
class Player {
public: 
	Player();
	virtual void Attack(Monster *A);
	virtual void DefeatMonster(Monster *A);
	virtual void Skill1(Monster *A);
	virtual void PassiveSkill1(){}
	virtual void LevelUp();
	virtual void ViewPlayerStats() const;
	virtual void EquipWeapon(Weapon w);

	virtual int GetPlayerHP() { return HP; }
	virtual int GetPlayerHPMax() { return HPMax; }
	virtual int GetPlayerMP() { return MP; }
	virtual int GetPlayerMPMax() { return MPMax; }
	virtual int GetPlayerAtt() { return Att; }
	virtual int GetPlayerDef() { return Def; }
	virtual int GetPlayerLv() { return Lv; }
	virtual int GetPlayerExp() { return Exp; }
	virtual void SetPlayerHP(int num) {HP = num;}
	virtual void ChangePlayerHP(int HP_) { HP -= HP_; }
	virtual void SetPlayerMP(int num) { MP = num; }
	virtual void ChangePlayerMP(int MP_) { MP -= MP_; }
	virtual void SetPlayerAtt(int num) { Att = num; }
	virtual void SetPlayerDef(int num) { Def = num; }
	virtual void ChangePlayerLv(int Lv_) { Lv += Lv_; }
	virtual void ChangePlayerExp(int Exp_) { Exp += Exp_; }

protected:
	int HP, HPMax, MP, MPMax, Att, Def;
	int Lv, Exp, Explim;
};

class Monster {
public:
	Monster();
	Monster(int Lv);
	virtual void Attack(Player *player_);
	virtual void MonsterHP();

	virtual int GetMonsterHP() { return HP; }
	virtual int GetMonsterAtt() { return Att; }
	virtual int GetMonsterDef() { return Def; }
	virtual int GetMonsterLv() { return Lv; }
	virtual int GetMonsterExp() { return Exp; }
	virtual void SetMonsterHP(int num) { HP = num; }
	virtual void ChangeMonsterHP(int HP_) { HP -= HP_; }

protected:
	int HP, Att, Def;
	int Lv, Exp;
};
class Warrior : public Player {
public:
	Warrior();
	void LevelUp() {     //레벨업 함수
		Lv++; Exp = Exp - Explim;
		Explim = (Explim * 2) + 10; HPMax += 100; HP = HPMax;
		MPMax += 20; MP = MPMax; Att += 30; Def += 30;
		cout << "축하합니다 레벨이 " << Lv << "가 되었습니다." << endl;
		if (Lv == 3) { void PassiveSkill1(); cout << "패시브 스킬을 배웠습니다" << endl; }
	}
	void Skill1(Monster* A) { //스킬사용함수
		if (MP >= 15) {
			MP -= 15;
			cout << "몬스터에게 PowerAttack스킬을 사용합니다." << endl;
			if ((Att * 2) - (A->GetMonsterDef() / 2) <= 1) { A->ChangeMonsterHP(1); }
			else { A->ChangeMonsterHP((Att * 2) - (A->GetMonsterDef() / 2)); }
			if (A->GetMonsterHP() > 0) { A->MonsterHP(); }
			else { DefeatMonster(A); }
		}
		else {
			cout << "MP가 부족하여 기본공격을 합니다. " << endl;
			Attack(A);
		}
	}
	void PassiveSkill1() { Def += 20; HP += 100; }
private:
};
class Magician : public Player {
public:
	Magician() :Player(){}
	void LevelUp() {     //레벨업 함수
		Lv++; Exp = Exp - Explim;
		Explim = (Explim * 2) + 10; HPMax += 50; HP = HPMax;
		MPMax += 40; MP = MPMax; Att += 45; Def += 15;
		cout << "축하합니다 레벨이 " << Lv << "가 되었습니다." << endl;
		if (Lv == 3) { void PassiveSkill1(); cout << "패시브 스킬을 배웠습니다" << endl; }
	}
	void Skill1(Monster* A) { //스킬사용함수
		if (MP >= 15) {
			MP -= 15;
			cout << "몬스터에게 FireBall스킬을 사용합니다." << endl;
			if ((Att * 2) - (A->GetMonsterDef() / 2) <= 1) { A->ChangeMonsterHP(1); }
			else { A->ChangeMonsterHP((Att * 2) - (A->GetMonsterDef() / 2)); }
			if (A->GetMonsterHP() > 0) { A->MonsterHP(); }
			else { DefeatMonster(A); }
		}
		else {
			cout << "MP가 부족하여 기본공격을 합니다. " << endl;
			Attack(A);
		}
	}
	void PassiveSkill1() { Att += 30; HP += 50; MP += 15; }
private:
};
class Achor : public Player {
public:
	Achor() : Player(){}
	void LevelUp() {     //레벨업 함수
		Lv++; Exp = Exp - Explim;
		Explim = (Explim * 2) + 10; HPMax += 75; HP = HPMax;
		MPMax += 30; MP = MPMax; Att += 40; Def += 20;
		cout << "축하합니다 레벨이 " << Lv << "가 되었습니다." << endl;
		if (Lv == 3) { void PassiveSkill1(); cout << "패시브 스킬을 배웠습니다" << endl; }
	}
	void Skill1(Monster* A) { //스킬사용함수
		if (MP >= 15) {
			MP -= 15;
			cout << "몬스터에게 ArrowShot스킬을 사용합니다." << endl;
			if ((Att * 2) - (A->GetMonsterDef() / 2) <= 1) { A->ChangeMonsterHP(1); }
			else { A->ChangeMonsterHP((Att * 2) - (A->GetMonsterDef() / 2)); }
			if (A->GetMonsterHP() > 0) { A->MonsterHP(); }
			else { DefeatMonster(A); }
		}
		else {
			cout << "MP가 부족하여 기본공격을 합니다. " << endl;
			Attack(A);
		}
	}
	void PassiveSkill1() { Att += 20; HP += 100; MP += 10; }
private:
};

class Rat : public Monster {    //Level 1의 몬스터 Rat
public:
	Rat() :Monster(1){ }
private:
};
class Rabbit : public Monster {    //Level 2의 몬스터 Rabbit
public:
	Rabbit():Monster(2) { }
private:
	
};
class Snake : public Monster {      //Level 3의 몬스터 Rat
public:
	Snake() : Monster(3) { }
private:
};

class  Weapon {
public:
	Weapon(int power): power(power){}
	virtual int Getpower() const { return power; }
private:
	int power;
};

class Sword : public Weapon {
public:
	Sword(int power) : Weapon(power) {}
private:
};


void MainScreen();
void ShowMonster();
void Resting(Player *p);
void HuntingRat(Player *p);
void HuntingRabbit(Player *p);
void HuntingSnake(Player *p);

int main() {
	int a, b;
	Player* My = new Player();
	cout << "원하는 직업을 선택하시오" << endl;
	cout << "1. 전사" << endl;
	cout << "2. 마법사" << endl;
	cout << "3. 궁수" << endl;
	cin >> a;
	switch (a) {
		case 1:
			My = new Warrior();
			break;
		case 2:
			My = new Magician();
			break;
		case 3:
			My = new Achor();
			break;
	}
	
	int c = 0;
	while (c!=1) {
		MainScreen();
		cin >> a;
		switch (a) {
		case 1: {
			ShowMonster();
			cin >> b;
			switch (b) {
			case 1:
				HuntingRat(My);
				break;
			case 2:
				HuntingRabbit(My);
				break;
			case 3:
				HuntingSnake(My);
				break;
			}
			break;
		}
		case 2: {
			My->ViewPlayerStats();
			break;
		}
		case 3:
			Resting(My);
			break;
		case 4:
			c = 1;
			break;
		}
	}
}

Player::Player() : Lv(1), Exp(0), Explim(50), HP(300), HPMax(300),
MP(50), MPMax(50), Att(50), Def(30) {}
void Player::Attack(Monster *A) {    //플레이어가 몬스터를 공격하는 함수
	cout << "몬스터를 공격합니다." << endl;
	if (Att - (A->GetMonsterDef() / 2) <= 1) { A->ChangeMonsterHP(1); } //데미지 공식 Att - Def의 1/2이 1보다 작을경우 1의 피해를 준다
	else { A->ChangeMonsterHP(Att - (A->GetMonsterDef() / 2)); }
	if (A->GetMonsterHP() > 0) { A->MonsterHP(); }
	else { DefeatMonster(A); }
}
void Player::DefeatMonster(Monster *A) {   //몬스터를 잡았을 때의 함수
	cout << "몬스터에게 승리하였습니다. " << A->GetMonsterExp() 
		<< "의 경험치를 획득하였습니다. " << endl;
	ChangePlayerExp(A->GetMonsterExp());
	if (Exp >= Explim) { LevelUp(); }
}
void Player::Skill1(Monster *A) { //스킬사용함수
	if (MP >= 15) { 
		MP -= 15;
		cout << "몬스터에게 스킬을 사용합니다." << endl;
		if ((Att * 2) - (A->GetMonsterDef() / 2) <= 1) { A->ChangeMonsterHP(1); }
		else { A->ChangeMonsterHP((Att * 2) - (A->GetMonsterDef() / 2)); }
		if (A->GetMonsterHP() > 0) { A->MonsterHP(); }
		else { DefeatMonster(A); }
	}
	else { 
		cout << "MP가 부족하여 기본공격을 합니다. " << endl;
		Attack(A);
	}
}
void Player::LevelUp() {     //레벨업 함수
	Lv++; Exp = Exp - Explim;
	Explim = (Explim * 2) + 10; HPMax += 50; HP = HPMax;
	MPMax += 10; MP = MPMax; Att += 25; Def += 15;
	cout << "축하합니다 레벨이 " << Lv << "가 되었습니다." << endl;
}
void Player::ViewPlayerStats() const {
	cout << "플레이어의 레벨은 " << Lv << "입니다." << endl;
	cout << "플레이어의 HP는 " << HP << "/" << HPMax << "입니다." << endl;
	cout << "플레이어의 MP는 " << MP << "/" << MPMax << "입니다." << endl;
	cout << "플레이어의 Att는 " << Att << "입니다." << endl;
	cout << "플레이어의 Def는 " << Def << "입니다." << endl;
	cout << "플레이어의 경험치는 " << Exp << "/" << Explim << " 입니다." << endl;
}
void Player::EquipWeapon(Weapon w) {
	Att += w.Getpower();
}

Warrior::Warrior() :Player() {  }
Monster::Monster() : Lv(1), HP(150), Att(20), Def(20), Exp(10) {}
Monster::Monster(int Lv) {
	HP = (Lv * 75) + 75; Att = Lv * 20; Def = Lv * 20; Exp = Lv * 10;
}
void Monster::Attack(Player *player_) {
	cout << "몬스터가 공격합니다." << endl;
	if (Att - (player_->GetPlayerDef() / 2) <= 1) { player_->ChangePlayerHP(1); }
	else { player_->ChangePlayerHP(Att - (player_->GetPlayerDef() / 2)); }
}
void Monster::MonsterHP() {  // 몬스터의 남은 Hp를 나타내는 함수
	cout << "몬스터의 HP는 " << HP << "남았습니다. " << endl;
}

void MainScreen() {
	cout << endl;
	cout << "메인 화면" << endl;
	cout << "원하는 번호를 입력하세요" << endl;
	cout << "1. 몬스터를 사냥한다." << endl;
	cout << "2. 나의 상태를 본다." << endl;
	cout << "3. 휴식을 취한다" << endl;
	cout << "4. 종료" << endl;
}
void ShowMonster() {
	cout << "원하는 몬스터의 번호를 입력하세요" << endl;
	cout << "1. Lv1 Rat" << endl;
	cout << "2. Lv2 Rabbit" << endl;
	cout << "3. Lv3 Snake" << endl;
}
void Resting(Player *p) {
	p->ChangePlayerHP(-50);
	if (p->GetPlayerHP() >= p->GetPlayerHPMax()) { p->SetPlayerHP(p->GetPlayerHPMax()); }
	p->ChangePlayerMP(-20);
	if (p->GetPlayerMP() >= p->GetPlayerMPMax()) { p->SetPlayerMP(p->GetPlayerMPMax()); }
	cout << "휴식을 취해 HP와 MP를 회복하였습니다." << endl;
}

void HuntingRat(Player *p) {
	Monster* R = new Rat();
	int* choice = new int (0);
	while (true) {
		cout << "1. 기본공격" << endl;
		cout << "2. 스킬(파워어택)" << endl;
		cin >> *choice;
		switch (*choice) {
		case 1:
			p->Attack(R);
			break;
		case 2:
			p->Skill1(R);
			break;
		}
		if (R->GetMonsterHP() <= 0) { break; }
		R->Attack(p);
	}
	delete choice;
	delete R;
}
void HuntingRabbit(Player* p) {
	Monster* R = new Rabbit();
	int* choice = new int(0);
	while (true) {
		cout << "1. 기본공격" << endl;
		cout << "2. 스킬(파워어택)" << endl;
		cin >> *choice;
		switch (*choice) {
		case 1:
			p->Attack(R);
			break;
		case 2:
			p->Skill1(R);
			break;
		}
		if (R->GetMonsterHP() <= 0) { break; }
		R->Attack(p);
	}
	delete choice;
	delete R;;
}
void HuntingSnake(Player* p) {
	Monster* R = new Snake();
	int* choice = new int(0);
	while (true) {
		cout << "1. 기본공격" << endl;
		cout << "2. 스킬(파워어택)" << endl;
		cin >> *choice;
		switch (*choice) {
		case 1:
			p->Attack(R);
			break;
		case 2:
			p->Skill1(R);
			break;
		}
		if (R->GetMonsterHP() <= 0) { break; }
		R->Attack(p);
	}
	delete choice;
	delete R;
}
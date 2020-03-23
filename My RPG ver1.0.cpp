#include <iostream>
#include <time.h>

using namespace std;

class Monster;
class Player {
public: 
	Player();
	void Attack(Monster *A);
	void DefeatMonster(Monster *A);
	void Skill(Monster *A);
	void LevelUp();
	void ViewPlayerStats() const;

	int GetPlayerHP() { return HP; }
	int GetPlayerHPMax() { return HPMax; }
	int GetPlayerMP() { return MP; }
	int GetPlayerMPMax() { return MPMax; }
	int GetPlayerAtt() { return Att; }
	int GetPlayerDef() { return Def; }
	int GetPlayerLv() { return Lv; }
	int GetPlayerExp() { return Exp; }
	void SetPlayerHP(int num) {HP = num;}
	void ChangePlayerHP(int HP_) { HP -= HP_; }
	void SetPlayerMP(int num) { MP = num; }
	void ChangePlayerMP(int MP_) { MP -= MP_; }
	void SetPlayerAtt(int num) { Att = num; }
	void SetPlayerDef(int num) { Def = num; }
	void ChangePlayerLv(int Lv_) { Lv += Lv_; }
	void ChangePlayerExp(int Exp_) { Exp += Exp_; }

private:
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
	virtual void SetMonsterHP(int num) { HP = num; }
	virtual void ChangeMonsterHP(int HP_) { HP -= HP_; }

protected:
	int HP, Att, Def;
	int Lv;
};

class Rat : public Monster {    //Level 1�� ���� Rat
public:
	Rat() { Monster(1); }
private:
};

class Rabbit : public Monster {    //Level 2�� ���� Rabbit
public:
	Rabbit() { Monster(2); }
private:
};

class Snake : public Monster {      //Level 3�� ���� Rat
public:
	Snake() { Monster(3); }
private:
};

void MainScreen();
void ShowMonster();
void Resting(Player *p);
void HuntingRat(Player *p);
void HuntingRabbit(Player *p);
void HuntingSnake(Player *p);

int main() {
	Player *My= new Player();
	int a,b;
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
void Player::Attack(Monster *A) {    //�÷��̾ ���͸� �����ϴ� �Լ�
	cout << "���͸� �����մϴ�." << endl;
	if (Att - (A->GetMonsterDef() / 2) <= 1) { A->ChangeMonsterHP(1); } //������ ���� Att - Def�� 1/2�� 1���� ������� 1�� ���ظ� �ش�
	else { A->ChangeMonsterHP(Att - (A->GetMonsterDef() / 2)); }
	if (A->GetMonsterHP() > 0) { A->MonsterHP(); }
	else { DefeatMonster(A); }
}
void Player::DefeatMonster(Monster *A) {   //���͸� ����� ���� �Լ�
	cout << "���Ϳ��� �¸��Ͽ����ϴ�. " << (A->GetMonsterLv() * 10)
		<< "�� ����ġ�� ȹ���Ͽ����ϴ�. " << endl;
	ChangePlayerExp(A->GetMonsterLv() * 10);
	if (Exp >= Explim) { LevelUp(); }
}
void Player::Skill(Monster *A) { //��ų����Լ�
	cout << "���Ϳ��� ��ų�� ����մϴ�." << endl;
	if ((Att * 2) - (A->GetMonsterDef() / 2) <= 1) { A->ChangeMonsterHP(1); }
	else { A->ChangeMonsterHP((Att * 2) - (A->GetMonsterDef() / 2)); }
	MP -= 15;
	if (A->GetMonsterHP() > 0) { A->MonsterHP(); }
	else { DefeatMonster(A); }
}
void Player::LevelUp() {     //������ �Լ�
	Lv++; Exp = Exp - Explim;
	Explim = (Explim * 2) + 10; HPMax += 50; HP = HPMax;
	MPMax += 10; MP = MPMax; Att += 25; Def += 15;
	cout << "�����մϴ� ������ " << Lv << "�� �Ǿ����ϴ�." << endl;
}
void Player::ViewPlayerStats() const {
	cout << "�÷��̾��� ������ " << Lv << "�Դϴ�." << endl;
	cout << "�÷��̾��� HP�� " << HP << "/" << HPMax << "�Դϴ�." << endl;
	cout << "�÷��̾��� MP�� " << MP << "/" << MPMax << "�Դϴ�." << endl;
	cout << "�÷��̾��� Att�� " << Att << "�Դϴ�." << endl;
	cout << "�÷��̾��� Def�� " << Def << "�Դϴ�." << endl;
	cout << "�÷��̾��� ����ġ�� " << Exp << "/" << Explim << " �Դϴ�." << endl;
}

Monster::Monster() : Lv(1), HP(150), Att(20), Def(20) {}
Monster::Monster(int Lv) {
	HP = (Lv * 75) + 75; Att = Lv * 20; Def = Lv * 20;
}
void Monster::Attack(Player *player_) {
	cout << "���Ͱ� �����մϴ�." << endl;
	if (Att - (player_->GetPlayerDef() / 2) <= 1) { player_->ChangePlayerHP(1); }
	else { player_->ChangePlayerHP(Att - (player_->GetPlayerDef() / 2)); }
}
void Monster::MonsterHP() {  // ������ ���� Hp�� ��Ÿ���� �Լ�
	cout << "������ HP�� " << HP << "���ҽ��ϴ�. " << endl;
}

void MainScreen() {
	cout << endl;
	cout << "���� ȭ��" << endl;
	cout << "���ϴ� ��ȣ�� �Է��ϼ���" << endl;
	cout << "1. ���͸� ����Ѵ�." << endl;
	cout << "2. ���� ���¸� ����." << endl;
	cout << "3. �޽��� ���Ѵ�" << endl;
	cout << "4. ����" << endl;
}
void ShowMonster() {
	cout << "���ϴ� ������ ��ȣ�� �Է��ϼ���" << endl;
	cout << "1. Lv1 Rat" << endl;
	cout << "2. Lv2 Rabbit" << endl;
	cout << "3. Lv3 Snake" << endl;
}
void Resting(Player *p) {
	p->ChangePlayerHP(-50);
	if (p->GetPlayerHP() >= p->GetPlayerHPMax()) { p->SetPlayerHP(p->GetPlayerHPMax()); }
	p->ChangePlayerMP(-20);
	if (p->GetPlayerMP() >= p->GetPlayerMPMax()) { p->SetPlayerMP(p->GetPlayerMPMax()); }
	cout << "�޽��� ���� HP�� MP�� ȸ���Ͽ����ϴ�." << endl;
}

void HuntingRat(Player *p) {
	Monster* R = new Rat();
	int* choice = new int (0);
	while (true) {
		cout << "1. �⺻����" << endl;
		cout << "2. ��ų(�Ŀ�����)" << endl;
		cin >> *choice;
		switch (*choice) {
		case 1:
			p->Attack(R);
			break;
		case 2:
			p->Skill(R);
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
		cout << "1. �⺻����" << endl;
		cout << "2. ��ų(�Ŀ�����)" << endl;
		cin >> *choice;
		switch (*choice) {
		case 1:
			p->Attack(R);
			break;
		case 2:
			p->Skill(R);
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
		cout << "1. �⺻����" << endl;
		cout << "2. ��ų(�Ŀ�����)" << endl;
		cin >> *choice;
		switch (*choice) {
		case 1:
			p->Attack(R);
			break;
		case 2:
			p->Skill(R);
			break;
		}
		if (R->GetMonsterHP() <= 0) { break; }
		R->Attack(p);
	}
	delete choice;
	delete R;
}
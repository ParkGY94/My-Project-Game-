#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	int input;
	int str = 0;
	int ball = 0;
	int num[3];
	num[0] = rand() % 10;
	num[1] = (rand() % 9) + 1;
	num[2] = (rand() % 9) + 1 ;
	while (num[1]==num[0]){
		num[1] = rand() % 10;
	}
	while (num[2]== num[1] || num[2] == num[0]) {
		num[2] = rand() % 10;
	}

	while (1) {
		cout << "���� �ٸ� ���ڸ� ���� �Է��ϼ���" << endl;
		cin >> input;
		int input_[3];
		input_[0] = input % 10;
		input_[1] = (input / 10) % 10;
		input_[2] = input / 100;
		for (int i=0; i < 3; i++) {
			if (num[i] == input_[i]) { str++; }
		}
		for (int i=0; i < 3; i++) {
			if (input_[i] == num[(i + 1) % 3] || input_[i] == num[(i + 2) % 3]) { ball++; }
		}
		if (str == 3) {
			cout << "�����մϴ�. �����Դϴ�." << endl;
			break;
		}
		else{
			cout << str << "��Ʈ����ũ " << ball << "���Դϴ�. " << endl;
			str = 0;
			ball = 0;
		}
	}
}
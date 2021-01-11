//������ ����쳿
//������ 23
//lab-9.3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;



struct Room
{
	bool booked;
	int num;
	string prizv;
	string inizialy;

};


void Create(Room* p, const int N);
void SaveToFile(Room* p, const int N, const char* filename);
void LoadFromFile(Room*& p, int& N, const char* filename);
int BinSearch(Room* p, const int N, const string prizv, const string inizialy);


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "������ N: "; cin >> N;

	Room* p = new Room[N];



	string prizv, inizialy;
	char filename[100];
	int found;

	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ����� � ����" << endl;
		cout << " [3] - ���������� � �����" << endl;
		cout << " [4] - ������� ����� �������� �� �������� �� ���������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;

		case 2:
			cin.get();
			cin.sync();

			cout << "������ ��'� �����: "; cin.getline(filename, 99);
			SaveToFile(p, N, filename);
			break;

		case 3:
			cin.get();
			cin.sync();

			cout << "������ ��'� �����: "; cin.getline(filename, 99);
			LoadFromFile(p, N, filename);
			break;
		case 4:
			cout << "������ ����� ������:" << endl;
			cout << "�������:  ";
			cin >> prizv;
			cout << "�������:  ";
			cin >> inizialy;

			cin.get();
			cin.sync();

			if ((found = BinSearch(p, N, prizv, inizialy)) != -1)
				cout << "�������� �������� � �������: " << found + 1 << endl;
			else
				cout << "�������� �������� �� ��������" << endl;
			break;

		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);


}

void Create(Room* p, const int N)
{
	int spec1;
	for (int i = 0; i < N; i++)
	{
		cout << "ʳ����� � " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << " [1] - �������� ����� [0] - ������: "; cin >> p[i].booked;
		cout << " ������� ���� � �����: "; cin >> p[i].num;

		if (p[i].booked == true)
		{
			cout << " �������: "; cin >> p[i].prizv;
			cout << " �������: "; cin >> p[i].inizialy;
		}

	}
}

void SaveToFile(Room* p, const int N, const char* filename)
{
	ofstream fout(filename, ios::binary);
	fout.write((char*)&N, sizeof(N));
	for (int i = 0; i < N; i++)
		fout.write((char*)&p[i], sizeof(Room));
	fout.close();
}

void LoadFromFile(Room*& p, int& N, const char* filename)
{
	delete[] p;
	ifstream fin(filename, ios::binary);
	fin.read((char*)&N, sizeof(N));
	p = new Room[N];
	for (int i = 0; i < N; i++)
		fin.read((char*)&p[i], sizeof(Room));
	fin.close();
}


void Edit(Room* p, const int N, int i)
{
	cout << "ʳ����� � " << i << ":" << endl;
	cin.get();
	cin.sync();

	cout << " [1] - �������� ����� [0] - ������: "; cin >> p[i - 1].booked;
	cout << " ������� ���� � �����: "; cin >> p[i - 1].num;

	if (p[i].booked == true)
	{
		cout << " �������: "; cin >> p[i - 1].prizv;
		cout << " �������: "; cin >> p[i - 1].inizialy;
	}
}

int BinSearch(Room* p, const int N, const string prizv, const string inizialy)
{
	int L = 0, R = N - 1, m;
	int mid;
	do {
		m = (L + R) / 2;

		if (p[m].prizv == prizv && p[m].inizialy == inizialy)
			return m;

		if (p[m].prizv == prizv && p[m].inizialy != inizialy)
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}
//ўеп≥тки —олом≥њ
//¬ар≥ант 23
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
	cout << "¬вед≥ть N: "; cin >> N;

	Room* p = new Room[N];



	string prizv, inizialy;
	char filename[100];
	int found;

	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "¬ибер≥ть д≥ю:" << endl << endl;
		cout << " [1] - введенн€ даних з клав≥атури" << endl;
		cout << " [2] - запис у файл" << endl;
		cout << " [3] - зчитуванн€ з файлу" << endl;
		cout << " [4] - б≥нарний пошук мешканц€ за пр≥звищем та ≥н≥ц≥алами" << endl;
		cout << " [0] - вих≥д та завершенн€ роботи програми" << endl << endl;
		cout << "¬вед≥ть значенн€: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;

		case 2:
			cin.get();
			cin.sync();

			cout << "¬вед≥ть ≥м'€ файлу: "; cin.getline(filename, 99);
			SaveToFile(p, N, filename);
			break;

		case 3:
			cin.get();
			cin.sync();

			cout << "¬вед≥ть ≥м'€ файлу: "; cin.getline(filename, 99);
			LoadFromFile(p, N, filename);
			break;
		case 4:
			cout << "¬вед≥ть ключ≥ пошуку:" << endl;
			cout << "пр≥звище:  ";
			cin >> prizv;
			cout << "≥н≥ц≥али:  ";
			cin >> inizialy;

			cin.get();
			cin.sync();

			if ((found = BinSearch(p, N, prizv, inizialy)) != -1)
				cout << "«найдено мешканц€ в позиц≥њ: " << found + 1 << endl;
			else
				cout << "Ўуканого мешканц€ не знайдено" << endl;
			break;

		case 0:
			break;
		default:
			cout << "¬и ввели помилкове значенн€! "
				"—л≥д ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);


}

void Create(Room* p, const int N)
{
	int spec1;
	for (int i = 0; i < N; i++)
	{
		cout << " ≥мната є " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << " [1] - зайн€тий номер [0] - в≥льний: "; cin >> p[i].booked;
		cout << " к≥льк≥сть м≥сць в номер≥: "; cin >> p[i].num;

		if (p[i].booked == true)
		{
			cout << " пр≥звище: "; cin >> p[i].prizv;
			cout << " ≥н≥ц≥али: "; cin >> p[i].inizialy;
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
	cout << " ≥мната є " << i << ":" << endl;
	cin.get();
	cin.sync();

	cout << " [1] - зайн€тий номер [0] - в≥льний: "; cin >> p[i - 1].booked;
	cout << " к≥льк≥сть м≥сць в номер≥: "; cin >> p[i - 1].num;

	if (p[i].booked == true)
	{
		cout << " пр≥звище: "; cin >> p[i - 1].prizv;
		cout << " ≥н≥ц≥али: "; cin >> p[i - 1].inizialy;
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
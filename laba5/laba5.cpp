#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void deleteMatrInt(int** matr, int m);
void deleteMatrDouble(double** matr, int m);
void Len(int* len);
void Task1();
void ShowMatrInt(int** matr, int m, int n);
void CreateMatrInt(int** matr, int m, int n);
void Task2();
void ShowMatrDouble(double** matr, int m, int n);
void CreateMatrDouble(double** matr, int m, int n);
void Task3();
int SearchMaxMatrInt(int** matr, int m, int n);
int KolvoMenMax(int** matr, int m, int n, int maxx);
void Task4();
void SortByStr(double** matr, int m, int n);
double sumOfOddElements(double* row, int n);
void Task5();
void ShowMatrDoubleInfo(double** matr, int m, int n);
void Task6();
void Task7();
void MultMatr(int** matr1, int m1, int nm, int n2, int** matr2, int** multMatr);

int main()
{
	setlocale(LC_ALL, "");
	srand(unsigned(time(0)));
	cout << "*******************************" << endl;
	cout << setw(45) << "Лабораторная работа №4" << endl;
	cout << setw(40) << "Одномерные массивы" << endl;
	cout << "Выполнил студент группы 151412" << endl;
	cout << setw(49) << "Пирогов Павел Алексеевич" << endl;
	cout << setw(30) << "Вариант №17" << endl;
	cout << "*******************************" << endl << endl;
	int n;
	cout << "Какую задачу хотите запустить? "; cin >> n;
	switch (n) {
	case 1:
		Task1();
		break;
	case 2:
		Task2();
		break;
	case 3:
		Task3();
		break;
	case 4:
		Task4();
		break;
	case 5:
		Task5();
		break;
	case 6:
		Task6();
		break;
	case 7:
		Task7();
		break;
	default:
		cout << "Такой задачи нет";
		break;
	}
}

void deleteMatrInt(int** matr, int m) {
	for (int i = 0; i < m; i++) {
		delete[] matr[i];
	}
	delete[] matr;
}

void deleteMatrDouble(double** matr, int m) {
	for (int i = 0; i < m; i++) {
		delete[] matr[i];
	}
	delete[] matr;
}

void Len(int* len) {
	do {
		cout << "Какой размер матрицы хотите(через пробел)? "; cin >> len[0] >> len[1];
	} while (len[0] <= 0 || len[1] <= 0);
}

void Task1() {
	int* len = new int[2];
	Len(len);

	int** matr = new int* [len[0]];
	CreateMatrInt(matr, len[0], len[1]);
	ShowMatrInt(matr, len[0], len[1]);
	deleteMatrInt(matr, len[0]);
}

void ShowMatrInt(int** matr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(4) << matr[i][j] << " ";
		}
		cout << endl;
	}
}

void CreateMatrInt(int** matr, int m, int n) {
	for (int i = 0; i < m; i++) {
		matr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			matr[i][j] = rand() % 200 - 100;
		}
	}
}

void Task2() {
	int* len = new int[2];
	Len(len);

	double** matr = new double* [len[0]];
	CreateMatrDouble(matr, len[0], len[1]);
	ShowMatrDouble(matr, len[0], len[1]);
	deleteMatrDouble(matr, len[0]);
}

void ShowMatrDouble(double** matr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(7) << matr[i][j] << " ";
		}
		cout << endl;
	}
}

void CreateMatrDouble(double** matr, int m, int n) {
	for (int i = 0; i < m; i++) {
		matr[i] = new double[n];
		for (int j = 0; j < n; j++) {
			matr[i][j] = 0.01 * (rand() % 20000 - 10000);
		}
	}
}

void Task3() {
	int m = 7, n = 5;

	int** matr = new int* [m];
	CreateMatrInt(matr, m, n);
	ShowMatrInt(matr, m, n);
	int maxx = SearchMaxMatrInt(matr, m, n);
	cout << endl << "Количество чисел, меньших максимального = " << KolvoMenMax(matr, m, n, maxx);
	deleteMatrInt(matr, m);
}

int SearchMaxMatrInt(int** matr, int m, int n) {
	int maxx = matr[0][0];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (maxx < matr[i][j]) maxx = matr[i][j];
		}
	}
	return maxx;
}

int KolvoMenMax(int** matr, int m, int n, int maxx) {
	int count = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (matr[i][j] < maxx) count++;
	return count;
}

void Task4() {
	int* len = new int[2];
	Len(len);

	double** matr = new double* [len[0]];
	CreateMatrDouble(matr, len[0], len[1]);
	ShowMatrDouble(matr, len[0], len[1]);

	cout << endl << endl;

	SortByStr(matr, len[0], len[1]);
	ShowMatrDouble(matr, len[0], len[1]);

	deleteMatrDouble(matr, len[0]);
}

void SortByStr(double** matr, int m, int n) {
	for (int i = 0; i < m - 1; ++i) {
		for (int j = i + 1; j < m; ++j) {
			if (sumOfOddElements(matr[i], m) < sumOfOddElements(matr[j], m)) {
				double* temp = matr[i];
				matr[i] = matr[j];
				matr[j] = temp;
			}
		}
	}
}

double sumOfOddElements(double* row, int n) {
	double sum = 0.0;
	for (int j = 0; j < n; ++j) {
		if (j % 2 != 0) {
			sum += row[j];
		}
	}
	return sum;
}

void Task5() {
	int* len = new int[2];
	Len(len);

	double** matr = new double* [len[0]];
	CreateMatrDouble(matr, len[0], len[1]);
	ShowMatrDoubleInfo(matr, len[0], len[1]);
	deleteMatrDouble(matr, len[0]);
}

void ShowMatrDoubleInfo(double** matr, int m, int n) {
	for (int i = 0; i < m; i++) {
		int zero = 0, below = 0, after = 0;
		for (int j = 0; j < n; j++) {
			if (matr[i][j] < 0.0)below++;
			else if (matr[i][j] > 0.0)after++;
			else zero++;
			cout << setw(7) << matr[i][j] << " ";
		}
		cout << endl << "меньше нуля = " << below << ", больше нуля = " << after << ", нулей = " << zero << endl;
	}
}

void Task6() {
	int* len1 = new int[2];
	Len(len1);

	int* len2 = new int[2] {len1[0], 1};

	cout << "1 matrix" << endl;
	double** matr1 = new double* [len1[0]];
	CreateMatrInt(matr1, len1[0], len1[1]);
	ShowMatrInt(matr1, len1[0], len1[1]);


	cout << endl << endl << "vector" << endl;

	double** matr2 = new double* [len2[0]];
	CreateMatrInt(matr2, len2[0], len2[1]);
	ShowMatrInt(matr2, len2[0], len2[1]);


	cout << endl << endl << "mult matrix" << endl;

	double** multMatr = new double* [len1[0]];
	MultMatr(matr1, len1[0], len1[1], len2[1], matr2, multMatr);
	ShowMatrInt(multMatr, len1[0], len2[1]);


	deleteMatrInt(multMatr, len1[0]);
	deleteMatrInt(matr2, len2[0]);
	deleteMatrInt(matr1, len1[0]);
}

void Task7() {
	int* len1 = new int[2];
	Len(len1);

	int* len2 = new int[2];
	Len(len2);

	if (len1[1] != len2[0]) {
		cout << "Такие матрицы нельзя перемножить";
		return;
	}

	cout << "1 matrix" << endl;
	int** matr1 = new int* [len1[0]];
	CreateMatrDouble(matr1, len1[0], len1[1]);
	ShowMatrDouble(matr1, len1[0], len1[1]);


	cout << endl << endl << "2 matrix" << endl;

	int** matr2 = new int* [len2[0]];
	CreateMatrDouble(matr2, len2[0], len2[1]);
	ShowMatrDouble(matr2, len2[0], len2[1]);


	cout << endl << endl << "mult matrix" << endl;

	int** multMatr = new int* [len1[0]];
	MultMatr(matr1, len1[0], len1[1], len2[1], matr2, multMatr);
	ShowMatrDouble(multMatr, len1[0], len2[1]);


	deleteMatrDouble(multMatr, len1[0]);
	deleteMatrDouble(matr2, len2[0]);
	deleteMatrDouble(matr1, len1[0]);
}

void MultMatr(double** matr1, int m1, int nm, int n2, double** matr2, double** multMatr) {
	for (int i = 0; i < m1; i++)
		multMatr[i] = new int[n2];

	for (int i = 0; i < m1; ++i)
		for (int j = 0; j < n2; ++j)
			multMatr[i][j] = 0.0;

	for (int i1 = 0; i1 < m1; i1++) {
		for (int j1 = 0; j1 < n2; j1++) {
			multMatr[i1][j1] = 0;
			for (int i = 0; i < nm; i++) {
				multMatr[i1][j1] += matr1[i1][i] * matr2[i][j1];
			}
		}
	}
}

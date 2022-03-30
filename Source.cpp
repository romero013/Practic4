#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

template <typename T> void showArray(T arr[], int length);
template <typename T> void clearArray(T arr[], int length, T a);
int indexSum(int arr1[], int length1, int arr2[], int length2, int a);
void primeRange(int a, int b);
template <typename T> T maxSum(T arr[], int n);

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n, m;

	// ������ 1
	cout << "������ 1.\n����������� ������:\n";
	int z1[10] = { 2, 5, 8, 4, 6, 3, 1, 2, 9, 2 };
	showArray(z1, 10);
	clearArray(z1, 10, 2);
	showArray(z1, 10);
	cout << endl;

	//������ 2
	cout << "������ 2\n����������� �������:\n";
	int z21[9] = { 11, 20, 5, 26, 7, 38, 9, 5, 40 };
	int z22[10] = { 57, 7, 8, 94, 65, 33, 2, 15, 4, 7 };
	showArray(z21, 9);
	showArray(z22, 10);
	cout << "������� ������ �������� ��������: ";
	cin >> n;
	cout << indexSum(z21, 9, z22, 10, n) << "\n\n";
		
	// ������ 3
	cout << "������ 3.\n";
	int z3[10] = { 2, 5, 8, 4, 6, 3, 10, 2, 11, 2 };
	showArray(z3, 10);
	cout << "����� ���� ������������ ��������� = " << maxSum(z3, 10) << "\n\n";
	
	// ������ 4
	cout << "������ 4.\n������� ������ � ����� ���������: ";
	cin >> n >> m;
	primeRange(n, m);
	cout << endl;


	return 0;
}
// ������ 1
template <typename T> void clearArray(T arr[], int length, T a) {
	for (int i = 0; i < length; i++)
		if (arr[i] == a)
			arr[i] = 0;
}
// ������ 2
int indexSum(int arr1[], int length1, int arr2[], int length2, int a) {
	int num1, num2;
	if (a > length1 - 1 || a > length2 - 1 || a < 0) {
		cout << "ERROR!\n";
		return 0;
	}
	for (int i = 0; i < length1; i++)
		if (i == a)
			num1 = arr1[i];
	for (int i = 0; i < length2; i++)
		if (i == a)
			num2 = arr2[i];
	cout << "����� ��������� ��������� �������� ��� �������� " << a << " = ";
	return num1 + num2;	
}
// ������ 3
template <typename T> T maxSum(T arr[], int length) {
	// ������� ��������
	int max = arr[0];
	for (int i = 0; i < length; i++) 
		if (arr[i] > max)
			max = arr[i];
	// �������� �� ������� ���� ���������� ����������
	int count = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] == max)
			count++;
	if (count == 2)
		return max * 2;
	// ���� ��������� ������
	for (int i = 0; i < length; i++) 
		if (arr[i] == max)
			arr[i] = 0;
	int max1 = arr[0];
	for (int i = 0; i < length; i++)
		if (arr[i] > max1)
			max1 = arr[i];
	return max + max1;
}
// ������ 4
void primeRange(int a, int b) {
	if (a > b)
		cout << "ERROR!\n";
	for (int i = a; i <= b; i++) {
		int count = 1;
		for (int j = 1; j <= i / 2; j++)
			if (i % j == 0)
				count++;
			if (count ==2)
				cout << i << " ";
	}	
}
// ����� �������
template <typename T> void showArray(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
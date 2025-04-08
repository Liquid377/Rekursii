#pragma once
#include "my.cpp"



string GpFile(int i) {
	string File;

	cout << endl << "������� �������� ������ �����(�� ��������� output.txt)." << endl;
	if (i == 1)
		cout << "��� ������� '1', ���� ������ ������� ����� ����." << endl;
	cout << endl << "����: ";
	getline(cin, File);
	if (File == "") {
		File = "output.txt";
	}
	if (File == "1") {
		cout << "������� �������� �������� �����(�� ��������� output.txt): ";
		getline(cin, File);
		if (File == "") {
			File = "output.txt";
		}
		ofstream file(File);
		cout << "���� ������� ������." << endl << endl;
	}

	return File;
}

void ReadFromFile(string pFile) {
	ifstream file(pFile);
	string sFile;

	if (!file) {
		cout << endl << "����� � ����� ��������� �� ����������. ���������� ���." << endl;
		pFile = GpFile(1);
		ReadFromFile(pFile);
	}
	file >> sFile;

	if (sFile == "") {
		cout << "���� ����." << endl << endl;
	} else
		cout << "���������� �����: " << endl <<sFile << endl << endl;
}

double CalculateSumHelper(int k, double previous, double current) {
	double currentSquare = current * current;
	double sum = 0;

	if (k == 1) {
		if (currentSquare <= 2) {
			sum += currentSquare;
		}
	}
	else {
		double prevSquare = previous * previous;
		if (currentSquare <= 2) {
			sum += currentSquare;
		}
		sum += CalculateSumHelper(k - 1, current, 2 * current - previous);
	}

	return sum;
}

double CalculateSum(int k) {
	double previous = cos(1) * cos(1);
	double current = -(sin(1) * sin(1));

	return CalculateSumHelper(k, previous, current);
}

double Check(int k){
	double previous = cos(1) * cos(1);
	double current = -(sin(1) * sin(1));
	double sum = 0;

	for (int i = 1; i <= k; i++) {
		double currentSquare = current * current;
		if (currentSquare <= 2) {
			sum += currentSquare;
		}

		double next = 2 * current - previous;
		previous = current;
		current = next;
	}

	return sum;
}

void WriteInFile(string path, string sString) {
	ofstream file(path);
	file << sString;
	cout << endl << "��������� '" << sString << "' ������� � ����." << endl << endl;
}

void about() {
	cout << "���������: '��������'" << endl;
	cout << "������: 1.0" << endl;
	cout << "���: 2023" << endl;
	cout << "�����������: �������� �.�." << endl;
	cout << "������: ���� - 1301" << endl << endl;
}

void help() {
	cout << "��������� ������� ����� ��������� a[1],..., a[100], ������� ������ ���� � ���������� �������� �������." << endl;
	cout << "a[0] = Cos(1) * Cos(1)" << endl;
	cout << "a[1] = -(Sin(1) * Sin(1))" << endl;
	cout << "a[k] = 2 * a[k-1] - a[k-2]" << endl;
	cout << "k = 2,3,..." << endl;
}

int iMenu() {
	system("cls");
	string input;
	int i;
	bool valid = false;

	cout << "����:" << endl;
	cout << "1. ��������� ������� ����������� ��������." << endl;
	cout << "2. ��������� ���������� �������� � ������." << endl;
	cout << "3. �������� ���������� � ����." << endl;
	cout << "4. ������� ���������� �� �����." << endl;
	cout << "5. � ���������." << endl;
	cout << "6. ������." << endl;
	cout << "7. �����." << endl;
	cout << "�������� ����� ����: ";

	while (valid == false) {
		try {
			getline(cin, input);
			i = stoi(input);
			if (i >= 1 && i <= 7) {
				valid = true;
			}
		}
		catch (...) {
			cout << endl << endl << "������������ ����. ���������� ���! " << endl;
			cout << "�������� ����� ����: ";
		}
	}
	return i;
}
#pragma once
#include "my.cpp"



string GpFile(int i) {
	string File;

	cout << endl << "Введите название вашего файла(по умолчанию output.txt)." << endl;
	if (i == 1)
		cout << "Или введите '1', если хотите создать новый файл." << endl;
	cout << endl << "Ввод: ";
	getline(cin, File);
	if (File == "") {
		File = "output.txt";
	}
	if (File == "1") {
		cout << "Введите желаемое название файла(по умолчанию output.txt): ";
		getline(cin, File);
		if (File == "") {
			File = "output.txt";
		}
		ofstream file(File);
		cout << "Файл успешно создан." << endl << endl;
	}

	return File;
}

void ReadFromFile(string pFile) {
	ifstream file(pFile);
	string sFile;

	if (!file) {
		cout << endl << "Файла с таким названием не существует. Попробуйте ещё." << endl;
		pFile = GpFile(1);
		ReadFromFile(pFile);
	}
	file >> sFile;

	if (sFile == "") {
		cout << "Файл пуст." << endl << endl;
	} else
		cout << "Содержимое файла: " << endl <<sFile << endl << endl;
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
	cout << endl << "Результат '" << sString << "' записан в файл." << endl << endl;
}

void about() {
	cout << "Программа: 'Рекурсия'" << endl;
	cout << "Версия: 1.0" << endl;
	cout << "Год: 2023" << endl;
	cout << "Разработчик: Хусаинов А.С." << endl;
	cout << "Группа: ИНБб - 1301" << endl << endl;
}

void help() {
	cout << "Программа считает сумму квадратов a[1],..., a[100], которые меньше двух в изначально заданной функции." << endl;
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

	cout << "Меню:" << endl;
	cout << "1. Выполнить задание рекурсивной функцией." << endl;
	cout << "2. Проверить результаты функцией с циклом." << endl;
	cout << "3. Записать результаты в файл." << endl;
	cout << "4. Вывести результаты из файла." << endl;
	cout << "5. О программе." << endl;
	cout << "6. Помощь." << endl;
	cout << "7. Выход." << endl;
	cout << "Выберите пункт меню: ";

	while (valid == false) {
		try {
			getline(cin, input);
			i = stoi(input);
			if (i >= 1 && i <= 7) {
				valid = true;
			}
		}
		catch (...) {
			cout << endl << endl << "Некорректный ввод. Попробуйте ещё! " << endl;
			cout << "Выберите пункт меню: ";
		}
	}
	return i;
}
#include "my.h"

int main()
{ 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int iM;
	double res{};
	string sFile;
	do {
		iM = iMenu();
		switch (iM) {
			case 1:
				system("cls");
				res = CalculateSum(100);
				cout << endl << "Сумма равна = " << res << endl << endl;
				system("pause");
				break;
			case 2:
				system("cls");
				res = Check(100);
				cout << endl << "Сумма равна = " << res << endl << endl;
				system("pause");
				break;
			case 3: 
				system("cls");
				if (res == 0) {
					res = CalculateSum(100);
					cout << "Вы не выполнили первый пункт, поэтому программа выполнила его автоматически." << endl;
				}
				sFile = GpFile(2);
				WriteInFile(sFile, to_string(res));
				system("pause");
				break;
			case 4:
				system("cls");
				sFile = GpFile(1);
				ReadFromFile(sFile);
				system("pause");
				break;
			case 5:
				system("cls");
				about();
				system("pause");
				break;
			case 6:
				system("cls");
				help();
				system("pause");
				break;
			case 7:
				system("cls");
				cout << endl << "Программа завершила свою работу." << endl << endl;
		}
	} while (iM != 7);

}

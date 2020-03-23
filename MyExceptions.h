#pragma once
#include <iostream>
#include <Windows.h>
#include "ColorCout.h"
using namespace std;


class Exception {
public: 
	virtual void error(string error_text) {
		ColorCout::write("!!! ", RED);
		cout << error_text << endl;
	}
};

class InvalidValueException : public Exception {
public: void what() { error("Ошибка. Проверьте правильность введенных данных"); }
};
class InvalidSpeed : public Exception {
public: void what() { error("Недопустимое значение скорости"); }
};
class InvalidName : public Exception {
public: void what() { error("Недопустимое название\nИмя не должно содержать символы \'_\', \n"); }
};
class InvalidCost : public Exception {
public: void what() { error("Недопустимая цена"); }
};
class InvalidMass : public Exception {
public: void what() { error("Недопустимое значение массы"); }
};
class InvalidObject : public Exception {
public: void what() { error("Не удалось создать обьёкт. Недопустимые данные\n"); }
};
class MenuError : public Exception {
public: void what() throw (Exception) { error("Ошибка меню. НА ПРАКТИКЕ ЭТО НЕВОЗМОЖНО\n");  throw Exception(); }
};

class BadAllocExit : public Exception
{
	BadAllocExit()
	{
		error("НЕТ ДОСТУПА К ПАМЯТИ! АВТОМАТИЧЕСКОЕ ЗАКРЫТИЕ ПРОГРАММЫ ЧЕРЕЗ\n3...\n");
		Sleep(1000);
		cerr << "2...\n";
		Sleep(1000);
		cerr << "1...\n";
		Sleep(1000);
		exit(0);
	}
};
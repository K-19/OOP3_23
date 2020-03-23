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
public: void what() { error("������. ��������� ������������ ��������� ������"); }
};
class InvalidSpeed : public Exception {
public: void what() { error("������������ �������� ��������"); }
};
class InvalidName : public Exception {
public: void what() { error("������������ ��������\n��� �� ������ ��������� ������� \'_\', \n"); }
};
class InvalidCost : public Exception {
public: void what() { error("������������ ����"); }
};
class InvalidMass : public Exception {
public: void what() { error("������������ �������� �����"); }
};
class InvalidObject : public Exception {
public: void what() { error("�� ������� ������� ������. ������������ ������\n"); }
};
class MenuError : public Exception {
public: void what() throw (Exception) { error("������ ����. �� �������� ��� ����������\n");  throw Exception(); }
};

class BadAllocExit : public Exception
{
	BadAllocExit()
	{
		error("��� ������� � ������! �������������� �������� ��������� �����\n3...\n");
		Sleep(1000);
		cerr << "2...\n";
		Sleep(1000);
		cerr << "1...\n";
		Sleep(1000);
		exit(0);
	}
};
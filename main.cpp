#include <iostream>
#include <locale.h>
#include <Windows.h>
#include <conio.h>
#include "Gym.h"
#include "RunningTrack.h"
#include "WeightTrainer.h"
#include "Menu.h"

void term_func();

int main()
{
    setlocale(LC_ALL, "rus");
    system("chcp 1251");
    system("cls");
    set_terminate(term_func);

    cout << "\t..:: Лабораторная работа 3  ~  СПОРТЗАЛ ::..\n\n" << endl;
    Sleep(1000);
    Gym* gym = NULL;
    
    vector<string> pMenu{ "Создать спортзал", "Выход из программы" };
    try {
        switch (Menu::out(pMenu))
        {
        case 1: gym = new Gym();
            gym->controlMenu();
            break;
        case 2: break;
        default: throw MenuError();
        }
    }
    catch (MenuError exc)
    {
        exc.what();
    }
   
    return 0;
}

void term_func()
{
    cout << "Работает пользовательская функция завершения" << endl;
    Sleep(1000);
    abort();
}
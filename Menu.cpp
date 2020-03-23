#include "Menu.h"
#include <conio.h>

int Menu::out(vector<string> pMenu)
{
    int key = 1, code = 0, enter13 = 0;
    do {
        system("cls");
        for (int i = 1; i <= pMenu.size(); i++)
        {
            if (key == i) {
                ColorCout::write(">> ", GREEN);
                cout << pMenu[i - 1] << endl;
            }
            else cout << pMenu[i - 1] << endl;
        }
        enter13 = _getch();
        if (enter13 == 13) break;
        code = _getch();
        if (code == 80)
        {
            key++;
            if (key > pMenu.size()) key = 1;
        }
        if (code == 72)
        {
            key--;
            if (key < 1) key = pMenu.size();
        }
    } while (true);
    return key;
}

static int outTitle(vector<string> pMenu, string title)
{
    cout << title;
    Menu::outWithoutCls(pMenu);
}

int Menu::outWithoutCls(vector<string> pMenu)
{
    int key = 1, code = 0, enter13 = 0;
    do {
        for (int i = 1; i <= pMenu.size(); i++)
        {
            if (key == i) {
                ColorCout::write(">> ", GREEN);
                cout << pMenu[i - 1] << endl;
            }
            else cout << pMenu[i - 1] << endl;
        }
        enter13 = _getch();
        if (enter13 == 13)
        {
            system("cls");
            break;
        }
        code = _getch();
        if (code == 80)
        {
            key++;
            if (key > pMenu.size()) key = 1;
        }
        if (code == 72)
        {
            key--;
            if (key < 1) key = pMenu.size();
        }
        system("cls");
    } while (true);
    return key;
}
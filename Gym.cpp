#include "Gym.h"
#include <conio.h>
#include <ctime>

Gym::Gym()
{
    setName();
}

Gym::Gym(string name) : name(name)
{
	
}

void Gym::setTrainers(vector<TrainingApparat*> newTrainers)
{
    trainers = newTrainers;
}

int Gym::controlMenu()
{
    Settings settings(DEC, FIX, false, EMPTY);
    vector<string> pMenu{ "Информация о тренажёрах", "Добавить новый тренажёр", "Удалить тренажёр", "Автозаполнение спортзала :)", "Выход из программы" };
    do {
        switch (Menu::out(pMenu))
        {
        case 1: formationMenu(settings); break;
        case 2: addTrainer(); break;
        case 3: deletedMenu(); break;
        case 4: AutoFill(); break;
        case 5: return 0;
        default: throw MenuError();
        }
    } while (true);
}

void Gym::changeBase(Settings& settings)
{
    if (settings.getBase() == DEC) settings.setBase(OCT);
    else if (settings.getBase() == OCT) settings.setBase(HEX);
    else if (settings.getBase() == HEX) settings.setBase(DEC);
}

void Gym::changeFormat(Settings& settings)
{
    if (settings.getFormat() == FIX) settings.setFormat(SCIENTIFIC);
    else if (settings.getFormat() == SCIENTIFIC) settings.setFormat(FIX);
}

void Gym::changePlus(Settings& settings)
{
    if (settings.getPlus() == true) settings.setPlus(false);
    else if (settings.getPlus() == false) settings.setPlus(true);
}

void Gym::changeFchar(Settings& settings)
{
    if (settings.getFchar() == EMPTY) settings.setFChar(CHPOINT);
    else if (settings.getFchar() == CHPOINT) settings.setFChar(EMPTY);
}

int Gym::formationMenu(Settings& settings)
{
    system("cls");
    int key = 1;
    vector<string> pMenu{ "Система счисления", "Форма вывода чисел", "Плюс перед положительными числами", "Символ заполнения :)", "Назад"};
    do {
        switch (showTablica(pMenu, settings, key))
        {
        case 1: Gym::changeBase(settings); break;
        case 2: Gym::changeFormat(settings); break;
        case 3: Gym::changePlus(settings); break;
        case 4: Gym::changeFchar(settings); break;
        case 5: return 0;
        default: throw MenuError();
        }
        //system("cls");
    } while (true);
}

int Gym::deletedMenu()
{
    do {
    vector<string> pMenu;
    for (int i = 0; i < trainers.size(); i++)
    {
        string temp;
        if (trainers[i]->getType() == RUN) temp = "Беговая дорожка \"";
        else if (trainers[i]->getType() == WEIGHT) temp = "Силовой тренажёр \"";
        temp += trainers[i]->getName();
        temp += "\"";
        pMenu.push_back(temp);
    }
    pMenu.push_back("Назад");
    system("cls");
    cout << "Выберите из списка тренажёр, подлежащий удалению\n" << endl;
    int key = Menu::outWithoutCls(pMenu);
    if (key == pMenu.size()) break;
    key--;
    vector<TrainingApparat*> newTrainers;
    for (int i = 0; i < trainers.size(); i++)
    {
        if (i != key) newTrainers.push_back(trainers[i]);
        else {
            cout << endl;
            if (trainers[i]->getType() == RUN) cout << "Беговая дорожка \"";
            else if (trainers[i]->getType() == WEIGHT) cout << "Силовой тренажёр \"";
            ColorCout::write(trainers[i]->getName(), GREEN);
            cout << "\" был";
            if (trainers[i]->getType() == RUN) cout << "а";
            ColorCout::write(" удален", RED);
            if (trainers[i]->getType() == RUN) ColorCout::writeln("а", RED);
            cout << endl;
            system("pause");
        }
    }
    setTrainers(newTrainers);
    } while (true);
    return 0;
}

void Gym::showFullInfo(Settings settings)
{
    cout << setfill(' ');
    cout.width(60);
    cout.setf(ios::right, ios::adjustfield);
    ColorCout::writeln("Инвентарь спортзала \"" + getName() + "\"", YELLOW);
    cout.width(20);
    cout.setf(ios::left, ios::adjustfield); ColorCout::write("Тренажёр", GREEN);
    cout.width(20);  ColorCout::write("Название", GREEN);
    cout.width(20);  ColorCout::write("Цена", GREEN);
    cout.width(25);  ColorCout::writeln("Макс. нагрузка", GREEN);
    for (int i = 0; i < trainers.size(); i++)
    {
        if (trainers[i]->getType() == RUN)
        {
            ((RunningTrack*)trainers[i])->showTablInfo(settings);
        }
    }
    for (int i = 0; i < trainers.size(); i++)
    {
        if (trainers[i]->getType() == WEIGHT)
        {
        ((WeightTrainer*)trainers[i])->showTablInfo(settings);
        }
    }
    cout << endl;
}

int Gym::showTablica(vector<string> pMenu, Settings& settings, int& key)
{
    int code = 0, enter13 = 0;
    do {
        showFullInfo(settings);
        for (int i = 1; i <= pMenu.size(); i++)
        {
            if (key == i) {
                ColorCout::write(">> ", GREEN);
                if (i != 3) cout << pMenu[i - 1];
                else {
                    if (settings.getPlus()) ColorCout::write(pMenu[(long)i - 1], GREEN);
                    else ColorCout::write(pMenu[(long)i - 1], RED);
                }
            }
            else {
                if (i != 3) cout << pMenu[i - 1];
                else {
                    if (settings.getPlus()) ColorCout::write(pMenu[(long)i - 1], GREEN);
                    else ColorCout::write(pMenu[(long)i - 1], RED);
                }
            }
            if (i == 1)
            {
                string strbase;
                if (settings.getBase() == DEC) strbase = "\tДесятичный";
                if (settings.getBase() == OCT) strbase = "\tВосьмиричный";
                if (settings.getBase() == HEX) strbase = "\tШестнадцатиричный";
                ColorCout::writeln(strbase, GREEN);
            }
            else if (i == 2)
            {
                string strformat;
                if (settings.getFormat() == FIX) strformat = "\tДесятичный";
                if (settings.getFormat() == SCIENTIFIC) strformat = "\tЭкспоненциальный";
                ColorCout::writeln(strformat, GREEN);
            }
            else if (i == 4)
            {
                string strfchar;
                if (settings.getFchar() == EMPTY) strfchar = "\t\" \"";
                if (settings.getFchar() == CHPOINT) strfchar = "\t\".\"";
                ColorCout::writeln(strfchar, GREEN);
            }
            else cout << endl;
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

string Gym::setName()
{
    int except;
    do
    {
        except = 0;
        string newName;
        try {
            system("cls");
            cout << "Придумайте название спортзала: ";
            // cin >> newName;
            getline(cin, newName);
            for (int i = 0; i < newName.length(); i++)
            {
                if (newName.at(i) == '_') throw InvalidName();
            }
        }
        catch (InvalidName exc) {
            exc.what();
            except = 1;
        }
        setName(newName);
    } while (except);
    return name;
}

string Gym::setName(string newName)
{
    string finalName = newName;
    for (int j = 1; finalName.at(finalName.length() - 1) == ' '; j++)
    {
        finalName = "";
        for (int i = 0; i < newName.length() - j; i++) finalName += newName.at(i);
    }
	return this->name = finalName;
}

string Gym::getName()
{
	return this->name;
}

TrainingApparat* Gym::addTrainer()
{
    system("cls");
    int flagType = 0;
    vector<string> pMenu{ "Беговая дорожка", "Силовой тренажёр" };
    try {
        switch (Menu::out(pMenu))
        {
        case 1: flagType = 1;
            break;
        case 2: flagType = 2;
            break;
        default: throw MenuError();
        }
    }
    catch (MenuError exc) {
        exc.what();
    }

    cout << "Введите ";
    ColorCout::write("название", GREEN);
    cout << " тренажёра: ";
    string newName;
    int except;
    do
    {
        except = 0;
        try {
            cin >> newName;
            if (!cin.good()) throw InvalidValueException();
        }
        catch (InvalidValueException exc) {
            exc.what();
            except = 1;
        }
    } while (except);
    cout << "Укажите ";
    if (flagType == 1)
        ColorCout::write("максимальную скорость", GREEN);
    else if (flagType == 2)
        ColorCout::write("максимальную нагрузку", GREEN);
    cout << " тренажёра: ";

    float Nagryzka;
    int flag;
    do {
        flag = 0;
        try {
            cin >> Nagryzka;

            if (!cin.good()) throw InvalidValueException();
            if (Nagryzka < 0) {
                if (flagType == 1) throw InvalidSpeed();
                else if (flagType == 2) throw InvalidMass();
            }
            cin.clear();
            cin.ignore(10, '\n');
        }
        catch (InvalidSpeed exc)
        {
            exc.what();
            flag = 1;
        }
        catch (InvalidMass exc)
        {
            exc.what();
            flag = 1;
        }
        catch (InvalidValueException exc)
        {
            exc.what();
            cin.clear();
            cin.ignore(10, '\n');
            flag = 1;
        }
    } while (flag);

    cout << "Введите ";
    ColorCout::write("стоимость", GREEN);
    cout << " тренажёра: ";
    float newCost;
    do {
        flag = 0;
        try {
            cin >> newCost;

            if (!cin.good()) throw InvalidValueException();
            if (newCost < 0) throw InvalidCost();
            cin.clear();
            cin.ignore(10, '\n');
        }
        catch (InvalidCost exc)
        {
            exc.what();
            flag = 1;
        }
        catch (InvalidValueException exc)
        {
            exc.what();
            cin.clear();
            cin.ignore(10, '\n');
            flag = 1;
        }
    } while (flag);
    TrainingApparat* newTrainer = NULL;
    
    if (flagType == 1) newTrainer = new RunningTrack(Nagryzka, newCost, newName);
    else if (flagType == 2) newTrainer = new WeightTrainer(Nagryzka, newCost, newName);
    addTrainer(newTrainer);
    system("pause");
    return newTrainer;
}

TrainingApparat* Gym::addTrainer(TrainingApparat* trainer)
{
	trainers.push_back(trainer);
    cout << "В тренажёрный зал \"";
    ColorCout::write(this->getName(), GREEN);
    cout << "\" добавлен тренажёр \"";
    ColorCout::write(trainer->getName(), GREEN);
    cout << "\"" << endl << endl;
    //system("pause");
	return trainer;
}

vector<TrainingApparat*> Gym::getAllTrainers()
{
	return trainers;
}




float Gym::getCostAllTrainers()
{
	float all = 0;
	for (int i = 0; i < trainers.size(); i++)
	{
		all += trainers[i]->getCost();
	}
	return all;
}

void Gym::AutoFill()
{
    vector<TrainingApparat*> empty;
    trainers = empty;
    system("cls");
    cout << "Сколько: ";
    int how;
    cin >> how;
    vector<string> names{ "Сила", "Лакоста", "Босс", "Сибирь", "Bosh", "Strong", "Power", "ЗИЛ", "АвтоВАЗ" };
    vector<string> numbers{ "1000", "1000M", "1100XXL", "1500", "1500M", "1500 Premium", "2000", "3000", "3000M", "3000M+" };
    for (int i = 0; i < how; i++) {
        srand(time(0) + i);
        float nagryzka = (rand() % 31 + 10) * 10;
        float newCost = (rand() % 901 + 100) * 10;
        int randInt = rand() % names.size();
        string newName(names[randInt]);
        newName += "-";
        randInt = rand() % numbers.size();
        newName += numbers[randInt];
        randInt = rand() % 2;
        TrainingApparat* newTrainer = NULL;
        if (randInt == 0) newTrainer = new RunningTrack(nagryzka, newCost, newName);
        else if(randInt == 1) newTrainer = new WeightTrainer(nagryzka, newCost, newName);
        addTrainer(newTrainer);
    }


}
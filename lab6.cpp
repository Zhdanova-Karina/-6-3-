#pragma warning(disable : 4996)
#define CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "string.h"
#include <locale.h>
#include <conio.h>
#include <stdexcept>
#include <sstream> 

#include <stdio.h>

using namespace std;

#define MAX_DALMATIANS 4
#define MAX_PLACE 5

class Dalmatian;
class Cage;
class Game;
class PlaceWithDalmatian;
class Level;

class Dalmatian {
private:
    string name;
public:
    Dalmatian() {}
    Dalmatian(string name) {
        this->name = name;
    }

    string getName() { return name; }

};

// Базовый класс
class PlaceWithDalmatian {
protected:
    string name;
    bool existDalmatian;

public:
    Dalmatian dalmatian;

    // Конструктор по умолчанию
    PlaceWithDalmatian() : name(""), existDalmatian(false), dalmatian("") {}

    // Конструктор с параметрами
    PlaceWithDalmatian(string name, Dalmatian dalmatian, bool trueORfalse)
        : name(name), existDalmatian(trueORfalse), dalmatian(dalmatian) {}

    // Конструктор для задания имени и наличия далматинца
    PlaceWithDalmatian(string name, bool trueORfalse)
        : name(name), existDalmatian(trueORfalse) {}

    string getName() { return name; }
    bool getExistDalmatian() { return existDalmatian; }
    void setExistDalmatian(bool existDalamtian) { this->existDalmatian = existDalamtian; }

    // Метод, который будет перегружен в производном классе
    virtual void display() {
        cout << "Место: " << name << (existDalmatian ? " (далматинец есть)" : " (далматинца нет)") << endl;
    }
    // Перегрузка оператора присваивания
    PlaceWithDalmatian& operator=(const PlaceWithDalmatian& other) {
        if (this != &other) {
            name = other.name;
            existDalmatian = other.existDalmatian;
            dalmatian = other.dalmatian; // Предполагается, что оператор присваивания перегружен в Dalmatian
        }
        return *this;
    }
};

class Cage: public PlaceWithDalmatian {
private:
    string answer;
public:
    Cage() {}
    Cage(string answer) {
        this->answer = answer;
    }
    // Конструктор с параметрами, вызывающий конструктор базового класса
    Cage(string name, Dalmatian dalmatian, bool trueORfalse, string answer)
        : PlaceWithDalmatian(name, dalmatian, trueORfalse), answer(answer) {}
    // Перегрузка оператора присваивания
    Cage& operator=(const Cage& other) {
        if (this != &other) {
            PlaceWithDalmatian::operator=(other); // Вызов оператора присваивания базового класса
            answer = other.answer;
        }
        return *this;
    }


    int getHintForCode();
    void CodeOfCage(Level& level, Game& game, int number);

    string getAnswerCode() { return answer; }
    // Перегрузка метода display() с вызовом метода базового класса
    void display() override {
        PlaceWithDalmatian::display(); // Вызов метода базового класса
        cout << "Ответ для клетки: " << answer << endl;
    }

    // Перегрузка метода display() без вызова метода базового класса
    void display(string additionalInfo) {
        cout << "Дополнительная информация: " << additionalInfo << endl;
    }

};

class Game {
private:
    static int countDalmatinsFound;
public:

    static int getCountDalmatins() { return countDalmatinsFound; }
    void PlusOne() { countDalmatinsFound++; }
    void Play();
    void printCompliments();
    int StartPlay();
    void PrintRepeatInput();
};

class Level {
private:
    string name;
    int countDalmatins, countPlace; //статические переменные

public:
    Dalmatian dalmatians[MAX_DALMATIANS];
    Cage cage;
    PlaceWithDalmatian place[2][MAX_PLACE];
    Level(bool level, string name, int countDalmatins, int countPlace) {
        // Инициализация далматинцев
        dalmatians[0] = Dalmatian("Патч");

        // Инциализация места
            this->name = name;
            this->countDalmatins = countDalmatins;
            this->countPlace = countPlace;
            place[1][0] = PlaceWithDalmatian("\n 1. Бочка", dalmatians[0], false);
            place[1][1] = PlaceWithDalmatian("\n 2. Клетка", dalmatians[0], true);
            place[1][2] = PlaceWithDalmatian("\n 3. Шкаф", dalmatians[0], false);

    }

    int getCountDalmatins() { return countDalmatins; }
    int getCountPlace() { return countPlace; }

    string getName() { return name; }

    int PrintLocationPlace(Level& level, int countPlace, int rowIndex);
    void dalmatianFound(Level& level, Game& game, int number, int rowIndex);
    void Level_2(Level& level, Game& game);
    int RangeCheck(int number, int range);
    void ViewingFoundDalmatians(Level& level, Game& game);


};

int Game::countDalmatinsFound = 0;

int main() {
    setlocale(LC_ALL, "RU");
    /*перегрузка метода базового класса в производном классе (с вызовом метода базового класса и без такого вызова)*/
    PlaceWithDalmatian place1("Стадион", true);
    Cage cage1("123");

    // Вызов метода базового класса
    place1.display();

    // Вызов перегруженного метода Cage с вызовом базового класса
    cage1.display();

    // Вызов перегруженного метода Cage без вызова базового класса
    cage1.display("Здесь есть далматинец! Освободите его!");

    /*в конструкторе производного класса с параметрами вызов конструктора базового класса*/
    Dalmatian myDalmatian("Понго");
    Cage myCage("Стадион", myDalmatian, true, "1234");

    cout << "Информация о клетке:" << endl;
    myCage.display();
    // Присваиваем новый объект
    Cage anotherCage;
    anotherCage = myCage; // Используем перегруженный оператор присваивания

    cout << "Информация о клетке после присваивания:" << endl;
    anotherCage.display();

    /*Игра*/
    Game game;
    int start;
    do {
        start = game.StartPlay();
        if (start == 1) {
            game.Play();
        }
        else  if (start == 0) break;
    } while (start < 0);
    cout << "Конец игры" << endl;
    return 0;
}

void Game::printCompliments() {
    cout << "Поздравляем! Уровень пройден!" << endl;
}

int Game::StartPlay() {
    char symbol;
    try {
        cout << "\nНажмите *, чтобы начать игру\n0, чтобы завершить игру\n" << endl;
        symbol = cin.get();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (symbol == '*') {
            return 1; // Начать игру
        }
        else if (symbol == '0') {
            return 0; // Завершить игру
        }
        else {
            throw invalid_argument("Некорректный ввод. Пожалуйста, нажмите * или ESC."); // Генерация исключения для некорректного ввода
        }
    }
    catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl; // Обработка исключения
        return -1; // Вернуть код ошибки
    }
    return -1;
}

void Game::PrintRepeatInput() {
    cout << "Повторите ввод." << endl;
}
void Game::Play() {
    while (true) {
        Level level(false, "Подвал", 1, 3);
        cout << level.getName() << endl;
        level.Level_2(level, *this);
        break;
    }
}

int Level::PrintLocationPlace(Level& level, int countPlace, int rowIndex) {
    int numberPlace;
    if (rowIndex < 0 || rowIndex > 1) {
        cout << "Ошибка: неверный индекс строки." << endl;
        return 1;
    }

    for (int i = 0; i < countPlace; i++) {
        cout << place[rowIndex][i].getName();
    }
    try {

        cout << "\nВведите пункт: ";
        cin >> numberPlace;

        // Проверка на корректность ввода
        if (cin.fail()) {
            cin.clear(); // Сбросить флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорировать оставшиеся символы
            throw invalid_argument("Некорректный ввод. Пожалуйста, введите число.");
        }

        // Дополнительные проверки на разумные значения
        if (numberPlace < 1 || numberPlace > countPlace) {
            ostringstream oss;
            oss << "Число должно быть в диапазоне от 1 до " << countPlace;
            throw out_of_range(oss.str());
        }

    }
    catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl; // Обработка исключения для некорректного ввода
    }
    catch (const out_of_range& e) {
        cout << "Ошибка: " << e.what() << endl; // Обработка исключения для выхода за пределы диапазона
    }
    catch (...) {
        cout << "Неизвестная ошибка." << endl; // Обработка всех других исключений
    }

    return numberPlace;
}

void Level::ViewingFoundDalmatians(Level& level, Game& game) {
    cout << "\nВы нашли " << game.getCountDalmatins() << "/4 далматинцев:" << endl;
    for (int i = 0; i < game.getCountDalmatins(); i++) {
        cout << level.dalmatians[i].getName() << endl;
    }
}

void Level::dalmatianFound(Level& level, Game& game, int number, int rowIndex) {
    if (place[rowIndex][number - 1].getExistDalmatian() == true) {
        place[rowIndex][number - 1].setExistDalmatian(false);
        game.PlusOne();

        ViewingFoundDalmatians(level, game);
    }
    else {
        cout << "Увы, здесь никого нет\n" << endl;
    }
}

int Level::RangeCheck(int number, int range) {
    if (number > 0 && number < range + 1) return 0;
    else return 1;
}
void Level::Level_2(Level& level, Game& game) {
    while (game.getCountDalmatins() < MAX_DALMATIANS) {
        int number;
        number = PrintLocationPlace(level, getCountPlace(), 1);
        if (RangeCheck(number, getCountPlace()) == 0) {
            if (number != 2) dalmatianFound(level, game, number, 1);
            else {
                cout << "\nО нет! Клетка закрыта на замок! Вам нужно отгадать код!" << endl;
                cage.CodeOfCage(level, game, number);
            }
        }
        else game.PrintRepeatInput();
    }
}
int Cage::getHintForCode() {
    string input; // Используем строку для ввода
    try {
        cout << "Нажмите *, чтобы получить подсказку" << endl;
        // Очищаем входной буфер перед считыванием
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Считываем всю строку
        getline(cin, input);

        // Проверяем на пустую строку перед доступом к символам
        if (input.empty()) {
            cout << "Ошибка: Ввод не может быть пустым." << endl; // Проверка пустого ввода
            return -1; // Вернуть код ошибки
        }

        char symbol = input[0]; // Получаем первый символ строки

        if (symbol == '*') {
            cout << "\nКод состоит из трёх символов. Чтобы найти каждый символ вам нужно:\n"
                << "1) перевести число 127 в двоичную, восьмеричную и шестнадцатиричную системы счисления;\n"
                << "2) каждый последний символ будет являться частью кода\n"
                << "Все буквы должны быть заглавными!\n" << endl;

            return 0; // Успешный переход
        }
        else {
            cout << "Ошибка: Некорректный ввод." << endl; // Сообщение об ошибке
            return -1; // Вернуть код ошибки
        }
    }
    catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl; // Обработка исключения
        return -1; // Вернуть код ошибки
    }
}

void Cage::CodeOfCage(Level& level, Game& game, int number) {
    string input;
    Cage cage("17F"); // Например, правильный ответ

    while (true) {
        // Метод получения подсказки
        if (getHintForCode() != 0) {
            continue; // Если ошибка, продолжаем запрашивать подсказку
        }

        // Если подсказка успешно получена, запрашиваем ввод кода
        while (true) {
            cout << "\nВведите код:" << endl;
            getline(cin, input); // Считываем код

            // Проверка на пустой ввод
            if (input.empty()) {
                cout << "Код не может быть пустым. Пожалуйста, попробуйте снова." << endl;
                continue; // Пропустить текущую итерацию цикла
            }

            // Проверка правильности введенного кода
            if (input == cage.getAnswerCode()) {
                cout << "Ура! Вы освободили далматинца!\n" << endl;
                level.dalmatianFound(level, game, number, 1); // Освобождение далматинца
                return; // Успешный выход
            }
            else {
                game.PrintRepeatInput(); // Если код неверен
            }
        }
    }
}

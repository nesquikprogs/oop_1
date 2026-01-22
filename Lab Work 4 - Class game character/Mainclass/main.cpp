#include "GameCharacter.h" // Подключение заголовочного файла с объявлением класса GameCharacter
#include "Warrior.h" // Подключение заголовочного файла с объявлением класса Warrior
#include "Mage.h" // Подключение заголовочного файла с объявлением класса Warrior
#include "Archer.h" // Подключение заголовочного файла с объявлением класса Warrior


#include <iostream> // Подключение библиотеки для работы с вводом и выводом
#include <stdexcept> // Подключение библиотеки для работы с исключениями
#include <string> // Подключение библиотеки для работы со строками
#include <cassert> // Подключение библиотеки для работы с проверками условий
#include <vector> // Подключение библиотеки для работы с вектором

using namespace std; // Использование пространства имён std

// Основная функция программы: выполняет тесты для проверки функциональности класса GameCharacter
int main() {

	setlocale(LC_ALL, "ru"); // Установка локали для вывода русских букв в консоль

    cout << "Тесты для Warrior\n";

    // Создание объекта для тестов
    Warrior warrior("Воин", 120, 3, 20);

    // Тест 1: Геттеры
    assert(warrior.GetName() == "Воин");
    assert(warrior.GetHealth() == 120);
    assert(warrior.GetLevel() == 3);
    assert(warrior.GetStrength() == 20);
    cout << "Тест 1: Геттеры для Warrior - пройден\n";

    // Тест 2: Сеттер для strength с некорректным значением
    bool flag = false;
    try {
        warrior.SetStrength(0);
        assert(false); // assert(false) гарантирует провал теста
    }
    catch (const invalid_argument&) {}
    cout << "Тест 2: Исключение SetStrength для Warrior - пройден\n";

    // Тест 3: DisplayInfo
    string expected = "Имя: Воин\nЗдоровье: 120\nУровень: 3\nСила: 20\n";
    assert(warrior.DisplayInfo() == expected);
    cout << "Тест 3: DisplayInfo для Warrior - пройден\n";

    // Тест 4: TakeDamage (урон уменьшается на strength/2 = 10)
    warrior.TakeDamage(30);
    assert(warrior.GetHealth() == 100);
    cout << "Тест 4: TakeDamage для Warrior - пройден\n";
    
    cout << "\nТесты для Mage\n";

    // Создание объекта для тестов
    Mage mage("Маг", 80, 4, 50);

    // Тест 1: Геттеры
    assert(mage.GetName() == "Маг");
    assert(mage.GetHealth() == 80);
    assert(mage.GetLevel() == 4);
    assert(mage.GetMana() == 50);
    cout << "Тест 1: Геттеры для Mage - пройден\n";

    // Тест 2: Сеттер для mana с некорректным значением
    flag = false;
    try {
        mage.SetMana(-1);
        assert(false); // assert(false) гарантирует провал теста
    }
    catch (const invalid_argument&) {}
    
    cout << "Тест 2: Исключение SetMana для Mage - пройден\n";

    // Тест 3: DisplayInfo
    expected = "Имя: Маг\nЗдоровье: 80\nУровень: 4\nМана: 50\n";
    assert(mage.DisplayInfo() == expected);
    cout << "Тест 3: DisplayInfo для Mage - пройден\n";

    // Тест 4: TakeDamage (мана поглощает урон)
    mage.TakeDamage(30);
    assert(mage.GetHealth() == 80);
    assert(mage.GetMana() == 20);
    cout << "Тест 4: TakeDamage для Mage - пройден\n";

    cout << "\nТесты для Archer\n";

    // Создание объекта для тестов
    Archer archer("Лучник", 90, 2, 15);

    // Тест 1: Геттеры
    assert(archer.GetName() == "Лучник");
    assert(archer.GetHealth() == 90);
    assert(archer.GetLevel() == 2);
    assert(archer.GetAgility() == 15);
    cout << "Тест 1: Геттеры для Archer - пройден\n";

    // Тест 2: Сеттер для agility с некорректным значением
    flag = false;
    try {
        archer.SetAgility(0);
        assert(false); // assert(false) гарантирует провал теста
    }
    catch (const invalid_argument&) {}
    cout << "Тест 2: Исключение SetAgility для Archer - пройден\n";

    // Тест 3: DisplayInfo
    expected = "Имя: Лучник\nЗдоровье: 90\nУровень: 2\nЛовкость: 15\n";
    assert(archer.DisplayInfo() == expected);
    cout << "Тест 3: DisplayInfo для Archer - пройден\n";

    // Тест 4: TakeDamage (учитываем оба исхода из-за рандома)
    int initialHealth = archer.GetHealth();
    archer.TakeDamage(10);
    bool validOutcome = (archer.GetHealth() == initialHealth || archer.GetHealth() == initialHealth - 10);
    assert(validOutcome);
    cout << "Тест 4: TakeDamage для Archer - пройден\n";

    cout << "\nДемонстрация полиморфизма\n";

    // Создание массива указателей на GameCharacter для демонстрации полиморфизма
    vector<GameCharacter*> characters = {
        new Warrior("Воин", 120, 3, 20),
        new Mage("Маг", 80, 4, 50),
        new Archer("Лучник", 90, 2, 15)
    };

    // Вызов методов через указатели для демонстрации полиморфизма
    for (size_t i = 0; i < characters.size(); ++i) {
        cout << "Персонаж " << i + 1 << ":\n" << characters[i]->DisplayInfo() << endl;
        characters[i]->TakeDamage(30);
        cout << "После урона 30:\n" << characters[i]->DisplayInfo() << endl;
    }

    // Очистка памяти
    for (auto* character : characters) {
        delete character;
    }

	return 0;
}



/*

разобраться в этом: - ВЫПОЛНЕНО

GameCharacter* с; 

c = new Warrior;
c->SetHealth(23423); 
c->SetStrength(3453);
c->DisplayInfo(); // срабатывает потому что используем указатель, метод переопределен и метод виртуальный в базовом классе

warrior* w = dynamic_cast<warrior*>(c);
if (w != nullptr) 
    w -> SetStrenght(45);

*/

/*
написать комменты ко всем методам - ВЫПОЛНЕНО
тесты сделать по примеру первого(трайкач сократить) - ВЫПОЛНЕНО
*/


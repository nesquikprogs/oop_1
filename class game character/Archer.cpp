#include "Archer.h" // Подключение заголовочного файла с объявлением класса Archer
#include <cstdlib> // Для rand() в симуляции уклонения
#include <ctime> // Для srand()

#include <string> // Подключение библиотеки для работы со строками

using namespace std; // Использование пространства имён std

// Конструктор по умолчанию: вызывает базовый конструктор и устанавливает ловкость по умолчанию
Archer::Archer() : GameCharacter(), agility(10) {
    srand(time(0)); // Инициализация случайных чисел для уклонения
}

// Конструктор с параметрами: вызывает базовый конструктор и устанавливает ловкость через сеттер
Archer::Archer(const string& initName, int initHealth, int initLevel, int initAgility)
    : GameCharacter(initName, initHealth, initLevel) {
    SetAgility(initAgility);
    srand(time(0)); // Инициализация случайных чисел для уклонения
}

// Геттер: возвращает значение ловкости
int Archer::GetAgility() const {
    return agility;
}

// Сеттер: устанавливает новое значение ловкости с проверкой (ловкость >= 1)
bool Archer::SetAgility(int newAgility) {
    if (newAgility < 1) {
        throw invalid_argument("Ловкость должна быть не меньше 1!");
    }
    agility = newAgility;
    return true;
}

// Переопределённый метод DisplayInfo: добавляет информацию о ловкости к базовой
string Archer::DisplayInfo() const {
    return GameCharacter::DisplayInfo() + "Ловкость: " + to_string(agility) + "\n";
}

// Переопределённый метод TakeDamage: с шансом уклонения (например, если rand() % 20 < agility, урон = 0)
bool Archer::TakeDamage(int damage) {
    if (rand() % 20 < agility) {
        // Уклонение: урон не наносится
        return true;
    }
    else {
        return GameCharacter::TakeDamage(damage);
    }
}
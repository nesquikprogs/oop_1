#include "Warrior.h" // Подключение заголовочного файла с объявлением класса Warrior

#include <string> // Подключение библиотеки для работы со строками

using namespace std; // Использование пространства имён std

// Конструктор по умолчанию: вызывает базовый конструктор и устанавливает силу по умолчанию
Warrior::Warrior() : GameCharacter(), strength(10) {}

// Конструктор с параметрами: вызывает базовый конструктор и устанавливает силу через сеттер для валидации
Warrior::Warrior(const string& initName, int initHealth, int initLevel, int initStrength)
    : GameCharacter(initName, initHealth, initLevel) {
    SetStrength(initStrength);
}

// Геттер: возвращает значение силы
int Warrior::GetStrength() const {
    return strength;
}

// Сеттер: устанавливает новое значение силы с проверкой (сила должна быть не меньше 1)
bool Warrior::SetStrength(int newStrength) {
    // Проверка: сила не может быть меньше 1
    if (newStrength < 1) {
        throw invalid_argument("Сила должна быть не меньше 1!");
    }
    else {
        strength = newStrength; // Установка новой силы
        return true;
    }
}

// Переопределённый метод DisplayInfo: вызывает базовую версию и добавляет информацию о силе
string Warrior::DisplayInfo() const {
    return GameCharacter::DisplayInfo() + "Сила: " + to_string(strength) + "\n";
}

// Переопределённый метод TakeDamage: уменьшает урон на основе силы (strength / 2), затем применяет базовую логику
bool Warrior::TakeDamage(int damage) {
    int reducedDamage = damage - (strength / 2); // Расчёт уменьшенного урона
    if (reducedDamage < 0) reducedDamage = 0; // Урон не может быть отрицательным
    return GameCharacter::TakeDamage(reducedDamage); // Вызов базового метода с уменьшенным уроном
}
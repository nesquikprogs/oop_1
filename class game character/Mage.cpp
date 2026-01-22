#include "Mage.h" // Подключение заголовочного файла с объявлением класса Mage

#include <string> // Подключение библиотеки для работы со строками

using namespace std; // Использование пространства имён std

// Конструктор по умолчанию: вызывает базовый конструктор и устанавливает ману по умолчанию
Mage::Mage() : GameCharacter(), mana(30) {}

// Конструктор с параметрами: вызывает базовый конструктор и устанавливает ману через сеттер
Mage::Mage(const string& initName, int initHealth, int initLevel, int initMana)
    : GameCharacter(initName, initHealth, initLevel) {
    SetMana(initMana);
}

// Геттер: возвращает значение маны
int Mage::GetMana() const {
    return mana;
}

// Сеттер: устанавливает новое значение маны с проверкой (мана >= 0)
bool Mage::SetMana(int newMana) {
    if (newMana < 0) {
        throw invalid_argument("Мана не может быть отрицательной!");
    }
    mana = newMana;
    return true;
}

// Переопределённый метод DisplayInfo: добавляет информацию о мане к базовой
string Mage::DisplayInfo() const {
    return GameCharacter::DisplayInfo() + "Мана: " + to_string(mana) + "\n";
}

// Переопределённый метод TakeDamage: если мана >= урона, тратит ману вместо здоровья; иначе применяет базовую логику
bool Mage::TakeDamage(int damage) {
    if (mana >= damage) {
        mana -= damage;
        return true;
    }
    else {
        return GameCharacter::TakeDamage(damage);
    }
}
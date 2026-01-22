// Защита от повторного включения
#ifndef WARRIOR_H
#define WARRIOR_H

#include "GameCharacter.h" // Подключение базового класса для наследования


// при наследовании наследуется всё ...
// Класс Warrior: наследует от GameCharacter, добавляет атрибут силы для специализации поведения
class Warrior : public GameCharacter {
private:
    // Приватное поле класса
    int strength; // Сила воина, влияющая на сопротивление урону и другие механики

public:
    // Конструктор по умолчанию: инициализирует воина с базовыми значениями и силой 10
    Warrior();

    // Конструктор с параметрами: инициализирует воина с заданными значениями, включая силу
    Warrior(const string& initName, int initHealth, int initLevel, int initStrength);

    // Геттер: возвращает значение силы
    int GetStrength() const;

    // Сеттер: устанавливает новое значение силы с проверкой корректности
    bool SetStrength(int newStrength);

    // Переопределённый метод DisplayInfo: возвращает строку с информацией о воине, включая силу
    string DisplayInfo() const override;

    // Переопределённый метод TakeDamage: наносит урон с учётом сопротивления на основе силы
    bool TakeDamage(int damage) override;
};

#endif // WARRIOR_H
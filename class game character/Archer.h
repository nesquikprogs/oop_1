// Защита от повторного включения
#ifndef ARCHER_H
#define ARCHER_H

#include "GameCharacter.h" // Подключение базового класса для наследования

// Класс Archer: наследует от GameCharacter, добавляет атрибут ловкости
class Archer : public GameCharacter {
private:
    // Приватное поле класса
    int agility; // Ловкость лучника, влияющая на шанс уклонения от урона

public:
    // Конструктор по умолчанию: инициализирует лучника с базовыми значениями и ловкостью 10
    Archer();

    // Конструктор с параметрами: инициализирует лучника с заданными значениями, включая ловкость
    Archer(const string& initName, int initHealth, int initLevel, int initAgility);

    // Геттер: возвращает значение ловкости
    int GetAgility() const;

    // Сеттер: устанавливает новое значение ловкости с проверкой корректности
    bool SetAgility(int newAgility);

    // Переопределённый метод DisplayInfo: возвращает строку с информацией о лучнике, включая ловкость
    string DisplayInfo() const override;

    // Переопределённый метод TakeDamage: с шансом уклонения (50% если ловкость > 10), иначе базовая логика
    bool TakeDamage(int damage) override;
};

#endif // ARCHER_H
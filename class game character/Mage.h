// Защита от повторного включения
#ifndef MAGE_H
#define MAGE_H

#include "GameCharacter.h" // Подключение базового класса для наследования

// Класс Mage: наследует от GameCharacter, добавляет атрибут маны
class Mage : public GameCharacter {
private:
    // Приватное поле класса
    int mana; // Мана мага, используемая для защиты от урона

public:
    // Конструктор по умолчанию: инициализирует мага с базовыми значениями и маной 30
    Mage();

    // Конструктор с параметрами: инициализирует мага с заданными значениями, включая ману
    Mage(const string& initName, int initHealth, int initLevel, int initMana);

    // Геттер: возвращает значение маны
    int GetMana() const;

    // Сеттер: устанавливает новое значение маны с проверкой корректности
    bool SetMana(int newMana);

    // Переопределённый метод DisplayInfo: возвращает строку с информацией о маге, включая ману
    string DisplayInfo() const override;

    // Переопределённый метод TakeDamage: использует ману для поглощения урона, если возможно
    bool TakeDamage(int damage) override;
};

#endif // MAGE_H
// защита от повторого включения
#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include <string> // Подключение библиотеки для работы со строками 
#include <stdexcept> // Подключение библиотеки для работы с исключениями (std::invalid_argument)

// Использование пространства имен std только для необходимых объектов
using std::string; 
using std::invalid_argument;

// Класс GameCharacter c атрибутами имени, здоровья и уровня
class GameCharacter {
private:
	// Приватные поля класса
	string name; // Имя персонажа
	int health; // Текущее здоровье персонажа
	int level; // Уровень персонажа

public:
	// Конструктор по умолчанию: создаёт персонажа с именем "Неизвестный", здоровьем 100 и уровнем 1
	GameCharacter();

	// Конструктор с параметрами: создаёт персонажа с заданными именем, здоровьем и уровнем
	GameCharacter(const string& initName, int initHealth, int initLevel);

	// Геттер: возвращает публичное значение имени 
	string GetName() const;

	// Геттер: возвращает публичное значение здоровья
	int GetHealth() const;

	// Геттер: возвращает публичное значение уровня
	int GetLevel() const;

	// Сеттер: устанавливает новое значение для имени с проверкой корректности
	bool SetName(const string& NewName);
	
	// Сеттер: устанавливает новое значение для здоровья с проверкой корректности
	bool SetHealth(int NewHealth);

	// Сеттер: устанавливает новое здоровья для имени с проверкой корректности
	bool SetLevel(int NewLevel);

	// Метод DisplayInfo: возвращает строку с информацией о персонаже
	virtual string DisplayInfo() const; 

	// Метод TakeDamage: уменьшает здоровье персонажа на заданный урон
	virtual bool TakeDamage(int damage); 

};

#endif // GAME_CHARACTER_H
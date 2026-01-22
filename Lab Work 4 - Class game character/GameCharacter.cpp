#include "GameCharacter.h" // Подключение заголовочного файла с объявлением класса GameCharacter

#include <string> // Подключение библиотеки для работы со строками

using namespace std; // Использование пространства имён std 

// Конструктор по умолчанию: инициализирует персонажа значениями по умолчанию
GameCharacter::GameCharacter() : name("Неизвестный"), health(100), level(1) {}

// Конструктор с параметрами: инициализирует персонажа заданными значениями через сеттеры
GameCharacter::GameCharacter(const string& initName, int initHealth, int initLevel) : name("Неизвестный"), health(100), level(1) {
	SetName(initName);
	SetHealth(initHealth);
	SetLevel(initLevel);
}

// Геттер: возвращает публичное значение имени 
string GameCharacter::GetName() const { return name; }

// Геттер: возвращает публичное значение здоровья
int GameCharacter::GetHealth() const { return health; }

// Геттер: возвращает публичное значение уровня
int GameCharacter::GetLevel() const { return level; }

// Сеттер: устанавливает новое значение имени с проверкой (имя не может быть пустым)
bool GameCharacter::SetName(const string& NewName) {
	// Проверка: имя не должно быть пустым
	if (NewName.empty()) {
		throw invalid_argument("Имя не может быть пустым");
	}
	else {
		name = NewName; // Установка нового имени
		return true;
	}
}
// Сеттер: устанавливает новое значение здоровья с проверкой (здорьве > 0)
bool GameCharacter::SetHealth(int NewHealth) {
	// Проверка: здоровье должно быть больше 0
	if (NewHealth <= 0) {
		throw invalid_argument("Показатель здоровья не может быть ниже или ровняться 0!");
	}
	else {
		health = NewHealth; // Установка нового здоровья
		return true;
	}
}
// Сеттер: устанавливает новое значение уровня с проверкой (уровень > 0)
bool GameCharacter::SetLevel(int NewLevel) {
	// Проверка: уровень должен быть не меньше 1
	if (NewLevel < 1) {
		throw invalid_argument("Уровень должен быть не меньше 1!");
	}
	else {
		level = NewLevel; // Установка нового уровня
		return true;
	}
}

// Метод DisplayInfo: возвращает строку с информацией о персонаже
string GameCharacter::DisplayInfo() const {
	return "Имя: " + name + "\nЗдоровье: " + to_string(health) + "\nУровень: " + to_string(level) + "\n";
}

// Метод TakeDamage: уменьшает здоровье персонажа на заданный урон
bool GameCharacter::TakeDamage(int damage) {
	// Проверка: урон должен быть больше 0
	if (damage <= 0) {
		throw invalid_argument("Нанесенный урон не может быть меньше или равен нулю!");
	}
	// Проверка: здоровье не может стать меньше 0
	if (health - damage < 0) {
		throw invalid_argument("Здоровье не может стать меньше нуля!");
	}
	health = health - damage; // Уменьшение здоровья
	return true;
}


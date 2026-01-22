@startuml

' Базовый класс GameCharacter
class GameCharacter {
  -string name
  -int health
  -int level
  +GameCharacter()
  +GameCharacter(string, int, int)
  +GetName() string
  +GetHealth() int
  +GetLevel() int
  +SetName(string) bool
  +SetHealth(int) bool
  +SetLevel(int) bool
  +{virtual}DisplayInfo() string
  +{virtual}TakeDamage(int) bool
}

' Класс Warrior
class Warrior {
  -int strength
  +Warrior()
  +Warrior(string, int, int, int)
  +GetStrength() int
  +SetStrength(int) bool
  +DisplayInfo() string
  +TakeDamage(int) bool
}

' Класс Mage
class Mage {
  -int mana
  +Mage()
  +Mage(string, int, int, int)
  +GetMana() int
  +SetMana(int) bool
  +DisplayInfo() string
  +TakeDamage(int) bool
}

' Класс Archer
class Archer {
  -int agility
  +Archer()
  +Archer(string, int, int, int)
  +GetAgility() int
  +SetAgility(int) bool
  +DisplayInfo() string
  +TakeDamage(int) bool
}

' Наследование
GameCharacter <|-- Warrior
GameCharacter <|-- Mage
GameCharacter <|-- Archer

@enduml

https://www.plantuml.com/plantuml/uml/


Ключевое слово virtual в C++ используется в объявлении методов класса, чтобы указать, что эти методы могут быть переопределены (overridden) в подклассах, 
и что выбор версии метода для вызова будет происходить динамически во время выполнения программы (в runtime), а не статически во время компиляции.
С virtual мы включаем динамический полиморфизм, что делает код гибким и расширяемым.
Virtual позволяет каждому подклассу (Warrior, потенциально Mage, Archer) определять своё поведение для общих методов.
Полиморфизм позволяет вызывать один и тот же метод (по имени) на объектах разных классов, но получать поведение, специфичное для каждого класса
Полиморфизм — это принцип ООП, при котором один и тот же метод, определённый в базовом классе, может выполняться по-разному для объектов разных подклассов, в зависимости от их конкретного типа.
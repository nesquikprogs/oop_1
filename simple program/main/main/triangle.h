#ifndef TRIANGLE_H
#define TRIANGLE_H

// Функция вычисления второго катета по теореме пифагора с аргументами hypotenuse - гипотенуза, leg1 - первый катет
// Возвращает длину второго катета типа double
double calculateLeg(double hypotenuse, double leg1);

// Функция вычисления радиуса вписанной окружности по формуле r = (a + b - c) / 2  с аргументами hypotenuse - гипотенуза, leg1 - первый катит, leg2 - второй катет
// Возвращает радиус вписанной окружности типа double
double calculateRadius(double hypotenuse, double leg1, double leg2);

// Объявляем функцию для выполнения всех проверок
void runAssertions();

#endif // TRIANGLE_H

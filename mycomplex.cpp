#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/**
 * @brief Конструктор комплексного числа.
 * @param aRe Действительная часть (по умолчанию 0).
 * @param aIm Мнимая часть (по умолчанию 0).
 */
Complex::Complex(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}

/**
 * @brief Конструктор копирования.
 * @param aRval Объект, который копируется.
 */
Complex::Complex(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
}

/**
 * @brief Деструктор.
 */
Complex::~Complex() {
    Re = 0.0;
    Im = 0.0;
}

/**
 * @brief Устанавливает новое значение комплексного числа.
 * @param aRe Новая действительная часть.
 * @param aIm Новая мнимая часть (по умолчанию 0).
 */
void Complex::Set(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}

/**
 * @brief Преобразование комплексного числа в число типа double.
 * @return Модуль комплексного числа.
 */
Complex::operator double() {
    return abs();
}

/**
 * @brief Вычисляет модуль комплексного числа.
 * @return Значение модуля.
 */
double Complex::abs() {
    return sqrt(Re * Re + Im * Im);
}

/**
 * @brief Перегруженный оператор сложения для двух комплексных чисел.
 * @param aRval Второе слагаемое.
 * @return Сумма комплексных чисел.
 */
Complex Complex::operator+(const Complex& aRval) {
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im;
    return Result;
}

/**
 * @brief Перегруженный оператор вычитания для двух комплексных чисел.
 * @param aRval Вычитаемое.
 * @return Разность комплексных чисел.
 */
Complex Complex::operator-(const Complex& aRval) {
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

/**
 * @brief Перегруженный оператор сложения комплексного числа и вещественного числа.
 * @param aRval Второе слагаемое (вещественное число).
 * @return Результат сложения.
 */
Complex Complex::operator+(const double& aRval) {
    Complex result;
    result.Re = Re + aRval;
    result.Im = Im;
    return result;
}

/**
 * @brief Перегруженный оператор вычитания вещественного числа из комплексного.
 * @param aRval Вычитаемое вещественное число.
 * @return Результат вычитания.
 */
Complex Complex::operator-(const double& aRval) {
    Complex Result(*this);
    Result.Re = Re - aRval;
    return Result;
}

/**
 * @brief Перегруженный оператор умножения для двух комплексных чисел.
 * @param aRval Множитель.
 * @return Произведение комплексных чисел.
 */
Complex Complex::operator*(const Complex& aRval) {
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}

/**
 * @brief Перегруженный оператор умножения комплексного и вещественного числа.
 * @param aRval Множитель (вещественное число).
 * @return Произведение.
 */
Complex Complex::operator*(const double& aRval) {
    Complex Result;
    Result.Re = Re * aRval;
    Result.Im = Im * aRval;
    return Result;
}

/**
 * @brief Перегруженный оператор деления комплексного числа на вещественное.
 * @param aRval Делитель (вещественное число).
 * @return Частное.
 */
Complex Complex::operator/(const double& aRval) {
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;
}

Complex& Complex::operator+=(const Complex& aRval) {
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}

Complex& Complex::operator-=(const Complex& aRval) {
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

Complex& Complex::operator*=(const Complex& aRval) {
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

Complex& Complex::operator+=(const double& aRval) {
    Re += aRval;
    return *this;
}

Complex& Complex::operator-=(const double& aRval) {
    Re -= aRval;
    return *this;
}

Complex& Complex::operator*=(const double& aRval) {
    Re *= aRval;
    Im *= aRval;
    return *this;
}

Complex& Complex::operator/=(const double& aRval) {
    Re /= aRval;
    Im /= aRval;
    return *this;
}

Complex& Complex::operator=(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

Complex& Complex::operator=(const double& aRval) {
    Re = aRval;
    Im = 0.0;
    return *this;
}

/**
 * @brief Перегруженный оператор ввода.
 * @param stream Входной поток.
 * @param a Комплексное число.
 * @return Ссылка на входной поток.
 */
istream& operator>>(istream& stream, Complex& a) {
    char tmp[256];
    stream >> a.Re >> a.Im >> tmp;
    return stream;
}

/**
 * @brief Перегруженный оператор вывода.
 * @param stream Выходной поток.
 * @param a Комплексное число.
 * @return Ссылка на выходной поток.
 */
ostream& operator<<(ostream& stream, Complex& a) {
    stream << a.Re;
    if (!(a.Im < 0)) stream << '+';
    stream << a.Im << 'i';
    return stream;
}

/**
 * @brief Перегруженный оператор сложения вещественного и комплексного числа.
 * @param aLval Вещественное число.
 * @param aRval Комплексное число.
 * @return Результат сложения.
 */
Complex operator+(const double& aLval, const Complex& aRval) {
    Complex Result;
    Result.Re = aLval + aRval.Re;
    Result.Im = aRval.Im;
    return Result;
}

/**
 * @brief Перегруженный оператор вычитания комплексного числа из вещественного.
 * @param aLval Вещественное число.
 * @param aRval Комплексное число.
 * @return Результат вычитания.
 */
Complex operator-(const double& aLval, const Complex& aRval) {
    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im = -aRval.Im;
    return Result;
}

/**
 * @brief Перегруженный оператор умножения вещественного и комплексного числа.
 * @param aLval Вещественное число.
 * @param aRval Комплексное число.
 * @return Результат умножения.
 */
Complex operator*(const double& aLval, const Complex& aRval) {
    Complex r;
    r.Re = aLval * aRval.Re;
    r.Im = aLval * aRval.Im;
    return r;
}

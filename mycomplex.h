#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_

#include <iostream>

using namespace std;

/**
 * @brief Класс для работы с комплексными числами.
 */
class Complex {
private:
    double Re; ///< Действительная часть
    double Im; ///< Мнимая часть

public:
    /**
     * @brief Конструктор комплексного числа.
     * @param aRe Действительная часть (по умолчанию 0).
     * @param aIm Мнимая часть (по умолчанию 0).
     */
    Complex(double aRe = 0, double aIm = 0);

    /**
     * @brief Конструктор копирования.
     * @param other Другой объект Complex.
     */
    Complex(const Complex& other);

    /**
     * @brief Деструктор.
     */
    ~Complex();

    /**
     * @brief Устанавливает значение комплексного числа.
     * @param aRe Новое значение действительной части.
     * @param aIm Новое значение мнимой части (по умолчанию 0).
     */
    void Set(double aRe, double aIm = 0);

    /**
     * @brief Преобразование комплексного числа в double.
     * @return Действительная часть комплексного числа.
     */
    operator double();

    /**
     * @brief Вычисляет модуль комплексного числа.
     * @return Значение модуля.
     */
    double abs();

    /**
     * @brief Перегрузка оператора ввода.
     * @param in Входной поток.
     * @param c Комплексное число.
     * @return Ссылка на входной поток.
     */
    friend istream& operator>>(istream& in, Complex& c);

    /**
     * @brief Перегрузка оператора вывода.
     * @param out Выходной поток.
     * @param c Комплексное число.
     * @return Ссылка на выходной поток.
     */
    friend ostream& operator<<(ostream& out, Complex& c);

    Complex operator+(const Complex&);
    Complex operator-(const Complex&);
    Complex operator+(const double&);
    friend Complex operator+(const double&, const Complex&);
    Complex operator-(const double&);
    friend Complex operator-(const double&, const Complex&);
    Complex operator*(const Complex&);
    Complex operator*(const double&);
    friend Complex operator*(const double&, const Complex&);
    Complex operator/(const double&);

    Complex& operator+=(const Complex&);
    Complex& operator-=(const Complex&);
    Complex& operator*=(const Complex&);
    Complex& operator+=(const double&);
    Complex& operator-=(const double&);
    Complex& operator*=(const double&);
    Complex& operator/=(const double&);
    Complex& operator=(const Complex&);
    Complex& operator=(const double&);
};

#endif

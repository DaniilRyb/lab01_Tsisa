 // Daniil Rybakov IU8-33
 // Лабораторная работа №1 Вариант 15 по дисциплине Тееорий систем и системный анализ
 // ПОИСК МИНИМУМА УНИМОДАЛЬНОЙ ФУНКЦИИ МЕТОДОМ ФИБОНАЧЧИ

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;


double Fun(double x) { // исходная функция

    return x * x * sin(x);
}


int F(int n) // ф-ия нахождения n-ого числа Фибоначчи
{
    int f, f1=1, f2=1, m=0;
       while (m < n - 1)
    {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
        ++m;
    }

    return f1;
}



void HeaderTable() { // ф-ия печати заголовка таблицы
    cout << "______________________________________________________________"  << endl;
    cout << "|   Начало  |    Конец   |    Длина   |           |           |" << endl;
    cout << "| интервала |  интервала |  интервала |   f(ak)   |    f(bk)  |" << endl;
    cout << "|    (ak)   |    (bk)    |     (l)    |           |           |" << endl;
    cout << "-------------------------------------------------------------"   << endl;

}


void FooterTable() {
    cout  << "_______________________________________________________________" << endl;
}


void PrintRow(const double a, const double b,
         const double l, const double xf1, const double xf2) { // ф-и печати строки значений таблицы

    cout << "|" << std::right << std::setw(11) << a << "|" << std::setw(12)
    << b << "|" << std::setw(12) << l << "|" << std::setw(11)
    << xf1 << "|" << std::setw(11)
    << xf2<< "|" << std::endl;


}


void MinFunctionPrint(const double &a, const double &b) { // ф-ия печати мин значения аргумента и
                                                          //значение самой ф-ии в этой точке
      double xmin = (a + b) / 2; // находим x минимальное на отрезке
             cout << endl << "Минимальное значение функции достигается при x = "
             << xmin << " +- " << (b-a)/2 << ";" << " F(x) = " << Fun(xmin) << endl;
}




void Fibonachi(double a, double b, int N)
   {

    double f1 = Fun(a);
    double f2 = Fun(b);
    HeaderTable();
    PrintRow(a, b, b-a, f1, f2);

    double x1, x2, xmin, xf1, xf2;

    for (int i = 0; i < N; ++i) {

        x1 = a + (double)F(N - 2) / F(N) * (b - a);
        x2 = a + (double)F(N - 1) / F(N) * (b - a);

        xf1 = Fun(x1);
        xf2 = Fun(x2);


        if (xf1 < xf2) {
            b = x2;
        }
        else if (xf1 > xf2) {
            a = x1;
        }

        double l = x2 - x1;



        PrintRow(a, b, l, xf1, xf2);

    }

    FooterTable();
    MinFunctionPrint(a,b);


}



int main() {

    setlocale(LC_ALL, "RUS");
    int a = 9;
    int b = 12;
    Fibonachi(a, b, 5);

    return 0;
}

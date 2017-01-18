#include "CTriangleTypeChecker.h"

Result CTriangleTypeChecker::CheckType(const std::string &first, const std::string &second,
                                       const std::string &third) {
    double a, b, c;
    try {
        a = std::stod(first);
        b = std::stod(second);
        c = std::stod(third);
    }
    catch (...) {
        return NOT_A_NUMBER;
    }
    if (a > 0 && b > 0 && c > 0) {
        if (a + b > c && a + c > b && b + c > a) {
            if (a == b && a == c) {
                return EQUILATERAL;
            }
            if (a == b || a == c || b == c) {
                return ISOSCELES;
            }
            return SIMPLE;
        }
        return NOT_TRIANGLE;
    }
    return NOT_SHAPE;
}

void CTriangleTypeChecker::OutputResult(Result result) {
    switch (result) {
        case NOT_A_NUMBER:
            std::cout << "Некорректный пользовательский ввод (все параметры должны быть числами)";
            break;
        case NOT_SHAPE:
            std::cout << "Не фигура (Одна из сторон имеет неположительную длину)";
            break;
        case NOT_TRIANGLE:
            std::cout << "Не треугольник";
            break;
        case SIMPLE:
            std::cout << "Простой треугольник";
            break;
        case ISOSCELES:
            std::cout << "Равнобедренный треугольник";
            break;
        case EQUILATERAL:
            std::cout << "Равносторонний треугольник";
            break;
    }
}

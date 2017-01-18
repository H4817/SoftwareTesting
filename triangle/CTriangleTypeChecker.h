#ifndef TRIANGLE_CTRIANGLETYPECHECKER_H
#define TRIANGLE_CTRIANGLETYPECHECKER_H

#pragma once

#include <string>
#include <iostream>

enum Result {
    NOT_A_NUMBER = -1,
    NOT_SHAPE = -2,
    NOT_TRIANGLE = -3,
    EQUILATERAL = 2,
    ISOSCELES = 1,
    SIMPLE = 0
};


class CTriangleTypeChecker {
public:
    CTriangleTypeChecker() = delete;

    static Result CheckType(const std::string &first, const std::string &second, const std::string &third);

    static void OutputResult(Result result);

};


#endif

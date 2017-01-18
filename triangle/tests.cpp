#define BOOST_TEST_MODULE MyTestModule

#include <boost/test/included/unit_test.hpp>
#include "CTriangleTypeChecker.h"

BOOST_AUTO_TEST_SUITE(TriangleTests)

    BOOST_AUTO_TEST_SUITE(CheckInput)

        BOOST_AUTO_TEST_CASE(should_get_NAN_error) {
            BOOST_CHECK_EQUAL(CTriangleTypeChecker::CheckType("f", "1", "2"), NOT_A_NUMBER);
            BOOST_CHECK_EQUAL(CTriangleTypeChecker::CheckType("3", "", "0"), NOT_A_NUMBER);
            BOOST_CHECK_EQUAL(CTriangleTypeChecker::CheckType("3", "", ""), NOT_A_NUMBER);
        }

    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE(correct_determines_triangle_type)

        BOOST_AUTO_TEST_CASE(not_shape) {
            BOOST_CHECK_EQUAL(CTriangleTypeChecker::CheckType("1", "0", "2"), NOT_SHAPE);
            BOOST_CHECK_EQUAL(CTriangleTypeChecker::CheckType("44", "-44", "44"), NOT_SHAPE);
            BOOST_CHECK_EQUAL(CTriangleTypeChecker::CheckType("-11.0", "4.4", "0"), NOT_SHAPE);
        }

        BOOST_AUTO_TEST_CASE(not_triangle) {
            BOOST_CHECK_EQUAL(CTriangleTypeChecker::CheckType("4", "1", "2"), NOT_TRIANGLE);
            BOOST_CHECK_EQUAL(CTriangleTypeChecker::CheckType("1", "1", "8"), NOT_TRIANGLE);
            BOOST_CHECK_EQUAL(CTriangleTypeChecker::CheckType("1", "2", "3"), NOT_TRIANGLE);
        }

        BOOST_AUTO_TEST_CASE(simple) {
            BOOST_CHECK_EQUAL(CTriangleTypeChecker::CheckType("8", "9", "11"), SIMPLE);
            BOOST_CHECK_EQUAL(CTriangleTypeChecker::CheckType("1.0", "2.11", "3.10"), SIMPLE);
            BOOST_CHECK_EQUAL(CTriangleTypeChecker::CheckType("100", "70", "40"), SIMPLE);
        }

        BOOST_AUTO_TEST_CASE(equilateral) {
            BOOST_CHECK_EQUAL(CTriangleTypeChecker::CheckType("6", "6", "6"), EQUILATERAL);
            BOOST_CHECK_EQUAL(CTriangleTypeChecker::CheckType("777", "777", "777"), EQUILATERAL);
            BOOST_CHECK(CTriangleTypeChecker::CheckType("0", "0", "0") != EQUILATERAL);
        }

        BOOST_AUTO_TEST_CASE(isosceles) {
            BOOST_CHECK_EQUAL(CTriangleTypeChecker::CheckType("3", "3", "4"), ISOSCELES);
            BOOST_CHECK_EQUAL(CTriangleTypeChecker::CheckType("5.123", "4.5", "5.123"), ISOSCELES);
            BOOST_CHECK_EQUAL(CTriangleTypeChecker::CheckType("2.77", "2.77", "3"), ISOSCELES);
        }

    BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()




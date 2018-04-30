#ifndef TEMPERATURE_TESTS_H_
#define TEMPERATURE_TESTS_H_

#include <gmock/gmock.h>
using namespace ::testing;
#include "../inc/temperature_converters.h"

class CelsiusToFahrenheitParamTests : public TestWithParam<std::pair<double, double>>
{
public:
        CelsiusToFahrenheitConverter cut;
};

INSTANTIATE_TEST_CASE_P(
        ,
        CelsiusToFahrenheitParamTests,
        Values(
                std::pair<double, double>(-3.14159265359e+8,   -5.6548664564620006e+8),
                std::pair<double, double>(-50.0,               -58.0),
                std::pair<double, double>(-40.0,               -40.0),
                std::pair<double, double>(-30.0,               -22.0),
                std::pair<double, double>(-20.0,               -4.0),
                std::pair<double, double>(-10.0,               14.0),
                std::pair<double, double>(0.0,                 32.0),
                std::pair<double, double>(1.0,                 33.8),
                std::pair<double, double>(2.0,                 35.6),
                std::pair<double, double>(3.0,                 37.4),
                std::pair<double, double>(4.0,                 39.2),
                std::pair<double, double>(5.0,                 41.0),
                std::pair<double, double>(10.0,                50.0),
                std::pair<double, double>(20.0,                68.0),
                std::pair<double, double>(30.0,                86.0),
                std::pair<double, double>(40.0,                104.0),
                std::pair<double, double>(50.0,                122.0),
                std::pair<double, double>(3.14159265359e+8,    5.6548670964620006e+8)
        )
);

TEST_P(CelsiusToFahrenheitParamTests, ShouldConvertCelsiusToFahrenheit)
{
        const double celsius = GetParam().first;
        const double fahrenheit = GetParam().second;
        EXPECT_THAT(cut.convert(celsius), DoubleEq(fahrenheit));
}

TEST(FahrenheitToCelsiusTests, ExpectZeroToConvertToCelsius)
{
        EXPECT_THAT(
                FahrenheitToCelsiusConverter().convert(0),
                DoubleNear(-17.7778, 0.001)
        );
}

TEST(FahrenheitToCelsiusTests, ExpectVerySmallNumberToConvertToFahrenheit)
{
        EXPECT_THAT(
                FahrenheitToCelsiusConverter().convert(-3.14159265359e+8),
                DoubleEq(-1.7453294297722223e+8)
        );
}

TEST(FahrenheitToCelsiusTests, ExpectVeryLargeNumberToConvertToFahrenheit)
{
        EXPECT_THAT(
                FahrenheitToCelsiusConverter().convert(3.14159265359e+8),
                DoubleEq(1.7453290742166668e+8)
        );
}

#endif

#ifndef TEMPERATURE_TESTS_H_
#define TEMPERATURE_TESTS_H_

#include <gmock/gmock.h>
using namespace ::testing;
#include "../inc/temperature_converters.h"

TEST(CelsiusToFahrenheitTests, ExpectZeroToConvertToThirtyTwo)
{
        EXPECT_THAT(
                CelsiusToFahrenheitConverter().convert(0),
                Eq(32.0)
        );
}

TEST(CelsiusToFahrenheitTests, ExpectVerySmallNumberToConvertToFahrenheit)
{
        EXPECT_THAT(
                CelsiusToFahrenheitConverter().convert(-3.14159265359e+8),
                DoubleEq(-5.6548664564620006e+8)
        );
}

TEST(CelsiusToFahrenheitTests, ExpectVeryLargeNumberToConvertToFahrenheit)
{
        EXPECT_THAT(
                CelsiusToFahrenheitConverter().convert(3.14159265359e+8),
                DoubleEq(5.6548670964620006e+8)
        );
}

#endif

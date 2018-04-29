#ifndef TEMPERATURE_CONVERTERS_H_
#define TEMPERATURE_CONVERTERS_H_

class CelsiusToFahrenheitConverter
{
public:
        const double convert(const double value) const
        {
                return value * 1.8 + 32;
        }
};

#endif

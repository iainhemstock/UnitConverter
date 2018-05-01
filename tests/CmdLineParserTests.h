#include <gmock/gmock.h>
using namespace ::testing;
#include "../inc/CmdLineParser.h"

TEST(CmdLineParserTests, ShouldThrowWhenArgCountIsNotExactlySix)
{
        EXPECT_THROW(CmdLineParser(0, nullptr), CmdLineParserException);
        EXPECT_THROW(CmdLineParser(5, nullptr), CmdLineParserException);
        EXPECT_THROW(CmdLineParser(7, nullptr), CmdLineParserException);
        EXPECT_NO_THROW(CmdLineParser(6, nullptr));
}

TEST(CmdLineParserTests, ShouldReturnAppName)
{
        const char * argv[] = { "convert", "", "", "", "", "" };
        const int argc = sizeof(argv) / sizeof(argv[0]);
        const std::string expected = argv[0];
        CmdLineParser parser(argc, argv);
        EXPECT_THAT(parser.appName(), Eq(expected));
}

TEST(CmdLineParserTests, ShouldReturnValueToConvert)
{
        const char * argv[] = { "", "3.14", "", "", "", "" };
        const int argc = sizeof(argv) / sizeof(argv[0]);
        const double expected = std::strtod(argv[1], nullptr);
        CmdLineParser parser(argc, argv);
        EXPECT_THAT(parser.valueToConvert(), Eq(expected));
}

TEST(CmdLineParserTests, ShouldReturnConverterTypeToConvertFrom)
{
        const char * argv[] = { "", "", "", "celsius", "", "" };
        const int argc = sizeof(argv) / sizeof(argv[0]);
        const std::string expected = argv[3];
        CmdLineParser parser(argc, argv);
        EXPECT_THAT(parser.convertFrom(), Eq(expected));
}

TEST(CmdLineParserTests, ShouldReturnConverterTypeToConvertTo)
{
        const char * argv[] = { "", "", "", "", "", "fahrenheit" };
        const int argc = sizeof(argv) / sizeof(argv[0]);
        const std::string expected = argv[5];
        CmdLineParser parser(argc, argv);
        EXPECT_THAT(parser.convertTo(), Eq(expected));
}

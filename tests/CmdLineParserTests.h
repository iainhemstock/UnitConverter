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
        char * argv[] = { (char*)"convert", (char*)"", (char*)"", (char*)"", (char*)"", (char*)"" };
        const int argc = sizeof(argv) / sizeof(argv[0]);
        const std::string expected = argv[0];
        CmdLineParser parser(argc, argv);
        EXPECT_THAT(parser.appName(), Eq(expected));
}

TEST(CmdLineParserTests, ShouldReturnValueToConvert)
{
        char * argv[] = { (char*)"", (char*)"3.14", (char*)"", (char*)"", (char*)"", (char*)"" };
        const int argc = sizeof(argv) / sizeof(argv[0]);
        const double expected = std::strtod(argv[1], nullptr);
        CmdLineParser parser(argc, argv);
        EXPECT_THAT(parser.valueToConvert(), Eq(expected));
}

TEST(CmdLineParserTests, ShouldReturnConverterTypeToConvertFrom)
{
        char * argv[] = { (char*)"", (char*)"", (char*)"--from", (char*)"celsius", (char*)"", (char*)"" };
        const int argc = sizeof(argv) / sizeof(argv[0]);
        const std::string expected = argv[3];
        CmdLineParser parser(argc, argv);
        EXPECT_THAT(parser.converters().first, Eq(expected));
}

TEST(CmdLineParserTests, ShouldReturnConverterTypeToConvertTo)
{
        char * argv[] = { (char*)"", (char*)"", (char*)"", (char*)"", (char*)"--to", (char*)"fahrenheit" };
        const int argc = sizeof(argv) / sizeof(argv[0]);
        const std::string expected = argv[5];
        CmdLineParser parser(argc, argv);
        EXPECT_THAT(parser.converters().second, Eq(expected));
}

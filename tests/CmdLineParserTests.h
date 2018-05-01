#include <gmock/gmock.h>
using namespace ::testing;
#include "../inc/CmdLineParser.h"

class CmdLineParserTests : public Test
{
public:
        constexpr static int argc{6};
        char * argv[argc];
        CmdLineParser cut;
        CmdLineParser::Args args;
public:
        void SetUp()
        {
                argv[0] = (char*)"convert";
                argv[1] = (char*)"3.14";
                argv[2] = (char*)"--from";
                argv[3] = (char*)"celsius";
                argv[4] = (char*)"--to";
                argv[5] = (char*)"fahrenheit";


                cut.parse(argc, argv, &args);
        }
};

TEST_F(CmdLineParserTests, ShouldThrowWhenNoArgsAreProvided)
{
        try
        {
                CmdLineParser cut(0, nullptr, nullptr);
                throw int{}; // caught in catch(...) below
        }
        catch (const CmdLineParserException& ex)
        {
                EXPECT_THAT(ex.errMsg(), Eq("Invalid arg count: should be 6"));
        }
        catch (...)
        {
                FAIL() << "Expected CmdLineParserException to be thrown";
        }
}

TEST_F(CmdLineParserTests, ShouldNotThrowWhenSixArgsAreProvided)
{
        EXPECT_NO_THROW(CmdLineParser(6, nullptr, nullptr));
}

TEST_F(CmdLineParserTests, ShouldReturnAppName)
{
        EXPECT_THAT(args.appName, Eq(argv[0]));
}

TEST_F(CmdLineParserTests, ShouldReturnValueToConvert)
{
        EXPECT_THAT(args.valueToConvert, Eq(3.14));
}

TEST_F(CmdLineParserTests, ShouldReturnTypeOfConverterToConvertFrom)
{
        EXPECT_THAT(args.converters.first, Eq("celsius"));
}

TEST_F(CmdLineParserTests, ShouldReturnTypeOfConverterToConvertTo)
{
        EXPECT_THAT(args.converters.second, Eq("fahrenheit"));
}

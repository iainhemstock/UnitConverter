#include <gmock/gmock.h>
using namespace ::testing;
#include "../inc/CmdLineParser.h"

class CmdLineParserTests : public Test
{
public:
        constexpr static int argc{6};
        char * argv[argc];
        CmdLineParser cut;
public:
        void SetUp()
        {
                argv[0] = (char*)"convert";
                argv[1] = (char*)"3.14";
                argv[2] = (char*)"--from";
                argv[3] = (char*)"celsius";
                argv[4] = (char*)"--to";
                argv[5] = (char*)"fahrenheit";

                cut.parse(argc, argv);
        }
};

TEST_F(CmdLineParserTests, ShouldThrowWhenArgCountIsNotExactlySix)
{
        EXPECT_THROW(CmdLineParser(0, nullptr), CmdLineParserException);
        EXPECT_THROW(CmdLineParser(5, nullptr), CmdLineParserException);
        EXPECT_THROW(CmdLineParser(7, nullptr), CmdLineParserException);
        EXPECT_NO_THROW(CmdLineParser(6, nullptr));
}

TEST_F(CmdLineParserTests, ShouldReturnAppName)
{
        EXPECT_THAT(cut.appName(), Eq(argv[0]));
}

TEST_F(CmdLineParserTests, ShouldReturnValueToConvert)
{
        EXPECT_THAT(cut.valueToConvert(), Eq(3.14));
}

TEST_F(CmdLineParserTests, ShouldReturnTypeOfConverterToConvertFrom)
{
        EXPECT_THAT(cut.converters().first, Eq("celsius"));
}

TEST_F(CmdLineParserTests, ShouldReturnTypeOfConverterToConvertTo)
{
        std::cout << argv[5] << std::endl;
        EXPECT_THAT(cut.converters().second, Eq("fahrenheit"));
}

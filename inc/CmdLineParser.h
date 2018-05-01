#ifndef CMD_LINE_PARSER_H_
#define CMD_LINE_PARSER_H_

#include <string>
#include <utility>

class CmdLineParserException
{
public:
        CmdLineParserException(const std::string& errMsg);
        const std::string errMsg() const;
private:
        std::string m_errMsg;
};

class CmdLineParser
{
public:
        struct Args
        {
                std::string appName{};
                double valueToConvert{};
                std::pair<std::string, std::string> converters{};
        };
public:
        CmdLineParser() = default;
        CmdLineParser(const int argc, char * argv[], CmdLineParser::Args * args);

        void parse(const int argc, char * argv[], CmdLineParser::Args * args);
private:
        const bool isValidArgCount(const int argc);
};

#endif

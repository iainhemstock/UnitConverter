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
        CmdLineParser() = default;
        CmdLineParser(const int argc, char * argv[]);

        void parse(const int argc, char * argv[]);
        const std::string appName() const;
        const double valueToConvert() const;
        std::pair<std::string, std::string> converters() const;
private:
        const bool isValidArgCount(const int argc);
private:
        std::string m_appName{};
        double m_valueToConvert{};
        std::string m_convertFrom{};
        std::string m_convertTo{};
};

#endif

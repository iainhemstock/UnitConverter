#ifndef CMD_LINE_PARSER_H_
#define CMD_LINE_PARSER_H_

#include <string>

class CmdLineParserException
{
public:
        CmdLineParserException(const std::string& errMsg)
        : m_errMsg{errMsg}
        {}

        const std::string errMsg() const
        {
                return m_errMsg;
        }
private:
        std::string m_errMsg;
};

class CmdLineParser
{
public:
        CmdLineParser(const int argc, const char * argv[])
        {
                if (isValidArgCount(argc))
                {
                        if (argv != nullptr) {
                                m_appName = argv[0];
                                m_valueToConvert = std::strtod(argv[1], nullptr);
                                m_convertFrom = argv[3];
                                m_convertTo = argv[5];
                        }
                }
                else
                {
                        throw CmdLineParserException("Invalid arg count: should be 6");
                }
        }

        const std::string
        appName() const
        {
                return m_appName;
        }

        const double
        valueToConvert() const
        {
                return m_valueToConvert;
        }

        const std::string
        convertFrom() const
        {
                return m_convertFrom;
        }

        const std::string
        convertTo() const
        {
                return m_convertTo;
        }
private:
        const bool isValidArgCount(const int argc)
        {
                if (argc < 6 || argc > 6)
                        return false;
                return true;
        }
private:
        std::string m_appName{};
        double m_valueToConvert{};
        std::string m_convertFrom{};
        std::string m_convertTo{};
};

#endif

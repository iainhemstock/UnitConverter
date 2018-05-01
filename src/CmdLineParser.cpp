#include "../inc/CmdLineParser.h"

CmdLineParserException::CmdLineParserException(const std::string& errMsg)
: m_errMsg{errMsg}
{}

const std::string
CmdLineParserException::errMsg() const
{
        return m_errMsg;
}

CmdLineParser::CmdLineParser(const int argc, const char * argv[])
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
CmdLineParser::appName() const
{
        return m_appName;
}

const double
CmdLineParser::valueToConvert() const
{
        return m_valueToConvert;
}

std::pair<std::string, std::string>
CmdLineParser::converters() const
{
        return std::make_pair(m_convertFrom, m_convertTo);
}

const bool
CmdLineParser::isValidArgCount(const int argc)
{
        if (argc < 6 || argc > 6)
                return false;
        return true;
}

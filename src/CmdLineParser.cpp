#include "../inc/CmdLineParser.h"
#include <getopt.h>
#include <iostream>

CmdLineParserException::CmdLineParserException(const std::string& errMsg)
: m_errMsg{errMsg}
{}

const std::string
CmdLineParserException::errMsg() const
{
        return m_errMsg;
}

CmdLineParser::CmdLineParser(const int argc, char * argv[])
{
        parse(argc, argv);
}

void
CmdLineParser::parse(const int argc, char * argv[])
{
        if (isValidArgCount(argc))
        {
                if (argv != nullptr)
                {
                        extern int optind;
                        optind = 0;
                        m_appName = argv[0];
                        static struct option long_options[] =
                        {
                                { "from", required_argument, 0, 'f' },
                                { "to", required_argument, 0, 't' }
                        };
                        int option_index = 0;
                        int c;
                        while ((c = getopt_long(argc, argv, "f:t:", long_options, &option_index)) != -1)
                        {
                                switch (c)
                                {
                                        case 'f':
                                                m_convertFrom = optarg;
                                                break;
                                        case 't':
                                                m_convertTo = optarg;
                                                break;
                                }
                        }

                        if (optind < argc)
                                m_valueToConvert = std::strtod(argv[optind], nullptr);
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

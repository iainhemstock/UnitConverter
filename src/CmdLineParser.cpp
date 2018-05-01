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

CmdLineParser::CmdLineParser(const int argc, char * argv[], CmdLineParser::Args * args)
{
        parse(argc, argv, args);
}

void
CmdLineParser::parse(const int argc, char * argv[], CmdLineParser::Args * args)
{
        if (isValidArgCount(argc))
        {
                if (argv != nullptr)
                {
                        extern int optind;
                        optind = 0;

                        args->appName = argv[0];
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
                                                args->converters.first = optarg;
                                                break;
                                        case 't':
                                                args->converters.second = optarg;
                                                break;
                                }
                        }

                        if (optind < argc)
                                args->valueToConvert = std::strtod(argv[optind], nullptr);
                }
        }
        else
        {
                throw CmdLineParserException("Invalid arg count: should be 6");
        }
}

const bool
CmdLineParser::isValidArgCount(const int argc)
{
        if (argc < 6 || argc > 6)
                return false;
        return true;
}

#pragma once

#include <stdio.h>

#define LOG(lvl, args...) { fprintf(Nexyon::__LOG_FD[lvl], "[%s@%d:%s] ", Nexyon::__LOG_LEVELS[lvl], __LINE__, __FILE__); fprintf(Nexyon::__LOG_FD[lvl], args); putc('\n', Nexyon::__LOG_FD[lvl]); }

namespace Nexyon
{
    static char* __LOG_LEVELS[] = {
        "INFO",
        "ERROR",
        "WARNING"
    };

    static FILE* __LOG_FD[] = {
        stdout, stderr, stdout
    };

    enum LogLevels {
        INFO = 0,
        ERROR,
        WARNING
    };

}


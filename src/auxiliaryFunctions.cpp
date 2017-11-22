// COPYRIGHT: Open source by GPL (GNU General Public License)
// Based on C5.0 GPL Edition provided by Rulequest Research Pty Ltd.
//===================================================================

#ifdef WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#include "auxiliaryFunctions.h"

double GetSystemClock() {
#ifdef WIN32
    static LONGLONG frequency = 0;
    LARGE_INTEGER li;
    if (frequency == 0 && QueryPerformanceFrequency(&li))
        frequency = li.QuadPart;
    if (frequency != 0 && QueryPerformanceCounter(&li))
        return (double)(((li.QuadPart * 100000) / frequency));
    return 0;
#else
    struct timeval	TV;
    struct timezone	TZ = { 0, 0 };

    gettimeofday(&TV, &TZ);
    return (double)(TV.tv_sec + TV.tv_usec / 1000000.0);
#endif
}
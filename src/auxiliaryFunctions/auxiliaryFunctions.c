// COPYRIGHT: Open source by GPL (GNU General Public License)
// Based on C5.0 GPL Edition provided by Rulequest Research Pty Ltd.
//===================================================================

#include "auxiliaryFunctions.h"

#ifdef WIN32
#include <windows.h>
#include <direct.h>
#include <time.h>
#include <strsafe.h>
#else
#include <sys/time.h>
#endif

/* solving rlimits */
#if defined(__unix__)
  #include <sys/time.h>
  #include <sys/resource.h>
#endif

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

void SetRunTimeStackSize(unsigned long int iValue_KB) {
#ifdef WIN32
    unsigned long int val = iValue_KB * 1024;
    if (SetThreadStackGuarantee(&val) == 0) {
        ErrorExit(TEXT("SetThreadStackGuarantee"));
    }
#else
    struct rlimit RL;
    getrlimit(RLIMIT_STACK, &RL);
    RL.rlim_cur = Max(RL.rlim_cur, iValue_KB * 1024);
    if (RL.rlim_max > 0) { /* -1 if unlimited */
        RL.rlim_cur = Min(RL.rlim_max, RL.rlim_cur);
    }
    setrlimit(RLIMIT_STACK, &RL);
#endif
}

#ifdef WIN32
void ErrorExit(LPTSTR lpszFunction) {
    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
    DWORD dw = GetLastError();

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf,
        0, NULL);

    // Display the error message and exit the process

    lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
        (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));
    StringCchPrintf((LPTSTR)lpDisplayBuf,
        LocalSize(lpDisplayBuf) / sizeof(TCHAR),
        TEXT("%s failed with error %d: %s"),
        lpszFunction, dw, lpMsgBuf);
    MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
    ExitProcess(dw);
}
#endif

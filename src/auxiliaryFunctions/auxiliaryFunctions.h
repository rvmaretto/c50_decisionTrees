// COPYRIGHT: Open source by GPL (GNU General Public License)
// Based on C5.0 GPL Edition provided by Rulequest Research Pty Ltd.
//===================================================================

#ifndef AUXILIARYFUNCTIONS_H_
#define AUXILIARYFUNCTIONS_H_

#include "../c50/defns.h"

double GetSystemClock();

void SetRunTimeStackSize(unsigned long int iValue_KB);

#ifdef WIN32
#include <windows.h>
void ErrorExit(LPTSTR lpszFunction);
#endif

#endif  // AUXILIARYFUNCTIONS_H_

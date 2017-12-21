// COPYRIGHT: Open source by GPL (GNU General Public License)
// Based on C5.0 GPL Edition provided by Rulequest Research Pty Ltd.
//===================================================================

#include "c50_main.h"

#ifndef C50_LIBENTRY_H_
#define C50_LIBENTRY_H_
void c50(const char **namesv, const char **datav, const char **costv, int *subset, int *rules, int *utility,
    int *trials, int *winnow, double *sample, int *seed, int *noGlobalPruning, double *CF,
    int *minCases, int *fuzzyThreshold, int *earlyStopping, char **treev, char **rulesv, char **outputv);

void predictions(const char **casev, const char **namesv, char **treev, char **rulesv,
    const char **costv,
    int *predv,  /* XXX predictions are character */ double *confidencev, int *trials, char **outputv);
#endif  // C50_LIBENTRY_H_

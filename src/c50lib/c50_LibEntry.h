// COPYRIGHT: Open source by GPL (GNU General Public License)
// Based on C5.0 GPL Edition provided by Rulequest Research Pty Ltd.
//===================================================================

#ifndef C50_LIBENTRY_H_
#define C50_LIBENTRY_H_

#include "c50_main.h"

void c50(char **namesv, char **datav, char **costv, int *subset, int *rules, int *utility,
    int *trials, int *winnow, double *sample, int *seed, int *noGlobalPruning, double *CF,
    int *minCases, int *fuzzyThreshold, int *earlyStopping, char **treev, char **rulesv, char **outputv);

void predictions(char **casev, char **namesv, char **treev, char **rulesv,
    char **costv,
    int *predv,  /* XXX predictions are character */ double *confidencev, int *trials, char **outputv);
#endif  // C50_LIBENTRY_H_

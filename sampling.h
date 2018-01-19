#ifndef SAMPLING_H
#define SAMPLING_H

#include <cstdint>

#include "parameter.h"
#include "Poly.h"
#include "PolyVec.h"

void generateNoise(Poly&);
void samplingWavy(PolyVec& publicKey, const PolyVec& secretKey);

#endif
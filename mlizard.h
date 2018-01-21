#ifndef MLIZARD_H
#define MLIZARD_H

#include <cstdlib>
#include <cstdint>

#include "parameter.h"
#include "PolyVec.h"
#include "sampling.h"

void secretKeyGeneration(PolyVec&);
void publicKeyGeneration(PolyVec*, PolyVec&, const PolyVec&);
void encryption();
void decryption();

#endif
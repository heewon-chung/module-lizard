#ifndef MLIZARD_H
#define MLIZARD_H

#include <cstdint>

#include "parameter.h"
#include "Poly.h"
#include "sampling.h"

void secretKeyGeneration(PolyVec&);
void publicKeyGeneration(PolyVec&, PolyVec*, PolyVec&);
void encryption();
void decryption();

#endif
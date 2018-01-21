#ifndef POLYVEC_H
#define POLYVEC_H

#include <cstdint>
#include <cstdlib>
#include <iostream>

#include "parameter.h"
#include "Poly.h"

using namespace std;

typedef struct{
    Poly* poly = new Poly[dimension];
} PolyVec;

void initializePolyVector(PolyVec&);

void generatePolyVector(PolyVec&);
void generateSignedPolyVector(PolyVec&);    

void addPolyVector(PolyVec&, const PolyVec&, const PolyVec&);

void printPolyVector(const PolyVec&);

#endif
#ifndef POLY_H
#define POLY_H

#include <cstdint>
#include <cstdlib>
#include <iostream>

#include "parameter.h"

using namespace std;

typedef struct{
    int16_t* coeff = new int16_t[degree];
} Poly;

void initializePolynomial(Poly&);

void generateRandomPolynomial(Poly&);
void generateSignedPolynomial(Poly&);

void addPolynomial(Poly&, const Poly&, const Poly&);
void subPolynomial(Poly&, const Poly&, const Poly&);
void shiftPolynomial(Poly&, const Poly&);
void mulPolynomial(Poly&, const Poly&, const Poly&);

void printPolynomial(const Poly&);

#endif
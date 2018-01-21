#include "Poly.h"

void initializePolynomial(Poly& poly){

    #pragma omp parallel for
    for(size_t i = 0; i < degree; i++){
        poly.coeff[i] = 0;
    }

}

void generateRandomPolynomial(Poly& poly){

    initializePolynomial(poly);

    #pragma omp parallel for
    for(size_t i = 0; i < degree; i++){
        poly.coeff[i] = rand() % coeffModulus;
    }

}

void generateSignedPolynomial(Poly& poly){
    
    initializePolynomial(poly);

    #pragma omp parallel for
    for(size_t i = 0; i < degree; i++){
        uint16_t rnd = rand() % 3;
        if (rnd == 0){
            poly.coeff[i] = 0;
        }
        else if(rnd == 1){
            poly.coeff[i] = 1;
        }
        else{
            poly.coeff[i] = -1;
        }
    }

}

void addPolynomial(Poly& addPoly, const Poly& poly1, const Poly& poly2){

    // initializePolynomial(addPoly);

    #pragma omp parallel for
    for(size_t i = 0; i < degree; i++){
        addPoly.coeff[i] = poly1.coeff[i] + poly2.coeff[i];
    }

}

void subPolynomial(Poly& subPoly, const Poly& poly1, const Poly& poly2){

    // initializePolynomial(subPoly);

    #pragma omp parallel for
    for(size_t i = 0; i < degree; i++){
        subPoly.coeff[i] = poly1.coeff[i] - poly2.coeff[i];
    }

}

// shiftPoly = Poly >> 1 mod X^n + 1
void shiftPolynomial(Poly& shiftPoly, const Poly& poly){

    // initializePolynomial(shiftPoly);

    shiftPoly.coeff[0] = -poly.coeff[degree - 1];

    #pragma omp parallel for
    for(size_t i = 1; i < degree; i++){
        shiftPoly.coeff[i] = poly.coeff[i - 1];
    }

}

// poly2 should be a signed binary polynomial.
void mulPolynomial(Poly& mulPoly, const Poly& poly1, const Poly& poly2){

    initializePolynomial(mulPoly);

    size_t pos = 0;
    Poly shiftPoly = poly1;

    while(pos < degree){

        Poly tmpShiftPoly, tmpMulPoly; 
        if(poly2.coeff[pos] == 1){
            addPolynomial(tmpMulPoly, mulPoly, shiftPoly);
            mulPoly = tmpMulPoly;
        }
        else if(poly2.coeff[pos] == -1){
            subPolynomial(tmpMulPoly, mulPoly, shiftPoly);
            mulPoly = tmpMulPoly;
        }
        
        shiftPolynomial(tmpShiftPoly, shiftPoly);
        shiftPoly = tmpShiftPoly;
        pos++;
    }

}


void printPolynomial(const Poly& poly){

    for(size_t i = 0; i < degree; i++){
        cout << poly.coeff[i] << "\t";
    }
    cout << endl;
}
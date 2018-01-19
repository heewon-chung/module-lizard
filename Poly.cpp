#include "Poly.h"


void initializePolynomial(Poly& poly){

    #pragma omp parallel for
    for(size_t i = 0; i < degree; i++){
        poly.coeff[i] = 0;
    }

}

void generateRandomPolynomial(Poly& poly){

    #pragma omp parallel for
    for(size_t i = 0; i < degree; i++){
        poly.coeff[i] = rand() % coeffModulus;
    }

}

void generateBinaryPolynomial(Poly& poly){

    
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

    #pragma omp parallel for
    for(size_t i = 0; i < degree; i++){
        addPoly.coeff[i] = poly1.coeff[i] + poly2.coeff[i];
    }

}

void subPolynomial(Poly& subPoly, const Poly& poly1, const Poly& poly2){

    #pragma omp parallel for
    for(size_t i = 0; i < degree; i++){
        subPoly.coeff[i] = poly2.coeff[i] - poly2.coeff[i];
    }

}

// shiftPoly = Poly << 1 mod X^n + 1
void shiftPolynomial(Poly& shiftPoly, const Poly& poly){
    
    #pragma omp parallel for
    for(size_t i = degree; i > 0; i--){
        shiftPoly.coeff[i] = poly.coeff[i - 1];
    }

    shiftPoly.coeff[0] = -shiftPoly.coeff[degree];

}

void multPolynomial(Poly& mulPoly, const Poly& poly1, const Poly& poly2){

    size_t pos = 0;
    Poly shiftPoly = poly2;

    while(pos < degree){    
        shiftPolynomial(shiftPoly, shiftPoly);

        if(poly2.coeff[pos] != 0){
            addPolynomial(mulPoly, poly1, shiftPoly);
        }

        pos++;
    }

}


void printPolynomial(const Poly& poly){

    for(size_t i = 0; i < degree; i++){
        cout << poly.coeff[i] << "\t" << endl;
    }
}
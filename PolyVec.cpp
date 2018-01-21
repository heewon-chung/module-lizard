#include "PolyVec.h"

void initializePolyVector(PolyVec& polyvec){

    #pragma omp parallel for
    for(size_t i = 0; i < dimension; i++){
        initializePolynomial(polyvec.poly[i]);
    }
    
}

void generatePolyVector(PolyVec& polyvec){
    
    #pragma omp prallel for
    for(size_t i = 0; i < dimension; i++){
        generateRandomPolynomial(polyvec.poly[i]);
    }

}

void generateSignedPolyVector(PolyVec& polyvec){

    #pragma omp parallel for
    for(size_t i = 0; i < dimension; i++){
        generateSignedPolynomial(polyvec.poly[i]);
    }

}

void addPolyVector(PolyVec& addPolyVec, const PolyVec& polyvec1, const PolyVec& polyvec2){

    #pragma omp parallel for
    for(size_t i = 0; i < dimension; i++){
        addPolynomial(addPolyVec.poly[i], polyvec1.poly[i], polyvec2.poly[i]);
    }

}

void printPolyVector(const PolyVec& polyVec){

    for(size_t i = 0; i < dimension; i++){
        printPolynomial(polyVec.poly[i]);
    }
    cout << endl;
}
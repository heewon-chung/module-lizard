#include "mlizard.h"

void secretKeyGeneration(PolyVec& secretKey){

    #pragma omp parallel for
    for(size_t i = 0; i < dimension - 1; i++){
        
        Poly skPoly = secretKey.poly[i];

        #pragma omp parallel for
        for(size_t j = 0; j < degree; j++){

            uint16_t rnd = rand () % 3;
            if(j == 0){
                if(rnd == 0){
                    skPoly.coeff[j] = 1;
                }
                else if(rnd == 1){
                    skPoly.coeff[j] = 3;
                }
                else{
                    skPoly.coeff[j] = -1;
                }
            }
            else{
                if(rnd == 0){
                    skPoly.coeff[j] = 0;
                }
                else if(rnd == 1){
                    skPoly.coeff[j] = 2;
                }
                else{
                    skPoly.coeff[j] = -2;
                }
            }

        }

    }
    
    secretKey.poly[dimension - 1].coeff[0] = 1;

}

void publicKeyGeneration(PolyVec* publicKeyA, PolyVec& publicKeyB, const PolyVec& secretKey){

    #pragma omp parallel for
    for(size_t i = 0; i < dimension; i++){
        samplingWavy(publicKeyA[i], secretKey);
    }

    samplingWavy(publicKeyB, secretKey);

}

void encryption(){

}

void decryption(){

}
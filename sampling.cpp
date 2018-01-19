#include "sampling.h"

void noiseSampling(Poly& poly){

    generateRandomPolynomial(poly);
    
}
                                                                     
void samplingWavy(PolyVec& publicKey, const PolyVec& secretKey){
    
    Poly tmpPoly;
    
    noiseSampling(publicKey.poly[dimension - 1]);

    for(size_t i = 0; i < dimension - 1; i++){
        generateRandomPolynomial(publicKey.poly[i]);
        mulPolynomial(tmpPoly, publicKey.poly[i], secretKey.poly[i]);
        subPolynomial(publicKey.poly[dimension - 1], publicKey.poly[i], tmpPoly);
    }

}
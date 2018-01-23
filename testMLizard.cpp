#include <cstdlib>
#include <cstdint>
#include <iostream>

#include "utilities.h"
#include "parameter.h"
#include "mlizard.h"

using namespace std;

int main(void){

    PolyVec     secretKey, publicKeyB;
    PolyVec*    publicKeyA = new PolyVec[dimension];
    TIMER       start, end;
    
    cout << "Generating Keys......\t";

    start = TIC;
    secretKeyGeneration(secretKey);
    publicKeyGeneration(publicKeyA, publicKeyB, secretKey);
    end = TOC;

    cout << "it takes " << get_time_us(start, end, 1) << " microsec" << endl;
    

    return 1;
}

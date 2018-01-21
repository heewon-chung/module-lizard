#include <cstdlib>
#include <cstdint>
#include <iostream>

#include "parameter.h"
#include "Poly.h"

using namespace std;

int main(void){
    
    srand(time(NULL));

    Poly poly1, poly2, poly3, addPoly, subPoly, mulPoly, shiftPoly;

    generateRandomPolynomial(poly1);
    generateSignedPolynomial(poly2);
    generateRandomPolynomial(poly3);
    cout << "poly1\t\t";        printPolynomial(poly1);
    cout << "poly2\t\t";        printPolynomial(poly2);
    cout << "poly3\t\t";        printPolynomial(poly3);
    
    cout << endl;
    shiftPolynomial(shiftPoly, poly1);
    cout << "poly1 >> 1\t";     printPolynomial(shiftPoly);

    addPolynomial(addPoly, poly1, poly3);
    cout << "poly1 + poly2\t";  printPolynomial(addPoly);

    subPolynomial(subPoly, poly1, poly3);
    cout << "poly1 - poly2\t";  printPolynomial(subPoly);

    mulPolynomial(mulPoly, poly1, poly2);
    // cout << "poly1 * poly2\t";  printPolynomial(mulPoly);

    return 1;
}
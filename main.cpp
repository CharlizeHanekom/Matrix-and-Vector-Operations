#include <iostream>
#include <fstream>
#include "vector.h"
#include "matrix.h"

using namespace std;

void testVectors() {
    cout << "=== VECTOR DEMONSTRATION ===" << endl << endl;
    
    // Create vectors
    Vector v1(3);
    Vector v2(3);
    
    // Initialize vectors
    v1[0] = 1.0; v1[1] = 2.0; v1[2] = 3.0;
    v2[0] = 4.0; v2[1] = 5.0; v2[2] = 6.0;
    
    cout << "Vector v1: ";
    v1.print();
    cout << "Vector v2: ";
    v2.print();
    
    // Vector operations
    cout << "\nVector Addition (v1 + v2): ";
    (v1 + v2).print();
    
    cout << "Vector Subtraction (v1 - v2): ";
    (v1 - v2).print();
    
    cout << "Vector Scalar Multiplication (v1 * 2.5): ";
    (v1 * 2.5).print();
    
    cout << "Vector Scalar Division (v2 / 2.0): ";
    (v2 / 2.0).print();
    
    cout << "Vector Power (v1^2): ";
    (v1^2).print();
    
    cout << "Vector Reverse (~v1): ";
    (~v1).print();
    
    // Compound operations
    Vector v3 = v1;
    cout << "Vector v3: ";
    v1.print();

    v3 += v2 += v2;
    cout << "\nCompound Addition (v3 += v2 += v2): ";
    v3.print();
    
    v3 *= 0.5 *+ 0.5;
    cout << "Compound Scalar Multiplication (v3 *= 0.5 *= 0.5): ";
    v3.print();

}

void testMatrices() {
    cout << "\n\n=== MATRIX DEMONSTRATION ===" << endl << endl;
    
    // Create matrices
    Matrix m1(2, 2);
    Matrix m2(2, 2);
    
    // Initialize matrices
    m1(0, 0) = 1.0; m1(0, 1) = 2.0;
    m1(1, 0) = 3.0; m1(1, 1) = 4.0;
    
    m2(0, 0) = 5.0; m2(0, 1) = 6.0;
    m2(1, 0) = 7.0; m2(1, 1) = 8.0;
    
    cout << "Matrix m1:" << endl;
    m1.print();
    cout << "\nMatrix m2:" << endl;
    m2.print();
    
    // Matrix operations
    cout << "\nMatrix Addition (m1 + m2):" << endl;
    (m1 + m2).print();
    
    cout << "\nMatrix Subtraction (m1 - m2):" << endl;
    (m1 - m2).print();
    
    cout << "\nMatrix Multiplication (m1 * m2):" << endl;
    (m1 * m2).print();
    
    cout << "\nMatrix Scalar Multiplication (m1 * 2.5):" << endl;
    (m1 * 2.5).print();
    
    cout << "\nMatrix Transpose (~m1):" << endl;
    (~m1).print();
    
    // Compound operations
    Matrix m3 = m1;
    m3 += m2;
    cout << "\nCompound Addition (m3 += m2 += m2):" << endl;
    m3.print();

    m3 *= m2;
    cout << "\nCompound Matrix Multiplication (m3 *= m2):" << endl;
    m3.print();
    
    m3 *= 0.5;
    cout << "\nCompound Scalar Multiplication (m3 *= 0.5):" << endl;
    m3.print();
    
    // Row access
    cout << "\nAccessing first row of m1 as vector:" << endl;
    Vector row = m1[0];
    row.print();
}

void testFileIO() {
    cout << "\n\n=== FILE I/O DEMONSTRATION ===" << endl << endl;
    
    // Write test data to files
    // ofstream outVec("vector.txt");
    // outVec << "1.1 2.2 3.3";
    // outVec.close();
    
    // ofstream outMat("matrix.txt");
    // outMat << "1.1 2.2\n3.3 4.4\n5.5 6.6";
    // outMat.close();
    
    // Read vector from file
    Vector fileVec(3);
    ifstream inVec("vector.txt");
    fileVec.readFile(inVec);
    inVec.close();
    
    cout << "Vector read from file:" << endl;
    fileVec.print();
    
    // Read matrix from file
    Matrix fileMat(3, 2);
    ifstream inMat("matrix.txt");
    fileMat.readFile(inMat);
    inMat.close();
    
    cout << "\nMatrix read from file:" << endl;
    fileMat.print();
}

int main() {
    testVectors();
    testMatrices();
    testFileIO();
    
    cout << "Press ENTER to exit";
    cin.get();
    
    return 0;
}
# Matrix and Vector Operations
A C++ program that implements Matrix and Vector classes with comprehensive mathematical operations.

## Features
- Vector operations: addition, subtraction, scalar multiplication/division, power, reverse
- Matrix operations: addition, subtraction, multiplication, scalar operations, transpose
- File I/O support for both vectors and matrices
- Error handling for invalid operations

## How to Compile and Run
### 1. Prerequisites:
- A C++ compiler (g++ recommended)
- Make sure all files are in the same directory:
- main.cpp (the demonstration program)
- arithmetic.h, arithmetic.cpp
- vector.h, vector.cpp
- matrix.h, matrix.cpp

### 2. Compilation
	g++ -std=c++11 main.cpp arithmetic.cpp vector.cpp matrix.cpp -o matrix_demo

### 3. Execution
	./matrix_demo

### 4. Expected Output:
The program will demonstrate:
- Vector operations
- Matrix operations
- File I/O functionality

## File Structure
- arithmetic.h/cpp: Base abstract class
- vector.h/cpp: Vector implementation
- matrix.h/cpp: Matrix implementation
- main.cpp: Demonstration program

## Customization
You can modify the main.cpp file to test different operations or create your own program using the provided classes.

## Notes
- Error messages will be displayed for invalid operations (like adding vectors of different sizes).
- This implementation was created for educational purposes.  

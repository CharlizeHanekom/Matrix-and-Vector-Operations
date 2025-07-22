#include <iomanip>
#include "matrix.h"

using namespace std;

    Matrix::Matrix(unsigned r, unsigned c): Arithmetic::Arithmetic()
    {
        rows = r;
        cols = c;
        matrix = new double*[r];
        for (unsigned i = 0; i < r; i++){
            matrix[i] = new double[cols];
        }
        for (unsigned i = 0; i < r; i++){
            for (unsigned j = 0; j < cols; j++)
                {matrix[i][j] = 0;}
        }
    }

    Matrix::Matrix(const Matrix& rhs){
        rows = rhs.rows;
        cols = rhs.cols;
        matrix = new double*[rows];
        for (unsigned i = 0; i < rows; i++) 
        {
            matrix[i] = new double[cols];
        }
        for (unsigned i = 0; i < rows; i++) 
        {
            for (unsigned j = 0; j < cols; j++) 
            {
                matrix[i][j] = rhs.matrix[i][j];
            }
        }  
    }

    Matrix::~Matrix(){
        for(unsigned i = 0; i< rows; ++i) {
            delete[] matrix[i];  
        }
        delete[] matrix;
    }

//********************************************************************************************

    void Matrix::print()
    {
        for (unsigned i = 0; i < rows; i++)
        {
            for (unsigned j = 0;j < cols; j++)
            {
                cout << setprecision(3) << setw(10) << matrix[i][j];
            }
            cout << endl;
        }
    }

    void Matrix::readFile(istream &infile){
        for (unsigned i = 0; i < rows; i++) {
            for (unsigned j = 0; j < cols; j++) {
                infile >> matrix[i][j];
            }
        }
    }

//********************************************************************************************

    // Insert overloaded = operator signature
    const Matrix& Matrix::operator=(const Matrix& rhs){
        if(&rhs == this) 
                return *this;
        for (unsigned i = 0; i < rows; i++) 
        {
            delete[] matrix[i];
        }
        delete matrix;

        rows = rhs.rows;
        cols = rhs.cols;
        matrix = new double*[rows];
        for (unsigned j =0;j < cols; j++)
        {
            matrix[j] = new double[cols];
        }
        for (unsigned i =0;i < rows; i++)
            {
                for (unsigned j =0;j < cols; j++)
                {
                    matrix[i][j] = rhs.matrix[i][j];
                }
            }
            return *this;       
    }

///////////////////////////////////////////////////////////////////////////////////////////////

    // Matrix mathematical operations
    Matrix Matrix::operator+(const Matrix& rhs)
    {
        try {
            if((rows != rhs.rows)||(cols != rhs.cols))
            {
                throw(1);
            }else{
                Matrix *temp = new Matrix(rows,cols);
                for (int i =0;i < rows; i++)
                {
                    for (int j =0;j < cols; j++)
                    {
                        temp->matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
                    }
                }

                return *temp;             
            }
        }
        catch (int beans){
            cout << "Error: adding matrices of different dimensionality";
            Matrix* except = new Matrix(0,0);
            except = NULL;
            return *except;
        }
    }

//********************************************************************************************

    Matrix& Matrix::operator+=(const Matrix& rhs)
    {
        try {
            if((rows != rhs.rows)||(cols != rhs.cols))
            {
                throw(1);
            }else{
                for (int i =0;i < rows; i++)
                {
                    for (int j =0;j < cols; j++)
                    {
                        matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
                    }
                }

                return *this;             
            }
        }
        catch (int beans){
            cout << "Error: adding matrices of different dimensionality";
            Matrix* except = new Matrix(0,0);
            except = NULL;
            return *except;
        }
    }

//********************************************************************************************

    Matrix Matrix::operator-(const Matrix& rhs)
    {
        try {
            if((rows != rhs.rows)||(cols != rhs.cols))
            {
                throw(1);
            }else{
                Matrix *temp = new Matrix(rows,cols);
                for (int i =0;i < rows; i++)
                {
                    for (int j =0;j < cols; j++)
                    {
                        temp->matrix[i][j] = matrix[i][j] - rhs.matrix[i][j];
                    }
                }
                return *temp;             
            }
        }
        catch (int beans){
            cout << "Error: subtracting matrices of different dimensionality";
            Matrix* except = new Matrix(0,0);
            except = NULL;
            return *except;
        }
    }

//********************************************************************************************

    Matrix& Matrix::operator-=(const Matrix& rhs){
        try {
            if((rows != rhs.rows)||(cols != rhs.cols))
            {
                throw(1);
            }else{
                for (int i =0;i < rows; i++)
                {
                    for (int j =0;j < cols; j++)
                    {
                        matrix[i][j] = matrix[i][j] - rhs.matrix[i][j];
                    }
                }
                return *this;             
            }
        }
        catch (int beans){
            cout << "Error: subtracting matrices of different dimensionality";
            Matrix* except = new Matrix(0,0);
            except = NULL;
            return *except;
        }
    }

//********************************************************************************************

    Matrix Matrix::operator*(const Matrix& rhs)
    {
        try {
            if(cols != rhs.rows)
            {
                throw(1);
            }else{
                Matrix temp = Matrix(rows,rhs.cols);
                for (int i = 0; i < rows; i++){
                    for (int j = 0; j < rhs.cols; j++){   
                        for (int k = 0; k < cols; k++)
                        {
                            temp(i,j) += (matrix[i][k] * rhs.matrix[k][j]);
                        }
                    }
                }

                return temp;             
            }
        }
        catch (int beans){
            cout << "Error: invalid matrix multiplication";
            Matrix* except = new Matrix(0,0);
            except = NULL;
            return *except;
        }
    }

//********************************************************************************************

    Matrix& Matrix::operator*=(const Matrix& rhs)
    {
        try {
            if(cols != rhs.rows)
            {
                throw(1);
            }else{
                Matrix *temp = new Matrix(rows,rhs.cols);
                double num;
                for (int i = 0; i < rows; i++){
                    for (int j = 0; j < rhs.cols; j++){   
                        for (int k = 0; k < cols; k++)
                        {
                            temp->matrix[i][j] += (matrix[i][k] * rhs.matrix[k][j]);
                        }
                    }
                }
                *this = *temp;

                return *this;             
            }
        }
        catch (int beans){
            cout << "Error: invalid matrix multiplication";
            Matrix* except = new Matrix(0,0);
            except = NULL;
            return *except;
        }  
    }

//********************************************************************************************

    Matrix Matrix::operator^(int pow){return *this;}

//********************************************************************************************

    Matrix& Matrix::operator^=(int pow){return *this;}

//********************************************************************************************

    // transpose
    Matrix Matrix::operator~()
    {
        Matrix *temp = new Matrix(cols,rows);
            for (int i =0;i < rows; i++)
            {
                for (int j =0;j < cols; j++)
                {
                    temp->matrix[j][i] = matrix[i][j];
                }
            }

            return *temp;             
    }

/////////////////////////////////////////////////////////////////////////////////////////////// 

    // Matrix/scalar operations
    Matrix Matrix::operator*(const double& rhs){
        Matrix *temp = new Matrix(rows,cols);
        for (int i =0;i < rows; i++)
        {
            for (int j =0;j < cols; j++)
            {
                temp->matrix[i][j] = matrix[i][j] * (rhs);
            }
        }
        return *temp;             
    }

//********************************************************************************************

    Matrix& Matrix::operator*=(const double& rhs)
    {
        for (int i =0;i < rows; i++)
        {
            for (int j =0;j < cols; j++)
            {
                matrix[i][j] = matrix[i][j] * (rhs);
            }
        }

        return *this;             
    }

//********************************************************************************************

    Matrix Matrix::operator/(const double& rhs)
    {
        Matrix *temp = new Matrix(rows,cols);
        for (int i =0;i < rows; i++)
        {
            for (int j =0;j < cols; j++)
            {
                temp->matrix[i][i] = matrix[i][j] / (rhs);
            }
        }
        return *temp;          
    }
 
///////////////////////////////////////////////////////////////////////////////////////////////

    // Access the individual elements
    double& Matrix::operator()(unsigned r, unsigned c){
        if (r >= rows) 
        {
            throw "Error: invalid row index";
        }
        else if (c >= cols) 
        {
            throw "Error: invalid column index";
        }
        else 
        {
            return matrix[r][c];
        }
    } 

    const double& Matrix::operator()(const unsigned r, const unsigned c) const{
        if (r >= rows) 
        {
            throw "Error: invalid row index";
        }
        else if (c >= cols) 
        {
            throw "Error: invalid column index";
        }
        else 
        {
            return matrix[r][c];
        }
    } 

    Vector Matrix::operator[](const unsigned r) const{
        Vector rowVect(getCols());
        for (unsigned i = 0; i < getCols(); i++) {
            rowVect[i] = matrix[r][i];
        }
        return rowVect;
    }

  
///////////////////////////////////////////////////////////////////////////////////////////////

    // Getters and setters:
    unsigned Matrix::getRows() const{
        return rows;
    }   

    unsigned Matrix::getCols() const{
        return cols;
    }
  
///////////////////////////////////////////////////////////////////////////////////////////////

    // Linear equations:
    Matrix Matrix::operator|(const Matrix& rhs)
    {
        return *this;
    }

    Matrix& Matrix::operator|=(Matrix& rhs)
    {
        return *this;
    }

///////////////////////////////////////////////////////////////////////////////////////////////

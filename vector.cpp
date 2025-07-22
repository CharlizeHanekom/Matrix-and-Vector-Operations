#include <iomanip>
#include "vector.h"
using namespace std;

    Vector::Vector(unsigned s): Arithmetic::Arithmetic()
    {
        size = s;
        vector = new double[size];
        for (unsigned j =0;j < size; j++)
                {vector[j] = 0;}
    }

    Vector::Vector(const Vector& rhs)
    {   
        size =rhs.size;
        vector = new double[size] ();
        for (unsigned i = 0; i < size;i++)
        {
            vector[i] = rhs.vector[i];
        }
    }

    Vector::~Vector()
    {
        delete[] vector;
    }

//********************************************************************************************

    void Vector::print()
    {   
        for (unsigned i=0; i <size;i++)
        {
            cout << setprecision(3) << setw(10) << vector[i];
        }
        cout << endl;
    }

    void Vector::readFile(istream &infile)
    {
        for (unsigned j = 0; j < size; j++) {
            infile >> vector[j];
        }
    }

//********************************************************************************************

    // Insert overloaded = operator signature
    const Vector& Vector::operator=(const Vector& rhs)
    {
        if(&rhs == this) 
            return *this;
        delete[] vector; 
        size = rhs.size;
        vector = new double[size];
        for (unsigned i=0; i < size;i++)
        {
            vector[i] = rhs.vector[i];
        }
        return *this;
    }

///////////////////////////////////////////////////////////////////////////////////////////////

    // Vector mathematical operations
    Vector Vector::operator+(const Vector& rhs)
    {   try{
            if(this->size != rhs.size)
                {throw 1;}
            else {
                Vector *temp = new Vector(size);
                 for (int i = 0; i < size; i++)
                    {
                        temp->vector[i] = this->vector[i] + rhs.vector[i];
                    }
                    return *temp;
            }
        }
        catch (int beans){
            cout << "Error: adding vectors of different dimensionality";
            Vector* except = new Vector(0);
            except = NULL;
            return *except;
        }
    }

//********************************************************************************************

    Vector& Vector::operator+=(const Vector& rhs)
    {
        try{

            if(this->size != rhs.size)
                {throw 1;}
            else {    
                 for (int i=0; i <size;i++)
                    {
                        this->vector[i] =  this->vector[i]+ rhs.vector[i];
                    }
                    return *this;
            }   
        }
        catch (int beans){
            cout << "Error: adding vectors of different dimensionality";
            Vector* except = new Vector(0);
            except = NULL;
            return *except;
        }
    }

//********************************************************************************************

    Vector Vector::operator-(const Vector& rhs)
    {
        try{

            if(this->size != rhs.size)
                {throw 1;}
            else {    
                Vector *temp = new Vector(size);
                 for (int i=0; i <size;i++)
                    {
                        temp->vector[i] = this->vector[i] - rhs.vector[i];
                    }
                    return *temp;
            }   
        }
        catch (int beans){
            cout << "Error: subtracting vectors of different dimensionality";
            Vector* except = new Vector(0);
            except = NULL;
            return *except;
        }
    }

//********************************************************************************************

    Vector& Vector::operator-=(const Vector& rhs)
    {
         try{

            if(this->size != rhs.size)
                {throw 1;}
            else {    
                 for (int i=0; i <size;i++)
                    {
                        this->vector[i] =  this->vector[i]- rhs.vector[i];
                    }
                    return *this;
            }   
        }
        catch (int beans){
            cout << "Error: subtracting vectors of different dimensionality";
            Vector* except = new Vector(0);
            except = NULL;
            return *except;
        }

    }

//********************************************************************************************

    Vector Vector::operator^(int pow)
    {
         try{
            if(pow < 0)
                {throw 1;}
            else {    
                Vector *tempy = new Vector(size);
                double temp;
                for (int i=0; i <size;i++)
                    {
                        temp = this->vector[i];
                        for (int j=1; j<pow;j++)
                            {
                                temp = temp * this->vector[i] ;
                            }
                    tempy->vector[i] = temp;
                    }
            return *tempy;
            }
        }
        catch (int beans){
            cout << "Error: negative power is not supported";
            Vector* except = new Vector(0);
            except = NULL;
            return *except;        
        }
    }

//********************************************************************************************

    Vector& Vector::operator^=(int pow)
    {
         try{

            if(pow < 0)
                {throw 1;}
            else {    
        
                double temp = this->vector[0];
                 for (int i=1; i <size;i++)
                    {
                        temp = this->vector[i];
                          for (int j=1; j<size;j++)
                    {
                        temp = temp * pow ;
                    }
                    this->vector[i] = temp;
                    }
             return *this;
            }
        }
        
        
        catch (int beans){
            cout << "Error: negative power is not supported";
            Vector* except = new Vector(0);
            except = NULL;
            return *except;
        }
    }

//********************************************************************************************

    Vector Vector::operator~()
    {
        double* temp = new double[size];
        for (int i=0; i <size;i++)
            {
                temp[i] =  this->vector[i];
            }
        for (int i=0; i <size;i++)
            {
                this->vector[i] = temp[size-(i+1)];
            }   
                return *this;       
                    
    } // reverse
    
///////////////////////////////////////////////////////////////////////////////////////////////

    // Vector/scalar operations
    Vector Vector::operator*(const double& rhs)
    {    Vector* temp = new Vector(size);
        for (int i=0; i <size;i++)
            {
                temp->vector[i] =  this->vector[i] * (rhs);
            }
        return *temp;
    }

//********************************************************************************************

    Vector& Vector::operator*=(const double& rhs)
    {
        for (int i=0; i <size;i++)
            {
                this->vector[i] =  this->vector[i] * (rhs);
            }
        return *this;
    }

//********************************************************************************************

    Vector Vector::operator/(const double& rhs)
    {
        try{
            if(rhs == 0)
                {throw 1;}
            else {    
                Vector *temp = new Vector(size);
                for (int i=0; i <size;i++)
                {
                    temp->vector[i] = this->vector[i] / rhs;
                }
                return *temp;
            }
        }
        catch (int beans){
            cout << "Error: division by zero";
            Vector* except = new Vector(0);
            except = NULL;
            return *except;
        }
    }

///////////////////////////////////////////////////////////////////////////////////////////////

    // Access the individual elements
    double& Vector::operator[](const unsigned r)
    {
        if(r < size)
            return vector[r];
        else {
            throw "Error: invalid row index";
        }
    }

    const double& Vector::operator[](const unsigned r) const
    {
        if(r < size)
            return vector[r];
        else {
            throw "Error: invalid row index";
        }
    }

/////////////////////////////////////////////////////////////////////////////////////////////// 

    // Getters and setters:
    unsigned Vector::getSize() const
    {
        return size;
    }

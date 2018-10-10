// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 1
// Program: CS213-2018-A1-T1-P1
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
//#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
    int* data;       // Pointer to 1-D array that will simulate matrix
    int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);
void deleteMatrix(matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
// new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
// matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
matrix   operator++ (matrix& mat,int);   	// Add 1 to each element ++mat
matrix   operator-- (matrix& mat,int);    	// Sub 1 from each element --mat
matrix   operator++ (matrix& mat);   	// Add 1 to each element ++mat
matrix   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
// Print matrix  as follows (2 x 3)			4	 6 	  8
// and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose
int	   item     (matrix mat,int row,int col);
//__________________________________________

int main()
{
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};
    int data4 [] = {1,1,2,2,3,4,5,6,7,8};
    int data5 [] = {13,233,3,4,5,6};
    int data6 [] = {10,100,10,100,10,100,10,100,10,100,1,14};
    int data7 [] = {1,2,3,4,5,6,7,8,9};
    int data8 [] = {1,3,5,3,4,10,5,10,7};
    int data9 [] = {1,0,0,0,1,0,0,0,1};

    matrix mat1, mat2, mat3, mat4, mat5, mat6, mat7, mat8, mat9;
    createMatrix (4, 2, data1, mat1 );
    createMatrix (2, 3, data2, mat2 );
    createMatrix (4, 2, data3, mat3 );
    createMatrix (5, 2, data4, mat4 );
    createMatrix (2, 3, data5, mat5 );
    createMatrix (3, 4, data6, mat6 );
    createMatrix (3, 3, data7, mat7 );
    createMatrix (3, 3, data8, mat8 );
    createMatrix (3, 3, data9, mat9 );

    cout << " \nMAT 1 : \n" << mat1 ;
    cout << " \nMAT 2 : \n" << mat2 ;
    cout << " \nMAT 3 : \n" << mat3 ;
    cout << " \nMAT 4 : \n" << mat4 ;
    cout << " \nMAT 5 : \n" << mat5 ;
    cout << " \nMAT 6 : \n" << mat6 ;
    cout << " \nMAT 7 : \n" << mat7 ;
    cout << " \nMAT 8 : \n" << mat8 ;
    cout << " \nMAT 9 : \n" << mat9 ;
    int student = 5 ;
    cout << "\n\nEnter num of student : " ;
    cin >> student ;

    if (student == 1){
        cout << "\nPlus : \n" ;
        cout << "Matrix 1 + Matrix 3 : \n" << mat1 + mat3 << endl;
        cout << "Matrix 1 + Matrix 2 : \n" << mat1 + mat2 << endl;

        cout << "\nMinus  \n" ;
        cout << "Matrix 1 - Matrix 3 : \n" << mat1 - mat3 << endl;
        cout << "Matrix 1 - Matrix 2 : \n" << mat1 - mat2 << endl;

        cout << "\nAdd Scalar \n" ;
        cout << "Matrix 1 + 5 :\n" ;
        cout << mat1 + 5;

        cout << "\nSubtract Scalar \n" ;
        cout << "Matrix 1 - 5 :\n" ;
        cout << mat1 - 5 ;

        cout << "\nMultiply Scalar \n" ;
        cout << "Matrix 1 * 5 :\n" ;
        cout << mat1 * 5 ;


        cout << "\nMatrix multiplication : \n" ;
        cout << "Matrix 1 * Matrix 2 \n" ;
        cout << mat1 * mat2 ;

        cout << "\nMatrix 3 * Matrix 4 : \n" ;
        cout << mat3 * mat4 ;
    }

    else if (student == 2){
        cout << "\nPlus Equal : \n" ;
        cout << "Matrix 1 += Matrix 3 : \n" << (mat1 += mat3) << endl;
        mat1-=mat3 ;
        cout << "Matrix 1 += Matrix 2 : \n" << (mat1 += mat2) << endl;

        cout << "\nMinus Equal : \n" ;
        cout << "Matrix 1 -= Matrix 3 : \n" << (mat1 -= mat3) << endl;
        mat1 += mat3 ;
        cout << "Matrix 1 += Matrix 2 : \n" << (mat1 += mat2) << endl;

        cout << "\nplus Equal Scalar \n" ;
        cout << "Matrix 1 += 5 :\n" ;
        cout << (mat1 += 5);
        mat1 -= 5;

        cout << "\nMinus Equal Scalar \n" ;
        cout << "Matrix 1 -= 5 :\n" ;
        cout << (mat1 -= 5);
        mat1 += 5;

        cout << "\nPlus Plus Matrix \n" ;
        cout << "++ Matrix 1 \n" ;
        cout << ++ mat1 ;
        mat1 --;

        cout << "\nMatrix Plus Plus\n" ;
        cout << "Matrix 1 ++\n" ;
        cout << mat1 ++ ;
        cout << "\nMatrix 1 : \n" ;
        cout << mat1 ;
        mat1 -- ;

        cout << "\nMinus Minus Matrix \n" ;
        cout << "-- Matrix 1 \n" ;
        cout << -- mat1 ;
        mat1 ++;

        cout << "\nMatrix Minus Minus\n" ;
        cout << "Matrix 1 --\n" ;
        cout << mat1 -- ;
        cout << "\nMatrix 1 : \n" ;
        cout << mat1 ;
        mat1 ++ ;


        cout << "\nInput (Cin >> Matrix)\n" ;
        cout << "Rows : " ;
        cin >> mat1.row ;
        cout << "Columns : " ;
        cin >> mat1.col ;
        cout << endl ;
        cin >> mat1 ;
        cout << endl;
        cout << mat1 ;
    }

    else if (student == 3)
    {
    cout << "\n\nIs Equal: \n" ;
    cout << (mat1==mat2) << "      " << (mat1!=mat2) << endl ;
    cout << (mat2==mat5) << "      " << (mat2!=mat5) << endl ;
    cout << (mat3==mat6) << "      " << (mat3!=mat6) << endl ;
    cout << (mat1==mat4) << "      " << (mat1!=mat4) << endl ;
    cout << (mat6==mat3) << "      " << (mat6!=mat3) << endl ;
    cout << (mat6==mat8) << "      " << (mat6!=mat8) << endl ;
    cout << (mat2==mat1) << "      " << (mat2!=mat1) << endl ;

    cout << "\n\nIs Square: \n" ;
    cout << "Matrix 1 : " << isSquare(mat1) << endl ;
    cout << "Matrix 7 : " << isSquare(mat7) << endl ;

    cout << "\n\nSymmetric: \n" ;
    cout << "Mat 1 : " << isSymetric(mat1) << endl ;
    cout << "Mat 2 : " << isSymetric(mat2) << endl ;
    cout << "Mat 3 : " << isSymetric(mat3) << endl ;
    cout << "Mat 4 : " << isSymetric(mat4) << endl ;
    cout << "Mat 5 : " << isSymetric(mat5) << endl ;
    cout << "Mat 6 : " << isSymetric(mat6) << endl ;
    cout << "Mat 7 : " << isSymetric(mat7) << endl ;
    cout << "Mat 8 : " << isSymetric(mat8) << endl ;
    cout << "Mat 9 : " << isSymetric(mat9) << endl ;

    cout << "\n\nIdentity: \n" ;
    cout << "Mat 1 : " << isIdentity(mat1) << endl ;
    cout << "Mat 2 : " << isIdentity(mat2) << endl ;
    cout << "Mat 3 : " << isIdentity(mat3) << endl ;
    cout << "Mat 4 : " << isIdentity(mat4) << endl ;
    cout << "Mat 5 : " << isIdentity(mat5) << endl ;
    cout << "Mat 6 : " << isIdentity(mat6) << endl ;
    cout << "Mat 7 : " << isIdentity(mat7) << endl ;
    cout << "Mat 8 : " << isIdentity(mat8) << endl ;
    cout << "Mat 9 : " << isIdentity(mat9) << endl ;

    cout << "\n\nTranspose:\n" ;
    cout << "Mat 1 \n" << mat1  << endl << "Transpose of 1: \n" << transpose(mat1) <<endl ;
    cout << "Mat 7 \n" << mat7  << endl << "Transpose of 7: \n" << transpose(mat7) <<endl ;
    cout << "Mat 8 \n" << mat8  << endl << "Transpose of 8: \n" << transpose(mat8) <<endl ;
    cout << "Mat 9 \n" << mat9  << endl << "Transpose of 9: \n" << transpose(mat9) <<endl ;
    }

    else
        cout << "Error" ;

    return 0;
    deleteMatrix(mat1);
    deleteMatrix(mat2);
    deleteMatrix(mat3);
    deleteMatrix(mat4);
    deleteMatrix(mat5);
    deleteMatrix(mat6);
    deleteMatrix(mat7);
    deleteMatrix(mat8);
    deleteMatrix(mat9);
    return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix(int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int[row * col];
    for (int i = 0; i < row * col; i++)
        mat.data[i] = num[i];
}


//Student 1

matrix operator+ (matrix mat1, matrix mat2)
{
    int mat10 [100] = {0} ;
    matrix Mat10 ;
    if (mat1.row == mat2.row && mat2.col == mat1.col )
    {
        for ( int i = 0 ; i < mat1.row * mat1.col ; i++)
        {
            mat10[i] = mat1.data[i] + mat2.data[i] ;
        }
    createMatrix(mat1.row, mat1.col, mat10, Mat10);
    return Mat10 ;
    }
    if (mat1.row != mat2.row || mat1.col == mat2.col)
    {
        cout << "Error , There are different in dimensions \n" ;
        createMatrix(mat1.row, mat1.col, mat10, Mat10);
        return Mat10 ;
    }
}
matrix operator-  (matrix mat1, matrix mat2)
{
    int mat11 [100] = {0} ;
    matrix Mat11 ;
    if (mat1.row == mat2.row && mat1.col == mat2.col)
    {
        for ( int i = 0 ; i < mat1.row * mat1.col ; i++)
        {
            mat11[i] = mat1.data[i] - mat2.data[i] ;
        }
    }
    else
    {
        cout << "Error , There are different in dimensions \n" ;

    }
    createMatrix(mat1.row, mat1.col, mat11, Mat11);
    return Mat11 ;
}
matrix operator+ (matrix mat1, int scalar)
{
    int mat12 [100] = {0} ;
    matrix Mat12 ;
    for (int i = 0 ; i < mat1.row*mat1.col ; i++ )
    {
        mat12 [i] = mat1.data[i] + scalar ;
    }
    createMatrix(mat1.row, mat1.col, mat12, Mat12);
    return Mat12 ;
}
matrix operator- (matrix mat1, int scalar)
{
    int mat13 [100] = {0} ;
    matrix Mat13 ;
    for (int i = 0 ; i < mat1.row*mat1.col ; i++ )
    {
        mat13 [i] = mat1.data[i] - scalar ;
    }
    createMatrix(mat1.row, mat1.col, mat13, Mat13);
    return Mat13 ;
}
matrix operator* (matrix mat1, int scalar)
{
    int mat14 [100] = {0} ;
    matrix Mat14 ;
    for (int i = 0 ; i < mat1.row*mat1.col ; i++ )
    {
        mat14 [i] = mat1.data[i] * scalar ;
    }
    createMatrix(mat1.row, mat1.col, mat14, Mat14);
    return Mat14 ;
}
matrix operator* (matrix mat1, matrix mat2)
{
    int mat15 [100] = {0}, z = 0, j = 0, i = 0, counter1 = 0, counter2 =0 ;
    matrix Mat15 ;
    if (mat1.col == mat2.row)
    {
        for (int matCount = 0 ; matCount < mat1.row ; matCount++)
        {
            for (int x = 0 ; x < mat2.col ; x++ )
            {
                for (int ColCount = 0 ; ColCount < mat1.col ; ColCount++ )
                {
                    mat15 [z] += mat1.data[i] * mat2.data[j] ;
                    i++ ;
                    j = j + mat2.col ;
                }
                counter1 = counter1 + 1 ;
                j = counter1 ;
                i = counter2 ;
                z++ ;
            }
            counter1 = 0 ;
            j = counter1 ;
            counter2 = counter2 + mat1.col ;
            i = counter2 ;
        }
        createMatrix(mat1.row, mat2.col, mat15, Mat15);
        return Mat15 ;
    }
    if (mat1.col != mat2.row) ;
    {
        cout << " The Matrix1 column isn't equal matrix2 row  " << endl ;
    }
    createMatrix(mat1.row, mat2.col, mat15, Mat15);
    return Mat15 ;
}





//Student 2
void deleteMatrix(matrix& mat)
{
    delete[] mat.data;
}
/* int item(matrix mat,int row,int col)
{
    return mat.data[col + row*mat.col];
}*/
matrix operator+= (matrix& mat1, matrix mat2)
{
    if (mat1.col == mat2.col && mat1.row == mat2.row)
    {
        for (int i = 0; i < mat1.col*mat1.row; i++)
            mat1.data[i] += mat2.data[i];
        return mat1;
    }
    else
    {
        cout << "Matrcies can't be added." << endl;
        return mat1;
    }

}
matrix operator-= (matrix& mat1, matrix mat2)
{
    if (mat1.col == mat2.col && mat1.row == mat2.row)
    {
        for (int i = 0; i < mat1.col*mat1.row; i++)
            mat1.data[i] -= mat2.data[i];
        return mat1;
    }
    else
    {
        cout << "Matrcies can't be subtracted." << endl;
        return mat1;
    }

}
matrix operator+= (matrix& mat, int scalar)
{
    for (int i = 0; i < mat.col*mat.row; i++)
        mat.data[i] += scalar;
    return mat;
}
matrix operator-= (matrix& mat, int scalar)
{
    for (int i = 0; i < mat.col*mat.row; i++)
        mat.data[i] -= scalar;
    return mat;
}
matrix operator++ (matrix& mat,int)
{
    matrix temp;
    createMatrix(mat.row, mat.col, mat.data, temp);
    for (int i = 0; i < mat.col*mat.row; i++)
        mat.data[i] ++;
    return temp;
}
matrix operator-- (matrix& mat,int)
{
    matrix temp;
    createMatrix(mat.row,mat.col,mat.data,temp);
    for (int i = 0; i < mat.col*mat.row; i++)
        mat.data[i] --;
    return temp;
}
matrix operator++ (matrix& mat)
{
    for (int i = 0; i < mat.col*mat.row; i++)
        mat.data[i] ++;
    return mat;
}
matrix operator-- (matrix& mat)
{
    for (int i = 0; i < mat.col*mat.row; i++)
        mat.data[i] --;
    return mat;
}
istream& operator >> (istream& in, matrix& mat)
{
    for (int i = 0; i < mat.row*mat.col; i++)
        in >> mat.data[i];
    return in;
}



// student # 3 : Khaled Ezzat

ostream& operator<< (ostream& out, matrix mat)
{
    int element =0 ;
    for (int i=0 ; i < mat.row ; i ++)
    {
        for ( int j = 0 ; j< mat.col ; j++ )
        {
            out << mat.data[element++] << "  " ;
        }
        out << endl ;
    }
    return out ;
}

bool   operator== (matrix mat1, matrix mat2)
{
    int same = 0;
    if ( mat1.row == mat2.row && mat1.col == mat2.col)
    {
        for(int i=0 ; i<mat1.row*mat1.col ; i++)
            if (mat1.data[i] == mat2.data[i])
                same = 1 ;
            else
            {
                same = 0 ;
                break ;
            }
    }
    return same ;
}

bool   operator!= (matrix mat1, matrix mat2)
{
    bool not_equal;
    if (mat1==mat2)
        not_equal = false ;
    else
        not_equal = true  ;
    return not_equal ;
}

bool   isSquare   (matrix mat)
{
    if (mat.row == mat.col)
        return true ;
    else
        return false ;
}

bool   isSymetric (matrix mat)
{
    bool symmetric = false ;

    if (isSquare(mat))
    {
        if ( transpose(mat) == mat )
            symmetric = true  ;
        else
            symmetric = false ;
    }
    return symmetric ;
}

bool   isIdentity (matrix mat)
{
    bool identity = true;
    if (isSquare(mat))
    {
        for (int i = 0 ; i < mat.row*mat.row ; i++)
            if( i%(mat.row+1) == 0 )
            {
                if(mat.data[i] != 1)   // for the Diagonal elements
                    identity = false ;
            }
            else
            {
                if(mat.data[i] != 0)   // not in the diagonal
                    identity = false;
            }
    }
    else
        identity = false ;
    return identity ;
}

matrix transpose(matrix mat)
{
    int transpose[100], add = mat.col, digit = 0;
    matrix Transpose ;

    for(int i=0 ; i<mat.col ; i++)
    {
        for(int j=0 ; j<mat.row ; j++)
        {
            transpose[digit++] = mat.data[i+add*j] ;
        }

    }

    createMatrix (mat.col, mat.row, transpose, Transpose);
    return Transpose ;
}







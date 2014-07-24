#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

namespace chittmatrix{
class Matrix
{
	int r, c;
	float *matrix;
	
 public:
 	Matrix()
 	{
 	}
 	
 	int GetRSize() { return r; }
 	int GetCSize() { return c; }
 	Matrix(float *a, int row, int col)
 	{
 		r = row;
 		c = col;
 		matrix = (float *)malloc(sizeof(float)*(row*col));	
		for(int i = 0; i<row; i++)
			for(int j = 0; j<col; j++)
				*(matrix + i*c + j) = *(a + i*col + j);
 	}
 	
 	void DisplayRC()
 	{
 		cout<<"\nRows: "<<r<<endl<<"Columns: "<<c<<endl;
 	}	
 	
	Matrix(int row, int col)
	{
		int i, j;
		r = row;
		c = col;
		matrix = (float *)malloc(sizeof(float)*(r*c));
		for(i = 0; i<row; i++)
			for(j = 0; j<col; j++)
				*(matrix + i*col + j) = 0;
	}
	
	void Zeroes(int row, int col)
	{
		int i, j;
		r = row;
		c = col;
		matrix = (float *)malloc(sizeof(float)*(r*c));
		for(i = 0; i<row; i++)
			for(j = 0; j<col; j++)
				*(matrix + i*col + j) = 0;
	}
	
	~Matrix()
	{
		//delete matrix;		
	}
	
	void Display(void)
	{
		int i, j;
		for(i = 0; i<r; i++)
		{
			for(j = 0; j<c; j++)
				printf("%0.2f  ", this->GetElement(i,j));
			printf("\n");
		}
	}
	
	void SetElement(int row, int col, float value)
	{
		*(matrix + (row*c) + col) = value; 
	}
	
	float GetElement(int row, int col)
	{
		return *(matrix + (row*c) + col);
	}
	
	void Get(void)
	{
		int i, j;
		printf("Getting Matrix input. Enter a %d by %d Matrix:\n", r, c);
		for(i = 0; i<r; i++)
			for(j = 0; j<c; j++)
				scanf("%f", &*(matrix + i*c + j));	
	}
	
/*	// Friends for Kalman.h
	friend Matrix enter_2d_Matrix(float a, float b, float c, float d);
	friend Matrix enter_2d_row_Matrix(float a, float b);
	friend Matrix enter_2d_column_Matrix(float a, float b);
	friend void kalman(float duration, float dt);
	// End
	// For partprogram.h
	friend Matrix pre_multiply33(Matrix, Matrix);
	friend Matrix post_multiply33(Matrix, Matrix);
	friend Matrix add33(Matrix, Matrix);
	friend Matrix multiplyRow3(Matrix, Matrix);
	friend Matrix Squarify(Matrix);
	friend void init_xp();
	friend class landmark;
	friend int main();
	// ENd 
	// extra functions
	friend Matrix Covar(Matrix, int);
	friend void kalmanUpdate(Matrix, Matrix);
	float getState(int);
	
	// end of all extra friends */
	
	
	friend chittmatrix::Matrix operator + (chittmatrix::Matrix a, chittmatrix::Matrix b);
	friend chittmatrix::Matrix operator - (chittmatrix::Matrix a, chittmatrix::Matrix b);
	friend chittmatrix::Matrix operator * (chittmatrix::Matrix a, chittmatrix::Matrix b);
	friend chittmatrix::Matrix operator * (chittmatrix::Matrix a, float b);
	friend chittmatrix::Matrix operator / (chittmatrix::Matrix a, float b);
	friend chittmatrix::Matrix operator * (float b, chittmatrix::Matrix a);
	friend chittmatrix::Matrix operator !(chittmatrix::Matrix a);
	friend chittmatrix::Matrix xpand(chittmatrix::Matrix a, int newr, int newc);
	friend float determinant2(chittmatrix::Matrix a);
	friend chittmatrix::Matrix inv2(chittmatrix::Matrix a);
	friend chittmatrix::Matrix cofactormatrix(chittmatrix::Matrix a, int x, int y);
	friend float cofactor(chittmatrix::Matrix a, int x, int y);
	friend float det(chittmatrix::Matrix a);
	friend chittmatrix::Matrix adjoint(chittmatrix::Matrix a);
	friend chittmatrix::Matrix operator ~(chittmatrix::Matrix a);
	friend chittmatrix::Matrix identity(int a);
	friend chittmatrix::Matrix inv(chittmatrix::Matrix);
	friend float delta(chittmatrix::Matrix);
	//friend int MedianFilter(chitmatrix::Matrix);
	// Yet another friend
	//friend struct player_point_2d TransferToGlobal(player_point_2d approx_LMpos, float X, float Y, float theta);
}; /* ***** End of class definition ***** */


/*---------------------------------------BASIC OPERATIONS '+', '-', '*', '/'------------------------------------------*/

/* Copy Matrix */

/* Overloaded '+' operator to add two matrices */
chittmatrix::Matrix operator + (chittmatrix::Matrix a, chittmatrix::Matrix b)
{
	chittmatrix::Matrix temp(a.r, b.c);
	int row = temp.r;
	int col = temp.c;
	
	
	for(int i = 0; i<row; i++)
		for(int j = 0; j<col; j++)
			*(temp.matrix + i*col + j) = (*(a.matrix + (i*a.c) + j)) + (*(b.matrix + (i*b.c) + j));
	
	return temp;
}

/* Overloaded '-' operator to subtract two matrices */
chittmatrix::Matrix operator - (chittmatrix::Matrix a, chittmatrix::Matrix b)
{
	chittmatrix::Matrix temp(a.r, b.c);
	int row = temp.r;
	int col = temp.c;
	
	for(int i = 0; i<row; i++)
		for(int j = 0; j<col; j++)
			*(temp.matrix + i*col + j) = (*(a.matrix + (i*a.c) + j)) - (*(b.matrix + (i*b.c) + j));
	
	return temp;
}

/* Overloaded '*' operator for scalar multiplication */
chittmatrix::Matrix operator * (chittmatrix::Matrix a, float b)
{
	int row, col, i, j;
	chittmatrix::Matrix temp(a.r, a.c);
	row = temp.r;
	col = temp.c;
	
	for(i = 0; i<row; i++)
		for(j = 0; j<col; j++)
			*(temp.matrix + i*col + j) = (*(a.matrix + (i*a.c) + j)) * b;
	return temp;
}

/* Overloaded '/' operator for scalar division */
chittmatrix::Matrix operator / (chittmatrix::Matrix a, float b)
{
	int row, col, i, j;
	chittmatrix::Matrix temp(a.r, a.c);
	row = temp.r;
	col = temp.c;
	
	for(i = 0; i<row; i++)
		for(j = 0; j<col; j++)
			*(temp.matrix + i*col + j) = (*(a.matrix + (i*a.c) + j)) / b;
	return temp;
}

/* Overloaded '*' operator for scalar multiplication ---- JUST IN CASE OPERANDS ARE PASSED REVERSE */ 
chittmatrix::Matrix operator * (float b, chittmatrix::Matrix a)
{
	int row, col, i, j;
	chittmatrix::Matrix temp(a.r, a.c);
	row = temp.r;
	col = temp.c;
	
	for(i = 0; i<row; i++)
		for(j = 0; j<col; j++)
			*(temp.matrix + i*col + j) = (*(a.matrix + (i*a.c) + j)) * b;
	return temp;
}

/* Overloaded '*' operator for multiplying two matrices */
chittmatrix::Matrix operator * (chittmatrix::Matrix a, chittmatrix::Matrix b)
{
	int row, col;
	if(a.c != b.r)
	{
		printf("Error. Matrices being multiplied are not compatible. Quiting...\n");
		getchar();
		exit(0);
	}
	chittmatrix::Matrix temp(a.r, b.c);
	row = temp.r;
	col = temp.c;
	
	for(int i = 0; i<row; i++)
		for(int j = 0; j<col; j++)
			for(int k = 0; k<a.c; k++)
				*(temp.matrix + i*col + j) += (*(a.matrix + (i*a.c) + k)) * (*(b.matrix + (k*b.c) + j));
	return temp;
}

/* Overloaded '!' operator for transpose */
chittmatrix::Matrix operator !(chittmatrix::Matrix a)
{
	int row = a.r;
	int col = a.c;
	
	chittmatrix::Matrix temp(col, row);
	for(int i = 0; i<temp.r; i++)
		for(int j = 0; j<temp.c; j++)
			*(temp.matrix + i*temp.c + j) = *(a.matrix + j*col + i);

	return temp;
}

/* Determinant of a 2 by 2 matrix */
float determinant2(chittmatrix::Matrix a)
{
	return (  ((*(a.matrix + 0)) * (*(a.matrix + 3))) - ((*(a.matrix + 1)) * (*(a.matrix + 2)))  );
}

chittmatrix::Matrix inv2(chittmatrix::Matrix a)
{
	int col = a.c;
	int row = a.r;
	
	chittmatrix::Matrix temp(row, col);
	*(temp.matrix + 0*temp.c + 0) = (*(a.matrix + 1*col + 1))/determinant2(a);
	*(temp.matrix + 0*temp.c + 1) = (-1* (*(a.matrix + 0*col + 1)))/determinant2(a);
	*(temp.matrix + 1*temp.c + 0) = (-1* (*(a.matrix + 1*col + 0)))/determinant2(a);
	*(temp.matrix + 1*temp.c + 1) = (*(a.matrix + 0*col + 0))/determinant2(a);
	
	return temp;
}

/* Get the cofactor matrix of a particular matrix element */	
chittmatrix::Matrix cofactormatrix(chittmatrix::Matrix a, int x, int y)
{	
	if(a.r!=a.c)
	{
		printf("Error: chittmatrix::Matrix is not square. Quitting...\n");
		exit(0);
	}
	int i, j, ii = 0, jj = 0;
	int col = a.c;
	int row = a.r;
	chittmatrix::Matrix temp(row-1, col-1);
	for(i = 0; i<row-1; i++)
	{
		if(ii == x)
			ii++;
		if(ii == row) ii = 0;
		if(ii == x)
			ii++;
		
		for(j = 0; j<col-1; j++)
		{
			if(jj == y)
				jj++;
			
			if(jj == col) jj = 0;
			
			if(jj == y)
				jj++;
			
			*(temp.matrix + (i*(col-1)) + j) = *(a.matrix + (ii*col) + jj);
			jj++;
		}
		ii++;
	}
	return temp;
}

/* Get the cofactor (scalar) of a particular matrix element */
float cofactor(chittmatrix::Matrix a, int x, int y)
{
	int test = (a.r*x + y);
	int minus = 1;
	int i = 0;
	if(a.r!=a.c)
	{
		printf("Error: chittmatrix::Matrix is not square. Hence Zero returned.\n");
		return 0;
	}
	if(a.r == 2)
	{
		switch(test)
		{
			case 0:
			 return *(a.matrix + 3);
			case 1:
			 return ((-1)*(*(a.matrix + 2)));
			case 2:
			 return ((-1)*(*(a.matrix + 1)));
			case 3:
			 return *(a.matrix + 0);
		}
	}		 
	chittmatrix::Matrix temp1;
	temp1 = cofactormatrix(a, x, y);
	
	for(i = 0; i< (x+y); i++)	minus *= -1;
	
	return (det(temp1)*minus);
}

/* Determinant of a small matrix (max. dimension = 10 x 10)*/
float det(chittmatrix::Matrix a)
{
	if(a.r!=a.c)
	{
		printf("Error: chittmatrix::Matrix is not square. Hence Zero returned.\n");
		return 0;
	}	
	float delta = 0.0000;
	int j;
	if(a.r==1)
		return *(a.matrix);
	if(a.r==2)
	{
		return determinant2(a);
	}	
	for(j = 0; j< a.c; j++)
	{
		if((*(a.matrix + 0*a.c + j)) == 0) continue;
		delta += (*(a.matrix + 0*a.c + j))*(cofactor(a, 0, j));
	}
	return delta;
}

/* Adjoint of Matrix */
chittmatrix::Matrix adjoint(chittmatrix::Matrix a)
{
	if(a.r!=a.c)
	{
		printf("Error: Matrix is not square. Hence NULL Pointer returned.\n");
		exit(0);
	}
	int col = a.c;
	int row = a.r;
	int i, j;
	chittmatrix::Matrix temp1(row, col);
	
	for(i = 0; i<temp1.r; i++)
		for(j = 0; j<temp1.c; j++)
			*(temp1.matrix + i*temp1.c + j) = cofactor(a, i, j);
	return temp1;
}

/* Inverse for a small chittmatrix::Matrix (max. dimension = 10 x 10)*/
chittmatrix::Matrix inv(chittmatrix::Matrix a)
{
	if(a.r!=a.c)
	{
		printf("Error: chittmatrix::Matrix is not square. Hence NULL Pointer returned.\n");
		exit(0);
	}
	return (!(adjoint(a)) / det(a));
}

/* Create an identity matrix */
chittmatrix::Matrix identity(int a)
{
	chittmatrix::Matrix mat(a,a);
	
	for(int i = 0; i<a; i++)
		for(int j = 0; j<a; j++)
		{
			if(i == j) *(mat.matrix + i*a + j) = 1;
			else *(mat.matrix + i*a + j) = 0;
		}
	return mat;
}	

/* Inverse for Large and small matrices */
chittmatrix::Matrix operator ~(chittmatrix::Matrix a)
{
	
	chittmatrix::Matrix temp(a.r,a.c);
	/* Save chittmatrix::Matrix a */
	for(int i = 0; i < a.r; i++)
		for(int j = 0; j<a.c; j++)
			*(temp.matrix + i*a.c + j) = *(a.matrix + i*a.c + j);
			
	float var, test;
	chittmatrix::Matrix b = identity(a.r);
	for(int j = 0; j< a.c; j++)
		for(int i = 0; i< a.r; i++)
		{
			if(i == j) continue;
				var = *(a.matrix + i*a.r + j);
				test = var/(*(a.matrix + j*a.r + j));
			
						
			for(int jj = 0; jj< a.r; jj++)
			{
				*(a.matrix + i*a.r + jj) -= (test)*(*(a.matrix + j*a.r + jj));
				*(b.matrix + i*a.r + jj) -= (test)*(*(b.matrix + j*b.r + jj));
			}
			
		}
		
	for(int i = 0; i<a.r; i++)
		for(int j = 0; j<a.c; j++)
		{
					
			*(b.matrix + i*a.c + j) = *(b.matrix + i*a.c + j)/ (*(a.matrix + i*a.c + i));
		}
	/* Restore a */
	for(int i = 0; i < a.r; i++)
		for(int j = 0; j<a.c; j++)
			*(a.matrix + i*a.c + j) = *(temp.matrix + i*a.c + j);
	return b;
}

/* Determinants of Larger matrices */

float delta(chittmatrix::Matrix a)
{
	float delta = 1.0000;
	chittmatrix::Matrix temp(a.r,a.c);
	/* Save chittmatrix::Matrix a */
	for(int i = 0; i < a.r; i++)
		for(int j = 0; j<a.c; j++)
			*(temp.matrix + i*a.c + j) = *(a.matrix + i*a.c + j);
			
	float var, test;
	chittmatrix::Matrix b = identity(a.r);
	for(int j = 0; j< a.c; j++)
		for(int i = 0; i< a.r; i++)
		{
			if(i == j) continue;
				var = *(a.matrix + i*a.r + j);
				test = var/(*(a.matrix + j*a.r + j));
			
						
			for(int jj = 0; jj< a.r; jj++)
			{
				*(a.matrix + i*a.r + jj) -= (test)*(*(a.matrix + j*a.r + jj));
				*(b.matrix + i*a.r + jj) -= (test)*(*(b.matrix + j*b.r + jj));
			}
			
		}
	
	for(int i = 0; i< a.r; i++)
		delta*=(*(a.matrix + i*a.r + i));
	/* Restore a */
	for(int i = 0; i < a.r; i++)
		for(int j = 0; j<a.c; j++)
			*(a.matrix + i*a.c + j) = *(temp.matrix + i*a.c + j);
	return delta;	
}

chittmatrix::Matrix xpand(chittmatrix::Matrix a, int newr, int newc)
{
	chittmatrix::Matrix temp(newr, newc);
	
	for(int i = 0; i<a.r; i++)
		for(int j = 0; j<a.c; j++)
			*(temp.matrix + newc*i + j) = *(a.matrix + a.c*i + j);	
	return temp;
}




/* For the Kalmaan */	
/*
Matrix enter_2d_Matrix(float a, float b, float c, float d)
{
	Matrix t;
	
	t.Zeroes(2,2);
	*(t.matrix + 0) = a;
	*(t.matrix + 1) = b;
	*(t.matrix + 2) = c;
	*(t.matrix + 3) = d;
	return t;
}

Matrix enter_2d_row_Matrix(float a, float b)
{
	Matrix t;
	
	t.Zeroes(1, 2);
	*(t.matrix + 0) = a;
	*(t.matrix + 1) = b;
	return t;
	
}		

Matrix enter_2d_column_Matrix(float a, float b)
{
	Matrix t;
	t.Zeroes(2, 1);
	*(t.matrix + 0) = a;
	*(t.matrix + 1) = b;
	return t;
	
}

Matrix pre_multiply33(Matrix a, Matrix b)
{
	int row, col, i, j, k;
	Matrix temp(b.r, b.c);
	
	row = temp.r;
	col = temp.c;
	
	
	
	for(i = 0; i<3; i++)
		for(j = 0; j<3; j++)
		{
			*(temp.matrix + i*col + j) = 0;
			for(k = 0; k<3; k++)
				*(temp.matrix + i*col + j) += (*(a.matrix + (i*a.c) + k)) * (*(b.matrix + (k*b.c) + j));
		}
			
	for(i = 0; i<temp.r; i++)
		for(j = 0; j<temp.c; j++)
		{
			if(i<3&&j<3) continue;
			*(temp.matrix + i*col + j) = *(b.matrix + (b.c)*(i) + j);
		}	
			
	return temp;
}

Matrix post_multiply33(Matrix b, Matrix a)
{
	int row, col, i, j, k;
	Matrix temp(b.r, b.c);
	
	row = temp.r;
	col = temp.c;
	
	
	
	for(i = 0; i<3; i++)
		for(j = 0; j<3; j++)
		{
			*(temp.matrix + i*col + j) = 0;
			for(k = 0; k<3; k++)
				*(temp.matrix + i*col + j) += (*(a.matrix + (k*a.c) + j)) * (*(b.matrix + (i*b.c) + k));
		}
			
	for(i = 0; i<temp.r; i++)
		for(j = 0; j<temp.c; j++)
		{
			if(i<3&&j<3) continue;
			*(temp.matrix + i*col + j) = *(b.matrix + (b.c)*(i) + j);
		}	
			
	return temp;
}

Matrix add33(Matrix a, Matrix b)
{
	
	Matrix temp(a.r, a.c);
	int row = temp.r;
	int col = temp.c;
	
	
	for(int i = 0; i<3; i++)
		for(int j = 0; j<3; j++)
			*(temp.matrix + i*col + j) = (*(a.matrix + (i*a.c) + j)) + (*(b.matrix + (i*b.c) + j));
	
	for(int i = 0; i<temp.r; i++)
		for(int j = 0; j<temp.c; j++)
		{
			if(i<3&&j<3) continue;
			*(temp.matrix + i*col + j) = *(a.matrix + (a.c)*(i) + j);
		}			
	
	return temp;
}

Matrix multiplyRow3(Matrix a, Matrix b)
{
	int row, col, i, j, k;
	Matrix temp(b.r, b.c);
	
	row = temp.r;
	col = temp.c;
	
	
	
	for(i = 0; i<3; i++)
		for(j = 0; j<col; j++)
		{
			*(temp.matrix + i*col + j) = 0;
			for(k = 0; k<3; k++)
				*(temp.matrix + i*col + j) += (*(a.matrix + (i*a.c) + k)) * (*(b.matrix + (k*b.c) + j));
		}
			
	for(i = 0; i<temp.r; i++)
		for(j = 0; j<temp.c; j++)
		{
			if(i<3) continue;
			*(temp.matrix + i*col + j) = *(b.matrix + (b.c)*(i) + j);
		}	
			
	return temp;
}	

Matrix Squarify(Matrix a)
{
	for(int i = 0; i< a.r; i++)
		for(int j = 0; j< a.c; j++)
			*(a.matrix + i*a.c + j) = *(a.matrix + j*a.c + i);
	
	return a;
}	
*/	
}

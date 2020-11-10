#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

const int MAX_SIZE_MATRIX = 3;
const int MAX_SIZE_SUBMATRIX = 2;
const int ROUNDING_FACTOR = 3;

const std::string ERROR_DETERMINANT_NULL = "The determinant = 0, it is impossible to invert the matrix";
const std::string ERROR_FILE_NOT_EXIST = "This file does not exist";
const std::string ERROR_NOT_ENOUGH_ARGUMENTS = "The number of arguments does not match the task condition\n"
"Input should look: invert.exe <matrix file>";



typedef float Matrix3x3[MAX_SIZE_MATRIX][MAX_SIZE_MATRIX];
typedef float Matrix2x2[MAX_SIZE_SUBMATRIX][MAX_SIZE_SUBMATRIX];

struct WrappedMatrix3x3 {
	Matrix3x3 items;
};

bool IsMatrixReader(Matrix3x3& matrix, std::string& fileName)
{
	std::ifstream fileInput(fileName);

	if (!fileInput.is_open())
	{
		return false;
	}

	for (int i = 0; i < MAX_SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < MAX_SIZE_MATRIX; ++j)
		{
			fileInput >> matrix[i][j];
		}
	}

	return true;
}

float DeterminantMatrix2x2(Matrix2x2& matrix)
{
	return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
}

float DeterminantMatrix3x3(Matrix3x3& matrix)
{
	float determinant = 0;
	determinant += matrix[0][0] * matrix[1][1] * matrix[2][2];
	determinant += matrix[0][1] * matrix[1][2] * matrix[2][0];
	determinant += matrix[0][2] * matrix[1][0] * matrix[2][1];
	determinant -= matrix[0][2] * matrix[1][1] * matrix[2][0];
	determinant -= matrix[0][0] * matrix[1][2] * matrix[2][1];
	determinant -= matrix[0][1] * matrix[1][0] * matrix[2][2];
	return determinant;
}

// minor matrix
void CalculationMatrix(Matrix3x3& transposeMatrix, Matrix3x3& matrixCalc)
{
	Matrix2x2 minorMatrix;
	int coefficient = 1;

	for (int i = 0; i < MAX_SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < MAX_SIZE_MATRIX; ++j)
		{
			for (int k = 0, l = 0; k < MAX_SIZE_MATRIX; ++k)
			{
				if (i != k)
				{
					for (int m = 0, n = 0; m < MAX_SIZE_MATRIX; ++m)
					{
						if (j != m)
						{
							minorMatrix[l][n] = transposeMatrix[k][m];
							++n;
						}
					}
					++l;
				}
			}

			matrixCalc[i][j] = coefficient * DeterminantMatrix2x2(minorMatrix);
			coefficient = -coefficient;
		}
	}
}

void MultiplyMatrixByNumber(Matrix3x3& inverseMatrix, Matrix3x3& matrix, const float multiplier)
{
	for (int i = 0; i < MAX_SIZE_MATRIX; i++)
	{
		for (int j = 0; j < MAX_SIZE_MATRIX; j++)
		{
			inverseMatrix[i][j] = matrix[i][j] * multiplier;
		}
	}
}

void GetTransposedMatrix(Matrix3x3& matrix)
{
	for (int i = 0; i < MAX_SIZE_MATRIX; i++)
	{
		for (int j = 0; j < MAX_SIZE_MATRIX && j < i; j++)
		{
			std::swap(matrix[i][j], matrix[j][i]);
		}
	}
}


bool IsInvertMatrix(Matrix3x3& matrix, Matrix3x3& inverseMatrix)
{
	float determinant = DeterminantMatrix3x3(matrix);

	if (determinant == 0)
	{
		return false;
	}

	GetTransposedMatrix(matrix);
	Matrix3x3 matrixCalc;
	CalculationMatrix(matrix, matrixCalc);
	MultiplyMatrixByNumber(inverseMatrix, matrixCalc, 1 / determinant);

	return true;
}

void PrintInvertMatrix(Matrix3x3& inverseMatrix)
{
	for (int i = 0; i < MAX_SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < MAX_SIZE_MATRIX; ++j)
		{
			std::cout << std::fixed << std::setprecision(ROUNDING_FACTOR) << inverseMatrix[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << ERROR_NOT_ENOUGH_ARGUMENTS << std::endl;
		return 1;
	}

	std::string fileName = argv[1];

	Matrix3x3 matrix;

	if (!IsMatrixReader(matrix, fileName))
	{
		std::cerr << ERROR_FILE_NOT_EXIST << std::endl;
		return 1;
	}

	Matrix3x3 inverseMatrix;

	if (!IsInvertMatrix(matrix, inverseMatrix))
	{
		std::cout << ERROR_DETERMINANT_NULL << std::endl;
		return 1;
	}

	PrintInvertMatrix(inverseMatrix);

	return 0;
}
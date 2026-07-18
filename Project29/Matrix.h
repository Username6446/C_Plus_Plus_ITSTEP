#pragma once
#include <iostream>

using namespace std;

template<typename T, size_t rows = 5, size_t cols = 5>
class Matrix {
private:
	T matrix[rows][cols];
public:
	Matrix(const T& value = T());
	void fill(const T& value = T());
	T minValue();
	T maxValue();
	T containValue(const T value = T());
	T sumOfElements() const;


	void print() const;

	T& operator() (int r, int c);
	Matrix<T> operator+(const Matrix& two);

	friend ostream& operator << (ostream& out, const Matrix<T, size, size>& obj) {
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t i = 0; i < cols; i++)
			{
				out << matrix[i][j] << "\t";
			}
			out << endl;
		}
	}
	friend istream& operator >> (sstream& in, Matrix<T, size, size>& obj) {
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t i = 0; i < cols; i++)
			{
				cout << "\nEnter " << i + 1 << "row, " << j + 1 << "element :: ";
				in >> matrix[i][j];
			}
			cout << endl;
		}
	}
};


template<typename T, size_t rows, size_t cols>
inline Matrix<T, rows, cols>::Matrix(const T& value)
{
	fill(value);
}

template<typename T, size_t rows, size_t cols>
inline void Matrix<T, rows, cols>::fill(const T& value)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t i = 0; i < cols; i++)
		{
			matrix[i][j] = value;
		}
	}
}

template<typename T, size_t rows, size_t cols>
inline T Matrix<T, rows, cols>::minValue()
{
	T min = matrix[0][0];
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t i = 0; i < cols; i++)
		{
			if (matrix[i][j] < min)
				min = matrix[i][j];
		}
	}
	return min;
}

template<typename T, size_t rows, size_t cols>
inline T Matrix<T, rows, cols>::maxValue()
{
	T max = matrix[0][0];
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t i = 0; i < cols; i++)
		{
			if (matrix[i][j] > max)
				max = matrix[i][j];
		}
	}
	return max;
}

template<typename T, size_t rows, size_t cols>
inline T Matrix<T, rows, cols>::containValue(const T value)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t i = 0; i < cols; i++)
		{
			if (matrix[i][j] == value)
				return true;
		}
	}
	return false;
}

template<typename T, size_t rows, size_t cols>
inline T Matrix<T, rows, cols>::sumOfElements() const
{
	T sum = T();
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t i = 0; i < cols; i++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}

template<typename T, size_t rows, size_t cols>
inline void Matrix<T, rows, cols>::print() const
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t i = 0; i < cols; i++)
		{
			 cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

template<typename T, size_t rows, size_t cols>
inline T& Matrix<T, rows, cols>::operator()(int r, int c)
{
	return matrix[r][c];
}

template<typename T, size_t rows, size_t cols>
inline Matrix<T> Matrix<T, rows, cols>::operator+(const Matrix& two)
{
	return Matrix();
}

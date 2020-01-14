#pragma once
#include "Matrix4x4.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"
namespace CommonUtilities
{
	template<class T>
	class Matrix3x3
	{
	public:
		// Creates the identity matrix.
		Matrix3x3<T>();
		// Copy Constructor.
		Matrix3x3<T>(const Matrix3x3<T>& aMatrix);
		// Copies the top left 3x3 part of the Matrix4x4.
		Matrix3x3<T>(const Matrix4x4<T>& aMatrix);
		// () operator for accessing element (row, column) for read/write or read,respectively.
		T& operator()(const int aRow, const int aColumn);
		const T& operator()(const int aRow, const int aColumn) const;
		Matrix3x3<T> operator+(Matrix3x3<T>& aMatrix);
		void operator+=(Matrix3x3<T>& aMatrix);
		Matrix3x3<T> operator-(Matrix3x3<T>& aMatrix);
		void operator-=(Matrix3x3<T>& aMatrix);
		Matrix3x3<T> operator*(Matrix3x3<T>& aMatrix);
		void operator*=(Matrix3x3<T>& aMatrix);
		friend Vector3<T> operator*(Vector3<T>& aVector3, Matrix3x3<T>& aMatrix);
		void operator=(Matrix3x3<T>& aMatrix);
		bool operator==(const Matrix3x3<T>& aMatrix)const;
		// Static functions for creating rotation matrices.
		static Matrix3x3<T> CreateRotationAroundX(T aAngleInRadians);
		static Matrix3x3<T> CreateRotationAroundY(T aAngleInRadians);
		static Matrix3x3<T> CreateRotationAroundZ(T aAngleInRadians);
		// Static function for creating a transpose of a matrix.
		static Matrix3x3<T> Transpose(const Matrix3x3<T>& aMatrixToTranspose);
	private:
		union
		{
			T oneDim[9];
			T twoDim[3][3];
		}myMatrix;
	};
	template<class T>
	inline Matrix3x3<T>::Matrix3x3()
	{

	}
	template<class T>
	inline Matrix3x3<T>::Matrix3x3(const Matrix3x3<T>& aMatrix)
	{
	}
	template<class T>
	inline Matrix3x3<T>::Matrix3x3(const Matrix4x4<T>& aMatrix)
	{
	}
	template<class T>
	inline T& Matrix3x3<T>::operator()(const int aRow, const int aColumn)
	{
		return myMatrix.twoDim[aRow][aColumn];
		// TODO: insert return statement here
	}
	template<class T>
	inline const T& Matrix3x3<T>::operator()(const int aRow, const int aColumn) const
	{
		return myMatrix.twoDim[aRow][aColumn];
		// TODO: insert return statement here
	}
	template<class T>
	Vector3<T> operator*(Vector3<T>& aVector3, Matrix3x3<T>& aMatrix)
	{
		return Vector3<T>();
	}

	template<class T>
	inline Matrix3x3<T> Matrix3x3<T>::CreateRotationAroundX(T aAngleInRadians)
	{
		return Matrix3x3<T>();
	}
	template<class T>
	inline Matrix3x3<T> Matrix3x3<T>::CreateRotationAroundY(T aAngleInRadians)
	{
		return Matrix3x3<T>();
	}
	template<class T>
	inline Matrix3x3<T> Matrix3x3<T>::CreateRotationAroundZ(T aAngleInRadians)
	{
		return Matrix3x3<T>();
	}
	template<class T>
	inline Matrix3x3<T> Matrix3x3<T>::Transpose(const Matrix3x3<T>& aMatrixToTranspose)
	{
		return Matrix3x3<T>();
	}
}
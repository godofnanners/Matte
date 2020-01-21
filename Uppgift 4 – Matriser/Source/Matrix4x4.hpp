#pragma once
#include "Vector3.hpp"
#include "Vector4.hpp"
#include <initializer_list>
#include <math.h>
namespace CommonUtilities
{

	template<class T>
	class Matrix4x4
	{
	#define TWODIMSIZE 4
	#define ONEDIMSIZE 16
	public:
		// Creates the identity matrix.
		Matrix4x4<T>();
		// Copy Constructor.
		Matrix4x4<T>(const Matrix4x4<T>& aMatrix);
		// () operator for accessing element (row, column) for read/write or read,respectively.
		T& operator()(const int aRow, const int aColumn);
		const T& operator()(const int aRow, const int aColumn) const;
		Matrix4x4<T> operator+(Matrix4x4<T>& aMatrix);
		void operator+=(Matrix4x4<T>& aMatrix);
		Matrix4x4<T> operator-(Matrix4x4<T>& aMatrix);
		void operator-=(Matrix4x4<T>& aMatrix);
		Matrix4x4<T> operator*(Matrix4x4<T>& aMatrix);
		void operator*=(Matrix4x4<T>& aMatrix);
		Vector4<T> operator*(Vector4<T>& aVector4);
		void operator*=(Vector4<T>& aVector4);
		void operator=(Matrix4x4<T>& aMatrix);
		bool operator==(const Matrix4x4<T>& aMatrixlhs)const;
		// Static functions for creating rotation matrices.
		static Matrix4x4<T> CreateRotationAroundX(T aAngleInRadians);
		static Matrix4x4<T> CreateRotationAroundY(T aAngleInRadians);
		static Matrix4x4<T> CreateRotationAroundZ(T aAngleInRadians);
		// Static function for creating a transpose of a matrix.
		static Matrix4x4<T> Transpose(const Matrix4x4<T>& aMatrixToTranspose);
	private:

		union
		{
			T twoDim[4][4];
			T oneDim[16];
		}myMatrix;
	};
	template<class T>
	inline Matrix4x4<T>::Matrix4x4()
	{
		for (int i = 0; i < ONEDIMSIZE; i++)
		{
			if (i == 0 || i == 5 || i == 10 || i == 15)
			{
				myMatrix.oneDim[i] = 1;
			}
			else
			{
				myMatrix.oneDim[i] = 0;
			}
		}
	}
	template<class T>
	inline Matrix4x4<T>::Matrix4x4(const Matrix4x4<T>& aMatrix)
	{
		for (int i = 0; i < ONEDIMSIZE; i++)
		{
			myMatrix.oneDim[i] = aMatrix.myMatrix.oneDim[i];
		}
	}
	template<class T>
	inline T& Matrix4x4<T>::operator()(const int aRow, const int aColumn)
	{
		// TODO: insert return statement here
		return myMatrix.twoDim[aRow - 1][aColumn - 1];
	}
	template<class T>
	inline const T& Matrix4x4<T>::operator()(const int aRow, const int aColumn) const
	{
		// TODO: insert return statement here
		return myMatrix.twoDim[aRow - 1][aColumn - 1];
	}
	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::operator+(Matrix4x4<T>& aMatrix)
	{
		Matrix4x4<T> addMatrix;
		for (int i = 0; i < ONEDIMSIZE; i++)
		{
			addMatrix.myMatrix.oneDim[i] = myMatrix.oneDim[i] + aMatrix.myMatrix.oneDim[i];
		}
		return addMatrix;
	}
	template<class T>
	inline void Matrix4x4<T>::operator+=(Matrix4x4<T>& aMatrix)
	{
		for (int i = 0; i < ONEDIMSIZE; i++)
		{
			myMatrix.oneDim[i] += aMatrix.myMatrix.oneDim[i];
		}
	}
	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::operator-(Matrix4x4<T>& aMatrix)
	{
		Matrix4x4<T> subMatrix;
		for (int i = 0; i < ONEDIMSIZE; i++)
		{
			subMatrix.myMatrix.oneDim[i] = myMatrix.oneDim[i] - aMatrix.myMatrix.oneDim[i];
		}
		return subMatrix;
	}
	template<class T>
	inline void Matrix4x4<T>::operator-=(Matrix4x4<T>& aMatrix)
	{
		for (int i = 0; i < ONEDIMSIZE; i++)
		{
			myMatrix.oneDim[i] -= aMatrix.myMatrix.oneDim[i];
		}
	}
	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::operator*(Matrix4x4<T>& aMatrix)
	{
		Matrix4x4<T>multMatrix;
		int multMatIndex = 0;
		T sum = 0;
		for (int lMatRow = 0; lMatRow < TWODIMSIZE; lMatRow++)
		{
			for (int rMatCol = 0; rMatCol < TWODIMSIZE; rMatCol++)
			{
				sum = 0;
				for (int lMatColrMatRow = 0; lMatColrMatRow < TWODIMSIZE; lMatColrMatRow++)
				{
					sum += myMatrix.twoDim[lMatRow][lMatColrMatRow] * aMatrix.myMatrix.twoDim[lMatColrMatRow][rMatCol];
				}
				multMatrix.myMatrix.oneDim[multMatIndex] = sum;
				++multMatIndex;
			}
		}
		return multMatrix;
	}
	template<class T>
	inline void Matrix4x4<T>::operator*=(Matrix4x4<T>& aMatrix)
	{
		Matrix4x4<T>multMatrix;
		int multMatIndex = 0;
		T sum = 0;
		for (int lMatRow = 0; lMatRow < TWODIMSIZE; lMatRow++)
		{
			for (int rMatCol = 0; rMatCol < TWODIMSIZE; rMatCol++)
			{
				sum = 0;
				for (int lMatColrMatRow = 0; lMatColrMatRow < TWODIMSIZE; lMatColrMatRow++)
				{
					sum += myMatrix.twoDim[lMatRow][lMatColrMatRow] * aMatrix.myMatrix.twoDim[lMatColrMatRow][rMatCol];
				}
				multMatrix.myMatrix.oneDim[multMatIndex] = sum;
				++multMatIndex;
			}
		}
		*this = multMatrix;
	}
	template<class T>
	inline Vector4<T> Matrix4x4<T>::operator*(Vector4<T>& aVector4)
	{
		Vector4<T>multVector;
		int multMatIndex = 0;
		T sum = 0;
		for (int lMatRow = 0; lMatRow < TWODIMSIZE; lMatRow++)
		{
			sum = 0;
			for (int lMatColrVectorRow = 0; lMatColrVectorRow < twoDimSize; lMatColrVectorRow++)
			{
				sum += myMatrix.twoDim[lMatRow][lMatColrMatRow] * aVector[lMatColrVectorRow];
			}
			multVector[multVectorIndex] = sum;
			++multVectorIndex;
		}

		return multVector;
	}

	template<class T>
	inline void Matrix4x4<T>::operator*=(Vector4<T>& aVector4)
	{
		Vector4<T>multVector;
		int multMatIndex = 0;
		T sum = 0;
		for (int lMatRow = 0; lMatRow < TWODIMSIZE; lMatRow++)
		{
			sum = 0;
			for (int lMatColrVectorRow = 0; lMatColrVectorRow < twoDimSize; lMatColrVectorRow++)
			{
				sum += myMatrix.twoDim[lMatRow][lMatColrMatRow] * aVector[lMatColrVectorRow];
			}
			multVector[multVectorIndex] = sum;
			++multVectorIndex;
		}

	}

	template<class T>
	inline Vector4<T> operator*(const Vector4<T>& aVector4, const Matrix4x4<T>& aMatrix)
	{

		Vector4<T>multVector;
		int multVectorIndex = 0;
		T sum = 0;

		for (int rMatCol = 0; rMatCol < 4; rMatCol++)
		{
			sum = 0;
			for (int lVectorColrMatRow = 0; lVectorColrMatRow < 4; lVectorColrMatRow++)
			{
				sum += aVector4[lVectorColrMatRow] * aMatrix(lVectorColrMatRow + 1, rMatCol + 1);
			}
			multVector[multVectorIndex] = sum;
			++multVectorIndex;
		}

		return multVector;
	}

	template<class T>
	inline void Matrix4x4<T>::operator=(Matrix4x4<T>& aMatrix)
	{
		for (int i = 0; i < ONEDIMSIZE; i++)
		{
			myMatrix.oneDim[i] = aMatrix.myMatrix.oneDim[i];
		}
	}
	template<class T>
	inline bool Matrix4x4<T>::operator==(const Matrix4x4<T>& aMatrixlhs) const
	{
		for (int i = 0; i < ONEDIMSIZE; i++)
		{
			if (myMatrix.oneDim[i] != aMatrixlhs.myMatrix.oneDim[i])
			{
				return false;
			}
		}
		return true;
	}

	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::CreateRotationAroundX(T aAngleInRadians)
	{
		Matrix4x4<T> xRot;

		xRot.myMatrix.oneDim[5] = cos(aAngleInRadians);
		xRot.myMatrix.oneDim[6] = sin(aAngleInRadians);
		xRot.myMatrix.oneDim[9] = -sin(aAngleInRadians);
		xRot.myMatrix.oneDim[10] = cos(aAngleInRadians);

		return xRot;
	}
	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::CreateRotationAroundY(T aAngleInRadians)
	{
		Matrix4x4<T> yRot;

		yRot.myMatrix.oneDim[0] = cos(aAngleInRadians);
		yRot.myMatrix.oneDim[2] = -sin(aAngleInRadians);
		yRot.myMatrix.oneDim[8] = sin(aAngleInRadians);
		yRot.myMatrix.oneDim[10] = cos(aAngleInRadians);

		return yRot;
	}
	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::CreateRotationAroundZ(T aAngleInRadians)
	{
		Matrix4x4<T> zRot;

		zRot.myMatrix.oneDim[0] = cos(aAngleInRadians);
		zRot.myMatrix.oneDim[1] = sin(aAngleInRadians);
		zRot.myMatrix.oneDim[4] = -sin(aAngleInRadians);
		zRot.myMatrix.oneDim[5] = cos(aAngleInRadians);

		return zRot;
	}
	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::Transpose(const Matrix4x4<T>& aMatrixToTranspose)
	{
		Matrix4x4<T> trans;
		for (int i = 0; i < TWODIMSIZE; i++)
		{
			for (int j = 0; j < TWODIMSIZE; j++)
			{
				trans.myMatrix.twoDim[j][i] = aMatrixToTranspose.myMatrix.twoDim[i][j];
			}
		}

		return trans;
	}
}
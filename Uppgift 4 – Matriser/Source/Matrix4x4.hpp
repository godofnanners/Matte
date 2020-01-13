#pragma once
#include "Vector3.hpp"
#include "Vector4.hpp"
namespace CommonUtilities
{
	template<class T>
	class Matrix4x4
	{
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
		Matrix4x4<T> operator*(Vector4<T>& aVector4);
		void operator*=(Vector4<T>& aVector4);
		friend Vector4<T> operator*(Vector4<T>& aVector4, Matrix4x4<T>& aMatrix);
		void operator=(Matrix4x4<T>& aMatrix);
		bool operator==(const Matrix4x4<T>& aMatrixlhs)const;
		// Static functions for creating rotation matrices.
		static Matrix4x4<T> CreateRotationAroundX(T aAngleInRadians);
		static Matrix4x4<T> CreateRotationAroundY(T aAngleInRadians);
		static Matrix4x4<T> CreateRotationAroundZ(T aAngleInRadians);
		// Static function for creating a transpose of a matrix.
		static Matrix4x4<T> Transpose(const Matrix4x4<T>& aMatrixToTranspose);
	private:
		union myMatrix
		{
			T twoDim[4][4];
			T oneDim[16];
		};
	};
	template<class T>
	inline Matrix4x4<T>::Matrix4x4()
	{
		
	}
	template<class T>
	inline Matrix4x4<T>::Matrix4x4(const Matrix4x4<T>& aMatrix)
	{
	}
	template<class T>
	inline T& Matrix4x4<T>::operator()(const int aRow, const int aColumn)
	{
		// TODO: insert return statement here
	}
	template<class T>
	inline const T& Matrix4x4<T>::operator()(const int aRow, const int aColumn) const
	{
		// TODO: insert return statement here
	}
	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::operator+(Matrix4x4<T>& aMatrix)
	{
	}
	template<class T>
	inline void Matrix4x4<T>::operator+=(Matrix4x4<T>& aMatrix)
	{
	}
	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::operator-(Matrix4x4<T>& aMatrix)
	{
		return Matrix4x4<T>();
	}
	template<class T>
	inline void Matrix4x4<T>::operator-=(Matrix4x4<T>& aMatrix)
	{
	}
	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::operator*(Matrix4x4<T>& aMatrix)
	{
		return Matrix4x4<T>();
	}
	template<class T>
	inline void Matrix4x4<T>::operator*=(Matrix4x4<T>& aMatrix)
	{
	}
	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::operator*(Vector4<T>& aVector4)
	{
		return Matrix4x4<T>();
	}

	template<class T>
	inline void Matrix4x4<T>::operator*=(Vector4<T>& aVector4)
	{
	}

	template<class T>
	inline Vector4<T> operator*(const Vector4<T>& aVector4, const Matrix4x4<T>& aMatrix)
	{
		return Vector4<T>();
	}

	template<class T>
	inline void Matrix4x4<T>::operator=(Matrix4x4<T>& aMatrix)
	{
	}
	template<class T>
	inline bool Matrix4x4<T>::operator==(const Matrix4x4<T>& aMatrixlhs) const
	{
		return false;
	}
	
	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::CreateRotationAroundX(T aAngleInRadians)
	{
		return Matrix4x4<T>();
	}
	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::CreateRotationAroundY(T aAngleInRadians)
	{
		return Matrix4x4<T>();
	}
	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::CreateRotationAroundZ(T aAngleInRadians)
	{
		return Matrix4x4<T>();
	}
	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::Transpose(const Matrix4x4<T>& aMatrixToTranspose)
	{
		return Matrix4x4<T>();
	}
}
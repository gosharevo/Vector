#include "Vector.h"
#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <cstring>
#include <cstdlib>


template <typename T, size_t N>
Vector<T, N>::Vector()
{
}

template <typename T, size_t N>
Vector<T, N>::Vector(const std::initializer_list<T> &other)
{
	for (size_t i = 0; i < N; i++)
	{
		this->_M_elems[i] = *(other.begin() + i);
	}
}

template <typename T, size_t N>
Vector<T, N>::Vector(const Vector &other)
{
	for (size_t i = 0; i < N; i++)
	{
		this->_M_elems[i] = other._M_elems[i];
	}
}

template <typename T, size_t N>
T &Vector<T, N>::operator[](size_t index)
{
	return this->_M_elems[index];
}

template <typename T, size_t N>
Vector<T, N>::Vector(Vector &&other)
{
	std::memcpy(this->_M_elems, other._M_elems, N * sizeof(T));
	std::memset(other._M_elems, T(0), N * sizeof(T));
}

template <typename T, size_t N>
Vector<T, N> &Vector<T, N>::operator=(const std::initializer_list<T> &other)
{
	for (size_t i = 0; i < N; i++)
	{
		this->_M_elems[i] = other[i];
	}
	return this;
}

template <typename T, size_t N>
Vector<T, N> &Vector<T, N>::operator=(const Vector &other)
{
	for (size_t i = 0; i < N; i++)
	{
		this->_M_elems[i] = other[i];
	}
	return this;
}

template <typename T, size_t N>
Vector<T, N> Vector<T, N>::operator+(const Vector &other) const
{
	Vector<T, N> result;
	for (int i = 0; i < N; i++)
	{
		result[i] = this->_M_elems[i] + other._M_elems[i];
	}
	return result;
}

template <typename T, size_t N>
Vector<T, N> Vector<T, N>::operator-(const Vector &other) const
{
	Vector<T, N> result;
	for (int i = 0; i < N; i++)
	{
		result[i] = this->_M_elems[i] - other._M_elems[i];
	}
	return result;
}

template <typename T, size_t N>
Vector<T, N> Vector<T, N>::operator*(const Vector &other) const
{
	Vector<T, N> result;
	for (int i = 0; i < N; i++)
	{
		result[i] = this->_M_elems[i] * other._M_elems[i];
	}
	return result;
}

template <typename T, size_t N>
Vector<T, N> Vector<T, N>::operator/(const Vector &other) const
{
	Vector<T, N> result;
	for (int i = 0; i < N; i++)
	{
		result[i] = this->_M_elems[i] / other._M_elems[i];
	}
	return result;
}

template <typename T, size_t N>
Vector<T, N> Vector<T, N>::operator+(const float &other) const
{
	Vector<T, N> result;
	for (int i = 0; i < N; i++)
	{
		result[i] = this->_M_elems[i] + other;
	}
	return result;
}

template <typename T, size_t N>
Vector<T, N> Vector<T, N>::operator-(const float &other) const
{
	Vector<T, N> result;
	for (int i = 0; i < N; i++)
	{
		result[i] = this->_M_elems[i] - other;
	}
	return result;
}

template <typename T, size_t N>
Vector<T, N> Vector<T, N>::operator*(const float &other) const
{
	Vector<T, N> result;
	for (int i = 0; i < N; i++)
	{
		result[i] = this->_M_elems[i] * other;
	}
	return result;
}

template <typename T, size_t N>
Vector<T, N> Vector<T, N>::operator/(const float &other) const
{
	Vector<T, N> result;
	for (int i = 0; i < N; i++)
	{
		result[i] = this->_M_elems[i] / other;
	}
	return result;
}

int main()
{
	using namespace std;
	Vector<int, 3> a = {1, 2, 3};
	auto b = std::move(a);
	for(int i=0;i<3;i++)
	{
		cout <<a[i] << ' ' << b[i] << endl;
	}
	return 0;
}
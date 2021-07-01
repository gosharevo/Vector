#include <array>
#include <initializer_list>
#include <cstddef>

template <typename T, size_t N>
class Vector : public std::array<T, N>
{
public:
	Vector();
	Vector(const std::initializer_list<T> &other);
	Vector(const Vector &other);
	T &operator[](size_t index);

	Vector &operator=(const std::initializer_list<T> &other);
	Vector &operator=(const Vector &other);

	Vector operator+(const Vector &other) const;
	Vector operator-(const Vector &other) const;
	Vector operator*(const Vector &other) const;
	Vector operator/(const Vector &other) const;

	Vector operator+(const T &other) const;
	Vector operator-(const T &other) const;
	Vector operator*(const T &other) const;
	Vector operator/(const T &other) const;

	Vector operator-() const;

	friend Vector operator+(T value, Vector &other)
	{
		Vector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			result[i] = value + other[i] ;
		}
		return result;
	}

	friend Vector operator-(T value, Vector &other)
	{
		Vector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			result[i] = value - other[i] ;
		}
		return result;
	}

	friend Vector operator*(T value, Vector &other)
	{
		Vector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			result[i] = value * other[i];
		}
		return result;
	}

	friend Vector operator/(T value, Vector &other)
	{
		Vector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			result[i] = value / other[i];
		}
		return result;
	}
};

#pragma once

template<typename T>
void swap(T &a, T &b)
{
	T copy_a;

	copy_a = a;
	a = b;
	b = copy_a;
}

template<typename T>
const T& min(const T& a, const T& b)
{
	if (a < b)
		return a;
	else
		return b;
}

//Another solution
/* template<typename T>
T min(T a, T b)
{
	if (a < b)
		return a;
	else
		return b;
} */

template<typename T>
const T& max(const T& a, const T& b)
{
	if (a > b)
		return a;
	else
		return b;
}

//Another solution
/* template<typename T>
T max(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
} */
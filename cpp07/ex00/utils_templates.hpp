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
const T& min(T a, T b)
{
	if (a < b)
		return a;
	else
		return b;
}

template<typename T>
const T& max(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}
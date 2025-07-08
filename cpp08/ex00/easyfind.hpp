template<typename Container>
typename Container::iterator easyfind(Container& container, int num)
{
	for (typename Container::iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == num)
			return it;
	}
	return container.end();
}
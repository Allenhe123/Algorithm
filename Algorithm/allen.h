#pragma once

#include <iostream>

class Allen
{
public:

	const float small_gaussian_tab[4][7] =
	{
		{ 1.f,0,0,0,0,0,0 },
	{ 0.25f, 0.5f, 0.25f,0,0,0,0 },
	{ 0.0625f, 0.25f, 0.375f, 0.25f, 0.0625f,0,0 },
	{ 0.03125f, 0.109375f, 0.21875f, 0.28125f, 0.21875f, 0.109375f, 0.03125f }
	};

	void myfunc()
	{
		std::cout << "hello world" << std::endl;
	}

private:

};

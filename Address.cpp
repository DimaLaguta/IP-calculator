#include "pch.h"
#include "Address.h"

using namespace std;

Address::Address(char* address)
{
	unsigned int* oktets = Parse(address);
	makeIntAddress(oktets);
}


Address::~Address()
{
}

unsigned int* Address::Parse(char* addres)
{
	char** CHARoktets = splitToString(addres);
	unsigned int* oktets = convertToInt(CHARoktets);

	for (unsigned int i = 0; i < numOktets; i++)
	{
		delete[] CHARoktets[i];
	}
	delete[] CHARoktets;
	return oktets;
}

char** Address::splitToString(char* addres)
{
	char** oktets = new char*[4];
	for (unsigned int i = 0; i < 4; i++)
	{
		oktets[i] = new char[4];
	}

	unsigned int i=0,j=0,k=0;
	while (addres[i] != '\0')
	{
		if (addres[i] == '.')
		{
			oktets[j][k] = '\0';
			j++;
			i++;
			k = 0;
			continue;
		}
		oktets[j][k] = addres[i];
		k++;
		i++;
	}
	oktets[j][k] = '\0';
	numOktets = j + 1;
	return oktets;
}

unsigned int * Address::convertToInt(char ** oktets)
{
	unsigned int* INToktets = new unsigned int[4];
	for (unsigned int i = 0; i < numOktets; i++)
	{
		INToktets[i] = convertToInt(oktets[i]);
	}
	return INToktets;
}

void Address::makeIntAddress(unsigned  int * oktets)
{
	for (unsigned int i = 0, j = numOktets; i < numOktets; i++,j--)
	{
		 unsigned int sdvig = 8 * (j - 1);
		oktets[i] = oktets[i] << sdvig;
		addres = addres | oktets[i];
	}
}

unsigned int Address::convertToInt(char * oktet)
{
	unsigned int res = 0;
	unsigned int i = 0;
	while (oktet[i] != '\0')
	{
		res *= 10;
		res += oktet[i] - 48;
		i++;
	}
	return res;
}

void Address::bits(unsigned int x)
{
	int sdvig = 8 * sizeof(int) - 1;
	int maska = 1 << sdvig;
	cout << " Int " << x << " = ";
	for (int i = 0; i <= sdvig; i++)
	{
		cout << (x & maska ? '1' : '0');
		x = x << 1;
		if ((i + 1) % 8 == 0) cout << ' ';
	}
}
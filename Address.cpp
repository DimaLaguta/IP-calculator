#include "pch.h"
#include "Address.h"

using namespace std;

Address::Address(char* address)
{
	unsigned int* oktets = Parse(address);
	makeIntAddress(oktets);
	unsigned int* a = convertToMasInt();
}

Address::Address(unsigned int mask)
{
	addres = genericMask(mask);
	numOktets = 4;
	
}

void Address::Binary(unsigned int x)
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



Address::~Address()
{
}

unsigned int Address::genericMask(int mask)
{
	unsigned int result = 0;
	unsigned int bit = 1;
	bit = bit << 31;
	for (unsigned int i = 0; i < mask; i++)
	{
		result = result | bit;
		bit = bit >> 1;
	}
	return result;
}

unsigned int* Address::Parse(char* addres)
{
	char** CHARoktets = splitToString(addres);
	unsigned int* oktets = convertToInt(CHARoktets);

	//for (unsigned int i = 0; i < numOktets; i++)
	//{
	//	delete[] CHARoktets[i];
	//}
	//delete[] CHARoktets;
	return oktets;
}

char** Address::splitToString(char* addres)
{
	char** oktets = new char*[numOktets];
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
	unsigned int* INToktets = new unsigned int[numOktets];
	for ( int i = 0; i < numOktets; i++)
	{
		INToktets[i] = convertCharToInt(oktets[i]);
	}
	return INToktets;
}

void Address::makeIntAddress(unsigned  int * oktets)
{
	for ( int i = 0, j = numOktets; i < numOktets; i++,j--)
	{
		 unsigned int sdvig = 8 * (j - 1);
		oktets[i] = oktets[i] << sdvig;
		addres = addres | oktets[i];
	}
}

unsigned int Address::convertCharToInt(char * oktet)
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

char * Address::charAddres()
{
	unsigned int* INToktets = convertToMasInt();
	char** oktets = makeCharOktets(INToktets);
	char* address = uniteOktets(oktets);
	return address;
}

unsigned int * Address::convertToMasInt()
{
	unsigned int* oktets = new unsigned int[numOktets];
	unsigned int mask = 4278190080;
	for ( int i = 0,j=numOktets; i < numOktets; i++,j--)
	{
		oktets[i] = addres & mask;
		oktets[i] = oktets[i] >> 8 * (j - 1);
		mask = mask >> 8;
	}
	return oktets;
}

char ** Address::makeCharOktets(unsigned int * oktets)
{
	char** addres = new char*[numOktets];
	for (int i = 0; i < numOktets; i++)
	{
		addres[i] = new char[4];
	}

	for (int i = 0; i < numOktets; i++)
	{
		addres[i] = convertIntToChar(oktets[i]);
		reversChar(addres[i]);
	}
	return addres;
}

char * Address::uniteOktets(char ** oktet)
{
	char* addres = new char[16];
	for (int i = 0; i < numOktets; i++)
	{
		sprintf_s(addres, 16, "%s.%s.%s.%s", oktet[0], oktet[1], oktet[2], oktet[3]);
	}
	return addres;
}

char * Address::convertIntToChar(unsigned int num)
{
	char * result = new char[4];
	int i = 0;
	bool isFirst = false;
	while (num != 0 || isFirst == false)
	{
		isFirst = true;
		int buf = num % 10;
		num /= 10;
		result[i] = buf + 48;
		i++;
	}
	result[i] = '\0';
	return result;
}

void Address::reversChar(char* num)
{
	int len = strlen(num);
	for (int i = 0; i < len -1; i++)
	{
		char buf = num[len - i-1];
		num[len - i-1] = num[i];
		num[i] = buf;
	}
}


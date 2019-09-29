#pragma once
class Address
{
public:
	unsigned int addres = 0;
private:
	int numOktets = 0;

public:

	static void bits(unsigned int x);


	Address(char* address);
	~Address();
private:
	unsigned int* Parse(char* addres);
	char** splitToString(char* addres);
	unsigned int* convertToInt(char** oktets);
	void makeIntAddress(unsigned int* oktets);
	unsigned int convertToInt(char* oktet);


};


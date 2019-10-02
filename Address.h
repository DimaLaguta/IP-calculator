#ifndef ADDRESS_H
#define ADDRESS_H
class Address
{
public:
	 unsigned int addres = 0;
private:
	int numOktets = 0;

public:
	Address(char* address);
	Address(unsigned int mask);

	static void Binary(unsigned int x);
	char* charAddres();

	~Address();
private:
	unsigned int genericMask(int mask);

	unsigned int* Parse(char* addres);
	char** splitToString(char* addres);
	unsigned int* convertToInt(char** oktets);
	void makeIntAddress(unsigned int* oktets);
	unsigned int convertCharToInt(char* oktet);

	unsigned int* convertToMasInt();
	char** makeCharOktets(unsigned int* oktets);
	//char** convertIntToChar(unsigned int* oktets);
	char* uniteOktets(char** oktet);
	char* convertIntToChar(unsigned int num);
	void reversChar(char* num);
};

#endif ADDRESS_H
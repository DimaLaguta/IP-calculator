#include "pch.h"
#include "Network.h"
#include "Address.h"

using namespace std;

Network::Network(char* ipNetwork,int networkMask,int numSubnet)
{
	addresNetwork = new Address(ipNetwork);
	mask = new Address(networkMask);
	numSubnets = numSubnet;
}


Network::~Network()
{
}

unsigned int Network::calculateBorrowBits()
{
	int powerTwo = 1;
	unsigned int numBits = 0;
	while (powerTwo < numSubnets)
	{
		numBits++;
		powerTwo = 1;
		powerTwo = powerTwo << numBits;
	}
	return numBits;
}

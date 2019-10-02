#include "pch.h"
#include "Network.h"
#include "Address.h"

using namespace std;

Network::Network(char* ipNetwork,int networkMask,int numSubnet)
{
	addresNetwork = new Address(ipNetwork);
	mask = new Address(networkMask);
	INTmask = networkMask;
	numSubnets = numSubnet;
	numBorrowBits = calculateBorrowBits();
	int numhostParts = 1;
	numDifferentHostsParts = numhostParts << numBorrowBits;

	hostParts = calculateAllHostParts();
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

unsigned int * Network::calculateAllHostParts()
{
	
	unsigned int* hostsParts = new unsigned int[numDifferentHostsParts];
	int sdvig = 32 - INTmask - numBorrowBits;
	for (int i = 0; i < numDifferentHostsParts; i++)
	{
		hostsParts[i] = i;
		hostsParts[i] = hostsParts[i] << sdvig;
	}
	return hostsParts;
}

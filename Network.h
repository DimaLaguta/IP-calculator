#ifndef NETWORK_H
#define NETWORK_H

#include "Address.h"
class Network
{
public:
	int maxNumUsers = 0;
	Address* addresNetwork;
	Address* mask;
	int numSubnets=0;
//private:
	unsigned int numBorrowBits = 0;
	unsigned int* hostParts;
	int INTmask;
	int numDifferentHostsParts;

public:
	Network(char* ipNetwork,int networkMask, int numSubnet);
	~Network();
//private:
	unsigned int calculateBorrowBits();
	unsigned int* calculateAllHostParts();
};

#endif NETWORK_H
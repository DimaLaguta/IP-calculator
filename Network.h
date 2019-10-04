#ifndef NETWORK_H
#define NETWORK_H

#include "Address.h"
#include "SubNet.h"

class Network
{
public:
	int maxNumUsers = 0;
	Address* addresNetwork;
	Address* mask;
	int numSubnets=0;
//private:
	SubNet* subnet;
	unsigned int numBorrowBits = 0;
	unsigned int* hostParts;
	int INTmask;
	int numDifferentHostsParts;

public:
	Network(char* ipNetwork,int networkMask, int numSubnet);
	~Network();
	void PrintReport();
//private:
	unsigned int calculateBorrowBits();
	unsigned int* calculateAllHostParts();
	void calculateSubNet();
	void calculateNetworkAddres();
	void calculateStartID();
	void calculateBroadcast();
	void calculateEndId();
};

#endif NETWORK_H
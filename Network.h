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
	   	 

public:
	Network(char* ipNetwork,int networkMask, int numSubnet);
	~Network();
};

#endif NETWORK_H
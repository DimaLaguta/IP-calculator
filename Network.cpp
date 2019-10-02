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

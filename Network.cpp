#include "pch.h"
#include "Network.h"
#include "Address.h"
#include "SubNet.h"
#include <iomanip>

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

	subnet = new SubNet[numDifferentHostsParts];
	calculateSubNet();
	// отчет
}


Network::~Network()
{
}

void Network::PrintReport()
{
	cout << "Report:" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Number of subnets |" << " Prefix length |" << " Start User IP |" << " End User IP |" << " Network Address |" << " Broadcast Address |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i=0;i<numSubnets;i++)
	{
		cout<< setw(10) << i + 1;
		cout << setw(17) << numBorrowBits + mask->numBitsMask;
		cout << setw(21) << subnet[i].startUserId.charAddres();
		cout << setw(16) << subnet[i].endUserId.charAddres();
		cout << setw(16) << subnet[i].networkAddress.charAddres();
		cout << setw(18) <<	subnet[i].Broadcast.charAddres() << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	}
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

void Network::calculateSubNet()
{
	calculateNetworkAddres();
	calculateStartID();
	calculateBroadcast();
	calculateEndId();
}

void Network::calculateNetworkAddres()
{
	unsigned int bufnetworkAddress = addresNetwork->addres;
	for (int i = 0; i < numDifferentHostsParts; i++)
	{
		subnet[i].networkAddress.addres = bufnetworkAddress | hostParts[i];
	}
}

void Network::calculateStartID()
{
	for (int i = 0; i < numDifferentHostsParts; i++)
	{
		hostParts[i]++;
	}
	unsigned int bufnetworkAddress = addresNetwork->addres;
	for (int i = 0; i < numDifferentHostsParts; i++)
	{
		subnet[i].startUserId.addres = bufnetworkAddress | hostParts[i];
	}
}

void Network::calculateBroadcast()
{
	//создание маски для заполнения единицами части хоста которыая не участвует в формировании подсети
	int restPartHost = 0;
	int mask = 1;
	for (int i = 1; i <= 32 - INTmask - numBorrowBits; i++)
	{
		restPartHost = restPartHost | mask;
		int buf = 1;
		buf = buf << i;
		mask = mask | buf;
	}
	//добавление единиц что бы получить шлюз
	for (int i = 0; i < numDifferentHostsParts; i++)
	{
		hostParts[i] = hostParts[i] | restPartHost;
	}


	unsigned int bufnetworkAddress = addresNetwork->addres;
	for (int i = 0; i < numDifferentHostsParts; i++)
	{
		subnet[i].Broadcast.addres = bufnetworkAddress | hostParts[i];
	}
}

void Network::calculateEndId()
{
	for (int i = 0; i < numDifferentHostsParts; i++)
	{
		hostParts[i]--;
	}
	unsigned int bufnetworkAddress = addresNetwork->addres;
	for (int i = 0; i < numDifferentHostsParts; i++)
	{
		subnet[i].endUserId.addres = bufnetworkAddress | hostParts[i];
	}
}

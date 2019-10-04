#include "pch.h"
#include "Address.h"
#include "Network.h"


using namespace std;



int main()
{
	unsigned int numSubnets = 0;
	char* ipNetwork = new char[16];
	int mask=0;
	cout << "Input:\n";
	cout << "Number of Subnets:";
	cin >> numSubnets;
	cout << "Source network:";
	cin >> ipNetwork;
	cout << "Mask:";
	cin >> mask;

	Network* network = new Network(ipNetwork, mask, numSubnets);
	network->PrintReport();


	//char* buf = a->addresNetwork->charAddres();
	//cout << buf << endl;
	//cout << a->mask->charAddres() << endl;
	//cout << a->numSubnets << endl;

	//cout << a->calculateBorrowBits() << endl;

	//unsigned int* hostpart = a->calculateAllHostParts();

	//for (int i = 0; i < a->numDifferentHostsParts; i++)
	//{
	//	cout << a->hostParts[i] << endl;
	//}
	//cout << endl;

	//for (int i = 0; i < a->numDifferentHostsParts; i++)
	//{
	//	cout << a->subnet[i].networkAddress.charAddres() << endl;
	//}
	//cout << endl;

	//for (int i = 0; i < a->numDifferentHostsParts; i++)
	//{
	//	cout << a->subnet[i].startUserId.charAddres() << endl;
	//}
	//cout << endl;

	//for (int i = 0; i < a->numDifferentHostsParts; i++)
	//{
	//	cout << a->subnet[i].Broadcast.charAddres() << endl;
	//}
	//cout << endl;
	//for (int i = 0; i < a->numDifferentHostsParts; i++)
	//{
	//	cout << a->subnet[i].endUserId.charAddres() << endl;
	//}
	return 0;
}
#pragma once
#include "Address.h"
class SubNet
{
public:
	Address networkAddress;
	Address startUserId;
	Address endUserId;
	Address Broadcast;

public:
	SubNet();
	~SubNet();
};


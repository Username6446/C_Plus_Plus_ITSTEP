#pragma once
#include "TV.h"

class Remote
{
	TV* tv = nullptr;
public:
	Remote(TV * tv);
	void chooseTV(TV* tv);
	void power() const;
	void goChannel(size_t channel) const;
	void operator++ () const;
	void operator-- () const;
	void operator+ () const;
	void operator- () const;
};


#include "Remote.h"

Remote::Remote(TV* tv)
{
	chooseTV(tv);
}

void Remote::chooseTV(TV* tv)
{
	this->tv = tv;
}

void Remote::power() const
{
	tv->power();
}

void Remote::goChannel(size_t channel) const
{
	if (!tv->state) return;
	if (channel > 0 && channel <= tv->numberOfChannels) {
		tv->currentChannel = channel;
	}
	cout << "Inccorect index of channel" << endl;
}

void Remote::operator++() const
{
	tv->nextChannel();
}

void Remote::operator--() const
{
	tv->prevChannel();
}

void Remote::operator+() const
{
	tv->incVolume();
}
void Remote::operator-() const
{
	tv->decVolume();
}

#pragma once
#include "iostream"
using namespace std;

class Remote;

class TV
{
private:
	bool state = false;
	size_t volume;
	size_t maxVolume;
	size_t currentChannel;
	size_t numberOfChannels;
public:
	TV();
	TV(const bool& state, const size_t& volume, const size_t& maxVolume, const size_t& currentChannel, const size_t& numberOfChannels);
	void power();
	void nextChannel();
	void prevChannel();
	void incVolume();
	void decVolume();
	void showState() const;
	friend class Remote;
};


#include "TV.h"

TV::TV() : state(false), volume(10), maxVolume(100), currentChannel(1), numberOfChannels(10) {}
TV::TV(const bool& state, const size_t& volume, const size_t& maxVolume, const size_t& currentChannel, const size_t& numberOfChannels)
	:state{state}, volume{volume}, maxVolume{maxVolume}, currentChannel{currentChannel}, numberOfChannels{numberOfChannels}
{
}

void TV::power()
{
	this->state = !state;
	cout << "TV is now " << (state ? "ON" : "OFF") << endl;
}

void TV::nextChannel()
{
	if (!state) return;
	if (currentChannel + 1 <= numberOfChannels)
		currentChannel++;
	else {
		cout << "This is last channel" << endl;
	}
}

void TV::prevChannel()
{
	if (!state) return;
	if (currentChannel != 0)
		currentChannel--;
	else {
		cout << "This is first channel" << endl;
	}

}

void TV::incVolume()
{
	if (!state) return;
	if (volume + 1 <= maxVolume) {
		volume++;
	}
	else {
		cout << "Volume is already Max" << endl;
	}
}

void TV::decVolume()
{
	if (!state) return;
	if (volume != 0) {
		volume--;
	}
	else {
		cout << "Volume is already Min" << endl;

	}

}

void TV::showState() const {
	cout << "TV: " << (state ? "ON" : "OFF")
		<< " | Channel: " << currentChannel
		<< " | Volume: " << volume << endl;
}
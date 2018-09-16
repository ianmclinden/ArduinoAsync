/*
  Async.h - Asynchronous JavaScript-like task scheduling for Arduino.
  2018 Ian McLinden
*/

#include "Arduino.h"
#include "Async.h"

// ==== Public ================================================================
void AsyncManager::update() {
	for (auto func = functions.begin(), last = functions.end(); func != last; ++func) {
		unsigned long mls = millis();
		if (mls - func->lastUpdate > func->timeout) {
			if (func->callback != NULL) {
				func->callback();
			}
			if (func->intervalID > 0) {
				func->lastUpdate = mls;
			} else {
				func = functions.erase(func--);
			}
		}
	}
}

void AsyncManager::setTimeout(void (*callback)(),unsigned long timeout) {
	struct asyncFunction f = {callback, timeout, millis(), 0};
	functions.push_back(f);
}

unsigned long AsyncManager::setInterval(void (*callback)(),unsigned long timeout) {
	unsigned long mils = millis();
	struct asyncFunction f = {callback, timeout, mils, mils};
	functions.push_back(f);
	return mils;
}

void AsyncManager::clearInterval(unsigned long intervalID) {
	if (intervalID <=0 ) return;
	for (auto func = functions.begin(), last = functions.end(); func != last; ++func) {
		if (func->intervalID == intervalID) {
			func = functions.erase(func--);
			return;
		}
	}
}


/*
  Async.h - Asynchronous JavaScript-like task scheduling for Arduino.
  2018 Ian McLinden
*/

// ensure this library description is only included once
#ifndef H_ARDUINO_ASYNC
#define H_ARDUINO_ASYNC

#include <list>

class AsyncManager {

    public:
		AsyncManager() {}
		void update();
		void setTimeout(void (*callback)(),unsigned long timeout);
		unsigned long setInterval(void (*callback)(),unsigned long timeout);
		void clearInterval(unsigned long intervalID);
    
	private:
		struct asyncFunction {
			void (*callback)();
			unsigned long timeout;
			unsigned long lastUpdate;
			unsigned long intervalID;
		};
		std::list<asyncFunction> functions;
    
};
static AsyncManager Async;
#endif


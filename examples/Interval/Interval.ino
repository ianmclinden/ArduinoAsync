#include <Async.h>

// Asynchronous JavaScript-like callbacks for Arduino
// 2018 Ian McLinden <https://github.com/ianmclinden>

// Use Async.setInterval to schedule a periodic function.
// Updated - 16 Sept 2018


// Create a callback Function to execute every interval
// Must be of type void -> void
void printMessage() {
    if (Serial) Serial.println("Interval Done! - Print forever");
}

// Create a long to hold the callback function's ID
unsigned long capturedInterval;
static int numberOfIntervals = 0;

void print5Messages() {
    if (numberOfIntervals++ < 5) {
        if (Serial) Serial.println("Interval Done - Only printed 5 times");
    } else {
        // Clear the interval so that it stops running
        Async.clearInterval(capturedInterval);
    }
}

void setup() {
    
    //Initialize serial and wait for port to open:
    Serial.begin(9600);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB
    }

    // Schedule an uncaptured Interval - this will run forever
    Serial.println("Scheduling an uncaptured Interval...");
    Async.setInterval(&printMessage,1000);

    // Schedule an interval and capture it's ID so that it can be cancelled 
    Serial.println("Scheduling a captured Interval...");
    capturedInterval = Async.setInterval(&print5Messages,1000);
}

void loop() {
    // Update the Async Manager
    Async.update();
}

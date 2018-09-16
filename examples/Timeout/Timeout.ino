#include <Async.h>

// Asynchronous JavaScript-like callbacks for Arduino
// 2018 Ian McLinden <https://github.com/ianmclinden>

// Use Async.setTimeout to schedule a function for the future.
// Updated - 16 Sept 2018


// Create a callback Function to execute when the timeout ends
// Must be of type void -> void
void printMessage() {
    if (Serial) Serial.println("Timeout Done!");
}

void setup() {
    
    //Initialize serial and wait for port to open:
    Serial.begin(9600);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB
    }

    // Schedule a timeout in 1000 ms (1s)
    Serial.println("Scheduling a Timeout...");
    Async.setTimeout(&printMessage,1000);

    // Schedule a timeout in 5000 ms (5s)
    Serial.println("Scheduling a longer Timeout...");
    Async.setTimeout(&printMessage,5000);
}

void loop() {
    // Update the Async Manager
    Async.update();
}

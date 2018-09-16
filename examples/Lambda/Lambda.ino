#include <Async.h>

// Asynchronous JavaScript-like callbacks for Arduino
// 2018 Ian McLinden <https://github.com/ianmclinden>

// Use Async.setInterval to schedule a periodic function.
// Updated - 16 Sept 2018


// Create a function to call from our lambda - this can be any type
void printMessage(String message) {
    if (Serial) Serial.println(message);
}

// Create a counter, just so we have something interesting to print
static int counter = 0;

void setup() {
    
    //Initialize serial and wait for port to open:
    Serial.begin(9600);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB
    }

    // Schedule an uncaptured Interval - this will run forever
    Serial.println("Scheduling an uncaptured Interval...");
    
    // We can specify the callback as a C++ Lambda, as long as the lambda
    // does not specify any captures
    Async.setInterval([]{
        printMessage("Callback called " + String(++counter) + " times");
    },1000);

}

void loop() {
    // Update the Async Manager
    Async.update();
}

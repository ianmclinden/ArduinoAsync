# ArduinoAsync
Asynchronous JavaScript-like task scheduling for Arduino

# Installation <sup>[1](#references)</sup>
From the [ArduinoAsync](https://github.com/ianmclinden/ArduinoAsync) repo, select `Clone or download > Download ZIP`, or use the [direct download link](https://github.com/ianmclinden/ArduinoAsync/archive/master.zip).

In the Arduino IDE, navigate to `Sketch > Include Library > Add .ZIP Library`. At the top of the drop down list, select the option to `Add .ZIP Library`.  

Return to the `Sketch > Include Library` menu. menu. You should now see the library at the bottom of the drop-down menu. It is ready to be used in your sketch. The zip file will have been expanded in the libraries folder in your Arduino sketches directory.


# Example Code
Three code examples are provided: 

### [Timeout](https://github.com/ianmclinden/ArduinoAsync/blob/master/examples/Timeout/Timeout.ino)
Demonstrates setting simple timeouts using pre-defined void->void functions.

### [Interval](https://github.com/ianmclinden/ArduinoAsync/blob/master/examples/Interval/Interval.ino)
Demonstrates setting and cancelling periodic functions using pre-defined void->void functions.


### [Lambda](https://github.com/ianmclinden/ArduinoAsync/blob/master/examples/Lambda/Lambda.ino)
Demonstrates use of C++ lamabdas for more advanced timeout handling.


# License and Author
2018 Ian McLinden under the [GNU General Public License v3.0](/LICENSE).
Use at your own risk, author retains no liability for misuse.

---
# References
*1) Installation instructions provided in part from the official [Installing Additional Arduino Libraries](https://www.arduino.cc/en/Guide/Libraries) guide.*

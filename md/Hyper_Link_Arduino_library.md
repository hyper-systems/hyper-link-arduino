# Hyper Link Arduino library

Hyper Link is a hardware component that adds connectivity and easy data IO to
your project. Read more on the [Hyper Link](#) page.

The Hyper Link Arduino library provides utilities specific to your device
schema so that you can easily publish sensor or diagnostic values and receiving
commands from other devices.


## Quickstart

A typical workflow for working with the Hyper Link Arduino library is:

1. [**Define your device schema**](#define-your-device-schema): define a device schema as a collection of read and write
   attributes that represent the capabilities of your device.
2. [**Download the arduino library**](#download-the-arduino-library): download the Arduino library auto-generated
   specifically for device schema.
3. [**Setup your board**](#setup-your-board): make sure you have Hyper-compatible components and
   configure your Arduino IDE.
4. [**Integrate the arduino library**](#integrate-the-arduino-library): follow the instructions to include the
   library and start working with the software resprestation of your device to
   record sensor values and bind incoming command handlers.
5. [**Test your setup**](#test-your-setup): connect everything together and start testing data publishing and command execution.

Below is a detailed description of every step.


### Define your device schema

Head to <https://hyper.systems> and log-in into your dashboard. In the sidebar
menu select "Device types" and click the "Create new device type" button in the
toolbar. A form for defining a new device type will appear where you can
provide a detailed description about your device type, including the supported
read/write attributes and their data types.

Once you are happy with the description of your device type press the "Save"
button. Congratulations you have completed the definition of your device
type!


### Download the arduino library

After completing the previous step you will be able to open your device type
page. This page includes all of the details about the read and write attributes
of your device type.

You can click the "Download Arduino library" button in the toolbar to get a ZIP
archieve containing an example Arduino project that demonstrates how to work
with your device type.

In addition to downloading the library you can also consult the library's API
documentation for your device type.


### Setup your board

Follow the official instructions for configuring the Arduino IDE for your board.


### Integrate the arduino library

The Arduino library code for your device type will include an example "main"
file that demonstrates how to initialise and start using your device type.

You start making changes to the code to add any modifications necessary for
your project.

The following sections must be present in your code to get a working integration:

#### 1. Include the library code

```cpp
// Include the generated support code for working with your device over
// I2C-slave interface. Replacce "XXX" with your unique device type identifier.
#include "HyperDeviceXXXI2CSlave.V1.h"
```

#### 2. Define the global device variable

```cpp
// Define a variable for your Hyper device in the global scope to make it easy
// for your to access the device anywhere in your code.
HyperDeviceXXXI2CSlave hyperDevice;
```

#### 3. Setup the device identifier and bind write attributes

```cpp
void setup() {
  // All devices must have a unique identifer composed of 6 hex characters. 
  // If possible use your boards MAC address or find an equivalent unique identifer.
  const uint8_t deviceId[6] = {0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x01};
  hyperDevice.begin(deviceId);

  // Bind write attributes.
  // Write attributes can be used to push data to your device from the server.
  // This section can be used to assign custom function handlers for every
  // write attribute. The function callback can perform any changes to the
  // device necessary to react to the attribute change.
  hyperDevice.bindMyAttribute1(onMyAttribute1Update);
}
```

#### 4. Record read attribute changes

```cpp
void loop() {
  int adcVal = analogRead(A0);

  // Record the values for your read attributes.
  hyperDevice.setMyAttribute1(adcVal);

  delay(1000);
}
```

Having completed these code changes your project is ready to start publishing
read attribute values and processing write attribute updates from the server.

You can always refer to the ZIP archieve for a complete example of the
integration.


### Test your setup

Once you have completed the software integration and uploaded the code to your
board, you can start testing the setup by connecting your board to the Hyper
Link device.

To connect the Hyper Link device you need to use a I2C-compatible port. Our
boards come with a I2C 3.3V QWIIC connector.

Hyper provides multiple Link devices for both development and production
scenarios.

During production you can use a Hypr Link device that supports a
network protocol most suitable for your deployment such as Thread, Bluetooth,
LoRa or WiFi.

For development we recommend using our Hyper Link WiFi device that makes is
easy to visualise the data coming in and out of your board. You can work with
it offline or online.


#### Monitor your Arduino board with the Hyper Link WiFi device

During development it is convenient to be able to inspect the communication
channel between your Arduino board and the Hyper Link WiFi device.

To start using Hyper Link WiFi:

1. Power the device on and hold the RESET button for 5 seconds.
2. On your computer or mobile phone connect to the "Hyper Link WiFI Setup -
   XX:XX:XX:XX:XX:XX" WiFi network. There is no password.
3. A network setup window will open where you can provide connection details
   for your local WiFi network.
     - Note: if the network setup window does not open automatically, you can
       go to `http://192.168.1.1` in your browser.
4. The Hyper Link WiFi device will restart and connect to your network. You can
   now connect to it from your computer or mobile phone by opening
   `http://hyper-link.local` in your browser.

Having these steps, you can now connect your board via I2C and start monitoring
your Arduino board with the Hyper Link WiFi device.


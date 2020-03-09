# Repo for general troubleshooting - open to public

## Status - 3/9/2020
<details>
<summary>This directory: "Troubleshoot-MXChipGPS"</summary>
<p>

- This is a listing of files reviewed and/or changed on 3/4/2020.
- These files will not be modified as of today, 3/9/2020.
- See the subdirectories for future updates.

</p>
</summary>
</details>

## Status - 3/4/2020

<details>
<summary>Hardware</summary>
<p>

- MXChip
- Adafruit "Ultimate GPS" module

</p>
</summary>
</details>

<details>
<summary>Software</summary>
<p>

- VS Code
- PlatforIO IDE
- Adafruit library
- Azure IoT Workbench - extension

</p>
</details>

<details>
<summary>Issues</summary>
<p>

- Setting up MXChip UART (Finger Connector)
- Setting up Adafruit "Ultimate GPS" module
- Between UART & GPS setup issues, can not read GPS Lat/Long in monitor

</p>
</details>

<details>
<summary>Solution (attempts) to Issues</summary>
<p>

- Solution1a: "Adafruit_GPS.h". Added: #include <AZ3166SPI.h>. Goal: reconcile SPI-undefined issue.

- Solution1b: "Adafruit_GPS.h". Because SoftwareSerial not available in MXChip library. Goal: followed in-file
              suggestion to comment out this option, lines 39 & 40:
              #define USE_SW_SERIAL ///< comment this out if you don't want to include
                                    ///< software serial in the library

- Solution2: "UARTClass.h". Added constructor, "UARTClass(UARTName p)" to "class UARTClass : public
              HardwareSerial".  Goal: setup up 2nd serial port (on finger connector), following Rob Miles proposed approach.

- Solution3: "Wire.h". Added member function, "uint8_t requestFrom(uint8_t, uint8_t, uint32_t, uint8_t, uint8_t)"
             to "class TwoWire". Also, added "#define WIRE_ERROR (-1)"
             Goal: to provide same member functions as shown in Arduino library.

- Solution4: "Variant.h": Added "extern UARTClass Serial1".  "Variant.cpp": Added "UARTClass Serial1(UART_1)".
             Goal: following Rob Miles recommendation.  

- Solution5: File5

</p>
</details>


<details>
<summary>Assumptions/Questions</summary>
<p>

- 1. MXChip can not use SoftwareSerial functions
- 2. 2nd Serial port for MXChip-GPS communications must be UART (not SPI or i2c)
- 3. Order of Serial vs. GPS initialization/functions
- 4. Syntax in main.cpp for:  Adafruit_GPS(HardwareSerial *ser); // Constructor when using HardwareSerial
- 5. Syntax in main.cpp for: UARTClass Serial1(UART_1);
- 6. Reconciling library differences between PlatformIO-IDE vs. Arduino-IDE
- 7. How to reconcile SPI.h functionality and low-level driver functionality?

</p>
</details>

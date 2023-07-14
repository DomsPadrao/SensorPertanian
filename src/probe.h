#include <Arduino.h>

// pre-define DEBUG when compiling to enable debug
#ifdef DEBUG

#include "debug.h"

#endif

// Probe constants parameters
const int PROBE_RX = 2;
const int PROBE_TX = 14;

const int TIMEOUT = 100;    // ms
const int MAX_RESEND = 10;

const byte NUM_SAMPLES = 10;

#if defined(PROBE_KHDTK)
const int PROBE_BAUDRATE = 9600;
// const byte code[]= {addressCode(0x01), functionCode(0x03), regStartAddr_L, regStartAddr_H, regLen_L, regLen_H, CRC_L, CRC_H};
const byte nitro[] = {0x01, 0x03, 0x00, 0x1E, 0x00, 0x01, 0xE4, 0x0C};
const byte phos[]  = {0x01, 0x03, 0x00, 0x1F, 0x00, 0x01, 0xB5, 0xCC};
const byte kali[]  = {0x01, 0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xC0};
const byte ph[]    = {0x01, 0x03, 0x00, 0x06, 0x00, 0x01, 0x64, 0x0B};
const byte temp[]  = {0x01, 0x03, 0x00, 0x13, 0x00, 0x01, 0x75, 0xCF};
const byte hum[]   = {0x01, 0x03, 0x00, 0x12, 0x00, 0x01, 0x24, 0x0F};
const byte ec[]    = {0x01, 0x03, 0x00, 0x15, 0x00, 0x01, 0x95, 0xCE};

#elif defined(PROBE_DEFAULT)
const int PROBE_BAUDRATE = 4800;
// const byte code[]= {addressCode(0x01), functionCode(0x03), regStartAddr_L, regStartAddr_H, regLen_L, regLen_H, CRC_L, CRC_H};
const byte nitro[] = {0x01, 0x03, 0x00, 0x04, 0x00, 0x01, 0xC5, 0xCB};
const byte phos[]  = {0x01, 0x03, 0x00, 0x05, 0x00, 0x01, 0x94, 0x0B};
const byte kali[]  = {0x01, 0x03, 0x00, 0x06, 0x00, 0x01, 0x64, 0x0B};
const byte ph[]    = {0x01, 0x03, 0x00, 0x03, 0x00, 0x01, 0x74, 0x0A};
const byte temp[]  = {0x01, 0x03, 0x00, 0x01, 0x00, 0x01, 0xD5, 0xCA};
const byte hum[]   = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A};
const byte ec[]    = {0x01, 0x03, 0x00, 0x02, 0x00, 0x01, 0x25, 0xCA};

#endif

const byte CODE_SIZE = 8;
const byte RESPONSE_SIZE = 7;

// class for storing soil data
class SoilData {
private:
    HardwareSerial probe;

public:
    int nitrogen, phosphorus, kalium;
    float pH, temperature, humidity;
    int EC;
    
    SoilData(int HWSerialNum=1);

    void sample();

    bool send_data_req(const byte code[]);
    int get_data(const byte code[]);
};
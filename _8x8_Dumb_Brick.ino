#include <LedControl.h>
#include <avr/pgmspace.h>


#define DEVICES  1
#define DIN_PIN  0
#define CS_PIN   1
#define CLK_PIN  2
#define IR_SENSOR 4
#define LED_OUT   3


LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, DEVICES);

byte frame_buffer[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

const byte message_data[] PROGMEM = {
    B01111111,  // H
    B00001000,
    B00001000,
    B00001000,
    B01111111,
    B00000000,
    B00000000,
    B00000000,

    B01111110,  // A
    B00010001,
    B00010001,
    B00010001,
    B01111110,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // P
    B00001001,
    B00001001,
    B00001001,
    B00000110,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // P
    B00001001,
    B00001001,
    B00001001,
    B00000110,
    B00000000,
    B00000000,
    B00000000,

    B00000111,  // Y
    B00001000,
    B01110000,
    B00001000,
    B00000111,
    B00000000,
    B00000000,
    B00000000,

    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,

    B00000000,  // 1
    B01000010,
    B01111111,
    B01000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,

    B00100111,  // 5
    B01000101,
    B01000101,
    B01000101,
    B00111001,
    B00000000,
    B00000000,
    B00000000,

    B00000001,  // T
    B00000001,
    B01111111,
    B00000001,
    B00000001,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // H
    B00001000,
    B00001000,
    B00001000,
    B01111111,
    B00000000,
    B00000000,
    B00000000,

    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,

    B01111110,  // A
    B00010001,
    B00010001,
    B00010001,
    B01111110,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // N
    B00000100,
    B00001000,
    B00010000,
    B01111111,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // N
    B00000100,
    B00001000,
    B00010000,
    B01111111,
    B00000000,
    B00000000,
    B00000000,

    B00000000,  // I
    B01000001,
    B01111111,
    B01000001,
    B00000000,
    B00000000,
    B00000000,
    B00000000,

    B00011111,  // V
    B00100000,
    B01000000,
    B00100000,
    B00011111,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // E
    B01001001,
    B01001001,
    B01001001,
    B01000001,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // R
    B00001001,
    B00011001,
    B00101001,
    B01000110,
    B00000000,
    B00000000,
    B00000000,

    B01000110,  // S
    B01001001,
    B01001001,
    B01001001,
    B00110000,
    B00000000,
    B00000000,
    B00000000,

    B01111110,  // A
    B00010001,
    B00010001,
    B00010001,
    B01111110,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // R
    B00001001,
    B00011001,
    B00101001,
    B01000110,
    B00000000,
    B00000000,
    B00000000,

    B00000111,  // Y
    B00001000,
    B01110000,
    B00001000,
    B00000111,
    B00000000,
    B00000000,
    B00000000,

    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // M
    B00000010,
    B00001100,
    B00000010,
    B01111111,
    B00000000,
    B00000000,
    B00000000,

    B00000111,  // Y
    B00001000,
    B01110000,
    B00001000,
    B00000111,
    B00000000,
    B00000000,
    B00000000,

    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // L
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B00000000,
    B00000000,
    B00000000,

    B00111110,  // O
    B01000001,
    B01000001,
    B01000001,
    B00111110,
    B00000000,
    B00000000,
    B00000000,

    B00011111,  // V
    B00100000,
    B01000000,
    B00100000,
    B00011111,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // E
    B01001001,
    B01001001,
    B01001001,
    B01000001,
    B00000000,
    B00000000,
    B00000000,

    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,

    B00000110,
    B00011001,
    B01100010,
    B00011001,
    B00000110,
    B00000000,
    B00000000,
    B00000000,

    B00000110,
    B00011111,
    B01111110,
    B00011111,
    B00000110,
    B00000000,
    B00000000,
    B00000000,

    B00000110,
    B00011001,
    B01100010,
    B00011001,
    B00000110,
    B00000000,
    B00000000,
    B00000000,

    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
};

const byte song_data[] PROGMEM = {
    B01111110,  // A
    B00010001,
    B00010001,
    B00010001,
    B01111110,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // L
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // L
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B00000000,
    B00000000,
    B00000000,

    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,

    B00000000,  // I
    B01000001,
    B01111111,
    B01000001,
    B00000000,
    B00000000,
    B00000000,
    B00000000,

    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,

    B00111111,  // W
    B01000000,
    B00111000,
    B01000000,
    B00111111,
    B00000000,
    B00000000,
    B00000000,

    B01111110,  // A
    B00010001,
    B00010001,
    B00010001,
    B01111110,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // N
    B00000100,
    B00001000,
    B00010000,
    B01111111,
    B00000000,
    B00000000,
    B00000000,

    B00000001,  // T
    B00000001,
    B01111111,
    B00000001,
    B00000001,
    B00000000,
    B00000000,
    B00000000,

    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,

    B00000000,  // I
    B01000001,
    B01111111,
    B01000001,
    B00000000,
    B00000000,
    B00000000,
    B00000000,

    B01000110,  // S
    B01001001,
    B01001001,
    B01001001,
    B00110000,
    B00000000,
    B00000000,
    B00000000,

    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,

    B00000001,  // T
    B00000001,
    B01111111,
    B00000001,
    B00000001,
    B00000000,
    B00000000,
    B00000000,

    B00111110,  // O
    B01000001,
    B01000001,
    B01000001,
    B00111110,
    B00000000,
    B00000000,
    B00000000,

    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // H
    B00001000,
    B00001000,
    B00001000,
    B01111111,
    B00000000,
    B00000000,
    B00000000,

    B00111110,  // O
    B01000001,
    B01000001,
    B01000001,
    B00111110,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // L
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // D
    B01000001,
    B01000001,
    B00100010,
    B00011100,
    B00000000,
    B00000000,
    B00000000,

    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,

    B00000111,  // Y
    B00001000,
    B01110000,
    B00001000,
    B00000111,
    B00000000,
    B00000000,
    B00000000,

    B00111110,  // O
    B01000001,
    B01000001,
    B01000001,
    B00111110,
    B00000000,
    B00000000,
    B00000000,

    B00111111,  // U
    B01000000,
    B01000000,
    B01000000,
    B00111111,
    B00000000,
    B00000000,
    B00000000,

    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // F
    B00001001,
    B00001001,
    B00001001,
    B00000001,
    B00000000,
    B00000000,
    B00000000,

    B00111110,  // O
    B01000001,
    B01000001,
    B01000001,
    B00111110,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // R
    B00001001,
    B00011001,
    B00101001,
    B01000110,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // E
    B01001001,
    B01001001,
    B01001001,
    B01000001,
    B00000000,
    B00000000,
    B00000000,

    B00011111,  // V
    B00100000,
    B01000000,
    B00100000,
    B00011111,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // E
    B01001001,
    B01001001,
    B01001001,
    B01000001,
    B00000000,
    B00000000,
    B00000000,

    B01111111,  // R
    B00001001,
    B00011001,
    B00101001,
    B01000110,
    B00000000,
    B00000000,
    B00000000,

    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,

    B00000110,
    B00011001,
    B01100010,
    B00011001,
    B00000110,
    B00000000,
    B00000000,
    B00000000,

    B00000110,
    B00011111,
    B01111110,
    B00011111,
    B00000110,
    B00000000,
    B00000000,
    B00000000,

    B00000110,
    B00011001,
    B01100010,
    B00011001,
    B00000110,
    B00000000,
    B00000000,
    B00000000,

    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
};


ISR(PCINT0_vect) {
    digitalWrite(LED_OUT, digitalRead(IR_SENSOR));
}

void setup() {
    for (int x=0; x<DEVICES; x++){
        lc.shutdown(x,false);       //The MAX72XX is in power-saving mode on startup
        lc.setIntensity(x, 3);      // Set the brightness to default value
        lc.clearDisplay(x);         // and clear the display
    }
    //pinMode(IR_SENSOR, INPUT);
    //pinMode(LED_OUT, OUTPUT);

    //GIMSK = _BV(PCIE);    // Enable pin change interrupt
    //PCMSK = _BV(PCINT4);  // Enable the interrupt for only pin 4.

    lc.setLed(0, 0, 0, 1);
    delay(500);
    lc.setLed(0, 0, 0, 0);
    delay(500);
    lc.setLed(0, 0, 0, 1);
    delay(500);
    lc.setLed(0, 0, 0, 0);
    delay(2500);
}


void loop() {
    int frame_delay = 65;
    for (int idx=0; idx<sizeof(message_data); idx++) {
        shift_display(pgm_read_byte_near(message_data + idx));
        show_display_buffer();
        delay(frame_delay);
    }
    delay(10000);
    frame_delay = 30;
    for (int idx=0; idx<sizeof(song_data); idx++) {
        shift_display(pgm_read_byte_near(song_data + idx));
        show_display_buffer();
        delay(frame_delay);
    }
    delay(5000);
}

void shift_display(byte next_col) {
    for (byte row=0; row<sizeof(frame_buffer); row++) {
        frame_buffer[row] = frame_buffer[row] << 1 | bitRead(next_col, row);
    }
}

void show_display_buffer() {
    byte tmp_buffer[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

    for (byte row=0; row<sizeof(tmp_buffer); row++) {
        for (byte col=0; col<8; col++) {
            bitWrite(tmp_buffer[7-col], row, bitRead(frame_buffer[7-row], 7-col));
            //lc.setLed(0, 7-col, row, bitRead(display_buffer[row], col));
            //delay(100);
        }
    }

    for (int row=0; row<sizeof(tmp_buffer); row++) {
        lc.setRow(0, row, tmp_buffer[row]);
    }
}


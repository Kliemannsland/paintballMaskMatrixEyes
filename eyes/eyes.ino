#include <LEDMatrixDriver.hpp>

const uint8_t LEDMATRIX_CS_PIN = 9;

// Define LED Matrix dimensions (0-n) - eg: 32x8 = 31x7
const int LEDMATRIX_WIDTH = 31;  
const int LEDMATRIX_HEIGHT = 7;
const int LEDMATRIX_SEGMENTS = 4;

// The LEDMatrixDriver class instance
LEDMatrixDriver lmd(LEDMATRIX_SEGMENTS, LEDMATRIX_CS_PIN);

void setup() {
  // init the display
  lmd.setEnabled(true);
  lmd.setIntensity(2);   // 0 = low, 10 = high
  randomSeed(analogRead(0));
}

int x=-1, y=0;   // start top left
bool s = true;  // start with led on

byte a[8]={ B00000000,
            B00000001,
            B00000011,
            B00000110,
            B00001100,
            B00011000,
            B00110000,
            B01100000};

byte b[8]={ B00000000,
            B10000000,
            B11000000,
            B01100000,
            B00110000,
            B00011000,
            B00001100,
            B00000110};

byte c[8]={ B00000000,
            B00000000,
            B00000001,
            B00000011,
            B00000110,
            B00001100,
            B00000000,
            B00000000};            

byte d[8]={ B00000000,
            B00000000,
            B10000000,
            B11000000,
            B01100000,
            B00110000,
            B00000000,
            B00000000};

byte e[8]={ B00000000,
            B00000000,
            B00000000,
            B00000011,
            B00000011,
            B00000000,
            B00000000,
            B00000000};

byte f[8]={ B00000000,
            B00000000,
            B00000000,
            B11000000,
            B11000000,
            B00000000,
            B00000000,
            B00000000};
            
byte g[8]={ B00011000,
            B00001100,
            B00000110,
            B00000011,
            B00000011,
            B00000110,
            B00001100,
            B00011000};

byte h[8]={ B00011000,
            B00110000,
            B01100000,
            B11000000,
            B11000000,
            B01100000,
            B00110000,
            B00011000};

byte i[8]={ B00001100,
            B00000110,
            B00000011,
            B00000001,
            B00000001,
            B00000011,
            B00000110,
            B00001100};

byte j[8]={ B00110000,
            B01100000,
            B11000000,
            B10000000,
            B10000000,
            B11000000,
            B01100000,
            B00110000};
            
const int ANIM_DELAY = 100;

boolean mode = true;

void loop() {

  if (random(0, 200) > 195) {
    mode = !mode;
  }

  if(mode) {
    triangle();
  } else {
    xing();
  }
    lmd.display();
    delay(ANIM_DELAY);

  if (random(0, 200) > 195) {
    blink();
    close();
    blink();
  }
}

void blink() {
  drawSprite( (byte*)&c, 0, 0, 8, 8 );
  drawSprite( (byte*)&d, 8, 0, 8, 8 );
  drawSprite( (byte*)&c, 16, 0, 8, 8 );
  drawSprite( (byte*)&d, 24, 0, 8, 8 );
  lmd.display();
  delay(100);
}

void close() {
  drawSprite( (byte*)&e, 0, 0, 8, 8 );
  drawSprite( (byte*)&f, 8, 0, 8, 8 );
  drawSprite( (byte*)&e, 16, 0, 8, 8 );
  drawSprite( (byte*)&f, 24, 0, 8, 8 );
  lmd.display();
  delay(100);
}

void xing() {
  drawSprite( (byte*)&i, 0, 0, 8, 8 );
  drawSprite( (byte*)&j, 8, 0, 8, 8 );
  drawSprite( (byte*)&i, 16, 0, 8, 8 );
  drawSprite( (byte*)&j, 24, 0, 8, 8 );
  lmd.display();
}

void triangle() {
  drawSprite( (byte*)&a, 0, 0, 8, 8 );
  drawSprite( (byte*)&b, 8, 0, 8, 8 );
  drawSprite( (byte*)&a, 16, 0, 8, 8 );
  drawSprite( (byte*)&b, 24, 0, 8, 8 );
}

void drawSprite( byte* sprite, int x, int y, int width, int height )
{
  byte mask = B10000000;
  for( int iy = 0; iy < height; iy++ )
  {
    for( int ix = 0; ix < width; ix++ )
    {
      lmd.setPixel(x + ix, y + iy, (bool)(sprite[iy] & mask ));
      mask = mask >> 1;
    }
    mask = B10000000;
  }
}


#include "FastLED.h" // add fastled library
#include    // add sdfat library


#define NUM_LEDS 225  // total leds  
#define DATA_PIN 7    // led data pin
CRGB leds[NUM_LEDS];

//SD chip select pin
const uint8_t chipSelect = SS; //chipSelect = 10;

SdFat sd;
SdFile file;


void setup() { 
      // Uncomment/edit one of the following lines for your leds arrangement.
      // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
       FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS); 
       // led in use - ws2811 with color sequence RGB
      // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);
      
      // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);

      // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);

     
}

void loop() { 
  
    sd.begin(chipSelect, SPI_FULL_SPEED);
  
  /*******************************************/
  // open first effect file - rainbow.dat
  // file size 70,800 bytes
      //or
  // total leds 118
  // 3 bytes for each rgb color
  // total recorded frames 200
  // 118 x 3 X 200 = 70,800 bytes
  /*******************************************/
  
   file.open("D0.dat", O_READ); 

   for(int i = 0 ;i<200;i++) // 200 frames
  {
    
   file.read((uint8_t*)leds,NUM_LEDS*3); // total bytes(buffer) for each frame 118 x 3 = 354
                         

  FastLED.show();
  delay(40); // delay between each frame 
  }

  file.close();

  
}
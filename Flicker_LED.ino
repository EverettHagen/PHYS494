#include <FastLED.h>

#define LED_PIN 8    // The signal output pin
#define NUM_LEDS 48  // The number of LEDs you have

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  randomSeed(analogRead(0));
}

void loop() {
  int numToTrigger = random(1, NUM_LEDS + 1); 

  for (int i = 0; i < numToTrigger; i++) {  
    leds[i] = CHSV(219, 58, 93);  //Inside CHSV() can change the colors according to HSV Color model
    FastLED.show();
    delay(100);  // How long till next LED turns on

    leds[i] = CHSV(0, 0, 0); 
    FastLED.show();
    delay(200);  // How long LED stays on
  }

  delay(random(0, 2000));  // Pause before next cycle
}

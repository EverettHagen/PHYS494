#include <FastLED.h>

#define LED_PIN 8
#define NUM_LEDS 48  // Change this based on the number of LEDs you have

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  randomSeed(analogRead(0)); // Initialize random seed
}

void loop() {
  int numToTrigger = random(1, NUM_LEDS + 1);  // Random number of LEDs to trigger sequentially

  for (int i = 0; i < numToTrigger; i++) {  
    leds[i] = CHSV(219, 58, 93);  // Turn on LED
    FastLED.show();
    delay(100);  // Delay between each LED lighting up

    leds[i] = CHSV(0, 0, 0);  // Turn off LED after delay
    FastLED.show();
    delay(200);
  }

  delay(random(0, 2000));  // Random pause before next cycle
}

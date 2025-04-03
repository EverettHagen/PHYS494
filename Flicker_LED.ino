#include <FastLED.h>
 
 #define LED_PIN 8    // The signal output pin
 #define NUM_LEDS 48  // The number of LEDs you have


 CRGB leds[NUM_LEDS];
 
 
 void setup() {
   FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
   randomSeed(analogRead(0)); //# Create random
 }
 
 void loop() {
   int numToTrigger = random(1, NUM_LEDS + 1); //#  Random number of LEDs to trigger sequentially
   int intensity = numToTrigger * 12 ; //# makes the number triggered proportional to the internsity of the light 
   int color = random(90,270); // values which the LED could be 
   for (int i = 0; i < numToTrigger; i++) {  
     leds[i] = CHSV(color, 200, intensity);  // Inside CHSV() can change the colors according to HSV Color model
     FastLED.show();
     delay(100);  // How long the LED stays on 
 
    //  leds[i] = CHSV(0, 0, 0); 
     leds[i] = CHSV(0, 0, 0);  //#  Turn off LED after delay
     FastLED.show();
     delay(200); // How long till next LED gets triggered
   }
 
   delay(random(0, 1000));  // Pause before next cycle
 }

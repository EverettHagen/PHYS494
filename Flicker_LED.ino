#include <FastLED.h>
 

 #define LED_PIN 8    // The signal output pin
 #define LED_PIN2 12    // The signal output pin
 #define LED_PIN3 13    // The signal output pin
 #define NUM_LEDS 21  // The number of LEDs you have


 CRGB leds1[NUM_LEDS];
 CRGB leds2[NUM_LEDS];
 CRGB leds3[NUM_LEDS];
 
 
 void setup() {
   FastLED.addLeds<WS2812, LED_PIN, GRB>(leds1, NUM_LEDS);
   FastLED.addLeds<WS2812, LED_PIN2, GRB>(leds2, NUM_LEDS);
   FastLED.addLeds<WS2812, LED_PIN3, GRB>(leds3, NUM_LEDS);
   randomSeed(analogRead(0)); //# Create random

 }
 
 void loop() {
  //LED 1
   int numToTrigger = random(1, NUM_LEDS + 1); //#  Random number of LEDs to trigger sequentially
   int intensity = numToTrigger * 12 ; //# makes the number triggered proportional to the internsity of the light 
   int color = random(85,212); // values which the LED could be 
   for (int i = 0; i < numToTrigger; i++) {  
     leds1[i] = CHSV(color, 200, intensity); // Inside CHSV() can change the colors according to HSV Color model
     FastLED.show();
     delay(10);  // How long the LED stays on leds[i] = CHSV(color, 200, intensity);  // Inside CHSV() can change the colors according to HSV Color model

     leds1[i+1] = CHSV(color, 200, intensity); // Inside CHSV() can change the colors according to HSV Color model
     FastLED.show();
     delay(10);  // How long the LED stays on leds[i] = CHSV(color, 200, intensity);  // Inside CHSV() can change the colors according to HSV Color model
 
     leds1[i] = CHSV(0, 0, 0); //#  Turn off LED after delay
     FastLED.show();
     delay(50); // How long till next LED gets triggered
    //  leds[i+1] = CHSV(0, 0, 0);  //#  Turn off LED after delay
    //  FastLED.show();
    //  delay(200); // How long till next LED gets triggered
   }
 
  //  delay(random(0, 400));  // Pause before next cycle

  //LED 2
   int numToTrigger2 = random(1, NUM_LEDS + 1); //#  Random number of LEDs to trigger sequentially
   int intensity2 = numToTrigger2 * 12 ; //# makes the number triggered proportional to the internsity of the light 
   int color2 = random(85,212); // values which the LED could be 
   for (int i = 0; i < numToTrigger2; i++) {   
     leds2[i] = CHSV(color2, 200, intensity2);// Inside CHSV() can change the colors according to HSV Color model
     FastLED.show();
     delay(10);  // How long the LED stays on leds[i] = CHSV(color, 200, intensity);  // Inside CHSV() can change the colors according to HSV Color model

     leds2[i+1] = CHSV(color2, 200, intensity2); // Inside CHSV() can change the colors according to HSV Color model
     FastLED.show();
     delay(10);  // How long the LED stays on leds[i] = CHSV(color, 200, intensity);  // Inside CHSV() can change the colors according to HSV Color model
 
     leds2[i] = CHSV(0, 0, 0); //#  Turn off LED after delay
     FastLED.show();
     delay(50); // How long till next LED gets triggered
    //  leds[i+1] = CHSV(0, 0, 0);  //#  Turn off LED after delay
    //  FastLED.show();
    //  delay(200); // How long till next LED gets triggered
   }
 
  //  delay(random(0, 400));  // Pause before next cycle
  //LED 3
   int numToTrigger3 = random(1, NUM_LEDS + 1); //#  Random number of LEDs to trigger sequentially
   int intensity3 = numToTrigger3 * 12 ; //# makes the number triggered proportional to the internsity of the light 
   int color3 = random(85,212); // values which the LED could be 
   for (int i = 0; i < numToTrigger3; i++) {  
     leds3[i] = CHSV(color3, 200, intensity3); // Inside CHSV() can change the colors according to HSV Color model
     FastLED.show();
     delay(10);  // How long the LED stays on leds[i] = CHSV(color, 200, intensity);  // Inside CHSV() can change the colors according to HSV Color model

     leds3[i+1] = CHSV(color3, 200, intensity3);  // Inside CHSV() can change the colors according to HSV Color model
     FastLED.show();
     delay(10);  // How long the LED stays on leds[i] = CHSV(color, 200, intensity);  // Inside CHSV() can change the colors according to HSV Color model
 
     leds3[i] = CHSV(0, 0, 0);  //#  Turn off LED after delay
     FastLED.show();
     delay(50); // How long till next LED gets triggered
    //  leds[i+1] = CHSV(0, 0, 0);  //#  Turn off LED after delay
    //  FastLED.show();
    //  delay(200); // How long till next LED gets triggered
   }
     delay(random(0, 400));
 }
 

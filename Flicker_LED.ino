#include <FastLED.h>

using namespace std;

#define LED_PIN 8  // The signal output pin
#define NUM_LEDS 8 // The number of LEDs you have

CRGB leds[NUM_LEDS];


//# Assigning variables
const float E_min = 6.0; //# Average energy at creation according to LBNL GeV
const float c = 2.99e5; //# Speed of light in km/s
const float m_mass = 0.10; //# Rough Muon mass in GeV/c^2
const float life_m = 2.2e-6; //# Muon lifetime in s

// Power-Law distribution, E^-2.7
void energies(int Number, double E_min, double E[]) {
    for (int i = 0; i < Number; ++i) {
        double r = random(0, 1); //# generate a random number between 0 and 1, double is useful here because it gives more options
        E[i] = E_min * pow(1 - r, -1.0 / (2.7 - 1));  //# 
    }
}

// Find Lorentz gamma and decay length
void lorentz_gamma(const double E_muons[], int size, double gamma[]) {
    for (int i = 0; i < size; ++i) {
        gamma[i] = E_muons[i] / m_mass;
    }
}

void decay_lengths(const double gamma[], int size, double decay_length[]) {
    for (int i = 0; i < size; ++i) {
        decay_length[i] = gamma[i] * c * life_m;
    }
}

void decay_distances(const double decay_length[], int size, double distances[]) {
    for (int i = 0; i < size; ++i) {
        double rand_exp = -log(1.0 - random(0, 10000) / 10000.0);
        distances[i] = rand_exp * decay_length[i];
    }
}

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  randomSeed(analogRead(0));
}

void loop() {
  // Create arrays for energies, gamma values, decay lengths, and distances
  double E[NUM_LEDS];
  double gamma[NUM_LEDS];
  double decay_length[NUM_LEDS];
  double distances[NUM_LEDS];

  // Get the energies for the muons
  energies(NUM_LEDS, E_min, E);

  // Find Lorentz gamma and decay length for each muon
  lorentz_gamma(E, NUM_LEDS, gamma);
  decay_lengths(gamma, NUM_LEDS, decay_length);

  // Find decay distances based on the decay length
  decay_distances(decay_length, NUM_LEDS, distances);

  // Calculate how many LEDs to trigger based on the decay distance
  int numToTrigger = (int)(distances[random(0, NUM_LEDS)] / 250.0 * 8); // Scale decay distance to 8 LEDs
  numToTrigger = constrain(numToTrigger, 1, NUM_LEDS);//# VERY IMPORTANT DO NOT DELETE!! will cause LED to fail otherwise!!
  int intensity = map(numToTrigger, 1, NUM_LEDS, 10, 100); //# intensity based on the number of LEDs triggered; last two values are the low and high of intensity 
  int color = random(90, 270); // values which the color could be 

  // Sequentially trigger LEDs
  for (int i = 0; i < numToTrigger; i++) {
    leds[i] = CHSV(color, 200, intensity);  // Inside CHSV() can change the colors according to HSV Color model
    FastLED.show(); 
    delay(100);  // How long the LED stays on 

    leds[i] = CHSV(0, 0, 0);
    FastLED.show();
    delay(200);  // How long till next LED gets triggered
  }

  delay(random(0, 1000));  // Pause before the next cycle
}

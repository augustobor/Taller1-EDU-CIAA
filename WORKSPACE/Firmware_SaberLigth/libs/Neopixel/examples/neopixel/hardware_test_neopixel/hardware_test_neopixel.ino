#include <Adafruit_NeoPixel.h>

// Definiciones de pines
#define PIN_LED 2   // LED integrado

#define PIN_ADC 32  // Pin para lectura analógica GPIO32 usa el ADC1 que NO INTERFIERE CON EL WIFI
  // Parametros ws2812b
#define PIN_LED_WS 5   // LED WS2812b - GPIO5
#define LED_LENGTH  111 // tira led de 111 pixels

// Objeto controlador Neopixel
Adafruit_NeoPixel strip(LED_LENGTH, PIN_LED_WS, NEO_GRB + NEO_KHZ800);

// funciones
void Test_RGB(float brillo);

void setup() {
  Serial.begin(115200); delay(10);
  Serial.println();
  Serial.println("Iniciando Test Neopixel ...");

  // Configuración de pines
  pinMode(PIN_LED_WS, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_ADC, INPUT);

}

void loop() {
  Test_RGB(10);
  Test_RGB(50);
  Test_RGB(128);
  Test_RGB(170);
  Test_RGB(255);

}


void Test_RGB(float brillo) {
  if(brillo>255) brillo=255;// trunca de 0 a 255
  if(brillo<0) brillo=0;

  for (int i = 0; i < LED_LENGTH; i++) { // prende ROJO
    strip.setPixelColor(i, strip.Color(brillo,0,0));
  }
  strip.show();
  delay(500);

  for (int i = 0; i < LED_LENGTH; i++) { // prende Verde
    strip.setPixelColor(i, strip.Color(0,brillo,0));
  }
  strip.show();
  delay(500);

  for (int i = 0; i < LED_LENGTH; i++) { // prende Azul
    strip.setPixelColor(i, strip.Color(0,0,brillo));
  }
  strip.show();
  delay(500);

  strip.clear(); // mantiene apagado
  delay(500);



}
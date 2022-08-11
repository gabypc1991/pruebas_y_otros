#include <Adafruit_NeoPixel.h>

#define PIN 6 //Neopixel pin
#define NUMPIXELS 40 //Numero de leds

uint8_t  todo_led[8] =  {1,1,1,1,1,1,1,1};
uint8_t  cero_led[8] =  {0,0,0,0,0,0,0,0};

uint8_t  data_led0[8] =  {1,0,0,0,0,0,0,0};
uint8_t  data_led1[8] =  {1,1,0,0,0,0,0,0};
uint8_t  data_led2[8] =  {1,1,1,0,0,0,0,0};
uint8_t  data_led3[8] =  {1,1,1,1,0,0,0,0};
uint8_t  data_led4[8] =  {1,1,1,1,1,0,0,0};
uint8_t  data_led5[8] =  {1,1,1,1,1,1,0,0};
uint8_t  data_led6[8] =  {1,1,1,1,1,1,1,0};
uint8_t  data_led7[8] =  {1,1,1,1,1,1,1,1};

int amarillo[3] = {255, 255, 0};
int blanco[3] =   {255, 255, 255};
int naranja[3] =  {200, 127, 0};
int rojo[3] =     {255, 0, 0};
int verde[3] =    {0, 255, 0};
int azul[3] =     {0, 0, 255};

int porcentaje;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
 pixels.begin();
 barra_neopixel(rojo, todo_led, 20);
 barra_neopixel(verde, todo_led, 20);
 barra_neopixel(azul, todo_led, 20);
 barra_neopixel(amarillo, todo_led, 20);
 barra_neopixel(amarillo, cero_led, 20);
}

void loop() {
 calc_porcentaje();
}

void calc_porcentaje(){
  if(porcentaje >= 0 && porcentaje < 12){
    barra_neopixel(rojo, data_led0, 0);
    }
  if(porcentaje >= 12 && porcentaje < 24){
    barra_neopixel(rojo, data_led1, 0);
    }
  if(porcentaje >= 24 && porcentaje < 36){
    barra_neopixel(rojo, data_led2, 0);
    }
  if(porcentaje >= 36 && porcentaje < 48){
    barra_neopixel(amarillo, data_led3, 0);
    }
  if(porcentaje >= 48 && porcentaje < 60){
    barra_neopixel(amarillo, data_led4, 0);
    }
  if(porcentaje >= 60 && porcentaje < 72){
    barra_neopixel(amarillo, data_led5, 0);
    }
  if(porcentaje >= 72 && porcentaje < 95){
    barra_neopixel(amarillo, data_led6, 0);
    }
  if(porcentaje >= 95){
    barra_neopixel(verde, data_led7, 0);
    }
  }

void barra_neopixel(int color[3], uint8_t print_np[40], int tmr){
  for ( int i = 0; i < NUMPIXELS; i++){
   int red;
   int green;
   int blue;
   int idv_led = print_np[i];
   if(idv_led > 0){
     red = color[0];
     green = color[1];
     blue = color[2];
   }else{        
     red = 0;
     green = 0;
     blue = 0;
   }
   
   pixels.setPixelColor(i, pixels.Color(red, green, blue));
   pixels.show();
   delay(tmr);
  }
}

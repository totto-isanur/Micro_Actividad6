/*
Israel Hernandez Alvarez
actividad de nombre
Oled_Microprecesadores
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "ssd1306.h"
#define T 5000

const uint8_t num_chars_per_disp[]={7,7,7,5};



void inicio(void);
void pant(void);

int main() {

    stdio_init_all();
    inicio();
    pant();

    return 0;
}


void inicio(void) {
    //se designa los puestos y la frecuencia a usars
    i2c_init(i2c1, 400000);
    gpio_set_function(2, GPIO_FUNC_I2C);
    gpio_set_function(3, GPIO_FUNC_I2C);
    gpio_pull_up(2);
    gpio_pull_up(3);
}


void pant(void) {
    //inicializacion ed variables y del display
    int x=128;
    ssd1306_t disp;
    disp.external_vcc=false;
    ssd1306_init(&disp, 128, 64, 0x3C, i2c1);
    ssd1306_clear(&disp);
    char buf[8];

   
    while (true)
    {
    //cargado de texto a mostrar el cual lo iniciamos en la coordenada x
            ssd1306_clear(&disp);
            ssd1306_draw_string(&disp, x,20,1, "Israel Hernandez" );  
            ssd1306_draw_string(&disp, x,50,1, "Alvarez_Microprocesadores");
            ssd1306_show(&disp);
            sleep_ms(10);
    //se hace el corriento para x, para que el nombre salga de la pantalla
         x -= 2;  
        if (x < -200) {
            x = 128; 
        }
    }

            
        }
     
    
    
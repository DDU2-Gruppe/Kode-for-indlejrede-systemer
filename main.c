/*
 * GccApplication1.c
 *
 * Created: 
 *  Author: 
 */ 

#include <avr/io.h> 
#include <util/delay.h>
#include <avr/interrupt.h>

#ifndef F_CPU //hvis F_CPU  (hastighed for MCU, (konstant / her til brug i udregninger)
#define F_CPU 8000000UL  //så definer den til 8Mhz
#endif
#define BIT(x) (1 << (x))
#define SETBITS(x,y) ((x) |= (y))
#define CLEARBITS(x,y) ((x) &= (~(y)))
#define SETBIT(x,y) SETBITS((x), (BIT((y))))
#define CLEARBIT(x,y) CLEARBITS((x), (BIT((y))))
#define BITVAL(x,y) (((x)>>(y)) & 1)
#define HERTZ(x) ((CPU_CLOCK/400)/2)

//andre defines
#define TAL_PORT PORTD 
#define DIS_PORT PORTC 


//DISPLAY
#define DISPLAY_1 PC4
#define DISPLAY_2 PC3
#define DISPLAY_3 PC2


#define SW_PIN PINC 
#define SWITCH_B PC0 
#define SWITCH_A PC1



void init(){
    DDRD = 0xFF; //alle bits på portd = output
    DDRC = 0x1C; //alle bits på portc = inputs
}
 

                                                               
int main(void){   
	init();

	uint8_t i = 0;
 	uint8_t j = 0; // 100
    uint8_t k = 0; // 10
    uint8_t l = 1; // 1
    uint8_t del = 0;
    uint8_t tim = 2;
    uint8_t talArr[] = {0x3F, 0x6, 0x5B, 0x4F, 0x66, 0x6D, 0xFD, 0x7, 0x7F, 0xEF};
	uint8_t frem = 1;
	uint8_t slut = 0;
	//uint8_t nV = 0;
	//uint8_t pV = 0;
	//uint8_t reg = 0;
 
    while(1){
        

		
        for(del = 0; del < 50; ++del){
        
            for(i = 0; i < 4; ++i){
            
 
                if (i == 0){
                    SETBIT(DIS_PORT, DISPLAY_1);
                    TAL_PORT = ~talArr[j];
                    _delay_ms(tim);
                    CLEARBIT(DIS_PORT, DISPLAY_1);
                }
 
                if (i == 1){
                    SETBIT(DIS_PORT, DISPLAY_2);
                    TAL_PORT = ~talArr[k];
                    _delay_ms(tim);
                    CLEARBIT(DIS_PORT, DISPLAY_2);
                }
 
                if (i == 2){
                    SETBIT(DIS_PORT, DISPLAY_3);
                    TAL_PORT = ~talArr[l];
                    _delay_ms(tim);
                    CLEARBIT(DIS_PORT, DISPLAY_3);
                }
 
 
            }
 
 
        }
    
      	
		// tæller frem
		if (frem == 1 && slut == 0) {
			if(k == 9 && j == 9 && l == 9){
				slut = 1;
			} else {
				if(l==9){
					l = 0;
					if(k==9){
						k = 0;
						if(j==9) {
							j = 0;
						} else {
							++j;
						}
					} else {
						++k;
					}
				} else {
					++l;
				}
			}
		}

	 

 
		

	}

return 0; 

}























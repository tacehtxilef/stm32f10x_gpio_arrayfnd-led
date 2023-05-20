#include <stdint.h>
#include "config.h"


#define delay_time 0xAFF

void delay(uint32_t  a)
{
  for(;a>0;a--){
  }
}
void GPIOA_Output_Init(uint16_t  pinNum, GPIOSpeed_TypeDef speedValE, GPIOMode_Output_TypeDef modeE) {
  uint32_t  tmpVal=modeE << 2 | speedValE;
  uint32_t  pinpos=0x00;
  
  //pin #0 ~ #7
  if((pinNum & 0xFF) !=0){
          for(pinpos = 0x00; pinpos <0x08; pinpos++) {
                  if(pinNum &((uint32_t)0x01 << pinpos)){
                          GPIOA->CRL &= ~(0xF << (pinpos*4));
                          GPIOA->CRL |= tmpVal << (pinpos*4);
                  }
          }
  }else{
          pinNum=pinNum >>8;
          for(pinpos = 0x00; pinpos <0x08; pinpos++){
                           if(pinNum==((uint32_t)0x01 <<pinpos)){
                          GPIOA->CRH &= ~(0xF << (pinpos*4));
                          GPIOA->CRH |= tmpVal << (pinpos*4);
                  }
          }
  }
}//GPIOA_OutPut_Init


void GPIOC_Output_Init(uint16_t  pinNum, GPIOSpeed_TypeDef speedValE, GPIOMode_Output_TypeDef modeE) {
  uint32_t  tmpVal=modeE << 2 | speedValE;
  uint32_t  pinpos=0x00;
  
  //pin #0 ~ #7
  if((pinNum & 0xFF) !=0){
          for(pinpos = 0x00; pinpos <0x08; pinpos++) {
                  if(pinNum &((uint32_t)0x01 << pinpos)){
                          GPIOC->CRL &= ~(0xF << (pinpos*4));
                          GPIOC->CRL |= tmpVal << (pinpos*4);
                  }
          }
  }else{
          pinNum=pinNum >>8;
          for(pinpos = 0x00; pinpos <0x08; pinpos++){
                           if(pinNum==((uint32_t)0x01 <<pinpos)){
                          GPIOC->CRH &= ~(0xF << (pinpos*4));
                          GPIOC->CRH |= tmpVal << (pinpos*4);
                  }
          }
  }
}//GPIOC_OutPut_Init

void  LED_On(uint16_t ledPin) {
		GPIO_LED->BSRR |= ledPin;
}//LED ON

void  LED_Off(uint16_t ledPin) {
		 GPIO_LED->BRR |= ledPin;
}//LED OFF

void  LED_All_On(void) {
  GPIO_LED->BSRR |= 0xff;
}

void GPIOA_ALL_OFF(void)
{
  GPIOA->BRR |= 0xff;
}

int main(void)
{
  int i=0;
  
  unsigned char FND_DATA_TBL[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,
                                  0x6D, 0x7D, 0x27, 0x7F, 0x6F,
                                  0x77, 0x7C, 0x39, 0x5E, 0x79,
                                  0x71};

  
  
  RCC_APB2ENR |= RCC_APB2Periph_GPIOA;
  RCC_APB2ENR |= RCC_APB2Periph_GPIOC;
  
  
  
  GPIOA_Output_Init(GPIO_LED0_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOA_Output_Init(GPIO_LED1_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOA_Output_Init(GPIO_LED2_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOA_Output_Init(GPIO_LED3_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOA_Output_Init(GPIO_LED4_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOA_Output_Init(GPIO_LED5_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOA_Output_Init(GPIO_LED6_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOA_Output_Init(GPIO_LED7_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP); 
  
  
  
  GPIOC_Output_Init(GPIO_LED0_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOC_Output_Init(GPIO_LED1_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOC_Output_Init(GPIO_LED2_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOC_Output_Init(GPIO_LED3_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOC_Output_Init(GPIO_LED4_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOC_Output_Init(GPIO_LED5_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOC_Output_Init(GPIO_LED6_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOC_Output_Init(GPIO_LED7_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP); 
 
  
  
  while (1)  {
    
    i=0;
    while(i<7){
      LED_On(0x01<<i);
      delay(0xAFFFF);
      LED_Off(0x01<<i);
      i++;
    }
    while(i>=0){
      LED_On(0x01<<i);
      delay(0xAFFFF);
      LED_Off(0x01<<i);
      i--;
    }
    
    
    //GPIOC->BSRR=0x07; 
    
    LED_All_On();
    
    LED_Off(GPIO_LED0_PIN);
    GPIOA->BSRR = FND_DATA_TBL[1];
    delay(delay_time);
    GPIOA_ALL_OFF();
    LED_All_On();
    
    LED_Off(GPIO_LED1_PIN);
    GPIOA->BSRR = FND_DATA_TBL[2];
    delay(delay_time);
    GPIOA_ALL_OFF();
    LED_All_On();
    
    LED_Off(GPIO_LED2_PIN);
    GPIOA->BSRR = FND_DATA_TBL[3];
    delay(delay_time);
    GPIOA_ALL_OFF();
    LED_All_On();
    
    LED_Off(GPIO_LED3_PIN);
    GPIOA->BSRR = FND_DATA_TBL[4];
    delay(delay_time);   
    GPIOA_ALL_OFF();
    
  }
  
}//end main

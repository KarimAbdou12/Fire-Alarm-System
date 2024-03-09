


#ifndef LED_INT_H_
#define LED_INT_H_

typedef enum{
	LED_YELLOW,
	LED_RED
}LED_Selec_t;

void Led_Status (LED_Selec_t led,status_t status);
void BUZZER_Status (status_t status);



#endif /* LED_INT_H_ */
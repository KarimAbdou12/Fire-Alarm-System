

#ifndef LED_CFG_H_
#define LED_CFG_H_

#define YELLOW  PINC4
#define RED     PINC5
#define BUZZER_CH  PINC6

#define max_num_led 2


#ifdef LED_PROG

const LED_Selec_t Led_arr[max_num_led]={YELLOW,RED};

#endif


#endif /* LED_CFG_H_ */
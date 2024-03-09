/*
 * DIO_Priv.h
 *
 * Created: 2/23/2024 9:01:36 PM
 *  Author: Magic
 */ 


#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_


extern const DIO_PinStatus_t DIO_PinsStatusArray[TOTAL_PINS];

static void DIO_InitPin(DIO_Pin_t pin, DIO_PinStatus_t status);



#endif /* DIO_PRIV_H_ */


#ifndef SENSOR_INT_H_
#define SENSOR_INT_H_


u16 TEMP_Read(void);
u8 POT_Read(void);
u16 Pressure_Read(void);
void pressur_Runnable (void);
u16 SMOKE_READ (void);

#define SMOKE_SENSOR CH_7

#endif /* SENSOR_INT_H_ */
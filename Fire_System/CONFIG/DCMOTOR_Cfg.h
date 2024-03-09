


#ifndef DCMOTOR_CFG_H_
#define DCMOTOR_CFG_H_


#define M1_IN1 PINC0
#define M1_IN2 PINC1

#define M2_IN1 PINC2
#define M2_IN2 PINC3

#define M3_IN1 PINA0
#define M3_IN2 PINA1

#define M4_IN1 PINA2
#define M4_IN2 PINA3

#define M5_IN1 PINC0
#define M5_IN2 PINC1

#define M6_IN1 PINC0
#define M6_IN2 PINC1

/* the largest number of motors is 6 */
#define NUM_OF_MOTORS 2

extern const MOTOR_t MOTOR_Array[NUM_OF_MOTORS][2];



#endif /* DCMOTOR_CFG_H_ */
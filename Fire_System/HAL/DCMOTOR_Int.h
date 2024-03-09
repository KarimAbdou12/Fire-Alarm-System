

#ifndef DCMOTOR_INT_H_
#define DCMOTOR_INT_H_


typedef enum {
	M1,
	M2,
	M3,
	M4,
	M5,
	M6,
	M7,
	M8,
	M9,
	M10
}MOTOR_t;

void MOTOR_Stop (MOTOR_t motor); // task ( optimize )

void MOTOR_CW (MOTOR_t motor);

void MOTOR_CCW (MOTOR_t motor);

/* speed 0:100 */
void MOTOR_Speed (MOTOR_t motor,u8 speed);





#endif /* DCMOTOR_INT_H_ */
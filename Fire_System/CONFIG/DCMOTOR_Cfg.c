
#include "StdTypes.h"
#include "DIO_Int.h"
#include "DCMOTOR_Int.h"
#include "DCMOTOR_Cfg.h"

/* modify num_of_motors from "motor_conf.h"
the largest number of motors is 6 */

const MOTOR_t MOTOR_Array[NUM_OF_MOTORS][2]={ {M1_IN1,M1_IN2},
{M2_IN1,M2_IN2},
{M3_IN1,M3_IN2},
{M4_IN1,M4_IN2},
{M5_IN1,M5_IN2},
{M6_IN1,M6_IN2}};




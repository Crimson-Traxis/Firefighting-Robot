//======================================================================
//======================================================================
//==    T R I N I T Y    F I R E     F I G H T I N G    R O B O T     ==
//==						   2 0 0 7						  	      ==
//==														 		  ==
//==	Project Members: Kevin Smith, Denny Esterline, 				  ==	
//==					 Kayla Kibbey, and Vaughn Lietzke			  ==															
//==																  ==
//==	Project Advisor: Dr. Russell Clark							  ==
//======================================================================
//======================================================================
//
// File: Debug.h
//
// Purpose: This file contains debugging routines for the robot. 
// 			This file is NOT complied when debugging is off.
//
////////////////////////////////////////////////////////////////////////

//Display Functions
void equalHeader(char NumTimes);
void equalHeaderTabNR(char NumTimes);
void equalHeaderTab(char NumTimes);
void equalHeaderNR(char NumTimes);
void Space(char NumTimes);
void Return(char NumTimes);
void Tab(char NumTimes);
void CommonMessages(char Message);
void DashHeader(char Num);
void NumOptionNR(char Num);



//Menu Options
void DEBUG_START(void);
void DEBUG_TITLE(void);
char DEBUG_MAIN_MENU(void);

char DEBUG_SENSOR_MENU(void);
char DEBUG_SENSOR_SUBMENU(void);
void DEBUG_IR_SENSOR(void);
void DEBUG_SONAR_SENSOR(void);
void DEBUG_UV_SENSOR(void);
void DEBUG_THERMAL_SENSOR(void);
void DEBUG_WHITELINE_SENSOR(void);
void DEBUG_SOUNDSTART_SENSOR(void);

char DEBUG_MOTOR_MENU(void);
char DEBUG_MOTOR_SUBMENU(void);
void DEBUG_MOTORS(void);
void DEBUG_ENCODER_MOTOR(void);
void DEBUG_PID_MOTOR(void);

char DEBUG_SERVO_MENU(void);
char DEBUG_SERVO_SUBMENU(void);

void DEBUG_TURRET_SERVO(void);
void DEBUG_THERMAL_SERVO(void);
void DEBUG_CO2_SERVO(void);


void OPERATING_MODE(void);


///////////////////////////////////////////////////////////////////////////
// DEBUG START
void DEBUG_START(void)
{
	IEC0bits.U1RXIE = 1;		//Enable UART Interrupts
	char Selection = 0;
	DEBUG_TITLE();

	do
	{
		Selection = DEBUG_MAIN_MENU();
		switch (Selection)
		{
			case '1': 
			{
				DEBUG_SENSOR_SUBMENU();
			}
			break;
			case '2': 
			{
				DEBUG_MOTOR_SUBMENU();
			}
			break;
			case '3': 
			{
				DEBUG_SERVO_SUBMENU();
			}
			break;
			case '4': 
			{
				//OPERATING_MODE();
			}
			break;
			case '5': 
			{
				//Nothing. Quit to main menu
			}
			break;
		}
	} 
	while (Selection != '5');

	Return(2);
	printf("Restart processor to return debugging menu");
	Return(1);
	printf("To disable this menu, recomplite with DEBUG = 0");

	while(1);	//Hold the processor until restart

}



///////////////////////////////////////////////////////////////////////////
// TITLE
void DEBUG_TITLE(void)
{
	Return(2);
	equalHeaderTab(44);
		   
	Tab(1);
	Space(5);
	printf("--  TRINITY FIREFIGHTING ROBOT --");
	Return(1);
	Tab(1);
	Space(12);
	printf("--  2   0   0   7 --");
	Return(2);
	printf("\t Team: Kevin Smith, Denney Esterline,");
	Return(1);
	Tab(1);
	Space(7);
	printf("Vaughn Lietzke, Kayla Kibbey");
	Return(2);
	printf("\t Advisor: Dr. Russell Clark");
	Return(1);
	equalHeaderTab(44);
	Return(2);
}

///////////////////////////////////////////////////////////////////////////
// Main Menu
char DEBUG_MAIN_MENU(void)
{
	char Selection = 0;
	UART_INPUT = 0;

	do
	{
		printf("Main Menu");
		Return(1);
		DashHeader(19);
		Return(1);
		NumOptionNR(1);
		printf("Sensor Debugging");
		Return(1);
		NumOptionNR(2);
		printf("Motor Debugging");
		Return(1);
		NumOptionNR(3);
		printf("Servo Debugging");
		Return(1);
		NumOptionNR(4);
		printf("Operating Mode");
		Return(1);
		NumOptionNR(5);
		printf("Quit");
		Return(2);
		CommonMessages(1);
		while((Selection > '5') || (Selection < '1'))
		{
			Selection = UART_INPUT;
		}
		Return(1);

	}
	while ( (Selection < '1') || (Selection > '5') );

	return Selection;

}

///////////////////////////////////////////////////////////////////////////
// Sensor Sub Menu
char DEBUG_SENSOR_SUBMENU(void)
{
	char Selection = 0;
	do
	{
		Selection = DEBUG_SENSOR_MENU();
		switch (Selection)
		{
			case '1': 
			{
				DEBUG_IR_SENSOR();
			}
			break;
			case '2': 
			{
				DEBUG_SONAR_SENSOR();
			}
			break;
			case '3': 
			{
				DEBUG_UV_SENSOR();
			}
			break;
			case '4': 
			{
				DEBUG_THERMAL_SENSOR();
			}
			break;
			case '5': 
			{
				DEBUG_WHITELINE_SENSOR();
			}
			break;
			case '6': 
			{
				DEBUG_SOUNDSTART_SENSOR();
			}
			break;
			case '7': 
			{
				
			}
			break;
		}
	} 
	while (Selection != '7');
	 
	return 0;
}

///////////////////////////////////////////////////////////////////////////
// Sensor Menu
char DEBUG_SENSOR_MENU(void)
{
	char Selection = 0;
	UART_INPUT = 0;
	Return(2);
	do
	{
		printf("Sensor Menu");
		Return(1);
		DashHeader(19);
		Return(1);
		NumOptionNR(1);
		printf("IR Sensors");
		Return(1);
		NumOptionNR(2);
		printf("Sonar Sensors");
		Return(1);
		NumOptionNR(3);
		printf("UVTRON");
		Return(1);
		NumOptionNR(4);
		printf("Thermal Array");
		Return(1);
		NumOptionNR(5);
		printf("White Line");
		Return(1);
		NumOptionNR(6);
		printf("Sound Start");
		Return(1);
		NumOptionNR(7);
		printf("Return");
		Return(2);
		
		CommonMessages(1);
		while((Selection > '7') || (Selection < '1'))
		{
			Selection = UART_INPUT;
		}
		Return(1);
	
	}
	while ((Selection > '7') || (Selection < '1'));

	return Selection;

}

void DEBUG_IR_SENSOR(void)
{
	char Selection = 0;
	UART_INPUT = 0;
	
	CommonMessages(0);
	while ((UART_INPUT != '1') && (UART_INPUT != 'Q') && (UART_INPUT != 'q'));

	if(UART_INPUT == '1')
	{
		float t1 = 0.0,t2 =0.0;
		Return(2);
		do 
		{
			if(DEBUG_ADRead == 1)
			{
				t1 = lr_Reading2Distance(AVG_IR_LR_FRONT);
				t2 = sr_Reading2Distance(AVG_IR_SR_FRONT);
				printf("Test: %f|%f\r\n",t1,t2);
				printf("Turret-> LR: %u | SR: %u",AVG_IR_LR_TURRET,AVG_IR_SR_TURRET);
				Return(1);
				printf("Front-> LR: %u | SR: %u",AVG_IR_LR_FRONT,AVG_IR_SR_FRONT);
				Return(1);
				printf("Rear-> LR: %u",AVG_IR_LR_REAR);
				DEBUG_ADRead = 0;
				Return(2);

			}
			
		} while(UART_INPUT != 'Q' && UART_INPUT != 'q');
	}
	
	return;
}

void DEBUG_SONAR_SENSOR(void)
{
	char Selection = 0;
	UART_INPUT = 0;
	
	CommonMessages(0);
	while ((UART_INPUT != '1') && (UART_INPUT != 'Q') && (UART_INPUT != 'q'));

	if(UART_INPUT == '1')
	{
		Return(2);
		//int TurretSonar = 0, FrontSonar = 0, RearSonar = 0;

		do 
		{
			//TurretSonar = SonarRead(1);			
			printf("Turret: %u", SONAR_TURRET);
			Return(1);
			//FrontSonar = SonarRead(2);			
			printf("Front: %u", SONAR_FRONT);
			Return(1);
			//RearSonar = SonarRead(3);			
			printf("Rear: %u", SONAR_REAR);
			DelayNmSec(200);
			Return(2);
		} while(UART_INPUT != 'Q' && UART_INPUT != 'q');
	}
	
	return;
}

void DEBUG_UV_SENSOR(void)
{
	int i = 0;
	char Selection = 0;
	UART_INPUT = 0;
	
	printf("This timer is based off of Timer 5.");
	Return(1);

	switch(T5CONbits.TCKPS)
	{
		case 0:
			printf("This timer has a prescaller of 1");
		break;	
		case 1:
			printf("This timer has a prescaller of 8");
		break;
		case 2:
			printf("This timer has a prescaller of 64");
		break;
		case 3:
			printf("This timer has a prescaller of 256");
		break;
	};
	Return(2);
	CommonMessages(0);
	while ((UART_INPUT != '1') && (UART_INPUT != 'Q') && (UART_INPUT != 'q'));

	if(UART_INPUT == '1')
	{
		Return(2);
		printf("Reading UVTRON...\r\n");
		do 
		{
			UVCheck();
			printf("Result: %u",UV_ROOM_FOUND);
			Return(1);
		} while(UART_INPUT != 'Q' && UART_INPUT != 'q');
	}

	return;
}

void DEBUG_THERMAL_SENSOR(void)
{
	int i = 0;
	char Selection = 0;
	UART_INPUT = 0;
	
	CommonMessages(0);
	while ((UART_INPUT != '1') && (UART_INPUT != 'Q') && (UART_INPUT != 'q'));

	if(UART_INPUT == '1')
	{
		Return(2);
		//int TurretSonar = 0, FrontSonar = 0, RearSonar = 0;

		do 
		{
			printf("Reading Thermal Array from I2C bus\r\n");
			for(i = 1; i < 10; i++)
			{
				TESTREAD0 = I2CReadWord(0xD0,i);
				printf("\tR%u-> %u\r\n",i,TESTREAD0);
			}
			Return(2);
			DelayNmSec(500);
		} while(UART_INPUT != 'Q' && UART_INPUT != 'q');
	}
	
	return;
}

void DEBUG_WHITELINE_SENSOR(void)
{
	int i = 0;
	char Selection = 0;
	UART_INPUT = 0;
	
	CommonMessages(0);
	while ((UART_INPUT != '1') && (UART_INPUT != 'Q') && (UART_INPUT != 'q'));

	if(UART_INPUT == '1')
	{
		WHITELINE_DEBUG = 1;
		do 
		{
			WhiteLineCheck();
			DelayNmSec(100);
		} while(UART_INPUT != 'Q' && UART_INPUT != 'q');
		WHITELINE_DEBUG = 0;
	}
	return;
}

void DEBUG_SOUNDSTART_SENSOR(void)
{
	return;
}


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
// Motor Sub Menu
char DEBUG_MOTOR_SUBMENU(void)
{
	char Selection = 0;
	do
	{
		Selection = DEBUG_MOTOR_MENU();
		switch (Selection)
		{
			case '1': 
			{
				DEBUG_MOTORS();
			}
			break;
			case '2': 
			{
				DEBUG_ENCODER_MOTOR();
			}
			break;
			case '3': 
			{
				DEBUG_PID_MOTOR();
			}
			break;
			case '4': 
			{
								
			}
			break;
		}
	} 
	while (Selection != '4');
	 
	return 0;
}

///////////////////////////////////////////////////////////////////////////
// Motor Menu
char DEBUG_MOTOR_MENU(void)
{
	char Selection = 0;
	UART_INPUT = 0;
	Return(2);
	do
	{
		printf("Motor Menu");
		Return(1);
		DashHeader(19);
		Return(1);
		NumOptionNR(1);
		printf("Motor Test");
		Return(1);
		NumOptionNR(2);
		printf("Encoder Reading");
		Return(1);
		NumOptionNR(3);
		printf("PID Control Testing");
		Return(1);
		NumOptionNR(4);
		printf("Return");
		Return(2);
		
		CommonMessages(1);
		while((Selection > '4') || (Selection < '1'))
		{
			Selection = UART_INPUT;
		}
		Return(1);
	
	}
	while ((Selection > '4') || (Selection < '1'));

	return Selection;

}


void DEBUG_MOTORS(void)
{
	return;
}

void DEBUG_ENCODER_MOTOR(void)
{
	char Selection = 0;
	UART_INPUT = 0;
	
	CommonMessages(0);
	while ((UART_INPUT != '1') && (UART_INPUT != 'Q') && (UART_INPUT != 'q'));

	if(UART_INPUT == '1')
	{
		Return(2);
		do 
		{
			printf("QEI:  %u", POSCNT);
			Return(1);
			printf("QEIS: %u", QEIS_COUNTER);
			DelayNmSec(250);
			Return(2);
		} while(UART_INPUT != 'Q' && UART_INPUT != 'q');
	}
	
	return;
}

void DEBUG_PID_MOTOR(void)
{
	return;
}


///////////////////////////////////////////////////////////////////////////
// Servo Sub Menu
char DEBUG_SERVO_SUBMENU(void)
{
	char Selection = 0;
	do
	{
		Selection = DEBUG_SERVO_MENU();
		switch (Selection)
		{
			case '1': 
			{
				DEBUG_TURRET_SERVO();
			}
			break;
			case '2': 
			{
				DEBUG_THERMAL_SERVO();
			}
			break;
			case '3': 
			{
				DEBUG_CO2_SERVO();
			}
			break;
			case '4': 
			{
								
			}
			break;
		}
	} 
	while (Selection != '4');
	 
	return 0;
}

///////////////////////////////////////////////////////////////////////////
// Motor Menu
char DEBUG_SERVO_MENU(void)
{
	char Selection = 0;
	UART_INPUT = 0;
	Return(2);
	do
	{
		printf("Servo Menu");
		Return(1);
		DashHeader(19);
		Return(1);
		NumOptionNR(1);
		printf("Turret Angle");
		Return(1);
		NumOptionNR(2);
		printf("Thermal Tilt");
		Return(1);
		NumOptionNR(3);
		printf("CO2 Position");
		Return(1);
		NumOptionNR(4);
		printf("Return");
		Return(2);
		
		CommonMessages(1);
		while((Selection > '4') || (Selection < '1'))
		{
			Selection = UART_INPUT;
		}
		Return(1);
	
	}
	while ((Selection > '4') || (Selection < '1'));

	return Selection;

}

void DEBUG_TURRET_SERVO(void)
{
	char Selection = 0;
	UART_INPUT = 0;
	
	CommonMessages(0);
	while ((UART_INPUT != '1') && (UART_INPUT != 'Q') && (UART_INPUT != 'q'));

	if(UART_INPUT == '1')
	{
		int i = 0;
		Return(2);
		printf("Please enter 1 to increase turrent position and 2 to decrease:");	
		Return(1);
		UART_INPUT = 0;
		do 
		{
			if(UART_INPUT == '1')
			{
				SERVO_TURRET_POS += 25;
				CommonMessages(2);
				for(i = 0; i < strlen(SERVO_DEBUG_DIR_RIGHT); i++)
				{
					printf("%c", SERVO_DEBUG_DIR_RIGHT[i]);
				}
				printf(" | %u", SERVO_TURRET_POS);
				Return(1);
				UART_INPUT = 0;
			}
			else if(UART_INPUT == '2')
			{
				SERVO_TURRET_POS -= 25;
				CommonMessages(2);
				for(i = 0; i < strlen(SERVO_DEBUG_DIR_LEFT); i++)
				{
					printf("%c", SERVO_DEBUG_DIR_LEFT[i]);
				}
				printf(" | %u", SERVO_TURRET_POS);
				Return(1);
				UART_INPUT = 0;
			}

		} while(UART_INPUT != 'Q' && UART_INPUT != 'q');
	}
	
	return;
}

void DEBUG_THERMAL_SERVO(void)
{
	char i=0;
	char Selection = 0;
	UART_INPUT = 0;
	
	CommonMessages(0);
	while ((UART_INPUT != '1') && (UART_INPUT != 'Q') && (UART_INPUT != 'q'));

	if(UART_INPUT == '1')
	{
		int i = 0;
		Return(2);
		printf("Please enter 1 to tilt sensor up and 2 to tilt down:");	
		Return(1);
		
		do 
		{
			if(UART_INPUT == '1')
			{
				/*if(i <= 30)
				{
					i++;
					I2CWriteWord(THERMAL_ADDRESS,0,i);
					printf("Position %u sent ",i);
					Return(1);
					DelayNmSec(100);
				}
				else
				{
					printf("Position at upper max");
					Return(1);
				}*/
				I2CWriteWord(THERMAL_ADDRESS,0,30);
				UART_INPUT = 0;	//Clear input
			}
			else if(UART_INPUT == '2')
			{
				/*
				if(i > 0)
				{
					i--;
					I2CWriteWord(THERMAL_ADDRESS,0,i);
					printf("Position %u sent ",i);
					Return(1);
					DelayNmSec(100);
				}
				else
				{
					printf("Position at lower max");
					Return(1);
				}*/
				I2CWriteWord(THERMAL_ADDRESS,0,1);
				UART_INPUT = 0;	//Clear input
			}
		} while(UART_INPUT != 'Q' && UART_INPUT != 'q');
	}

	return;
}
void DEBUG_CO2_SERVO(void)
{
	
	char Selection = 0;
	UART_INPUT = 0;
	
	printf("WARNING: Please remove Co2 before testing this function!");
	Return(1);
	CommonMessages(0);
	while ((UART_INPUT != '1') && (UART_INPUT != 'Q') && (UART_INPUT != 'q'));

	if(UART_INPUT == '1')
	{
		int i = 0;
		Return(2);
		printf("Please enter 1 to increase turrent position and 2 to decrease:");	
		Return(1);
		UART_INPUT = 0;
		do 
		{
			if(UART_INPUT == '1')
			{
				SERVO_CO2_POS += 25;
				CommonMessages(2);
				for(i = 0; i < strlen(SERVO_DEBUG_DIR_LEFT); i++)
				{
					printf("%c", SERVO_DEBUG_DIR_LEFT[i]);
				}
				printf(" | %u", SERVO_CO2_POS);
				Return(1);
				UART_INPUT = 0;
			}
			else if(UART_INPUT == '2')
			{
				SERVO_CO2_POS -= 25;
				CommonMessages(2);
				for(i = 0; i < strlen(SERVO_DEBUG_DIR_RIGHT); i++)
				{
					printf("%c", SERVO_DEBUG_DIR_RIGHT[i]);
				}
				printf(" | %u", SERVO_CO2_POS);
				Return(1);
				UART_INPUT = 0;
			}
		} while(UART_INPUT != 'Q' && UART_INPUT != 'q');
	}
	
	return;
}
		










////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
//
//Display Functions
void CommonMessages(char Message)
{
	switch(Message)
	{
		case 0:
			printf("Press 1 to start, Press Q to quit");
		break;
		case 1:
			printf("Enter Choice:");
		break;
		case 2:
			printf("-Turning pod to the ");
		break;
	};

	return;
		
}

void DashHeader(char Num)
{
	int i;
	for (i = 0; i < Num; i++)
	{
		printf("-");
	}
	
	Return(1);
	
	return;
}

void NumOptionNR(char Num)
{
	printf("%u. ",Num);
	
	return;
}	


void equalHeader(char NumTimes)
{
	int i;
	for (i = 0; i < NumTimes; i++)
	{
		printf("=");
	}
	printf("\r\n");

	return;
}
void equalHeaderTabNR(char NumTimes)
{
	int i;
	printf("\t");
	for (i = 0; i < NumTimes; i++)
	{
		printf("=");
	}

	return;
}
void equalHeaderTab(char NumTimes)
{
	int i;
	printf("\t");
	for (i = 0; i < NumTimes; i++)
	{
		printf("=");
	}
	printf("\r\n");

	return;
}
void equalHeaderNR(char NumTimes)
{
	int i;
	for (i = 0; i < NumTimes; i++)
	{
		printf("=");
	}

	return;
}
void Space(char NumTimes)
{
	int i;
	for (i = 0; i < NumTimes; i++)
	{
		printf(" ");
	}

	return;
}
void Return(char NumTimes)
{
	int i;
	for (i =0; i < NumTimes; i++)
	{
		printf("\r\n");
	}
}	
void Tab(char NumTimes)
{
	int i;
	for (i =0; i < NumTimes; i++)
	{
		printf("\t");
	}
}	




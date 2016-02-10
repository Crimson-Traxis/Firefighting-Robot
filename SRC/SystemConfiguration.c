//======================================================================
// System Configuration
//======================================================================
//
////////////////////////////////////////////////////////////////////////////
// Clock Cycle Frequency and Baud Rate Contstants
#define Fcy   29480000				//Used for internal OSC
#define baud 115200					//Used for Inernal OSC
#define BRGH  (((Fcy/baud)/16)-1)	
#define MILLISEC Fcy/10000			// 1 mSec delay constant
//#define CountDistance 1200/(3.95*3.1416)  //1200 counts/(4in dia.*pi)
//#define TurnCountPerDegree 5.590717

////////////////////////////////////////////////////////////////////////
//Custom Typedef Structures
typedef unsigned char bit;             // 1 Bit 
typedef unsigned char nib;             // 4 Bit unsigned integer
typedef unsigned char byte;            // 8 Bit unsigned integer
typedef unsigned int word;             // 16 Bit unsigned integer
typedef unsigned long longword;        // 32 Bit unsigned integer
typedef byte HexByte_T[3];             // Hex byte string type range (00..FF)
typedef byte HexWord_T[5];             // Hex word string type range (0000..FFFF)
typedef byte HexLongWord_T[9];         // Hex word string type range (00000000..FFFFFFFF)   






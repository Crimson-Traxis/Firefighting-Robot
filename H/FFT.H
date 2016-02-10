/* Constant Definitions */
#define FFT_BLOCK_LENGTH	256     /* = Number of frequency points in the FFT */
#define LOG2_BLOCK_LENGTH 	8		/* = Number of "Butterfly" Stages in FFT processing */
#define SAMPLING_RATE		51181	/* = Rate at which input signal was sampled */
                                        /* SAMPLING_RATE is used to calculate the frequency*/
                                        /* of the largest element in the FFT output vector*/

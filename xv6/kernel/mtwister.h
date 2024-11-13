 /* The following code is added directly from the github 
references are given below
*/ 
 /*Removed stdint.h, used xv6 unsigned int instead*/


/* An implementation of the MT19937 Algorithm for the Mersenne Twister
 * by Evan Sultanik.  Based upon the pseudocode in: M. Matsumoto and
 * T. Nishimura, "Mersenne Twister: A 623-dimensionally
 * equidistributed uniform pseudorandom number generator," ACM
 * Transactions on Modeling and Computer Simulation Vol. 8, No. 1,
 * January pp.3-30 1998.
 *
 * http://www.sultanik.com/Mersenne_twister
 */

 
#ifndef MTWISTER_H
#define MTWISTER_H
 
#include "types.h"
 
/* Function declarations */
void init_genrand(uint seed);
uint genrand_int32(void);
uint genRandLong(uint max);
 
#endif
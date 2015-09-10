/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  /*
   * Nor operation is logically equivalent to
   * (~x) & (~y). It derived easily from easy boolean algebra.
   * ~(x|y) = (~x) & (~y) by De Morgan's Law
   */
  
  return (~x) & (~y);
}

/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  /*
   * LSB is x&1. since x is binary code,
   * x & 1 is 1 or 0, so bitwise negation of 
   * x&1 becomes 0xffffffff if x & is 0,
   * else 0xfffffffe. Finally add 1 becomes 
   * desired result
   */

  return (~(x&1))+1;
}

/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  /* 
   * x^y is 0 if all bits are same.
   * So not operation of x^y becomes 1 only 
   * x and y are same
   */

  return !(x^y);
}

/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
  /*
   */ 
  
  return (~((~0 << highbit) << 1)) & (~0 << lowbit);
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  /*
   */
  int mask = 0x01;
  int count = 0;
  mask = mask | (mask << 8);
  mask = mask | (mask << 16);
  count += (x & mask);
  count += ((x >> 1) & mask);
  count += ((x >> 2) & mask);
  count += ((x >> 3) & mask);
  count += ((x >> 4) & mask);
  count += ((x >> 5) & mask);
  count += ((x >> 6) & mask);
  count += ((x >> 7) & mask);

  return (count & 0xff) + ((count >> 8) & 0xff) + ((count >> 16) & 0xff) + ((count >> 24) & 0xff);
}

/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  /* 
   * Maximum number of 2's complement integer is 
   * equal to maximum positive number.
   * So except most significant bit, all bits should be 1.
   * And it is equivalent to negation of (0x80000000).
   * 1 << 0x1f becomes 0x80000000, and than negation becomes
   * maximum number
   */ 

  return ~(1 << 0x1f);
}

/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  /* 
   * In 2's complement, negative number's
   * most significant bit is 1, and 0 for non-negative integers
   * So we just check for MSB for x is enough
   * if we shift 31bits, result becomes 0 if x is non negative,
   * 0xffffffff for negative integers. 
   * Finally negation of shifted reult is what we disired
   */

  return !(x >> 0x1f);
}

/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  /* 
   * Overflow occures when adding two positive numbers
   * become negative number and similarily adding two
   * negative numbers become positive number. So we can check 
   * over flow via most significant bit of two oprands.
   * In digital logic overflows is detected by follwing equations
   * (!MSB_x & !MSB_y & MSB_xy) | (MSB_x & MSB_Y & !MSB_xy)
   *  - Overflow is occur when the MSB of result is different from two oprands,
   *  and we do not concern about different sign.
   * So negation of above result is disired value
   */
  int MSB_x = !(x >> 0x1f);
  int MSB_y = !(y >> 0x1f);
  int MSB_xy = !((x + y) >> 0x1f);

  return !((!MSB_x & !MSB_y & MSB_xy) | (MSB_x & MSB_y & !MSB_xy));
}

/* 
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int rempwr2(int x, int n) {
  /*
   * divisor mask is 2^n -1. So and operation is positive remainder.
   * When x is negative we subtract 2^n for desired value.
   * x >> 0x1f is 0 if x is non-negative, 1 else. 
   * But if x is divided by 2^n, we do not subtract 2^n, 
   * so we need additional variable is_divided;
   *  if x is divided it result 0(divided), else 0xffffffff(not divided).
   * We can subtract 2^n if x is negative and x is not_divided.
   * So (x >> 0x1f) & is_divided gives whether subtract or not.
   * ((~(1 << n) + 1) is equivalent to -2^n.
   * So(( x>> 0x1f) & is_divided) & ((~(1 << n)) +1 ) subtract 2^n if x is 
   * negative and not divided. So positive x does not affected by above term
   * and it becomes desired result. 
   */
  int divisor_mask = ~(~0 << n);
  int is_divided = (!!(x & divisor_mask) << 0x1f) >> 0x1f;

  return (x & divisor_mask) + (((x >> 0x1f) & is_divided) & ((~(1 << n)) + 1));
}

/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
  /* 
   * We can solve this problem dividing into two cases.
   * First, sign of x and y is same.
   * In this case, we perform subtraction(x - y = x + (~y + 1))
   * and check it is negative. Above logic is 
   * (!(sign_x ^ sign_y)) & !sign_xy. (sign is 1 if x is non-negative.)
   * The other case, sign is different. In this case, if y is positive and
   * x is negative is desired. So check sign_x and sign_y is different 
   * using xor operation. and check sign_y is non-negative.
   * This is equivalent to ((sign_x ^ sign_y) & sign_y) 
   */
  int sign_x = !(x >> 0x1f);
  int sign_y = !(y >> 0x1f);
  int sign_xy = !((x + (~y) + 1) >> 0x1f);

  return ((!(sign_x ^ sign_y)) & !sign_xy) | ((sign_x ^ sign_y) & sign_y);
}

/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  /*
   * Description of each terms
   * (x >> 0x1f) : 0x00000000 if x is non-negative, 
   * else 0xffffffff.
   * x ^ (x >> 0x1f) : if x is non-negative, result of this term is x.
   * Otherwise, x's bits are fliped.
   * (x >> 0x1f) & 0x01 : if x is non-
   */

  return (x ^ (x >> 0x1f)) + ((x >> 0x1f) & 0x01) ;
}

/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
  /* 
   * Description of each term
   * !!x : determines x is zero or not (because isPower2(0) is 0
   * !x & (x + (~1) + 1) : determine wheter x is power of 2 or not 
   * regardless of its sign. This is work because if x is power of 2,
   * it contains only one '1' so x-1 becomes all 1s except x's 1's location
   * so only power of 2 becomes 0x00000000. (~1) + 1 means -1
   * !(x >> 0x1f) : determine whether x is non-negative.
   * so it returns and(&) operations of above three terms
   * isPower2 is true only x is non-zero and power of 2 and non-negative 
   */

  return (!!x) & (!(x & (x + (~1) +1))) & (!(x >> 0x1f));
}

/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {

	return 2;

}

/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {

  return 2;

}

/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {

  return 2;

}





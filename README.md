# Ternary CWCs with weight four and distance six of short length in l1-metric

In this file, we list all base codewords for short lengths of (n, 6, 4)_3 codes. We also give a simple code to verify the correctness of the given codewords. You can downlode the rar file or goto the specific branches.

Here is an example to illustrate how to adjust the corresponding parameters:

#define bsize 5 //The number of base codewords.

#define opsize 25 //The number of codewords.

#define vector_m 15 //The length of code.

int cycle[vector_m] = {
	3,4,5,6,7,8,9,10,11,12,13,14,0,1,2
}; //Group action or automorphism cycle[i].

FILE *f = fopen ("15check.txt","r");//File path.

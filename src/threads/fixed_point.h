#include <stdint.h>

#define F 16
/*Shawn is dumb and didn't capitalize all of his F's */
//Declarations
//Convert n to fixed point:
int __toFixed(int n);

//Convert x to integer (rounding toward zero):
int __toInt_Zero(int x);

//Convert x to integer (rounding to nearest):
#define __toInt_Round(x)(x >= 0 ? ((x + (1 << (F - 1))) >> F) \
                            : ((x - (1 << (F - 1))) >> F))

//Add x and n:
int __addFixedInt(int x, int n);

//Add x and y:
int __addFixedFixed(int x, int y);

//Subtract n from x:
int __subFixedInt(int x, int n);

//Subtract y from x: 
int __subFixedFixed(int x, int y);

//Multiply x by n:
int __mulFixedInt(int x, int n);

//Multiply x by y:
int __mulFixedFixed(int x, int y);

//Divide x by n:
int __divFixedInt(int x, int n);

//Divide x by y:
int __divFixedFixed(int x, int y);

//Definitions
int __toFixed(int n){

	return n << F;
}

int __toInt_Zero(int x){

	return x >> F;
}
int __addFixedFixed(int x, int y){

	return x+y;
}
int __subFixedFixed(int x, int y){

	return x-y;
}
int __addFixedInt(int x, int n){

	return x+(n << F);
}
int __subFixedInt(int x, int n){

	return x-(n << F);
}
int __mulFixedFixed(int x, int y){

	return ((int64_t) x) * (y >> F);
}
int __mulFixedInt(int x, int n){

	return x*n;
}
int __divFixedFixed(int x, int y){

	return (((int64_t) x) << F) / y;
}
int __divFixedInt(int x, int n){

	return x/n;
}
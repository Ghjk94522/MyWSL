#include<stdio.h>
#include<stdint.h>

int foo(int x, int y){
	int z;
	x++; y++;
	asm(
		"addl %1, %2; "
		"movl %2, %0; "
		: "=r"(z) // output
		: "r"(x), "r"(y) // input
	);
	return z;
}

int main(){
	int x = 1, y = 2;
	int z = foo(x, y);
	printf("z is %d\n", z);
	return 0;
}

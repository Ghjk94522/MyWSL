#include<stdio.h>
#include<stdint.h>

float Q_rsqrt( float number ) {
  union { float f; uint32_t i; } conv;
  float x2 = number * 0.5F;
  conv.f = number;
  conv.i = 0x5f3759df - ( conv.i >> 1 ); // ???
  conv.f = conv.f * ( 1.5F - ( x2 * conv.f * conv.f ) );
  return conv.f;
}

int main(){
	float res = Q_rsqrt(4);
	printf("res is %f\n", res);
	return 0;
}

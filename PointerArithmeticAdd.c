#include <stdio.h>

int main()
{
	int a = 22;
	int *p = &a;
	printf("p = %u\n", p); 
	p++;
	printf("p++ = %u\n", p); //p++ = +4 bytes
	p--;
	printf("p-- = %u\n", p); 
	float b = 22.22;
	float *q = &b;
	printf("q = %u\n", q); 
	q++;
	printf("q++ = %u\n", q); //q++ = +  4 bytes
	q--;
	printf("q-- = %u\n", q); 
	char c = 'a';
	char *r = &c;
	printf("r = %u\n", r);
	r++;
	printf("r++ = %u\n", r); //r++ = +1 byte
	r--;
	printf("r-- = %u\n", r); 
	return 0;
}

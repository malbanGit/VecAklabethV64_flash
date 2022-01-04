#include <vectrex.h>

#include "aklabeth.h"
#include "globals.h"
#include "controller.h"
#include "string.h"


void printfs(const char *s1, const char *s2)
{
	_fs(s1,s2);
	printDirect(stringBuffer40);
}

void printfss(const char *s1, const char *s2, const char *s3)
{
	char *to = stringBuffer40;
	char c;
	while ( (c=*(s1++)) != '%')
	*(to++) = c;
	while ( (c=*(s2++)) != 0)
	*(to++) = c;
	while ( (c=*(s1++)) != '%')
	*(to++) = c;
	while ( (c=*(s3++)) != 0)
	*(to++) = c;
	while ( (c=*(s1++)) != 0)
	*(to++) = c;
	*to = '\x80';
	printDirect(stringBuffer40);
}


// with spaces in front
// result is zero terminated
// 8 bit unsigned
char * itoa(unsigned int n)
{
	long digit = '0'*256+'0';
	int useSpace = 0;
	
	if (n>=200) {digit+=2*256;n-=(unsigned int)200;}
	else if (n>=100) {digit+=1*256;n-=100;}
	else {digit=' '*256+'0';useSpace = 1;}
	
	
	if (n >= 80) { n -= 80; digit += 8;} else if (n >= 40) {n -= 40; digit += 4; }
	if (n >= 20) { n -= 20; digit += 2;}
	if (n >= 10) { n -= 10; digit += 1;}
	if ((digit == ' '*256+'0') && (useSpace == 1)) digit=' '*256+' ';
	*((long *) stringBuffer4+0) = digit;
	
	*(stringBuffer4+2) = '0' + n;
	*(stringBuffer4+3) = '\x00';
	return stringBuffer4;
}
char * ltoaP(unsigned long n, char *pointer)
{
	long digit = '0'*256+'0';
	int useSpace = 0;
	
	if (n >= (unsigned long int)40000) { n -= (unsigned long int)40000; digit += 4*256;}
	if (n >= (unsigned long int)20000) { n -= (unsigned long int)20000; digit += 2*256;}
	if (n >= (unsigned long int)10000) { n -= (unsigned long int)10000; digit += 1*256;}
	if (digit=='0'*256+'0') {useSpace = 1;digit=' '*256+'0';}
	
	if (n >= 8000) { n -= 8000; digit += 8;} else if (n >= 4000) {n -= 4000; digit += 4;}
	if (n >= 2000) { n -= 2000; digit += 2;}
	if (n >= 1000) { n -= 1000; digit += 1;}
	if ((useSpace==1) && (digit==' '*256+'0')) {digit=' '*256+' ';}
	*((long *) pointer+0) = digit;
	digit = '0'*256+'0';
	
	if (n >= 800) { n -= 800; digit += 8*256;} else if (n >= 400) {n -= 400; digit += 4*256;}
	if (n >= 200) { n -= 200; digit += 2*256;}
	if (n >= 100) { n -= 100; digit += 1*256;}
	if ((useSpace==1) && (digit=='0'*256+'0')) {digit=' '*256+'0';}
	
	if (n >= 80) { n -= 80; digit += 8;} else if (n >= 40) {n -= 40; digit += 4;}
	if (n >= 20) { n -= 20; digit += 2;}
	if (n >= 10) { n -= 10; digit += 1;}
	if ((useSpace==1) && (digit==' '*256+'0')) {digit=' '*256+' ';}
	*((long *) pointer+1) = digit; // +1, since we use a long pointer, thus +1 = two bytes
	
	*(pointer+4) = '0' + (char)n;
	return pointer;
}
char * ltoaPRemoveSpaces5(char *pointer)
{
	if (*(pointer+4) == ' ')  {*pointer = 0;return pointer;}
	if (*(pointer+3) == ' ')
	{
		*pointer = *(pointer+4);
		*(pointer+1) = 0;
		return pointer;
	}
	if (*(pointer+2) == ' ')
	{
		*pointer = *(pointer+3);
		*(pointer+1) = *(pointer+4);
		*(pointer+2) = 0;
		return pointer;
	}
	if (*(pointer+1) == ' ')
	{
		*pointer = *(pointer+2);
		*(pointer+1) = *(pointer+3);
		*(pointer+2) = *(pointer+4);
		*(pointer+3) = 0;
		return pointer;
	}
	if (*pointer == ' ')
	{
		*pointer = *(pointer+1);
		*(pointer+1) = *(pointer+2);
		*(pointer+2) = *(pointer+3);
		*(pointer+3) = *(pointer+4);
		*(pointer+4) = 0;
	}
	return pointer;
}

// with spaces in front
// result is zero terminated
// 16 bit unsigned
char * ltoa(unsigned long n)
{
	*(stringBuffer6+5) = '\x00';
	return ltoaP(n, stringBuffer6);
}

// fi = format int (8bit unsigned)
// max buf size
// '%' is used as placeholder
// place holder must exist!
void printfi(const char *s1, const unsigned int i)
{
	printfs(s1, itoa(i));
}

void _fsi(const char *s1, const char *s2, const unsigned int i)
{
	itoa(i);
	char *to = stringBuffer40;
	char c;
	while ( (c=*(s1++)) != '%')
	*(to++) = c;
	while ( (c=*(s2++)) != 0)
	*(to++) = c;
	while ( (c=*(s1++)) != '%')
	*(to++) = c;
	
	*(to++) = *(stringBuffer4+0);
	*(to++) = *(stringBuffer4+1);
	*(to++) = *(stringBuffer4+2);
	
	while ( (c=*(s1++)) != 0)
	*(to++) = c;
	*to = '\x80';
}

// first string, than i
void printfsi(const char *s1, const char *s2, const unsigned int i)
{
/*
	itoa(i);
	char *to = stringBuffer40;
	char c;
	while ( (c=*(s1++)) != '%')
	*(to++) = c;
	while ( (c=*(s2++)) != 0)
	*(to++) = c;
	while ( (c=*(s1++)) != '%')
	*(to++) = c;
	
	*(to++) = *(stringBuffer4+0);
	*(to++) = *(stringBuffer4+1);
	*(to++) = *(stringBuffer4+2);
	
	while ( (c=*(s1++)) != 0)
	*(to++) = c;
	*to = '\x80';
*/
    _fsi(s1, s2, i);
	printDirect(stringBuffer40);
}

// fi = format int (8bit unsigned)
// max buf size
// '%' is used as placeholder
// place holder must exist!
void printfl(const char *s1, const unsigned long i)
{
	printfs(s1, ltoa(i));
}

// first string, than i
void printfslrs(const char *s1, const char *s2, const unsigned long i)
{
	ltoa(i);
	ltoaPRemoveSpaces5(stringBuffer6);
	char *to = stringBuffer40;
	char c;
	while ( (c=*(s1++)) != '%')
	*(to++) = c;
	while ( (c=*(s2++)) != 0)
	*(to++) = c;
	while ( (c=*(s1++)) != '%')
	*(to++) = c;
	
	
	*to = *(stringBuffer6+0);
	if (*to != 0)
	{
		*(++to) = *(stringBuffer6+1);
		if (*to != 0)
		{
			*(++to) = *(stringBuffer6+2);
			if (*to != 0)
			{
				*(++to) = *(stringBuffer6+3);
				if (*to != 0)
				{
					*(++to) = *(stringBuffer6+4);
					if (*to != 0) to++;
				}
			}
		}
	}
	
	while ( (c=*(s1++)) != 0)
	*(to++) = c;
	*to = '\x80';
	printDirect(stringBuffer40);
}

// first string, than i
void printfsl(const char *s1, const char *s2, const unsigned long i)
{
	ltoa(i);
	char *to = stringBuffer40;
	char c;
	while ( (c=*(s1++)) != '%')
	*(to++) = c;
	while ( (c=*(s2++)) != 0)
	*(to++) = c;
	while ( (c=*(s1++)) != '%')
	*(to++) = c;
	
	*(to++) = *(stringBuffer6+0);
	*(to++) = *(stringBuffer6+1);
	*(to++) = *(stringBuffer6+2);
	*(to++) = *(stringBuffer6+3);
	*(to++) = *(stringBuffer6+4);
	
	while ( (c=*(s1++)) != 0)
	*(to++) = c;
	*to = '\x80';
	printDirect(stringBuffer40);
}


void printfsli(const char *s1, const char *s2, unsigned long l, unsigned int i)
{
	ltoa(l);
	itoa(i);
	char *to = stringBuffer40;
	char c;
	while ( (c=*(s1++)) != '%')
	*(to++) = c;
	while ( (c=*(s2++)) != 0)
	*(to++) = c;
	while ( (c=*(s1++)) != '%')
	*(to++) = c;
	
	*(to++) = *(stringBuffer6+0);
	*(to++) = *(stringBuffer6+1);
	*(to++) = *(stringBuffer6+2);
	*(to++) = *(stringBuffer6+3);
	*(to++) = *(stringBuffer6+4);
	
	while ( (c=*(s1++)) != '%')
	*(to++) = c;
	*(to++) = *(stringBuffer4+0);
	*(to++) = *(stringBuffer4+1);
	*(to++) = *(stringBuffer4+2);
	
	while ( (c=*(s1++)) != 0)
	*(to++) = c;
	*to = '\x80';
	printDirect(stringBuffer40);
}





void vstrcpy(char * dest, char *source)
{
	do
	{
		*(dest) = *(source++);
	} while (*(dest++) != 0);
}





void setRandSeed(unsigned int n)
{
	_x = n;
	_a = 73-n;
	_b = ((unsigned int) 211)-n;
	_c = ((unsigned int) 129)-n;
	_x++;
	_a = (_a^_c^_x);
	_b = (_b+_a);
	_c = ((_c+(_b>>1))^_a);
}

unsigned int Rand()
{
	_x++;
	_a = (_a^_c^_x);
	_b = (_b+_a);
	_c = ((_c+(_b>>1))^_a);
	return _c;
}

unsigned int RandMax(unsigned int m)
{
	return Rand()%m;
}



void _MessageBox(const char *m)
{
	while (1)
	{
		CLS;
		Wait_Recal();
		Do_Sound();
		check_buttons();
		VIA_t1_cnt_lo = MESSAGE_SCALE; // scale
		Intensity_a(0x5f); /* set intensity of vector beam... */
		
		ADDLINE;
		ADDLINE;
		ADDLINE;
		ADDLINE;
		ADDLINE;
		printDirect(m);
		
		if (buttons_pressed())
		{
			break;
		}
	}
	check_buttons();
}

void print_timed(const char * tm)
{
	char *to = messageBuffer;
	char c;
	messageTime = 25;
	do
	{
		c=*(tm++);
		*(to++) = c;
	} while ((c != 0)&&(c != 0x80));
	if (c==0) *(to-1) = 0x80;
}

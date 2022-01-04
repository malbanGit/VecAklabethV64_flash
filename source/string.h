
extern void syncPrintStrd(const int a, const int b, void* const u);
#define Print_Str_d syncPrintStrd

#define TEXT_SCALE (0x44)
#define MESSAGE_SCALE (0x50)

void _MessageBox(const char *m);
void printfs(const char *s1, const char *s2);
void printfss(const char *s1, const char *s2, const char *s3);
void printfi(const char *s1, const unsigned int i);
void printfsi(const char *s1, const char *s2, const unsigned int i);
void printfl(const char *s1, const unsigned long i);
void printfsl(const char *s1, const char *s2, const unsigned long i);
void printfsli(const char *s1, const char *s2, unsigned long l, unsigned int i);
void _print_timed(const char * tm);

#define MessageBox(m) _MessageBox(m "\x80")

char * itoa(unsigned int n);
char * ltoa(unsigned long n);
char * ltoaP(unsigned long n, char *pointer);

void vstrcpy(char * dest, char *source);				

#define printDirect(text) do {Print_Str_d((_YC-=0x10),_XC, (void* const)(text));} while (0)
#define print(text) do {printDirect( (text "\x80")  );} while (0)
#define CLS do{_XC = -0x70;_YC = 0x70;} while(0)
#define ADDLINE do{_YC -= 0x10;} while(0)
#define WAIT(a) do {waitTimer = a;} while (0)

//void abort(void);
//void free(void* pointer);
//void* malloc(long unsigned int size);
//int memcmp (const void* str1, const void* str2, long unsigned int count);
//void* memcpy (void* dest, const void* src, long unsigned int len);
//void* memmove(void* dest, const void* src, long unsigned int len);
void* memset(void* dest, unsigned int val, long unsigned int len);


void setRandSeed(unsigned int n);
unsigned int Rand();
unsigned int RandMax(unsigned int m);

// fs = format string
// max buf size
// '%' is used as placeholder
// place holder must exist!

__INLINE char * _fs(const char *s1, const char *s2)
{
    char *to = stringBuffer40;
    char c;
    while ( (c=*(s1++)) != '%') 
        *(to++) = c;
    while ( (c=*(s2++)) != 0) 
        *(to++) = c;
    while ( (c=*(s1++)) != 0) 
        *(to++) = c;
    *to = '\x80';
    return stringBuffer40;
}

__INLINE char * _fi(const char *s1, unsigned int i)
{
    return _fs(s1,  itoa(i));
}
void _fsi(const char *s1, const char *s2, const unsigned int i);
void print_timed(const char * tm);




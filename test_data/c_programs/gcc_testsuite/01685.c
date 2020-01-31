










typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;

typedef long int int64_t;







typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

typedef unsigned int uint32_t;



typedef unsigned long int uint64_t;
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;

typedef long int int_least64_t;






typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;

typedef unsigned long int uint_least64_t;
typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;


typedef unsigned long int uintptr_t;
typedef long int intmax_t;
typedef unsigned long int uintmax_t;

void param_test(short int my_short, int my_int, long int my_long,
                long long int my_long_long, int8_t my_int8_t,
                int_least8_t my_int_least8_t, int_fast8_t my_int_fast8_t,
                int16_t my_int16_t, int_least16_t my_int_least16_t,
                int_fast16_t my_int_fast16_t, int32_t my_int32_t,
                int_least32_t my_int_least32_t, int_fast32_t my_int_fast32_t,
                int64_t my_int64_t, int_least64_t my_int_least64_t,
                int_fast64_t my_int_fast64_t, intmax_t my_intmax_t,
                intptr_t my_intptr_t, float my_float, double my_double,
                long double my_long_double, char my_char, _Bool my_bool);


int main(int argc, char **argv)
{
   short int my_short = 1;
   int my_int = 2;
   long int my_long = 3;
   long long int my_long_long = 4;
   int8_t my_int8_t = 1;
   int_least8_t my_int_least8_t = 2;
   int_fast8_t my_int_fast8_t = 3;
   int16_t my_int16_t = 1;
   int_least16_t my_int_least16_t = 2;
   int_fast16_t my_int_fast16_t = 3;
   int32_t my_int32_t = 1;
   int_least32_t my_int_least32_t = 2;
   int_fast32_t my_int_fast32_t = 3;
   int64_t my_int64_t = 1;
   int_least64_t my_int_least64_t = 2;
   int_fast64_t my_int_fast64_t = 3;
   intmax_t my_intmax_t = 1;
   intptr_t my_intptr_t = 0;
   float my_float = 1.0;
   double my_double = 2.0;
   long double my_long_double = 3.0;
   char my_char = 'y';
   _Bool my_bool = 1;

   param_test(my_short, my_int, my_long, my_long_long, my_int8_t,
              my_int_least8_t, my_int_fast8_t, my_int16_t,
              my_int_least16_t, my_int_fast16_t, my_int32_t,
              my_int_least32_t, my_int_fast32_t, my_int64_t,
              my_int_least64_t, my_int_fast64_t, my_intmax_t,
              my_intptr_t, my_float, my_double, my_long_double, my_char,
              my_bool);

   return 0;
}

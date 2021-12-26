#include <stdio.h>
#include <math.h>

int main()
{
    double value = sqrt(9242333333453322);
    float value2 = sqrt(9242333333453322);
    printf("double: %lf\n", value);
    printf("float: %f\n", value2);

    int valuex = 1111111111;// Ten digits overflow in int
    long long int valuex2 = 9999999999;
    printf("Ten digits : %d %lld\n", valuex, valuex2);

    valuex = 999999999;
    valuex2 = 999999999;
    printf("Nine digits : %d %lld\n", valuex, valuex2);

    valuex2 = 111111111111111111;
    printf("Eighteen digits : %d %lld\n", valuex, valuex2);

    valuex2 = 1111111111111111111;
    printf("Nineteen digits : %d %lld\n", valuex, valuex2);

    valuex2 = 11111111111111111111;
    printf("Twenty digits : %d %lld\n", valuex, valuex2); //Twenty digits overflow in long long int


    //CTRL F9 Build; CTRL F10 RUN

    int absolute_value = fabs(-34);
    double absolute_value2 = fabs(-5.5);

    printf("Absolute value of int: %d\nAbsolute value of double: %lf\n", absolute_value, absolute_value2);

    double pi = acos(-1.0);
    printf("PI ~ %lf\n\n", pi);

    printf("Range of int\n\n");

    int pw = -1 * pow(2, 31);
    int pw2 = pow(2, 31) - 1;
    printf("2^10    : %d \n2^10 - 1 : %d\n", pw, pw2);

    printf("Range of long long\n\n");

    long long  pw3 = -1 * pow(2, 63);
    long long  pw4 = pow(2, 63) - 1;
    printf("2^63    : %lld \n2^63 - 1 : %lld\n", pw3, pw4);

    double floorval = floor(3.696565);
    double ceilval = ceil(3.6659865);
    printf("floor: %lf \nceil: %lf\n", floorval, ceilval);







    return 0;

}

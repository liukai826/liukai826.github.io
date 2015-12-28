//Author:kaka
//date:2015/12/18

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#define DIM 1024
#define DM1 (DIM - 1)
#define _sq(x) (x^2)
#define _cb(x) abs(x^3)
#define _cr(x) (unsigned char)(pow((x), 1.0/3.0))

unsigned char GR(int, int);
unsigned char BL(int, int);

unsigned char RD(int i, int j)
{
    //return i&&j?(i%j)&(j%i):0;
    float s=3./(j+99);
    return (int((i+DIM)*s+j*s)%2+int((DIM*2-i)*s+j*s)%2)*127;
}

unsigned char GR(int i, int j)
{
    //return i&&j?(i%j)+(j%i):0;
    float s=3./(j+99);
    return (int((i+DIM)*s+j*s)%2+int((DIM*2-i)*s+j*s)%2)*127;
}

unsigned char BL(int i, int j)
{
    //return i&&j?(i%j)|(j%i):0;
    float s=3./(j+99);
    return (int((i+DIM)*s+j*s)%2+int((DIM*2-i)*s+j*s)%2)*127;

}

void pixel_write(int, int);
FILE *fp;

int main()
{
    fp = fopen("MathPic.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", DIM, DIM);
    for (int j = 0; j < DIM; j++)
    {
        for (int i = 0; i < DIM; i++)
        {
            pixel_write(i, j);
        }
    }
    fclose(fp);
    return 0;
}

void pixel_write(int i, int j)
{
    static unsigned char color[3];
    color[0] = RD(i, j)&255;
    color[1] = GR(i, j)&255;
    color[2] = BL(i, j)&255;
    fwrite(color, 1, 3, fp);
}

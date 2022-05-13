#include<cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include"Bacterium.h"
#include "Growth_medium.h"
#include "Nutrient_particle.h"  
#define _USE_MATH_DEFINES
#include <math.h> //��� ����� M_PI �� ������������


const float a = 20; //�������� ������ ����� ����� ��� X
const float b = 10; //�������� ������ ����� ����� ��� Y
const float D = 3.35; //����������� �������� ��� ������������ ��������
const float I = 1.2; //����������� �������� ��� ������������ �������� (����������)
const float g = 0.75;  // ����������� ������������������ ��� ���������� ������ ����� ���������
const float k = 0.5; // ����������� ������������������ ������� ������� � ������������





bool Bacterium::one_active_step()
{
    float dx, dy, xx, yy, V1, V2, Sum;
    size = fabs(size);
    if (size <= 0) 
        return false;
    V1 = velocity * cos(orientation);
    V2 = velocity * sin(orientation);
    dx = g * (V1 / size) * cos(orientation);
    dy = g * (V2 / size) * sin(orientation);

    if (x < 0 || x > a || y < 0 || y > b)
        return false;
    xx = x; yy = y;
    Sum = xx + dx;
    if (Sum >= 0 && Sum <= a)
        xx += dx;
    if (Sum > a)
    {
        xx = 2*a - xx - dx;
        V1 = -V1;
        orientation = 2* M_PI - orientation;
    }
    if (Sum < 0)
    {
        xx = - (xx + dx);
        V1 = -V1;
        orientation = 2 * M_PI - orientation;
    }
    Sum = yy + dy;
    if (Sum >= 0 && Sum <= b)
        yy += dy;
    if (Sum < 0)
    {
        yy = -(yy + dy);
        V2 = -V2;
        orientation = 2 * M_PI - orientation;
    }
    if (Sum > b)
    {
        yy = 2*b - yy - dy;
        V2 = -V2;
        orientation = 2 * M_PI - orientation;
    }
    //velocity = sqrt(V1 * V1 + V2 * V2);
    if (xx < 0 || xx > a || yy < 0 || yy > b)
        return false;
    //��������, ��� �������� �������� ���������
    if (((fabs(xx-x)) < 0.0000000000001) || ((fabs(yy - y)) < 0.0000000000001))
       return false;
    else
    {
        x = xx; y = yy;
        return true;
    }
}

bool Bacterium::brownian_motion()
{
    float dx, dy, dl, df, xx, yy;
    float Sum;
    int z;
    if (x < 0 || x > a || y < 0 || y > b)
        return false;
    if (size <= 0)
        return false;
    z = rand() % 3 - 1; // ��������� ������� ����������� - ���������� �� ���� ����������, ���������� �� ��� ��������� ����������.
    dl = D / (sqrt(size));
    df = I / (sqrt(size));
    dx = z * dl * cos(orientation); 
    dy = z * dl * sin(orientation);
    xx = x; yy = y;
    Sum = xx + dx;
    if (Sum >= 0 && Sum <= a)
        xx += dx;
    if (Sum < 0)
       xx = 0;
    if (Sum > a)
        xx = a;
    Sum = yy + dy;
    if (Sum >= 0 && Sum <= b)
        yy += dy;
    if (Sum < 0)
        yy = 0;
    if (Sum > b)
        yy = b;
    orientation = z * df + orientation;
    if (xx < 0 || xx > a || yy < 0 || yy > b)
        return false;
   else
        x = xx;
        y = yy;
        return true;
}

void Bacterium::print() const
{
    static int kb = 0;
    printf("the Bacterium status is %d \n", (this->get_status()));
    printf("x = %f \n", (this->x));
    printf("y = %f \n", (this->y));
    printf("orientation = %f \n", (this->orientation));
    printf("food = %d \n", (this->food));
    printf("size = %f \n", (this->size));
    printf("velocity = %f \n \n \n", (this->velocity));
    kb++;
}

void Bacterium::bacterium_creating(float a, float b)
{
    x = ((double)(rand()) / (RAND_MAX / a));
    y = ((double)(rand()) / (RAND_MAX / b));
    orientation= ((double)(rand()) / (RAND_MAX /3));
    food = 0;
    size = ((double)(rand()) / (RAND_MAX / 5));
    velocity = ((double)(rand()) / (RAND_MAX / 5));
}

#include <kipr/botball.h>
void Drive_Forward (int distance);
void Drive_Backwards (int distance);
void Turn_Left (int distance);
void Turn_Right (int distance);
int Grab_Firefighter (int count);
int Open=380;
int Close=800;
int count=0;
int Up=10;
int Down=10;
int main()
{
//Drive_Forward(68);
//Drive_Backwards(68);
//Turn_Left(90);
//Turn_Right(90);
Drive_Forward(10);
Turn_Left(90);
Drive_Forward(10);
Turn_Left(90);
Drive_Forward(10);
Turn_Right(90);
Drive_Forward(10);
Grab_Firefighter(5);
return 0;
}
void Drive_Forward(int distance)
{
    cmpc(0);
    while(abs(gmpc(0))<100*distance)
    {
        motor(0,96.5);
        motor(1,97.5);
        msleep(10);
    }
	ao();
}
void Drive_Backwards(int distance)
{
    cmpc(0);
    while(abs(gmpc(0))<100*distance)
    {
        motor(0,-96.5);
        motor(1,-97.5);
        msleep(10);
    }
	ao();
}
void Turn_Left (int distance)
{
    cmpc(1);
    while(abs(gmpc(1))<21.5*distance)
    {
        motor(0,0);
        motor(1,100);
        msleep(10);
    }
    ao();
}
void Turn_Right (int distance)
{
    cmpc(0);
    while(abs(gmpc(0))<21*distance)
    {
        motor(0,100);
        motor(1,0);
        msleep(10);
    }
    ao();
}
int Grab_Firefighter (int count)
{
    set_servo_position(2,Open);
    Drive_Forward(3);
    set_servo_position(2,Close);
    Drive_Backwards(10);
    Turn_Right(110);
    set_servo_position(2,Open);
	set_servo_position(1, Up);
    Turn_Left(110);
    set_servo_position(1, Down);
}
    
    




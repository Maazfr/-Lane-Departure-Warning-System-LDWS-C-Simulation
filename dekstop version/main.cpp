#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class LaneSensor
{
public:

bool leftlane;
bool rightLane;

LaneSensor() : leftlane(true), rightLane(true) {}

void update(bool left , bool right)
{

    leftlane = left;
    rightLane = right;
}

void input()
{
    leftlane = rand() % 2;
    rightLane = rand() %2;
}

};

class laneDeptSys
{
LaneSensor& sensor;

public:

laneDeptSys(LaneSensor& s) : sensor(s) {}

void checkDept()
{
    if(!sensor.leftlane && sensor.rightLane )
    {
        cout<<"DANGER!! Drifting left!!! CORRECT STEERING"<<endl;
    }
    else if( sensor.leftlane && !sensor.rightLane)
    {
        cout<<"DANGER!! Drifting right!!! CORRECT STEERING"<<endl;
    }
    else if(!sensor.leftlane && !sensor.rightLane)
    {
        cout<<"EMERGENCY!!! DANGER!!! OUT OF LANE!!! HOLD STEERING!!!"<<endl;
    }
    else
    {
        cout<<"You are in lane~~~"<<endl;
    }
}

};

int main()
{
    srand(time(0));
    LaneSensor laneSensor;
    laneDeptSys laneSys(laneSensor);

    while(true)
    {
        laneSensor.input();
        laneSys.checkDept();
    }

    return 0;
}


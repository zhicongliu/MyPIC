#include "BeamRotationMap.h"
BeamRotationMap::~BeamRotationMap(){}
BeamRotationMap::BeamRotationMap(double anglexy,double anglexz,double anglezy)
{
  anglexy=anglexy*M_PI/180;
  anglexz=anglexz*M_PI/180;
  anglezy=anglezy*M_PI/180;
  angleXY=anglexy;
  angleXZ=anglexz;
  angleZY=anglezy;
  Map();
}
  void BeamRotationMap::Map()
{
//=================angleXY-start========================
//xx
Rxy(0,0)=cos(angleXY);
Rxy(0,1)=0;
Rxy(1,0)=0;
Rxy(1,1)=cos(angleXY);
//yy
Rxy(2,2)=cos(angleXY);
Rxy(2,3)=0;
Rxy(3,2)=0;
Rxy(3,3)=cos(angleXY);
//zz
Rxy(4,4)=1;
Rxy(4,5)=0;
Rxy(5,4)=0;
Rxy(5,5)=1;
//xy
Rxy(0,2)=sin(angleXY);
Rxy(0,3)=0;
Rxy(1,2)=0;
Rxy(1,3)=sin(angleXY);
//yx
Rxy(2,0)=-sin(angleXY);
Rxy(2,1)=0;
Rxy(3,0)=0;
Rxy(3,1)=-sin(angleXY);
//
//=================angleXY-end========================
//
//=================angleXZ-start========================
//xx
Rxz(0,0)=cos(angleXZ);
Rxz(0,1)=0;
Rxz(1,0)=0;
Rxz(1,1)=cos(angleXZ);
//yy
Rxz(2,2)=1;
Rxz(2,3)=0;
Rxz(3,2)=0;
Rxz(3,3)=1;
//zz
Rxz(4,4)=cos(angleXZ);
Rxz(4,5)=0;
Rxz(5,4)=0;
Rxz(5,5)=cos(angleXZ);
//xz
Rxz(0,4)=sin(angleXZ);
Rxz(0,5)=0;
Rxz(1,4)=0;
Rxz(1,5)=sin(angleXZ);
//zx
Rxz(4,0)=-sin(angleXZ);
Rxz(4,1)=0;
Rxz(5,0)=0;
Rxz(5,1)=-sin(angleXZ);
//
//=================angleXZ-end========================
//
//=================angleZY-start========================
//xx
Rzy(0,0)=1;
Rzy(0,1)=0;
Rzy(1,0)=0;
Rzy(1,1)=1;
//yy
Rzy(2,2)=cos(angleZY);
Rzy(2,3)=0;
Rzy(3,2)=0;
Rzy(3,3)=cos(angleZY);
//zz
Rzy(4,4)=cos(angleZY);
Rzy(4,5)=0;
Rzy(5,4)=0;
Rzy(5,5)=cos(angleZY);
//yz
Rzy(2,4)=sin(angleZY);
Rzy(2,5)=0;
Rzy(3,4)=0;
Rzy(3,5)=sin(angleZY);
//zy
Rzy(4,2)=-sin(angleZY);
Rzy(4,3)=0;
Rzy(5,2)=0;
Rzy(5,3)=-sin(angleZY);
//
//=================angleZY-end========================
R=Rxy*Rxz*Rzy;
}

void BeamRotationMap::print()
{
cout<<"The transfer matrix of Beam Rotation(anglexy = "<<angleXY/M_PI*180<<" deg,anglexz = "<<angleXZ/M_PI*180<<" deg,anglezy = "<<angleZY/M_PI*180<<" deg) is\n"<<R<<endl;
cout<<"Rxy=\n"<<Rxy<<endl<<endl;
cout<<"Rxz=\n"<<Rxz<<endl<<endl;
cout<<"Rzy=\n"<<Rzy<<endl<<endl;
}


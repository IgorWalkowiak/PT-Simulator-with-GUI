#ifndef PARTRAJECTORY_H_INCLUDED
#define PARTRAJECTORY_H_INCLUDED


#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>
#include <iostream>
#include <math.h>
#include <fstream>


const double G=9.80665;




class ParTrajectory
{

public:
    ParTrajectory(double,double,double,double);


};



#endif // PARTRAJECTORY_H_INCLUDED

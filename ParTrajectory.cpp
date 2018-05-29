#include "ParTrajectory.h"
int funcX (double t, const double y[], double f[], void *params)
{
  (void)(t);
  double mu=*((double *)params+0);


  double Uy=*((double *)params+2);
  double Wx=*((double *)params+3);
  double Wy=*((double *)params+4);

  f[0] = y[1];
  f[1] = -mu*sqrt((y[1]-Wx)*(y[1]-Wx)+(Uy-Wy)*(Uy-Wy))*(y[1]-Wx);

  return GSL_SUCCESS;
}

int jacX (double t, const double y[], double *dfdy,
     double dfdt[], void *params)
{
  (void)(t);
    double mu=*((double *)params+0);
    double Ux=*((double *)params+1);
    double Uy=*((double *)params+2);
    double Wx=*((double *)params+3);
    double Wy=*((double *)params+4);

  gsl_matrix_view dfdy_mat = gsl_matrix_view_array (dfdy, 2, 2);
  gsl_matrix * m = &dfdy_mat.matrix;
  gsl_matrix_set (m, 0, 0, 0.0);
  gsl_matrix_set (m, 0, 1, 1.0);
  gsl_matrix_set (m, 1, 0, -mu*(Ux-Wx)*(Ux-Wx)/sqrt((Ux-Wx)*(Ux-Wx)+(Uy-Wy)*(Uy-Wy))-mu*sqrt((Ux-Wx)*(Ux-Wx)+(Uy-Wy)*(Uy-Wy)));
  gsl_matrix_set (m, 1, 1, 0);
  dfdt[0] = 0.0;
  dfdt[1] = 0.0;
  return GSL_SUCCESS;
}

//___________Y_______________

int funcY (double t, const double y[], double f[], void *params)
{
  (void)(t);

    double mu=*((double *)params+0);
    double Ux=*((double *)params+1);

    double Wx=*((double *)params+3);
    double Wy=*((double *)params+4);

  f[0] = y[1];
  f[1] = -G-mu*sqrt((Ux-Wx)*(Ux-Wx)+(y[1]-Wy)*(y[1]-Wy))*(y[1]-Wy);
  return GSL_SUCCESS;
}

int jacY (double t, const double y[], double *dfdy,
     double dfdt[], void *params)
{
  (void)(t);
    double mu = *(double *)params;
    double Ux=*((double *)params+1);
    double Uy=*((double *)params+2);
    double Wx=*((double *)params+3);
    double Wy=*((double *)params+4);
  gsl_matrix_view dfdy_mat = gsl_matrix_view_array (dfdy, 2, 2);
  gsl_matrix * m = &dfdy_mat.matrix;
  gsl_matrix_set (m, 0, 0, 0.0);
  gsl_matrix_set (m, 0, 1, 1.0);
  gsl_matrix_set (m, 1, 0, -mu*(Uy-Wy)*(Uy-Wy)/sqrt((Ux-Wx)*(Ux-Wx)+(Uy-Wy)*(Uy-Wy))-mu*sqrt((Ux-Wx)*(Ux-Wx)+(Uy-Wy)*(Uy-Wy)));
  gsl_matrix_set (m, 1, 1, 0);
  dfdt[0] = 0.0;
  dfdt[1] = 0.0;
  return GSL_SUCCESS;
}


ParTrajectory::ParTrajectory(double Uangle,double UValue, double Wangle, double WValue)
{

        Uangle=Uangle*0.017453;
        Wangle=Wangle*0.017453;

        double k=0.1;

        double Ux=UValue*cos(Uangle);
        double Uy=UValue*sin(Uangle);
        double Wx=WValue*cos(Wangle);
        double Wy=WValue*sin(Wangle);


        double par[5] = {k, Ux, Uy, Wx, Wy};
        double t = 0.0;
        double x[2] = { 20, UValue*cos(Uangle)};
        double y[2] = { 20, UValue*sin(Uangle)};

            gsl_odeiv2_system sysX = {funcX, jacX, 2, &par};
            gsl_odeiv2_driver * X = gsl_odeiv2_driver_alloc_y_new(&sysX, gsl_odeiv2_step_rk8pd,1e-6, 1e-6, 0.0);

            gsl_odeiv2_system sysY = {funcY, jacY, 2, &par};
            gsl_odeiv2_driver * Y = gsl_odeiv2_driver_alloc_y_new(&sysY, gsl_odeiv2_step_rk8pd,1e-6, 1e-6, 0.0);



        std::fstream file;
        file.open( "data.txt", std::ios::out );
        if( file.good() == true )
        {
            std::cout << "I've opened a file" << std::endl;
        }
        else std::cout << "Something goes wrong" << std::endl;




      for (int i = 1; i <= 10000; i++)
        {

            int s = gsl_odeiv2_driver_apply_fixed_step(X,&t,1e-5,100,x);
            par[1]=x[1];

            if(s != GSL_SUCCESS)
            {
              printf ("error: driver returned %d\n", s);
              break;
            }

            s = gsl_odeiv2_driver_apply_fixed_step(Y,&t,1e-5,100,y);
            par[2]=y[1];

            if(s != GSL_SUCCESS)
            {
                printf ("error: driver returned %d\n", s);
                break;
            }

            if(y[0]<=0) break;


            file<<t<<" "<<y[0]<<" "<<y[1]<<" "<<x[0]<<" "<<x[1]<<"\n";

        }
       gsl_odeiv2_driver_free (Y);
    }

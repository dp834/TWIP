#include <math.h>    
#include "trigfun.h"  
/* 
 *  
 *            Syntax  [sys, x0] = TWIP_sFunc(t,x,u,flag,X0) 
*/ 
/* 
* The following #define is used to specify the name of this S-Function. 
*/ 
#define S_FUNCTION_NAME TWIP_sFunc 
/* 
* need to include simstruc.h for the definition of the SimStruct and 
* its associated macro definitions. 
*/ 
#include "simstruc.h" 
  
/* 
 * mdlInitializeSizes - initialize the sizes array 
 * 
 * The sizes array is used by SIMULINK to determine the S-function block's 
 * characteristics (number of inputs, outputs, states, etc.). 
 */ 
static void mdlInitializeSizes(S) 
    SimStruct *S; 
{ 
    ssSetNumContStates(    S, 7);      /* number of continuous states */ 
    ssSetNumDiscStates(    S, 0);      /* number of discrete states */ 
    ssSetNumInputs(        S, 2);      /* number of inputs */ 
    ssSetNumOutputs(       S, 7);      /* number of outputs */ 
    ssSetDirectFeedThrough(S, 0);      /* direct feedthrough flag */ 
    ssSetNumSampleTimes(   S, 1);      /* number of sample times */ 
    ssSetNumInputArgs(     S, 1);      /* number of input arguments */ 
    ssSetNumRWork(         S, 0);      /* number of real work vector elements */ 
    ssSetNumIWork(         S, 0);      /* number of integer work vector elements */ 
    ssSetNumPWork(         S, 0);      /* number of pointer work vector elements */ 
     /* 
     * if there aren't the correct number of parameters, just return, simulink.c will 
     * flag the error 
     */ 
    if (ssGetNumArgs(S) != 1) 
       return; 
    if (mxGetM(ssGetArg(S,0)) != 7  || mxGetN(ssGetArg(S,0)) !=1)  { 
        ssSetErrorStatus( S,"X0 must have dimensions: 7 by 1"); 
        return; 
    } 
} 
/* 
 * mdlInitializeSampleTimes - initialize the sample times array 
 * 
 * This function is used to specify the sample time(s) for your S-function. 
 * If your S-function is continuous, you must specify a sample time of 0.0. 
 * Sample times must be registered in ascending order. 
 */ 
static void mdlInitializeSampleTimes(S) 
    SimStruct *S; 
{ 
    ssSetSampleTimeEvent(S, 0, 0.0); 
    ssSetOffsetTimeEvent(S, 0, 0.0); 
} 
/* 
 * mdlInitializeConditions - initialize the states 
 * 
 * In this function, you should initialize the continuous and discrete 
 * states for your S-function block.  The initial states are placed 
 * in the x0 variable.  You can also perform any other initialization 
 * activities that your S-function may require. 
 */ 
static void mdlInitializeConditions(x0, S) 
#ifdef MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */ 
    double *x0; 
    SimStruct *S; 
{ 
    int i,imax; 
    double *X0pr; 
/* Set initial value for state vector */ 
    X0pr = mxGetPr(ssGetArg(S,0));  
    imax = mxGetM(ssGetArg(S,0)); 
    for(i=0;i<imax;i++){ 
        x0[i] = X0pr[i]; 
    } 
} 
#else    /* compiled for dSpace board? */ 
    real_T *x0; 
    SimStruct *S; 
{ 
    int_T i,imax; 
    real_T *X0pr; 
/* Set initial value for state vector */ 
    X0pr = mxGetPr(ssGetArg(S,0));  
    imax = mxGetM(ssGetArg(S,0)); 
    for(i=0;i<imax;i++){ 
        x0[i] = X0pr[i]; 
    } 
} 
#endif 
/* 
 * mdlDerivatives - compute the derivatives 
 * 
 * In this function, you compute the S-function block's derivatives. 
 * The derivatives are placed in the dx variable. 
 */ 
static void mdlDerivatives(dx, x, u, S, tid) 
#ifdef MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */ 
    double *dx, *x, *u; 
    SimStruct *S; 
    int tid; 
{  
    int n; 
    double s1, s2, s3, s4, s5, s6, s7, s8, s9, s10; 
    double t1, t2, t3, t4, t5, t6, t7, t8, t9, t10; 
    double *RWork = ssGetRWork(S); 
    int i,j; 
    char s='L'; 
    int nrhs, LDA, info; 
#else    /* compiled for dSpace board? */ 
    real_T *dx; 
	 const real_T *x, *u; 
    SimStruct *S; 
    int_T tid; 
{  
    int_T n; 
    real_T s1, s2, s3, s4, s5, s6, s7, s8, s9, s10; 
    real_T t1, t2, t3, t4, t5, t6, t7, t8, t9, t10; 
    real_T *RWork = ssGetRWork(S); 
    int_T i,j; 
    char s='L'; 
    int_T nrhs, LDA, info; 
#endif 
    n = 7; 
    t1 =    pow(x[6],2.); 
    t2 =    pow(x[4],2.); 
    t3 =    cos(x[2]); 
    t4 =    cos(x[3]); 
    t5 =    sin(x[2]); 
    t6 =    sin(x[3]); 
    t7 =    pow(t4,2.); 
    t8 =    sin(3.*x[3]); 
    t9 =    1/(-0.064739967+t7); 
    t10 =    1/(-2.6236921+t7); 
  dx[0] =     t3*x[5]; 
  dx[1] =     t5*x[5]; 
  dx[2] =     x[6]; 
  dx[3] =     x[4]; 
  dx[4] =     t10*(-56.058937*t6+0.65308212*u[0]+t4*((-1.3810068*t1+t2)*t6+0.45714286*u[0]+0.45714286*u[1])+0.65308212*u[1]); 
  dx[5] =     t10*((-0.35496571*t1-0.45913143*t2)*t6+0.10416571*t1*t8-0.20988865*u[0]+t4*(9.81*t6-0.11428571*u[0]-0.11428571*u[1])-0.20988865*u[1]); 
  dx[6] =     t9*(-0.010253676*u[0]+0.010253676*u[1]+t6*(0.093457129*t4*x[4]+0.11214958*x[5])*x[6]); 
} 
/* 
 * mdlOutputs - compute the outputs 
 * 
 * In this function, you compute the outputs of your S-function 
 * block.  The outputs are placed in the y variable. 
 */ 
static void mdlOutputs(y, x, u, S, tid) 
#ifdef MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */ 
    double *y, *x, *u; 
    SimStruct *S; 
    int tid; 
{ 
    double s1, s2, s3, s4, s5, s6, s7, s8, s9, s10; 
  
#else    /* compiled for dSpace board? */ 
    real_T *y; 
	  const real_T *x, *u; 
    SimStruct *S; 
    int_T tid; 
{ 
    real_T s1, s2, s3, s4, s5, s6, s7, s8, s9, s10; 
  
#endif 
    y[0] =     x[0]; 
    y[1] =     x[1]; 
    y[2] =     x[2]; 
    y[3] =     x[3]; 
    y[4] =     x[4]; 
    y[5] =     x[5]; 
    y[6] =     x[6]; 
} 
/* 
 * mdlUpdate - perform action at major integration time step 
 * 
 * This function is called once for every major integration time step. 
 * Discrete states are typically updated here, but this function is useful 
 * for performing any tasks that should only take place once per integration 
 * step. 
 */ 
static void mdlUpdate(x, u, S, tid) 
#ifdef MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */ 
    double  *x, *u; 
    SimStruct *S; 
    int tid; 
#else    /* compiled for dSpace board? */ 
    real_T *x; 
	  const real_T *u; 
    SimStruct *S; 
    int_T tid; 
#endif 
{ 
} 
/* 
 * mdlTerminate - called when the simulation is terminated. 
 * 
 * In this function, you should perform any actions that are necessary 
 * at the termination of a simulation.  For example, if memory was allocated 
 * in mdlInitializeConditions, this is the place to free it. 
 */ 
static void mdlTerminate(S) 
    SimStruct *S; 
{ 
} 
#ifdef MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */ 
#include "simulink.c"      /* MEX-file interface mechanism */ 
#else 
#include "cg_sfun.h"       /* Code generation registration function */ 
#endif 

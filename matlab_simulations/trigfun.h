/* Trig functions to work around Watcom Bug */
/* This file also redines functions that Mathmatica seems to think
are in standard C but are not! */

/*  7/27/99  Modifications - C. A. Teolis 
	1.  to run from dSpace boards ArcSinh(x), ArcCosh(x), ArcTanh(x) are not
		defined in the standard math library so include these definitions
		for mex files (simulink simulations) but exclude them for dSpace.
		Thus if these functions are needed in a model other libraries will
		have to be included for dSpace code to compile. */

static 
#ifdef __STDC__
double Cos(double x)
#else
double Cos(x)
double x; 
#endif /* __STDC__ */
{
        double y;
        y=cos(x);
        return (y);
}

static 
#ifdef __STDC__
double ArcCos(double x)
#else
double ArcCos(x)
double x; 
#endif /* __STDC__ */
{
        double y;
        y=acos(x);
        return (y);
}

static 
#ifdef __STDC__
double Sin(double x)
#else
double Sin(x)
double x; 
#endif /* __STDC__ */
{
        double y;
        y=sin(x);
        return (y);
}

static 
#ifdef __STDC__
double ArcSin(double x)
#else
double ArcSin(x)
double x; 
#endif /* __STDC__ */
{
        double y;
        y=asin(x);
        return (y);
}

static 
#ifdef __STDC__
double Power(double x, double y)
#else
double Power(x,y)
double x;
double y;
#endif /* __STDC__ */
{
        double z;
        z=pow(x,y);
        return (z);
}

static 
#ifdef __STDC__
double Tan(double x)
#else
double Tan(x)
double x;
#endif /* __STDC__ */
{
        double y;
        y=tan(x);
        return (y);
}

static 
#ifdef __STDC__
double ArcTan2(double arg1, double arg2)
#else
double ArcTan2(arg1,arg2)
double arg1, arg2;
#endif /* __STDC__ */
{
        double z;
        z=atan2(arg2,arg1);
        return (z);
}

static 
#ifdef __STDC__
double Cot(double x)
#else
double Cot(x)
double x;
#endif /* __STDC__ */
{
        double y;
        y=1/tan(x);
        return (y);
}

static 
#ifdef __STDC__
double Csc(double x)
#else
double Csc(x)
double x; 
#endif /* __STDC__ */
{
        double y;
        y=1/sin(x);
        return (y);
}

static 
#ifdef __STDC__
double Sec(double x)
#else
double Sec(x)
double x; 
#endif /* __STDC__ */
{
        double y;
        y=1/cos(x);
        return (y);
}

static 
#ifdef __STDC__
double Exp(double x)
#else
double Exp(x)
double x; 
#endif /* __STDC__ */
{
        double y;
        y=exp(x);
        return (y);
}

static 
#ifdef __STDC__
double Log(double x)
#else
double Log(x)
double x; 
#endif /* __STDC__ */
{
        double y;
        y=log(x);
        return (y);
}

static 
#ifdef __STDC__
double Sinh(double x)
#else
double Sinh(x)
double x; 
#endif /* __STDC__ */
{
        double y;
        y=sinh(x);
        return (y);
}


static 
#ifdef __STDC__
double Cosh(double x)
#else
double Cosh(x)
double x; 
#endif /* __STDC__ */
{
        double y;
        y=cosh(x);
        return (y);
}

static 
#ifdef __STDC__
double Tanh(double x)
#else
double Tanh(x)
double x; 
#endif /* __STDC__ */
{
        double y;
        y=tanh(x);
        return (y);
}

static 
#ifdef __STDC__
double Csch(double x)
#else
double Csch(x)
double x; 
#endif /* __STDC__ */
{
        double y;
        y=1/sinh(x);
        return (y);
}

static 
#ifdef __STDC__
double Sech(double x)
#else
double Sech(x)
double x; 
#endif /* __STDC__ */
{
        double y;
        y=1/cosh(x);
        return (y);
}

static 
#ifdef __STDC__
double Coth(double x)
#else
double Coth(x)
double x; 
#endif /* __STDC__ */
{
        double y;
        y=1/tanh(x);
        return (y);
}

static 
#ifdef __STDC__
double UnitStep(double x)
#else
double UnitStep(x)
double x; 
#endif /* __STDC__ */
{
        double y;
		if (x>0)
			y=1;
		else
			y=0;
        return (y);
}

static 
#ifdef __STDC__
double Sign(double x)
#else
double Sign(x)
double x; 
#endif /* __STDC__ */
{
        double y;
		if (x==0)
			y=0;
		else
			y=x/fabs(x);
        return (y);
}

static 
#ifdef __STDC__
double sign(double x)
#else
double sign(x)
double x; 
#endif /* __STDC__ */
{
        double y;
		if (x==0)
			y=0;
		else
			y=x/fabs(x);
        return (y);
}

static 
#ifdef __STDC__
double sat(double x)
#else
double sat(x)
double x; 
#endif /* __STDC__ */
{
        double y;
		if (x>1)
			y=1;
		if (x<-1)
			y=-1;
		else
			y=x;
        return (y);
}

#ifdef MATLAB_MEX_FILE
	static 
	#ifdef __STDC__
	double ArcSinh(double x)
	#else
	double ArcSinh(x)
	double x; 
	#endif 
	{
	        double y;
	        y=asinh(x);
	        return (y);
	} 

	static 
	#ifdef __STDC__
	double ArcCosh(double x)
	#else
	double ArcCosh(x)
	double x; 
	#endif 
	{
	        double y;
        	y=acosh(x);
		return (y);
	}  

	static 
	#ifdef __STDC__
	double ArcTanh(double x)
	#else
	double ArcTanh(x)
	double x; 
	#endif 
	{
	       double y;
	       y=atanh(x);
	       return (y);
	}  

#endif
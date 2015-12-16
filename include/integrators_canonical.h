#ifndef INTEGRATORS_CANONICAL_H
#define INTEGRATORS_CANONICAL_H

#include <vector>
#include "Polynomial/canonical.h"

// Euler forward integrator step
// Inputs
//   x         dependent variable (initial values)
//   t         independent variable (initial time)
//   h          fixed step size

template <class T>
std::vector<Canonical_Polynomial<T> > euler(std::vector<Canonical_Polynomial<T> > (*f)(const std::vector<Canonical_Polynomial<T> > &x, const std::vector<Canonical_Polynomial<T> > &param),std::vector<Canonical_Polynomial<T> > &x, const std::vector<Canonical_Polynomial<T> > &param, const T &h) {

        int n = x.size();
        int degree = x[0].get_degree();
        int nvar = x[0].get_nvar();

        std::vector<Canonical_Polynomial<T> > k1;
        for(int i=0; i<n; i++){
            k1.push_back(Canonical_Polynomial<T>(nvar,degree));
        }

        //* Evaluate k1 = f(x).
        k1 = (*f)(x,param);

        for(int i=0; i<n; i++)
            x[i] += h*k1[i];

        return x;
}

template <class T>
std::vector<Canonical_Polynomial<T> > discrete_method(std::vector<Canonical_Polynomial<T> > (*f)(const std::vector<Canonical_Polynomial<T> > &x, const std::vector<Canonical_Polynomial<T> > &param), std::vector<Canonical_Polynomial<T> > &x, const std::vector<Canonical_Polynomial<T> > &param, const T &h) {

        int n = x.size();
        int degree = x[0].get_degree();
        int nvar = x[0].get_nvar();

        std::vector<Canonical_Polynomial<T> > k1;
        for(int i=0; i<n; i++){
            k1.push_back(Canonical_Polynomial<T>(nvar,degree));
        }

        //* Evaluate k1 = f(x).
        k1 = (*f)(x,param);

        for(int i=0; i<n; i++)
            x[i] = k1[i];

        return x;
}



// Runge-Kutta integrator step (2th order)
// Inputs
//   x         dependent variable (initial values)
//   t         independent variable (initial time)
//   h          fixed step size
//   param      parameters

template <class T>
std::vector<Canonical_Polynomial<T> > rk2(std::vector<Canonical_Polynomial<T> > (*f)(const std::vector<Canonical_Polynomial<T> > &x, const std::vector<Canonical_Polynomial<T> > &param), std::vector<Canonical_Polynomial<T> > &x, const std::vector<Canonical_Polynomial<T> > &param, const T &h) {

        int n = x.size();
        int degree = x[0].get_degree();
        int nvar = x[0].get_nvar();

        std::vector<Canonical_Polynomial<T> > k1;
        std::vector<Canonical_Polynomial<T> > k2;
        std::vector<Canonical_Polynomial<T> > xtemp;

        for(int i=0; i<n; i++){
            k1.push_back(Canonical_Polynomial<T>(nvar,degree));
            k2.push_back(Canonical_Polynomial<T>(nvar,degree));
            xtemp.push_back(Canonical_Polynomial<T>(nvar,degree));
        }

        //* Evaluate k1 = f(x).
        k1 = (*f)(x,param);

	//* Evaluate k2 = f(x+h*k1),
	for(int i=0; i<n; i++)
	    xtemp[i] = x[i]+k1[i]*h;
	k2 = (*f)(xtemp,param);

        //* Return x(t+h) computed from second-order Runge Kutta.
        for(int i=0; i<n; i++)
            x[i] += (k1[i]+k2[i])*h/2.0;

        return x;

}


// Runge-Kutta integrator step (4th order)
// Inputs
//   x         dependent variable (initial values)
//   t         independent variable (initial time)
//   h          fixed step size

template <class T>
std::vector<Canonical_Polynomial<T> > rk4(std::vector<Canonical_Polynomial<T> > (*f)(const std::vector<Canonical_Polynomial<T> > &x, const std::vector<Canonical_Polynomial<T> > &param), std::vector<Canonical_Polynomial<T> > &x, const std::vector<Canonical_Polynomial<T> > &param, const T &h) {
    int n = x.size();
    int degree = x[0].get_degree();
    int nvar = x[0].get_nvar();

    std::vector<Canonical_Polynomial<T> > k1;
    std::vector<Canonical_Polynomial<T> > k2;
    std::vector<Canonical_Polynomial<T> > k3;
    std::vector<Canonical_Polynomial<T> > k4;
    std::vector<Canonical_Polynomial<T> > xtemp;

    for(int i=0; i<n; i++){
        k1.push_back(Canonical_Polynomial<T>(nvar,degree));
        k2.push_back(Canonical_Polynomial<T>(nvar,degree));
        k3.push_back(Canonical_Polynomial<T>(nvar,degree));
        k4.push_back(Canonical_Polynomial<T>(nvar,degree));
        xtemp.push_back(Canonical_Polynomial<T>(nvar,degree));
    }

    //* Evaluate k1 = f(x).
    k1 = (*f)(x,param);

    //* Evaluate k2 = f(x+h/2*k1),
    for(int i=0; i<n; i++)
        xtemp[i] = x[i]+k1[i]*h/2.0;
    k2 = (*f)(xtemp,param);

    //* Evaluate k3 = f(x+h/2*k2),
    for(int i=0; i<n; i++)
        xtemp[i] = x[i]+k2[i]*h/2.0;
    k3 = (*f)(xtemp,param);

    //* Evaluate k4 = f(x+h*k3),
    for(int i=0; i<n; i++)
        xtemp[i] = x[i]+k3[i]*h;
    k4 = (*f)(xtemp,param);

    //* Return x(t+h) computed from second-order Runge Kutta.
    for(int i=0; i<n; i++)
        x[i] += (k1[i]+2.0*k2[i]+2.0*k3[i]+k4[i])*h/6.0;

    return x;
}

#endif // INTEGRATORS_CANONICAL_H
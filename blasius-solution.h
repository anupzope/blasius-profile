#ifndef BLASIUS_SOLUTION_H
#define BLASIUS_SOLUTION_H

#include <cmath>
#include <map>
#include <iostream>

void eulerIntegrateBlasius(
  int const size, double const * eta,
  double * f, double * g, double * h
) {
  for(int i = 1; i < size; ++i) {
    double const dEta = eta[i]-eta[i-1];
    f[i] = f[i-1] + g[i-1]*dEta;
    g[i] = g[i-1] + h[i-1]*dEta;
    h[i] = h[i-1] - 0.5*f[i-1]*h[i-1]*dEta;
  }
}

std::pair<bool, int> shootingSolveBlasius(
  int const size, double const * eta,
  double * f, double * g, double * h,
  double const h0 = 1.0, double const h1 = 2.0,
  int const maxNewtonIter = 1000, double const tol = 1e-12
) {
  f[0] = 0.0;
  g[0] = 0.0;
  
  h[0] = h0;
  eulerIntegrateBlasius(size, eta, f, g, h);
  
  double hkm1 = h[0];
  double gkm1 = g[size-1];
  
  h[0] = h1;
  eulerIntegrateBlasius(size, eta, f, g, h);
  
  double hk = h[0];
  double gk = g[size-1];
  
  int iter = 0;
  double F = gk-1.0;
  bool converged = true;
  do {
    h[0] = hk - (g[size-1]-1.0)*(hk-hkm1)/(gk-gkm1);
    eulerIntegrateBlasius(size, eta, f, g, h);
    
    hkm1 = hk;
    gkm1 = gk;
    hk = h[0];
    gk = g[size-1];
    F = gk-1.0;
    std::cout << "F = " << F << std::endl;
    if(iter > maxNewtonIter) {
      std::cout << "solution did not converge" << std::endl;
      std::cout << "F = " << F << std::endl;
      converged = false;
      break;
    }
    ++iter;
  } while(std::fabs(F) > tol);
  
  return std::pair<bool, int>(converged, iter);
}

#endif // #ifdef BLASIUS_SOLUTION_H

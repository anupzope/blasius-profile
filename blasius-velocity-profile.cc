#include "blasius-solution.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>

bool isOption(char const * optionName, char const * arg) {
  size_t const len = std::strlen(optionName);
  if(std::strncmp(optionName, arg, len) == 0) {
    return true;
  }
  return false;
}

bool getOption(char const * optionName, char const * arg, char const * value) {
  size_t const len = std::strlen(optionName);
  if(std::strncmp(optionName, arg, len) == 0) {
    value = &arg[len];
    return true;
  }
  return false;
}

bool getOption(char const * optionName, char const * arg, long & value) {
  size_t const len = std::strlen(optionName);
  if(std::strncmp(optionName, arg, len) == 0) {
    value = std::strtol(&arg[len], NULL, 0);
    return true;
  }
  return false;
}

bool getOption(char const * optionName, char const * arg, double & value) {
  size_t const len = std::strlen(optionName);
  if(std::strncmp(optionName, arg, len) == 0) {
    value = std::strtod(&arg[len], NULL);
    return true;
  }
  return false;
}

int main(int argc, char * argv[]) {
  double pInf = 101325.0;
  double tInf = 300.0;
  double mInf = 100.0;
  double x = 0.3;
  double gamma = 1.4;
  double R = 287.101591851;
  double a1 = 1.458e-6;
  double a2 = 1.5;
  double a3 = 110.4;
  
  double minEta = 0.0;
  double maxEta = 10.0;
  long N = 10000;
  double h0 = 0.1;
  double h1 = 0.2;
  char const * outFile = "velocity-profile.dat";
  
  for(int i = 1; i < argc; ++i) {
    if(getOption("pInf=", argv[i], pInf)) {
    } else if(getOption("tInf=", argv[i], tInf)) {
    } else if(getOption("mInf=", argv[i], mInf)) {
    } else if(getOption("x=", argv[i], x)) {
    } else if(getOption("gamma=", argv[i], gamma)) {
    } else if(getOption("R=", argv[i], R)) {
    } else if(getOption("a1=", argv[i], a1)) {
    } else if(getOption("a2=", argv[i], a2)) {
    } else if(getOption("a3=", argv[i], a3)) {
    } else if(getOption("minEta", argv[i], minEta)) {
    } else if(getOption("maxEta", argv[i], maxEta)) {
    } else if(getOption("N", argv[i], N)) {
    } else if(getOption("h0", argv[i], h0)) {
    } else if(getOption("h1", argv[i], h1)) {
    } else if(getOption("out", argv[i], outFile)) {
    } else if(isOption("-help", argv[i])) {
      std::cout << "Usage: " << argv[0]
        << " [pInf] [tInf] [mInf] [gamma] [R] [a1] [a2] [a3] [x]"
        << " [minEta] [maxEta] [N] [h0] [h1] [out]"
        << std::endl;
      return 1;
    } else {
      std::cerr << "Unknown option" << std::endl;
      return 1;
    }
  }
  
  std::cout << std::endl;
  std::cout << "Given Quantities:" << std::endl;
  std::cout << "pInf = " << pInf << std::endl;
  std::cout << "tInf = " << tInf << std::endl;
  std::cout << "mInf = " << mInf << std::endl;
  std::cout << "x = " << x << std::endl;
  std::cout << "gamma = " << gamma << std::endl;
  std::cout << "R = " << R << std::endl;
  std::cout << "a1 = " << a1 << std::endl;
  std::cout << "a2 = " << a2 << std::endl;
  std::cout << "a3 = " << a3 << std::endl;
  std::cout << "minEta = " << minEta << std::endl;
  std::cout << "maxEta = " << maxEta << std::endl;
  std::cout << "N = " << N << std::endl;
  std::cout << "h0 = " << h0 << std::endl;
  std::cout << "h1 = " << h1 << std::endl;
  std::cout << "out = " << outFile << std::endl;
  
  double const uInf = std::sqrt(gamma*R*tInf)*mInf;
  double const muInf = a1*std::pow(tInf, a2)/(tInf+a3);
  double const rhoInf = pInf/(R*tInf);
  double const nuInf = muInf/rhoInf;
  
  std::cout << std::endl;
  std::cout << "Calculated Quantities:" << std::endl;
  std::cout << "uInf = " << uInf << std::endl;
  std::cout << "muInf = " << muInf << std::endl;
  std::cout << "rhoInf = " << rhoInf << std::endl;
  std::cout << "nuInf = " << nuInf << std::endl;
  
  std::cout << std::endl;
  std::cout << "Solving for Blasius velocity profile..." << std::endl;
  std::vector<double> eta(N), f(N), g(N), h(N);
  double const dEta = (maxEta - minEta)/double(N-1);
  for(int i = 0; i < N; ++i) {
    eta[i] = i*dEta;
  }
  
  std::pair<bool, int> converged = shootingSolveBlasius(N, &eta[0], &f[0], &g[0], &h[0], h0, h1);
  if(converged.first) {
    std::cout << "Blasius solution converged" << std::endl;
  } else {
    std::cout << "Blasius solution NOT converged" << std::endl;
  }
  
  std::cout << "Number of iterations = " << converged.second << std::endl;
  
  std::cout << std::endl;
  std::cout << "Solving for velocity profile..." << std::endl;
  std::vector<double> y(N), u(N), v(N);
  
  double const c1 = std::sqrt(nuInf*x/uInf);
  double const c2 = std::sqrt(nuInf*uInf/x);
  for(int i = 0; i < N; ++i) {
    y[i] = eta[i]*c1;
    u[i] = uInf*g[i];
    v[i] = 0.5*c2*(eta[i]*g[i]-f[i]);
  }
  
  for(int i = 0; i < N; ++i) {
    double const vMag = std::sqrt(u[i]*u[i]+v[i]*v[i]);
    if(vMag > 0.99*uInf) {
      std::cout << "BL thickness = " << y[i] << std::endl;
      break;
    }
  }
  
  std::ofstream file(outFile);
  for(int i = 0; i < N; ++i) {
    file << x << " " << y[i] << " " << u[i] << " " << v[i] << " " << pInf << " " << tInf << std::endl;
  }
  file.close();
  
  return 0;
}

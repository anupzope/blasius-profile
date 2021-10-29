#include "blasius-solution.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

int main(int argc, char * argv[]) {
  if(argc < 7) {
    std::cerr << "Usage: " << argv[0] << " <minEta> <maxEta> <N> <h0> <h1> <output-file>" << std::endl;
    return 1;
  }
  
  double const minEta = std::strtod(argv[1], NULL);
  double const maxEta = std::strtod(argv[2], NULL);
  int const N = std::strtol(argv[3], NULL, 0);
  double const h0 = std::strtod(argv[4], NULL);
  double const h1 = std::strtod(argv[5], NULL);
  char const * outFile = argv[6];
  
  std::cout << "minEta = " << minEta << std::endl;
  std::cout << "maxEta = " << maxEta << std::endl;
  std::cout << "N = " << N << std::endl;
  
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
  
  std::ofstream file(outFile);
  file.precision(15);
  for(int i = 0; i < N; ++i) {
    file << eta[i] << " " << f[i] << " " << g[i] << " " << h[i] << std::endl;
  }
  file.close();
  
  return 0;
}

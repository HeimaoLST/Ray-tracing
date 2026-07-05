#include "color.h"
#include <iostream>
#include <ostream>
int main() {
  int weight = 256;
  int height = 256;
  std::cout << "P3\n" << weight << ' ' << height << "\n255\n";
  for (int i = 0; i < height; i++) {
    std::clog << "\rRow Remaining: " << height - i << ' ' << std::flush;
    for (int j = 0; j < weight; j++) {

      auto rr = double(j) / (weight - 1);
      auto rg = double(i) / (height - 1);
      auto rb = 0;

      color pixel = color(rr, rg, rb);
      write_pixels(std::cout, pixel);
    }
  }
  std::clog << "Done!\n";
}

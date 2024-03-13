#include <vector>

#include <iostream>
#include <sstream>
#include <string>
template <typename T> int sign(T val) { return (T(0) < val) - (val < T(0)); }

int main() {
  float x0 = 1.0f, x1 = 0.0f, x2 = -1.0f;
  std::vector<float> inputVec = {1.0f, 0.0f, -1.0f};
  std::vector<float> wightVec = {-5.0f, 0.0f, 0.0f};

  float w0 = -5, w1 = 0.0f, w2 = 0.0f;
  float target = 1.0f;
  float learningRate = 1.0f;
  float y = 0.0f;
  float input = 0.0f;
  float output = 0.0f;

  std::ostringstream console;
  for (int i = 0; i < 100; ++i) {
    for (auto &w : wightVec) {
      console << w << "\t";
    }
    console << "\n";
    input = 0.0f;
    for (int i = 0; i < inputVec.size(); ++i) {
      input += inputVec[i] * wightVec[i];
    }
    output = sign(input);
    if ((target - output) > 1e-5) {
      for (int i = 0; i < inputVec.size(); ++i) {
        wightVec[i] += learningRate * (target - output) * inputVec[i];
      }
    } else {
      console << std::endl;
      break;
    }
  }
  std::cout << console.str() << std::endl;
}
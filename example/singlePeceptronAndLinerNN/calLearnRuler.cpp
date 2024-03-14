// In this case,  aim to adjust the wight vector to make output y equal to
// target wight i = wight i + del w-i
// the sign is the activation function
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
// the sign function
template <typename T> int sign(T val) { return (T(0) < val) - (val < T(0)); }

int main() {
  std::vector<float> inputVec = {1.0f, 0.0f, -1.0f};
  std::vector<float> wightVec = {-5.0f, 0.0f, 0.0f};
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
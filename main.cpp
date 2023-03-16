#include <string>
#include <array>
#include "ap_fixed.h"
#include "emulator.h"

int main()
{
  std::string modelName = "GTADModel_v1";
  hls4mlEmulator::ModelLoader loader = hls4mlEmulator::ModelLoader(modelName);
  std::shared_ptr<hls4mlEmulator::Model> model = loader.load_model();

  std::cout << "modelInput = [";
  ap_fixed<18,13> modelInput[57];
  for (int i = 0; i < 57; i++) {
    modelInput[i] = 10.25;
    std::cout << modelInput[i] << ", ";
  }
  std::cout << "]" << std::endl;
  
  std::array<ap_fixed<10,7>,13> modelResult;
  for (int i = 0; i < 13; i++) {
    modelResult[i] = -1;
  }
  ap_ufixed<18,14> modelLoss;

  model->prepare_input(modelInput);
  model->predict();

  auto pairResult = std::make_pair(modelResult, modelLoss);

  std::cout << "pairResult before read = [";
  for (int i = 0; i < 13; i++){
    std::cout << pairResult.first[i] << ", ";
  }
  std::cout << "], " << pairResult.second << std::endl;
  
  model->read_result(&pairResult);

  std::cout << "pairResult after read = [";
  for (int i = 0; i < 13; i++){
    std::cout << pairResult.first[i] << ", ";
  }
  std::cout << "], " << pairResult.second << std::endl;

  return 0;
}
 

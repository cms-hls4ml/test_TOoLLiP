#include <string>
#include <array>
#include <stdlib.h>
#include "ap_fixed.h"
#include "emulator.h"

int main()
{
  std::string modelName = "TOoLLiP_v1";
  hls4mlEmulator::ModelLoader loader = hls4mlEmulator::ModelLoader(modelName);
  std::shared_ptr<hls4mlEmulator::Model> model = loader.load_model();

  std::cout << "modelInput = [";
  ap_fixed<16,6> modelInput[140];
  for (int i = 0; i < 140; i++) {
    modelInput[i] = (rand() % 100) / 10.;
    std::cout << modelInput[i] << ", ";
  }
  std::cout << "]" << std::endl;
  
  ap_fixed<16,6> modelResult[1];
  for (int i = 0; i < 1; i++) {
    modelResult[i] = -1;
  }

  model->prepare_input(modelInput);
  model->predict();

  std::cout << "modelResult before read = [";
  for (int i = 0; i < 1; i++){
    std::cout << modelResult[i] << ", ";
  }
  std::cout << "]" << std::endl;

  std::cout << "reading result..." << std::endl;
  model->read_result(modelResult);
  std::cout << "DONE..." << std::endl;

  std::cout << "modelResult after read = [";
  for (int i = 0; i < 1; i++){
    std::cout << modelResult[i] << ", ";
  }
  std::cout << "]" << std::endl;

  return 0;
}
 

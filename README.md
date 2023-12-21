# test_TOoLLiP

```bash
git clone git@github.com:Xilinx/HLS_arbitrary_Precision_Types hls
git clone git@github.com:cms-hls4ml/hls4mlEmulatorExtras
git clone git@github.com:cms-hls4ml/TOoLLiP
git clone git@github.com:cms-hls4ml/test_TOoLLiP

cd hls4mlEmualtorExtras
make
mkdir lib64
mv libemulator_interface.so lib64
cd -

cd TOoLLiP
make
cd -

cd test_TOoLLiP
export LD_LIBRARY_PATH=./:../hls4mlEmulatorExtras/lib64
make
./main.o
```

# test_L1METML

```bash
git clone git@github.com:Xilinx/HLS_arbitrary_Precision_Types hls
git clone git@github.com:cms-hls4ml/hls4mlEmulatorExtras
git clone git@github.com:cms-hls4ml/L1METML
git clone git@github.com:cms-hls4ml/test_L1METML

cd hls4mlEmualtorExtras
make
mkdir lib64
mv libemulator_interface.so lib64
cd -

cd L1METML
make
cd -

cd test_L1METML
export LD_LIBRARY_PATH=./:../hls4mlEmulatorExtras/lib64
make
./main.o
```

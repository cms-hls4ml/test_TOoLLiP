# test_AXOL1TL

Log in to `lxplus8.cern.ch` then do

```bash
git clone git@github.com:jmduarte/test_AXOL1TL --recurse-submodules
export LD_LIBRARY_PATH=./:/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/hls4mlEmulatorExtras/1.1.1-6933fcc7cdb4cdd5a649bd6579151d1b/lib64
make
./main.o
```

Example for libspatialindex
===========================

I had an absolute 'mare trying to find a basic quick-start guide for the libspatialindex library.

The example code in the wiki seems to mix up the `C` api and the `C++` api, and gave me horrible
memory errors...

My advice is to try and use a better altnative library (Boost, CGAL.) Failing that, a simple
example example can be found in `main.cc`


Build and run the example
-------------------------
```
mkdir build
cd build
cmake ..
make
./example
```

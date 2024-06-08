# libsodium with C++

## Step 1: installation

1. download a [tarball of libsodium](https://download.libsodium.org/libsodium/releases/LATEST.tar.gz). If you are using Windows, you may need to download a different version of libsodium for windows [from here](https://download.libsodium.org/libsodium/releases/).
2. Extract the tarball into a directory, e.g. `<path/to/this/directory>/libsodium`
3. Build and install the libsodium library using:
```bash
cd libsodium
./configure
make
sudo make install
```
4. After installation, run `sudo ldconfig` to load the installed library.

On windows and some architectures, you may need to provide some different flags. If the above does not work for you,
check [this link](https://doc.libsodium.org/installation).

## Step 2: implementation

Write you implementation in `hw.cc`. You can compile it into an executable using `make`.
This will produce an executable that you can run using `./hw`.

## Step 3: answer the questions on our course website!

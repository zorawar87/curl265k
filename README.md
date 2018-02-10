# curl265k

## set up
Get the curl tarball from [here](https://curl.haxx.se/download.html).
This program uses v7.58, which can be pulled through
```bash
wget https://curl.haxx.se/download/curl-7.58.0.tar.gz
tar -xzf curl-7.58.0.tar.gz
```

Then, in accordance with [these instructions](https://curl.haxx.se/docs/install.html), install libcurl.

For Linux, do:
```bash
./configure
make
make test
sudo make install
```

Per the default configuration, libcurl will be installed in `/usr/local`.
To install elsewhere, specify `./configure --prefix=/path/to/curl/tree`.
Depending on the path chosen, `make install` may not need sudo privileges.



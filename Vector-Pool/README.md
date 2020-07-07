# Setting up Check

### A Unit Testing Framework for C

---

For setting up the [Check Framework](https://libcheck.github.io/check/) I would recommend installing it from source no matter which platform you are one. At the time of writing this I am using Ubuntu 20.04 LTS and the version of Check available via Aptitude is quite out of sync with the latest version of the framework. Even some of the features of the framework used in this project also require newer/higher versions of check as compared to what is available via Aptitude so I [compiled and installed it from source](https://libcheck.github.io/check/web/install.html#linuxsource) and recommend every to do so as well.

One thing I would recommend is that after running the three commands mentioned on the web-page for [compiling and installing from source](https://libcheck.github.io/check/web/install.html#linuxsource) also run the following command to make sure that the `check.h` header file is available for your project to use.

```bash
$ sudo ldconfig
```

So all the *four commands* you need to run in the downloaded check folder, to compile and install the framework from source are:

```bash
$ ./configure
$ make
$ make check
$ sudo make install
$ sudo ldconfig
```



**Note:** I also recommend to the compiler flag `-lsubunit` while linking the test object file to all your other files. I did not see this mentioned anywhere except on a GitHub issue on the project, but it solved all the linking issues for me.


# Virtual Machine

In this project I am working on creating a virtual machine which supports:

1. A extensible set of instructions
2. Registers
3. Stack

At the moment there are features to emulated features such as virtual memory, caching or paging or any mapping techniques but I am working on adding them soon.



## Note

At the moment this VM is not targeting any specific computer architecture, but going forward I will try aligning the VM to support the ARM architecture.

## How to Run the Project

1. Enter the same folder as the Makefile and type the following instruction into the command line and ignore the output of the command, unless the output text is in **RED**,  in which case it means something went wrong.

   1. ```bash
      	make
      ```

2. Run the file `main_vm` in the `bin` folder using the command

   1. ```bash
      ./main_vm
      ```



## Reference Links

[Website I followed to create the initial VM](https://felixangell.com/blogs/virtual-machine-in-c)
# Sample code for the blog article *Test-driving the MCP2515 CAN Controller (Part 3)*
[Link to blog](http://steffen.ronalter.de/2017/11/12/test-driving-the-mcp2515-can-controller-part-3/)

To build the project (AVR libc is a prerequisite):
```
$ make all
```

To flash onto an ATmega32 (using avrdude with USBtiny programmer):
```
$ make program
```

The default fuse settings should be OK.

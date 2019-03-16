A lot of research was done on this topic, since the keyboard lightning on my laptop was not configurable. But now it is.
"Light" folder is the module, based on the ioctl and keyboard interrupt handling. A little bit buggy,since we need to find a way to get the handles for ioctl to work.
"Light2" folder is the userspace application, which is based on the hidapi library. 
The serial number and the manufacturing number that is passed on to it, can be got using lsusb command (detects the keyboard usb port number)

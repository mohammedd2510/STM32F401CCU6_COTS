import struct
HexFile = open('STM32F401CCU6_COTS.bin', 'rb')
for i in range(100):
   val1= HexFile.read(1)
   print(val1)



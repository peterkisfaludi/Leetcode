import math
class Solution:
    def reverseBits(self, n: int) -> int:
        mask=1
        result=0
        numbits=32
        for i in range(numbits):
            bit_bool = (n & mask) != 0
            bit = 0
            if bit_bool: bit=1
            result <<= 1
            result |= bit
            mask <<= 1
            #print(mask)
        return result

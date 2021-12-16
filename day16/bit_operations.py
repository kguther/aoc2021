from bitstring import BitArray


def bits_to_int(bits):
    return int(bits, 2)


def bitstream_from_hex(hex_string):
    bit_array = BitArray(hex=hex_string)
    return bit_array.bin

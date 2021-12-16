from stream_parser import StreamParser
from bit_operations import bitstream_from_hex


def read_message_string(filename):
    with open(filename, "r") as bt:
        content = bt.readline()
    return content


def main():
    hex_message = read_message_string("input")
    bitstream = bitstream_from_hex(hex_message)

    parser = StreamParser()
    package = parser.parse_package(bitstream)

    print(f"Accumulated version is {package.effective_version}")
    print(f"Value of the package is {package.get_value()}")

if __name__ == "__main__":
    main()

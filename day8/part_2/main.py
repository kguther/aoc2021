from parser import Parser
from decoder import Decoder


def main():
    parser = Parser()
    displays = parser.read_file("input")
    result = 0
    for display in displays:
        decoder = Decoder(display.digits)
        decoded_output = int("".join([str(decoder.decode(digit)) for digit in display.output]))
        result += decoded_output
    print(f"Total sum is {result}")


if __name__ == "__main__":
    main()
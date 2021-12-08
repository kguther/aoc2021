from parser import Parser


def main():
    parser = Parser()
    displays = parser.read_file("input")
    count = 0
    for display in displays:
        for digit in display.output:
            if len(digit) in [2, 3, 4, 7]:
                count += 1

    print(f"Number of digits with unique number of lines: {count}")

if __name__ == "__main__":
    main()
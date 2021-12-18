from parser import parse_tree_number
from tree_number import print_tree_number


def parse_input(filename):
    with open(filename, "r") as sn:
        return [parse_tree_number(line) for line in sn]

def main():
    input_numbers = parse_input("input")
    added_number = input_numbers[0]
    for number in input_numbers[1:]:
        added_number += number
    print(f"Final magnitude is {added_number.magnitude()}")

    largest_magnitude = 0
    for number_a in input_numbers:
        for number_b in input_numbers:
            if number_a != number_b:
                sum_magnitude = (number_a + number_b).magnitude()
                if sum_magnitude > largest_magnitude:
                    largest_magnitude = sum_magnitude

    print(f"Largest sum magnitude is {largest_magnitude}")

if __name__ == "__main__":
    main()
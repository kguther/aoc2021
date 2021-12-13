from dot_input import DotInput
from dot_sheet import DotSheet
from instruction_input import get_instructions


def main():
    instructions = get_instructions("input_instructions")
    dots = DotInput.from_file("input")
    sheet = DotSheet(dots)

    for instruction in instructions:
        sheet.fold(instruction)
        print(f"Number of dots after fold {sheet.number_of_dots()}")

    print(f"Folded sheet is now \n {sheet.output()}")


if __name__ == "__main__":
    main()
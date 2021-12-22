from cuboid import Cuboid
from reactor import Reactor


def read_instructions(filename):
    instructions = []
    with open(filename, "r") as it:
        for line in it:
            instructions.append(Cuboid.from_string(line))
    return instructions


def main():
    instructions = read_instructions("input")
    reactor = Reactor()

    for instruction in instructions:
        reactor.step(instruction)

    print(f"Now turned on {reactor.count_cubes_switched_on()} cubes")


if __name__ == "__main__":
    main()
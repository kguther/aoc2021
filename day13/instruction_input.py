from dataclasses import dataclass


@dataclass(frozen=True)
class FoldInstruction:
    axis: str
    position: int


def get_instructions(filename):
    instructions = []
    with open(filename, "r") as ist:
        for line in ist:
            parts = line.split("=")
            instructions.append(FoldInstruction(axis=parts[0][-1], position=int(parts[1])))

    return instructions
from analyzer import Analyzer
from polymer_builder import PolymerBuilder
from rule import RuleSet

INPUT_FILE = "input"

def read_input(filename):
    with open(filename, "r") as rl:
        lines = [line.rstrip() for line in rl.readlines()]
        initial_polymer = lines[0]
        rule_set = RuleSet.from_rule_list(lines[2:])

    return initial_polymer, rule_set

def main():
    polymer, rule_set = read_input("input")
    builder = PolymerBuilder(rule_set)

    for i in range(10):
        polymer = builder.iterate(polymer)

    analyzer = Analyzer()
    print(f"Occurence diff is now {analyzer.occurrence_diff(polymer)}")

if __name__ == "__main__":
    main()

from polymer import Polymer
from part_2.analyzer import Analyzer
from rule_iterator import RuleIterator
from rule import RuleSet

INPUT_FILE = "input"


def read_input(filename):
    with open(filename, "r") as rl:
        lines = [line.rstrip() for line in rl.readlines()]
        initial_polymer = Polymer.from_string(lines[0])
        analyzer = Analyzer([lines[0][0], lines[0][-1]])
        rule_set = RuleSet.from_rule_list(lines[2:])

    return initial_polymer, rule_set, analyzer


def main():
    polymer, rule_set, analyzer = read_input("input")
    iterator = RuleIterator(rule_set)

    for i in range(40):
        polymer = iterator.iterate(polymer)

    print(f"Occurence diff is now {analyzer.occurrence_diff(polymer)}")


if __name__ == "__main__":
    main()

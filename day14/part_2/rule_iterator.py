from polymer import Polymer


class RuleIterator:
    def __init__(self, rules):
        self._rules = rules

    def iterate(self, polymer):
        new_polymer = Polymer()
        for pair, count in polymer.pairs.items():
            new_pairs = self._rules.get_rule(pair)
            for new_pair in new_pairs:
                new_polymer.add_pair(new_pair, count)

        return new_polymer

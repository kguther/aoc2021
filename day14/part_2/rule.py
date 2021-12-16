from collections import defaultdict
from dataclasses import dataclass
from typing import List, Dict


@dataclass(frozen=True)
class RuleSet:
    _rules: Dict[str, List[str]]

    def get_rule(self, pair):
        return self._rules.get(pair, [])

    @classmethod
    def from_rule_list(cls, rule_list):
        rules = defaultdict(list)
        for line in rule_list:
            parts = line.split("->")
            pair = parts[0].rstrip()
            added = parts[1].lstrip()
            new_pairs = [
                pair[0]+added,
                added+pair[1]
            ]
            rules[pair] = new_pairs
        return RuleSet(rules)

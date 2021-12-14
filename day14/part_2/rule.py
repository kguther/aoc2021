from collections import defaultdict
from dataclasses import dataclass
from typing import Dict, List


@dataclass(frozen=True)
class Target:
    required: str
    add: str


@dataclass(frozen=True)
class RuleSet:
    rules: Dict[str, List[Target]]

    def get_targets(self, element):
        return self.rules.get(element, [])

    @classmethod
    def from_rule_list(cls, rule_list):
        rules = defaultdict(list)
        for line in rule_list:
            parts = line.split("->")
            element = parts[0][0]
            required = parts[0][1]
            added = parts[1].lstrip()
            rules[element].append(Target(
                required=required,
                add=added
            ))
        return RuleSet(rules)

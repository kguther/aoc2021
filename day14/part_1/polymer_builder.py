class PolymerBuilder:
    def __init__(self, rules):
        self._rules = rules

    def iterate(self, base_polymer):
        new_polymer = ""
        for i in range(len(base_polymer)-1):
            element = base_polymer[i]
            next_element = base_polymer[i+1]
            new_polymer += element
            new_polymer += self._check_rules(element, next_element)

        new_polymer += base_polymer[-1]
        return new_polymer

    def _check_rules(self, element, next_element):
        additions = ""
        rules = self._rules.get_targets(element)
        for rule in rules:
            if rule.required == next_element:
                additions += rule.add
        return additions

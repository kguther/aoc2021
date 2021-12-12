class SyntaxChecker:
    MARKERS = {")": "(", "]": "[", "}": "{", ">": "<"}
    SCORE = {"(": 1, "[": 2, "{": 3, "<": 4}

    def get_line_score(self, line):
        stack = []
        for char in line:
            if char in self.MARKERS.values():
                stack.append(char)
            elif char in self.MARKERS.keys():
                if len(stack) == 0 or stack[-1] != self.MARKERS[char]:
                    return 0
                else:
                    stack.pop()
        return self._get_stack_score(stack)

    def _get_stack_score(self, stack):
        score = 0
        for char in stack[::-1]:
            score = 5*score + self.SCORE[char]
        return score
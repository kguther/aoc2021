class SyntaxChecker:
    MARKERS = {")": "(", "]": "[", "}": "{", ">": "<"}
    SCORE = {")": 3, "]": 57, "}": 1197, ">": 25137}

    def get_line_score(self, line):
        stack = []
        for char in line:
            if char in self.MARKERS.values():
                stack.append(char)
            elif char in self.MARKERS.keys():
                if len(stack) == 0 or stack[-1] != self.MARKERS[char]:
                    return self.SCORE[char]
                else:
                    stack.pop()
        return 0

def get_score_of_file(filename):
    checker = SyntaxChecker()
    with open(filename, "r") as sc:
        score = 0
        for line in sc:
            score += checker.get_line_score(line)

    return score

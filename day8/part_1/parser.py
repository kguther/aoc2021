from display import Display


class Parser:
    def read_file(self, filename):
        displays = []
        with open(filename, "r") as dp:
            for line in dp:
                displays.append(self._read_line(line.rstrip()))

        return displays

    def _read_line(self, line):
        parts = line.split("|")
        digits = parts[0].split(" ")
        output = parts[1].split(" ")
        digits.pop()
        output.pop(0)
        return Display(digits, output)
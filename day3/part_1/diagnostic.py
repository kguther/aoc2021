import numpy as np

def split_bitstring(bitstring):
    return np.array([int(char) for char in bitstring])

class DiagnosticStream:
    def __init__(self, data):
        self._data = data

    @classmethod
    def from_file(cls, filename):
        data = []
        with open(filename, "r") as dt:
            for line in dt:
                data.append(line.rstrip())

        return DiagnosticStream(data)

    @property
    def gamma_rate(self):
        counts = split_bitstring(self._data[0])
        for row in self._data[1:]:
            counts += split_bitstring(row)

        bin_string = ""
        for count in counts:
            if count > len(self._data)/2:
                bin_string += "1"
            else:
                bin_string += "0"

        return int(bin_string, 2)

    @property
    def epsilon_rate(self):
        return (1 << len(self._data[0])) - 1 - self.gamma_rate

    @property
    def power_consumption(self):
        return self.gamma_rate * self.epsilon_rate
                    
def main():
    stream = DiagnosticStream.from_file("input")
    print(f"Gamma rate is {stream.gamma_rate}")
    print(f"Epsilon rate is {stream.epsilon_rate}")
    print(f"Power consumption is {stream.power_consumption}")

if __name__ == "__main__":
    main()

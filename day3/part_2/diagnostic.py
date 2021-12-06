from bitarray import bitarray
from bitarray.util import ba2int

class DiagnosticStream:
    def __init__(self, data):
        self._data = data

    @classmethod
    def from_file(cls, filename):
        data = []
        with open(filename, "r") as dt:
            for line in dt:
                data.append(bitarray(line))

        return DiagnosticStream(data)

    @property
    def oxygen_generator_rating(self):
        def iterative_filter(data, pos):
            bit = _get_most_common_bit(data, pos)
            return _filter_criterion(data, bit, pos)

        return _iterative_criterion(self._data, iterative_filter)

    @property
    def co2_scrubber_rating(self):
        def iterative_filter(data, pos):
            bit = _get_least_common_bit(data, pos)
            return _filter_criterion(data, bit, pos)

        return _iterative_criterion(self._data, iterative_filter)

    @property
    def life_support_rating(self):
        return self.oxygen_generator_rating * self.co2_scrubber_rating
        
    
def _iterative_criterion(data, iterative_filter):
    filtered_data = data
    pos = 0
    while len(filtered_data) > 1:
        filtered_data = iterative_filter(filtered_data, pos)
        pos += 1

    return ba2int(filtered_data[0])

def _filter_criterion(data, bit, pos):
    return [value for value in data if value[pos] == bit]

def _get_least_common_bit(data, pos):
    return not _get_most_common_bit(data, pos)

def _get_most_common_bit(data, pos):
    count = 0
    for val in data:
        if val[pos]:
            count += 1

    if count >= len(data) / 2:
        return True
    return False
    
                    
def main():
    stream = DiagnosticStream.from_file("input")
    print(f"Life support rating is {stream.life_support_rating}")

if __name__ == "__main__":
    main()

class Decoder:
    def __init__(self, digits):
        for digit in digits:
            if len(digit) == 2:
                one = digit
            if len(digit) == 4:
                four = digit
        assert one
        assert four
        self._cf = list(one)
        self._bd = [char for char in four if char not in one]

    def decode(self, digit):
        if len(digit) == 2:
            return 1
        if len(digit) == 3:
            return 7
        if len(digit) == 4:
            return 4
        if len(digit) == 7:
            return 8

        cf_elements = self._get_number_of_contained_chars(digit, self._cf)
        bd_elements = self._get_number_of_contained_chars(digit, self._bd)
        if len(digit) == 5:
            if cf_elements == 1:
                if bd_elements == 1:
                    return 2
                if bd_elements == 2:
                    return 5
            if cf_elements == 2 and bd_elements == 1:
                return 3

        if len(digit) == 6:
            if cf_elements == 2:
                if bd_elements == 1:
                    return 0
                if bd_elements == 2:
                    return 9
            if cf_elements == 1 and bd_elements == 2:
                return 6

        raise ValueError("Digit not decodable")

    def _get_number_of_contained_chars(self, digit, ref):
        return len([char for char in ref if char in digit])
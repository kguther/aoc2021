class FishNumber:
    def __init__(self, left, right):
        self._pair = [left, right]

    def explode(self):
        pass

    def reduce(self):
        for number in self._pair:

    def check_explosion(self, nesting_counter):
        nested_numbers = self.contained_fish_numbers()
        if nested_numbers:
            if nesting_counter == 3:
                self.explode()
            else:
                nested_numbers[0].check_explosion(nesting_counter+1)



    def contained_fish_numbers(self):
        return [number for number in self._pair if isinstance(FishNumber, number)]

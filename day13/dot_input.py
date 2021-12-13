class DotInput:
    def __init__(self, coordinates):
        self.coordinates = coordinates

    def _size_of_axis(self, axis_index):
        size = 0
        for dot in self.coordinates:
            dot_position = dot[axis_index]
            if dot_position > size:
                size = dot_position

        return size+1

    def size_x(self):
        return self._size_of_axis(0)

    def size_y(self):
        return self._size_of_axis(1)

    @classmethod
    def from_file(cls, filename):
        coordinates = []
        with open(filename, "r") as dt:
            for line in dt:
                coords = line.split(",")
                coordinates.append(list(map(int, coords)))

        return DotInput(coordinates)

from vent_line import VentLine, Point


def get_grid_corner(lines):
    corner = Point(x=0,y=0)
    for line in lines:
        corner = Point(
            x=max([corner.x, line.end.x, line.start.x]),
            y=max([corner.y, line.end.y, line.start.y]),
        )
    return corner


class VentGrid:
    def __init__(self, lines):
        self._lines = lines
        self._grid_corner = get_grid_corner(lines)

    @property
    def intersections(self):
        intersections = []
        for x in range(self._grid_corner.x+1):
            print(f"Iterating over point {x}/{self._grid_corner.x}")
            for y in range(self._grid_corner.y+1):
                point = Point(x=x, y=y)
                if self.count_vents(point) > 1:
                    intersections.append(point)

        return len(intersections)

    def count_vents(self, point):
        vents = 0
        for vent_line in self._lines:
            if vent_line.contains(point):
                vents += 1

        return vents


def read_vent_grid(filename):
    lines = []
    with open(filename, "r") as vg:
        for line in vg:
            vent_line = VentLine.from_string(line)
            if vent_line:
                lines.append(vent_line)

    return VentGrid(lines)

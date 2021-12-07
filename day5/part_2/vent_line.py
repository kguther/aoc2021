from dataclasses import dataclass


@dataclass(frozen=True)
class Point:
    x: int
    y: int

    @classmethod
    def from_string(cls, string):
        parts = string.split(",")
        return Point(x=int(parts[0]), y=int(parts[1]))

def int_is_between(x1, x2, val):
    return min(x1,x2) <= val <= max(x1,x2)

class VentLine:
    def __init__(self, start, end):
        self.start = start
        self.end = end

    def contains(self, point):
        c_a = (self.end.x - self.start.x) * (point.y - self.start.y)
        c_b = (point.x - self.start.x) * (self.end.y - self.start.y)
        collinear = c_a == c_b
        on_segment = (
            int_is_between(self.start.x, self.end.x, point.x) if self.start.x != self.end.x else (int_is_between(self.start.y, self.end.y, point.y) and self.end.x == point.x)
        )
        return collinear and on_segment

    @classmethod
    def from_string(cls, string):
        parts = string.split(" -> ")
        start = Point.from_string(parts[0])
        end = Point.from_string(parts[1])
        return VentLine(start, end)

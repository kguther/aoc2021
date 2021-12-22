from dataclasses import dataclass
from typing import List, Tuple


@dataclass
class Cuboid:
    ranges: List[Tuple[int, int]]
    value: int

    @property
    def volume(self):
        vol = 1
        for range in self.ranges:
            vol *= (range[1] - range[0] + 1)

        return vol

    @classmethod
    def from_string(cls, string):
        if string.startswith("on"):
            value = 1
        else:
            value = 0
        range_part = string.split(" ")[1]
        range_parts = range_part.split(",")
        ranges = []
        for range_string in range_parts:
            vals_part = range_string.split("=")
            bounds = vals_part[1].split("..")
            ranges.append((int(bounds[0]), int(bounds[1])))

        return Cuboid(ranges=ranges, value=value)

    def intersection(self, other_cube):
        new_ranges = [interval_intersect(self.ranges[i], other_cube.ranges[i]) for i in range(len(self.ranges))]
        if None in new_ranges:
            return None

        intersect_value = -other_cube.value
        return Cuboid(ranges=new_ranges, value=intersect_value)


def interval_intersect(first, second):
    upper = min(first[1], second[1])
    lower = max(first[0], second[0])
    if lower <= upper:
        return lower, upper
    return None
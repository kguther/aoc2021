from dataclasses import dataclass

SCAN_WINDOW = range(-1, 2)


@dataclass(frozen=True)
class Point:
    x: int
    y: int

    def adjacents(self):
        points = []
        for y in SCAN_WINDOW:
            for x in SCAN_WINDOW:
                points.append(Point(self.x + x, self.y + y))
        return points


class Image:
    def __init__(self, pixels, background):
        self._pixels = set(pixels)
        self._background = background
        self._marker = "1" if self._background == "0" else "0"

    def image_area(self):
        return {point for pixel in self._pixels for point in pixel.adjacents()}

    def get_pixel(self, point):
        if point in self._pixels:
            return self._marker
        return self._background

    def background_mapper(self):
        if self._background == "0":
            return 0
        return -1

    def num_pixels(self):
        return len(self._pixels)

    def print(self):
        x_values = [point.x for point in self._pixels]
        y_values = [point.y for point in self._pixels]
        for y in range(min(y_values)-1, max(y_values) + 2):
            output_string = ""
            for x in range(min(x_values)-1, max(x_values) + 2):
                output_string += self.get_pixel(Point(x, y)).replace(self._marker, "#").replace(self._background, ".")

            print(output_string)

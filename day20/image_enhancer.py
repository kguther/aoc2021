from image import Image


class ImageEnhancer:
    def __init__(self, bit_map):
        self._bit_map = bit_map

    def map_image(self, image):
        pixels = []
        i = 0
        area = image.image_area()
        new_background = self._bit_map[image.background_mapper()]
        for point in area:
            mapped_pixel = self.map_pixel(image, point)
            if mapped_pixel != new_background:
                pixels.append(point)

        return Image(pixels, new_background)

    def map_pixel(self, image, pixel_pos):
        value = ""
        for point in pixel_pos.adjacents():
            value += image.get_pixel(point)

        map_index = int(value, 2)
        return self._bit_map[map_index]

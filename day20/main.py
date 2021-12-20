from image_enhancer import ImageEnhancer
from image import Point, Image


def parse_input(filename):
    with open(filename, "r") as px:
        bit_map = px.readline().rstrip().replace("#", "1").replace(".", "0")
        px.readline()
        pixels = []
        line = px.readline().rstrip()
        row = 0
        while line:
            for column in range(len(line)):
                if line[column] == "#":
                    pixels.append(Point(column, row))
            line = px.readline().rstrip()
            row += 1

    return bit_map, pixels


def main():
    bit_map, pixels = parse_input("input")
    enhancer = ImageEnhancer(bit_map)
    image = Image(pixels, "0")
    for i in range(50):
        print(f"Image has {image.num_pixels()} pixels")
        image = enhancer.map_image(image)
    print(f"Image has {image.num_pixels()} pixels")


if __name__ == "__main__":
    main()

class Reactor:
    def __init__(self):
        self._cuboids = []

    def step(self, cuboid):
        intersections = []
        for other_cuboid in self._cuboids:
            intersect = cuboid.intersection(other_cuboid)
            if intersect:
                intersections.append(intersect)
        self._cuboids += intersections
        self._cuboids.append(cuboid)

    def count_cubes_switched_on(self):
        return sum(cuboid.value * cuboid.volume for cuboid in self._cuboids)





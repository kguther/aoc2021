from vent_grid import read_vent_grid


def main():
    vent_grid = read_vent_grid("input")
    print(f"Grid has {vent_grid.intersections} intersections")

if __name__ == "__main__":
    main()

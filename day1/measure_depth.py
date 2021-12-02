import numpy as np

def read_depths(file):
    depths = []
    with open(file, "r") as dp:
        for line in dp:
            depths.append(int(line))

    return np.array(depths)

def get_binned_depths(depths):
    return depths[:-2] + depths[1:-1] + depths[2:]

def get_num_increases(depths):
    diffs = np.diff(depths)    
    increases = [delta > 0 for delta in diffs]
    return increases.count(True)

def main():
    depths = read_depths("input")
    binned_depths = get_binned_depths(depths)
    num_increases = get_num_increases(binned_depths)
    print(f"Depth increases {num_increases} times")


if __name__ == "__main__":
    main()

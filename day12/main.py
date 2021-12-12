from path import Path
from connection import connections_from_file
from path_list import PathList
from path_mapper import PathMapper, START_CAVE
from revisitor_conditions import revisitor_condition_part_1, revisitor_condition_part_2


def get_number_of_connections(revisitor_condition):
    connections = connections_from_file("input")
    mapper = PathMapper(connections, revisitor_condition)

    paths = PathList()
    paths.add_path(Path([START_CAVE]))
    while paths.not_empty():
        paths = mapper.expand_paths(paths)

    print(f"There are a total of {len(mapper.possible_paths)} paths")


def main():
    print("For part 1:")
    get_number_of_connections(revisitor_condition_part_1)
    print("For part 2:")
    get_number_of_connections(revisitor_condition_part_2)


if __name__ == "__main__":
    main()

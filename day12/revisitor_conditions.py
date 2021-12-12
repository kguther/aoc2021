from path_mapper import START_CAVE, END_CAVE


def revisitor_condition_part_1(connection, path):
    return connection.large_target() or connection.target not in path.caves


def revisitor_condition_part_2(connection, path):
    return connection.large_target() or connection.target not in path.caves or _small_revisit_allowed(connection, path)


def _small_revisit_allowed(connection, path):
    return (not path.small_revisit and connection.target not in [START_CAVE, END_CAVE])
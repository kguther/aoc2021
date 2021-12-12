from dataclasses import dataclass


@dataclass(frozen=True)
class Connection:
    origin: str
    target: str

    def large_target(self):
        return self.target.isupper()


def connections_from_file(filename):
    connections = []
    with open(filename, "r") as ct:
        for line in ct:
            parts = line.rstrip().split("-")
            connections.append(Connection(
                origin=parts[0],
                target=parts[1]
            ))
            connections.append(Connection(
                origin=parts[1],
                target=parts[0]
            ))
    return connections
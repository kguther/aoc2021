from abc import abstractmethod, ABC
from dataclasses import dataclass
from functools import reduce
from operator import mul
from typing import List


@dataclass
class Package(ABC):
    bit_count: int
    version: int
    type_id: int

    @property
    def effective_version(self):
        return self.version

    @abstractmethod
    def get_value(self):
        ...


@dataclass
class ValuePackage(Package):
    value: int

    def get_value(self):
        return self.value


@dataclass
class OperatorPackage(Package):
    sub_packages: List[Package]

    def __post_init__(self):
        if self.type_id > 4 and len(self.sub_packages) != 2:
            raise ValueError("Comparison type packages need exactly two sub-packages")

    @property
    def effective_version(self):
        return self.version + sum(sub_package.effective_version for sub_package in self.sub_packages)

    def _value_iterator(self):
        return (sub_package.get_value() for sub_package in self.sub_packages)

    def get_value(self):
        if self.type_id == 0:
            return sum(self._value_iterator())
        if self.type_id == 1:
            return reduce(mul, self._value_iterator(), 1)
        if self.type_id == 2:
            return min(self._value_iterator())
        if self.type_id == 3:
            return max(self._value_iterator())
        if self.type_id == 5:
            return int(self.sub_packages[0].get_value() > self.sub_packages[1].get_value())
        if self.type_id == 6:
            return int(self.sub_packages[0].get_value() < self.sub_packages[1].get_value())
        if self.type_id == 7:
            return int(self.sub_packages[0].get_value() == self.sub_packages[1].get_value())


def total_package_bit_count(packages):
    return sum(package.bit_count for package in packages)
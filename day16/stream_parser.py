from bit_operations import bits_to_int
from package import ValuePackage, OperatorPackage, total_package_bit_count

GLOBAL_HEADER_BIT_COUNT = 6
TYPE_0_SUBPACKAGE_HEADER_BIT_COUNT = 15
TYPE_1_SUBPACKAGE_HEADER_BIT_COUNT = 11

class StreamParser:
    def parse_package(self, bitstream):
        version = bits_to_int(bitstream[:3])
        type_id = bits_to_int(bitstream[3:6])
        if type_id == 4:
            value_bit_count, package_value = self.parse_package_value(bitstream[6:])
            bit_count = GLOBAL_HEADER_BIT_COUNT + value_bit_count
            return ValuePackage(version=version, type_id=type_id, value=package_value, bit_count=bit_count)
        else:
            operator_header_bit_count, sub_packages = self.parse_operator_package_content(bitstream[6:])
            bit_count = GLOBAL_HEADER_BIT_COUNT + operator_header_bit_count + total_package_bit_count(sub_packages)
            return OperatorPackage(version=version, type_id=type_id, sub_packages=sub_packages, bit_count=bit_count)

    def parse_package_value(self, bitstream):
        value_bits = ''
        read_package = True
        start = 0
        while read_package:
            end = start + 5
            next_package = bitstream[start:end]
            value_bits += next_package[1:]
            read_package = next_package[0] == "1"
            start = end
        return start, bits_to_int(value_bits)

    def parse_operator_package_content(self, bitstream):
        length_type_id = bitstream[0]
        if length_type_id == "0":
            operator_header_bit_count = 1 + TYPE_0_SUBPACKAGE_HEADER_BIT_COUNT
            sub_packages_bit_count = bits_to_int(bitstream[1:operator_header_bit_count])

            def sub_package_count_condition(packages):
                return total_package_bit_count(packages) < sub_packages_bit_count
        else:
            operator_header_bit_count = 1 + TYPE_1_SUBPACKAGE_HEADER_BIT_COUNT
            sub_packages_number = bits_to_int(bitstream[1:operator_header_bit_count])

            def sub_package_count_condition(packages):
                return len(packages) < sub_packages_number

        sub_packages = self.parse_sub_packages(bitstream[operator_header_bit_count:], sub_package_count_condition)
        return operator_header_bit_count, sub_packages

    def parse_sub_packages(self, bitstream, sub_package_count_condition):
        sub_packages = []
        next_package = 0
        while sub_package_count_condition(sub_packages):
            package = self.parse_package(bitstream[next_package:])
            sub_packages.append(package)
            next_package += package.bit_count
        return sub_packages




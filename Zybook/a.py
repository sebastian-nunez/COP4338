import math
from abc import ABC, abstractmethod


class Person(ABC):
    def __init__(self, name, age):
        super.__init__()
        self.name = name
        self.age = age

    def get_age(self):
        for i in range(self.age):
            return i + 2

    def __str__(self):
        self.get_age()
        return ""

    @abstractmethod
    def get_name(self):
        pass


def main():
    x = math.ceil(5.3)
    a = Person("Sebastian", x)
    if True:
        pass

    print(a.get_age())


if __name__ == "__main__":
    main()

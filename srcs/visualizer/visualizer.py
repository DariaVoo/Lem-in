import os

from read_graph import read_graph


def main():
    """ Main method """
    namefile = os.path.dirname(os.path.abspath(__file__))
    namefile += "/test"
    read_graph(namefile)


if __name__ == "__main__":
    main()
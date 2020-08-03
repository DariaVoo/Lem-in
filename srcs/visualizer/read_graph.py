import networkx as nx
import matplotlib.pyplot as plt
import re


def read_graph(file_name: str):
    file = open(file_name)
    file = file.readlines()
    graph = nx.Graph()
    index = 0

    # read nodes
    for line in file[1:]:
        if line.find('-') != -1:
            break
        index += 1
        if line.find('#') == -1:
            graph.add_node(line.split(' ')[0])
    print(graph.nodes())

    # read edges
    index += 1
    for line in file[index:]:
        if line == '\n':
            break
        index += 1
        if line.find('#') == -1:
            edge = re.split(r'[-\n]', line)
            graph.add_edge(edge[0], edge[1])
    print(graph.edges())

    nx.draw_networkx(graph,
                     with_labels=False,
                     node_color='red',
                     node_size=10)
    plt.show()

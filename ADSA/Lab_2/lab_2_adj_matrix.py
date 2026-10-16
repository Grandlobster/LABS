import matplotlib.pyplot as plt 
import numpy
import graphx as gx
graph={}
no_vertices=int(input("Enter Number of vertices:"))
for i in range(no_vertices):
    print("Enter the Vertices Name:")
    var=input("Input vertex name:")
    graph[var] = {}
for i in graph.keys():
    conn=[]
    var=int(input("Enter number of edges:"))
    for j in range(var):
        var_2=input("Input Vertex Name").upper()
        graph[i]=conn.append(var_2)

# Adjacency List
for i in range(graph.keys().sum()):
    
'''
no_edges=int(input("Enter Number of edges:"))
if no_edges > ((no_vertices*(no_vertices-1))/2):
    print("Invalid number of edges for given number of vertices re-enter:")
    no_edges=int(input("Enter Number of edges:"))
for i in range(no_vertices):
    var=input("Enter the node name:")
    loop=int(input("Enter the number of edges "))
    '''

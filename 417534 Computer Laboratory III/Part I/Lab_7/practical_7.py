import numpy as np
import random

pool = []

def affinity_cal(gene):
    return np.sum(np.cos(gene))

class Antibody:
    def __init__(self, gene):
        self.gene = gene
        self.affinity = affinity_cal(gene)

    def mutate(self):
        idx = random.randint(0, len(self.gene) - 1)
        self.gene[idx] += random.uniform(-1, 1)
        self.affinity = affinity_cal(self.gene)

    def clone(self):
        cloned = Antibody(self.gene.copy())
        return cloned


def initialize(pool):
    for i in range(50):
        gene = np.array([
            random.randint(1, 24),
            random.randint(1, 18),
            random.randint(1, 18)
        ], dtype=float)
        ab = Antibody(gene)
        pool.append(ab)


def clonal_selection(pool, generations, clone_count, top_n):
    initialize(pool)

    for gen in range(generations):
        pool.sort(key=lambda ab: ab.affinity, reverse=True)

        top = pool[:top_n]

        clones = []
        for ab in top:
            for _ in range(clone_count):
                c = ab.clone()
                c.mutate()
                clones.append(c)

        pool.extend(clones)
        pool.sort(key=lambda ab: ab.affinity, reverse=True)
        pool[:] = pool[:50]

        best = pool[0]
        print(f"gen {gen+1} | best affinity: {best.affinity:.4f} | gene: {best.gene}")

    return pool[0]


clonal_selection(pool, generations=20, clone_count=5, top_n=10)
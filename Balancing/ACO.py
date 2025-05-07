import numpy as np
import random

distances = {
    'a': {'b': 3, 'c': 4, 'd': 7, 'e': 10},
    'b': {'a': 3, 'c': 6, 'd': 8, 'e': 4},
    'c': {'a': 4, 'b': 6, 'd': 5, 'e': 9},
    'd': {'a': 7, 'b': 8, 'c': 5, 'e': 2},
    'e': {'a': 10, 'b': 4, 'c': 9, 'd': 2}
}

nodes = list(distances.keys())
pheromone = { (i, j): 1.0 for i in nodes for j in nodes if i != j}
evaporation_rate = 0.5
alpha = 1.0
beta = 2.0
iterations = 100
num_ants = 10

def calculate_total_distance(tour):
    total_distance = 0
    for i in range(len(tour)-1):
        total_distance += distances[tour[i]][tour[i+1]]
    total_distance += distances[tour[-1]][tour[0]]
    return total_distance

def update_pheromones(tours):
    global pheromone
    for key in pheromone:
        pheromone[key] *= (1 - evaporation_rate)

    for tour in tours:
        tour_distance = calculate_total_distance(tour)
        for i in range(len(tour)-1):
            pheromone[(tour[i], tour[i+1])] += 1.0 / tour_distance
        pheromone[(tour[-1], tour[0])] += 1.0 / tour_distance

def select_next_node(ant, unvisited):
    pheromone_probs = {}
    for node in unvisited:
        pheromone_level = pheromone[(ant[-1], node)]
        distance = distances[ant[-1]][node]
        pheromone_probs[node] = (pheromone_level ** alpha) * ((1.0 / distance) ** beta)
    
    total_prob = sum(pheromone_probs.values())
    pheromone_probs = {node: prob/total_prob for node, prob in pheromone_probs.items()}
    return random.choices(list(pheromone_probs.keys()), list(pheromone_probs.values()))[0]

def aco():
    global pheromone
    best_tour = None
    best_distance = float('inf')
    
    for _ in range(iterations):
        all_tours = []
        
        for _ in range(num_ants):
            ant = [random.choice(nodes)]
            unvisited = set(nodes) - {ant[0]}
            
            while unvisited:
                next_node = select_next_node(ant, unvisited)
                ant.append(next_node)
                unvisited.remove(next_node)
            
            total_distance = calculate_total_distance(ant)
            if total_distance < best_distance:
                best_tour = ant
                best_distance = total_distance
            
            all_tours.append(ant)
        
        update_pheromones(all_tours)
    return best_tour, best_distance

best_tour, best_distance = aco()
print(f"Best tour: {best_tour}")
print(f"Best distance: {best_distance}")

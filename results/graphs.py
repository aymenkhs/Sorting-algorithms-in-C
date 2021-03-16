import os
import math

import pandas as pd
import seaborn as sns
sns.set_theme(style="darkgrid")

import matplotlib
import matplotlib.pyplot as plt

font = {'family' : 'normal',
        'weight' : 'normal',
        'size'   : 22}

matplotlib.rc('font', **font)

sorting_names = {
    "insertion": ("Insertion Sort", "Tri par insertion"),
    "bubbles": ("Bubble Sort", "Tri à bulles"),
    "merge": ("Merge Sort", "Tri par fusion"),
    "quick": ("Quick Sort", "Tri rapide"),
    "heap": ("Heap Sort", "Tri par tas"),
}

def create_hue_data(initial_data, fusion=3):
    hue_data = pd.DataFrame(columns = ["n", "Partie", "temps d'execution"])
    hue_data["n"] = initial_data["num"].tolist() * fusion

    hue_data["temps d'execution"] = initial_data["time_ordered"].tolist() + \
    initial_data["time_inverse"].tolist() + initial_data["time_random"].tolist()
    hue_data["Partie"] = ["données deja ordonner"] * 13 + ["données ordre inverse"] * 13 + ["données aleatoires"] * 13

    return hue_data


def graph_langage(data, type, langage, min_values, max_values):
    hue_data = create_hue_data(data)
    ax =  sns.lineplot(data=hue_data, x="n", y="temps d'execution", hue="Partie")
    ax.legend(["données deja ordonner", "données ordre inverse", "données aleatoires"])
    ax.set_xlim(min_values, max_values)
    ax.set(xlabel='n', ylabel='Temps d\'execution en secondes', title="resultats pour le {}, avec le langage {}".format(sorting_names[type][1], langage))
    plt.tight_layout()
    file_save_path = os.path.join("graphs" ,"{}_{}.png".format(sorting_names[type][0], langage))
    plt.savefig(file_save_path)
    plt.close()


def main():
    for sorting_name in sorting_names:
        # reading data
        c_values = pd.read_csv("{}.csv".format(sorting_names[sorting_name][0]))
        graph_langage(c_values, sorting_name, "C", 50000, 204800000)

if __name__ == '__main__':
    main()

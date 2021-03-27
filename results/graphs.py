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

best_cases = {
    "insertion": lambda x: (6 * x) - 6,
    "bubbles": lambda x: x,
    "merge": lambda x: x,
    "quick": lambda x: x,
    "heap": lambda x: x * (17 * math.log2(x) - 1),
}

worst_cases = {
    "insertion": lambda x: (x * (x - 1)) / 2,
    "bubbles": lambda x: x,
    "merge": lambda x: x,
    "quick": lambda x: x,
    "heap": lambda x: (3 * x * (17 * math.log2(x) - 1)) / 2,
}


def fusion_graphs(type , title , filename, fusion_dict, theorique=False):
    hue_data = pd.DataFrame(columns = ["n", "algorithm", "temps d'execution"])
    hue_data["n"] = fusion_dict["insertion"]["num"].tolist() * 5

    temps_list = []
    for i in fusion_dict:
        temps_list += fusion_dict[i][type].tolist()
    hue_data["temps d'execution"] = temps_list

    hue_data["algorithm"] = ["Tri Par insertion"] * 13 + ["Tri à bulles"] * 13\
        + ["Tri Fusion"] * 13 + ["Tri Rapide"] * 13 + ["Tri Par Tas"] * 13

    ax = sns.lineplot(data=hue_data, x="n", y="temps d'execution", hue="algorithm", style="algorithm")
    ax.legend(["Tri Par insertion", "Tri à bulles", "Tri Fusion", "Tri Rapide", "Tri Par Tas"])

    if theorique:
        ylabel = "nombre d'iterations"
    else:
        ylabel = "Temps d'execution en secondes"

    ax.set(xlabel='n', ylabel=ylabel, title=title)
    plt.tight_layout()
    file_save_path = os.path.join("graphs" ,filename)
    plt.savefig(file_save_path)
    plt.close()


def create_hue_data(initial_data, fusion=3):
    hue_data = pd.DataFrame(columns = ["n", "Partie", "temps d'execution"])
    hue_data["n"] = initial_data["num"].tolist() * fusion

    hue_data["temps d'execution"] = initial_data["time_ordered"].tolist() + \
    initial_data["time_inverse"].tolist() + initial_data["time_random"].tolist()
    hue_data["Partie"] = ["données deja ordonner"] * 13 + ["données ordre inverse"] * 13 + ["données aleatoires"] * 13

    return hue_data


def graph_langage(data, type, langage, min_values=500, max_values=2048000):
    hue_data = create_hue_data(data)
    ax =  sns.lineplot(data=hue_data, x="n", y="temps d'execution", hue="Partie")
    ax.legend(["données deja ordonner", "données ordre inverse", "données aleatoires"])
    ax.set_xlim(min_values, max_values)
    ax.set(xlabel='n', ylabel='Temps d\'execution en secondes', title="resultats pour le {}, avec le langage {}".format(sorting_names[type][1], langage))
    plt.tight_layout()
    file_save_path = os.path.join("graphs" ,"{}_{}.png".format(sorting_names[type][0], langage))
    plt.savefig(file_save_path)
    plt.close()


def graph_function(list_values, type):
    best_case_values = [best_cases[type](value) for value in list_values]
    ax =  sns.lineplot(x=list_values, y=best_case_values)
    ax.legend(["ctm(n)"])
    ax.set(xlabel='n', ylabel='nombre d\'iterations', title='Gm {}'.format(sorting_names[type][1]))
    plt.tight_layout()
    file_save_path = os.path.join("graphs" ,"ctm_{}.png".format(sorting_names[type][0]))
    plt.savefig(file_save_path)
    plt.close()

    worst_case_values = [worst_cases[type](value) for value in list_values]
    ax =  sns.lineplot(x=list_values, y=worst_case_values)
    ax.legend(["ctp(n)"])
    ax.set(xlabel='n', ylabel='nombre d\'iterations', title='Gp {}'.format(sorting_names[type][1]))
    plt.tight_layout()
    file_save_path = os.path.join("graphs" ,"ctp_{}.png".format(sorting_names[type][0]))
    plt.savefig(file_save_path)
    plt.close()


def main():
    c_values = {}
    theorique_values = {}
    for sorting_name in sorting_names:
        # reading data
        c_values[sorting_name] = pd.read_csv("{}.csv".format(sorting_names[sorting_name][0]))
        graph_langage(c_values[sorting_name], sorting_name, "C")
        graph_function(c_values[sorting_name]["num"].tolist(), sorting_name)

        list_values = c_values[sorting_name]["num"].tolist()
        theorique_values[sorting_name] = pd.DataFrame(columns = ["num", "worst_case", "best_case"])
        theorique_values[sorting_name]["num"] = list_values
        theorique_values[sorting_name]["best_case"] = [best_cases[sorting_name](value) for value in list_values]
        theorique_values[sorting_name]["worst_case"] = [worst_cases[sorting_name](value) for value in list_values]


    # ordred values comparaison graph with C langage
    title = "Comparaison des Algorithmes (données deja ordonner) langage C"
    file_name = "comp_ordredTimeC"
    fusion_graphs("time_ordered", title, file_name, c_values)

    # inverse order values comparaison graph with C langage
    title = "Comparaison des Algorithmes (données ordre inverse) langage C"
    file_name = "comp_inverseTimeC"
    fusion_graphs("time_inverse", title, file_name, c_values)

    # ordred values comparaison graph with C langage
    title = "Comparaison des Algorithmes (données aleatoires) langage C"
    file_name = "comp_randomTimeC"
    fusion_graphs("time_ordered", title, file_name, c_values)

    # constructing dictionary

    # best case comparaison graph
    title = "Comparaison des Algorithmes meilleur cas (theorique)"
    file_name = "comp_bestCase"
    fusion_graphs("best_case", title, file_name, theorique_values, theorique=True)

    # worst case comparaison graph
    title = "Comparaison des Algorithmes pire cas (theorique)"
    file_name = "comp_worstCase"
    fusion_graphs("worst_case", title, file_name, theorique_values, theorique=True)

if __name__ == '__main__':
    main()

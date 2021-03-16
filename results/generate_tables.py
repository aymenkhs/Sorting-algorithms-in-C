import pandas as pd
import math
import re

sorting_names = {
    "insertion": ("Insertion Sort", "Tri par insertion"),
    "bubbles": ("Bubble Sort", "Tri à bulles"),
    "merge": ("Merge Sort", "Tri par fusion"),
    "quick": ("Quick Sort", "Tri rapide"),
    "heap": ("Heap Sort", "Tri par tas"),
}

def generate_latex_tabels(data, part, diviser):
    past_cmpt = 0
    string = ""
    for value in diviser:
        string += r"\begin{table}[H]" + "\n\t" + r"\centering" + "\n\t\t" + r"\begin{tabular}{|"
        ls = "l|" * (value+2)
        string += ls
        string += r"}\hline"
        string += "\n"
        string += generate_tabel_elements(data[past_cmpt:value+past_cmpt], part)
        string +="\t"
        string += r"\end{tabular}"
        string +="\n"
        string += r"\end{table}"
        string += "\n\n"
        past_cmpt += value
    return string

def generate_tabel_elements(data, part):
    string = ""
    string += "\tn "
    for i in data.index.tolist():
        n = data.loc[i, "num"]
        string += "& ${}$ ".format(constructing_n(n))
    string += r" \\ \hline"
    string += "\n\tT(n)"
    for i in data.index.tolist():
        string += "& ${}$ ".format(data.loc[i, part])
    string += r" \\ \hline"
    string += "\n"
    return string

def constructing_n(number):
    number = str(number)
    first_digit = number[0]
    second_part = number[1:]
    power = len(number) - 1
    result = first_digit
    if second_part != "":
        match = re.search(r"0+$", second_part[1:3])
        if match == None:
            if power < 2:
                result += second_part[0]
                if second_part[1:3] != "":
                    result += "." + second_part[1:3]
            else:
                result += "." + second_part[:3] + r"*10^" + str(power)
        else:
            match = re.search(r"[1-9]+", second_part[:3])
            if match == None:
                if power < 2:
                    result += "0"
                else:
                    result += r"*10^" + str(power)
            else:
                if power < 2:
                    result += second_part[0]
                    match = re.search(r"0+", second_part[1:3])
                    if second_part[1:3] != "" and match is not None:
                        result += "." + second_part[1:3]
                else:
                    match = re.search(r"([1-9]?0*[1-9]+)", second_part[:3])
                    result += "." + match[0] + r"*10^" + str(power)
    return result


def main():
    file_string = ""
    for sorting_name in sorting_names:
        # reading data
        c_values = pd.read_csv("{}.csv".format(sorting_names[sorting_name][0]))

        file_string += "\n\n\n** {} **".format(sorting_names[sorting_name][0])

        file_string += "\n\n** ordered values **\n\n"
        file_string += generate_latex_tabels(c_values, "time_ordered", (7,6))

        file_string += "\n\n\n** inversed values **\n\n"
        file_string += generate_latex_tabels(c_values, "time_inverse", (7,6))

        file_string += "\n\n\n** random values **\n\n"
        file_string += generate_latex_tabels(c_values, "time_random", (7,6))

    with open("latexTables.LT", "w") as file:
        file.write(file_string)

if __name__ == '__main__':
    main()

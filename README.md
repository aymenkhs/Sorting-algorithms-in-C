An Implementation and comparaison between different sorting techniques in C, as a Master 1, Artificial inteligence Algorithmic project.

# Implmented Sorting Techniques
* [Insertion sort](https://en.wikipedia.org/wiki/Insertion_sort)
* [Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort)
* [Quicksort](https://en.wikipedia.org/wiki/Quicksort)
* [Merge sort](https://en.wikipedia.org/wiki/Merge_sort)
* [Heapsort](https://en.wikipedia.org/wiki/Heapsort)

# Approach

We first implemented the different algorithm then tested their execution time with tables of n integers with three different scenarios (the integers are ordered, ordered in reverse and random), the values of n used are:

| n | 6.4*10^4 | 1.28*10^5 | 2.56*10^5 | 5.12*10^5 | 1.024*10^6 | 2.048*10^6 | 5*10^2 | 10^3 | 2*10^3 | 4*10^3 | 8*10^3 | 1.6*10^4 | 3.2*10^4 |
|---|----------|-----------|-----------|-----------|------------|------------|--------|------|--------|--------|--------|----------|----------|

we then procedded to make plots of the executions time for each technique in python using seaborn and pandas in the file results/graphs.py

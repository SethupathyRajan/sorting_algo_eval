import matplotlib.pyplot as plt
import pandas as pd

df= pd.read_csv("e:/programs/sorting_algorithm_eval/all_algos_eval.csv")

for al in df['ALGORITHM'].unique():
    specific_algo = df[df['ALGORITHM'] == al]
    plt.plot(specific_algo['ARRAYSIZE'],specific_algo['EXEC_TIME'],label = al)

plt.xlabel("Array Size")
plt.ylabel("Execution Time (in ms)")

plt.legend()
plt.grid(True)
plt.show()
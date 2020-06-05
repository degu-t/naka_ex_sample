import csv
from matplotlib import pyplot as plt
import numpy as np

with open("result.csv", "r") as f:
    reader = csv.reader(f)
    x = []
    t = []
    v = []
    for row in reader:
        t.append(float(row[0]))
        x.append(float(row[2]))
        v.append(float(row[1]))

    x_arr = np.array(x)
    t_arr = np.array(t)
    v_arr = np.array(v)

    plt.plot(t_arr, x_arr, label="x")
    plt.plot(t_arr, v_arr, label="v")
    plt.legend()
    plt.show()
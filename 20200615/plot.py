import csv
from matplotlib import pyplot as plt
import numpy as np

with open("result.csv", "r") as f:
    reader = csv.reader(f)
    x = []
    y = []
    for row in reader:
        x.append(float(row[0]))
        y.append(float(row[1]))

    x_arr = np.array(x)
    y_arr = np.array(y)
    plt.plot(x_arr, y_arr, '.')
    plt.show()
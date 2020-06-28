import csv
from matplotlib import pyplot as plt
import numpy as np

with open("data.csv", "r") as f:
    reader = csv.reader(f)
    x = []
    y = []
    for row in reader:
        x.append(float(row[0]))
        y.append(float(row[1]))

    x_arr = np.array(x)
    y_arr = np.array(y)
    plt.plot(x_arr, y_arr, '.')

    x_range = np.arange(float(x[0]), float(x[len(x)-1]), 0.1)
    y_esttimated = 9.846229*x_range + -0.172106
    plt.plot(x_range, y_esttimated)
    plt.show()
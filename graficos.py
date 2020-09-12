import numpy as np
import seaborn as sea
import matplotlib.pyplot as plt

z = np.loadtxt("poisson/file8.txt")

plt.title("Poisson")
sea.heatmap((np.transpose(z)))



plt.figure()

plt.title("Charge")
z1 = np.loadtxt("charge/file8.txt")

sea.heatmap(z1)

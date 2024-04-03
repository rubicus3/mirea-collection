 
import matplotlib.pyplot as plt
import numpy as np

x = np.array([100, 1000, 100000, 1000000])
y = np.array([5320, 503429, 50034848, 5000350627])


plt.xticks([0, 200000, 400000, 600000, 800000, 1000000])


plt.ticklabel_format(axis="x", style='plain')



plt.xlabel("n")
plt.ylabel("T(n)")

plt.plot(x, y)
plt.show()

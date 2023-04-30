#%%
#Here I have imported the generated output files which are in csv format and then plotted the tracks for each event.
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import pandas as pd
df1 = pd.read_csv("../data/ical_Event10k_1GeV_nt_ical_data.csv",skiprows=12,sep=",",names=["event_id","x","y","z","t","Px","Py","Pz"])
df2 = pd.read_csv("../data/ical_Event10k_2GeV_nt_ical_data.csv",skiprows=12,sep=",",names=["event_id","x","y","z","t","Px","Py","Pz"])
df3 = pd.read_csv("../data/ical_event10k_3GeV_nt_ical_data.csv",skiprows=12,sep=",",names=["event_id","x","y","z","t","Px","Py","Pz"])
df4 = pd.read_csv("../data/ical_event10k_4GeV_nt_ical_data.csv",skiprows=12,sep=",",names=["event_id","x","y","z","t","Px","Py","Pz"])
df5 = pd.read_csv("../data/ical_event10k_5GeV_nt_ical_data.csv",skiprows=12,sep=",",names=["event_id","x","y","z","t","Px","Py","Pz"])
df6 = pd.read_csv("../data/ical_event10k_6GeV_nt_ical_data.csv",skiprows=12,sep=",",names=["event_id","x","y","z","t","Px","Py","Pz"])
df7 = pd.read_csv("../data/ical_event10k_7GeV_nt_ical_data.csv",skiprows=12,sep=",",names=["event_id","x","y","z","t","Px","Py","Pz"])
df8 = pd.read_csv("../data/ical_event10k_8GeV_nt_ical_data.csv",skiprows=12,sep=",",names=["event_id","x","y","z","t","Px","Py","Pz"])
df9 = pd.read_csv("../data/ical_event10k_9GeV_nt_ical_data.csv",skiprows=12,sep=",",names=["event_id","x","y","z","t","Px","Py","Pz"])
df10 =pd.read_csv("../data/ical_event10k_10GeV_nt_ical_data.csv",skiprows=12,sep=",",names=["event_id","x","y","z","t","Px","Py","Pz"])



df=df10
# fig = plt.figure()
# ax = plt.axes(projection='3d')

# df11 = df[df["event_id"]==800]
# ax.scatter(df11["x"],df11["y"],df11["z"])
# ax.set_xlabel('X')
# ax.set_ylabel('Y')
# ax.set_zlabel('Z')

# plt.hist(df['x'])
# plt.hist(df['y'])
plt.hist(df['z'])
plt.show()



#%%
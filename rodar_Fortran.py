import pandas as pd
import os

os.system('gfortran practice.f90 -o practice')
for i in range(300, 46301, 1000):
    os.system(f'practice.exe {i}')

dados = pd.read_csv('pontos_em_Fortran.csv')
print(dados)

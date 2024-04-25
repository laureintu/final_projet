import subprocess
import os
import tqdm
time_max=0
for i in tqdm.trange(1000):
        #out=subprocess.check_output("time ./ipsa_sched.c",shell=True)
        os.system("/usr/bin/time --output=outtime -p sh -c './BSS > /dev/null'")
        file=open("outtime","r")
        file.seek(0)
        f=file.readline()
        file.close()
        time=f[5:9]
        if float(time)>time_max:
                time_max=float(time)
print(time_max)

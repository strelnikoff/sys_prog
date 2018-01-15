import os

f = open("clear_log")
f_out = open("block_log", "a")
ips = []
for line in f:
    tmp = line.split()
    ips.append({
        "ip": tmp[1],
        "count": int(tmp[0])
    })
for ip in ips:
    if ip["count"] > 5:
        os.system("iptables -A INPUT -p tcp -s {} --dport 22 -j DROP".format(ip["ip"]))
        f_out.write(str(ip))
